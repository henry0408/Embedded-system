#-------------------------------------------------
#
# Project created by QtCreator 2023-06-09T14:09:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatroom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CJsonObject.cpp \
    cJSON.c \
    logindialog.cpp \
    registdialog.cpp \
    mysocket.cpp \
    MsgBuilder.cpp

HEADERS  += mainwindow.h \
    cJSON.h \
    CJsonObject.hpp \
    logindialog.h \
    registdialog.h \
    mysocket.h \
    MsgBuilder.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registdialog.ui
