#ifndef TIMETAGGERULTRA_H
#define TIMETAGGERULTRA_H

#include <QObject>
#include <QtCore>

#include "CustomDelayedChannel.h"
#include "CustomStartStop.h"
#include "typedefs.h"

#include <Iterators.h>
#include <TimeTagger.h>

#define EVENT_BUFFER_SIZE 1000000
#define NTTUCHANNELS 8
#define TTUSTARTCHANNEL 1


class timetaggerUltra : public QThread
{
    Q_OBJECT
public:
    void run();
    explicit timetaggerUltra();
    ~timetaggerUltra();
    bool anlAvilable = false;
    int in_TSON=0;
    bool break_;
    int in_binsinplot, in_histStart, in_binWidth;
    double in_adqtime;
    QVector<int64_t> timetags;
    QVector<int> channelsTDC;
    int TSpercentage=10;
    int in_binwidth=1;
    int in_nbins=1000;


public slots:
    void TSanl(int val){this->in_TSON=val;}
    void changTSper(int val){this->TSpercentage=val;}
    void Break(){break_= true;}

private:
    TimeTagger *t;
    TimeTagStream *tts;
    SynchronizedMeasurements *tmg;
    Histogram *ttuhisto[NTTUCHANNELS];

    void getTimeStampsTTU();
    void getHisto();
    void setHistograms();
    QVector<double> dataA;
    QVector<double> dataB;
    QVector<double> dataC;
    QVector<double> dataD;



signals:
         // void dataready(const vectorInt64 &TTdata, const channelsTDCPP &CHdata, int nevent); // sends to inputdata()
    void dataready(const vectorInt64 &vectorTimetags, const vectorInt &vectorChannels, int tsvalid);
    void qutaghist(const vectorDouble &TTdata1, const vectorDouble &TTdata2, const vectorDouble &TTdata3, const vectorDouble &TTdata4, int count1, int count2, int count3, int count4);
    void TDCerror(QString);
    void initdone();

};

#endif // TIMETAGGERULTRA_H
