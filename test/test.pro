QT       += widgets qml quick network testlib

TARGET = tst_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
