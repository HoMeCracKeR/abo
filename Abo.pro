#-------------------------------------------------
#
# Project created by QtCreator 2014-03-05T21:18:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Abo
TEMPLATE = app


SOURCES += main.cpp\
        abo.cpp \
    dialog.cpp \
    sqllogin.cpp

HEADERS  += abo.h \
    dialog.h \
    sqllogin.h \
    exceptions.h

FORMS    += abo.ui \
    dialog.ui
