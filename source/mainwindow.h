/////////////////////////////////////////////
/// by Lautaro Narvaez
/// For quantum communication aplications
///
/// lautaro@caltech.edu
/// lautaroleon@gmail.com
///
/// third party code from:
/// QT
/// MYSQL
/// Qutools
/// Swabian Instruments
/// qcustomplot
/// /////////////////////////////////////////


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "qcustomplot.h" 
#include <QtCore>
#include <ctime>
#include <stdio.h>
#include "qutag_adq.h"
#include "qutag_anl.h"
#include "dbcontrol.h"
#include "ovdl.h"
#include <math.h>
#include "gui_param.h"
#include "timetaggerultra.h"





namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void closeEvent(QCloseEvent *event);

  void setupPlotA(QCustomPlot *customPlot);
  void setupratePlot(QCustomPlot *customPlot);
  void setupratePlot_tab2(QCustomPlot *customPlot);

  void setupsignalslot();
  void setupsignalslot2();
  void setupHistoPlot(QCustomPlot *customPlot);
  void QUTAG_setup_comboboxes();
  void qutag_paremetes_setup();
  void TTU_paremetes_setup();


private slots:
    void QUTAG_initdone();
    void TTUinitdone();

    void plotRates(int AoB, int event, double key);
    void plotRates_tab2(const vectorInt32 &dat, double key);
    void changeStartchan(int starchan){this->in_startChan=starchan;}

    void histoplot(const vectorDouble &dat1, const vectorDouble &dat2, const vectorDouble &dat3, const vectorDouble &dat4, int count1,int count2 ,int count3 ,int count4 );

    void Chang_in_binsinplot(int val);
    void Chang_in_histStart(int val);
    void Chang_in_binWidth(int val);

    void Chang_in_adqtime(double val){this->in_adqtime=val;}

    void Chang_trackA(bool val);
    void Chang_trackB(bool val);
    void Chang_trackC(bool val);
    void Chang_trackD(bool val);




  void CombinationChange(bool val){CombiChang =val;}

  void Chang_adqtime_2(double val){in_adqtime_2=val;}

  void turnONDB(int val);
  void createTablesDB();
  void SaveState(bool a);
  void LoadState(bool a);
  void SaveSeason(bool a);
  bool LoadPrevoiusSeason(bool a);

  void tab2_plot1_activate(bool val){in_tab2_plot1=val;}
  void tab2_plot2_activate(bool val){in_tab2_plot2=val;}
  void tab2_plot3_activate(bool val){in_tab2_plot3=val;}
  void tab2_plot4_activate(bool val){in_tab2_plot4=val;}
  void tab2_plot5_activate(bool val){in_tab2_plot5=val;}
  void tab2_plot6_activate(bool val){in_tab2_plot6=val;}

  void loadLogicS();
  void saveLogicS();
  void clean_tab2();

  void Chang_delayline(int val){in_delayline=val;}

  void Chang_homscan_time(double val){in_homscan_time=val;}
  void Chang_homscan(int val);

  void chang_tab2range(int val){xrange=val;}


   void resetdelay(){in_delayline=0;prev_homscan=0;}
   void chang_in_max_del(double val){in_Max_delay=val;}

   void chang_in_stepduration(int val){in_stepduration=val;}

   void Chang_in_thch1(double val){this->in_thch1=val;}
   void Chang_in_thch2(double val){this->in_thch2=val;}
   void Chang_in_thch3(double val){this->in_thch3=val;}
   void Chang_in_thch4(double val){this->in_thch4=val;}
   void Chang_in_cw(int val){this->in_cw=val; }

   void setup_log_plot(QCustomPlot *histo);
   void Chang_log1(int val);
   void Chang_log2(int val);
   void Chang_log3(int val);
   void Chang_log4(int val);

   void error1(QString text);

    void chang_QKD_time(double val);
    void chang_QKD_numb(int val);

   void chang_QKD_phA(int val);
   void chang_QKD_pxqA(int val);
   void chang_QKD_iwA(int val);
   void chang_QKD_zeroA(int val);

   void chang_QKD_phB(int val);
   void chang_QKD_pxqB(int val);
   void chang_QKD_iwB(int val);
   void chang_QKD_zeroB(int val);

   void chang_QKD_phC(int val);
   void chang_QKD_pxqC(int val);
   void chang_QKD_iwC(int val);
   void chang_QKD_zeroC(int val);

   void chang_QKD_phD(int val);
   void chang_QKD_pxqD(int val);
   void chang_QKD_iwD(int val);
   void chang_QKD_zeroD(int val);


   void hidelinesQ_A(int qubits);
   void hidelinesW_A(int windows);
   void hidelinesQ_B(int qubits);
   void hidelinesW_B(int windows);
   void hidelinesQ_C(int qubits);
   void hidelinesW_C(int windows);
   void hidelinesQ_D(int qubits);
   void hidelinesW_D(int windows);


   void createQKDLinesA();
   void createQKDLinesB();
   void createQKDLinesC();
   void createQKDLinesD();

   void setup_histolines_QKD();

   void AddLogicSelectorElement();
   void AddLogicSelectorWindowsL(QString t, int index);
   void AddLogicSelectorWindowsR(QString t, int index);

   void updateTab2Windows(QString t, int index);

   void tracktab2_change(bool c, int i);

   void chang_LogicWinL(QString t, int i);
   void chang_LogicWinR(QString t, int i);
   void chang_LogicOP(QString s, int i);

   void chang_VDL_start(double v){in_VDL_start=v;}

   void runQutag(bool a);
   void runTTU(bool a);

   void connectOVDLmw();

