TEMPLATE = subdirs

cMenu.depends = cCalculations
cTests.depends = cCalculations
cppMenu.depends = cppCalculations

SUBDIRS += \
    cMenu \
    cCalculations \
    cTests \
    cppMenu \
    cppCalculations \
    cppTests

