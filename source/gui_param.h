#ifndef GUI_PARAM_H
#define GUI_PARAM_H

#include <QWidget>
#include <stdio.h>
#include <QtCore>
#include <iostream>//entradas y salidas por consola
#include <fstream>//archivos.txt

namespace Ui {
class GUI_param;
}

class GUI_param : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_param(QWidget *parent = nullptr);
    ~GUI_param();
    void QKD_setDefault();
    bool LoadPrevoiusSeason(bool a);
    void SaveSeason(bool a);


private:
    Ui::GUI_param *ui;
    int  in_QKD_numb, in_QKD_phA, in_QKD_iwA, in_QKD_pxqA, in_QKD_zeroA;
    int   in_QKD_phB, in_QKD_iwB, in_QKD_pxqB, in_QKD_zeroB;
    int   in_QKD_phC, in_QKD_iwC, in_QKD_pxqC, in_QKD_zeroC;
    int   in_QKD_phD, in_QKD_iwD, in_QKD_pxqD, in_QKD_zeroD;
    double in_QKD_time;


signals:
    void sig_QKD_time(double a);
    /*void sig_QKD_timeB(double a);
    void sig_QKD_timeC(double a);
    void sig_QKD_timeD(double a);*/

    void sig_QKD_numb(int a);
    /*void sig_QKD_numbB(int a);
    void sig_QKD_numbC(int a);
    void sig_QKD_numbD(int a);*/

    void sig_QKD_phA(int a);
    void sig_QKD_phB(int a);
    void sig_QKD_phC(int a);
    void sig_QKD_phD(int a);

    void sig_QKD_iwA(int a);
    void sig_QKD_iwB(int a);
    void sig_QKD_iwC(int a);
    void sig_QKD_iwD(int a);

    void sig_QKD_pxqA(int a);
    void sig_QKD_pxqB(int a);
    void sig_QKD_pxqC(int a);
    void sig_QKD_pxqD(int a);

    void sig_QKD_zeroA(int a);
    void sig_QKD_zeroB(int a);
    void sig_QKD_zeroC(int a);
    void sig_QKD_zeroD(int a);

    void savehdf5();
    void sig_turnONDB(int a);

    void sig_PlotA_log(int a);
    void sig_PlotB_log(int a);
    void sig_PlotC_log(int a);
    void sig_PlotD_log(int a);


public slots:

    void slot_QKD_time(double a){emit sig_QKD_time(a);}
   /* void slot_QKD_timeB(double a){emit sig_QKD_timeB(a);}
    void slot_QKD_timeC(double a){emit sig_QKD_timeC(a);}
    void slot_QKD_timeD(double a){emit sig_QKD_timeD(a);}*/

    void slot_QKD_numb(int a){emit sig_QKD_numb(a);}
    /*void slot_QKD_numbB(int a){emit sig_QKD_numbB(a);}
    void slot_QKD_numbC(int a){emit sig_QKD_numbC(a);}
    void slot_QKD_numbD(int a){emit sig_QKD_numbD(a);}*/

    void slot_QKD_phA(int a){emit sig_QKD_phA(a);}
    void slot_QKD_phB(int a){emit sig_QKD_phB(a);}
    void slot_QKD_phC(int a){emit sig_QKD_phC(a);}
    void slot_QKD_phD(int a){emit sig_QKD_phD(a);}

    void slot_QKD_iwA(int a){emit sig_QKD_iwA(a);}
    void slot_QKD_iwB(int a){emit sig_QKD_iwB(a);}
    void slot_QKD_iwC(int a){emit sig_QKD_iwC(a);}
    void slot_QKD_iwD(int a){emit sig_QKD_iwD(a);}

    void slot_QKD_pxqA(int a){emit sig_QKD_pxqA(a);}
    void slot_QKD_pxqB(int a){emit sig_QKD_pxqB(a);}
    void slot_QKD_pxqC(int a){emit sig_QKD_pxqC(a);}
    void slot_QKD_pxqD(int a){emit sig_QKD_pxqD(a);}

    void slot_QKD_zeroA(int a){sig_QKD_zeroA(a);}
    void slot_QKD_zeroB(int a){sig_QKD_zeroB(a);}
    void slot_QKD_zeroC(int a){sig_QKD_zeroC(a);}
    void slot_QKD_zeroD(int a){sig_QKD_zeroD(a);}

    void in_savehdf5(){emit savehdf5();}
    void turnONDB(int a){emit sig_turnONDB(a);}

    void slot_PlotA_log(int a){emit sig_PlotA_log(a);}
    void slot_PlotB_log(int a){emit sig_PlotB_log(a);}
    void slot_PlotC_log(int a){emit sig_PlotC_log(a);}
    void slot_PlotD_log(int a){emit sig_PlotD_log(a);}
};

#endif // GUI_PARAM_H
