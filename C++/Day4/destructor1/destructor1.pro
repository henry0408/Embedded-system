TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    student.h

