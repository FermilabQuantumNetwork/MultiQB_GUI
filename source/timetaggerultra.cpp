#include "timetaggerultra.h"

timetaggerUltra::timetaggerUltra()
{

    //TTURes = Resolution::HighResA;
    TTURes = Resolution::Standard;
    break_=false;
    //timetags.reserve(EVENT_BUFFER_SIZE+1);
    //channelsTDC.reserve(EVENT_BUFFER_SIZE+1);
}


timetaggerUltra::~timetaggerUltra()
{
    qDebug()<<"TTU destructor";
    freeTimeTagger(t);
}



void timetaggerUltra::run(){
    std::vector<std::string> taggers = scanTimeTagger();
    if (taggers.empty()) {
        std::cout << std::endl << "No time tagger found." << std::endl << "Please attach a Time Tagger." << std::endl;
        return;
    }
    //int res = 0;

    // connect to a time tagger

/*
if any high resolution mode is selected, the hardware will combine 2, 4 or even 8 input channels and average
their timestamps. This results in a discretization jitter improvement of factor sqrt(N) for N combined channels. The
averaging is implemented before any filter, buffer or USB transmission. So all of those features are available with
the averaged timestamps. Because of hardware limitations, only fixed combinations of channels are supported:
• HighResA: 1 : [1,2], 3 : [3,4], 5 : [5,6], 7 : [7,8], 10 : [10,11], 12 : [12,13], 14 : [14,15], 16 : [16,17], 9, 18
• HighResB: 1 : [1,2,3,4], 5 : [5,6,7,8], 10 : [10,11,12,13], 14 : [14,15,16,17], 9, 18
• HighResC: 5 : [1,2,3,4,5,6,7,8], 14 : [10,11,12,13,14,15,16,17], 9, 18 The inputs 9 and 18 are always available
without averaging. The number of channels available will be limited to the number of channels licensed.
*/


    try{
        t = createTimeTagger("", TTURes);//{1,3,5,7}
    }
    catch (std::invalid_argument const& ex){
        std::cout << "#1: " << ex.what() << '\n';
    }

    if(TTURes == Resolution::HighResA)for(int i = 0; i< NTTUCHANNELS; i++)TTUChannelsinuse[i]=i*2+1;//{1,3,5,7}
    if(TTURes == Resolution::Standard)for(int i = 0; i< NTTUCHANNELS; i++)TTUChannelsinuse[i]=i+1;//{1,2,3,4}


    for(int i = 0; i< NTTUCHANNELS; i++){

        try{
            thresholds[i]=t->getTriggerLevel(TTUChannelsinuse[i]);
        }
        catch (std::invalid_argument const& ex){
            std::cout << "#1: " << ex.what() << '\n';
        }
    }
    //stored values extracted from the device, ready to load them on the screen
    emit ttuinitdone();

    //copy the channels on a std vector
    int n = sizeof(TTUChannelsinuse) / sizeof(TTUChannelsinuse[0]);
    TTUChannels = std::vector<int>(TTUChannelsinuse, TTUChannelsinuse+n);

    long buffersize = EVENT_BUFFER_SIZE;

    tts = new TimeTagStream(t,buffersize , TTUChannels );
    tts->start();

    setHistograms();

    double previous_time = QDateTime::currentDateTime().toMSecsSinceEpoch();
    double current_time;

    while(!break_ && tts->isRunning()){
        current_time = QDateTime::currentDateTime().toMSecsSinceEpoch();
        // std::cout<< current_time-previous_time <<std::endl;
        if((current_time-previous_time) > 1000*in_adqtime){
            getHisto();//TDC_clearAllHistograms ();
            previous_time = current_time;
        }
        //if(anlAvilable && in_TSON)getTimeStamps();
        if(in_TSON)getTimeStampsTTU();
        QThread::msleep(1);
    }

}

