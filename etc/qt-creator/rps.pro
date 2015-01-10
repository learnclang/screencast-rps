TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += ../../src/c/main.c \
    ../../src/c/rps.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../src/c/rps.h

