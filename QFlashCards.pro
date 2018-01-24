#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T07:31:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = QFlashCards
TEMPLATE = app


SOURCES += main.cpp\
        qflashcards.cpp \
    inputcard.cpp \
    choicecard.cpp \
    reviewcard.cpp \
    createcard.cpp \
    studypanel.cpp \
    createpanel.cpp \
    choicebox.cpp \
    cardentry.cpp \
    cardgroup.cpp

HEADERS  += qflashcards.h \
    inputcard.h \
    choicecard.h \
    reviewcard.h \
    createcard.h \
    studypanel.h \
    createpanel.h \
    choicebox.h \
    cardentry.h \
    cardgroup.h

FORMS    += qflashcards.ui

RESOURCES += \
    assets.qrc
