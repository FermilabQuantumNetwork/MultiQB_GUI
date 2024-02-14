#include "gui_param.h"
#include "ui_gui_param.h"

GUI_param::GUI_param(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_param)
{
    ui->setupUi(this);

    QApplication::connect(ui->QKD_time, SIGNAL(valueChanged(double)), this, SLOT(slot_QKD_time(double)));
    QApplication::connect(ui->QKD_numb, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_numb(int)));



    QApplication::connect(ui->QKD_phA, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_phA(int)));
    QApplication::connect(ui->QKD_phB, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_phB(int)));
    QApplication::connect(ui->QKD_phC, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_phC(int)));
    QApplication::connect(ui->QKD_phD, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_phD(int)));

    QApplication::connect(ui->QKD_iwA, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_iwA(int)));
    QApplication::connect(ui->QKD_iwB, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_iwB(int)));
    QApplication::connect(ui->QKD_iwC, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_iwC(int)));
    QApplication::connect(ui->QKD_iwD, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_iwD(int)));

    QApplication::connect(ui->QKD_pxqA, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_pxqA(int)));
    QApplication::connect(ui->QKD_pxqB, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_pxqB(int)));
    QApplication::connect(ui->QKD_pxqC, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_pxqC(int)));
    QApplication::connect(ui->QKD_pxqD, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_pxqD(int)));

    QApplication::connect(ui->QKD_zeroA, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_zeroA(int)));
    QApplication::connect(ui->QKD_zeroB, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_zeroB(int)));
    QApplication::connect(ui->QKD_zeroC, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_zeroC(int)));
    QApplication::connect(ui->QKD_zeroD, SIGNAL(valueChanged(int)), this, SLOT(slot_QKD_zeroD(int)));

    QApplication::connect(ui->PlotA_log, SIGNAL(stateChanged(int)), this, SLOT(slot_PlotA_log(int)));
    QApplication::connect(ui->PlotB_log, SIGNAL(stateChanged(int)), this, SLOT(slot_PlotB_log(int)));
    QApplication::connect(ui->PlotC_log, SIGNAL(stateChanged(int)), this, SLOT(slot_PlotC_log(int)));
    QApplication::connect(ui->PlotD_log, SIGNAL(stateChanged(int)), this, SLOT(slot_PlotD_log(int)));

    QObject::connect(ui->QKD_DB, SIGNAL(valueChanged(int)), this, SLOT(turnONDB(int)));

    QApplication::connect(ui->hdf5, SIGNAL(released()), this, SLOT(in_savehdf5()));

    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    ui->QKD_time->setMaximum(MAX_QUBIT_TIME);
    ui->QKD_numb->setMaximum(MAX_QUBITS);
    ui->QKD_numb->setMinimum(0);

    ui->QKD_phA->setMaximum(MAX_PHASE);
    ui->QKD_phB->setMaximum(MAX_PHASE);
    ui->QKD_phC->setMaximum(MAX_PHASE);
    ui->QKD_phD->setMaximum(MAX_PHASE);

    ui->QKD_iwA->setMaximum(MAX_INT_WIN);
    ui->QKD_iwB->setMaximum(MAX_INT_WIN);
    ui->QKD_iwC->setMaximum(MAX_INT_WIN);
    ui->QKD_iwD->setMaximum(MAX_INT_WIN);

    ui->QKD_pxqA->setMaximum(MAX_WIN);
    ui->QKD_pxqB->setMaximum(MAX_WIN);
    ui->QKD_pxqC->setMaximum(MAX_WIN);
    ui->QKD_pxqD->setMaximum(MAX_WIN);

    ui->QKD_zeroA->setMaximum(MAX_LINES_OFFSET);
    ui->QKD_zeroB->setMaximum(MAX_LINES_OFFSET);
    ui->QKD_zeroC->setMaximum(MAX_LINES_OFFSET);
    ui->QKD_zeroD->setMaximum(MAX_LINES_OFFSET);


}

void GUI_param::QKD_setDefault(){
    if(LoadPrevoiusSeason(1)){
        ui->QKD_time->setValue(10000);
        ui->QKD_numb->setValue(10);

        ui->QKD_phA->setValue(2000);
        ui->QKD_phB->setValue(2000);
        ui->QKD_phC->setValue(2000);
        ui->QKD_phD->setValue(2000);

        ui->QKD_iwA->setValue(1900);
        ui->QKD_iwB->setValue(1900);
        ui->QKD_iwC->setValue(1900);
        ui->QKD_iwD->setValue(1900);

        ui->QKD_pxqA->setValue(2);
        ui->QKD_pxqB->setValue(2);
        ui->QKD_pxqC->setValue(2);
        ui->QKD_pxqD->setValue(2);

        ui->QKD_zeroA->setValue(80);
        ui->QKD_zeroB->setValue(0);
        ui->QKD_zeroC->setValue(0);
        ui->QKD_zeroD->setValue(0);
    }
}

