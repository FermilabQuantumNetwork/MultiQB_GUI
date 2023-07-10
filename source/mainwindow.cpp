#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <iostream>//entradas y salidas por consola
#include <fstream>//archivos.txt
#include <vector>//min_element//max_exelement//HD
#include <QApplication>
#include <QtCore>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){

  ui->setupUi(this);
  setGeometry(200, 200, 1500, 800);

setupsignalslot();

setWindowTitle(QString("INQNET TDC"));

setupHistoPlot(ui->PlotB);
setupHistoPlot(ui->PlotA);
setupHistoPlot(ui->PlotC);
setupHistoPlot(ui->PlotD);

plotslist<<QString("")<<QString("PlotA")<<QString("PlotB")<< QString("PlotC")<< QString("PlotD");
logicrelations<<QString("")<<QString("AND")<<QString("OR");

setupratePlot(ui->PlotTrack);
setupratePlot_tab2(ui->PlotTab2);

setup_histolines_QKD();


if(LoadPrevoiusSeason(1)){
    std::cout<<"loading hard coded initial values"<<std::endl;

    ui->histStart->setValue(0);

    ui->adqtime->setValue(1);//update rate Adq time

    ui->adqtime_2->setValue(1);


    ui->Max_delayd->setValue(500);
    ui->homscan_timed->setValue(10);
    ui->stepduration->setValue(30);


}

lastPointKey_tab1 = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
lastPointKey_tab2 = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;




//dbc.start();

//anl.start();

//while(adq.isRunning())usleep(100);



/*if(RoF[1])ui->rof1->setCurrentText("Rise");
else ui->rof1->setCurrentText("Fall");
if(RoF[2])ui->rof2->setCurrentText("Rise");
else ui->rof2->setCurrentText("Fall");
if(RoF[3])ui->rof3->setCurrentText("Rise");
else ui->rof3->setCurrentText("Fall");
if(RoF[4])ui->rof4->setCurrentText("Rise");
else ui->rof4->setCurrentText("Fall");
if(RoF[0])ui->rof5->setCurrentText("Rise");
else ui->rof5->setCurrentText("Fall");
*/
//std::cout<<"filtersss   "<<adq.filtertypeSTR[1].toStdString()<<"  "<<adq.filtertypeSTR[2].toStdString()<<"   "<<adq.filtertypeSTR[3].toStdString()<<std::endl;




qkdparam.QKD_setDefault();

setupsignalslot2();

//qutag.start();//the start rutine for the adquisition


//std::cout<<" MAINWINDOW rof"<<adq.RoF[1]<<"rof"<<adq.RoF[2]<<"rof"<<adq.RoF[3]<<"rof"<<adq.RoF[4]<<std::endl;

//adq.initdone = 1;

initR=true;
createQKDLinesA();
createQKDLinesB();
createQKDLinesC();
createQKDLinesD();


//trackFL_A();
//AddLogicSelectorElement();
}


//////////////////////////////////////////////////////////
///////////////////setups///////////////////////////
///////////////////////////////////////////////////////////

void MainWindow::QUTAG_initdone(){
    for (int i=0;i<5;i++)this->RoF[i]=qutag.RoF[i];
    QUTAG_setup_comboboxes();
    qutag_paremetes_setup();

    /*
    for (int i = 0;i<NQUTAGCHANNELS ;i++ ) {
        thch[i]->setValue(qutag.thresholds[i]);
        qutagFilterType[i]->setCurrentText(qutag.filtertypeSTR[i]);
        delaych[i]->setValue(double(qutag.delays[i])/1000);
    }*/




  /*  if(adq.ch_filtermask[1] & 0x01<<1)ui->Filter1_1->setCheckState(Qt::Checked);
    else ui->Filter1_1->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[1] & 0x01<<2)ui->Filter1_2->setCheckState(Qt::Checked);
    else ui->Filter1_2->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[1] & 0x01<<3)ui->Filter1_3->setCheckState(Qt::Checked);
    else ui->Filter1_3->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[1] & 0x01<<4)ui->Filter1_4->setCheckState(Qt::Checked);
    else ui->Filter1_4->setCheckState(Qt::Unchecked);

    if(adq.ch_filtermask[2] & 0x01<<1)ui->Filter2_1->setCheckState(Qt::Checked);
    else ui->Filter2_1->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[2] & 0x01<<2)ui->Filter2_2->setCheckState(Qt::Checked);
    else ui->Filter2_2->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[2] & 0x01<<3)ui->Filter2_3->setCheckState(Qt::Checked);
    else ui->Filter2_3->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[2] & 0x01<<4)ui->Filter2_4->setCheckState(Qt::Checked);
    else ui->Filter2_4->setCheckState(Qt::Unchecked);

    if(adq.ch_filtermask[3] & 0x01<<1)ui->Filter3_1->setCheckState(Qt::Checked);
    else ui->Filter3_1->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[3] & 0x01<<2)ui->Filter3_2->setCheckState(Qt::Checked);
    else ui->Filter3_2->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[3] & 0x01<<3)ui->Filter3_3->setCheckState(Qt::Checked);
    else ui->Filter3_3->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[3] & 0x01<<4)ui->Filter3_4->setCheckState(Qt::Checked);
    else ui->Filter3_4->setCheckState(Qt::Unchecked);

    if(adq.ch_filtermask[4] & 0x01<<1)ui->Filter4_1->setCheckState(Qt::Checked);
    else ui->Filter4_1->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[4] & 0x01<<2)ui->Filter4_2->setCheckState(Qt::Checked);
    else ui->Filter4_2->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[4] & 0x01<<3)ui->Filter4_3->setCheckState(Qt::Checked);
    else ui->Filter4_3->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[4] & 0x01<<4)ui->Filter4_4->setCheckState(Qt::Checked);
    else ui->Filter4_4->setCheckState(Qt::Unchecked);

    if(adq.ch_filtermask[0] & 0x01<<1)ui->Filter5_1->setCheckState(Qt::Checked);
    else ui->Filter5_1->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[0] & 0x01<<2)ui->Filter5_2->setCheckState(Qt::Checked);
    else ui->Filter5_2->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[0] & 0x01<<3)ui->Filter5_3->setCheckState(Qt::Checked);
    else ui->Filter5_3->setCheckState(Qt::Unchecked);
    if(adq.ch_filtermask[0] & 0x01<<4)ui->Filter5_4->setCheckState(Qt::Checked);
    else ui->Filter5_4->setCheckState(Qt::Unchecked);
   */
}
void MainWindow::setup_histolines_QKD(){

    for (int i = 0 ; i<MAX_QUBITS ; i++) {
        for (int j=0; j<MAX_WIN; j++) {
            LinesPlotA[j][i] = new QCPItemStraightLine(ui->PlotA);
            LinesPlotA[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
            LinesPlotA[j][i]->setVisible(0);
        }
    }

        for (int i = 0 ; i<MAX_QUBITS ; i++) {
            for (int j=0; j<MAX_WIN; j++) {
                LinesPlotB[j][i] = new QCPItemStraightLine(ui->PlotB);
                LinesPlotB[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
                LinesPlotB[j][i]->setVisible(0);
            }
    }
        for (int i = 0 ; i<MAX_QUBITS ; i++) {
            for (int j=0; j<MAX_WIN; j++) {
                LinesPlotC[j][i] = new QCPItemStraightLine(ui->PlotC);
                LinesPlotC[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
                LinesPlotC[j][i]->setVisible(0);
            }
    }
        for (int i = 0 ; i<MAX_QUBITS ; i++) {
            for (int j=0; j<MAX_WIN; j++) {
                LinesPlotD[j][i] = new QCPItemStraightLine(ui->PlotD);
                LinesPlotD[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
                LinesPlotD[j][i]->setVisible(0);
            }
    }
}

void MainWindow::setupratePlot(QCustomPlot *scope){


scope->plotLayout()->clear();

QCPAxisRect *wideAxisRect = new QCPAxisRect(scope);


  wideAxisRect->setupFullAxesBox(true);
  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabels(true);
  //wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabels(true);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabelColor(Qt::white);
  //wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickLabelColor(Qt::white);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setBasePen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setSubTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridVisible(true);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridVisible(true);
  //wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setVisible(false);//
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setVisible(false);//
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);

  //wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabel("Counts");
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabel("Time");

  wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabelColor(Qt::white);

  wideAxisRect->setRangeZoom(Qt::Vertical);


 //scope->plotLayout()->addElement(0, 0, title1);
 scope->plotLayout()->addElement(0, 0, wideAxisRect);

  QCPGraph *graph1 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::white),4));
  graph1->setPen(QPen(QColor(200, 0, 0), 2));

  QCPGraph *graph2 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::red),4));
  graph2->setPen(QPen(QColor(0, 200, 0), 2));

  QCPGraph *graph3 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::blue),4));
  graph3->setPen(QPen(QColor(200, 200, 0), 2));

  QCPGraph *graph4 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::green),4));
  graph3->setPen(QPen(QColor(200, 200, 200), 2));



  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(80, 80, 80));
  plotGradient.setColorAt(1, QColor(50, 50, 50));
  scope->setBackground(plotGradient);
  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(80, 80, 80));
  axisRectGradient.setColorAt(1, QColor(30, 30, 30));
  scope->axisRect()->setBackground(axisRectGradient);


  //scope->yAxis->setRange(0, 2);

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  scope->xAxis->setTicker(timeTicker);
  scope->rescaleAxes();
  scope->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MainWindow::setupratePlot_tab2(QCustomPlot *scope){


scope->plotLayout()->clear();

QCPAxisRect *wideAxisRect = new QCPAxisRect(scope);


  wideAxisRect->setupFullAxesBox(true);
  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabels(true);
  //wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabels(true);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabelColor(Qt::white);
  //wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickLabelColor(Qt::white);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setBasePen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setSubTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridVisible(true);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridVisible(true);
  //wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setVisible(false);//
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setVisible(false);//
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);

  //wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabel("Counts");
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabel("Time");

  wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabelColor(Qt::white);

  wideAxisRect->setRangeZoom(Qt::Vertical);


 //scope->plotLayout()->addElement(0, 0, title1);
 scope->plotLayout()->addElement(0, 0, wideAxisRect);

 for (int i=0;i<MAX_LOGIC;i++) {
     graphtab2[i] = new QCPGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
     graphtab2[i]->setPen(QPen(QColor::fromHsv( i*(360/MAX_LOGIC), 255, 255, 255  )));
 }
 /* QCPGraph *graph1 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(128,0,0), 1), QBrush(QColor(240,128,128)),4));
  //graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(200, 0, 0), 1), QBrush(QColor(128,0,0)),4));
  graph1->setPen(QPen(QColor(200, 0, 0), 2));

  QCPGraph *graph2 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(0,100,0), 1), QBrush(QColor(144,238,144)),4));
  //graph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(0, 200, 0), 1), QBrush(QColor(0,128,0)),4));
  graph2->setPen(QPen(QColor(0, 200, 0), 2));

  QCPGraph *graph3 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(189,183,107), 1), QBrush(QColor(255,255,0)),4));
  //graph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(200, 200, 0), 1), QBrush(QColor(255,255,0)),4));
  graph3->setPen(QPen(QColor(200, 200, 0), 2));


  QCPGraph *graph4 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph4->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(72,61,139), 1), QBrush(QColor(230,230,250)),4));
  //graph4->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(173, 127, 168), 1), QBrush(QColor(138,43,226)),4));
  graph4->setPen(QPen(QColor(63, 211, 249), 2));

  QCPGraph *graph5 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph5->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(0,0,139), 1), QBrush(QColor(135,206,250)),4));
  //graph5->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(63, 211, 249), 1), QBrush(QColor(30,144,255)),4));
  graph5->setPen(QPen(QColor(173, 127, 168), 2));

  QCPGraph *graph6 = scope->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  graph6->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(0,0,139), 1), QBrush(QColor(51,51,255)),4));
  //graph5->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(QColor(63, 211, 249), 1), QBrush(QColor(30,144,255)),4));
  graph6->setPen(QPen(QColor(130, 170, 120), 2));


*/



  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(80, 80, 80));
  plotGradient.setColorAt(1, QColor(50, 50, 50));
  scope->setBackground(plotGradient);
  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(80, 80, 80));
  axisRectGradient.setColorAt(1, QColor(30, 30, 30));
  scope->axisRect()->setBackground(axisRectGradient);

  scope->rescaleAxes();
  //scope->yAxis->setRange(0, 2);

  scope->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


}

