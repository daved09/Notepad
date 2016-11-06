#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T19:18:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    options.cpp

HEADERS  += mainwindow.h \
    options.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
