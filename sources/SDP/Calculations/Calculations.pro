#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T20:13:41
#
#-------------------------------------------------

QT       -= core gui

TARGET = Calculations
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    t1.c \
    t2.c \
    t3.c \
    t4.c \
    t5.c

HEADERS += \
    t1.h \
    t2.h \
    t3.h \
    t4.h \
    t5.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
