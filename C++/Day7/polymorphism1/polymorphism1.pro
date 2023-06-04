TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    developer.cpp \
    manito.cpp \
    smallbird.cpp \
    company.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    developer.h \
    manito.h \
    smallbird.h \
    company.h

