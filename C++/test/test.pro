TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pocker.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pocker.h

