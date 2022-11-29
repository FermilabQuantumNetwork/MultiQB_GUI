

QT       += core gui multimedia sql widgets serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
DEFINES += LINUX linux
TARGET = PROGRAM
TEMPLATE = app
LIBS += -DLINUX -Dlinux -L$$PWD/../lib/ -lftd3xx -ltdcbase
PKGCONFIG += 
CONFIG += link_pkgconfig 


INCPATH +=




SOURCES += main.cpp\
           dbcontrol.cpp \
           gui_param.cpp \
           mainwindow.cpp \
           qcustomplot.cpp \
           qutag_adq.cpp \
           qutag_anl.cpp \
    ovdl.cpp
          

HEADERS  += mainwindow.h \
            dbcontrol.h \
            gui_param.h \
            qcustomplot.h \
            qutag_adq.h \
            qutag_anl.h \
            tdcbase.h \
            tdcdecl.h \
            tdcstartstop.h \
    ovdl.h
	   

FORMS    += mainwindow.ui \
    gui_param.ui


RESOURCES += \
    resources.qrc

DISTFILES +=


