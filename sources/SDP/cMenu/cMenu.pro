TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    c_main.c \
    c_main_cl.c \
    c_matrix_ui.c \
    c_main_ui.c \
    c_text_ui.c \
    c_reversion_ui.c \
    c_sum_ui.c \
    c_multiples_ui.c

HEADERS += \
    main \
    c_main.h \
    c_main_cl.h \
    c_sum_ui.h \
    c_text_ui.h \
    c_matrix_ui.h \
    c_reversion_ui.h \
    c_multiples_ui.h


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
