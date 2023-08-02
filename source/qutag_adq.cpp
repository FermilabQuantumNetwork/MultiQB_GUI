#include <qutag_adq.h>
#include <iostream>//entradas y salidas por consola
#include <fstream>//archivos.txt
#include <time.h>
#define SLEEP(x) usleep(x)


//////////////////////////////////////////////////
//////constructor////////
//////////////////////////////////////////////////

qutagadq::qutagadq(){

    timetags.reserve(QUTAG_TIMESTAMP_COUNT+1);
    channelsTDC.reserve(QUTAG_TIMESTAMP_COUNT+1);
    break_=false;
    adqpause_=false;
    histodataA=nullptr;
    histodataB=nullptr;
    histodataC=nullptr;
    histodataD=nullptr;
    anlAvilable=true;
    HIST_BINWIDTH=10;
    HIST_BINCOUNT=100;


}

void qutagadq::run(){
lautrun();

}

/* Check return code and exit on error */
void qutagadq::checkRc( const char * fctname, int rc ){
  //std::cout<<"function: "<<fctname<< "     rc = "<<rc<<std::endl;
  if ( rc ) {
    printf("error\n");
    printf( ">>> %s: %s\n", fctname, TDC_perror( rc ) );
    QString errormessage= "error >>>" + QString(fctname) + ": " + QString(TDC_perror( rc ));
    if(rc == TDC_NotConnected)emit TDCerror("TDC not initialized, is disconnected or another instance is running");
    else emit TDCerror(errormessage);
    break_=true;
  }
}


 qutagadq::~qutagadq(){

    TDC_deInit();

 }


