#include <qutag_anl.h>
#include <iostream>


#define SLEEP(x) usleep(x)

qutaganl::qutaganl(){



    previouskey = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    cumulative = QVector<int>(5,0);
    flagaux = QVector<int>(3);
    flag = QVector<QVector<int>>(6,flagaux);
    counterplot = QVector<int>(6,0);
    outputCounter = QVector<int>(MAX_LOGIC, 0);

    /*in_QKD_ph= QVector<int8_t>(4,0);
    in_QKD_iw= QVector<int8_t>(4,0);
    in_QKD_zero= QVector<int8_t>(4,0);
    in_QKD_pxq= QVector<int8_t>(4,0);

    LSource= QVector<int8_t>(MAX_LOGIC,0);
    RSource= QVector<int8_t>(MAX_LOGIC,0);
    LWin= QVector<int8_t>(MAX_LOGIC,0);
    RWin= QVector<int8_t>(MAX_LOGIC,0);*/
    in_QKD_ph= QVector<int>(4,0);
    in_QKD_iw= QVector<int>(4,0);
    in_QKD_zero= QVector<int>(4,0);
    in_QKD_pxq= QVector<int>(4,0);

    LSource= QVector<int>(MAX_LOGIC,0);
    RSource= QVector<int>(MAX_LOGIC,0);
    LWin= QVector<int>(MAX_LOGIC,0);
    RWin= QVector<int>(MAX_LOGIC,0);
    logicOP= QVector<bool>(MAX_LOGIC,0);
    //flagL= QVector<bool>(MAX_LOGIC,0);
    //flagR= QVector<bool>(MAX_LOGIC,0);

  /*  int LSource[MAX_LOGIC]={0};
    int RSource[MAX_LOGIC]={0};
    int LWin[MAX_LOGIC]={0};
    int RWin[MAX_LOGIC]={0};
    int numberOfLogicPlots=0;
    bool logicOP[MAX_LOGIC];
    bool flagL[MAX_LOGIC] = {0};
    bool flagR[MAX_LOGIC] = {0};*/

    qRegisterMetaType<vectorInt64>("vectorInt64");
    qRegisterMetaType<vectorInt32>("vectorInt32");
    qRegisterMetaType<vectorInt8>("vectorInt8");
    qRegisterMetaType<vectorDouble>("vectorDouble");
    qRegisterMetaType<vectorBool>("vectorBool");
    qRegisterMetaType<vectorInt>("vectorInt");


    timestampProcess *analisis = new timestampProcess;
    analisis->moveToThread(&anlWorker1);
    connect(&anlWorker1, &QThread::finished, analisis, &QObject::deleteLater);
    connect(this, SIGNAL(timestampANL(vectorInt64 , vectorInt , int ,
                                          int , int,
                                          int , double , double ,
                                          vectorInt , vectorInt ,
                                          vectorInt ,vectorInt ,
                                          vectorInt , vectorInt , vectorInt ,
                                          vectorBool, bool )),
            analisis, SLOT(timestampANL(vectorInt64 , vectorInt , int ,
                                           int , int,
                                           int , double , double ,
                                           vectorInt , vectorInt ,
                                           vectorInt ,vectorInt ,
                                           vectorInt , vectorInt , vectorInt ,
                                           vectorBool, bool)),
            Qt::QueuedConnection);

    connect(analisis, SIGNAL(TScumulator_fromThread(vectorInt32)),
            this, SLOT(TScumulator(vectorInt32)), Qt::QueuedConnection);
    connect(analisis, SIGNAL(saveTTondisk_(long, long)), this, SLOT(saveTTondisk(long, long)));
    anlWorker1.start();

}
/*void qutaganl::run(){


    emit(Chang_anlAvilable(true));
    int i=0;
    std::cout<<"breal:  "<<break_<<std::endl;
    while(!break_){
        if(anlbusy){
                anlbusy=false;
                timestampANL();
        }
        else msleep(1);
     }

}
*/
qutaganl::~qutaganl(){
 if(rawTT->isOpen())rawTT->close();
 anlWorker1.quit();
 anlWorker1.wait();
}

