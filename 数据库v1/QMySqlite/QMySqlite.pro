#-------------------------------------------------
#
# Project created by QtCreator 2017-07-06T15:51:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMySqlite
TEMPLATE = app


SOURCES += main.cpp \
    overweight.cpp \
    overweightimpl.cpp \
    caridmanagement.cpp \
    caridmanagementimpl.cpp \
    artidmanagement.cpp \
    artidmanagementimpl.cpp \
    weightrecords.cpp \
    weightrecordsimpl.cpp

HEADERS  += \
    overweight.h \
    overweightimpl.h \
    caridmanagement.h \
    caridmanagementimpl.h \
    artidmanagement.h \
    artidmanagementimpl.h \
    weightrecords.h \
    weightrecordsimpl.h
