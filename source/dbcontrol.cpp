#include "dbcontrol.h"
#include <iostream>
#include <time.h>

DBControl::DBControl(){
    QString val;
    QFile file("databaseInfo.json");
    //file.setFileName;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue subobj1 = d["server"];
    server = subobj1.toString();
    QJsonValue subobj2 = d["port"];
    port = subobj2.toInt();
    QJsonValue subobj3 = d["DBName"];
    database = subobj3.toString();
    QJsonValue subobj4 = d["user"];
    user = subobj4.toString();
    QJsonValue subobj5 = d["pass"];
    passwd = subobj5.toString();

}

DBControl::~DBControl(){
    if(db.isOpen())db.close();
    std::cout<<"log off from DB"<<std::endl;
}

void DBControl::run(){

    //this->DBConnect("localhost", 3306, "INQNET_GUI", "GUI2", "Teleport1536!");

}

void DBControl::DBConnect(QString server, int port, QString database, QString login, QString password){

    this->DBConnect(server, port, database, user, passwd);
    std::cout<<"server:"<<server.toStdString()<<"  port:"<<port<<std::endl;

    db = QSqlDatabase();
    db.removeDatabase("example-connection"); // remove old connection if exists
    db = QSqlDatabase::addDatabase("QMYSQL", "example-connection");

    connection_succesfull = connectToServerMySQL(server, port, database, login, password);
    if(connection_succesfull){
        std::cout<<"connection DB success"<<std::endl;
       /* QStringList tables_names = db.tables();
        for (int i = 0; i < tables_names.size(); ++i)
                 //std::cout << tables_names.at(i).toLocal8Bit().constData() << std::endl;
       QSqlQuery query("create table if not exists inqnet_gui_tab2gates_V3(id int not null auto_increment primary key, and1 int,and2 int, and3 int, orgate int, bsm1 int, bsm2 int, and_adqtime float(7,2), delayline int,currentdelay double, attenuation double, datetime datetime);",db);
       QSqlQuery query2("create table if not exists inqnet_gui_NEWhistorates(id int not null auto_increment primary key, Ra1 int,Ra2 int, Ra3 int, Ra4 int, Rb1 int,Rb2 int, Rb3 int, Rb4 int, Rc1 int,Rc2 int, Rc3 int, Rc4 int, Rd1 int,Rd2 int, Rd3 int, Rd4 int ,hist_adqtime float(7,2), datetime datetime);",db);
       usleep(1000);
       */
    }
    else std::cout<<"database connection failed "<<std::endl;

}


bool DBControl::connectToServerMySQL(QString server, int port, QString database,
                                        QString login, QString password)
{
    db.setHostName(server);
    db.setPort(port);
    db.setDatabaseName(database);
    db.setUserName(login);
    db.setPassword(password);
    bool ret =db.open();
    qDebug() << db.lastError();
    return ret;
}

void DBControl::SaveTab2Values(QVector<int> datatab2, float andTime, int delayline){
    //QString s= "insert into inqnet_gui_tab2gates_V3(and1,and2, and3, orgate, bsm1, bsm2, and_adqtime, delayline, datetime) values("+QString::number(and1)+","+QString::number(and2)+","+QString::number(and3)+","+QString::number(orgate)+","+QString::number(bsm1)+","+QString::number(bsm2)+","+QString::number(andTime)+","+QString::number(delayline)+","+"now());";
    QString s ="insert into "+currentTableTab2+"("+currentColumnstab2+"and_adqtime, delayline, datetime) values(";
    for (int i=0;i<datatab2.size();i++) {
        s+=QString::number(datatab2[i])+",";
    }
    s+=QString::number(double(andTime))+","+QString::number(delayline)+","+"now());";
    //std::cout<<s.toStdString()<<std::endl;
    if(connection_succesfull){
        QSqlQuery query(s,db);
    }

}

void DBControl::SaveTab1Values(QVector<int> PlotA, QVector<int> PlotB, QVector<int> PlotC , QVector<int> PlotD , float hist_adqtime){
    //QString s= "insert into inqnet_gui_historates(Ra1, Ra2, Ra3, Ra4, Rb1, Rb2, Rb3, Rb4, Rc1, Rc2, Rc3, Rc4, Rd1, Rd2, Rd3, Rd4, hist_adqtime, datetime) values("+QString::number(Ra1)+","+QString::number(Ra2)+","+QString::number(Ra3)+","+QString::number(Ra4)+","+QString::number(Rb1)+","+QString::number(Rb2)+","+QString::number(Rb3)+","+QString::number(Rb4)+","+QString::number(Rc1)+","+QString::number(Rc2)+","+QString::number(Rc3)+","+QString::number(Rc4)+","+QString::number(Rd1)+","+QString::number(Rd2)+","+QString::number(Rd3)+","+QString::number(Rd4)+","+QString::number(hist_adqtime)+","+"now());";
    QString s = "insert into "+currentTableTab1+"("+currentColumnstab1+"hist_adqtime, datetime) values(";
    //std::cout<<s.toStdString()<<std::endl;
    for (int i=0;i<PlotA.size();i++) {
        s+=QString::number(PlotA[i])+",";
    }
    for (int i=0;i<PlotB.size();i++) {
        s+=QString::number(PlotB[i])+",";
    }
    for (int i=0;i<PlotC.size();i++) {
        s+=QString::number(PlotC[i])+",";
    }
    for (int i=0;i<PlotD.size();i++) {
        s+=QString::number(PlotD[i])+",";
    }
    s+=QString::number(double(hist_adqtime))+","+"now());";
    if(connection_succesfull){
       //std::cout<<s.toStdString()<<std::endl;
       QSqlQuery query(s,db);
   }
}

