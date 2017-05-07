QT += core
QT -= gui

CONFIG += c++11
QMAKE_CXXFLAGS += -lSDL -lGL -O3

TARGET = LeNexusBiendur
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rpggame.cpp \
    toolbox.cpp \
    lodepng.cpp \
    randomgenerator.cpp \
    imggen.cpp

HEADERS += \
    rpggame.h \
    toolbox.h \
    lodepng.h \
    randomgenerator.h \
    imggen.h \
    pcg_uint128.hpp \
    pcg_random.hpp \
    pcg_extras.hpp
