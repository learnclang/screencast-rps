TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += ../../src/cpp/main.cpp \
    ../../src/cpp/rps.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../src/cpp/rps.hpp

