#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
//#include <QDesktopWidget>
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
logicrelations<<QString("")<<QString("OR")<<QString("AND");

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


tab2buttongroup.setExclusive(0);

//dbc.start();

//anl.start();

//while(adq.isRunning())usleep(100);

//qkdparam.QKD_setDefault();

qkdparam.LoadPrevoiusSeason(1);

setupsignalslot2();

//adq.initdone = 1;

initR=true;
createQKDLinesA();
createQKDLinesB();
createQKDLinesC();
createQKDLinesD();


/*
QDialog * dlg = new QDialog();
dlg->setGeometry( 100, 100, 260, 260);
filtersTabScroll = new QScrollArea(dlg);
filtersTabScroll->setWidgetResizable(true);
filtersTabScroll->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
filtersTabScroll->setWidgetResizable( true );
filtersTabScroll->setGeometry( 10, 10, 200, 200 );

filtersTabScroll->setWidget( ui->filterlayoutwidget );
*/
t2lableftp=new QLabel("LeftP");
t2lableftw=new QLabel("LeftW");
t2lablogic=new QLabel("logic");
t2labrightp=new QLabel("RightP");
t2labrightw=new QLabel("RightW");
t2labcur=new QLabel("Value");
t2labmin=new QLabel("Min");
t2labmax=new QLabel("Max");
t2labavr=new QLabel("Avr");

t2labcur->setVisible(false);
t2labmin->setVisible(false);
t2labmax->setVisible(false);
t2labavr->setVisible(false);

t2lableftp->setAlignment(Qt::AlignHCenter);
t2lableftw->setAlignment(Qt::AlignHCenter);
t2lablogic->setAlignment(Qt::AlignHCenter);
t2labrightp->setAlignment(Qt::AlignHCenter);
t2labrightw->setAlignment(Qt::AlignHCenter);
t2labcur->setAlignment(Qt::AlignHCenter);
t2labmin->setAlignment(Qt::AlignHCenter);
t2labmax->setAlignment(Qt::AlignHCenter);
t2labavr->setAlignment(Qt::AlignHCenter);

t2lableftp->setStyleSheet("color: rgb(238, 238, 236)");
t2lableftw->setStyleSheet("color: rgb(238, 238, 236)");
t2lablogic->setStyleSheet("color: rgb(238, 238, 236)");
t2labrightp->setStyleSheet("color: rgb(238, 238, 236)");
t2labrightw->setStyleSheet("color: rgb(238, 238, 236)");
t2labcur->setStyleSheet("color: rgb(238, 238, 236)");
t2labmin->setStyleSheet("color: rgb(238, 238, 236)");
t2labmax->setStyleSheet("color: rgb(238, 238, 236)");
t2labavr->setStyleSheet("color: rgb(238, 238, 236)");

ui->logicgrid->setHorizontalSpacing(5);

ui->logicgrid->addWidget(t2lableftp,0,1);
ui->logicgrid->addWidget(t2lableftw,0,2);
ui->logicgrid->addWidget(t2lablogic,0,3);
ui->logicgrid->addWidget(t2labrightp,0,4);
ui->logicgrid->addWidget(t2labrightw,0,5);
ui->logicgrid->addWidget(t2labcur,0,6);
ui->logicgrid->addWidget(t2labmin,0,7);
ui->logicgrid->addWidget(t2labmax,0,8);
ui->logicgrid->addWidget(t2labavr,0,9);

ui->dbcronometeroff->setDateTime(QDateTime::currentDateTime());

AddLogicSelectorElements();

}


//////////////////////////////////////////////////////////
///////////////////setups///////////////////////////
///////////////////////////////////////////////////////////

void MainWindow::QUTAG_initdone(){


    qutag_paremetes_setup();

    //for (int i=0;i<NQUTAGCHANNELS;i++)qutagEdge[i]=qutag.RoF[i];

    for (int i = 0;i<NQUTAGCHANNELS ;i++ ) {
        thch[i]->setValue(qutag.thresholds[i]);
        qutagFilterType[i]->setCurrentText(qutag.filtertypeSTR[i]);
        delaych[i]->setValue(double(qutag.delays[i]));
        if(qutag.RoF[i])qutagEdge[i]->setCurrentText("Rise");else qutagEdge[i]->setCurrentText("Fall");
    }
  /*  this->in_binsinplot=qutag.in_binsinplot;
    anl.in_binsinplot=qutag.in_binsinplot;
    QSignalBlocker blocker(ui->binsinplot);
    ui->binsinplot->setValue(qutag.in_binsinplot);
    blocker.unblock();

    this->in_binWidth=qutag.in_binWidth;
    anl.in_binWidth=qutag.in_binWidth;
    QSignalBlocker blocker2(ui->binWidth);
    ui->binWidth->setValue(qutag.in_binWidth);
    blocker2.unblock();*/
    anl.Chang_in_startChan(QUTAG_START_CHANNEL);

}

void MainWindow::TTUinitdone(){

    TTU_paremetes_setup();

    for (int i = 0;i<NTTUCHANNELS ;i++ ) {
        threshTTU[i]->setValue(TTUThresh[i]);
        delayTTU[i]->setValue(TTUdelays[i]);
        TTUEdge[i]->setCurrentText(rofMW[i]);
    }
    anl.Chang_in_startChan(TTUSTARTCHANNEL);
}

