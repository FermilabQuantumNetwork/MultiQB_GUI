/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <./qcustomplot.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_state;
    QAction *actionLoad_state;
    QAction *actionQKD;
    QAction *action7;
    QAction *actioninit_Qutag;
    QAction *actioninit_TTU;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *horizontalTabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QFrame *generalconfwid;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QWidget *ee;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_2;
    QSpinBox *histStart;
    QLabel *label_70;
    QSpinBox *binWidth;
    QWidget *rr;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QSpinBox *binsinplot;
    QLabel *label_111;
    QHBoxLayout *horizontalLayout_32;
    QLCDNumber *HistoEndDisplay;
    QLabel *label_112;
    QWidget *ww;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *adqtime;
    QSpacerItem *verticalSpacer_14;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_18;
    QWidget *plotAwid;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *PlotA;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_6;
    QFormLayout *trackFL_A;
    QLabel *label_17;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_9;
    QWidget *plotBwid;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *PlotB;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_12;
    QFormLayout *trackFL_B;
    QLabel *label_54;
    QLabel *label_55;
    QSpacerItem *verticalSpacer_8;
    QWidget *plotCwid_2;
    QHBoxLayout *horizontalLayout_28;
    QCustomPlot *PlotC;
    QVBoxLayout *verticalLayout_38;
    QVBoxLayout *verticalLayout_37;
    QLabel *label_87;
    QFormLayout *trackFL_C;
    QLabel *label_85;
    QLabel *label_86;
    QSpacerItem *verticalSpacer_6;
    QWidget *plotDwid;
    QHBoxLayout *horizontalLayout_6;
    QCustomPlot *PlotD;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_39;
    QLabel *label_160;
    QFormLayout *trackFL_D;
    QLabel *label_161;
    QLabel *label_162;
    QSpacerItem *verticalSpacer_7;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_3;
    QWidget *tab2W;
    QHBoxLayout *horizontalLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QPushButton *saveLogic;
    QPushButton *loadLogic;
    QPushButton *AddLogic;
    QPushButton *RemoveLogic;
    QPushButton *clean_tab2;
    QFormLayout *formLayout_3;
    QLabel *label_22;
    QDoubleSpinBox *adqtime_2;
    QLabel *label_21;
    QSpinBox *tab2_xrange;
    QLabel *label_3;
    QSlider *TSON;
    QLabel *label_7;
    QSpinBox *TSper;
    QFormLayout *formLayout_5;
    QLabel *label_77;
    QSlider *DBON;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *LogicSelector;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_15;
    QCustomPlot *PlotTab2;
    QVBoxLayout *verticalLayout_19;
    QCustomPlot *PlotTrack;
    QVBoxLayout *verticalLayout_17;
    QWidget *conf;
    QHBoxLayout *horizontalLayout_26;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_25;
    QFormLayout *Parameters_left;
    QFormLayout *parameters_R;
    QWidget *tab4;
    QVBoxLayout *verticalLayout_20;
    QWidget *verticalWidget;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_7;
    QLabel *label_103;
    QSlider *homscan;
    QLabel *label_104;
    QDoubleSpinBox *homscan_timed;
    QLabel *label_108;
    QSpinBox *stepduration;
    QLabel *label_106;
    QDoubleSpinBox *Max_delayd;
    QLabel *label_105;
    QLCDNumber *current_delay_pos;
    QLabel *label_9;
    QDoubleSpinBox *VDL_start;
    QPushButton *connect_OVDL;
    QPushButton *reset_delay;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuconfig_n;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1500, 1200);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSave_state = new QAction(MainWindow);
        actionSave_state->setObjectName("actionSave_state");
        actionLoad_state = new QAction(MainWindow);
        actionLoad_state->setObjectName("actionLoad_state");
        actionQKD = new QAction(MainWindow);
        actionQKD->setObjectName("actionQKD");
        action7 = new QAction(MainWindow);
        action7->setObjectName("action7");
        actioninit_Qutag = new QAction(MainWindow);
        actioninit_Qutag->setObjectName("actioninit_Qutag");
        actioninit_TTU = new QAction(MainWindow);
        actioninit_TTU->setObjectName("actioninit_TTU");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalTabWidget = new QTabWidget(centralWidget);
        horizontalTabWidget->setObjectName("horizontalTabWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalTabWidget->sizePolicy().hasHeightForWidth());
        horizontalTabWidget->setSizePolicy(sizePolicy1);
        tab1 = new QWidget();
        tab1->setObjectName("tab1");
        verticalLayout_2 = new QVBoxLayout(tab1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(tab1);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        generalconfwid = new QFrame(widget);
        generalconfwid->setObjectName("generalconfwid");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(generalconfwid->sizePolicy().hasHeightForWidth());
        generalconfwid->setSizePolicy(sizePolicy2);
        generalconfwid->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_4 = new QHBoxLayout(generalconfwid);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(9, 0, -1, 0);
        label_8 = new QLabel(generalconfwid);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        QPalette palette;
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0, 0, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(80, 80, 80, 255));
        gradient.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        QLinearGradient gradient1(0, 0, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(80, 80, 80, 255));
        gradient1.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush6(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QLinearGradient gradient2(0, 0, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(80, 80, 80, 255));
        gradient2.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush7(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0, 0, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(80, 80, 80, 255));
        gradient3.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush10(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        QLinearGradient gradient4(0, 0, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(80, 80, 80, 255));
        gradient4.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush11(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        QLinearGradient gradient5(0, 0, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(80, 80, 80, 255));
        gradient5.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush12(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        QLinearGradient gradient6(0, 0, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(80, 80, 80, 255));
        gradient6.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush14(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        QLinearGradient gradient7(0, 0, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(80, 80, 80, 255));
        gradient7.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush15(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        QLinearGradient gradient8(0, 0, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(80, 80, 80, 255));
        gradient8.setColorAt(1, QColor(50, 50, 50, 255));
        QBrush brush16(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
        QBrush brush17(QColor(0, 0, 0, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush17);
#endif
        label_8->setPalette(palette);
        label_8->setTextFormat(Qt::RichText);
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/logo15.png")));
        label_8->setScaledContents(true);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_8->setWordWrap(false);
        label_8->setMargin(0);
        label_8->setIndent(-1);

        horizontalLayout_4->addWidget(label_8);

        ee = new QWidget(generalconfwid);
        ee->setObjectName("ee");
        verticalLayout_8 = new QVBoxLayout(ee);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(-1, 0, -1, 0);
        label_2 = new QLabel(ee);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_8->addWidget(label_2);

        histStart = new QSpinBox(ee);
        histStart->setObjectName("histStart");
        histStart->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        histStart->setMinimum(1);
        histStart->setMaximum(11000000);
        histStart->setSingleStep(10);
        histStart->setValue(2);

        verticalLayout_8->addWidget(histStart);

        label_70 = new QLabel(ee);
        label_70->setObjectName("label_70");
        label_70->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_8->addWidget(label_70);

        binWidth = new QSpinBox(ee);
        binWidth->setObjectName("binWidth");
        binWidth->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        binWidth->setMinimum(1);
        binWidth->setMaximum(1000000);
        binWidth->setValue(800);

        verticalLayout_8->addWidget(binWidth);


        horizontalLayout_4->addWidget(ee);

        rr = new QWidget(generalconfwid);
        rr->setObjectName("rr");
        verticalLayout_9 = new QVBoxLayout(rr);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(-1, 0, -1, 0);
        label_4 = new QLabel(rr);
        label_4->setObjectName("label_4");
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_9->addWidget(label_4);

        binsinplot = new QSpinBox(rr);
        binsinplot->setObjectName("binsinplot");
        binsinplot->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        binsinplot->setMinimum(2);
        binsinplot->setMaximum(1000000);

        verticalLayout_9->addWidget(binsinplot);

        label_111 = new QLabel(rr);
        label_111->setObjectName("label_111");
        label_111->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_9->addWidget(label_111);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        HistoEndDisplay = new QLCDNumber(rr);
        HistoEndDisplay->setObjectName("HistoEndDisplay");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HistoEndDisplay->sizePolicy().hasHeightForWidth());
        HistoEndDisplay->setSizePolicy(sizePolicy4);
        HistoEndDisplay->setDigitCount(7);

        horizontalLayout_32->addWidget(HistoEndDisplay);

        label_112 = new QLabel(rr);
        label_112->setObjectName("label_112");
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_112->sizePolicy().hasHeightForWidth());
        label_112->setSizePolicy(sizePolicy5);
        label_112->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_32->addWidget(label_112);


        verticalLayout_9->addLayout(horizontalLayout_32);


        horizontalLayout_4->addWidget(rr);

        ww = new QWidget(generalconfwid);
        ww->setObjectName("ww");
        verticalLayout_7 = new QVBoxLayout(ww);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(-1, 0, -1, 0);
        label_5 = new QLabel(ww);
        label_5->setObjectName("label_5");
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_7->addWidget(label_5);

        adqtime = new QDoubleSpinBox(ww);
        adqtime->setObjectName("adqtime");
        adqtime->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        adqtime->setMinimum(0.100000000000000);
        adqtime->setMaximum(1000.000000000000000);
        adqtime->setSingleStep(1.000000000000000);

        verticalLayout_7->addWidget(adqtime);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_14);


        horizontalLayout_4->addWidget(ww);


        verticalLayout_4->addWidget(generalconfwid);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1476, 1019));
        verticalLayout_18 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_18->setSpacing(4);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        plotAwid = new QWidget(scrollAreaWidgetContents);
        plotAwid->setObjectName("plotAwid");
        plotAwid->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_2 = new QHBoxLayout(plotAwid);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        PlotA = new QCustomPlot(plotAwid);
        PlotA->setObjectName("PlotA");
        sizePolicy.setHeightForWidth(PlotA->sizePolicy().hasHeightForWidth());
        PlotA->setSizePolicy(sizePolicy);
        PlotA->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_10 = new QVBoxLayout(PlotA);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName("verticalLayout_10");

        horizontalLayout_2->addWidget(PlotA);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_6 = new QLabel(plotAwid);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_13->addWidget(label_6);

        trackFL_A = new QFormLayout();
        trackFL_A->setSpacing(6);
        trackFL_A->setObjectName("trackFL_A");
        label_17 = new QLabel(plotAwid);
        label_17->setObjectName("label_17");
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_A->setWidget(0, QFormLayout::LabelRole, label_17);

        label_20 = new QLabel(plotAwid);
        label_20->setObjectName("label_20");
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_A->setWidget(0, QFormLayout::FieldRole, label_20);


        verticalLayout_13->addLayout(trackFL_A);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_9);


        horizontalLayout_2->addLayout(verticalLayout_13);


        verticalLayout_18->addWidget(plotAwid);

        plotBwid = new QWidget(scrollAreaWidgetContents);
        plotBwid->setObjectName("plotBwid");
        plotBwid->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_5 = new QHBoxLayout(plotBwid);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        PlotB = new QCustomPlot(plotBwid);
        PlotB->setObjectName("PlotB");
        sizePolicy.setHeightForWidth(PlotB->sizePolicy().hasHeightForWidth());
        PlotB->setSizePolicy(sizePolicy);
        verticalLayout_11 = new QVBoxLayout(PlotB);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName("verticalLayout_11");

        horizontalLayout_5->addWidget(PlotB);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_12 = new QLabel(plotBwid);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_14->addWidget(label_12);

        trackFL_B = new QFormLayout();
        trackFL_B->setSpacing(6);
        trackFL_B->setObjectName("trackFL_B");
        label_54 = new QLabel(plotBwid);
        label_54->setObjectName("label_54");
        label_54->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_B->setWidget(0, QFormLayout::LabelRole, label_54);

        label_55 = new QLabel(plotBwid);
        label_55->setObjectName("label_55");
        label_55->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_B->setWidget(0, QFormLayout::FieldRole, label_55);


        verticalLayout_14->addLayout(trackFL_B);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_8);


        horizontalLayout_5->addLayout(verticalLayout_14);


        verticalLayout_18->addWidget(plotBwid);

        plotCwid_2 = new QWidget(scrollAreaWidgetContents);
        plotCwid_2->setObjectName("plotCwid_2");
        horizontalLayout_28 = new QHBoxLayout(plotCwid_2);
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        horizontalLayout_28->setContentsMargins(0, 0, 0, 0);
        PlotC = new QCustomPlot(plotCwid_2);
        PlotC->setObjectName("PlotC");
        sizePolicy.setHeightForWidth(PlotC->sizePolicy().hasHeightForWidth());
        PlotC->setSizePolicy(sizePolicy);
        verticalLayout_38 = new QVBoxLayout(PlotC);
        verticalLayout_38->setSpacing(6);
        verticalLayout_38->setContentsMargins(11, 11, 11, 11);
        verticalLayout_38->setObjectName("verticalLayout_38");

        horizontalLayout_28->addWidget(PlotC);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setObjectName("verticalLayout_37");
        label_87 = new QLabel(plotCwid_2);
        label_87->setObjectName("label_87");
        label_87->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_37->addWidget(label_87);

        trackFL_C = new QFormLayout();
        trackFL_C->setSpacing(6);
        trackFL_C->setObjectName("trackFL_C");
        label_85 = new QLabel(plotCwid_2);
        label_85->setObjectName("label_85");
        label_85->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_C->setWidget(0, QFormLayout::LabelRole, label_85);

        label_86 = new QLabel(plotCwid_2);
        label_86->setObjectName("label_86");
        label_86->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_C->setWidget(0, QFormLayout::FieldRole, label_86);


        verticalLayout_37->addLayout(trackFL_C);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_37->addItem(verticalSpacer_6);


        horizontalLayout_28->addLayout(verticalLayout_37);


        verticalLayout_18->addWidget(plotCwid_2);

        plotDwid = new QWidget(scrollAreaWidgetContents);
        plotDwid->setObjectName("plotDwid");
        horizontalLayout_6 = new QHBoxLayout(plotDwid);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        PlotD = new QCustomPlot(plotDwid);
        PlotD->setObjectName("PlotD");
        sizePolicy.setHeightForWidth(PlotD->sizePolicy().hasHeightForWidth());
        PlotD->setSizePolicy(sizePolicy);
        verticalLayout_12 = new QVBoxLayout(PlotD);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName("verticalLayout_12");

        horizontalLayout_6->addWidget(PlotD);

        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setSpacing(6);
        verticalLayout_39->setObjectName("verticalLayout_39");
        label_160 = new QLabel(plotDwid);
        label_160->setObjectName("label_160");
        label_160->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_39->addWidget(label_160);

        trackFL_D = new QFormLayout();
        trackFL_D->setSpacing(6);
        trackFL_D->setObjectName("trackFL_D");
        label_161 = new QLabel(plotDwid);
        label_161->setObjectName("label_161");
        label_161->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_D->setWidget(0, QFormLayout::LabelRole, label_161);

        label_162 = new QLabel(plotDwid);
        label_162->setObjectName("label_162");
        label_162->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        trackFL_D->setWidget(0, QFormLayout::FieldRole, label_162);


        verticalLayout_39->addLayout(trackFL_D);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_39->addItem(verticalSpacer_7);


        horizontalLayout_6->addLayout(verticalLayout_39);


        verticalLayout_18->addWidget(plotDwid);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout_2->addWidget(widget);

        horizontalTabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName("tab2");
        verticalLayout_3 = new QVBoxLayout(tab2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tab2W = new QWidget(tab2);
        tab2W->setObjectName("tab2W");
        tab2W->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout = new QHBoxLayout(tab2W);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalWidget = new QWidget(tab2W);
        horizontalWidget->setObjectName("horizontalWidget");
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy6);
        horizontalLayout_27 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName("formLayout_2");
        saveLogic = new QPushButton(horizontalWidget);
        saveLogic->setObjectName("saveLogic");
        saveLogic->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, saveLogic);

        loadLogic = new QPushButton(horizontalWidget);
        loadLogic->setObjectName("loadLogic");
        loadLogic->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, loadLogic);


        verticalLayout_5->addLayout(formLayout_2);

        AddLogic = new QPushButton(horizontalWidget);
        AddLogic->setObjectName("AddLogic");
        AddLogic->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_5->addWidget(AddLogic);

        RemoveLogic = new QPushButton(horizontalWidget);
        RemoveLogic->setObjectName("RemoveLogic");
        RemoveLogic->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_5->addWidget(RemoveLogic);

        clean_tab2 = new QPushButton(horizontalWidget);
        clean_tab2->setObjectName("clean_tab2");
        clean_tab2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_5->addWidget(clean_tab2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(-1, 15, -1, 9);
        label_22 = new QLabel(horizontalWidget);
        label_22->setObjectName("label_22");
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_22);

        adqtime_2 = new QDoubleSpinBox(horizontalWidget);
        adqtime_2->setObjectName("adqtime_2");
        adqtime_2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        adqtime_2->setMinimum(1.000000000000000);
        adqtime_2->setMaximum(6000.000000000000000);
        adqtime_2->setValue(1.000000000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, adqtime_2);

        label_21 = new QLabel(horizontalWidget);
        label_21->setObjectName("label_21");
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_21);

        tab2_xrange = new QSpinBox(horizontalWidget);
        tab2_xrange->setObjectName("tab2_xrange");
        tab2_xrange->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        tab2_xrange->setMinimum(1);
        tab2_xrange->setMaximum(10000);
        tab2_xrange->setSingleStep(5);
        tab2_xrange->setValue(125);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, tab2_xrange);

        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_3);

        TSON = new QSlider(horizontalWidget);
        TSON->setObjectName("TSON");
        TSON->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, TSON);

        label_7 = new QLabel(horizontalWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        TSper = new QSpinBox(horizontalWidget);
        TSper->setObjectName("TSper");
        TSper->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        TSper->setMinimum(1);
        TSper->setMaximum(100);
        TSper->setSingleStep(10);
        TSper->setValue(10);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, TSper);


        verticalLayout_5->addLayout(formLayout_3);

        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setHorizontalSpacing(17);
        formLayout_5->setVerticalSpacing(1);
        formLayout_5->setContentsMargins(2, 12, 0, -1);
        label_77 = new QLabel(horizontalWidget);
        label_77->setObjectName("label_77");
        label_77->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_77);

        DBON = new QSlider(horizontalWidget);
        DBON->setObjectName("DBON");
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(DBON->sizePolicy().hasHeightForWidth());
        DBON->setSizePolicy(sizePolicy7);
        DBON->setMaximum(1);
        DBON->setOrientation(Qt::Horizontal);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, DBON);


        verticalLayout_5->addLayout(formLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_27->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(25, -1, 0, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        LogicSelector = new QVBoxLayout();
        LogicSelector->setSpacing(6);
        LogicSelector->setObjectName("LogicSelector");

        horizontalLayout_3->addLayout(LogicSelector);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_27->addLayout(verticalLayout_6);


        horizontalLayout->addWidget(horizontalWidget);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName("verticalLayout_15");
        PlotTab2 = new QCustomPlot(tab2W);
        PlotTab2->setObjectName("PlotTab2");
        verticalLayout_19 = new QVBoxLayout(PlotTab2);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName("verticalLayout_19");

        verticalLayout_15->addWidget(PlotTab2);

        PlotTrack = new QCustomPlot(tab2W);
        PlotTrack->setObjectName("PlotTrack");
        verticalLayout_17 = new QVBoxLayout(PlotTrack);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName("verticalLayout_17");

        verticalLayout_15->addWidget(PlotTrack);


        horizontalLayout->addLayout(verticalLayout_15);


        verticalLayout_3->addWidget(tab2W);

        horizontalTabWidget->addTab(tab2, QString());
        conf = new QWidget();
        conf->setObjectName("conf");
        horizontalLayout_26 = new QHBoxLayout(conf);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        horizontalWidget1 = new QWidget(conf);
        horizontalWidget1->setObjectName("horizontalWidget1");
        horizontalWidget1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_25 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        Parameters_left = new QFormLayout();
        Parameters_left->setSpacing(6);
        Parameters_left->setObjectName("Parameters_left");

        horizontalLayout_25->addLayout(Parameters_left);

        parameters_R = new QFormLayout();
        parameters_R->setSpacing(6);
        parameters_R->setObjectName("parameters_R");

        horizontalLayout_25->addLayout(parameters_R);


        horizontalLayout_26->addWidget(horizontalWidget1);

        horizontalTabWidget->addTab(conf, QString());
        tab4 = new QWidget();
        tab4->setObjectName("tab4");
        verticalLayout_20 = new QVBoxLayout(tab4);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName("verticalLayout_20");
        verticalWidget = new QWidget(tab4);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_7 = new QHBoxLayout(verticalWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        formLayout_7 = new QFormLayout();
        formLayout_7->setSpacing(6);
        formLayout_7->setObjectName("formLayout_7");
        formLayout_7->setContentsMargins(-1, 20, -1, -1);
        label_103 = new QLabel(verticalWidget);
        label_103->setObjectName("label_103");
        label_103->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_103);

        homscan = new QSlider(verticalWidget);
        homscan->setObjectName("homscan");
        sizePolicy7.setHeightForWidth(homscan->sizePolicy().hasHeightForWidth());
        homscan->setSizePolicy(sizePolicy7);
        homscan->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        homscan->setMinimum(0);
        homscan->setMaximum(1);
        homscan->setValue(0);
        homscan->setOrientation(Qt::Horizontal);

        formLayout_7->setWidget(1, QFormLayout::FieldRole, homscan);

        label_104 = new QLabel(verticalWidget);
        label_104->setObjectName("label_104");
        label_104->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_104);

        homscan_timed = new QDoubleSpinBox(verticalWidget);
        homscan_timed->setObjectName("homscan_timed");
        homscan_timed->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        homscan_timed->setDecimals(3);
        homscan_timed->setMinimum(0.001000000000000);
        homscan_timed->setMaximum(560.000000000000000);

        formLayout_7->setWidget(2, QFormLayout::FieldRole, homscan_timed);

        label_108 = new QLabel(verticalWidget);
        label_108->setObjectName("label_108");
        label_108->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_108);

        stepduration = new QSpinBox(verticalWidget);
        stepduration->setObjectName("stepduration");
        stepduration->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        stepduration->setMinimum(1);
        stepduration->setMaximum(50000);

        formLayout_7->setWidget(3, QFormLayout::FieldRole, stepduration);

        label_106 = new QLabel(verticalWidget);
        label_106->setObjectName("label_106");
        label_106->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(5, QFormLayout::LabelRole, label_106);

        Max_delayd = new QDoubleSpinBox(verticalWidget);
        Max_delayd->setObjectName("Max_delayd");
        Max_delayd->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        Max_delayd->setDecimals(3);
        Max_delayd->setMinimum(1.000000000000000);
        Max_delayd->setMaximum(560.000000000000000);

        formLayout_7->setWidget(5, QFormLayout::FieldRole, Max_delayd);

        label_105 = new QLabel(verticalWidget);
        label_105->setObjectName("label_105");
        label_105->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(6, QFormLayout::LabelRole, label_105);

        current_delay_pos = new QLCDNumber(verticalWidget);
        current_delay_pos->setObjectName("current_delay_pos");
        current_delay_pos->setDigitCount(4);

        formLayout_7->setWidget(6, QFormLayout::FieldRole, current_delay_pos);

        label_9 = new QLabel(verticalWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_9);

        VDL_start = new QDoubleSpinBox(verticalWidget);
        VDL_start->setObjectName("VDL_start");
        VDL_start->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        VDL_start->setDecimals(3);
        VDL_start->setMaximum(560.000000000000000);

        formLayout_7->setWidget(4, QFormLayout::FieldRole, VDL_start);

        connect_OVDL = new QPushButton(verticalWidget);
        connect_OVDL->setObjectName("connect_OVDL");
        connect_OVDL->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, connect_OVDL);

        reset_delay = new QPushButton(verticalWidget);
        reset_delay->setObjectName("reset_delay");
        reset_delay->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, reset_delay);


        horizontalLayout_7->addLayout(formLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_20->addWidget(verticalWidget);

        horizontalTabWidget->addTab(tab4, QString());

        verticalLayout->addWidget(horizontalTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1500, 22));
        QFont font;
        font.setPointSize(11);
        menuBar->setFont(font);
        menuconfig_n = new QMenu(menuBar);
        menuconfig_n->setObjectName("menuconfig_n");
        menuconfig_n->setFont(font);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuconfig_n->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuconfig_n->addSeparator();
        menuconfig_n->addAction(actioninit_Qutag);
        menuconfig_n->addSeparator();
        menuconfig_n->addAction(actioninit_TTU);
        menuconfig_n->addSeparator();
        menuconfig_n->addAction(actionLoad_state);
        menuconfig_n->addAction(actionSave_state);
        menuEdit->addAction(actionQKD);

        retranslateUi(MainWindow);

        horizontalTabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QCustomPlot plot examples", nullptr));
        actionSave_state->setText(QCoreApplication::translate("MainWindow", "Save state", nullptr));
        actionLoad_state->setText(QCoreApplication::translate("MainWindow", "Load state", nullptr));
        actionQKD->setText(QCoreApplication::translate("MainWindow", "Lines", nullptr));
        action7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        actioninit_Qutag->setText(QCoreApplication::translate("MainWindow", "init Qutag", nullptr));
        actioninit_TTU->setText(QCoreApplication::translate("MainWindow", "init TTU", nullptr));
        label_8->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Histogram DisplayStart", nullptr));
        histStart->setSuffix(QCoreApplication::translate("MainWindow", "  [ps]", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "Bin Width", nullptr));
        binWidth->setSuffix(QCoreApplication::translate("MainWindow", " [ps]", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "# bins in plot", nullptr));
        label_111->setText(QCoreApplication::translate("MainWindow", "Histogram End", nullptr));
        label_112->setText(QCoreApplication::translate("MainWindow", "[ps]", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "update rate / Adq time", nullptr));
        adqtime->setSuffix(QCoreApplication::translate("MainWindow", " [s]", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Plot A", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Counts", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Plot B", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "Counts", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "Plot C", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "Counts", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        label_160->setText(QCoreApplication::translate("MainWindow", "Plot D", nullptr));
        label_161->setText(QCoreApplication::translate("MainWindow", "Counts", nullptr));
        label_162->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        horizontalTabWidget->setTabText(horizontalTabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "Histograms", nullptr));
        saveLogic->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadLogic->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        AddLogic->setText(QCoreApplication::translate("MainWindow", "Add Logic Element", nullptr));
        RemoveLogic->setText(QCoreApplication::translate("MainWindow", "Remove Logic Element", nullptr));
        clean_tab2->setText(QCoreApplication::translate("MainWindow", "Clean Plot", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Adquisition time", nullptr));
        adqtime_2->setSuffix(QCoreApplication::translate("MainWindow", " [s]", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "X axis range", nullptr));
        tab2_xrange->setSuffix(QCoreApplication::translate("MainWindow", " [s]", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TS Anlalysis", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Data %", nullptr));
        TSper->setSuffix(QCoreApplication::translate("MainWindow", " [%]", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "Record Data", nullptr));
        horizontalTabWidget->setTabText(horizontalTabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "AND gates", nullptr));
        horizontalTabWidget->setTabText(horizontalTabWidget->indexOf(conf), QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        label_103->setText(QCoreApplication::translate("MainWindow", "Scan mode", nullptr));
        label_104->setText(QCoreApplication::translate("MainWindow", "Scan step Size", nullptr));
        homscan_timed->setSuffix(QCoreApplication::translate("MainWindow", " [ps]", nullptr));
        label_108->setText(QCoreApplication::translate("MainWindow", "Step duration", nullptr));
        stepduration->setSuffix(QCoreApplication::translate("MainWindow", " [ps]", nullptr));
        label_106->setText(QCoreApplication::translate("MainWindow", "Max Delay", nullptr));
        Max_delayd->setSuffix(QCoreApplication::translate("MainWindow", " [ps]", nullptr));
        label_105->setText(QCoreApplication::translate("MainWindow", "Current pos.", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Start delay", nullptr));
        VDL_start->setSuffix(QCoreApplication::translate("MainWindow", " [ps]", nullptr));
        connect_OVDL->setText(QCoreApplication::translate("MainWindow", "OVDL connect", nullptr));
        reset_delay->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        horizontalTabWidget->setTabText(horizontalTabWidget->indexOf(tab4), QCoreApplication::translate("MainWindow", "OVDL", nullptr));
        menuconfig_n->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
