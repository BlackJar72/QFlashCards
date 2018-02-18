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

QT += widgets

RC_ICONS = IndexCards32.ico
RC_FILE = QFlashCards.rc

SOURCES += main.cpp\
        qflashcards.cpp \
    inputcard.cpp \
    reviewcard.cpp \
    createcard.cpp \
    cardentry.cpp \
    cardgroup.cpp \
    cardmanager.cpp \
    buttonpanel.cpp \
    mutablebutton.cpp \
    editcard.cpp \
    centrallabel.cpp \
    filehandler.cpp

HEADERS  += qflashcards.h \
    inputcard.h \
    reviewcard.h \
    createcard.h \
    cardentry.h \
    cardgroup.h \
    cardmanager.h \
    buttonpanel.h \
    mutablebutton.h \
    editcard.h \
    centrallabel.h \
    enumcardtype.h \
    filehandler.h

FORMS    += qflashcards.ui

RESOURCES += \
    assets.qrc


LIBS += /home/jared/Libraries/cpp/src/MyLibraries/ArrayContainers/bin/Release/libArrayContainers.a
INCLUDEPATH += /home/jared/Libraries/cpp/src/MyLibraries/ArrayContainers/

