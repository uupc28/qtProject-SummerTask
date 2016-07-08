#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T10:14:23
#
#-------------------------------------------------

QT       += core gui
QT         += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = buildF
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    chatprivate.cpp \
    server.cpp \
    client.cpp \
    compile.cpp \
    startscreen.cpp \
    privatescreen.cpp \
    tcpserver.cpp \
    minheap.cpp \
    hafdisplay.cpp \
    historydisplay.cpp

HEADERS  += widget.h \
    chatprivate.h \
    server.h \
    client.h \
    compile.h \
    startscreen.h \
    privatescreen.h \
    tcpserver.h \
    minheap.h \
    hafdisplay.h \
    historydisplay.h

FORMS    += widget.ui \
    chatprivate.ui \
    compile.ui \
    startscreen.ui \
    privatescreen.ui \
    hafdisplay.ui \
    historydisplay.ui