bool GUI_param::LoadPrevoiusSeason(bool a){

    QString fileName = "LastSeasonVariables.conf";
    if (fileName.isEmpty())return 1;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        std::cout<<"Unable to open file"<<std::endl;
        return 1;
    }
    std::cout<<"loading previous season parameters <<qubits>>"<<std::endl;
    QMap<QString, int> mapintout;
    QMap<QString, double> mapdoubleout;
    QDataStream in(&file);
    //in.setVersion(QDataStream::Qt_4_5);
    in>>mapintout;


    QMapIterator<QString,int>i(mapintout);
    while (i.hasNext()) {
        i.next();
       //std::cout<< i.key().toStdString() <<  ": " << i.value() << std::endl;
    }
    in>>mapdoubleout;
    QMapIterator<QString,double>j(mapdoubleout);
    while (j.hasNext()) {
        j.next();
     //   std::cout<< j.key().toStdString() <<  ": " << j.value() << std::endl;
    }

    if(mapdoubleout.contains("QKD_time"))ui->QKD_time->setValue(mapdoubleout.value("QKD_time"));
    else ui->QKD_time->setValue(10000);
    if(mapintout.contains("QKD_numb"))ui->QKD_numb->setValue(mapintout.value("QKD_numb"));
    else ui->QKD_numb->setValue(10);

    if(mapintout.contains("QKD_phA"))ui->QKD_phA->setValue(mapintout.value("QKD_phA"));
    else ui->QKD_phA->setValue(2000);
    if(mapintout.contains("QKD_iwA"))ui->QKD_iwA->setValue(mapintout.value("QKD_iwA"));
    else ui->QKD_iwA->setValue(1900);
    if(mapintout.contains("QKD_pxqA"))ui->QKD_pxqA->setValue(mapintout.value("QKD_pxqA"));
    else ui->QKD_pxqA->setValue(2);
    if(mapintout.contains("QKD_zeroA"))ui->QKD_zeroA->setValue(mapintout.value("QKD_zeroA"));
    else  ui->QKD_zeroA->setValue(80);


    if(mapintout.contains("QKD_phB"))ui->QKD_phB->setValue(mapintout.value("QKD_phB"));
    else ui->QKD_phB->setValue(2000);
    if(mapintout.contains("QKD_iwB"))ui->QKD_iwB->setValue(mapintout.value("QKD_iwB"));
    else ui->QKD_iwB->setValue(1900);
    if(mapintout.contains("QKD_pxqB"))ui->QKD_pxqB->setValue(mapintout.value("QKD_pxqB"));
    else ui->QKD_pxqB->setValue(2);
    if(mapintout.contains("QKD_zeroB"))ui->QKD_zeroB->setValue(mapintout.value("QKD_zeroB"));
    else ui->QKD_zeroB->setValue(0);

    if(mapintout.contains("QKD_phC"))ui->QKD_phC->setValue(mapintout.value("QKD_phC"));
    else ui->QKD_phC->setValue(2000);
    if(mapintout.contains("QKD_iwC"))ui->QKD_iwC->setValue(mapintout.value("QKD_iwC"));
    else ui->QKD_iwC->setValue(1900);
    if(mapintout.contains("QKD_pxqC"))ui->QKD_pxqC->setValue(mapintout.value("QKD_pxqC"));
    else ui->QKD_pxqC->setValue(2);
    if(mapintout.contains("QKD_zeroC"))ui->QKD_zeroC->setValue(mapintout.value("QKD_zeroC"));
    else ui->QKD_zeroC->setValue(0);

    if(mapintout.contains("QKD_phD"))ui->QKD_phD->setValue(mapintout.value("QKD_phD"));
    else ui->QKD_phD->setValue(2000);
    if(mapintout.contains("QKD_iwD"))ui->QKD_iwD->setValue(mapintout.value("QKD_iwD"));
    else ui->QKD_iwD->setValue(1900);
    if(mapintout.contains("QKD_pxqD"))ui->QKD_pxqD->setValue(mapintout.value("QKD_pxqD"));
    else ui->QKD_pxqD->setValue(2);
    if(mapintout.contains("QKD_zeroD"))ui->QKD_zeroD->setValue(mapintout.value("QKD_zeroD"));
    else ui->QKD_zeroD->setValue(0);

    file.close();
    return 0;
}


GUI_param::~GUI_param()
{
    delete ui;
}
