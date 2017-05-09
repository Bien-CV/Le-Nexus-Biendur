QT += core
QT -= gui

CONFIG += c++14
QMAKE_CXXFLAGS += -Wall -O3

release:LIBS +=
debug:LIBS +=

TARGET = LeNexusBiendur
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rpggame.cpp \
    toolbox.cpp \
    lodepng.cpp \
    randomgenerator.cpp \
    imggen.cpp \
    color.cpp \
    image.cpp

HEADERS += \
    rpggame.h \
    toolbox.h \
    lodepng.h \
    randomgenerator.h \
    imggen.h \
    color.h \
    image.h
