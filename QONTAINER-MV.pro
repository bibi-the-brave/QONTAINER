#-------------------------------------------------
#
# Project created by QtCreator 2019-05-05T19:42:14
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
CONFIG += warn_off
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    data.cpp \
    delegatebottone.cpp \
    delegateeliminazione.cpp \
    delegatemodifica.cpp \
    dialogatleta.cpp \
    dialogciclismo.cpp \
    dialogallenamento.cpp \
    dialogcorsa.cpp \
    dialognuoto.cpp \
    dialogtriathlon.cpp \
    gestorefile.cpp \
        main.cpp \
    finestraprincipale.cpp \
    modeltabellaallenamenti.cpp \
    modeltabellaatleti.cpp \
    allenamento.cpp \
    nuoto.cpp \
    corsa.cpp \
    ciclismo.cpp \
    sortfilterproxymodelallenamenti.cpp \
    triathlon.cpp \
    persona.cpp \
    widgetallenamenti.cpp \
    widgetatleti.cpp \
    widgetciclismo.cpp \
    widgetcorsa.cpp \
    widgetintroduttivo.cpp \
    widgetnuoto.cpp \
    widgetnuovosport.cpp \
    widgetricerca.cpp

HEADERS += \
    contenitore.h \
    data.h \
    delegatebottone.h \
    delegateeliminazione.h \
    delegatemodifica.h \
    dialogatleta.h \
    dialogciclismo.h \
    dialogallenamento.h \
    dialogcorsa.h \
    dialognuoto.h \
    dialogtriathlon.h \
    errori.h \
    finestraprincipale.h \
    gestorefile.h \
    modeltabellaallenamenti.h \
    modeltabellaatleti.h \
    allenamento.h \
    nuoto.h \
    corsa.h \
    ciclismo.h \
    sortfilterproxymodelallenamenti.h \
    triathlon.h \
    persona.h \
    deepptr.h \
    widgetallenamenti.h \
    widgetatleti.h \
    widgetciclismo.h \
    widgetcorsa.h \
    widgetintroduttivo.h \
    widgetnuoto.h \
    widgetnuovosport.h \
    widgetricerca.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone.qrc
