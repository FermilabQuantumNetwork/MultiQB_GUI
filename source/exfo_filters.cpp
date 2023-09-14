#include "exfo_filters.h"

EXFO_Filters::EXFO_Filters()
{
    filterips[0] = EXFO_IP1;
    filterips[1] = EXFO_IP2;

    readlambda = new QRegularExpression("^LAMBDA=(?<value>([0-9]*[.])?[0-9]+)\r\n$");
    readfwhm = new QRegularExpression("^FWHM=(?<value>([0-9]*[.])?[0-9]+)\r\n$");

}

EXFO_Filters::~EXFO_Filters(){

    for(int i=0; i < NofFilters; i++){
        if(socket[i]->state() == QAbstractSocket::ConnectedState)socket[i]->disconnectFromHost();
    }
}

void EXFO_Filters::setBandwidth(int bw, int n){
    float fwhm = (float)bw/1000; // value comes in pm, command needs nm
    qDebug()<<fwhm;
    if(n<NofFilters){
        if(socket[n]->state() == QAbstractSocket::ConnectedState && bw>31 && bw<651){
            QString dataqs = "FWHM="+QString::number(fwhm)+"\r\n";
            qDebug()<<dataqs;
            socket[n]->write(dataqs.toUtf8());
        }
    }
}

void EXFO_Filters::setWavelength(double wavel, int n){
    if(n<NofFilters){
        if(socket[n]->state() == QAbstractSocket::ConnectedState){
            QString dataqs = "LAMBDA="+QString::number(wavel)+"\r\n";
            socket[n]->write(dataqs.toUtf8());
        }
    }
}

void EXFO_Filters::filterConnect(int n){

    NofFilters = n+1;

    qDebug()<<"ip :"<<filterips[n];

    if(socket[n] == NULL){
        qDebug() << "creating a new socket...."<<n;
        socket[n] = new QTcpSocket(this);
        connect(socket[n], &QTcpSocket::readyRead,[this, n]() { readTcpData(n); });
        connect(socket[n], &QTcpSocket::connected,[this,n](){ FilterConnected(n);});
        connect(socket[n], &QTcpSocket::disconnected, [this,n](){ FilterDisconnected(n);});
        connect(socket[n], &QTcpSocket::bytesWritten,[this,n](qint64 data){ FilterbytesWritten(data, n);});
    }

    //connect( socket[n], SIGNAL(readyRead()), this, SLOT(readTcpData()) );
    //QObject::connect(socket[n], &QTcpSocket::readyRead,[this, n]() {readTcpData(n);});
    //if(socket[n]->state() == QAbstractSocket::UnconnectedState){
    socket[n]->connectToHost(filterips[n], 5025);
    if(!socket[n]->waitForConnected(10000))
    {
        qDebug() << "Error: " << socket[n]->errorString();
    }
}

void EXFO_Filters::setIP(QString ip, int n){
    filterips[n]=ip;
   // qDebug()<<filterips[n];

}

void EXFO_Filters::readTcpData(int n)
{
    QByteArray data = socket[n]->readAll();
    //qDebug()<<"en la read fucntion";
    QString message = QString::fromUtf8(data);
    qDebug()<<message;

    QRegularExpressionMatch match1 = readlambda->match(message);
    if (match1.hasMatch()) {
        QString LAMBDA = match1.captured("value");
        if(!initdoneBW){
                emit DeviceWL(LAMBDA.toFloat(), n);
                initdoneWL=true;
        }
        //qDebug()<<LAMBDA;
    }



    QRegularExpressionMatch match2 = readfwhm->match(message);
    if (match2.hasMatch()) {
        QString FWHM = match2.captured("value");
        if(!initdoneBW){
            emit DeviceBW((int)(FWHM.toFloat()*1000), n);
            initdoneBW=true;
        }
        //qDebug()<<FWHM;
    }

}
void EXFO_Filters::FilterConnected(int n){
    //qDebug()<<"really connected";
    QString dataqs = "*IDN?\r\n";
    socket[n]->write(dataqs.toUtf8()); //write the data itself
    dataqs = "LAMBDA?\r\n";
    socket[n]->write(dataqs.toUtf8()); //write the data itself
    dataqs = "FWHM?\r\n";
    socket[n]->write(dataqs.toUtf8()); //write the data itself
}

void EXFO_Filters::FilterDisconnected(int n){
    qDebug()<<"filter " <<n<< " disconected..";
}

void EXFO_Filters::FilterbytesWritten(qint64 data, int n){
    qDebug() << data << " bytes written...";
}