void MainWindow::setup_histolines_QKD(){

    for (int i = 0 ; i<MAX_QUBITS*2 ; i++) {
        for (int j=0; j<MAX_WIN; j++) {
            LinesPlotA[j][i] = new QCPItemStraightLine(ui->PlotA);
            LinesPlotA[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
            LinesPlotA[j][i]->setVisible(0);
        }
    }

        for (int i = 0 ; i<MAX_QUBITS*2 ; i++) {
            for (int j=0; j<MAX_WIN; j++) {
                LinesPlotB[j][i] = new QCPItemStraightLine(ui->PlotB);
                LinesPlotB[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
                LinesPlotB[j][i]->setVisible(0);
            }
    }
        for (int i = 0 ; i<MAX_QUBITS*2 ; i++) {
            for (int j=0; j<MAX_WIN; j++) {
                LinesPlotC[j][i] = new QCPItemStraightLine(ui->PlotC);
                LinesPlotC[j][i]->setPen(QPen(QColor::fromHsv( j*(360/MAX_WIN), 255, 255, 255  )));
                LinesPlotC[j][i]->setVisible(0);
            }
    }
        for (int i = 0 ; i<MAX_QUBITS*2 ; i++) {
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
  graph4->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1), QBrush(Qt::green),4));
  graph4->setPen(QPen(QColor(200, 200, 200), 2));



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
    QObject::connect(ui->adqtime, SIGNAL(valueChanged(double)), &TTU1, SLOT(Chang_in_adqtime(double)));

    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_histStart(int)));
    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_histStart(int)));
    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_histStart(int)));
    QObject::connect(ui->histStart, SIGNAL(valueChanged(int)), &TTU1, SLOT(Chang_in_histStart(int)));

    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_binWidth(int)));
    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_binWidth(int)));
    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_binWidth(int)));
    QObject::connect(ui->binWidth, SIGNAL(valueChanged(int)), &TTU1, SLOT(Chang_in_binWidth(int)));

    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), &anl, SLOT(Chang_in_binsinplot(int)));
    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), this, SLOT(Chang_in_binsinplot(int)));
    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), &qutag, SLOT(Chang_in_binsinplot(int)));
    QObject::connect(ui->binsinplot, SIGNAL(valueChanged(int)), &TTU1, SLOT(Chang_in_binsinplot(int)));

    QObject::connect(ui->adqtime_2, SIGNAL(valueChanged(double)), &anl, SLOT(Chang_adqtime_2(double)));
    QObject::connect(ui->adqtime_2, SIGNAL(valueChanged(double)), this, SLOT(Chang_adqtime_2(double)));

    QObject::connect(&anl, SIGNAL(Chang_anlAvilable(bool)), &qutag, SLOT(Chang_anlAvilable(bool)));

    QObject::connect(&anl, SIGNAL(CombinationChange(bool)), this, SLOT(CombinationChange(bool)));
   // QObject::connect(&anl, SIGNAL(CombinationChange(bool)), this, SLOT(CombinationChange(bool)));

    QObject::connect(&qutag, SIGNAL(dataready(vectorInt64, vectorInt, int)), &anl, SLOT(timestampREC(vectorInt64, vectorInt, int)),Qt::QueuedConnection);
    QObject::connect(&TTU1, SIGNAL(dataready(vectorInt64, vectorInt, int)), &anl, SLOT(timestampREC(vectorInt64, vectorInt, int)),Qt::QueuedConnection);

    QObject::connect(&anl, SIGNAL(anlongoing(bool)), &qutag, SLOT(adqpausechange(bool)));

    QObject::connect(&qutag, SIGNAL(qutaghist(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )), this, SLOT(histoplot(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )),Qt::QueuedConnection);
    QObject::connect(&TTU1, SIGNAL(TTUhist(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )), this, SLOT(histoplot(vectorDouble, vectorDouble, vectorDouble, vectorDouble, int, int , int ,int )),Qt::QueuedConnection);


    QObject::connect(&anl, SIGNAL(rates_tab2(vectorInt32, double)), this, SLOT(plotRates_tab2(vectorInt32, double)));


    QObject::connect(ui->DBON, SIGNAL(valueChanged(int)), this, SLOT(turnONDB(int)));
    QObject::connect(ui->CreateTables, SIGNAL(released()), this, SLOT(createTablesDB()));


    QObject::connect(ui->actionSave_state, SIGNAL(triggered(bool)), this, SLOT(SaveState(bool)));
    QObject::connect(ui->actionLoad_state, SIGNAL(triggered(bool)), this, SLOT(LoadState(bool)));


    QObject::connect(ui->loadLogic, SIGNAL(released()), this, SLOT(loadLogicS()));
    QObject::connect(ui->saveLogic, SIGNAL(released()), this, SLOT(saveLogicS()));

    //QObject::connect(ui->delayline, SIGNAL(valueChanged(int)), this, SLOT(Chang_delayline(int)));


    QObject::connect(this, SIGNAL(main_CreateTableTab1(int ,int ,int ,int , QLabel *)), &dbc, SLOT(CreateTableTab1(int ,int ,int ,int, QLabel *)));
    QObject::connect(this, SIGNAL( main_CreateTableTab2(vectorInt32,vectorInt32,vectorInt32,vectorInt32,vectorInt32, vectorBool, int, QLabel*)), &dbc, SLOT(CreateTableTab2(vectorInt32,vectorInt32,vectorInt32,vectorInt32,vectorInt32, vectorBool, int, QLabel*)),Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(main_SaveTab2Values(vectorInt32, float, double)), &dbc, SLOT(SaveTab2Values(vectorInt32, float, double)),Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(main_SaveTab1Values(vectorInt32,vectorInt32,vectorInt32,vectorInt32,float)), &dbc, SLOT(SaveTab1Values(vectorInt32,vectorInt32,vectorInt32,vectorInt32,float)),Qt::QueuedConnection);


    QObject::connect(ui->homscan_timed, SIGNAL(valueChanged(double)), this, SLOT(Chang_homscan_time(double)));
    QObject::connect(ui->homscan, SIGNAL(valueChanged(int)), this, SLOT(Chang_homscan(int)));

    QObject::connect(ui->tab2_xrange, SIGNAL(valueChanged(int)), this, SLOT(chang_tab2range(int)));


    QObject::connect(ui->reset_delay, SIGNAL(released()), this, SLOT(resetdelay()));

    QObject::connect(ui->Max_delayd, SIGNAL(valueChanged(double)), this, SLOT(chang_in_max_del(double)));

    QObject::connect(ui->stepduration, SIGNAL(valueChanged(int)), this, SLOT(chang_in_stepduration(int)));

    QObject::connect(ui->clean_tab2, SIGNAL(released()), this, SLOT(clean_tab2()));


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

    QObject::connect(ui->TSON, SIGNAL(valueChanged(int)), &TTU1, SLOT(TSanl(int)));
    QObject::connect(ui->TSper, SIGNAL(valueChanged(int)), &TTU1, SLOT(changTSper(int)));

    QObject::connect(this, SIGNAL(setOVDL(float)), &ovdl_1, SLOT(setDelay(float)));

    QObject::connect(ui->VDL_start, SIGNAL(valueChanged(double)), this, SLOT(chang_VDL_start(double)));

    QObject::connect(&qutag, SIGNAL(initdone()), this , SLOT(QUTAG_initdone()));
    QObject::connect(&TTU1, SIGNAL(ttuinitdone()), this , SLOT(TTUinitdone()));

    QObject::connect(ui->actioninit_Qutag, SIGNAL(triggered(bool)), this, SLOT(runQutag(bool)));

    QObject::connect(this, SIGNAL(MWChang_qutag_filtertype(QString, int)), &qutag, SLOT(Chang_qutag_filtertype(QString, int)));
    QObject::connect(this, SIGNAL(MWChang_qutag_filtermask(int, int, int)), &qutag, SLOT(Chang_qutag_filtermask(int, int, int)));

    QObject::connect(this, SIGNAL( MWChang_qutagThresh(double, int)), &qutag, SLOT(Chang_in_thch(double, int)));
    QObject::connect(this, SIGNAL( MWChang_TTUThresh(double, int)), &TTU1, SLOT(Chang_in_thch(double, int)));
    QObject::connect(this, SIGNAL( MWChang_TTUThresh(double, int)), this, SLOT(Chang_MW_TTUThresh(double, int)));

    QObject::connect(this, SIGNAL(MWChang_qutag_edge(QString, int)), &qutag, SLOT(Chang_rof(QString, int)));
    QObject::connect(this, SIGNAL(MWChang_TTU_edge(QString, int)), &TTU1, SLOT(Chang_rof(QString, int)));
    QObject::connect(this, SIGNAL(MWChang_TTU_edge(QString, int)), this, SLOT(Chang_MWTTU_rof(QString, int)));

    QObject::connect(this, SIGNAL( MWChang_qutag_delay(double, int)), &qutag, SLOT(Chang_delay(double, int)));
    QObject::connect(this, SIGNAL( MWChang_TTU_delay(double, int)), &TTU1, SLOT(Chang_delay(double, int)));
    QObject::connect(this, SIGNAL( MWChang_TTU_delay(double, int)), this, SLOT(Chang_delayTTUMain(double, int)));

    QObject::connect(ui->actionTTURes_Std, SIGNAL(triggered(bool)), this, SLOT(TTURes_Std(bool)));
    QObject::connect(ui->actionTTURes_A, SIGNAL(triggered(bool)), this, SLOT(TTURes_A(bool)));
    QObject::connect(ui->actionTTURes_B, SIGNAL(triggered(bool)), this, SLOT(TTURes_B(bool)));
    QObject::connect(ui->actionTTURes_C, SIGNAL(triggered(bool)), this, SLOT(TTURes_C(bool)));

    QObject::connect(ui->actionTTXRes_Std, SIGNAL(triggered(bool)), this, SLOT(TTXRes_Std(bool)));
    QObject::connect(ui->actionTTXRes_B, SIGNAL(triggered(bool)), this, SLOT(TTXRes_B(bool)));

    QObject::connect(ui->connect_OVDL, SIGNAL(released()), this, SLOT(connectOVDLmw()));

    QObject::connect(ui->addfilter, SIGNAL(released()), this, SLOT(addfilterMW()));

    QObject::connect(this, SIGNAL( MWfilterConnect(int) ), &EXFOfilters, SLOT( filterConnect(int) ) );
    QObject::connect(this, SIGNAL( MWfilteripRet(QString , int) ), &EXFOfilters, SLOT( setIP(QString, int) ) );

    QObject::connect(this, SIGNAL( MWFilterWLChange(double, int) ), &EXFOfilters, SLOT( setWavelength(double, int) ) );
    QObject::connect(this, SIGNAL( MWFilterBWChange(int, int) ), &EXFOfilters, SLOT( setBandwidth(int, int) ) );

    QObject::connect(this, SIGNAL( MWFilterWLChange(double, int) ), &dbc, SLOT( setfiltersWL(double, int) ) );
    QObject::connect(this, SIGNAL( MWFilterBWChange(int, int) ), &dbc, SLOT( setfiltersBW(int, int) ) );

    QObject::connect(&EXFOfilters, SIGNAL(DeviceWL(float, int)), this, SLOT(loadFilterWL(float, int)));
    QObject::connect(&EXFOfilters, SIGNAL(DeviceBW(int, int)), this, SLOT(loadFilterBW(int, int)));
    QObject::connect(ui->rawtssave, SIGNAL(valueChanged(int)), &anl, SLOT(saveRawTSon(int)));

    QObject::connect(this, SIGNAL( BWscanONsignal(int, int) ), this, SLOT( BWfilterscanslot(int, int) ) );
    QObject::connect(this, SIGNAL( WLscanONsignal(int, int) ), this, SLOT( WLfilterscanslot(int, int) ) );

    QObject::connect(ui->tab2showcurrent, SIGNAL(stateChanged(int)), this, SLOT(t2showcurrent(int)));
    QObject::connect(ui->tab2showmin, SIGNAL(stateChanged(int)), this, SLOT(t2showmin(int)));
    QObject::connect(ui->tab2showmax, SIGNAL(stateChanged(int)), this, SLOT(t2showmax(int)));
    QObject::connect(ui->tab2showavr, SIGNAL(stateChanged(int)), this, SLOT(t2showavr(int)));

    QObject::connect(ui->dbofftimer, SIGNAL(released()), this, SLOT(programDBoff()));

    QObject::connect(&TTU1, SIGNAL(errortt(QString)), this, SLOT(error1(QString)));

    QObject::connect(ui->RemoveLogic,  SIGNAL(released()), this, SLOT(RemoveLogic()));

    QObject::connect(ui->loopfilterscan,  SIGNAL(stateChanged(int)), this, SLOT(loopfilterscanch(int)));

}