private:

  Ui::MainWindow *ui;
    timetaggerUltra TTU1;
  qutagadq qutag;
  qutaganl anl;
  DBControl dbc;
  OVDL ovdl_1;
  QString demoName;
  QTimer dataTimer;
  GUI_param qkdparam;
  QCPItemTracer *itemDemoPhaseTracer;
  int currentDemoIndex;
  double prom;
  QButtonGroup *buttonGroup1 ;
  QButtonGroup *buttonGroup2 ;
  bool trackRateChang =false, CombiChang =false;
  double in_adqtime_2;
  QVector<int> datach1;
  QVector<int> datacali;
  bool dbrunning=false;

  double lastPointKey_tab1;
  double lastPointKey_tab2;

  ////first tab//////
  QMap<QString, int>windows;

  ///general Configs////
  int in_binsinplot, in_startChan, in_binWidth, in_histStart;
  double in_adqtime;

  /////first plot////
  int P_R[4][MAX_WIN]={{0}};
  bool P_T[4][MAX_WIN]={{0}};
  int Plot_Win_BoE[3][3][2]={{{0}}};
  double qkd_prevKey;
  bool initR=false;

  ////SECOND tab////



  int tab2_plot[6][2]={{0}};
  int tab2_win[4][2]={{0}};

  bool in_tab2_plot1=false;
  bool in_tab2_plot2=false;
  bool in_tab2_plot3=false;
  bool in_tab2_plot4=false;
  bool in_tab2_plot5=false;
  bool in_tab2_plot6=false;

  int in_delayline=0;

  bool in_homscan=false;
 double in_homscan_time=1;
 double prev_homscan=0;
 int xrange = 120;
 double in_Max_delay=500;
 bool firstscan=false;
 int in_stepduration;
 double del_key, del_previouskey;

 double in_thch1, in_thch2, in_thch3, in_thch4;
 int in_cw;
 bool RoF[5];
 int logar[4];

 //////lines///////////////

   QCPItemStraightLine *LinesPlotA[MAX_WIN][MAX_QUBITS];
   QCPItemStraightLine *LinesPlotB[MAX_WIN][MAX_QUBITS];
   QCPItemStraightLine *LinesPlotC[MAX_WIN][MAX_QUBITS];
   QCPItemStraightLine *LinesPlotD[MAX_WIN][MAX_QUBITS];

   int   in_QKD_phA=50, in_QKD_iwA=45, in_QKD_pxqA=0, in_QKD_zeroA=1;
   int   in_QKD_phB=50, in_QKD_iwB=45, in_QKD_pxqB=0, in_QKD_zeroB=1;
   int   in_QKD_phC=50, in_QKD_iwC=45, in_QKD_pxqC=0, in_QKD_zeroC=1;
   int   in_QKD_phD=50, in_QKD_iwD=45, in_QKD_pxqD=0, in_QKD_zeroD=1;
   double in_QKD_time=200;
   int  in_QKD_numb=30;

   QLCDNumber *counterA[MAX_WIN];
   QLCDNumber *counterB[MAX_WIN];
   QLCDNumber *counterC[MAX_WIN];
   QLCDNumber *counterD[MAX_WIN];

   QRadioButton *trackA[MAX_WIN];
   QRadioButton *trackB[MAX_WIN];
   QRadioButton *trackC[MAX_WIN];
   QRadioButton *trackD[MAX_WIN];
   QButtonGroup plotAtrackG;
   QButtonGroup plotBtrackG;
   QButtonGroup plotCtrackG;
   QButtonGroup plotDtrackG;

   int numberOfLogicPlots=0;
   QRadioButton *LogicTrack[MAX_LOGIC];
   QComboBox *LogicL[MAX_LOGIC];
   bool leftexpanded[MAX_LOGIC] = {false};
   QComboBox *LogicR[MAX_LOGIC];
   QComboBox *LogicG[MAX_LOGIC];
   QHBoxLayout *LogicBox[MAX_LOGIC];
   QButtonGroup tab2buttongroup;
   QComboBox *LogicWinR[MAX_LOGIC]={nullptr};
   QComboBox *LogicWinL[MAX_LOGIC]={nullptr};

   tab2win *Windowlogic[MAX_LOGIC]={nullptr};

   QStringList plotslist, logicrelations;
   QStringList WindowAlist, WindowBlist, WindowClist, WindowDlist;

   bool trackTab2[MAX_LOGIC]={false};

   QCPGraph *graphtab2[MAX_LOGIC];

   int LSource[MAX_LOGIC]={0};
   int RSource[MAX_LOGIC]={0};
   int LWin[MAX_LOGIC]={0};
   int RWin[MAX_LOGIC]={0};
   int logicOP[MAX_LOGIC]={0};
   double in_VDL_start = 0;



   QDoubleSpinBox *thch[NQUTAGCHANNELS];
   QDoubleSpinBox *delaych[NQUTAGCHANNELS];
   QCheckBox *qutagfilter[NQUTAGCHANNELS][NQUTAGCHANNELS];
   QComboBox *qutagFilterType[NQUTAGCHANNELS];
   QComboBox *qutagEdge[NQUTAGCHANNELS];

   QDoubleSpinBox *threshTTU[NTTUCHANNELS];
   QDoubleSpinBox *delayTTU[NTTUCHANNELS];
   QCheckBox *TTUtriggerfilter[NTTUCHANNELS];
   QCheckBox *TTUfilter[NTTUCHANNELS];
   //QComboBox *qutagFilterType[NQUTAGCHANNELS];
   //QComboBox *qutagEdge[NQUTAGCHANNELS];


signals:

    //void main_CreateTableTab1(QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD );
   void main_CreateTableTab1(int PlotA, int PlotB, int PlotC , int PlotD , QLabel *lab );
    void main_CreateTableTab2(QVector<int> channels, QVector<int> logicL,QVector<int> logicR,QVector<int> WinL,QVector<int> WinR, QVector<bool> gate, QLabel *lab2);
    void main_SaveTab2Values(QVector<int> datatab2, float andTime, double delayline);
    void main_SaveTab1Values(QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD, float hist_adqtime);
    //QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD
    void setOVDL(float timeps);
    void MWChang_qutag_filtertype(QString, int);
    void MWChang_qutag_filtermask(int, int, int);
    void MWChang_qutagThresh(double, int);
    void MWChang_qutag_edge(QString, int);
    void MWChang_qutag_delay(double, int);

    void MWChang_TTUThresh(double, int);
};

class Filtertype: public QWidget{

};

#endif // MAINWINDOW_H
