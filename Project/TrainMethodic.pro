#-------------------------------------------------
#
# Project created by QtCreator 2016-07-15T19:58:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainMethodic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addmethodicwidget.cpp \
    powerunit.cpp \
    power.cpp \
    trainday.cpp \
    databasemanager.cpp \
    execisewidget.cpp \
    viewmethodicwidget.cpp \
    viewdaywidget.cpp \
    selectdatewidget.cpp

HEADERS  += mainwindow.h \
    addmethodicwidget.h \
    powerunit.h \
    power.h \
    trainday.h \
    databasemanager.h \
    execisewidget.h \
    viewmethodicwidget.h \
    viewdaywidget.h \
    selectdatewidget.h

FORMS    += mainwindow.ui \
    addmethodicwidget.ui \
    powerunit.ui \
    power.ui \
    trainday.ui \
    execisewidget.ui \
    viewmethodicwidget.ui \
    viewdaywidget.ui \
    selectdatewidget.ui
