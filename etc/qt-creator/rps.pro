TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += ../../src/c/main.c

include(deployment.pri)
qtcAddDeployment()

