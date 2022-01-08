TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console

SOURCES += main.cpp \
    convert_func.cpp \
    encrytion_func.cpp

HEADERS += \
    tables.h \
    convertion_func.h \
    encrytion_func.h
