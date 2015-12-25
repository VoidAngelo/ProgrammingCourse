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
    KeysInText.cpp \
    MatrixTurn.cpp \
    UnlimitedInt.cpp \
    SumOfDigits.cpp \
    ReversedNum.cpp \
    Multiples.cpp

HEADERS += \
    UnlimitedInt.h \
    MatrixTurn.h \
    Multiples.h \
    ReversedNum.h \
    SumOfDigits.h \
    Exceptions.h \
    KeysInText.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
