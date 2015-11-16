#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T15:03:41
#
#-------------------------------------------------

QT       += core

QT += sql

QT       -= gui

TARGET = ContactorsUpdate
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ChinesePinyinTable.cpp \
    DatabaseTable.cpp \
    CContactorsTable.cpp

HEADERS += \
    ChinesePinyinTable.h \
    DatabaseTable.h \
    CContatorsTable.h