void qutaganl::timestampREC(const vectorInt64 &inconimg_vectorTimetags, const vectorInt &inconimg_vectorChannels, int inconimg_tsvalid){
    emit Chang_anlAvilable(false);
    /*vectorTimetags.clear();
    vectorChannels.clear();
    //std::copy( inconimg_vectorTimetags, inconimg_vectorTimetags+tsvalid, std::back_inserter(vectorTimetags) );
    //std::copy( inconimg_vectorChannels, inconimg_vectorChannels+tsvalid, std::back_inserter(vectorTimetags) );
    this->vectorTimetags=inconimg_vectorTimetags;
    this->vectorChannels=inconimg_vectorChannels;
    this->tsvalid=inconimg_tsvalid;
    //std::cout<<"TS  incoming: "<<inconimg_vectorTimetags.size()<<"   saved: "<<vectorTimetags.size()<< std::endl;
    anlbusy=true;*/
//std::cout<<"REC"<<std::endl;

   /* QFuture<int> future = QtConcurrent::run(this, &qutaganl::timestampANL,
                                            inconimg_vectorTimetags, inconimg_vectorChannels, inconimg_tsvalid,
                                            numberOfLogicPlots, in_startChan,
                                            in_QKD_numb, in_QKD_time,  clkdiffT,
                                            LSource, RSource,
                                            LWin,RWin,
                                            in_QKD_ph,in_QKD_zero, in_QKD_iw,
                                            logicOP );*/

   emit timestampANL(inconimg_vectorTimetags, inconimg_vectorChannels, inconimg_tsvalid,
                  numberOfLogicPlots, this->in_startChan,
                      in_QKD_numb, in_QKD_time,  clkdiffT,
                      LSource, RSource,
                      LWin,RWin,
                      in_QKD_ph,in_QKD_zero, in_QKD_iw,
                      logicOP, saveTSon);
}



