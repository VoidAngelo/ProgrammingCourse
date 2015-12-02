TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    menu.c \
    menu_t1.c \
    menu_t2.c \
    menu_t3.c \
    menu_t4.c \
    menu_t5.c \
    main_cl.c

HEADERS += \
    main \
    main.h \
    menu_t1.h \
    menu_t2.h \
    menu_t3.h \
    menu_t4.h \
    menu_t5.h \
    main_cl.h





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
