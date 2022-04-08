QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../app

SOURCES +=  ../app/customer.cpp \
            ../app/vehicle.cpp  \
            ../app/dealership.cpp \
            tst_testdealerhelper.cpp
