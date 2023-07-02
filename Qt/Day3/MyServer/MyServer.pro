#-------------------------------------------------
#
# Project created by QtCreator 2023-06-12T10:05:37
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CJsonObject.cpp \
    MsgBuilder.cpp \
    cJSON.c \
    userdao.cpp \
    server.cpp \
    socketthread.cpp

HEADERS  += mainwindow.h \
    cJSON.h \
    CJsonObject.hpp \
    MsgBuilder.h \
    userdao.h \
    server.h \
    socketthread.h

FORMS    += mainwindow.ui