/*
int qutagadq::filterset(){

    int maskA=0x00 , maskB=0x00, maskC=0x00;

    maskA|=0x1<<(in_PlotACh2);
    maskA|=0x1<<(in_startChan);

    maskB|=0x1<<(in_PlotBCh1);
    maskB|=0x1<<(in_startChan);

    maskC|=0x1<<(in_PlotACh2);
    maskC|=0x1<<(in_PlotBCh2);
    maskC|=0x1<<(in_PlotCCh2);
    //maskC|=0x1<<(in_startChan);

    std::cout<<"filter channel : "<<in_startChan<<"  , mask : "<<maskC<<std::endl;
    std::cout<<"filter channel : "<<in_PlotACh2<<"  , mask : "<<maskA<<std::endl;
    std::cout<<"filter channel : "<<in_PlotBCh2<<"  , mask : "<<maskB<<std::endl;
    //rc = TDC_configureFilter(in_startChan, FILTER_SYNC , maskC);
    //checkRc( "TDC_configureFilter clock", rc );
    rc = TDC_configureFilter(in_PlotACh2, FILTER_NONE, maskA);
    checkRc( "TDC_configureFilter mask A", rc );
    rc = TDC_configureFilter(in_PlotBCh2, FILTER_NONE, maskB);
    checkRc( "TDC_configureFilter mask B", rc );
    rc = TDC_configureFilter(in_PlotCCh2, FILTER_NONE, maskB);
    checkRc( "TDC_configureFilter mask B", rc );

    return 0;
}
*/

 void qutagadq::lautrun(){

     printf( ">>> tdcbase version: %f\n", TDC_getVersion() );
     rc = TDC_init( -1 );                                 /* Accept every device */
     checkRc( "TDC_init", rc );

     rc = TDC_getTimebase( &timeBase );
     checkRc( "TDC_getTimebase", rc );

     std::cout<<" >>> timebase: "<<timeBase*1.e12<<"ps"<<std::endl;

    // rc=TDC_setFiveChannelMode(1);
    // checkRc( "TDC_setFiveChannelMode", rc );

     rc = TDC_enableChannels( 0xff );                     /* Use all channels */
     checkRc( "TDC_enableChannels", rc );

     rc = TDC_setTimestampBufferSize( QUTAG_TIMESTAMP_COUNT );
     checkRc( "TDC_setTimestampBufferSize", rc );

     rc = TDC_setExposureTime( 1000 );
     checkRc( "TDC_setExposureTime", rc );

     ///////////////initial thresholds and edges/////////////
     //int temp_edge[1];
     //double temp_thresh[1];
    /* int *temp_edge = nullptr;
     double *temp_thresh = nullptr;*/

     for(int i = 0 ; i<NQUTAGCHANNELS; i++){
         if(i==0)rc = TDC_getSignalConditioning(5, RoF,thresholds );
         else rc = TDC_getSignalConditioning(i, RoF+i,thresholds+i );
         checkRc( "TDC_getSignalConditioning", rc );
         std::cout<<" ch "<<i<<" edge : "<<RoF[i]<<"\t thresh"<<thresholds[i] <<std::endl;


     }

/*
     rc = TDC_getSignalConditioning(2, temp_edge,temp_thresh);
     std::cout<<" ch2 edge : "<<*temp_edge<<"\t thresh"<<*temp_thresh<<std::endl;
     thresholds[2] = *temp_thresh;
     RoF[2] = bool(*temp_edge);
     rc = TDC_getSignalConditioning(3, temp_edge,temp_thresh);
     std::cout<<" ch3 edge : "<<*temp_edge<<"\t thresh"<<*temp_thresh<<std::endl;
     thresholds[3] = *temp_thresh;
     RoF[3] = bool(*temp_edge);
     rc = TDC_getSignalConditioning(4, temp_edge,temp_thresh);
     std::cout<<" ch4 edge : "<<*temp_edge<<"\t thresh"<<*temp_thresh<<std::endl;
     thresholds[4] = *temp_thresh;
     RoF[4] = bool(*temp_edge);
     rc = TDC_getSignalConditioning(5, temp_edge,temp_thresh);
     std::cout<<" ch5 edge : "<<*temp_edge<<"\t thresh"<<*temp_thresh<<std::endl;
     thresholds[0] = *temp_thresh;
     RoF[0] = bool(*temp_edge);
*/
    //TDC_FilterType temp_filtertype[1];
     /////////////filters//////
     for(int i = 0 ; i<5; i++){
         if(i==0) rc = TDC_getFilter(5, filtertype, ch_filtermask);
         else  rc = TDC_getFilter(i, filtertype+i, ch_filtermask+i);
     }
     /*

     Int32 temp_channelmask[1];
     rc = TDC_getFilter(1, temp_filtertype, temp_channelmask);
     filtertype[1]= *temp_filtertype;
     ch_filtermask[1] = *temp_channelmask;

     rc = TDC_getFilter(2, temp_filtertype, temp_channelmask);
     filtertype[2]= *temp_filtertype;
     ch_filtermask[2] = *temp_channelmask;

     rc = TDC_getFilter(3, temp_filtertype, temp_channelmask);
     filtertype[3]= *temp_filtertype;
     ch_filtermask[3] = *temp_channelmask;

     rc = TDC_getFilter(4, temp_filtertype, temp_channelmask);
     filtertype[4]= *temp_filtertype;
     ch_filtermask[4] = *temp_channelmask;

     rc = TDC_getFilter(5, temp_filtertype, temp_channelmask);
     filtertype[0]= *temp_filtertype;
     ch_filtermask[0] = *temp_channelmask;
*/
     loadtdcfiltertype();

     /////delays//////
     ///
     rc = TDC_getChannelDelays(delays);

     //std::cout<<"ADQ  rof"<<RoF[1]<<"rof"<<RoF[2]<<"rof"<<RoF[3]<<"rof"<<RoF[4]<<std::endl;
     //rc = TDC_enableMarkers(0);        //WHY IS THIS NOT WORKING??
     //checkRc( "TDC_enableMarkers", rc);
     //rc = TDC_setExposureTime( EXP_TIME );
     //checkRc( "TDC_setExposureTime", rc );

     //rc = TDC_setCoincidenceWindow( 90000 ); /* 30ns */
    // checkRc( "TDC_setCoincidenceWindow", rc );


     fflush(stdout);

   /////histograms//////

   rc = TDC_enableStartStop( 1 );
   checkRc( "TDC_enableStartStop", rc );
   rc = TDC_getHistogramParams(&in_binWidth, &in_binsinplot);
   setHistograms();

   emit initdone();
   initdone_bool =1;

  TDC_clearAllHistograms ();

  double previous_time = QDateTime::currentDateTime().toMSecsSinceEpoch();
  double current_time;

     //while(!break_ && !rc){
    while(!break_ ){
         current_time = QDateTime::currentDateTime().toMSecsSinceEpoch();
        // std::cout<< current_time-previous_time <<std::endl;
         if((current_time-previous_time) > 1000*in_adqtime){           
             getHisto();//TDC_clearAllHistograms ();
             previous_time = current_time;
         }
         //if(anlAvilable && in_TSON)getTimeStamps();
         if(in_TSON)getTimeStamps();
         QThread::msleep(1);
     }
    std::cout<<"adq thread broke"<<std::endl;
 }

 void qutagadq::getHisto(){

    int count1, count2, count3, count4;

    //std::cout<<"gethisto"<<std::endl;
    if(paramschange)setHistogramsParam();
    if(rc)return;

     if (histodataA != 0) {
         delete [] histodataA;
     }

     histodataA = new Int32 [in_binsinplot];

     if (histodataB != 0) {
         delete [] histodataB;
     }

     histodataB = new Int32 [in_binsinplot];

     if (histodataC != 0) {
         delete [] histodataC;
     }

     histodataC = new Int32 [in_binsinplot];

     if (histodataD != 0) {
         delete [] histodataD;
     }

     histodataD = new Int32 [in_binsinplot];

    /* std::cout<<"binsinplot adq  :  "<< in_binsinplot<<std::endl;
     std::cout<<"plot 1A  :  "<< in_PlotACh1<<std::endl;
     std::cout<<"plot 2A  :  "<< in_PlotACh2<<std::endl;
*/

    rc = TDC_getHistogram(QUTAG_START_CHANNEL, 1, 1, histodataA, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
//rc = TDC_getHistogram(1,START_CHANNEL, 1, histodataA, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    checkRc( "TDC_getHistogram A", rc );
    count1=count;
    //std::cout<<"Channel A   starts: "<<eventsA<<"   stops: "<<eventsB<<std::endl;
   /* dataA.resize(in_binsinplot);

    for (int i=0; i<in_binsinplot; ++i){
        dataA[i]=double(histodataA[i]);
    }*/
    std::copy(histodataA,histodataA+in_binsinplot,std::back_inserter(dataA));

    rc = TDC_getHistogram(QUTAG_START_CHANNEL, 2, 1, histodataB, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
   // rc = TDC_getHistogram(2,START_CHANNEL, 1, histodataB, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    checkRc( "TDC_getHistogram B", rc );

    count2=count;
    //std::cout<<"Channel B   starts: "<<eventsA<<"   stops: "<<eventsB<<std::endl;
    /*dataB.resize(in_binsinplot);

    for (int i=0; i<in_binsinplot; ++i){
        dataB[i]=double( histodataB[i] );
     }*/
    std::copy(histodataB,histodataB+in_binsinplot,std::back_inserter(dataB));

    rc = TDC_getHistogram(QUTAG_START_CHANNEL, 3, 1, histodataC, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    //rc = TDC_getHistogram(3,START_CHANNEL, 1, histodataC, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    checkRc( "TDC_getHistogram C", rc );
    count3=count;
    //std::cout<<"Channel C   starts: "<<eventsA<<"   stops: "<<eventsB<<std::endl;
    /*dataC.resize(in_binsinplot);
    for (int i=0; i<in_binsinplot; ++i){
        dataC[i]=double (histodataC[i]);
    }*/
    std::copy(histodataC,histodataC+in_binsinplot,std::back_inserter(dataC));

    rc = TDC_getHistogram(QUTAG_START_CHANNEL, 4, 1, histodataD, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    //rc = TDC_getHistogram(4,START_CHANNEL, 1, histodataD, &count, &tooSmall, &tooBig, &eventsA, &eventsB, &expTime );
    checkRc( "TDC_getHistogram D", rc );

    count4=count;
    //std::cout<<"Channel D   starts: "<<eventsA<<"   stops: "<<eventsB<<std::endl;
    /*dataD.resize(in_binsinplot);

    for (int i=0; i<in_binsinplot; ++i){
        dataD[i]=double (histodataD[i]);
     }*/
    std::copy(histodataD,histodataD+in_binsinplot,std::back_inserter(dataD));

   /* if(count1==0){
        dataA.resize(in_binsinplot);
        dataA.fill(0);
    }
    if(count2==0){
        dataB.resize(in_binsinplot);
        dataB.fill(0);
    }

    if(count3==0){
        dataC.resize(in_binsinplot);
        dataC.fill(0);
    }
    if(count4==0){
        dataD.resize(in_binsinplot);
        dataD.fill(0);
    }*/
    //std::cout<<count1<<"\t"<<count2<<"\t"<<count3<<"\t"<<count4<<"\t"<<std::endl;
    //std::cout<<dataA.size()<<"\t"<<dataB.size()<<"\t"<<dataC.size()<<"\t"<<dataD.size()<<"\t"<<std::endl;

     if(count1 != 0 || count2 !=0 || count3 !=0|| count4 !=0) emit qutaghist(dataA, dataB, dataC, dataD,  count1, count2, count3, count4);
    //QVector<int8_t> channelsTDC;
       dataA.clear();
       dataB.clear();
       dataC.clear();
       dataD.clear();
 }

 void qutagadq::getTimeStamps(){
     //std::cout<<"gettimestanmps"<<std::endl;
     timetags.clear();channelsTDC.clear();
     rc = TDC_getLastTimestamps( 1, timestamps, channels, &tsValid );
     checkRc( "TDC_getLastTimestamps", rc );
     //std::cout<<"TSValid: "<<tsValid<<std::endl;
     std::copy(timestamps, timestamps + int(tsValid*(float(TSpercentage)/100)), std::back_inserter(timetags));
     std::copy(channels, channels + int(tsValid*(float(TSpercentage)/100)), std::back_inserter(channelsTDC));
     if(tsValid>=QUTAG_TIMESTAMP_COUNT)std::cout<<"qutag buffer saturated!!        "<<tsValid<<std::endl;
     if(tsValid>0 && anlAvilable){
     //if(tsValid>0){
         //std::cout<<"     channel :"<<(int)chann
        // QThread::msleep(1);
         /*for ( int i=0; i < 20; i++ ) {
         //   printf("channel original:  %hd",channels[i]);
           std::cout<<"     channel :"<<(int)channels[i]<<"\t TTS: "<<timestamps[i]<<"       "<<timestamps[i+1]-timestamps[i]<<std::endl;
         }*/
        emit dataready(timetags, channelsTDC, int(tsValid*(float(TSpercentage)/100)));
    }

 }

 void qutagadq::setHistograms(){


     /////////////create the histograms on the FPGA /////////////

     rc = TDC_addHistogram(QUTAG_START_CHANNEL, 1, 1 );
     checkRc( "TDC_addHistogram", rc );
     rc = TDC_addHistogram( QUTAG_START_CHANNEL, 2, 1 );
     checkRc( "TDC_addHistogram", rc );
     rc = TDC_addHistogram( QUTAG_START_CHANNEL, 3, 1 );
     checkRc( "TDC_addHistogram", rc );
     rc = TDC_addHistogram( QUTAG_START_CHANNEL, 4, 1 );
     checkRc( "TDC_addHistogram", rc );
     /*rc = TDC_addHistogram(1, START_CHANNEL, 1 );
          checkRc( "TDC_addHistogram", rc );
          rc = TDC_addHistogram(2,  START_CHANNEL, 1 );
          checkRc( "TDC_addHistogram", rc );
          rc = TDC_addHistogram(3,  START_CHANNEL, 1 );
          checkRc( "TDC_addHistogram", rc );
          rc = TDC_addHistogram(4, START_CHANNEL, 1 );
          checkRc( "TDC_addHistogram", rc );*/
 }

  void qutagadq::setHistogramsParam(){

      HIST_BINWIDTH=in_binWidth;
      HIST_BINCOUNT=in_binsinplot;

      if((HIST_BINWIDTH!= HIST_BINWIDTH_out || HIST_BINCOUNT!=HIST_BINCOUNT_out) && HIST_BINWIDTH>=1){
        HIST_BINWIDTH_out= HIST_BINWIDTH;
        HIST_BINCOUNT_out = HIST_BINCOUNT;
        std::cout<<"HIST_BINWIDTH  :  "<< HIST_BINWIDTH_out<<std::endl;
        std::cout<<"HIST_BINCOUNT  :  "<< HIST_BINCOUNT_out<<std::endl;
        rc = TDC_setHistogramParams( HIST_BINWIDTH_out, HIST_BINCOUNT_out );
        checkRc( "TDC_setHistogramParams", rc );

      }
       paramschange=false;
  }

 void qutagadq::changThreshold(int ch){

     rc = TDC_configureSignalConditioning(ch, SCOND_MISC, RoF[ch], thresholds[ch]);
     checkRc( "TDC_configureSignalConditioning", rc );

 }

 void qutagadq::set_delays(){
     rc = TDC_setChannelDelays(delays);
     checkRc( "TDC_setChannelDelays", rc );
 }

 void qutagadq::loadtdcfiltertype(){

     for (int i =0; i<5;i++) {
         if(filtertype[i]==FILTER_NONE)filtertypeSTR[i]="NONE";
         if(filtertype[i]==FILTER_MUTE)filtertypeSTR[i]="MUTE";
         if(filtertype[i]==FILTER_COINC)filtertypeSTR[i]="COINC";
         if(filtertype[i]==FILTER_SYNC)filtertypeSTR[i]="SYNC";
         if(filtertype[i]==FILTER_INVALID)filtertypeSTR[i]="INVALID";
         std::cout<<filtertypeSTR[i].toStdString()<<std::endl;
     }

 }
 void qutagadq::updatefiltertype(int ch){
    for (int i =0; i<5;i++) {
        if(filtertypeSTR[i]=="NONE")filtertype[i]=FILTER_NONE;
        if(filtertypeSTR[i]=="MUTE")filtertype[i]=FILTER_MUTE;
        if(filtertypeSTR[i]=="COINC")filtertype[i]=FILTER_COINC;
        if(filtertypeSTR[i]=="SYNC")filtertype[i]=FILTER_SYNC;
    }
    setfilter(ch);
 }

 void qutagadq::setfilter(int ch){
     if(ch==0)rc = TDC_configureFilter(5, filtertype[ch] , ch_filtermask[ch]);
     else rc = TDC_configureFilter(ch, filtertype[ch] , ch_filtermask[ch]);
     checkRc( "TDC_configureFilter", rc );
 }
