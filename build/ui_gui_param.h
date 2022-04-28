/********************************************************************************
** Form generated from reading UI file 'gui_param.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_PARAM_H
#define UI_GUI_PARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_param
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *QKD_phA;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *QKD_iwA;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *QKD_pxqA;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *QKD_zeroA;
    QHBoxLayout *horizontalLayout_21;
    QCheckBox *PlotA_log;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_15;
    QSpinBox *QKD_phB;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QSpinBox *QKD_iwB;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QSpinBox *QKD_pxqB;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSpinBox *QKD_zeroB;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *PlotB_log;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QSpinBox *QKD_phC;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QSpinBox *QKD_iwC;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QSpinBox *QKD_pxqC;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QSpinBox *QKD_zeroC;
    QHBoxLayout *horizontalLayout_23;
    QCheckBox *PlotC_log;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_22;
    QSpinBox *QKD_phD;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_23;
    QSpinBox *QKD_iwD;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_24;
    QSpinBox *QKD_pxqD;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_25;
    QSpinBox *QKD_zeroD;
    QHBoxLayout *horizontalLayout_30;
    QCheckBox *PlotD_log;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *QKD_numb;
    QDoubleSpinBox *QKD_time;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_19;
    QSlider *QKD_DB;
    QPushButton *hdf5;

    void setupUi(QWidget *GUI_param)
    {
        if (GUI_param->objectName().isEmpty())
            GUI_param->setObjectName(QString::fromUtf8("GUI_param"));
        GUI_param->resize(1162, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUI_param->sizePolicy().hasHeightForWidth());
        GUI_param->setSizePolicy(sizePolicy);
        GUI_param->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(80, 80, 80, 255), stop:1 rgba(50, 50, 50, 255));"));
        horizontalLayout_7 = new QHBoxLayout(GUI_param);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(GUI_param);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_3);

        QKD_phA = new QSpinBox(GUI_param);
        QKD_phA->setObjectName(QString::fromUtf8("QKD_phA"));
        QKD_phA->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_phA->setMinimum(1);
        QKD_phA->setMaximum(10000);
        QKD_phA->setSingleStep(100);

        horizontalLayout_3->addWidget(QKD_phA);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(GUI_param);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_4);

        QKD_iwA = new QSpinBox(GUI_param);
        QKD_iwA->setObjectName(QString::fromUtf8("QKD_iwA"));
        QKD_iwA->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_iwA->setMinimum(1);
        QKD_iwA->setMaximum(10000);
        QKD_iwA->setSingleStep(100);

        horizontalLayout_4->addWidget(QKD_iwA);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(GUI_param);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(label_5);

        QKD_pxqA = new QSpinBox(GUI_param);
        QKD_pxqA->setObjectName(QString::fromUtf8("QKD_pxqA"));
        QKD_pxqA->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_pxqA->setMinimum(1);
        QKD_pxqA->setMaximum(7);

        horizontalLayout_5->addWidget(QKD_pxqA);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(GUI_param);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(label_6);

        QKD_zeroA = new QSpinBox(GUI_param);
        QKD_zeroA->setObjectName(QString::fromUtf8("QKD_zeroA"));
        QKD_zeroA->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_zeroA->setMaximum(100000);
        QKD_zeroA->setSingleStep(10);

        horizontalLayout_6->addWidget(QKD_zeroA);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        PlotA_log = new QCheckBox(GUI_param);
        PlotA_log->setObjectName(QString::fromUtf8("PlotA_log"));
        PlotA_log->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_21->addWidget(PlotA_log);


        verticalLayout->addLayout(horizontalLayout_21);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_15 = new QLabel(GUI_param);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_16->addWidget(label_15);

        QKD_phB = new QSpinBox(GUI_param);
        QKD_phB->setObjectName(QString::fromUtf8("QKD_phB"));
        QKD_phB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_phB->setMinimum(1);
        QKD_phB->setMaximum(10000);
        QKD_phB->setSingleStep(100);

        horizontalLayout_16->addWidget(QKD_phB);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_13 = new QLabel(GUI_param);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_14->addWidget(label_13);

        QKD_iwB = new QSpinBox(GUI_param);
        QKD_iwB->setObjectName(QString::fromUtf8("QKD_iwB"));
        QKD_iwB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_iwB->setMinimum(1);
        QKD_iwB->setMaximum(10000);
        QKD_iwB->setSingleStep(100);

        horizontalLayout_14->addWidget(QKD_iwB);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(GUI_param);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_12->addWidget(label_11);

        QKD_pxqB = new QSpinBox(GUI_param);
        QKD_pxqB->setObjectName(QString::fromUtf8("QKD_pxqB"));
        QKD_pxqB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_pxqB->setMinimum(1);
        QKD_pxqB->setMaximum(7);

        horizontalLayout_12->addWidget(QKD_pxqB);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(GUI_param);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(label_8);

        QKD_zeroB = new QSpinBox(GUI_param);
        QKD_zeroB->setObjectName(QString::fromUtf8("QKD_zeroB"));
        QKD_zeroB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_zeroB->setMaximum(100000);
        QKD_zeroB->setSingleStep(10);

        horizontalLayout_9->addWidget(QKD_zeroB);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        PlotB_log = new QCheckBox(GUI_param);
        PlotB_log->setObjectName(QString::fromUtf8("PlotB_log"));
        PlotB_log->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_22->addWidget(PlotB_log);


        verticalLayout_2->addLayout(horizontalLayout_22);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_16 = new QLabel(GUI_param);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_17->addWidget(label_16);

        QKD_phC = new QSpinBox(GUI_param);
        QKD_phC->setObjectName(QString::fromUtf8("QKD_phC"));
        QKD_phC->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_phC->setMaximum(10000);
        QKD_phC->setSingleStep(100);

        horizontalLayout_17->addWidget(QKD_phC);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(GUI_param);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(label_14);

        QKD_iwC = new QSpinBox(GUI_param);
        QKD_iwC->setObjectName(QString::fromUtf8("QKD_iwC"));
        QKD_iwC->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_iwC->setMinimum(1);
        QKD_iwC->setMaximum(10000);
        QKD_iwC->setSingleStep(100);

        horizontalLayout_15->addWidget(QKD_iwC);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(GUI_param);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_13->addWidget(label_12);

        QKD_pxqC = new QSpinBox(GUI_param);
        QKD_pxqC->setObjectName(QString::fromUtf8("QKD_pxqC"));
        QKD_pxqC->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_pxqC->setMinimum(1);
        QKD_pxqC->setMaximum(7);

        horizontalLayout_13->addWidget(QKD_pxqC);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(GUI_param);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_11->addWidget(label_10);

        QKD_zeroC = new QSpinBox(GUI_param);
        QKD_zeroC->setObjectName(QString::fromUtf8("QKD_zeroC"));
        QKD_zeroC->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_zeroC->setMaximum(100000);
        QKD_zeroC->setSingleStep(10);

        horizontalLayout_11->addWidget(QKD_zeroC);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        PlotC_log = new QCheckBox(GUI_param);
        PlotC_log->setObjectName(QString::fromUtf8("PlotC_log"));
        PlotC_log->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_23->addWidget(PlotC_log);


        verticalLayout_3->addLayout(horizontalLayout_23);


        horizontalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_22 = new QLabel(GUI_param);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_26->addWidget(label_22);

        QKD_phD = new QSpinBox(GUI_param);
        QKD_phD->setObjectName(QString::fromUtf8("QKD_phD"));
        QKD_phD->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_phD->setMinimum(1);
        QKD_phD->setMaximum(10000);
        QKD_phD->setSingleStep(100);

        horizontalLayout_26->addWidget(QKD_phD);


        verticalLayout_5->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_23 = new QLabel(GUI_param);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_27->addWidget(label_23);

        QKD_iwD = new QSpinBox(GUI_param);
        QKD_iwD->setObjectName(QString::fromUtf8("QKD_iwD"));
        QKD_iwD->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_iwD->setMinimum(1);
        QKD_iwD->setMaximum(10000);
        QKD_iwD->setSingleStep(100);

        horizontalLayout_27->addWidget(QKD_iwD);


        verticalLayout_5->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_24 = new QLabel(GUI_param);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_28->addWidget(label_24);

        QKD_pxqD = new QSpinBox(GUI_param);
        QKD_pxqD->setObjectName(QString::fromUtf8("QKD_pxqD"));
        QKD_pxqD->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_pxqD->setMinimum(1);
        QKD_pxqD->setMaximum(7);

        horizontalLayout_28->addWidget(QKD_pxqD);


        verticalLayout_5->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_25 = new QLabel(GUI_param);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_29->addWidget(label_25);

        QKD_zeroD = new QSpinBox(GUI_param);
        QKD_zeroD->setObjectName(QString::fromUtf8("QKD_zeroD"));
        QKD_zeroD->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_zeroD->setMaximum(100000);
        QKD_zeroD->setSingleStep(10);

        horizontalLayout_29->addWidget(QKD_zeroD);


        verticalLayout_5->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        PlotD_log = new QCheckBox(GUI_param);
        PlotD_log->setObjectName(QString::fromUtf8("PlotD_log"));
        PlotD_log->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_30->addWidget(PlotD_log);


        verticalLayout_5->addLayout(horizontalLayout_30);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(GUI_param);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(GUI_param);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        QKD_numb = new QSpinBox(GUI_param);
        QKD_numb->setObjectName(QString::fromUtf8("QKD_numb"));
        QKD_numb->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QKD_numb->setMinimum(1);
        QKD_numb->setMaximum(500);

        formLayout->setWidget(1, QFormLayout::FieldRole, QKD_numb);

        QKD_time = new QDoubleSpinBox(GUI_param);
        QKD_time->setObjectName(QString::fromUtf8("QKD_time"));
        QKD_time->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        QKD_time->setDecimals(3);
        QKD_time->setMaximum(120000.000000000000000);
        QKD_time->setSingleStep(100.000000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, QKD_time);


        verticalLayout_4->addLayout(formLayout);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_19 = new QLabel(GUI_param);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_20->addWidget(label_19);

        QKD_DB = new QSlider(GUI_param);
        QKD_DB->setObjectName(QString::fromUtf8("QKD_DB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QKD_DB->sizePolicy().hasHeightForWidth());
        QKD_DB->setSizePolicy(sizePolicy1);
        QKD_DB->setMinimumSize(QSize(76, 0));
        QKD_DB->setMaximum(1);
        QKD_DB->setOrientation(Qt::Horizontal);

        horizontalLayout_20->addWidget(QKD_DB);


        verticalLayout_4->addLayout(horizontalLayout_20);

        hdf5 = new QPushButton(GUI_param);
        hdf5->setObjectName(QString::fromUtf8("hdf5"));
        hdf5->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        verticalLayout_4->addWidget(hdf5);


        horizontalLayout_7->addLayout(verticalLayout_4);


        retranslateUi(GUI_param);

        QMetaObject::connectSlotsByName(GUI_param);
    } // setupUi

    void retranslateUi(QWidget *GUI_param)
    {
        GUI_param->setWindowTitle(QApplication::translate("GUI_param", "Windows Parameters", nullptr));
        label_3->setText(QApplication::translate("GUI_param", "Phase time A", nullptr));
        QKD_phA->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_4->setText(QApplication::translate("GUI_param", "Integration Win A", nullptr));
        QKD_iwA->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_5->setText(QApplication::translate("GUI_param", "Peaks x Qubit A", nullptr));
        label_6->setText(QApplication::translate("GUI_param", "Offset A", nullptr));
        PlotA_log->setText(QApplication::translate("GUI_param", "Plot A log scale", nullptr));
        label_15->setText(QApplication::translate("GUI_param", "Phase time B", nullptr));
        QKD_phB->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_13->setText(QApplication::translate("GUI_param", "Integration Win B", nullptr));
        QKD_iwB->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_11->setText(QApplication::translate("GUI_param", "Peaks x Qubit B", nullptr));
        label_8->setText(QApplication::translate("GUI_param", "Offset B", nullptr));
        PlotB_log->setText(QApplication::translate("GUI_param", "Plot B log scale", nullptr));
        label_16->setText(QApplication::translate("GUI_param", "Phase time C", nullptr));
        QKD_phC->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_14->setText(QApplication::translate("GUI_param", "Integration Win B", nullptr));
        QKD_iwC->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_12->setText(QApplication::translate("GUI_param", "Peaks x Qubit C", nullptr));
        label_10->setText(QApplication::translate("GUI_param", "Offset C", nullptr));
        PlotC_log->setText(QApplication::translate("GUI_param", "Plot C log scale", nullptr));
        label_22->setText(QApplication::translate("GUI_param", "Phase time D", nullptr));
        QKD_phD->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_23->setText(QApplication::translate("GUI_param", "Integration Win D", nullptr));
        QKD_iwD->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_24->setText(QApplication::translate("GUI_param", "Peaks x Qubit D", nullptr));
        label_25->setText(QApplication::translate("GUI_param", "Offset D", nullptr));
        PlotD_log->setText(QApplication::translate("GUI_param", "Plot D log scale", nullptr));
        label->setText(QApplication::translate("GUI_param", "Qubit time", nullptr));
        label_2->setText(QApplication::translate("GUI_param", "# qubits ", nullptr));
        QKD_time->setSuffix(QApplication::translate("GUI_param", " [ps]", nullptr));
        label_19->setText(QApplication::translate("GUI_param", "Save data", nullptr));
        hdf5->setText(QApplication::translate("GUI_param", "HDF5 hist save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI_param: public Ui_GUI_param {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_PARAM_H
