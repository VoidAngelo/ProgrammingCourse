#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T22:34:18
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_t0test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_t0test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Calculations/release/ -lCalculations
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Calculations/debug/ -lCalculations
else:unix: LIBS += -L$$OUT_PWD/../Calculations/ -lCalculations

INCLUDEPATH += $$PWD/../Calculations
DEPENDPATH += $$PWD/../Calculations

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Calculations/release/libCalculations.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Calculations/debug/libCalculations.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Calculations/release/Calculations.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Calculations/debug/Calculations.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Calculations/libCalculations.a
