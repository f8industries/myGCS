#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T16:08:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = myGCS
TEMPLATE = app


SOURCES += main.cpp\
    mainwidget.cpp \
    mapview.cpp \
    videoview.cpp \
    lightmaps.cpp \
    slippymap.cpp

HEADERS  += \
    mainwidget.h \
    mapview.h \
    videoview.h \
    lightmaps.h \
    slippymap.h

FORMS    +=
