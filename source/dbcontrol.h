#ifndef DBCONTROL_H
#define DBCONTROL_H

#include <QString>
#include <QtSql>
#include <QObject>
#include <QtCore>
#include <iostream>//entradas y salidas por consola
#include <fstream>//archivos.txt
#include <qlabel.h>
#include "typedefs.h"



class DBControl : public QThread
{
    Q_OBJECT

public:
    void run();
    explicit DBControl();
    ~DBControl();
    void disconnectFromServer();
    void DBConnect(QString server, int port, QString database, QString login, QString password);

    bool connection_succesfull;
private:
    QSqlDatabase db;

    //bool connectToServerMySQL(QString server, int port, QString database, QString login, QString password);
    QString server, database, user, passwd;
    int port;
    QString currentTableTab2, currentColumnstab2, currentTableTab1, currentColumnstab1;
    int NTA,NTB,NTC,NTD;
    int DB_numberOfLogicPlots = 0;
    int Noffilters = 0;
    double filtersWLcurrentValue[MAX_N_FILTERS];
    int filtersBWcurrentValue[MAX_N_FILTERS];
    QVector<int> _channels;
signals:

public slots:
    void SaveTab2Values(vectorDouble datatab2, float andTime, double delayline);
    void SaveTab1Values(QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD , float hist_adqtime);
    void CreateTableTab2(QVector<int> channels, QVector<int> logicL,QVector<int> logicR,QVector<int> WinL,QVector<int> WinR, QVector<bool> gate,int filters, QLabel *lab);
    void CreateTableTab1(int PlotA, int PlotB, int PlotC , int PlotD, QLabel *lab );
    void setfiltersBW(int bw, int n){filtersBWcurrentValue[n]=bw;}
    void setfiltersWL(double wavel, int n){filtersWLcurrentValue[n]=wavel;}

};
#endif // DBCONTROL_H