void MainWindow::setupHistoPlot(QCustomPlot *histograma){

  histograma->plotLayout()->clear();

  QCPAxisRect *wideAxisRect = new QCPAxisRect(histograma);


  wideAxisRect->setupFullAxesBox(true);
  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabels(true);
  wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabels(true);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atTop, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickLabelColor(Qt::white);

  wideAxisRect->axis(QCPAxis::atRight, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setBasePen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setBasePen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atRight, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atTop, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setSubTickPen(QPen(Qt::white, 1));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setSubTickPen(QPen(Qt::white, 1));

  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setSubGridVisible(true);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setSubGridVisible(true);
  //wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setVisible(false);//
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setVisible(false);//
  wideAxisRect->axis(QCPAxis::atLeft, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->grid()->setZeroLinePen(Qt::NoPen);
  wideAxisRect->axis(QCPAxis::atLeft, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setUpperEnding(QCPLineEnding::esSpikeArrow);

  //wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabel("Cuentas");
  //wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabel("Energia");

  wideAxisRect->axis(QCPAxis::atLeft, 0)->setLabelColor(Qt::white);
  wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabelColor(Qt::white);

  wideAxisRect->setRangeZoom(Qt::Horizontal);



  
/*QCPPlotTitle *title1 = new QCPPlotTitle(histograma);
title1->setText("histo");
title1->setFont(QFont("sans", 12, QFont::Bold));
title1->setTextColor(Qt::white);

*/


  //histograma->plotLayout()->addElement(0, 0, title1);
  histograma->plotLayout()->addElement(0, 0, wideAxisRect);


  QCPGraph *graph1 = histograma->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
  //QCPGraph *graph2 = histograma->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));

  graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::white),4));
  graph1->setPen(QPen(QColor(100, 100, 100), 2));
  graph1->setLineStyle((QCPGraph::LineStyle)4);

  histograma->xAxis->setRange(0, 10000);
  //histograma->yAxis->setScaleType(QCPAxis::stLogarithmic);
  //histograma->addGraph();
  //histograma->graph(0)->setPen(QPen(Qt::red));

  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(80, 80, 80));
  plotGradient.setColorAt(1, QColor(50, 50, 50));
  histograma->setBackground(plotGradient);
  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(80, 80, 80));
  axisRectGradient.setColorAt(1, QColor(30, 30, 30));
  histograma->axisRect()->setBackground(axisRectGradient);



 // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  histograma->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


  for (int i=0;i<MAX_WIN;i++) {
      trackA[i] = new QRadioButton(QString(QString::number(i)));
      trackB[i] = new QRadioButton(QString(QString::number(i)));
      trackC[i] = new QRadioButton(QString(QString::number(i)));
      trackD[i] = new QRadioButton(QString(QString::number(i)));
      plotAtrackG.addButton(trackA[i]);
      plotBtrackG.addButton(trackB[i]);
      plotCtrackG.addButton(trackC[i]);
      plotDtrackG.addButton(trackD[i]);

      trackA[i]->setStyleSheet("background-color: rgb(238, 238, 236)");
      trackB[i]->setStyleSheet("background-color: rgb(238, 238, 236)");
      trackC[i]->setStyleSheet("background-color: rgb(238, 238, 236)");
      trackD[i]->setStyleSheet("background-color: rgb(238, 238, 236)");

      counterA[i] = new QLCDNumber(7);
      counterB[i] = new QLCDNumber(7);
      counterC[i] = new QLCDNumber(7);
      counterD[i] = new QLCDNumber(7);
  }

}

