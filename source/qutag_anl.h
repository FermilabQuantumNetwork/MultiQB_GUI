#ifndef ANLCLASS_H
#define ANLCLASS_H

#include <iostream>
#include <QObject>
#include <QtCore>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>              /* for exit() */
#include <math.h>
#include <qutag_adq.h>
#include <iostream>//entradas y salidas por consola
#include <fstream>//archivos.txt
#include <QtConcurrent/QtConcurrent>
#include <QFuture>

typedef QVector<Int32> vectorInt32;
typedef QVector<int> vectorInt;

#define MAX_LOGIC 25


class qutaganl : public QObject
{
    Q_OBJECT


public:

   bool anlAvilable = false;
  explicit qutaganl();
    //void run();

  QThread anlWorker1;
    ~qutaganl();

    /////histogram Windows////
    /////PlotA =-1    PlotB=-2    PlotC=-3    PlotD=-4/////
    /*int LSource[MAX_LOGIC]={0};
    int RSource[MAX_LOGIC]={0};
    int LWin[MAX_LOGIC]={0};
    int RWin[MAX_LOGIC]={0};
    int numberOfLogicPlots=0;
    bool logicOP[MAX_LOGIC];
    bool flagL[MAX_LOGIC] = {0};
    bool flagR[MAX_LOGIC] = {0};*/

    //QVector<int> LSource;
    //QVector<int> RSource;
   vectorInt RSource;
   vectorInt LSource;
    //QVector<int> LWin;
   //QVector<int> RWin;
   vectorInt LWin;
   vectorInt RWin;
    int numberOfLogicPlots=0;
    QVector<int> logicOP;
    //QVector<bool> flagL;
    //QVector<bool> flagR;

    double clkdiffT;
    ////first plot////
    int in_binsinplot, in_startChan=QUTAG_START_CHANNEL, in_histStart, in_binWidth;
    double in_adqtime;
    int in_PlotACh1, in_PlotACh2, in_PlotBCh1, in_PlotBCh2, in_PlotCCh1, in_PlotCCh2, in_PlotDCh1, in_PlotDCh2;

   //////tab 2 param/////////
    int xtime;
    float adqtime_tab2;


   /* int in_QKD_ph[4];
    int in_QKD_iw[4];
    int in_QKD_zero[4];
    int in_QKD_numb=30;
    int in_QKD_pxq[4]={0};
    double in_QKD_time=200;*/

    /*QVector<int> in_QKD_ph;
    QVector<int> in_QKD_iw;
    QVector<int> in_QKD_zero;
    QVector<int>in_QKD_pxq;*/
    vectorInt in_QKD_ph;
    vectorInt in_QKD_iw;
    vectorInt in_QKD_zero;
    vectorInt in_QKD_pxq;
    double in_QKD_time=200;
    int in_QKD_numb=30;

public slots:



  void timestampREC(const vectorInt64 &inconimg_vectorTimetags, const vectorInt &inconimg_vectorChannels, int inconimg_tsvalid);

  void Chang_in_startChan(int starchan){this->in_startChan=starchan;}
  void Chang_in_PlotAChn1(int val){this->in_PlotACh1=val;}
  void Chang_in_PlotAChn2(int val){this->in_PlotACh2=val;}
  void Chang_in_PlotBChn1(int val){this->in_PlotBCh1=val;}
  void Chang_in_PlotBChn2(int val){this->in_PlotBCh2=val;}
  void Chang_in_PlotCChn1(int val){this->in_PlotCCh1=val;}
  void Chang_in_PlotCChn2(int val){this->in_PlotCCh2=val;}

  void Chang_in_binsinplot(int val){this->in_binsinplot=val;}
  void Chang_in_histStart(int val){this->in_histStart=val;}
  void Chang_in_binWidth(int val){this->in_binWidth=val;}

  void Chang_adqtime_2(double val){this->adqtime_2=val;}

  void chang_QKD_time(double val){in_QKD_time=val;}
  void chang_QKD_numb(int val){in_QKD_numb=val;}

  void chang_QKD_phA(int val){in_QKD_ph[0]=val;}
  void chang_QKD_pxqA(int val){in_QKD_pxq[0]=val;}
  void chang_QKD_iwA(int val){in_QKD_iw[0]=val;}
  void chang_QKD_zeroA(int val){in_QKD_zero[0] =val;}

  void chang_QKD_phB(int val){in_QKD_ph[1]=val;}
  void chang_QKD_pxqB(int val){in_QKD_pxq[1]=val;}
  void chang_QKD_iwB(int val){in_QKD_iw[1]=val;}
  void chang_QKD_zeroB(int val){in_QKD_zero[1] =val;}

  void chang_QKD_phC(int val){in_QKD_ph[2]=val;}
  void chang_QKD_pxqC(int val){in_QKD_pxq[2]=val;}
  void chang_QKD_iwC(int val){in_QKD_iw[2]=val;}
  void chang_QKD_zeroC(int val){in_QKD_zero[2] =val;}

