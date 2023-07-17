#ifndef TIMETAGGERULTRA_H
#define TIMETAGGERULTRA_H

#include <QObject>
#include <QtCore>

#include "CustomDelayedChannel.h"
#include "CustomStartStop.h"

#include <Iterators.h>
#include <TimeTagger.h>

class timetaggerUltra : public QThread
{
    Q_OBJECT
public:
    void run(){}
    explicit timetaggerUltra();

signals:

};

#endif // TIMETAGGERULTRA_H