void MainWindow::setupsignalslot(){


    //QTimer::singleShot(0, this, SLOT(showFullScreen()));


    qRegisterMetaType<vectorInt64>("vectorInt64");
    qRegisterMetaType<vectorInt32>("vectorInt32");
    qRegisterMetaType<vectorInt8>("vectorInt8");
    qRegisterMetaType<vectorDouble>("vectorDouble");
    qRegisterMetaType<vectorBool>("vectorBool");
    qRegisterMetaType<vectorInt>("vectorInt");

    QObject::connect(ui->adqtime, SIGNAL(valueChanged(double)), this, SLOT(Chang_in_adqtime(double)));
    QObject::connect(ui->adqtime, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_in_adqtime(double)));



    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_histStart(int)));
    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_histStart(int)));
    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_histStart(int)));


    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_binWidth(int)));
    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_binWidth(int)));
    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_binWidth(int)));

    //QObject::connect(this, SIGNAL(valueChanged(int)), &adq, SLOT(Chang_in_binWidth(int)));

    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_binsinplot(int)));
    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_binsinplot(int)));
    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_binsinplot(int)));



    QObject::connect(ui->adqtime_2, SIGNAL(valueChanged(double)), &anl, SLOT(Chang_adqtime_2(double)));
    QObject::connect(ui->adqtime_2, SIGNAL(valueChanged(double)), this, SLOT(Chang_adqtime_2(double)));

    QObject::connect(&anl, SIGNAL(Chang_anlAvilable(bool)), &qutag, SLOT(Chang_anlAvilable(bool)));

    QObject::connect(&anl, SIGNAL(CombinationChange(bool)), this, SLOT(CombinationChange(bool)));
   // QObject::connect(&anl, SIGNAL(CombinationChange(bool)), this, SLOT(CombinationChange(bool)));

    QObject::connect(&qutag, SIGNAL(dataready(vectorInt64, vectorInt, int)), &anl, SLOT(timestampREC(vectorInt64, vectorInt, int)),Qt::QueuedConnection);


    QObject::connect(&anl, SIGNAL(anlongoing(bool)), &qutag, SLOT(adqpausechange(bool)));

    QObject::connect(&qutag, SIGNAL(qutaghist(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )), this, SLOT(histoplot(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )),Qt::QueuedConnection);


    QObject::connect(&anl, SIGNAL(rates_tab2(vectorInt32, double)), this, SLOT(plotRates_tab2(vectorInt32, double)));

    /*QObject::connect(ui->thch1, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_in_thch1(double)));
    QObject::connect(ui->thch2, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_in_thch2(double)));
    QObject::connect(ui->thch3, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_in_thch3(double)));
    QObject::connect(ui->thch4, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_in_thch4(double)));

    QObject::connect(ui->thch1, SIGNAL(valueChanged(double)), this, SLOT(Chang_in_thch1(double)));
    QObject::connect(ui->thch2, SIGNAL(valueChanged(double)), this, SLOT(Chang_in_thch2(double)));
    QObject::connect(ui->thch3, SIGNAL(valueChanged(double)), this, SLOT(Chang_in_thch3(double)));
    QObject::connect(ui->thch4, SIGNAL(valueChanged(double)), this, SLOT(Chang_in_thch4(double)));

    QObject::connect(ui->cw, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_cw(int)));
    QObject::connect(ui->cw, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_cw(int)));*/

    QObject::connect(ui->DBON, SIGNAL(valueChanged(int)), this, SLOT(turnONDB(int)));

    QObject::connect(ui->actionSave_state, SIGNAL(triggered(bool)), this, SLOT(SaveState(bool)));
    QObject::connect(ui->actionLoad_state, SIGNAL(triggered(bool)), this, SLOT(LoadState(bool)));


    QObject::connect(ui->BSM, SIGNAL(released()), this, SLOT(setBSMmeas()));
    QObject::connect(ui->HOM, SIGNAL(released()), this, SLOT(setHOMmeas()));

    //QObject::connect(ui->delayline, SIGNAL(valueChanged(int)), this, SLOT(Chang_delayline(int)));


    QObject::connect(this, SIGNAL(main_CreateTableTab1(int ,int ,int ,int )), &dbc, SLOT(CreateTableTab1(int ,int ,int ,int)));
    QObject::connect(this, SIGNAL( main_CreateTableTab2(vectorInt32,vectorInt32,vectorInt32,vectorInt32,vectorInt32, vectorBool)), &dbc, SLOT(CreateTableTab2(vectorInt32,vectorInt32,vectorInt32,vectorInt32,vectorInt32, vectorBool)),Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(main_SaveTab2Values(vectorInt32, float, double)), &dbc, SLOT(SaveTab2Values(vectorInt32, float, double)),Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(main_SaveTab1Values(vectorInt32,vectorInt32,vectorInt32,vectorInt32,float)), &dbc, SLOT(SaveTab1Values(vectorInt32,vectorInt32,vectorInt32,vectorInt32,float)),Qt::QueuedConnection);
    /*void main_CreateTableTab1(QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD );
    void main_CreateTableTab2(QVector<int> channels, QVector<int> logicL,QVector<int> logicR,QVector<int> WinL,QVector<int> WinR, QVector<bool> gate);
    void main_SaveTab2Values(QVector<int> datatab2, float andTime, int delayline);
    void main_SaveTab1Values(QVector<int> dataplots, float hist_adqtime);*/


    QObject::connect(ui->homscan_timed, SIGNAL(valueChanged(double)), this, SLOT(Chang_homscan_time(double)));
    QObject::connect(ui->homscan, SIGNAL(valueChanged(int)), this, SLOT(Chang_homscan(int)));

    QObject::connect(ui->tab2_xrange, SIGNAL(valueChanged(int)), this, SLOT(chang_tab2range(int)));


    QObject::connect(ui->reset_delay, SIGNAL(released()), this, SLOT(resetdelay()));

    QObject::connect(ui->Max_delayd, SIGNAL(valueChanged(double)), this, SLOT(chang_in_max_del(double)));

    QObject::connect(ui->stepduration, SIGNAL(valueChanged(int)), this, SLOT(chang_in_stepduration(int)));

    QObject::connect(ui->clean_tab2, SIGNAL(released()), this, SLOT(clean_tab2()));

 /*   QObject::connect(ui->rof1, SIGNAL(currentTextChanged(QString)), this, SLOT(Chang_rof1(QString)));
    QObject::connect(ui->rof2, SIGNAL(currentTextChanged(QString)), this, SLOT(Chang_rof2(QString)));
    QObject::connect(ui->rof3, SIGNAL(currentTextChanged(QString)), this, SLOT(Chang_rof3(QString)));
    QObject::connect(ui->rof4, SIGNAL(currentTextChanged(QString)), this, SLOT(Chang_rof4(QString)));*/


    /*QObject::connect(ui->delay1, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_delay1(double)));
    QObject::connect(ui->delay2, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_delay2(double)));
    QObject::connect(ui->delay3, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_delay3(double)));
    QObject::connect(ui->delay4, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_delay4(double)));
    QObject::connect(ui->delay5, SIGNAL(valueChanged(double)), &qutag, SLOT(Chang_delay5(double)));*/

    QObject::connect(&qutag, SIGNAL(TDCerror(QString)), this, SLOT(error1(QString)) );

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_time(double)), this, SLOT(chang_QKD_time(double)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_numb(int)), this, SLOT(chang_QKD_numb(int)));


    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phA(int)), this, SLOT(chang_QKD_phA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phB(int)), this, SLOT(chang_QKD_phB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phC(int)), this, SLOT(chang_QKD_phC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phD(int)), this, SLOT(chang_QKD_phD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwA(int)), this, SLOT(chang_QKD_iwA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwB(int)), this, SLOT(chang_QKD_iwB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwC(int)), this, SLOT(chang_QKD_iwC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwD(int)), this, SLOT(chang_QKD_iwD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqA(int)), this, SLOT(chang_QKD_pxqA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqB(int)), this, SLOT(chang_QKD_pxqB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqC(int)), this, SLOT(chang_QKD_pxqC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqD(int)), this, SLOT(chang_QKD_pxqD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroA(int)), this, SLOT(chang_QKD_zeroA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroB(int)), this, SLOT(chang_QKD_zeroB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroC(int)), this, SLOT(chang_QKD_zeroC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroD(int)), this, SLOT(chang_QKD_zeroD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_time(double)), &anl, SLOT(chang_QKD_time(double)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_numb(int)), &anl, SLOT(chang_QKD_numb(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phA(int)), &anl, SLOT(chang_QKD_phA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phB(int)), &anl, SLOT(chang_QKD_phB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phC(int)), &anl, SLOT(chang_QKD_phC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_phD(int)), &anl, SLOT(chang_QKD_phD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwA(int)), &anl, SLOT(chang_QKD_iwA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwB(int)), &anl, SLOT(chang_QKD_iwB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwC(int)), &anl, SLOT(chang_QKD_iwC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_iwD(int)), &anl, SLOT(chang_QKD_iwD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqA(int)), &anl, SLOT(chang_QKD_pxqA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqB(int)), &anl, SLOT(chang_QKD_pxqB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqC(int)), &anl, SLOT(chang_QKD_pxqC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_pxqD(int)), &anl, SLOT(chang_QKD_pxqD(int)));

    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroA(int)), &anl, SLOT(chang_QKD_zeroA(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroB(int)), &anl, SLOT(chang_QKD_zeroB(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroC(int)), &anl, SLOT(chang_QKD_zeroC(int)));
    QObject::connect(&qkdparam, SIGNAL(sig_QKD_zeroD(int)), &anl, SLOT(chang_QKD_zeroD(int)));

    QObject::connect(ui->actionQKD, SIGNAL(triggered()), &qkdparam, SLOT(show()));

    QObject::connect(ui->AddLogic, SIGNAL(released()), this, SLOT(AddLogicSelectorElement()));

    QObject::connect(ui->TSON, SIGNAL(valueChanged(int)), &qutag, SLOT(TSanl(int)));
    QObject::connect(ui->TSper, SIGNAL(valueChanged(int)), &qutag, SLOT(changTSper(int)));

    QObject::connect(this, SIGNAL(setOVDL(float)), &ovdl_1, SLOT(setDelay(float)));

    QObject::connect(ui->VDL_start, SIGNAL(valueChanged(double)), this, SLOT(chang_VDL_start(double)));

    QObject::connect(&qutag, SIGNAL(initdone()), this , SLOT(QUTAG_initdone()));

     QObject::connect(ui->actioninit_Qutag, SIGNAL(triggered(bool)), this, SLOT(runQutag(bool)));
}

void MainWindow::setupsignalslot2(){

    for (int i=0;i<MAX_WIN;i++) {
        QObject::connect(trackA[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackA(bool)));
        if(i<in_QKD_pxqA)ui->trackFL_A->addRow(counterA[i],trackA[i]);
        QObject::connect(trackB[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackB(bool)));
        if(i<in_QKD_pxqB)ui->trackFL_B->addRow(counterB[i],trackB[i]);
        QObject::connect(trackC[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackC(bool)));
        if(i<in_QKD_pxqC)ui->trackFL_C->addRow(counterC[i],trackC[i]);
        QObject::connect(trackD[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackD(bool)));
        if(i<in_QKD_pxqD)ui->trackFL_D->addRow(counterD[i],trackD[i]);
    }

    /*QObject::connect(&plotAtrackG, SIGNAL(ididToggled(int, bool)), this, SLOT(Chang_trackA(int, bool)));
    QObject::connect(&plotBtrackG, SIGNAL(ididToggled(int, bool)), this, SLOT(Chang_trackB(int, bool)));
    QObject::connect(&plotCtrackG, SIGNAL(ididToggled(int, bool)), this, SLOT(Chang_trackC(int, bool)));
    QObject::connect(&plotDtrackG, SIGNAL(ididToggled(int, bool)), this, SLOT(Chang_trackD(int, bool)));*/

    QObject::connect(ui->rof1, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_rof1(QString)));
    QObject::connect(ui->rof2, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_rof2(QString)));
    QObject::connect(ui->rof3, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_rof3(QString)));
    QObject::connect(ui->rof4, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_rof4(QString)));
    QObject::connect(ui->rof5, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_rof5(QString)));

  /*  QObject::connect(ui->FilterType1, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype1(QString)));
    QObject::connect(ui->FilterType2, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype2(QString)));
    QObject::connect(ui->FilterType3, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype3(QString)));
    QObject::connect(ui->FilterType4, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype4(QString)));
    QObject::connect(ui->FilterType5, SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype5(QString)));

    QObject::connect(ui->Filter1_1, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask1_1(int)));
    QObject::connect(ui->Filter1_2, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask1_2(int)));
    QObject::connect(ui->Filter1_3, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask1_3(int)));
    QObject::connect(ui->Filter1_4, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask1_4(int)));


    QObject::connect(ui->Filter2_1, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask2_1(int)));
    QObject::connect(ui->Filter2_2, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask2_2(int)));
    QObject::connect(ui->Filter2_3, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask2_3(int)));
    QObject::connect(ui->Filter2_4, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask2_4(int)));

    QObject::connect(ui->Filter3_1, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask3_1(int)));
    QObject::connect(ui->Filter3_2, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask3_2(int)));
    QObject::connect(ui->Filter3_3, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask3_3(int)));
    QObject::connect(ui->Filter3_4, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask3_4(int)));

    QObject::connect(ui->Filter4_1, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask4_1(int)));
    QObject::connect(ui->Filter4_2, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask4_2(int)));
    QObject::connect(ui->Filter4_3, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask4_3(int)));
    QObject::connect(ui->Filter4_4, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask4_4(int)));

    QObject::connect(ui->Filter5_1, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask5_1(int)));
    QObject::connect(ui->Filter5_2, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask5_2(int)));
    QObject::connect(ui->Filter5_3, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask5_3(int)));
    QObject::connect(ui->Filter5_4, SIGNAL(stateChanged(int)), &qutag, SLOT(Chang_filtermask5_4(int)));*/
}

//////////////////////////////////////////////////////////
///////////////////plotting///////////////////////////
///////////////////////////////////////////////////////////

