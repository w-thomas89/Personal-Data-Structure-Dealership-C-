QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  ../app/customer.cpp \
            ../app/vehicle.cpp  \
            tst_testdealerhelper.cpp
