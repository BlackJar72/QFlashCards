/********************************************************************************
** Form generated from reading UI file 'qflashcards.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFLASHCARDS_H
#define UI_QFLASHCARDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFlashCards
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionReview;
    QAction *actionFree_Responce;
    QAction *actionNewCards;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionEdit_Cards;
    QAction *actionLicense;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuUse;
    QMenu *menuCreate;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QFlashCards)
    {
        if (QFlashCards->objectName().isEmpty())
            QFlashCards->setObjectName(QStringLiteral("QFlashCards"));
        QFlashCards->resize(400, 300);
        actionSave = new QAction(QFlashCards);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(QFlashCards);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionReview = new QAction(QFlashCards);
        actionReview->setObjectName(QStringLiteral("actionReview"));
        actionFree_Responce = new QAction(QFlashCards);
        actionFree_Responce->setObjectName(QStringLiteral("actionFree_Responce"));
        actionNewCards = new QAction(QFlashCards);
        actionNewCards->setObjectName(QStringLiteral("actionNewCards"));
        actionHelp = new QAction(QFlashCards);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon);
        actionAbout = new QAction(QFlashCards);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionNew = new QAction(QFlashCards);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/IndexCard32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionLoad = new QAction(QFlashCards);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionEdit_Cards = new QAction(QFlashCards);
        actionEdit_Cards->setObjectName(QStringLiteral("actionEdit_Cards"));
        actionLicense = new QAction(QFlashCards);
        actionLicense->setObjectName(QStringLiteral("actionLicense"));
        centralWidget = new QWidget(QFlashCards);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFlashCards->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QFlashCards);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuUse = new QMenu(menuBar);
        menuUse->setObjectName(QStringLiteral("menuUse"));
        menuCreate = new QMenu(menuBar);
        menuCreate->setObjectName(QStringLiteral("menuCreate"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QFlashCards->setMenuBar(menuBar);
        statusBar = new QStatusBar(QFlashCards);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFlashCards->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuUse->menuAction());
        menuBar->addAction(menuCreate->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuUse->addAction(actionReview);
        menuUse->addSeparator();
        menuUse->addAction(actionFree_Responce);
        menuCreate->addAction(actionNewCards);
        menuCreate->addAction(actionEdit_Cards);
        menuHelp->addSeparator();
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionLicense);
        menuHelp->addAction(actionAbout);

        retranslateUi(QFlashCards);

        QMetaObject::connectSlotsByName(QFlashCards);
    } // setupUi

    void retranslateUi(QMainWindow *QFlashCards)
    {
        QFlashCards->setWindowTitle(QApplication::translate("QFlashCards", "QFlashCards", nullptr));
        actionSave->setText(QApplication::translate("QFlashCards", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("QFlashCards", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("QFlashCards", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("QFlashCards", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionReview->setText(QApplication::translate("QFlashCards", "Review", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReview->setShortcut(QApplication::translate("QFlashCards", "Ctrl+Shift+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionFree_Responce->setText(QApplication::translate("QFlashCards", "Quiz", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFree_Responce->setShortcut(QApplication::translate("QFlashCards", "Ctrl+Shift+Return", nullptr));
#endif // QT_NO_SHORTCUT
        actionNewCards->setText(QApplication::translate("QFlashCards", "New Cards", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNewCards->setShortcut(QApplication::translate("QFlashCards", "Ctrl+Shift+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("QFlashCards", "Help", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("QFlashCards", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("QFlashCards", "About", nullptr));
        actionNew->setText(QApplication::translate("QFlashCards", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("QFlashCards", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad->setText(QApplication::translate("QFlashCards", "Load", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad->setShortcut(QApplication::translate("QFlashCards", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionEdit_Cards->setText(QApplication::translate("QFlashCards", "Edit Cards", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEdit_Cards->setShortcut(QApplication::translate("QFlashCards", "Ctrl+Shift+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionLicense->setText(QApplication::translate("QFlashCards", "License", nullptr));
        menuFile->setTitle(QApplication::translate("QFlashCards", "File", nullptr));
        menuUse->setTitle(QApplication::translate("QFlashCards", "Use", nullptr));
        menuCreate->setTitle(QApplication::translate("QFlashCards", "Create", nullptr));
        menuHelp->setTitle(QApplication::translate("QFlashCards", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFlashCards: public Ui_QFlashCards {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFLASHCARDS_H
