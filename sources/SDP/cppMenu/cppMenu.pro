TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    UnlimitedIntDemo.cpp \
    main.cpp

HEADERS += \
    UnlimitedIntDemo.h



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