void MainWindow::setupsignalslot2(){

    for (int i=0;i<MAX_WIN;i++) {
     //qDebug()<<"prev"<<i;
     trackA[i] = new QRadioButton(QString(QString::number(i)));
     QObject::connect(trackA[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackA(bool)));


     trackB[i] = new QRadioButton(QString(QString::number(i)));
     QObject::connect(trackB[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackB(bool)));


     trackC[i] = new QRadioButton(QString(QString::number(i)));
     QObject::connect(trackC[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackC(bool)));


     trackD[i] = new QRadioButton(QString(QString::number(i)));
     QObject::connect(trackD[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackD(bool)));


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


    ui->trackFL_A->addRow(counterA[i],trackA[i]);
    ui->trackFL_A->setRowVisible(i,false);

    ui->trackFL_B->addRow(counterB[i],trackB[i]);
    ui->trackFL_B->setRowVisible(i,false);

    ui->trackFL_C->addRow(counterC[i],trackC[i]);
    ui->trackFL_C->setRowVisible(i,false);

    ui->trackFL_D->addRow(counterD[i],trackD[i]);
    ui->trackFL_D->setRowVisible(i,false);
    }
    //for (int i=MAX_WIN-1;i>=0;i--) {
     for (int i=0;i<MAX_WIN;i++) {
      /*  QObject::connect(trackA[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackA(bool)));
        if(i<in_QKD_pxqA)ui->trackFL_A->addRow(counterA[i],trackA[i]);
        QObject::connect(trackB[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackB(bool)));
        if(i<in_QKD_pxqB)ui->trackFL_B->addRow(counterB[i],trackB[i]);
        QObject::connect(trackC[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackC(bool)));
        if(i<in_QKD_pxqC)ui->trackFL_C->addRow(counterC[i],trackC[i]);
        QObject::connect(trackD[i], SIGNAL(toggled(bool)), this, SLOT(Chang_trackD(bool)));
        if(i<in_QKD_pxqD)ui->trackFL_D->addRow(counterD[i],trackD[i]);*/
    // qDebug()<<i;

    }

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
        if(cleanTab2){
                tab2data[i].clear();
                ui->PlotTab2->graph(i)->data()->clear();
                //ui->PlotTab2->graph(i)->setData({(double)counters[i]},{(double)counters[i]});
        }

        LogicCurrent[i]->display(counters[i]);
        tab2data[i].prepend(counters[i]);

        if(trackTab2[i]){
            ui->PlotTab2->graph(i)->addData(key-lastPointKey_tab2, counters[i]);
            //ui->PlotTab2->graph(i)->addToLegend();
            if(CombiChang ){
                ui->PlotTab2->graph(i)->data()->clear();
                CombiChang=false;
            }

        }
        if(tab2data[i].size()>xrange)tab2data[i].resize(xrange);

    /*    for (int j = 0; j < xrange; j++) {
            if(tab2data[i][j]<t2min[i])t2min[i] = tab2data[i][j];
            if(tab2data[i][j]>t2max[i])t2max[i] = tab2data[i][j];
            t2avr[i]+=tab2data[i][j];
        }
*/
        double t2min = *std::min_element(tab2data[i].begin(),tab2data[i].end());
        double t2max = *std::max_element(tab2data[i].begin(), tab2data[i].end());
        double t2avr = std::accumulate(tab2data[i].begin(), tab2data[i].end(), 0.0) / tab2data[i].size();

        //t2avr[i]=t2avr[i]/xrange;
        LogicMin[i]->display(t2min);
        LogicMax[i]->display(t2max);
        LogicAvr[i]->display(t2avr);

    }
    if(cleanTab2)cleanTab2=false;


    if(dbrunning && dbc.connection_succesfull ){
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

    ui->plotAtsv->display(count1);
    ui->plotBtsv->display(count2);
    ui->plotCtsv->display(count3);
    ui->plotDtsv->display(count4);

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

    if(dbrunning && dbc.connection_succesfull)emit main_SaveTab1Values(A, B, C ,D , in_adqtime);
  x.clear();

	
}

void MainWindow::turnONDB(int val){
    if(!dbc.isRunning()  && val==1){
        dbc.run();
        //dbrunning=val;
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
    if(val==0){
        //dbrunning = val;
        dbc.disconnectFromServer();
        //while(dbc.isRunning())usleep(100);
        //dbc.~DBControl();
        /**/
    }
   // dbrunning=val;

}

void MainWindow::createTablesDB(){
    if(dbc.connection_succesfull){
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

        emit main_CreateTableTab1(in_QKD_pxqA,in_QKD_pxqB,in_QKD_pxqC,in_QKD_pxqD, ui->tabledisplay1);
        emit main_CreateTableTab2(ActiveChan, logicL, logicR, WinL, WinR, gate, numberOfFilters, ui->tabledisplay2);
        dbrunning=true;
    }else error1("database not open yet");
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


                    /*QMapIterator<QString,int>ip(mapint);
                    while (ip.hasNext()) {
                        ip.next();
                        std::cout<< ip.key().toStdString()<< ": " << ip.value() << std::endl;

                    }*/
                    out<<mapint;
                    out<<mapdouble;
            }

   // LoadState(1);
}

bool MainWindow::LoadPrevoiusSeason(bool a){


    QString fileName = "LastSeasonVariables.conf";
    if (fileName.isEmpty())return 1;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file for the paremeters"),
        file.errorString());
        return 1;
    }
    else  std::cout<<"loading previous season parameters"<<std::endl;


    QMap<QString, int> mapintout;
    QMap<QString, double> mapdoubleout;
    QMap<QString, QString> mapstringout;

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_5);
    in>>mapintout;
    in>>mapdoubleout;
    in>>mapstringout;


    QMapIterator<QString,int>i(mapintout);
    while (i.hasNext()) {
        i.next();
       // std::cout<< i.key().toStdString() <<  ": " << i.value() << std::endl;
    }
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

    //if(mapdoubleout.contains("in_adqtime_2"))ui->adqtime_2->setValue(mapdoubleout.value("in_adqtime_2"));
    //else
    ui->adqtime_2->setValue(1);
    if(mapdoubleout.contains("Max_delay"))ui->Max_delayd->setValue(mapdoubleout.value("Max_delay"));
    else ui->Max_delayd->setValue(500);
    if(mapintout.contains("stepduration"))ui->stepduration->setValue(mapintout.value("stepduration"));
    else ui->stepduration->setValue(30);
    if(mapintout.contains("homscan_time"))ui->homscan_timed->setValue(mapintout.value("homscan_time"));
    else ui->homscan_timed->setValue(1);

    if(mapdoubleout.contains("QKD_time"))ui->Max_delayd->setValue(mapdoubleout.value("Max_delay"));
    else ui->Max_delayd->setValue(500);


    if(mapintout.contains("TSper"))ui->TSper->setValue(mapintout.value("TSper"));
    else ui->TSper->setValue(10);

    if(mapdoubleout.contains("QKD_time"))ui->Max_delayd->setValue(mapdoubleout.value("Max_delay"));
    else ui->Max_delayd->setValue(500);


    for(int i = 0; i<NTTUCHANNELS; i++){
        QString wordTTUThresh = "TTUThresh" + QString::number(i);
        if(mapdoubleout.contains(wordTTUThresh))TTUThresh[i]=mapdoubleout.value(wordTTUThresh);

        QString wordTTUdelays = "TTUdelays" + QString::number(i);
        if(mapdoubleout.contains(wordTTUdelays))TTUdelays[i]=mapdoubleout.value(wordTTUdelays);

        QString wordrofMW = "rofMW"+ QString::number(i);
        if(mapstringout.contains(wordrofMW))rofMW[i]=mapstringout.value(wordrofMW);
    }

    // std::cout<<"parameters loaded"<<std::endl;
    file.close();



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

    //out.setVersion(QDataStream::Qt_4_5);
    QMap<QString, int> mapint;
    QMap<QString, double> mapdouble;
    QMap<QString, QString> mapstring;


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
   //double TTUThresh[NTTUCHANNELS];   double TTUdelays[NTTUCHANNELS];  QString rofMW[NTTUCHANNELS];
   for(int i = 0; i<NTTUCHANNELS; i++){
        QString wordTTUThresh = "TTUThresh" + QString::number(i);
        mapdouble.insert(wordTTUThresh,TTUThresh[i]);
        QString wordTTUdelays = "TTUdelays" + QString::number(i);
        mapdouble.insert(wordTTUdelays,TTUdelays[i]);
        QString wordrofMW = "rofMW"+ QString::number(i);
        mapstring.insert(wordrofMW, rofMW[i]);
   }

    out<<mapint;
    out<<mapdouble;
    out<<mapstring;

    file.close();
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