void timestampProcess::timestampANL(const vectorInt64 &vectorTimetags, const vectorInt &vectorChannels, int tsvalid,
                                    int numberOfLogicPlots, int in_startChan,
                                    int in_QKD_numb, double in_QKD_time, double clkdiffT,
                                    const vectorInt &LSource, const vectorInt &RSource,
                                    const vectorInt &LWin,const vectorInt &RWin,
                                    const vectorInt &in_QKD_ph, const vectorInt &in_QKD_zero, const vectorInt &in_QKD_iw,
                                    const vectorBool &logicOP, bool saveTSon_){
    //std::cout<<"tsvalid on thread: "<<tsvalid<<std::endl;
    //cumulativeTS+=tsvalid;
    int j;  //current element of the vector index
    int qq;// current qubit within clk signals
    double diffh=0;
    //if(outputCounter.isEmpty()) outputCounter.resize(numberOfLogicPlots);
    //for(int i = 0 ; i<10; i++)std::cout<<"chan: "<< vectorChannels[i]<<"\t tts: "<<vectorTimetags[i]<<"\n";
    vectorInt32 threadCounter(numberOfLogicPlots,0);
    int ChannelIndex;
    int StopIndex;
    QVector<bool> flagL(logicOP.size(),0);
    QVector<bool> flagR(logicOP.size(),0);
    ////two vectors with the same size (tsvalid) are comming, one with timestamps (vectorTimetags) and the other with the corresponding channel (vectorChannels)////
    //// the variable i point the current element on the vector
    /// the variable j point the current element within one clk cicle
    /// the variable qq point the current "qubit" (set of windows) within one ckl cycle
    /// the variable clkdiffT is the TS relative to the beggining of the current qubitTS
    /// LSource[] and RSource[], stores which source you use for logic, from 0 and ahead are the previous results, -1 to -4 correspond to the 4 histograms

    for ( int i=0 ; i<tsvalid; i++) {  // iterate across all the ts comming
        ChannelIndex = abs(int(vectorChannels[i])); // check the channel of the current i
        if(ChannelIndex == in_startChan){ //found the start channel (5)
            qq=0;//starts from the first qubit (of 10 in the current case)
            j=i+1; //next element on the vector after the start channel
            if(j>=tsvalid)break; //next element is actualy out of the array - STOP
            StopIndex= abs(int(vectorChannels[j])); // check the channel for j element, starts from i+1 and keep increasing iside the while
            //if(StopIndex!=in_startChan)diffh = vectorTimetags[j]-vectorTimetags[i];
            //if(StopIndex!=in_startChan)diffh = vectorTimetags[j]-vectorTimetags[i]-in_QKD_zero[StopIndex];
            //if(diffh<0)break;
            //if(diffh<0)std::cout<<"relative TS is negative!!!   clk:"<<ChannelIndex<<"      stop:"<<StopIndex<<std::endl;
            // unless we found again the clk channel (5), calculate the relative TS (diffh) TS-TSclk and substract the corresponding offset from the lines
            while(StopIndex!=in_startChan){ // unless we found again the clk channel (5), keep iterating
                diffh = vectorTimetags[j]-vectorTimetags[i]-in_QKD_zero[StopIndex-1];
                if(diffh<=0)break;
                while(diffh>=(qq+1)*in_QKD_time && qq<in_QKD_numb)qq++;//increase the counter for the qubit counter as long the relativeTS is not bigger than the next-qubitTS...
                if(qq>=in_QKD_numb)break;
                clkdiffT=diffh-qq*in_QKD_time;//TS relative to the beggining of the current qubit is calculated (clkdiffT)
                if(clkdiffT<0)break;
                //if(clkdiffT<0)std::cout<<"internal TS is negative!!!!!!!!!!!!!       qq: "<<qq<<std::endl;
                //if(qq>0)std::cout<<"    qq: "<<qq<<std::endl;
                for (int ii=0;ii<numberOfLogicPlots;ii++) {// go thru all the logic on second tab
                    for (int pp=0;pp<4;pp++) {//go thru the 4 histograms
                        if(LSource[ii]==-pp-1 && StopIndex == pp+1){// if the current channel on the vector correspond with the channel on the left logic
                            //if(i<5)std::cout<<"Left Logic = timestamp: "<<clkdiffT<<"   WinL: "<<(LWin[ii]*in_QKD_ph[pp])+in_QKD_zero[pp]<<"    winR: "<<(LWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp])+in_QKD_zero[pp]<<"   qq: "<<qq<<"    clk: "<<vectorTimetags[i]<<std::endl;
                            //std::cout<<"LWin[ii]: "<<LWin[ii]<<"   in_QKD_ph[pp]: "<<in_QKD_ph[pp]<<"\t in_QKD_zero[pp]:"<<in_QKD_zero[pp]<<std::endl;}
                            //if((LWin[ii]*in_QKD_ph[pp])+in_QKD_zero[pp]<clkdiffT && clkdiffT<(LWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp])+in_QKD_zero[pp])flagL[ii]=true;//is the TS inside the window? Left logic
                            if((LWin[ii]*in_QKD_ph[pp])<clkdiffT && clkdiffT<(LWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp]))flagL[ii]=true;
                            //aux1++;
                        }
                        if(RSource[ii]==-pp-1 && StopIndex == pp+1){// if the current channel on the vector correspond with the channel on the Right logic
                            //if(i<10){std::cout<<"Right Logic = timestamp: "<<clkdiffT<<"   WinL: "<<(RWin[ii]*in_QKD_ph[pp])+in_QKD_zero[pp]<<"    winR: "<<(RWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp]+in_QKD_zero[pp])<<"   qq: "<<qq<<"    clk: "<<vectorTimetags[i]<<std::endl;
                            //std::cout<<"RSource: "<<RSource[0]<<"   RWin: "<<RWin[0]<<std::endl;}
                            //if((RWin[ii]*in_QKD_ph[pp])+in_QKD_zero[pp]<clkdiffT && clkdiffT<(RWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp])+in_QKD_zero[pp])flagR[ii]=true;//is the TS inside the window? Right logic
                            if((RWin[ii]*in_QKD_ph[pp])<clkdiffT && clkdiffT<(RWin[ii]*in_QKD_ph[pp]+in_QKD_iw[pp]))flagR[ii]=true;
                            //aux2++;
                        }

                    }//4 channels

                   if(LSource[ii]>=0){//if the left logic is calling a previous result
                        if(logicOP[LSource[ii]]) if( flagL[LSource[ii]] && flagR[LSource[ii]] ) flagL[ii]=true;//and
                        if(!logicOP[LSource[ii]]) if( flagL[LSource[ii]] || flagR[LSource[ii]] ) flagL[ii]=true;//or
                    }
                    if(RSource[ii]>=0){//if the Right logic is calling a previous result
                        if(logicOP[RSource[ii]]) if( flagL[RSource[ii]] && flagR[RSource[ii]] ) flagR[ii]=true;//and
                        if(!logicOP[RSource[ii]]) if( flagL[RSource[ii]] || flagR[RSource[ii]] ) flagR[ii]=true;//or
                    }
                }//all relations on tab2

                j++;
                if(j>=tsvalid)break;
                StopIndex= abs(int(vectorChannels[j]));
                diffh=vectorTimetags[j]-vectorTimetags[i]-in_QKD_zero[StopIndex-1];
                if( (diffh>=(qq+1)*in_QKD_time+in_QKD_zero[StopIndex-1] || StopIndex==in_startChan) && qq+1<=in_QKD_numb){
                    qq++;
                    for (int k=0;k<numberOfLogicPlots;k++) {
                        if(logicOP[k] && (flagL[k] && flagR[k])){

                            if(saveTSon_)emit saveTTondisk_(vectorTimetags[i], vectorTimetags[j-1]);
                            threadCounter[k]++;
                        }
                        if(!logicOP[k] && (flagL[k] || flagR[k])) threadCounter[k]++;
                        flagL[k]=false;
                        flagR[k]=false;
                       // if(i<10)std::cout<<"enter flags --- counter: "<<outputCounter[k]<<std::endl;
                    }
                }//qqchange
            }//While -- clk signal reappears
        }
    }


   /*

    if(key-previouskey>adqtime_2){

        emit rates_tab2(outputCounter, key);
        previouskey=key;
        outputCounter.clear();

        std::cout<<"events:"<<cumulativeTS<<std::endl;
        std::cout<<"tsvalid: "<<tsvalid<<std::endl;
        //std::cout<<"cumulative:"<<cumulative[0]<<"\t"<<cumulative[1]<<"\t"<<cumulative[2]<<"\t"<<cumulative[3]<<"\t"<<std::endl;
        std::cout<<"LoR:   "<<aux1<<"\t"<<aux2<<std::endl;
        //cumulative[0]=0;cumulative[1]=0;cumulative[2]=0;cumulative[3]=0;
        cumulativeTS=0; aux1=0; aux2=0;
        /*for (int i=0;i<200;i++)
            if( ((int)vectorChannels[i] == 2 && (int)vectorChannels[i+1] ==3) || ((int)vectorChannels[i+1] == 2 && (int)vectorChannels[i] ==3)){
                std::cout<<"channel :"<<(int)vectorChannels[i]<<"\t TTS: "<<vectorTimetags[i]<<"\t diff:"<<vectorTimetags[i+1]-vectorTimetags[i]<<std::endl;
                std::cout<<"channel :"<<(int)vectorChannels[i+1]<<"\t TTS: "<<vectorTimetags[i+1]<<std::endl;
            }
        //for (int i=0;i<4;i++)std::cout<<"offset: "<<in_QKD_zero[i];
        //std::cout<<std::endl;
    }*/

    //emit(Chang_anlAvilable(true));
   /* std::cout<<"inside:  ";
    for(int i=0; i<threadCounter.size(); i++) std::cout<<"\t"<<threadCounter[i];
    std::cout<<std::endl;*/
    emit TScumulator_fromThread(threadCounter);
    threadCounter.clear();

}