void MainWindow::plotRates(int plot, int event, double key){


    double value1 = event; 

   if(plot==0){

        ui->PlotTrack->graph(0)->addData(key-lastPointKey_tab1, value1);
    // remove data of lines that's outside visible range:key, value1
    //ui->PlotTrack->graph(0)->removeDataBefore(key-55);
    // rescale value (vertical) axis to fit the current data:
        //ui->PlotTrack->graph(0)->rescaleValueAxis(true);
      //  lastPointKey_tab1 = key;
 // make key axis range scroll with the data (at a constant range size of 8):
       // ui->PlotTrack->graph(0)->keyAxis()->setRange(key+0.25, 50, Qt::AlignRight);
        //ui->PlotTrack->xAxis->setRange(key, 8, Qt::AlignRight);
        //ui->PlotTrack->replot();
    }
   if(plot==1){
        ui->PlotTrack->graph(1)->addData(key-lastPointKey_tab1, value1);
    }
   if(plot==2){
        ui->PlotTrack->graph(2)->addData(key-lastPointKey_tab1, value1);
    }
   if(plot==3){
        ui->PlotTrack->graph(3)->addData(key-lastPointKey_tab1, value1);
    }


    ui->PlotTrack->xAxis->setRange(key-lastPointKey_tab1, 120, Qt::AlignRight);
   //ui->PlotTrack->yAxis->rescale();

    ui->PlotTrack->replot();

    if(trackRateChang && plot== 0){
        ui->PlotTrack->graph(0)->data()->clear();
        trackRateChang=false;
    }
    if(trackRateChang && plot==1){
        ui->PlotTrack->graph(1)->data()->clear();
        trackRateChang=false;
    }
    if(trackRateChang && plot==2){
        ui->PlotTrack->graph(2)->data()->clear();
        trackRateChang=false;
    }
    if(trackRateChang && plot==3){
        ui->PlotTrack->graph(3)->data()->clear();
        trackRateChang=false;
    }
   //prom=0;
   //promedio.prepend(event);
   //for(int i=0; i<promedio.size(); i++)prom=prom+promedio[i];
   //prom=prom/promedio.size();
   //ui->mediamovil->display(prom);
   //if(promedio.size()>50)promedio.resize(50);
    //lastPointKey_tab1 = key;

}

void MainWindow::plotRates_tab2(const vectorInt32 &counters, double key){
    /*for (int i=0;i<counters.size();i++) {
        std::cout<<counters[i]<<"\t";
    }
    std::cout<<std::endl;*/
    for (int i=0;i<numberOfLogicPlots;i++) {
        if(trackTab2[i]){
            ui->PlotTab2->graph(i)->addData(key-lastPointKey_tab2, counters[i]);
            //ui->PlotTab2->graph(i)->addToLegend();
            if(CombiChang ){
                ui->PlotTab2->graph(i)->data()->clear();
                CombiChang=false;
            }
        }
    }

    if(dbrunning){
        if(in_homscan && prev_homscan<=in_Max_delay){
            del_key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

            if(prev_homscan<in_VDL_start)prev_homscan=in_VDL_start;
            if(del_key-del_previouskey>in_stepduration){
                prev_homscan+=in_homscan_time;
                del_previouskey=del_key;
                setOVDL(float(prev_homscan));
                ui->current_delay_pos->display(prev_homscan);
            }

        }
        emit main_SaveTab2Values(counters, float(in_adqtime_2), prev_homscan);
    }
   ui->PlotTab2->xAxis->setRange(key-lastPointKey_tab2, double(xrange), Qt::AlignRight);
  //ui->PlotTab2->yAxis->rescale();
   ui->PlotTab2->replot();

  /*  if(CombiChang ){
        ui->PlotTab2->graph(0)->data()->clear();
        CombiChang=false;
    }
    if(CombiChang){
        ui->PlotTab2->graph(1)->data()->clear();
        CombiChang=false;
    }
    if(CombiChang){
        ui->PlotTab2->graph(2)->data()->clear();
        CombiChang=false;
    }*/
//lastPointKey_tab2 = key;

}

//////////////////////////////////////////////////////////
///////////////////histograms///////////////////////////
///////////////////////////////////////////////////////////


void MainWindow::histoplot(const vectorDouble &datA, const vectorDouble &datB, const vectorDouble &datC, const vectorDouble &datD, int count1,int count2 ,int count3 ,int count4 ){
    //std::cout<<" histosizes:  "<<datB.size()<<"   "<< datB.size()<<"   "<<datC.size() <<std::endl;
    //double binwidth=((in_histEnd-in_histStart)/in_binsinplot);
    double binwidth=double(in_binWidth);
    //std::cout<<"histogram size   "<<datA.size()<<std::endl;
    int histStart_bins = int(in_histStart/binwidth);
   /* QVector<double> datA_out(datA.size()-histStart_bins);
    QVector<double> datB_out(datB.size()-histStart_bins);
    QVector<double> datC_out(datC.size()-histStart_bins);
    QVector<double> datD_out(datD.size()-histStart_bins);*/
    int maxsize = qMax((datA.size()-histStart_bins),qMax((datB.size()-histStart_bins),qMax((datC.size()-histStart_bins),(datD.size()-histStart_bins))));
    QVector<double> x(maxsize);
    //std::cout<<"size x : "<<x.size()<<std::endl;
//for (int i=in_histStart; i<in_histEnd; i++){


    for (int i=0; i<x.size(); ++i){
        x[i] = binwidth*i+in_histStart;
    }
/*
    for (int i=0; i<datA_out.size(); ++i){
        if(logar[0] && datA[i+in_histStart]>0)datA_out[i] = log10(datA[i+in_histStart]);
        else datA_out[i] = datA[i+in_histStart];
        datA_out[i] = datA[i+histStart_bins];
    }

    for (int i=0; i<datB_out.size(); ++i){

        datB_out[i] = datB[i+histStart_bins];
    }
    for (int i=0; i<datC_out.size(); ++i){

        datC_out[i] = datC[i+histStart_bins];
    }

    for (int i=0; i<datD_out.size(); ++i){
        datD_out[i] = datD[i+histStart_bins];
    }*/
   /* QVector<double> datA_out;
    QVector<double> datB_out;
    QVector<double> datC_out;
    QVector<double> datD_out;
    if(count1>histStart_bins)QVector<double> datA_out = datA.mid(histStart_bins,-1);
    if(count2>histStart_bins)QVector<double> datB_out = datB.mid(histStart_bins,-1);
    if(count3>histStart_bins)QVector<double> datC_out = datC.mid(histStart_bins,-1);
    if(count4>histStart_bins)QVector<double> datD_out = datD.mid(histStart_bins,-1);*/

    QVector<double> datA_out = datA.mid(histStart_bins,-1);
    QVector<double> datB_out = datB.mid(histStart_bins,-1);
    QVector<double> datC_out = datC.mid(histStart_bins,-1);
    QVector<double> datD_out = datD.mid(histStart_bins,-1);

  ui->PlotA->graph(0)->data()->clear();
  ui->PlotA->graph(0)->setData(x, datA_out);
  ui->PlotA->graph(0)->rescaleAxes();
  ui->PlotA->replot();

  ui->PlotB->graph(0)->data()->clear();
  ui->PlotB->graph(0)->setData(x, datB_out);
  ui->PlotB->graph(0)->rescaleAxes();
  ui->PlotB->replot();

  ui->PlotC->graph(0)->data()->clear();
  ui->PlotC->graph(0)->setData(x, datC_out);
  ui->PlotC->graph(0)->rescaleAxes();
  ui->PlotC->replot();

  ui->PlotD->graph(0)->data()->clear();
  ui->PlotD->graph(0)->setData(x, datD_out);
  ui->PlotD->graph(0)->rescaleAxes();
  ui->PlotD->replot();

  for (int D=0; D<datA_out.size(); D++) {
      for (int i=0; i<in_QKD_pxqA; i++) {
          for(int j=0; j<in_QKD_numb;j++){
              if(x[D]>j*in_QKD_time+in_QKD_zeroA+i*in_QKD_phA && x[D]<j*in_QKD_time+in_QKD_zeroA+i*in_QKD_phA+in_QKD_iwA)P_R[0][i]+=datA_out[D];
          }
      }
  }

  for (int D=0; D<datB_out.size(); D++) {
      for (int i=0; i<in_QKD_pxqB; i++) {
          for(int j=0; j<in_QKD_numb;j++){
              if(x[D]>j*in_QKD_time+in_QKD_zeroB+i*in_QKD_phB && x[D]<j*in_QKD_time+in_QKD_zeroB+i*in_QKD_phB+in_QKD_iwB)P_R[1][i]+=datB_out[D];
          }
      }
  }

  for (int D=0; D<datC_out.size(); D++) {
      for (int i=0; i<in_QKD_pxqC; i++) {
          for(int j=0; j<in_QKD_numb;j++){
              if(x[D]>j*in_QKD_time+in_QKD_zeroC+i*in_QKD_phC && x[D]<j*in_QKD_time+in_QKD_zeroC+i*in_QKD_phC+in_QKD_iwC)P_R[2][i]+=datC_out[D];
          }
      }
  }

  for (int D=0; D<datD_out.size(); D++) {
      for (int i=0; i<in_QKD_pxqD; i++) {
          for(int j=0; j<in_QKD_numb;j++){
              if(x[D]>j*in_QKD_time+in_QKD_zeroD+i*in_QKD_phD && x[D]<j*in_QKD_time+in_QKD_zeroD+i*in_QKD_phD+in_QKD_iwD)P_R[3][i]+=datD_out[D];
          }
      }
  }
  double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

  for (int i=0;i<4;i++) {
      for (int j=0;j<4;j++) {
          if(P_T[i][j])plotRates(i, P_R[i][j],key);
      }
  }
    QVector<int> A,B,C,D;
  for(int i=0;i<in_QKD_pxqA;i++) {
      counterA[i]->display(P_R[0][i]);
      //if(P_T[0][i])plotRates(i, P_R[0][i],key);
      A.append(P_R[0][i]);
      P_R[0][i]=0;
  }
  for(int i=0;i<in_QKD_pxqB;i++) {
      counterB[i]->display(P_R[1][i]);
      //if(P_T[1][i])plotRates(i, P_R[1][i],key);
      B.append(P_R[1][i]);
      P_R[1][i]=0;   
  }
  for(int i=0;i<in_QKD_pxqC;i++) {
      counterC[i]->display(P_R[2][i]);
      //if(P_T[2][i])plotRates(i, P_R[2][i],key);
      C.append(P_R[2][i]);
      P_R[2][i]=0;
  }
  for(int i=0;i<in_QKD_pxqD;i++) {
      counterD[i]->display(P_R[3][i]);
      //if(P_T[3][i])plotRates(i, P_R[3][i],key);
      D.append(P_R[3][i]);
      P_R[3][i]=0;
  }

    if(dbrunning)emit main_SaveTab1Values(A, B, C ,D , in_adqtime);
  x.clear();

	
}

