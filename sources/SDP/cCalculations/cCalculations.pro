#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T23:11:16
#
#-------------------------------------------------

QT       -= core gui

TARGET = cCalculations
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    c_matrix.c \
    c_reversion.c \
    c_text.c \
    c_multiples.c \
    c_sum.c

HEADERS += \
    c_reversion.h \
    c_text.h \
    c_sum.h \
    c_matrix.h \
    c_multiples.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