void MainWindow::loadLogicS(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "./",
                                                  tr("Images (LogicState*)"));

    if (fileName.isEmpty())return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }

        QMap<QString, int> mapintout;
        QMap<QString, QString> mapstringout;

        QDataStream in(&file);
        in>>mapintout;
        in>>mapstringout;

        if(mapintout.contains("numberOfLogicPlots")){
            int logicnumberloaded = mapintout.value("numberOfLogicPlots");
            for(int i = 0; i<logicnumberloaded; i++)if(numberOfLogicPlots <=logicnumberloaded)this->AddLogicSelectorElement();
            for(int i = 0; i<logicnumberloaded; i++){
                QString LeftSourceMap = QString("SourceLeft%1").arg(i);
                if(mapintout.contains(LeftSourceMap)){
                    int LeftSourceMapValue = mapintout.value(LeftSourceMap);
                    //qDebug()<<mapintout.value(QString("SourceLeft%1").arg(i));
                    if(LeftSourceMapValue<0){
                        LogicL[i]->setCurrentIndex(-1*LeftSourceMapValue);
                        QString WinLeftMap = QString("WindowLeft%1").arg(i);
                        if(mapintout.contains(WinLeftMap)){
                            int WinLeftMapValue = mapintout.value(WinLeftMap);
                            LogicWinL[i]->setCurrentIndex(WinLeftMapValue+1);

                        }
                    }
                    if(LeftSourceMapValue>=0)LogicL[i]->setCurrentText(QString::number(LeftSourceMapValue));
                }
                QString RightSourceMap = QString("SourceRight%1").arg(i);
                if(mapintout.contains(RightSourceMap)){
                    int RightSourceMapValue = mapintout.value(RightSourceMap);
                    if(RightSourceMapValue<0){
                        LogicR[i]->setCurrentIndex(-1*RightSourceMapValue);
                        QString WinRightMap = QString("WindowRight%1").arg(i);
                        if(mapintout.contains(WinRightMap)){
                            int WinLeftMapValue = mapintout.value(WinRightMap);
                            //qDebug()<<"winlef"<<WinLeftMapValue;
                            LogicWinR[i]->setCurrentIndex(WinLeftMapValue+1);
                        }
                    }
                    if(RightSourceMapValue>=0)LogicR[i]->setCurrentText(QString::number(RightSourceMapValue));
                }
                QString LogicOperatorMap = QString("LogicOperator%1").arg(i);
                //qDebug()<<"LogicOperatorMap: "<<LogicOperatorMap<<"\t value: "<<mapstringout.value(LogicOperatorMap);
                if(mapstringout.contains(LogicOperatorMap) ){
                //int LogicOperatorMapValue = mapintout.value(LogicOperatorMap);
                    //qDebug()<<"log op"<<mapstringout.value(LogicOperatorMap);
                    LogicG[i]->setCurrentText(mapstringout.value(LogicOperatorMap));
                //LogicG[i]->setCurrentIndex(LogicOperatorMapValue+1);
                }
            }

        }
    }
}

void MainWindow::saveLogicS(){


    bool ok;
    QString com = QInputDialog::getText(this, tr("Record DATA"),tr("Insert a name for the file"), QLineEdit::Normal,QDir::home().dirName(), &ok);

        if (ok && !com.isEmpty()){
            com.prepend("LogicState_");
            com.append(".txt");
            QFile LogicFile(com);
            if (!LogicFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::information(this, tr("Unable to open file"),
                LogicFile.errorString());
                return;
            }
            QDataStream out(&LogicFile);

            //out.setVersion(QDataStream::Qt_4_5);

            QMap<QString, int> mapint;
            QMap<QString, QString> mapstring;

            mapint.insert("numberOfLogicPlots", anl.numberOfLogicPlots);

            for(int i=0;i<anl.numberOfLogicPlots;i++){
                mapint.insert(QString("SourceLeft%1").arg(i), anl.LSource[i]);
                mapint.insert(QString("SourceRight%1").arg(i), anl.RSource[i]);
                mapint.insert(QString("WindowLeft%1").arg(i), anl.LWin[i]);
                mapint.insert(QString("WindowRight%1").arg(i), anl.RWin[i]);
                //mapint.insert(QString("LogicOperator%1").arg(i), anl.logicOP[i]);
                mapstring.insert(QString("LogicOperator%1").arg(i), LogicG[i]->currentText());
            }
            out<<mapint;
            out<<mapstring;
       }

}

