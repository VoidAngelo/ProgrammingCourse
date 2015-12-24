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
    c_matrix_turn.c \
    c_reversed_num.c \
    c_sum_of_digits.c \
    c_keys_in_text.c \
    c_multiples.c

HEADERS += \
    c_matrix_turn.h \
    c_reversed_num.h \
    c_sum_of_digits.h \
    c_keys_in_text.h \
    c_multiples.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
