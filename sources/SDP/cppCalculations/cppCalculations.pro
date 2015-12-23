#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T15:35:13
#
#-------------------------------------------------

QT       -= gui

TARGET = cppCalculations
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    cpp_int_unlim.cpp \
    cpp_sum_of_digits.cpp \
    cpp_reversed_num.cpp \
    cpp_multiples.cpp \
    cpp_keys_in_text.cpp \
    cpp_matrix_turn.cpp

HEADERS += \
    cpp_int_unlim.h \
    cpp_sum_of_digits.h \
    cpp_reversed_num.h \
    cpp_multiples.h \
    cpp_keys_in_text.h \
    cpp_matrix_turn.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