void MainWindow::turnONDB(int val){
    if(!dbc.isRunning() && dbrunning == 0 && val==1){
        dbc.run();
        dbrunning=val;
    }
    if(dbc.isRunning() && dbrunning == 1 && val==0){
        dbrunning = val;
        while(dbc.isRunning())usleep(100);
        dbc.~DBControl();
        for (int i=0;i<in_QKD_pxqA;i++) {
            trackA[i]->setEnabled(true);
        }
        for (int i=0;i<in_QKD_pxqB;i++) {
            trackB[i]->setEnabled(true);
        }
        for (int i=0;i<in_QKD_pxqC;i++) {
            trackC[i]->setEnabled(true);
        }
        for (int i=0;i<in_QKD_pxqD;i++) {
            trackD[i]->setEnabled(true);
        }
    }
   // dbrunning=val;
    if(val){
        QVector<int> ActiveChan;
        QVector<int> logicL;
        QVector<int> logicR;
        QVector<int> WinL;
        QVector<int> WinR;
        QVector<bool> gate;

        for (int i=0;i<MAX_LOGIC;i++) {
            //qWarning()<<i;
            if(trackTab2[i]){
                //qWarning()<<i;
                ActiveChan.append(i);
                logicL.append(LSource[i]);
                logicR.append(RSource[i]);
                WinL.append(LWin[i]);
                WinR.append(RWin[i]);
                if(logicOP[i])gate.append(1);
                else gate.append(0);
            }
        }

        for (int i=0;i<in_QKD_pxqA;i++) {
            trackA[i]->setEnabled(false);
        }
        for (int i=0;i<in_QKD_pxqB;i++) {
            trackB[i]->setEnabled(false);
        }
        for (int i=0;i<in_QKD_pxqC;i++) {
            trackC[i]->setEnabled(false);
        }
        for (int i=0;i<in_QKD_pxqD;i++) {
            trackD[i]->setEnabled(false);
        }

        emit main_CreateTableTab1(in_QKD_pxqA,in_QKD_pxqB,in_QKD_pxqC,in_QKD_pxqD);
        emit main_CreateTableTab2(ActiveChan, logicL, logicR, WinL, WinR, gate);
    }
}

void MainWindow::SaveState(bool a){
//std::cout<<"debug"<<std::cout;
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Current Configuration"), "",
            tr("Configuration (*.conf);;All Files (*)"));

   //QString fileName = "test";
    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

            QDataStream out(&file);

                    out.setVersion(QDataStream::Qt_4_5);
                    QMap<QString, int> mapint;
                    QMap<QString, double> mapdouble;
                    QString localstring;


                    for ( int i=0;i<3;i++) {
                           for (int j =0;j<3;j++) {
                               for (int k = 0;k<2;k++) {
                                   localstring = QString("Plot_Win_BoE[%1][%2][%3]").arg(i).arg(j).arg(k);
                                   //std::cout<< localstring.toStdString()<< std::endl;
                                    if(!mapint.contains(localstring))mapint.insert(localstring,Plot_Win_BoE[i][j][k]);
                                    else mapint.value(localstring, Plot_Win_BoE[i][j][k]);
                               }

                           }

                     }

                    for ( int i=0;i<3;i++) {
                           for (int j =0;j<2;j++) {
                                   localstring = QString("tab2_plot[%1][%2]").arg(i).arg(j);
                                   //std::cout<< localstring.toStdString()<< std::endl;
                                    if(!mapint.contains(localstring))mapint.insert(localstring,tab2_plot[i][j]);
                                    else mapint.value(localstring, tab2_plot[i][j]);
                               }
                     }

                    for ( int i=0;i<3;i++) {
                           for (int j =0;j<2;j++) {
                                   localstring = QString("tab2_win[%1][%2]").arg(i).arg(j);
                                   //std::cout<< localstring.toStdString()<< std::endl;
                                    if(!mapint.contains(localstring))mapint.insert(localstring,tab2_win[i][j]);
                                    else mapint.value(localstring, tab2_win[i][j]);
                               }
                     }

                    mapint.insert("in_startChan",in_startChan);

                    mapint.insert("in_histStart",in_histStart);
                    mapint.insert("in_binWidth",in_binWidth);
                    mapint.insert("in_binsinplot",in_binsinplot);

                    mapdouble.insert("in_adqtime", in_adqtime);
                    mapdouble.insert("in_adqtime_2", double(in_adqtime_2));

                    /*mapint.insert("RoF1",int(RoF[1]));
                    mapint.insert("RoF2",int(RoF[2]));
                    mapint.insert("RoF3",int(RoF[3]));
                    mapint.insert("RoF4",int(RoF[4]));*/

                    /*QMapIterator<QString,int>ip(mapint);
                    while (ip.hasNext()) {
                        ip.next();
                        std::cout<< ip.key().toStdString()<< ": " << ip.value() << std::endl;

 double in_thch1, in_thch2,in_thch3,in_thch4;
 int in_cw;
 bool RoF[5];
                    }*/
                    out<<mapint;
                    out<<mapdouble;
            }

   // LoadState(1);
}

bool MainWindow::LoadPrevoiusSeason(bool a){
    std::cout<<"loading previous season parameters"<<std::endl;
    QString fileName = "LastSeasonVariables.conf";
    if (fileName.isEmpty())return 1;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
        file.errorString());
        return 1;
    }



    QMap<QString, int> mapintout;
    QMap<QString, double> mapdoubleout;
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_5);
    in>>mapintout;


    QMapIterator<QString,int>i(mapintout);
    while (i.hasNext()) {
        i.next();
       // std::cout<< i.key().toStdString() <<  ": " << i.value() << std::endl;
    }
    in>>mapdoubleout;
    QMapIterator<QString,double>j(mapdoubleout);
    while (j.hasNext()) {
        j.next();
     //   std::cout<< j.key().toStdString() <<  ": " << j.value() << std::endl;
    }

    if(mapintout.contains("in_histStart"))ui->histStart->setValue(mapintout.value("in_histStart"));
    else ui->histStart->setValue(0);
    if(mapintout.contains("in_binWidth"))ui->binWidth->setValue(mapintout.value("in_binWidth"));
    else ui->binWidth->setValue(1);
    if(mapintout.contains("in_binsinplot"))ui->binsinplot->setValue(mapintout.value("in_binsinplot"));
    else ui->binsinplot->setValue(1000);
    if(mapdoubleout.contains("in_adqtime"))ui->adqtime->setValue(mapdoubleout.value("in_adqtime"));
    else ui->adqtime->setValue(1);

    if(mapdoubleout.contains("in_adqtime_2"))ui->adqtime_2->setValue(mapdoubleout.value("in_adqtime_2"));
    else ui->adqtime_2->setValue(1);
    if(mapdoubleout.contains("Max_delay"))ui->Max_delayd->setValue(mapdoubleout.value("Max_delay"));
    else ui->Max_delayd->setValue(500);
    if(mapintout.contains("stepduration"))ui->stepduration->setValue(mapintout.value("stepduration"));
    else ui->stepduration->setValue(30);
    if(mapintout.contains("homscan_time"))ui->homscan_timed->setValue(mapintout.value("homscan_time"));
    else ui->homscan_timed->setValue(1);

    if(mapintout.contains("TSper"))ui->TSper->setValue(mapintout.value("TSper"));
    else ui->TSper->setValue(10);


/*
       QMapIterator<QString,int>i(mapintout);
       while (i.hasNext()) {
           i.next();
           std::cout<< i.key().toStdString() <<  ": " << i.value() << std::endl;
       }
       in>>mapdoubleout;
       QMapIterator<QString,double>j(mapdoubleout);
       while (j.hasNext()) {
           j.next();
           std::cout<< j.key().toStdString() <<  ": " << j.value() << std::endl;
       }

*/
     std::cout<<"parameters loaded"<<std::endl;
    return 0;
}

void MainWindow::SaveSeason(bool a){

    QString CurrentSeason = "LastSeasonVariables.conf";

    QFile file(CurrentSeason);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
        file.errorString());
        return;
    }

    QDataStream out(&file);

    out.setVersion(QDataStream::Qt_4_5);
    QMap<QString, int> mapint;
    QMap<QString, double> mapdouble;
    QString localstring;

    mapint.insert("in_startChan",in_startChan);

    mapint.insert("in_histStart",in_histStart);
    mapint.insert("in_binsinplot",in_binsinplot);
    mapint.insert("in_binWidth",in_binWidth);

    mapdouble.insert("in_adqtime", in_adqtime);
    mapdouble.insert("in_adqtime_2", double(in_adqtime_2));


    mapdouble.insert("QKD_time",in_QKD_time);
    mapint.insert("QKD_numb",in_QKD_numb);

    mapint.insert("QKD_phA",in_QKD_phA);
    mapint.insert("QKD_iwA",in_QKD_iwA);
    mapint.insert("QKD_pxqA",in_QKD_pxqA);
    mapint.insert("QKD_zeroA",in_QKD_zeroA);

    mapint.insert("QKD_phB",in_QKD_phB);
    mapint.insert("QKD_iwB",in_QKD_iwB);
    mapint.insert("QKD_pxqB",in_QKD_pxqB);
    mapint.insert("QKD_zeroB",in_QKD_zeroB);

    mapint.insert("QKD_phC",in_QKD_phC);
    mapint.insert("QKD_iwC",in_QKD_iwC);
    mapint.insert("QKD_pxqC",in_QKD_pxqC);
    mapint.insert("QKD_zeroC",in_QKD_zeroC);

    mapint.insert("QKD_phD",in_QKD_phD);
    mapint.insert("QKD_iwD",in_QKD_iwD);
    mapint.insert("QKD_pxqD",in_QKD_pxqD);
    mapint.insert("QKD_zeroD",in_QKD_zeroD);

    mapint.insert("TSper",qutag.TSpercentage);



    mapdouble.insert("Max_delay",in_Max_delay);
    mapdouble.insert("homscan_time",in_homscan_time);
    mapint.insert("stepduration",in_stepduration);


    out<<mapint;
    out<<mapdouble;

   // LoadState(1);
}

