QT += core
QT -= gui

CONFIG += c++11

TARGET = LeNexusBiendur
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rpggame.cpp \
    toolbox.cpp

HEADERS += \
    rpggame.h \
    toolbox.h
