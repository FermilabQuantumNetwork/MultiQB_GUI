#ifndef OVDL_H
#define OVDL_H

#include <QObject>
#include <QSerialPort>
#include <iostream>

#define OVDL_PORT "ttyUSB0"

class OVDL : public QObject
{
    Q_OBJECT
public:
    explicit OVDL(QObject *parent = 0);
    QSerialPort *delaylineport;
signals:

public slots:
    void setDelay(float timeps);
};

#endif // OVDL_H
