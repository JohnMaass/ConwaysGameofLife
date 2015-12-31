#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T16:57:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Conways_Game_Of_Life
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grid.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    grid.h \
    cell.h

FORMS    += mainwindow.ui
