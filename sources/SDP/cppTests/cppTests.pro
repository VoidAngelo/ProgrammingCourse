#-------------------------------------------------
#
# Project created by QtCreator 2015-12-23T19:26:57
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_cppteststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_cppteststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cppCalculations/release/ -lcppCalculations
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cppCalculations/debug/ -lcppCalculations
else:unix: LIBS += -L$$OUT_PWD/../cppCalculations/ -lcppCalculations

INCLUDEPATH += $$PWD/../cppCalculations
DEPENDPATH += $$PWD/../cppCalculations

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cppCalculations/release/libcppCalculations.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cppCalculations/debug/libcppCalculations.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cppCalculations/release/cppCalculations.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cppCalculations/debug/cppCalculations.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../cppCalculations/libcppCalculations.a