void timetaggerUltra::getTimeStampsTTU(){
    TimeTagStreamBuffer ttsb = tts->getData();

    //std::cout<<"gettimestanmps"<<std::endl;
    //timetags.clear();channelsTDC.clear();

    //rc = TDC_getLastTimestamps( 1, timestamps, channels, &tsValid );

    //checkRc( "TDC_getLastTimestamps", rc );
    //std::cout<<"TSValid: "<<tsValid<<std::endl;
    std::vector<int>channels;
    std::vector<long long>timestamps;

    ttsb.getChannels([&channels](size_t size){
        channels.resize(size);
        return channels.data();
    });

    ttsb.getTimestamps([&timestamps](size_t size){
        timestamps.resize(size);
        return timestamps.data();
    });

    QVector<int64_t> timetags = QVector<int64_t>(timestamps.begin(),timestamps.end());

    QVector<int> channelsTDC = QVector<int>(channels.begin(),channels.end());

   //std::copy(timestamps.begin(), timestamps.begin() + int(ttsb.size*(float(TSpercentage)/100)), std::back_inserter(timetags));
    //std::copy(channels.begin(), channels.begin() + int(ttsb.size*(float(TSpercentage)/100)), std::back_inserter(channelsTDC));

    if(ttsb.size>=EVENT_BUFFER_SIZE)std::cout<<"timetaggerultra buffer saturated!!        "<<ttsb.size<<std::endl;
    //if(ttsb.size>0 && anlAvilable){
    if(ttsb.size>0 ){
        //if(tsValid>0){
        //std::cout<<"     channel :"<<(int)chann
        // QThread::msleep(1);
        /*for ( int i=0; i < 20; i++ ) {
         //   printf("channel original:  %hd",channels[i]);
           std::cout<<"     channel :"<<(int)channels[i]<<"\t TTS: "<<timestamps[i]<<"       "<<timestamps[i+1]-timestamps[i]<<std::endl;
        }*/
        emit dataready(timetags, channelsTDC, int(ttsb.size*(float(TSpercentage)/100)));
    }
}

void timetaggerUltra::getHisto(){
    //qDebug()<<"histottu";
    int count[NTTUCHANNELS];
    QVector<double> dataA, dataB, dataC, dataD;
    std::vector<double> datac;
    ttuc->getData([&datac](size_t size) {
        datac.resize(size);
        return datac.data();
    });
    for(int i = 0; i<NTTUCHANNELS; i++){

        count[i]=(int)datac[i];
        std::vector<int32_t> histodata;
        ttuhisto[i]->getData([&histodata](size_t size1) {
        histodata.resize(size1);
        return histodata.data();
        });
        if(i==0){dataA = QVector<double>(histodata.begin(), histodata.end());ttuhisto[i]->clear();}
        if(i==1){dataB = QVector<double>(histodata.begin(), histodata.end());ttuhisto[i]->clear();}
        if(i==2){dataC = QVector<double>(histodata.begin(), histodata.end());ttuhisto[i]->clear();}
        if(i==3){dataD = QVector<double>(histodata.begin(), histodata.end());ttuhisto[i]->clear();}
    }
    datac.clear();
    if(!dataA.isEmpty() || !dataB.isEmpty() || !dataC.isEmpty() || !dataD.isEmpty() ) emit TTUhist(dataA, dataB, dataC, dataD,  count[0], count[1], count[2], count[3]);
    else qDebug()<<"TTU histograms empty";
    /*dataA.clear();
    dataB.clear();
    dataC.clear();
    dataD.clear();*/
}

void timetaggerUltra::setHistograms(){

    for(int i = 0; i<NTTUCHANNELS; i++){
        try{
            ttuhisto[i] = new Histogram(t, TTUChannelsinuse[i] , TTUSTARTCHANNEL, in_binWidth, in_nbins);
        }
        catch (std::invalid_argument const& ex){
            std::cout << "#1: " << ex.what() << '\n';
        }
        try{

            ttuc = new Countrate(t, TTUChannels);
        }
        catch (std::invalid_argument const& ex){
            std::cout << "#1: " << ex.what() << '\n';
        }

    }
}