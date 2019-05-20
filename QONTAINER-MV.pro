#-------------------------------------------------
#
# Project created by QtCreator 2018-12-05T19:42:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QONTAINER-MV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
        main.cpp \
    finestraprincipale.cpp \ 
    allenamento.cpp \
    nuoto.cpp \
    palestra.cpp \
    corsa.cpp \
    ciclismo.cpp \
    calcio.cpp \
    pallavolo.cpp \
    triathlon.cpp \
    persona.cpp \
    menuview.cpp \
    finestrasceltasport.cpp \
    inserimentosportview.cpp

HEADERS += \
    contenitore.h \
    errori.h \
    finestraprincipale.h \ 
    allenamento.h \
    nuoto.h \
    palestra.h \
    corsa.h \
    ciclismo.h \
    calcio.h \
    pallavolo.h \
    triathlon.h \
    persona.h \
    deepptr.h \
    menuview.h \
    finestrasceltasport.h \
    inserimentosportview.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone.qrc