void MainWindow::LoadState(bool a){
    QString fileName = QFileDialog::getOpenFileName(this,
                tr("Load Configuration"), "",
                tr("Configuration (*.conf);;All Files (*)"));
        //QString fileName = "test";
        if (fileName.isEmpty())
                return;
    else {

            QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            QMap<QString, int> mapintout;
            QMap<QString, double> mapdoubleout;
            QDataStream in(&file);
            in.setVersion(QDataStream::Qt_4_5);
            in>>mapintout;





            if(mapintout.contains("in_histStart"))ui->histStart->setValue(mapintout.value("in_histStart"));
            //if(mapintout.contains("in_histEnd"))ui->histEnd->setValue(mapintout.value("in_histEnd"));
            if(mapintout.contains("in_binsinplot"))ui->binsinplot->setValue(mapintout.value("in_binsinplot"));

            if(mapdoubleout.contains("in_adqtime"))ui->adqtime->setValue(mapdoubleout.value("in_adqtime"));
            if(mapdoubleout.contains("in_adqtime_2"))ui->adqtime_2->setValue(mapdoubleout.value("in_adqtime_2"));


            /*if(mapintout.contains("RoF1")){
                if(mapintout.value("RoF1"))ui->rof1->setCurrentText("Rise");
            }
            else ui->rof1->setCurrentText("Fall");

            if(mapintout.contains("RoF2")){
                if(mapintout.value("RoF2"))ui->rof2->setCurrentText("Rise");
            }
            else ui->rof2->setCurrentText("Fall");

            if(mapintout.contains("RoF3")){
                if(mapintout.value("RoF3"))ui->rof3->setCurrentText("Rise");
            }
            else ui->rof3->setCurrentText("Fall");

            if(mapintout.contains("RoF4")){
                if(mapintout.value("RoF4"))ui->rof4->setCurrentText("Rise");
            }
            else ui->rof4->setCurrentText("Fall");
*/


               QMapIterator<QString,int>i(mapintout);
               while (i.hasNext()) {
                   i.next();
                   std::cout<< i.key().toStdString() <<  ": " << i.value() << std::endl;
               }
               in>>mapdoubleout;
               QMapIterator<QString,double>j(mapdoubleout);
               while (j.hasNext()) {
                   j.next();
                   std::cout<< j.key().toStdString() <<  ": " << j.value() << std::endl;
               }

    }

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setBSMmeas(){

    //ui->win3_2->setValue(2);

}

void MainWindow::setHOMmeas(){

    QMessageBox msgBox;
    msgBox.setText("Still to do :P");
    msgBox.exec();
}

void MainWindow::clean_tab2(){

    QMessageBox msgBox;
    msgBox.setText("Still to do :P");
    msgBox.exec();
}

void MainWindow::Chang_homscan(int val){
    in_homscan=bool(val);
    if(in_homscan && !firstscan){
        firstscan=true;
        del_previouskey = 0;
    }
}

void MainWindow::error1(QString text){
	QMessageBox msgBox;
    msgBox.setText(text);
	msgBox.exec();
}

void MainWindow::closeEvent(QCloseEvent *event){
   SaveSeason(1);
   std::cout<<"going out"<<std::endl;
   qutag.Break();
   anl.Break();
   qutag.quit();
   //anl.quit();
   dbc.quit();
   //usleep(100);
   //adq.~qutagadq();
   //usleep(100e3);
   std::cout<<"destroy"<<std::endl;
   //dbc.~DBControl();


   while(qutag.isRunning())sleep(1);std::cout<<"adq"<<std::endl;
   //while(anl.isRunning())sleep(1);std::cout<<"anl"<<std::endl;
   while( dbc.isRunning())sleep(1);std::cout<<"dbc"<<std::endl;
   //usleep(1000);
   event->accept();

//else event->ignore();

}

void MainWindow::Chang_in_binsinplot(int val){
    this->in_binsinplot=val;
    ui->HistoEndDisplay->display(in_binWidth*in_binsinplot);
}

void MainWindow::Chang_in_histStart(int val){
    this->in_histStart=val;
    ui->HistoEndDisplay->display(in_binWidth*in_binsinplot);
}

void MainWindow::Chang_in_binWidth(int val){
    this->in_binWidth=val;
    ui->HistoEndDisplay->display(in_binWidth*in_binsinplot);
}

void MainWindow::Chang_log1(int val){
    if(val){
        setup_log_plot(ui->PlotA);
    }else{
        setupHistoPlot(ui->PlotA);
    }
}
void MainWindow::Chang_log2(int val){
    if(val){
        setup_log_plot(ui->PlotB);
    }else{
        setupHistoPlot(ui->PlotB);
    }
}
void MainWindow::Chang_log3(int val){
    if(val){
        setup_log_plot(ui->PlotC);
    }else{
        setupHistoPlot(ui->PlotC);
    }
}
void MainWindow::Chang_log4(int val){
    if(val){
        setup_log_plot(ui->PlotD);
    }else{
        setupHistoPlot(ui->PlotD);
    }
}
void MainWindow::setup_log_plot(QCustomPlot *histo){

    histo->yAxis->grid()->setSubGridVisible(true);
    histo->xAxis->grid()->setSubGridVisible(true);
    histo->yAxis->setScaleType(QCPAxis::stLogarithmic);
    histo->yAxis2->setScaleType(QCPAxis::stLogarithmic);
    //ui->PlotA->xAxis->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    histo->yAxis->setTicker(logTicker);
    histo->yAxis2->setTicker(logTicker);
    histo->yAxis->setNumberFormat("eb"); // e = exponential, b = beautiful decimal powers
    histo->yAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"

}

void MainWindow::QUTAG_setup_comboboxes(){

    ui->rof1->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    ui->rof2->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    ui->rof3->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    ui->rof4->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    ui->rof5->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");



    ui->rof1->addItem(tr("Rise"));
    ui->rof1->addItem(tr("Fall"));
    ui->rof2->addItem(tr("Rise"));
    ui->rof2->addItem(tr("Fall"));
    ui->rof3->addItem(tr("Rise"));
    ui->rof3->addItem(tr("Fall"));
    ui->rof4->addItem(tr("Rise"));
    ui->rof4->addItem(tr("Fall"));
    ui->rof5->addItem(tr("Rise"));
    ui->rof5->addItem(tr("Fall"));


    tab2buttongroup.setExclusive(0);
}

void MainWindow::createQKDLinesA(){

    for(int i=0; i<in_QKD_numb*2; i++){
        for (int j=0;j<in_QKD_pxqA;j++) {
            if((i+1)%2){
                LinesPlotA[j][i]->setVisible(1);
                LinesPlotA[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroA+j*in_QKD_phA,0);
                LinesPlotA[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroA+j*in_QKD_phA,1);
                //if(i==0 && WindowAlist.size()<i/2)WindowAlist<<(QString("w")+QString::number(i/2));
            }
            else{
                LinesPlotA[j][i]->setVisible(1);
                LinesPlotA[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroA+in_QKD_iwA+j*in_QKD_phA,0);
                LinesPlotA[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroA+in_QKD_iwA+j*in_QKD_phA,1);
            }
        //if(i==0 && QubitsAlist.size()<j)QubitsAlist<<(QString("q")+QString::number(j));
        }
    }


    if(in_QKD_pxqA > ui->trackFL_A->rowCount()-1)ui->trackFL_A->addRow(counterA[in_QKD_pxqA-1],trackA[in_QKD_pxqA-1]);
    ui->PlotA->replot();
}
void MainWindow::createQKDLinesB(){
    for(int i=0; i<in_QKD_numb*2; i++){
        for (int j=0;j<in_QKD_pxqB;j++) {
            if((i+1)%2){
               LinesPlotB[j][i]->setVisible(1);
               LinesPlotB[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroB+j*in_QKD_phB,0);
               LinesPlotB[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroB+j*in_QKD_phB,1);
               //if(j==0 && WindowBlist.size()<i/2)WindowBlist<<QString::number(i/2);
            }
            else{
               LinesPlotB[j][i]->setVisible(1);
               LinesPlotB[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroB+in_QKD_iwB+j*in_QKD_phB,0);
               LinesPlotB[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroB+in_QKD_iwB+j*in_QKD_phB,1);

            }
        }
    }

    if(in_QKD_pxqB > ui->trackFL_B->rowCount()-1)ui->trackFL_B->addRow(counterB[in_QKD_pxqB-1],trackB[in_QKD_pxqB-1]);
    ui->PlotB->replot();
}
void MainWindow::createQKDLinesC(){
    for(int i=0; i<in_QKD_numb*2; i++){
        for (int j=0;j<in_QKD_pxqC;j++) {
            if((i+1)%2){
               LinesPlotC[j][i]->setVisible(1);
               LinesPlotC[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroC+j*in_QKD_phC,0);
               LinesPlotC[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroC+j*in_QKD_phC,1);
               //if(j==0 && WindowClist.size()<i/2)WindowClist<<QString::number(i/2);

            }
            else{
               LinesPlotC[j][i]->setVisible(1);
               LinesPlotC[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroC+in_QKD_iwC+j*in_QKD_phC,0);
               LinesPlotC[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroC+in_QKD_iwC+j*in_QKD_phC,1);

            }
        }
    }

    if(in_QKD_pxqC > ui->trackFL_C->rowCount()-1)ui->trackFL_C->addRow(counterC[in_QKD_pxqC-1],trackC[in_QKD_pxqC-1]);
    ui->PlotC->replot();
}
void MainWindow::createQKDLinesD(){
    for(int i=0; i<in_QKD_numb*2; i++){
        for (int j=0;j<in_QKD_pxqD;j++) {
            if((i+1)%2){
               LinesPlotD[j][i]->setVisible(1);
               LinesPlotD[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroD+j*in_QKD_phD,0);
               LinesPlotD[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroD+j*in_QKD_phD,1);

            }
            else{
               LinesPlotD[j][i]->setVisible(1);
               LinesPlotD[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroD+in_QKD_iwD+j*in_QKD_phD,0);
               LinesPlotD[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroD+in_QKD_iwD+j*in_QKD_phD,1);

            }
        }
    }

    if(in_QKD_pxqD > ui->trackFL_D->rowCount()-1)ui->trackFL_D->addRow(counterD[in_QKD_pxqD-1],trackD[in_QKD_pxqD-1]);
    ui->PlotD->replot();
}

void MainWindow::hidelinesQ_A(int qubits){

    for (int i= 2*qubits;i<2*in_QKD_numb;i++) {
        for (int j=0;j<MAX_WIN;j++) {
            LinesPlotA[j][i]->setVisible(0);
            //if(j==0 && WindowAlist.size()>i/2)WindowAlist.takeLast();
        }
    }   
}
void MainWindow::hidelinesW_A(int win){

    for (int i=0;i<2*in_QKD_numb;i++) {
        for (int j=win;j<in_QKD_pxqA;j++) {
            LinesPlotA[j][i]->setVisible(0);
            if(i==0){
                ui->trackFL_A->removeRow(j+1);
                trackA[j] = new QRadioButton(QString(QString::number(j)));
                plotAtrackG.addButton(trackA[j]);
                trackA[j]->setStyleSheet("background-color: rgb(238, 238, 236)");
                counterA[j] = new QLCDNumber(7);
            }
        }

    }

}
void MainWindow::hidelinesQ_B(int qubits){

    for (int i= 2*qubits;i<2*in_QKD_numb;i++) {
        for (int j=0;j<MAX_WIN;j++) {
            LinesPlotB[j][i]->setVisible(0);
        }
    }
}
void MainWindow::hidelinesW_B(int win){

 for (int i=0;i<2*in_QKD_numb;i++) {
    for (int j=win;j<in_QKD_pxqB;j++) {
        LinesPlotB[j][i]->setVisible(0);
        if(i==0){
            ui->trackFL_B->removeRow(j+1);
            trackB[j] = new QRadioButton(QString(QString::number(j)));
            plotBtrackG.addButton(trackB[j]);
            trackB[j]->setStyleSheet("background-color: rgb(238, 238, 236)");
            counterB[j] = new QLCDNumber(7);
        }
     }

  }

}
void MainWindow::hidelinesQ_C(int qubits){

    for (int i= 2*qubits;i<2*in_QKD_numb;i++) {
        for (int j=0;j<MAX_WIN;j++) {
            LinesPlotC[j][i]->setVisible(0);
        }
    }
}
void MainWindow::hidelinesW_C(int win){

    for (int i=0;i<2*in_QKD_numb;i++) {
        for (int j=win;j<in_QKD_pxqC;j++) {
           LinesPlotC[j][i]->setVisible(0);
           if(i==0){
              ui->trackFL_C->removeRow(j+1);
              trackC[j] = new QRadioButton(QString(QString::number(j)));
              plotCtrackG.addButton(trackC[j]);
              trackC[j]->setStyleSheet("background-color: rgb(238, 238, 236)");
              counterC[j] = new QLCDNumber(7);
            }
        }

    }

}
void MainWindow::hidelinesQ_D(int qubits){

    for (int i= 2*qubits;i<2*in_QKD_numb;i++) {
        for (int j=0;j<MAX_WIN;j++) {
            LinesPlotD[j][i]->setVisible(0);
        }
    }
}
void MainWindow::hidelinesW_D(int win){

 for (int i=0;i<2*in_QKD_numb;i++) {
    for (int j=win;j<in_QKD_pxqD;j++) {
        LinesPlotD[j][i]->setVisible(0);
        if(i==0){
           ui->trackFL_D->removeRow(j+1);
           trackD[j] = new QRadioButton(QString(QString::number(j)));
           plotDtrackG.addButton(trackD[j]);
           trackD[j]->setStyleSheet("background-color: rgb(238, 238, 236)");
           counterD[j] = new QLCDNumber(7);
         }
        }
    }

}

void MainWindow::AddLogicSelectorElement(){

    int i = numberOfLogicPlots;

    Windowlogic[i]= new tab2win(i);

    LogicTrack[i] = new QRadioButton(QString(QString::number(i)));
    LogicTrack[i]->setStyleSheet("background-color: rgb(238, 238, 236)");
    tab2buttongroup.addButton(LogicTrack[i]);
    QObject::connect(LogicTrack[i], SIGNAL(toggled(bool)), Windowlogic[i], SLOT(trackTab2_changeParser(bool)));
    QObject::connect(Windowlogic[i], SIGNAL(trackTab2_change(bool, int)),this, SLOT(tracktab2_change(bool, int)));
    //QObject::connect(LogicTrack[i], SIGNAL(toggled(bool)), Windowlogic[i], SLOT(trackTab2_changeParser(bool)));

    LogicL[i] = new QComboBox();
    LogicL[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    LogicL[i]->addItems(plotslist);
    QObject::connect(LogicL[i], SIGNAL(currentTextChanged(QString)), Windowlogic[i], SLOT(AddLogicSelectorWindowsLparser(QString)));
    QObject::connect(Windowlogic[i], SIGNAL(AddLogicSelectorWindowsL(QString, int)), this, SLOT(AddLogicSelectorWindowsL(QString, int)));

   if(i>0){
        for (int j=i-1;j>=0;j--) {
            LogicL[i]->addItem(QString::number(j));
        }
    }

    LogicG[i] = new QComboBox();
    LogicG[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    LogicG[i]->addItems(logicrelations);
    QObject::connect(LogicG[i], SIGNAL(currentTextChanged(QString)), Windowlogic[i], SLOT(chang_LogicOPparser(QString)));
    QObject::connect(Windowlogic[i], SIGNAL(chang_LogicOP(QString, int)), &anl, SLOT(chang_LogicOP(QString, int)));
    QObject::connect(Windowlogic[i], SIGNAL(chang_LogicOP(QString, int)), this, SLOT(chang_LogicOP(QString, int)));

    LogicR[i] = new QComboBox();
    LogicR[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
    LogicR[i]->addItems(plotslist);
    QObject::connect(LogicR[i], SIGNAL(currentTextChanged(QString)), Windowlogic[i], SLOT(AddLogicSelectorWindowsRparser(QString)));
    QObject::connect(Windowlogic[i], SIGNAL(AddLogicSelectorWindowsR(QString, int)), this, SLOT(AddLogicSelectorWindowsR(QString, int)));

   if(i>0){
        for (int j=i-1;j>=0;j--) {
            LogicR[i]->addItem(QString::number(j));
        }
    }

    LogicBox[i] = new QHBoxLayout();
    LogicBox[i]->addWidget(LogicTrack[i]);
    LogicBox[i]->addWidget(LogicL[i]);

    LogicBox[i]->addWidget(LogicG[i]);
    LogicBox[i]->addWidget(LogicR[i]);


    ui->LogicSelector->addLayout(LogicBox[i]);

    numberOfLogicPlots++;
    anl.numberOfLogicPlots=this->numberOfLogicPlots;
    dbc.numberOfLogicPlots=this->numberOfLogicPlots;
}

void MainWindow::AddLogicSelectorWindowsL(QString t, int index){
//std::cout<<"outside plot add   text:"<<t.toStdString()<<" index:  "<<index<<std::endl;

    if((t.compare("PlotA")==0 || t.compare("PlotB")==0 || t.compare("PlotC")==0 || t.compare("PlotD")==0) && LogicWinL[index]==nullptr){
        LogicWinL[index] = new QComboBox();
        LogicWinL[index]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        LogicBox[index]->insertWidget(2, LogicWinL[index]);
        QObject::connect(LogicWinL[index], SIGNAL(currentTextChanged(QString)), Windowlogic[index], SLOT(chang_LogicWinLparser(QString)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinL(QString, int)), &anl, SLOT(chang_LogicWinL(QString, int)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinL(QString, int)), this, SLOT(chang_LogicWinL(QString, int)));
        leftexpanded[index]=true;
        //std::cout<<"inside plot add  text:"<<t.toStdString()<<" index:  "<<index<<std::endl;
    }
    else {
        anl.LSource[index]=t.toInt();
        this->LSource[index]=t.toInt();
    }

    updateTab2Windows(t,index);

}

void MainWindow::AddLogicSelectorWindowsR(QString t, int index){
    int position;
    if(leftexpanded[index])position=5;
    else position=6;
   if((t.compare("PlotA")==0 || t.compare("PlotB")==0 || t.compare("PlotC")==0 || t.compare("PlotD")==0) && LogicWinR[index]==nullptr){
        LogicWinR[index] = new QComboBox();
        LogicWinR[index]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        LogicBox[index]->insertWidget(position, LogicWinR[index]);
        QObject::connect(LogicWinR[index], SIGNAL(currentTextChanged(QString)), Windowlogic[index], SLOT(chang_LogicWinRparser(QString)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinR(QString, int)), &anl, SLOT(chang_LogicWinR(QString, int)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinR(QString, int)), this, SLOT(chang_LogicWinR(QString, int)));
    }
   else {
       anl.RSource[index]=t.toInt();
       this->RSource[index]=t.toInt();
   }
   updateTab2Windows(t,index);
}

void MainWindow::updateTab2Windows(QString t, int index){

    if(t.compare("PlotA")==0){
        if(LogicWinL[index]!=nullptr && LogicL[index]->currentText().compare("PlotA")==0){
            LogicWinL[index]->clear();
            LogicWinL[index]->addItems(WindowAlist);
            anl.LSource[index]=-1;
            this->LSource[index]=-1;
        }
        if(LogicWinR[index]!=nullptr && LogicR[index]->currentText().compare("PlotA")==0){
            LogicWinR[index]->clear();
            LogicWinR[index]->addItems(WindowAlist);
            anl.RSource[index]=-1;
            this->RSource[index]=-1;
        }

    }
    if(t.compare("PlotB")==0){
        if(LogicWinL[index]!=nullptr && LogicL[index]->currentText().compare("PlotB")==0){
            LogicWinL[index]->clear();
            LogicWinL[index]->addItems(WindowBlist);
            anl.LSource[index]=-2;
            this->LSource[index]=-2;
        }
        if(LogicWinR[index]!=nullptr && LogicR[index]->currentText().compare("PlotB")==0){
            LogicWinR[index]->clear();
            LogicWinR[index]->addItems(WindowBlist);
            anl.RSource[index]=-2;
            this->RSource[index]=-2;
        }
    }
    if(t.compare("PlotC")==0){
        if(LogicWinL[index]!=nullptr && LogicL[index]->currentText().compare("PlotC")==0){
            LogicWinL[index]->clear();
            LogicWinL[index]->addItems(WindowClist);
            anl.LSource[index]=-3;
            this->LSource[index]=-3;
        }
        if(LogicWinR[index]!=nullptr && LogicR[index]->currentText().compare("PlotC")==0){
            LogicWinR[index]->clear();
            LogicWinR[index]->addItems(WindowClist);
            anl.RSource[index]=-3;
            this->RSource[index]=-3;
        }
    }
    if(t.compare("PlotD")==0){
        if(LogicWinL[index]!=nullptr && LogicL[index]->currentText().compare("PlotD")==0){
            LogicWinL[index]->clear();
            LogicWinL[index]->addItems(WindowDlist);
            anl.LSource[index]=-4;
            this->LSource[index]=-4;
        }
        if(LogicWinR[index]!=nullptr && LogicR[index]->currentText().compare("PlotD")==0){
            LogicWinR[index]->clear();
            LogicWinR[index]->addItems(WindowDlist);
            anl.RSource[index]=-4;
            this->RSource[index]=-4;
        }
    }
    //if(t.compare("PlotA")!=0 && t.compare("PlotB")!=0 && t.compare("PlotC")!=0 && t.compare("PlotD")!=0)anl.LWin[index]=
    /*QRegularExpression rx("\\d\\d");
    QRegularExpressionMatch match = rx.match(t);
    std::cout<<t.toStdString()<<"\t cap:"<<match.captured(0).toStdString()<<std::endl;*/
}

void MainWindow::chang_QKD_time(double val){
    in_QKD_time=val;
    if(initR){
        createQKDLinesA();
        createQKDLinesB();
        createQKDLinesC();
        createQKDLinesD();
    }
}
void MainWindow::chang_QKD_numb(int val){
    if(in_QKD_numb>val){
        hidelinesQ_A(val);
        hidelinesQ_B(val);
        hidelinesQ_C(val);
        hidelinesQ_D(val);
    }
    in_QKD_numb=val;
    createQKDLinesA();
    createQKDLinesB();
    createQKDLinesC();
    createQKDLinesD();
}

void MainWindow::chang_QKD_phA(int val){
    in_QKD_phA=val;
    if(initR)createQKDLinesA();
}

void MainWindow::chang_QKD_pxqA(int val){
    if(in_QKD_pxqA>val)hidelinesW_A(val);
    in_QKD_pxqA=val;
    if(initR)createQKDLinesA();

    WindowAlist.clear();
    WindowAlist<<"";
    for (int j=0;j<in_QKD_pxqA;j++) {
        WindowAlist<<(QString("w")+QString::number(j));
    }
    for (int index=0;index<numberOfLogicPlots;index++) {
        updateTab2Windows("PlotA",index);
    }
}
void MainWindow::chang_QKD_iwA(int val){
    in_QKD_iwA=val;
    if(initR)createQKDLinesA();
}
void MainWindow::chang_QKD_zeroA(int val){
    in_QKD_zeroA =val;
    if(initR)createQKDLinesA();
}

void MainWindow::chang_QKD_phB(int val){
    in_QKD_phB=val;
    if(initR)createQKDLinesB();
}

void MainWindow::chang_QKD_pxqB(int val){
    if(in_QKD_pxqB>val)hidelinesW_B(val);
    in_QKD_pxqB=val;
    if(initR)createQKDLinesB();

    WindowBlist.clear();
    WindowBlist<<"";
    for (int j=0;j<in_QKD_pxqB;j++) {
        WindowBlist<<(QString("w")+QString::number(j));
    }
    for (int index=0;index<numberOfLogicPlots;index++) {
        updateTab2Windows("PlotB",index);
    }
}
void MainWindow::chang_QKD_iwB(int val){
    in_QKD_iwB=val;
    if(initR)createQKDLinesB();
}
void MainWindow::chang_QKD_zeroB(int val){
    in_QKD_zeroB =val;
    if(initR)createQKDLinesB();
}
void MainWindow::chang_QKD_phC(int val){
    in_QKD_phC=val;
    if(initR)createQKDLinesC();
}
void MainWindow::chang_QKD_pxqC(int val){
    if(in_QKD_pxqC>val)hidelinesW_C(val);
    in_QKD_pxqC=val;
    if(initR)createQKDLinesC();

    WindowClist.clear();
    WindowClist<<"";
    for (int j=0;j<in_QKD_pxqC;j++) {
        WindowClist<<(QString("w")+QString::number(j));
    }
    for (int index=0;index<numberOfLogicPlots;index++) {
        updateTab2Windows("PlotC",index);
    }
}
void MainWindow::chang_QKD_iwC(int val){
    in_QKD_iwC=val;
    if(initR)createQKDLinesC();
}
void MainWindow::chang_QKD_zeroC(int val){
    in_QKD_zeroC =val;
    if(initR)createQKDLinesC();
}
void MainWindow::chang_QKD_phD(int val){
    in_QKD_phD=val;
    if(initR)createQKDLinesD();
}
void MainWindow::chang_QKD_pxqD(int val){
    if(in_QKD_pxqD>val)hidelinesW_D(val);
    in_QKD_pxqD=val;
    if(initR)createQKDLinesD();

    WindowDlist.clear();
    WindowDlist<<"";
    for (int j=0;j<in_QKD_pxqD;j++) {
        WindowDlist<<(QString("w")+QString::number(j));
    }
    for (int index=0;index<numberOfLogicPlots;index++) {
        updateTab2Windows("PlotD",index);
    }
}
void MainWindow::chang_QKD_iwD(int val){
    in_QKD_iwD=val;if(initR)createQKDLinesD();
}
void MainWindow::chang_QKD_zeroD(int val){
    in_QKD_zeroD =val;if(initR)createQKDLinesD();
}

void MainWindow::chang_LogicWinL(QString t, int i){
    QRegularExpression rx("w(\\d+)");
    QRegularExpressionMatch match = rx.match(t);
    LWin[i]=match.captured(1).toInt();
    //std::cout<<t.toStdString()<<"\t cap:"<<match.captured(1).toStdString()<<std::endl;
}
void MainWindow::chang_LogicWinR(QString t, int i){
    QRegularExpression rx("w(\\d+)");
    QRegularExpressionMatch match = rx.match(t);
    RWin[i]=match.captured(1).toInt();
    //std::cout<<t.toStdString()<<"\t cap:"<<match.captured(1).toStdString()<<std::endl;
}

void MainWindow::chang_LogicOP(QString t, int index){
    if(t.compare("AND")==0)logicOP[index]=true;
    if(t.compare("OR")==0)logicOP[index]=false;
}

void MainWindow::Chang_trackA(bool val){
    for(int i=0; i<in_QKD_pxqA; i++){
        P_T[0][i]=trackA[i]->isChecked();
    }
    if(val)ui->PlotTrack->yAxis->rescale();
}
void MainWindow::Chang_trackB(bool val){
    for(int i=0; i<in_QKD_pxqB; i++){
        P_T[1][i]=trackB[i]->isChecked();
    }
    if(val)ui->PlotTrack->yAxis->rescale();
}
void MainWindow::Chang_trackC(bool val){
    for(int i=0; i<in_QKD_pxqC; i++){
        P_T[2][i]=trackC[i]->isChecked();
    }
    if(val)ui->PlotTrack->yAxis->rescale();
}
void MainWindow::Chang_trackD(bool val){
    for(int i=0; i<in_QKD_pxqD; i++){
        P_T[3][i]=trackD[i]->isChecked();
    }
    if(val)ui->PlotTrack->yAxis->rescale();
}

void MainWindow::tracktab2_change(bool c, int i){
    trackTab2[i]=c;
    //ui->PlotTab2->yAxis->rescale();
    if(c)ui->PlotTab2->graph(i)->addToLegend();
    else ui->PlotTab2->graph(i)->removeFromLegend();
}

/*void MainWindow::timestampParser(const vectorInt64 &inconimg_vectorTimetags, const vectorInt8 &inconimg_vectorChannels, int inconimg_tsvalid){

 timestampREC(const vectorInt64 &inconimg_vectorTimetags, const vectorInt8 &inconimg_vectorChannels, int inconimg_tsvalid);
}*/

void MainWindow::qutag_paremetes_setup(){
    QLabel *thchLab[NQUTAGCHANNELS];
    QHBoxLayout *FiltersHLayout[NQUTAGCHANNELS];
    QHBoxLayout *FiltersboxesHLayout[NQUTAGCHANNELS];
    QLabel *filterLab[NQUTAGCHANNELS];
    for (int i=0;i<NQUTAGCHANNELS ;i++) {
        thchLab[i] = new QLabel(tr("Threshold Channel ")+QString::number(i));
        thchLab[i]->setStyleSheet("color: rgb(238, 238, 236)");
        thch[i] = new QDoubleSpinBox();
        thch[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
        ui->Parameters_left->addRow(thchLab[i], thch[i]);

    }

    for (int i=0;i<NQUTAGCHANNELS ;i++) {
        filterLab[i] = new QLabel(tr("Filter Ch ")+QString::number(i));
        filterLab[i]->setStyleSheet("color: rgb(238, 238, 236)");

        FiltersHLayout[i] = new QHBoxLayout();
        FiltersboxesHLayout[i] = new QHBoxLayout();

        ui->Parameters_left->addRow(filterLab[i], FiltersHLayout[i]);

        qutagFilterType[i] = new QComboBox();

        qutagFilterType[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        qutagFilterType[i] ->addItem(tr("NONE"));
        qutagFilterType[i] ->addItem(tr("MUTE"));
        qutagFilterType[i] ->addItem(tr("COINC"));
        qutagFilterType[i] ->addItem(tr("SYNC"));
        //QObject::connect(qutagFilterType[i], SIGNAL(currentTextChanged(QString)), &qutag, SLOT(Chang_filtertype[i](QString)));
        for (int j=0;j<NQUTAGCHANNELS ;j++) {
            qutagfilter[i][j] = new QCheckBox(QString::number(j)+tr(" "));
            qutagfilter[i][j]->setStyleSheet("color: rgb(238, 238, 236);");
            FiltersboxesHLayout[i]->addWidget(qutagfilter[i][j]);

        }

        FiltersHLayout[i]->addWidget(qutagFilterType[i]);
        FiltersHLayout[i]->addLayout(FiltersboxesHLayout[i]);

    }

}

void MainWindow::runQutag(bool a){
    if(!qutag.isRunning()){
        qutag.start();
    }
}
