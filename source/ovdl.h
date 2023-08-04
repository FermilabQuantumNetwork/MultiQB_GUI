#ifndef OVDL_H
#define OVDL_H

#include <QObject>
#include <QSerialPort>
#include <iostream>
#include <QFileDialog>

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
    void ovdlconnect(QString s);
};

#endif // OVDL_H
