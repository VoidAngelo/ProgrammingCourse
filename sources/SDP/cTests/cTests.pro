#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T23:24:21
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_cteststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_cteststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"





win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cCalculations/release/ -lcCalculations
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cCalculations/debug/ -lcCalculations
else:unix: LIBS += -L$$OUT_PWD/../cCalculations/ -lcCalculations

INCLUDEPATH += $$PWD/../cCalculations
DEPENDPATH += $$PWD/../cCalculations

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cCalculations/release/libcCalculations.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cCalculations/debug/libcCalculations.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cCalculations/release/cCalculations.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cCalculations/debug/cCalculations.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../cCalculations/libcCalculations.a