void qutaganl::TScumulator(const vectorInt32 &counter){

    key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    for (int i=0;i<counter.size();i++) {
        this->outputCounter[i] += counter[i];
    }
    /*std::cout<<"outside:  ";
    for(int i=0; i<counter.size(); i++) std::cout<<"\t"<<counter[i];
    std::cout<<std::endl;*/

    if(key-previouskey>adqtime_2){
      /*  std::cout<<"++++++++to plot:  ";
        for(int i=0; i<outputCounter.size(); i++) std::cout<<"\t"<<outputCounter[i];
        std::cout<<std::endl;*/
        emit rates_tab2(this->outputCounter, key);
        previouskey=key;
        this->outputCounter.fill(0);

    }
    emit(Chang_anlAvilable(true));
}



void qutaganl::chang_LogicWinL(QString t, int i){
    QRegularExpression rx("w(\\d+)");
    QRegularExpressionMatch match = rx.match(t);
    LWin[i]=match.captured(1).toInt();
    //std::cout<<t.toStdString()<<"\t cap:"<<match.captured(1).toStdString()<<std::endl;
}
void qutaganl::chang_LogicWinR(QString t, int i){
    QRegularExpression rx("w(\\d+)");
    QRegularExpressionMatch match = rx.match(t);
    RWin[i]=match.captured(1).toInt();
    //std::cout<<t.toStdString()<<"\t cap:"<<match.captured(1).toStdString()<<std::endl;
}

void qutaganl::chang_LogicOP(QString t, int index){
    if(t.compare("AND")==0)logicOP[index]=true;
    if(t.compare("OR")==0)logicOP[index]=false;
}
timestampProcess::timestampProcess(){

}

timestampProcess::~timestampProcess(){

}
void qutaganl::saveTTondisk(long clk, long tt){

    if(outTSstream != NULL)*outTSstream<< clk << "\t"<< tt << "\n";
}
void qutaganl::saveRawTSon(int a){
    if(a){
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("dd_MM_yyyy_hh_mm_ss");
        QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
        QString filename = "RawTS_"+formattedTimeMsg;

        rawTT = new QFile(filename);
        if (!rawTT->open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        outTSstream = new QTextStream(rawTT);
        saveTSon=true;

    }
    else{
        if(rawTT->isOpen()){
            rawTT->close();
            delete rawTT;
            delete outTSstream;
        }
        saveTSon=false;
    }
}