void DBControl::CreateTableTab2(QVector<int> channels, QVector<int> logicL,QVector<int> logicR,QVector<int> WinL,QVector<int> WinR, QVector<bool> gate){
    QString columnstocreate;
    for (int i=0;i<channels.size();i++) {
        currentColumnstab2+="ch"+QString::number(channels[i])+",";
        columnstocreate+="ch"+QString::number(channels[i])+" int,";
    }
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd_MM_yyyy_hh_mm_ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    currentTableTab2 = "TAB2"+formattedTimeMsg;
    QSqlQuery query("create table if not exists "+currentTableTab2+"(id int not null auto_increment primary key,"+columnstocreate+" and_adqtime float, delayline int, datetime datetime);",db);

    QString filename = "databaseLOG_logic.txt";
    QFile dblog(filename);

    if(dblog.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Append)){
        QTextStream out(&dblog);
        out<<formattedTimeMsg <<"\t Tab 2 \t";
        for (int i=0;i<channels.size();i++) {
            out<<"channel"+QString::number(channels[i])<<"/Left_";
            if(logicL[i]==-1)out<<"PlotA/WinL"<<QString::number(WinL[i]);
            if(logicL[i]==-2)out<<"PlotB/WinL"<<QString::number(WinL[i]);
            if(logicL[i]==-3)out<<"PlotC/WinL"<<QString::number(WinL[i]);
            if(logicL[i]==-4)out<<"PlotD/WinL"<<QString::number(WinL[i]);
            if(logicL[i]>-1)out<<QString::number(logicL[i]);
            if(gate[i])out<<"/AND/Right_";
            if(!gate[i]) out<<"/OR/Right_";
            if(logicR[i]==-1)out<<"PlotA/WinR"<<QString::number(WinR[i]);
            if(logicR[i]==-2)out<<"PlotB/WinR"<<QString::number(WinR[i]);
            if(logicR[i]==-3)out<<"PlotC/WinR"<<QString::number(WinR[i]);
            if(logicR[i]==-4)out<<"PlotD/WinR"<<QString::number(WinR[i]);
            if(logicR[i]>-1)out<<QString::number(logicR[i]);
            out<<"\t";
        }
        out<<"\n";
        dblog.close();
    }
}
void DBControl::CreateTableTab1(int PlotA, int PlotB, int PlotC , int PlotD ){
    QString columnstocreate;
    NTA=0;NTB=0;NTC=0;NTD=0;
    for (int i=0;i<PlotA;i++) {
        currentColumnstab1+="A"+QString::number(i)+",";
        columnstocreate+="A"+QString::number(i)+" int,";
        NTA++;
    }
    for (int i=0;i<PlotB;i++) {
        currentColumnstab1+="B"+QString::number(i)+",";
        columnstocreate+="B"+QString::number(i)+" int,";
        NTB++;
    }
    for (int i=0;i<PlotC;i++) {
        currentColumnstab1+="C"+QString::number(i)+",";
        columnstocreate+="C"+QString::number(i)+" int,";
        NTC++;
    }
    for (int i=0;i<PlotD;i++) {
        currentColumnstab1+="D"+QString::number(i)+",";
        columnstocreate+="D"+QString::number(i)+" int,";
        NTD++;
    }
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd_MM_yyyy_hh_mm_ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    currentTableTab1 = "TAB1"+formattedTimeMsg;
    QString st = "create table if not exists "+currentTableTab1+"(id int not null auto_increment primary key,"+columnstocreate+" hist_adqtime float, datetime datetime);";
    std::cout<<st.toStdString()<<std::endl;
    QSqlQuery query(st, db);
  /*  QString filename = "databaseLOG_Rates.txt";
    QFile dblog(filename);

    if(dblog.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Append)){
        QTextStream out(&dblog);
        out<<formattedTimeMsg <<"\t Tab 2 \t";
        for (int i=0;i<channels.size();i++) {
            out<<"channel"+QString::number(channels[i])<<"/Left_";
        }
        out<<"\n";
        dblog.close();
    }*/
}

void DBControl::disconnectFromServer()
{
    db.close();
}


