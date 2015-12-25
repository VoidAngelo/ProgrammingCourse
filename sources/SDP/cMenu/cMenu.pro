TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    c_main.c \
    c_main_cl.c \
    c_main_ui.c \
    c_keys_in_text_ui.c \
    c_reversed_num_ui.c \
    c_matrix_turn_ui.c \
    c_sum_of_digits_ui.c \
    c_multiples_ui.c

HEADERS += \
    main \
    c_main.h \
    c_main_cl.h \
    c_matrix_turn_ui.h \
    c_reversed_num_ui.h \
    c_sum_of_digits_ui.h \
    c_keys_in_text_ui.h \
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
