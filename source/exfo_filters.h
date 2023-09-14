#ifndef EXFO_FILTERS_H
#define EXFO_FILTERS_H

#include <QtCore>
#include <QtNetwork>


#define EXFO_IP1    "192.168.0.105"
#define EXFO_IP2    "192.168.0.156"
#define MAX_N_FILTERS 10
class EXFO_Filters : public QObject
{
    Q_OBJECT
public:
    EXFO_Filters();
    ~EXFO_Filters();
    int NofFilters = 0;
    QString filterips[MAX_N_FILTERS] = {""};

private:

    QTcpSocket *socket[MAX_N_FILTERS] = {NULL};
    QRegularExpression *readlambda;
    QRegularExpression *readfwhm;
    bool initdoneBW = false;
    bool initdoneWL = false;

public slots:

    void filterConnect(int n);
    void setIP(QString ip, int n);

    void setBandwidth(int bw, int n);
    void setWavelength(double wavel, int n);

    void readTcpData(int n);
    void FilterConnected(int n);
    void FilterDisconnected(int n);
    void FilterbytesWritten(qint64 data, int n);

signals:
    void DeviceWL(float a, int dev);
    void DeviceBW(int a, int dev);
};

#endif // EXFO_FILTERS_H