  void chang_QKD_phD(int val){in_QKD_ph[3]=val;}
  void chang_QKD_pxqD(int val){in_QKD_pxq[3]=val;}
  void chang_QKD_iwD(int val){in_QKD_iw[3]=val;}
  void chang_QKD_zeroD(int val){in_QKD_zero[3] =val;}

  void chang_LogicWinL(QString t, int i);
  void chang_LogicWinR(QString t, int i);
  void chang_LogicOP(QString t, int index);

    void Break(){break_= true;}

    void TScumulator(const vectorDouble &counter);
    void saveRawTSon(int a);

    void saveTTondisk(long clk, long tt);

signals:

    void histo1signal(const vectorDouble &TTdata);      //histogram 1 data ready
    void anlongoing(bool ong);                          //analysis program still working
    void Chang_anlAvilable(bool val);
    void CombinationChange(bool val);
    void rates_tab2(const vectorDouble &counters ,double);
    void timestampANL(const vectorInt64 &vectorTimetags, const vectorInt &vectorChannels, int tsvalid,
                                        int numberOfLogicPlots, int in_startChan,
                                        int in_QKD_numb, double in_QKD_time, double clkdiffT,
                                        const vectorInt &LSource, const vectorInt &RSource,
                                        const vectorInt &LWin,const vectorInt &RWin,
                                        const vectorInt &in_QKD_ph, const vectorInt &in_QKD_zero, const vectorInt &in_QKD_iw,
                                        const vectorInt &logicOP, bool saveTSon);
private:
 QFile *rawTT;
 QTextStream *outTSstream;
 bool break_=false;
  QVector<double> histo1data;
  std::ofstream file;
  bool saveTSon =false;
  int ChannelIndex=0, StopIndex=0;//, counterplot[6]={0};
  QVector<int> counterplot;
  //int flag[6][3]= {{0}};
  QVector<int> flagaux;
  QVector<QVector<int>> flag;
  double adqtime_2=0;
  double previouskey;
  double key;
  bool anlbusy =false;
  //bool borrame =false;double firstkey;
  vectorDouble outputCounter;
  //int cumulativeTS=0;
  vectorDouble cumulative;
  int aux1=0, aux2=0;

  vectorInt64 vectorTimetags;
  vectorInt vectorChannels;
  int tsvalid;

 /* void timestampANL(const vectorInt64 &vectorTimetags, const vectorInt8 &vectorChannels, int tsvalid,
                                      int numberOfLogicPlots, int in_startChan,
                                      int in_QKD_numb, double in_QKD_time, double clkdiffT,
                                      const vectorInt8 &LSource, const vectorInt8 &RSource,
                                      const vectorInt8 &LWin,const vectorInt8 &RWin,
                                      const vectorInt8 &in_QKD_ph, const vectorInt8 &in_QKD_zero, const vectorInt8 &in_QKD_iw,
                                      const vectorBool &logicOP);
  */
};

/*class tab2win: public QThread{

Q_OBJECT


public:
    tab2win(int index){this->index=index;}
    int index;
    QString selection;
public slots:
    void AddLogicSelectorWindowsLparser(QString t){this->selection=t; emit AddLogicSelectorWindowsL(t, index);}
    void AddLogicSelectorWindowsRparser(QString t){this->selection=t; emit AddLogicSelectorWindowsR(t, index);}
    void chang_LogicWinLparser(QString t){emit chang_LogicWinL(t, index);}
    void chang_LogicWinRparser(QString t){emit chang_LogicWinR(t, index);}
    void chang_LogicOPparser(QString t){emit chang_LogicOP(t, index);}
    void trackTab2_changeParser(bool c){emit trackTab2_change(c, index);}

signals:
    void AddLogicSelectorWindowsL(QString t, int index);
    void AddLogicSelectorWindowsR(QString t, int index);
    void chang_LogicWinL(QString t, int index);
    void chang_LogicWinR(QString t, int index);
    void chang_LogicOP(QString t, int index);
    void trackTab2_change(bool c, int index);

};
*/
class timestampProcess : public QObject
{
    Q_OBJECT
public:
    timestampProcess();
    ~timestampProcess();

public slots:
    void timestampANL(const vectorInt64 &vectorTimetags, const vectorInt &vectorChannels, int tsvalid,
                                        int numberOfLogicPlots, int in_startChan,
                                        int in_QKD_numb, double in_QKD_time, double clkdiffT,
                                        const vectorInt &LSource, const vectorInt &RSource,
                                        const vectorInt &LWin,const vectorInt &RWin,
                                        const vectorInt &in_QKD_ph, const vectorInt &in_QKD_zero, const vectorInt &in_QKD_iw,
                                        const vectorInt &logicOP, bool saveTSon);

signals:
    void TScumulator_fromThread(const vectorDouble &counter);
    void saveTTondisk_(long clk, long tt);
};

#endif
