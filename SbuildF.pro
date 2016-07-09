#-------------------------------------------------
#
# Project created by QtCreator 2016-07-09T11:26:56
#
#-------------------------------------------------

QT       += core gui
QT      +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SbuildF
TEMPLATE = app


SOURCES += main.cpp\
    hafdisplay.cpp \
    historydisplay.cpp \
    minheap.cpp \
    privatescreen.cpp \
    startscreen.cpp

HEADERS  += \
    hafdisplay.h \
    historydisplay.h \
    minheap.h \
    msgtype.h \
    privatescreen.h \
    startscreen.h

FORMS    += \
    hafdisplay.ui \
    historydisplay.ui \
    privatescreen.ui \
    startscreen.ui
