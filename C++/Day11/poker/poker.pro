TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pockermanager.cpp \
    poker.cpp \
    judge.cpp \
    player.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pockermanager.h \
    poker.h \
    judge.h \
    player.h

