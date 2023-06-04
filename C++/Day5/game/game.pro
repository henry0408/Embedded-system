TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    computer.cpp \
    people.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    computer.h \
    people.h

