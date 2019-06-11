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
    delegateeliminazione.cpp \
    dialogcreazioneallenamento.cpp \
    dialoginserimentoatleta.cpp \
        main.cpp \
    finestraprincipale.cpp \
    modeltabellaallenamenti.cpp \
    modeltabellaatleti.cpp \
    allenamento.cpp \
    nuoto.cpp \
    corsa.cpp \
    ciclismo.cpp \
    triathlon.cpp \
    persona.cpp \
    menuview.cpp \
    widgetallenamenti.cpp \
    widgetatleti.cpp \
    widgetnuovosport.cpp \
    widgetricerca.cpp

HEADERS += \
    contenitore.h \
    delegateeliminazione.h \
    dialogcreazioneallenamento.h \
    dialoginserimentoatleta.h \
    errori.h \
    finestraprincipale.h \
    modeltabellaallenamenti.h \
    modeltabellaatleti.h \
    allenamento.h \
    nuoto.h \
    corsa.h \
    ciclismo.h \
    triathlon.h \
    persona.h \
    deepptr.h \
    menuview.h \
    widgetallenamenti.h \
    widgetatleti.h \
    widgetnuovosport.h \
    widgetricerca.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone.qrc