void MainWindow::clean_tab2(){
       cleanTab2=true;
/*    QMessageBox msgBox;
    msgBox.setText("Still to do :P");
    msgBox.exec();
*/
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
   TTU1.Break();
   anl.Break();
   qutag.quit();

   dbc.quit();

   std::cout<<"destroy"<<std::endl;



   while(qutag.isRunning())sleep(1);
   std::cout<<"adq"<<std::endl;
   while(TTU1.isRunning())sleep(1);
   std::cout<<"TTU"<<std::endl;
   while( dbc.isRunning())sleep(1);
   std::cout<<"dbc"<<std::endl;
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



void MainWindow::createQKDLinesA(){

    for(int i=0; i<MAX_QUBITS*2; i++){
        for (int j=0;j<MAX_WIN;j++) {
            if((i+1)%2){
                LinesPlotA[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroA+j*in_QKD_phA,0);
                LinesPlotA[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroA+j*in_QKD_phA,1);

            }
            else{
                //if(i<in_QKD_numb*2 && j<in_QKD_pxqA)LinesPlotA[j][i]->setVisible(1);
                LinesPlotA[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroA+in_QKD_iwA+j*in_QKD_phA,0);
                LinesPlotA[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroA+in_QKD_iwA+j*in_QKD_phA,1);
            }
            if(i<in_QKD_numb*2 && j<in_QKD_pxqA)LinesPlotA[j][i]->setVisible(1);
        }
    }
    for (int j=0;j<MAX_WIN;j++)if(j<in_QKD_pxqA)ui->trackFL_A->setRowVisible(j,true);
    //if(in_QKD_pxqA > ui->trackFL_A->rowCount()-1)ui->trackFL_A->addRow(counterA[in_QKD_pxqA-1],trackA[in_QKD_pxqA-1]);
    ui->PlotA->replot();
}
void MainWindow::createQKDLinesB(){
    for(int i=0; i<MAX_QUBITS*2; i++){
        for (int j=0;j<MAX_WIN;j++) {
            if((i+1)%2){

               LinesPlotB[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroB+j*in_QKD_phB,0);
               LinesPlotB[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroB+j*in_QKD_phB,1);
               //if(j==0 && WindowBlist.size()<i/2)WindowBlist<<QString::number(i/2);
            }
            else{
               LinesPlotB[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroB+in_QKD_iwB+j*in_QKD_phB,0);
               LinesPlotB[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroB+in_QKD_iwB+j*in_QKD_phB,1);
            }
            if(i<in_QKD_numb*2 && j<in_QKD_pxqB)LinesPlotB[j][i]->setVisible(1);
        }
    }
    for (int j=0;j<MAX_WIN;j++)if(j<in_QKD_pxqB)ui->trackFL_B->setRowVisible(j,true);
    //if(in_QKD_pxqB > ui->trackFL_B->rowCount()-1)ui->trackFL_B->addRow(counterB[in_QKD_pxqB-1],trackB[in_QKD_pxqB-1]);
    ui->PlotB->replot();
}
void MainWindow::createQKDLinesC(){
    for(int i=0; i<MAX_QUBITS*2; i++){
        for (int j=0;j<MAX_WIN;j++) {
            if((i+1)%2){
               //LinesPlotC[j][i]->setVisible(1);
               LinesPlotC[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroC+j*in_QKD_phC,0);
               LinesPlotC[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroC+j*in_QKD_phC,1);
               //if(j==0 && WindowClist.size()<i/2)WindowClist<<QString::number(i/2);

            }
            else{
               //LinesPlotC[j][i]->setVisible(1);
               LinesPlotC[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroC+in_QKD_iwC+j*in_QKD_phC,0);
               LinesPlotC[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroC+in_QKD_iwC+j*in_QKD_phC,1);
            }
            if(i<in_QKD_numb*2 && j<in_QKD_pxqC)LinesPlotC[j][i]->setVisible(1);
        }
    }
    for (int j=0;j<MAX_WIN;j++)if(j<in_QKD_pxqC)ui->trackFL_C->setRowVisible(j,true);
    //if(in_QKD_pxqC > ui->trackFL_C->rowCount()-1)ui->trackFL_C->addRow(counterC[in_QKD_pxqC-1],trackC[in_QKD_pxqC-1]);
    ui->PlotC->replot();
}
void MainWindow::createQKDLinesD(){
    for(int i=0; i<MAX_QUBITS*2; i++){
        for (int j=0;j<MAX_WIN;j++) {
            if((i+1)%2){
               LinesPlotD[j][i]->point1->setCoords(i/2*in_QKD_time+in_QKD_zeroD+j*in_QKD_phD,0);
               LinesPlotD[j][i]->point2->setCoords(i/2*in_QKD_time+in_QKD_zeroD+j*in_QKD_phD,1);
            }
            else{
               LinesPlotD[j][i]->point1->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroD+in_QKD_iwD+j*in_QKD_phD,0);
               LinesPlotD[j][i]->point2->setCoords((i-1)/2*in_QKD_time+in_QKD_zeroD+in_QKD_iwD+j*in_QKD_phD,1);
            }
            if(i<in_QKD_numb*2 && j<in_QKD_pxqD)LinesPlotD[j][i]->setVisible(1);
        }
    }
    for (int j=0;j<MAX_WIN;j++)if(j<in_QKD_pxqD)ui->trackFL_D->setRowVisible(j,true);
   // if(in_QKD_pxqD > ui->trackFL_D->rowCount()-1)ui->trackFL_D->addRow(counterD[in_QKD_pxqD-1],trackD[in_QKD_pxqD-1]);
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
    //qDebug()<<"number of elements in trackFL_A: "<<ui->trackFL_A->rowCount();
    for (int j=win;j<in_QKD_pxqA;j++)ui->trackFL_A->setRowVisible(j, false);
    for (int i=0;i<2*in_QKD_numb;i++) {
        for (int j=win;j<in_QKD_pxqA;j++) {
            LinesPlotA[j][i]->setVisible(0);
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
        for (int j=win;j<in_QKD_pxqB;j++)ui->trackFL_B->setRowVisible(j, false);
        for (int i=0;i<2*in_QKD_numb;i++) {
            for (int j=win;j<in_QKD_pxqB;j++) {
               LinesPlotB[j][i]->setVisible(0);
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
        for (int j=win;j<in_QKD_pxqC;j++)ui->trackFL_C->setRowVisible(j, false);
        for (int i=0;i<2*in_QKD_numb;i++) {
            for (int j=win;j<in_QKD_pxqC;j++) {
               LinesPlotC[j][i]->setVisible(0);
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
        for (int j=win;j<in_QKD_pxqD;j++)ui->trackFL_D->setRowVisible(j, false);
        for (int i=0;i<2*in_QKD_numb;i++) {
            for (int j=win;j<in_QKD_pxqD;j++) {
               LinesPlotD[j][i]->setVisible(0);
            }
        }
    }
}

void MainWindow::AddLogicSelectorElements(){
    for(int i=0; i< MAX_LOGIC; i++){
        LogicTrack[i] = new QRadioButton(QString(QString::number(i)));
        LogicTrack[i]->setStyleSheet("background-color: rgb(238, 238, 236)");
        tab2buttongroup.addButton(LogicTrack[i]);
        QObject::connect(LogicTrack[i], &QRadioButton::toggled, [this, i](bool tog){tracktab2_change(tog, i);});


        LogicL[i] = new QComboBox();
        LogicL[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        LogicL[i]->addItems(plotslist);
        QObject::connect(LogicL[i], &QComboBox::currentTextChanged, [this, i](QString logicl){AddLogicSelectorWindowsL(logicl, i);});

        if(i>0){
            for (int j=i-1;j>=0;j--) {
               LogicL[i]->addItem(QString::number(j));
            }
        }

        LogicG[i] = new QComboBox();
        LogicG[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        LogicG[i]->addItems(logicrelations);
        QObject::connect(LogicG[i], &QComboBox::currentTextChanged, [this, i](QString logicg){this->chang_LogicOP(logicg, i); anl.chang_LogicOP(logicg, i);});


        LogicR[i] = new QComboBox();
        LogicR[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        LogicR[i]->addItems(plotslist);

        QObject::connect(LogicR[i], &QComboBox::currentTextChanged, [this, i](QString logicr){AddLogicSelectorWindowsR(logicr, i);});

        if(i>0){
            for (int j=i-1;j>=0;j--) {
               LogicR[i]->addItem(QString::number(j));
            }
        }
        LogicCurrent[i]= new QLCDNumber();
        LogicCurrent[i]->setVisible(false);
        LogicMin[i] = new QLCDNumber();
        LogicMin[i]->setVisible(false);
        LogicMax[i] = new QLCDNumber();
        LogicMax[i]->setVisible(false);
        LogicAvr[i] = new QLCDNumber();
        LogicAvr[i]->setVisible(false);

        LogicTrack[i]->setVisible(false);
        LogicL[i]->setVisible(false);
        LogicG[i]->setVisible(false);
        LogicR[i]->setVisible(false);

        ui->logicgrid->addWidget(LogicTrack[i],i+1,0);
        ui->logicgrid->addWidget(LogicL[i], i+1, 1);
        ui->logicgrid->addWidget(LogicG[i], i+1, 3);
        ui->logicgrid->addWidget(LogicR[i],i+1,4);
        ui->logicgrid->addWidget(LogicCurrent[i],i+1,6);
        ui->logicgrid->addWidget(LogicMin[i],i+1,7);
        ui->logicgrid->addWidget(LogicMax[i],i+1,8);
        ui->logicgrid->addWidget(LogicAvr[i],i+1,9);
    }

}

void MainWindow::AddLogicSelectorElement(){

    int i = numberOfLogicPlots;

    if(i>MAX_LOGIC){
        qDebug()<<"reached the maximum number of logic plots: "<<MAX_LOGIC;
        return;
   }
    LogicTrack[i]->setVisible(true);
    LogicL[i]->setVisible(true);
    LogicG[i]->setVisible(true);
    LogicR[i]->setVisible(true);

    if(ui->tab2showcurrent->isChecked() )LogicCurrent[i]->setVisible(true);
    if(ui->tab2showmin->isChecked() )LogicMin[i]->setVisible(true);
    if(ui->tab2showmax->isChecked() )LogicMax[i]->setVisible(true);
    if(ui->tab2showavr->isChecked() )LogicAvr[i]->setVisible(true);


   /*
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

   LogicCurrent[i]= new QLCDNumber();
   LogicCurrent[i]->setVisible(false);
   LogicMin[i] = new QLCDNumber();
   LogicMin[i]->setVisible(false);
   LogicMax[i] = new QLCDNumber();
   LogicMax[i]->setVisible(false);
   LogicAvr[i] = new QLCDNumber();
   LogicAvr[i]->setVisible(false);

   ui->logicgrid->addWidget(LogicTrack[i],i+1,0);
   ui->logicgrid->addWidget(LogicL[i], i+1, 1);
   ui->logicgrid->addWidget(LogicG[i], i+1, 3);
   ui->logicgrid->addWidget(LogicR[i],i+1,4);
   ui->logicgrid->addWidget(LogicCurrent[i],i+1,6);
   ui->logicgrid->addWidget(LogicMin[i],i+1,7);
   ui->logicgrid->addWidget(LogicMax[i],i+1,8);
   ui->logicgrid->addWidget(LogicAvr[i],i+1,9);
*/

    numberOfLogicPlots++;
    qDebug()<<"number of logics plots: "<<numberOfLogicPlots;
    anl.numberOfLogicPlots=this->numberOfLogicPlots;
    //dbc.numberOfLogicPlots=this->numberOfLogicPlots;

}

void MainWindow::RemoveLogic(){

    int i = numberOfLogicPlots;

    LogicTrack[i]->setVisible(false);
    LogicL[i]->setVisible(false);
    LogicG[i]->setVisible(false);
    LogicR[i]->setVisible(false);

    LogicCurrent[i]->setVisible(false);
    LogicMin[i]->setVisible(false);
    LogicMax[i]->setVisible(false);
    LogicAvr[i]->setVisible(false);
    if(LogicTrack[i]->isChecked())LogicTrack[i]->toggle();
    if(i<1){
        qDebug()<<"nothing to delete here";
        return;
    }else numberOfLogicPlots--;
    qDebug()<<"number of logics plots: "<<numberOfLogicPlots;
    anl.numberOfLogicPlots=this->numberOfLogicPlots;
}
void MainWindow::AddLogicSelectorWindowsL(QString t, int i){
//std::cout<<"outside plot add   text:"<<t.toStdString()<<" index:  "<<index<<std::endl;

    if((t.compare("PlotA")==0 || t.compare("PlotB")==0 || t.compare("PlotC")==0 || t.compare("PlotD")==0) && LogicWinL[i]==nullptr){
        LogicWinL[i] = new QComboBox();
        LogicWinL[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        //LogicBox[index]->insertWidget(2, LogicWinL[index]);
        ui->logicgrid->addWidget(LogicWinL[i],i+1,2);
        /*QObject::connect(LogicWinL[index], SIGNAL(currentTextChanged(QString)), Windowlogic[index], SLOT(chang_LogicWinLparser(QString)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinL(QString, int)), &anl, SLOT(chang_LogicWinL(QString, int)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinL(QString, int)), this, SLOT(chang_LogicWinL(QString, int)));*/
        QObject::connect(LogicWinL[i], &QComboBox::currentTextChanged, [this, i](QString logicwinl){this->chang_LogicWinL(logicwinl, i); anl.chang_LogicWinL(logicwinl, i);});
        leftexpanded[i]=true;
        //std::cout<<"inside plot add  text:"<<t.toStdString()<<" index:  "<<index<<std::endl;
    }
    else {
        anl.LSource[i]=t.toInt();
        this->LSource[i]=t.toInt();
    }

    updateTab2Windows(t,i);

}

void MainWindow::AddLogicSelectorWindowsR(QString t, int i){
    /*int position;
    if(leftexpanded[i])position=5;
    else position=6;*/
   if((t.compare("PlotA")==0 || t.compare("PlotB")==0 || t.compare("PlotC")==0 || t.compare("PlotD")==0) && LogicWinR[i]==nullptr){
        LogicWinR[i] = new QComboBox();
        LogicWinR[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        //LogicBox[index]->insertWidget(position, LogicWinR[index]);
        ui->logicgrid->addWidget(LogicWinR[i],i+1,5);
        /*QObject::connect(LogicWinR[index], SIGNAL(currentTextChanged(QString)), Windowlogic[index], SLOT(chang_LogicWinRparser(QString)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinR(QString, int)), &anl, SLOT(chang_LogicWinR(QString, int)));
        QObject::connect(Windowlogic[index], SIGNAL(chang_LogicWinR(QString, int)), this, SLOT(chang_LogicWinR(QString, int)));*/
        QObject::connect(LogicWinR[i], &QComboBox::currentTextChanged, [this, i](QString logicwinr){this->chang_LogicWinR(logicwinr, i); anl.chang_LogicWinR(logicwinr, i);});
    }
   else {
       anl.RSource[i]=t.toInt();
       this->RSource[i]=t.toInt();
   }
   updateTab2Windows(t,i);
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

    //qDebug()<<"new in_QKD_numb   "<<val;

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

    /*************Thresholds*********/

    QLabel *thchLab[NQUTAGCHANNELS];


    for (int i=0;i<NQUTAGCHANNELS ;i++) {
        thchLab[i] = new QLabel(tr("Threshold Channel ")+QString::number(i));
        thchLab[i]->setStyleSheet("color: rgb(238, 238, 236)");
        thch[i] = new QDoubleSpinBox();
        thch[i]->setMaximum(3);
        thch[i]->setMinimum(-3);
        thch[i]->setDecimals(3);
        thch[i]->setSuffix(" [V]");
        thch[i]->setSingleStep(QUTAG_THRESHOLD_STEP);
        thch[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
        ui->Parameters_left->addRow(thchLab[i], thch[i]);
        QObject::connect(thch[i], &QDoubleSpinBox::valueChanged,[this, i](double thresh) {emit MWChang_qutagThresh(thresh, i);});
    }

      /*************Filters*********/


    QHBoxLayout *FiltersHLayout[NQUTAGCHANNELS];
    QHBoxLayout *FiltersboxesHLayout[NQUTAGCHANNELS];
    QLabel *filterLab[NQUTAGCHANNELS];

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
       // filterTypemapper->map(qutagFilterType[i]);

        QObject::connect(qutagFilterType[i], &QComboBox::currentTextChanged,[this, i](const QString text) {emit MWChang_qutag_filtertype(text, i);});

        for (int j=0;j<NQUTAGCHANNELS ;j++) {
            qutagfilter[i][j] = new QCheckBox(QString::number(j)+tr(" "));
            qutagfilter[i][j]->setStyleSheet("color: rgb(238, 238, 236);");
            FiltersboxesHLayout[i]->addWidget(qutagfilter[i][j]);
            QObject::connect(qutagfilter[i][j], &QCheckBox::stateChanged,[this, i, j](int state) {emit MWChang_qutag_filtermask(state, i, j);});
        }

        FiltersHLayout[i]->addWidget(qutagFilterType[i]);
        FiltersHLayout[i]->addLayout(FiltersboxesHLayout[i]);

    }

    /*********Delays**********/


    QLabel *delLab[NQUTAGCHANNELS];
    for (int i=0;i<NQUTAGCHANNELS ;i++) {
        delLab[i] = new QLabel(tr("Delay ch ")+QString::number(i));
        delLab[i]->setStyleSheet("color: rgb(238, 238, 236)");
        delaych[i] = new QDoubleSpinBox();
        delaych[i]->setMaximum(100000);
        delaych[i]->setMinimum(-100000);
        delaych[i]->setDecimals(0);
        delaych[i]->setSuffix(" [ps]");
        delaych[i]->setSingleStep(QUTAG_DELAY_STEP);
        delaych[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
        ui->Parameters_left->addRow(delLab[i], delaych[i]);
        QObject::connect(delaych[i], &QDoubleSpinBox::valueChanged,[this, i](double delay) {emit MWChang_qutag_delay(delay, i);});
    }

    /********** trigger polarity***********/

    QLabel *edgeLab[NQUTAGCHANNELS];

    for (int i=0;i<NQUTAGCHANNELS ;i++) {
        edgeLab[i] = new QLabel(tr("Trigger polarity ch ")+QString::number(i));
        edgeLab[i]->setStyleSheet("color: rgb(238, 238, 236)");
        qutagEdge[i] = new QComboBox();
        qutagEdge[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        qutagEdge[i] ->addItem(tr("RISE"));
        qutagEdge[i] ->addItem(tr("FALL"));

        QObject::connect(qutagEdge[i], &QComboBox::currentTextChanged,[this, i](const QString text) {emit MWChang_qutag_edge(text, i);});

        ui->parameters_R->addRow(edgeLab[i], qutagEdge[i]);
    }
}

void MainWindow::runQutag(bool a){
    if(!qutag.isRunning()){
        qutag.start();
    }
}

void MainWindow::TTU_paremetes_setup(){

    ///thresholds/////

    QLabel *thchLab[NTTUCHANNELS];

    for (int i=0;i<NTTUCHANNELS ;i++) {
        thchLab[i] = new QLabel(tr("Threshold Channel ")+QString::number(i+1));
        thchLab[i]->setStyleSheet("color: rgb(238, 238, 236)");
        threshTTU[i] = new QDoubleSpinBox();
        threshTTU[i]->setMaximum(2.5);
        threshTTU[i]->setMinimum(-2.5);
        threshTTU[i]->setDecimals(3);
        threshTTU[i]->setSuffix(" [V]");
        threshTTU[i]->setSingleStep(QUTAG_THRESHOLD_STEP);
        threshTTU[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
        ui->Parameters_left->addRow(thchLab[i], threshTTU[i]);
        QObject::connect(threshTTU[i], &QDoubleSpinBox::valueChanged,[this, i](double thresh) {emit MWChang_TTUThresh(thresh, i);});
    }

    /////rise or fall////
    QLabel *edgeLabTTU[NTTUCHANNELS];
    for (int i=0;i<NTTUCHANNELS ;i++) {
        edgeLabTTU[i] = new QLabel(tr("Trigger polarity ch ")+QString::number(i));
        edgeLabTTU[i]->setStyleSheet("color: rgb(238, 238, 236)");
        TTUEdge[i] = new QComboBox();
        TTUEdge[i]->setStyleSheet("QComboBox { background-color: darkGray }" "QListView { color: white; }");
        TTUEdge[i] ->addItem(tr("RISE"));
        TTUEdge[i] ->addItem(tr("FALL"));

        QObject::connect(TTUEdge[i], &QComboBox::currentTextChanged,[this, i](const QString text) {emit MWChang_TTU_edge(text, i);});

        ui->parameters_R->addRow(edgeLabTTU[i], TTUEdge[i]);
    }
    /*********Delays**********/


    QLabel *delLabTTU[NTTUCHANNELS];
    for (int i=0;i<NTTUCHANNELS ;i++) {
        delLabTTU[i] = new QLabel(tr("Delay ch ")+QString::number(i));
        delLabTTU[i]->setStyleSheet("color: rgb(238, 238, 236)");
        delayTTU[i] = new QDoubleSpinBox();
        delayTTU[i]->setMaximum(100000000);
        delayTTU[i]->setMinimum(-1000000);
        delayTTU[i]->setDecimals(0);
        delayTTU[i]->setSuffix(" [ps]");
        delayTTU[i]->setSingleStep(QUTAG_DELAY_STEP);
        delayTTU[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
        ui->Parameters_left->addRow(delLabTTU[i], delayTTU[i]);
        QObject::connect(delayTTU[i], &QDoubleSpinBox::valueChanged,[this, i](double delay) {emit MWChang_TTU_delay(delay, i);});
    }
}


void MainWindow::TTURes_Std(bool a){
    TTU1.SetTTResStd();
    TTU1.currentDevice = TTU;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}
void MainWindow::TTURes_A(bool a){
    TTU1.SetTTResA();
    TTU1.currentDevice = TTU;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}
void MainWindow::TTURes_B(bool a){
    TTU1.SetTTResB();
    TTU1.currentDevice = TTU;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}
void MainWindow::TTURes_C(bool a){
    TTU1.SetTTResC();
    TTU1.currentDevice = TTU;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}

void MainWindow::TTXRes_Std(bool a){
    TTU1.SetTTResStd();
    TTU1.currentDevice = TTX;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}
void MainWindow::TTXRes_B(bool a){
    TTU1.SetTTResB();
    TTU1.currentDevice = TTX;
    if(!TTU1.isRunning()){
        TTU1.start();
    }
}


void MainWindow::connectOVDLmw(){

    QString ovdlport = QFileDialog::getOpenFileName(this, tr("Open File"), "/dev/", tr("Images (ttyUSB*)"));

    if (ovdlport.isEmpty())return;
    else {
        ovdl_1.ovdlconnect(ovdlport);
    }
}


void MainWindow::addfilterMW(){


    if(numberOfFilters<MAX_N_FILTERS)numberOfFilters++;
    else return;
    int i = numberOfFilters-1;
    ////main horizontal layouts for each filter (3 rows)

    QHBoxLayout *filterParamsLayout = new QHBoxLayout();
    ui->filtersLayout->addLayout(filterParamsLayout);
    QHBoxLayout *filterWLscanLayout = new QHBoxLayout();
    ui->filtersLayout->addLayout(filterWLscanLayout);
    QHBoxLayout *filterBWscanLayout = new QHBoxLayout();
    ui->filtersLayout->addLayout(filterBWscanLayout);
    filterBWscanLayout->setContentsMargins(0,0,0,20);

    ////tiles for the main horizontal layouts, these goes on the left of the screen

    QLabel *filterTitle = new QLabel(tr("Filter ")+QString::number(numberOfFilters));// left of filterParamsLayout
    filterTitle->setStyleSheet("color: rgb(238, 238, 236)");
    filterParamsLayout->addWidget(filterTitle);
    QLabel *filterWLtitle = new QLabel(tr("Scan WL ")+QString::number(numberOfFilters));
    filterWLtitle->setStyleSheet("color: rgb(238, 238, 236)");
    filterWLscanLayout->addWidget(filterWLtitle);
    QLabel *filterBWtitle = new QLabel(tr("Scan BW ")+QString::number(numberOfFilters));
    filterBWtitle->setStyleSheet("color: rgb(238, 238, 236)");
    filterBWscanLayout->addWidget(filterBWtitle);

    ////for the first row add 3 pairs, connectButton-ip, WLlabel-WLset, BWLabel-BWset
    ///
    /// connectButton-ip
    ///
    QGridLayout *FilterFormLayout = new QGridLayout();
    filterconnect[i] = new QPushButton("connect");
    filterconnect[i]->setStyleSheet("color: rgb(238, 238, 236)");
    QObject::connect(filterconnect[i], &QPushButton::released,[this, i]() {emit MWfilterConnect(i);});
    //QObject::connect(filterconnect[i], &QPushButton::clicked,[this](bool clickedd) {qDebug()<<clickedd;});
    FilterFormLayout->addWidget(filterconnect[i],0,0);
    filterip[i] = new QLineEdit(EXFOfilters.filterips[i]);
    QObject::connect(filterip[i], &QLineEdit::returnPressed,[this, i]() {emit MWfilteripRet(filterip[i]->text(),i);});
    filterip[i]->setStyleSheet("color: rgb(238, 238, 236)");
    filterip[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    FilterFormLayout->addWidget(filterip[i],1,0);
    filterParamsLayout->addLayout(FilterFormLayout);

    ///WL label - WL set

    QLabel *filterWLlabel = new QLabel("Walvelength");
    filterWLlabel->setStyleSheet("color: rgb(238, 238, 236)");
    FilterFormLayout->addWidget(filterWLlabel,0,1);
    filterWavel[i] = new QDoubleSpinBox();
    filterWavel[i]->setMaximum(620);
    filterWavel[i]->setMinimum(480);
    filterWavel[i]->setDecimals(4);
    filterWavel[i]->setPrefix("1");
    filterWavel[i]->setSuffix(" [nm]");
    filterWavel[i]->setSingleStep(0.5);
    filterWavel[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    QObject::connect(filterWavel[i], &QDoubleSpinBox::valueChanged,[this, i](double wavel) {emit MWFilterWLChange(wavel, i);});
    filterWavel[i]->setValue(EXFOfilters.filterWLDef[i]);
    FilterFormLayout->addWidget(filterWavel[i],1,1);

    ///BW label - BW set

    QLabel *filterBWlabel = new QLabel("Bandwidth");
    filterBWlabel->setStyleSheet("color: rgb(238, 238, 236)");
    FilterFormLayout->addWidget(filterBWlabel,0,2);
    filterBandw[i] = new QSpinBox();
    filterBandw[i]->setMaximum(650);
    filterBandw[i]->setMinimum(32);
    filterBandw[i]->setSuffix(" [pm]");
    filterBandw[i]->setSingleStep(1);
    filterBandw[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    QObject::connect(filterBandw[i], &QSpinBox::valueChanged,[this, i](int bandw) {emit MWFilterBWChange(bandw, i);});
    filterBandw[i]->setValue(EXFOfilters.filterBWDef[i]);
    FilterFormLayout->addWidget(filterBandw[i],1,2);

    /////second row, WL scan with 5 elements (+labels): scanSlider, min, max,step, step duration
    ///
    ////labels:
    QGridLayout *FilterWLGridLayout = new QGridLayout();
    QLabel *WLscanLab = new QLabel("Scan");
    WLscanLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *WLscanMinLab = new QLabel("Min");
    WLscanMinLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *WLscanMaxLab = new QLabel("Max");
    WLscanMaxLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *WLscanStepSizeLab = new QLabel("Step Size");
    WLscanStepSizeLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *WLscanStepDurationLab = new QLabel("Step Duration");
    WLscanStepDurationLab->setStyleSheet("color: rgb(238, 238, 236)");
    FilterWLGridLayout->addWidget(WLscanLab, 0,0 );
    FilterWLGridLayout->addWidget(WLscanMinLab, 0,1 );
    FilterWLGridLayout->addWidget(WLscanMaxLab, 0,2 );
    FilterWLGridLayout->addWidget(WLscanStepSizeLab, 0,3 );
    FilterWLGridLayout->addWidget(WLscanStepDurationLab, 0,4 );

    ////WL scan slider
    WLscanON[i] = new QSlider(Qt::Orientation::Horizontal);
    WLscanON[i]->setMaximum(1);
    QObject::connect(WLscanON[i], &QSlider::valueChanged,[this, i](int s) {emit WLscanONsignal(s, i);});
    FilterWLGridLayout->addWidget(WLscanON[i],1,0);

    ///WL scan min
    WLscanMin[i] = new QDoubleSpinBox();
    WLscanMin[i]->setStyleSheet("color: rgb(238, 238, 236)");
    WLscanMin[i]->setMaximum(1620);
    WLscanMin[i]->setMinimum(1480);
    WLscanMin[i]->setSuffix(" [nm]");
    WLscanMin[i]->setSingleStep(1);
    WLscanMin[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterWLGridLayout->addWidget(WLscanMin[i],1,1);
    WLscanMin[i]->setValue(EXFOfilters.filterWLScanMinDef[i]);
    /////WL scan max

    WLscanMax[i] = new QDoubleSpinBox();
    WLscanMax[i]->setStyleSheet("color: rgb(238, 238, 236)");
    WLscanMax[i]->setMaximum(1620);
    WLscanMax[i]->setMinimum(1480);
    WLscanMax[i]->setSuffix(" [nm]");
    WLscanMax[i]->setSingleStep(1);
    WLscanMax[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterWLGridLayout->addWidget(WLscanMax[i],1,2);
    WLscanMax[i]->setValue(EXFOfilters.filterWLScanMaxDef[i]);
    ////WL scan step size

    WLscanstepsize[i] = new QDoubleSpinBox();
    WLscanstepsize[i]->setStyleSheet("color: rgb(238, 238, 236)");
    WLscanstepsize[i]->setMaximum(140);
    WLscanstepsize[i]->setMinimum(0.001);
    WLscanstepsize[i]->setSuffix(" [nm]");
    WLscanstepsize[i]->setSingleStep(1);
    WLscanstepsize[i]->setDecimals(3);
    WLscanstepsize[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterWLGridLayout->addWidget(WLscanstepsize[i],1,3);
    WLscanstepsize[i]->setValue(EXFOfilters.filterWLScanStepSizeDef[i]);

    ///WL scan step duration

    WLscanstepduration[i] = new QDoubleSpinBox();
    WLscanstepduration[i]->setStyleSheet("color: rgb(238, 238, 236)");
    WLscanstepduration[i]->setMaximum(86400);//one day
    WLscanstepduration[i]->setMinimum(1);
    WLscanstepduration[i]->setSuffix(" [s]");
    WLscanstepduration[i]->setSingleStep(1);
    WLscanstepduration[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterWLGridLayout->addWidget(WLscanstepduration[i],1,4);
    WLscanstepduration[i]->setValue(EXFOfilters.filterWLScanStepDurDef[i]);

    ///add the grid layout with the scan elements to the secon row layout
    filterWLscanLayout->addLayout(FilterWLGridLayout);

    ///--------------------///


    ///Thid row with the elements for BW scan: scanSlider, min, max,step, step duration
    QGridLayout *FilterBWGridLayout = new QGridLayout();

    ///labels:

    QLabel *BWscanLab = new QLabel("Scan");
    BWscanLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *BWscanMinLab = new QLabel("Min");
    BWscanMinLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *BWscanMaxLab = new QLabel("Max");
    BWscanMaxLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *BWscanStepSizeLab = new QLabel("Step Size");
    BWscanStepSizeLab->setStyleSheet("color: rgb(238, 238, 236)");
    QLabel *BWscanStepDurationLab = new QLabel("Step Duration");
    BWscanStepDurationLab->setStyleSheet("color: rgb(238, 238, 236)");
    FilterBWGridLayout->addWidget(BWscanLab, 0,0 );
    FilterBWGridLayout->addWidget(BWscanMinLab, 0,1 );
    FilterBWGridLayout->addWidget(BWscanMaxLab, 0,2 );
    FilterBWGridLayout->addWidget(BWscanStepSizeLab, 0,3 );
    FilterBWGridLayout->addWidget(BWscanStepDurationLab, 0,4 );

    ////BW scan slider
    BWscanON[i] = new QSlider(Qt::Orientation::Horizontal);
    BWscanON[i]->setMaximum(1);
    QObject::connect(BWscanON[i], &QSlider::valueChanged,[this, i](int s) {emit BWscanONsignal(s, i);});
    FilterBWGridLayout->addWidget(BWscanON[i],1,0);

    ///BW scan min

    BWscanMin[i] = new QSpinBox();
    BWscanMin[i]->setStyleSheet("color: rgb(238, 238, 236)");
    BWscanMin[i]->setMaximum(650);
    BWscanMin[i]->setMinimum(32);
    BWscanMin[i]->setSuffix(" [pm]");
    BWscanMin[i]->setSingleStep(1);
    BWscanMin[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterBWGridLayout->addWidget(BWscanMin[i],1,1);
    BWscanMin[i]->setValue(EXFOfilters.filterBWScanMinDef[i]);

    /////BW scan max

    BWscanMax[i] = new QSpinBox();
    BWscanMax[i]->setStyleSheet("color: rgb(238, 238, 236)");
    BWscanMax[i]->setMaximum(650);
    BWscanMax[i]->setMinimum(32);
    BWscanMax[i]->setSuffix(" [pm]");
    BWscanMax[i]->setSingleStep(1);
    BWscanMax[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterBWGridLayout->addWidget(BWscanMax[i],1,2);
    BWscanMax[i]->setValue(EXFOfilters.filterBWScanMaxDef[i]);

    ////BW scan step size

    BWscanstepsize[i] = new QSpinBox();
    BWscanstepsize[i]->setStyleSheet("color: rgb(238, 238, 236)");
    BWscanstepsize[i]->setMaximum(618);
    BWscanstepsize[i]->setMinimum(1);
    BWscanstepsize[i]->setSuffix(" [pm]");
    BWscanstepsize[i]->setSingleStep(1);
    BWscanstepsize[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterBWGridLayout->addWidget(BWscanstepsize[i],1,3);
    BWscanstepsize[i]->setValue(EXFOfilters.filterBWScanStepSizeDef[i]);


    ///BW scan step duration

    BWscanstepduration[i] = new QDoubleSpinBox();
    BWscanstepduration[i]->setStyleSheet("color: rgb(238, 238, 236)");
    BWscanstepduration[i]->setMaximum(86400);//one day
    BWscanstepduration[i]->setMinimum(1);
    BWscanstepduration[i]->setSuffix(" [s]");
    BWscanstepduration[i]->setSingleStep(1);
    BWscanstepduration[i]->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255)); color: rgb(238, 238, 236)");
    FilterBWGridLayout->addWidget(BWscanstepduration[i],1,4);
    BWscanstepduration[i]->setValue(EXFOfilters.filterBWScanStepDurDef[i]);

    ///add the grid layout with the scan elements to the secon row layout
    filterBWscanLayout->addLayout(FilterBWGridLayout);



}

void MainWindow::loadFilterWL(float val, int dev){

    if(dev<numberOfFilters){
        QSignalBlocker blocker(filterWavel[dev]);
        filterWavel[dev]->setValue((double)val);
        blocker.unblock();
    }
}

void MainWindow::loadFilterBW(int val, int dev){
    if(dev<numberOfFilters){
        QSignalBlocker blocker(filterBandw[dev]);
        filterBandw[dev]->setValue(val);
        blocker.unblock();
    }
}

void MainWindow::BWfilterscanslot(int signal, int i){
    filterBandw[i]->setValue(BWscanMin[i]->value());
    if(BWscantimer[i]!=nullptr && signal==0){
        BWscantimer[i]->stop();
    }
    if(BWscantimer[i]==nullptr && signal){
        BWscantimer[i] = new QTimer(this);
        connect(BWscantimer[i], &QTimer::timeout, [this,i]() {BWscanstep(i);});
    }

    if(BWscantimer[i]!=nullptr && signal )BWscantimer[i]->start(BWscanstepduration[i]->value()*1000);


}

void MainWindow::WLfilterscanslot(int signal, int i){

    filterWavel[i]->setValue(WLscanMin[i]->value()-1000);
    if(WLscantimer[i]!=nullptr && signal==0){
        WLscantimer[i]->stop();
    }
    if(WLscantimer[i]==nullptr && signal){
        WLscantimer[i] = new QTimer(this);
        connect(WLscantimer[i], &QTimer::timeout, [this,i]() {WLscanstep(i);});
    }

    if(WLscantimer[i]!=nullptr && signal )WLscantimer[i]->start(WLscanstepduration[i]->value()*1000);
}


void MainWindow::BWscanstep(int i){
    if(filterBandw[i]->value() < BWscanMax[i]->value()){

        //filterBandw[i]->setValue(filterBandw[i]->value()+BWscanstepsize[i]->value());
        QString current = QString::number(filterBandw[i]->value()) ;
        int newval = current.toInt() + BWscanstepsize[i]->value();
        filterBandw[i]->setValue(newval);

    }else{
        if(loopfilterscanvar)filterBandw[i]->setValue(BWscanMin[i]->value());
        else BWscantimer[i]->stop();
    }
}

void MainWindow::WLscanstep(int i){
    if(filterWavel[i]->value() < WLscanMax[i]->value()-1000){

        QString current = QString::number(filterWavel[i]->value(),'f',filterWavel[i]->decimals()) ;    
        double newval = current.toDouble() + WLscanstepsize[i]->value();
        filterWavel[i]->setValue(newval);

    }else{
        if(loopfilterscanvar)filterWavel[i]->setValue(WLscanMin[i]->value()-1000);
        else WLscantimer[i]->stop();
    }
}

void MainWindow::t2showcurrent(int a){
    if(a){
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicCurrent[i]->setVisible(true);
            t2labcur->setVisible(true);
        }
    }
    else{
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicCurrent[i]->setVisible(false);
            t2labcur->setVisible(false);

        }
    }
}

void MainWindow::t2showmin(int a){
    if(a){
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicMin[i]->setVisible(true);
            t2labmin->setVisible(true);
        }
    }
    else{
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicMin[i]->setVisible(false);
            t2labmin->setVisible(false);

        }
    }
}
void MainWindow::t2showmax(int a){
    if(a){
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicMax[i]->setVisible(true);
            t2labmax->setVisible(true);
        }
    }
    else{
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicMax[i]->setVisible(false);
            t2labmax->setVisible(false);

        }
    }
}
void MainWindow::t2showavr(int a){
    if(a){
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicAvr[i]->setVisible(true);
            t2labavr->setVisible(true);
        }
    }
    else{
        for (int i = 0; i < numberOfLogicPlots; i++) {
            LogicAvr[i]->setVisible(false);
            t2labavr->setVisible(false);

        }
    }
}


void MainWindow::programDBoff(){

    int dboffinms = QDateTime::currentDateTime().msecsTo(ui->dbcronometeroff->dateTime());
    std::cout<<"database will be off in "<<dboffinms/60000<<" minutes, miliseconds: "<<dboffinms<<std::endl;
    ui->dbcronometeroff->setStyleSheet("color: rgb(238, 0, 0)");
    QTimer::singleShot(dboffinms, this, SLOT(slideDBoff()));
}
void MainWindow::slideDBoff(){ui->DBON->setValue(0); ui->dbcronometeroff->setStyleSheet("color: rgb(238, 238, 236)");}
