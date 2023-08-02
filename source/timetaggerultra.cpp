#include "timetaggerultra.h"

timetaggerUltra::timetaggerUltra()
{
    break_=false;
    timetags.reserve(EVENT_BUFFER_SIZE+1);
    channelsTDC.reserve(EVENT_BUFFER_SIZE+1);
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


    try{
         t = createTimeTagger();
    }
    catch (std::invalid_argument const& ex){
        std::cout << "#1: " << ex.what() << '\n';
    }


    for(int i = 0; i< NTTUCHANNELS; i++){

        try{
            thresholds[i]=t->getTriggerLevel(i+1);
        }
        catch (std::invalid_argument const& ex){
            std::cout << "#1: " << ex.what() << '\n';
        }
    }

    emit ttuinitdone();

    std::vector<int>TTUChannels = {1,2};
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
            //getHisto();//TDC_clearAllHistograms ();
            previous_time = current_time;
        }
        //if(anlAvilable && in_TSON)getTimeStamps();
        //if(in_TSON)getTimeStampsTTU();
        QThread::msleep(1);
    }

}

void timetaggerUltra::getTimeStampsTTU(){
    TimeTagStreamBuffer ttsb = tts->getData();

    //std::cout<<"gettimestanmps"<<std::endl;
    timetags.clear();channelsTDC.clear();

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

    std::copy(timestamps.begin(), timestamps.begin() + int(ttsb.size*(float(TSpercentage)/100)), std::back_inserter(timetags));
    std::copy(channels.begin(), channels.begin() + int(ttsb.size*(float(TSpercentage)/100)), std::back_inserter(channelsTDC));

    if(ttsb.size>=EVENT_BUFFER_SIZE)std::cout<<"timetaggerultra buffer saturated!!        "<<ttsb.size<<std::endl;
    if(ttsb.size>0 && anlAvilable){
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

    for(int i = 0; i<NTTUCHANNELS; i++){
/*        std::vector<timestamp_t> histodata;
        ttuhisto[i]->getData([&histodata](size_t size1, size_t size2) {
        histodata.resize(size1*size2);
        return histodata.data();
        });*/
    }
}

void timetaggerUltra::setHistograms(){
    for(int i = 0; i<NTTUCHANNELS; i++){
        try{
            ttuhisto[i] = new Histogram(t, i+1 , TTUSTARTCHANNEL, in_binWidth, in_nbins);
        }
        catch (std::invalid_argument const& ex){
            std::cout << "#1: " << ex.what() << '\n';
        }

    }
}
