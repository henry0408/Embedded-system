TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circle.cpp \
    table.cpp \
    roundtable.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    circle.h \
    table.h \
    roundtable.h

