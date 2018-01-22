#include "qflashcards.h"
#include "ui_qflashcards.h"
#include "inputcard.h"

QFlashCards::QFlashCards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFlashCards)
{
    ui->setupUi(this);
    this->setCentralWidget(new InputCard(this));
    this->centralWidget()->showMaximized();
}

QFlashCards::~QFlashCards()
{
    delete ui;
}

/**
 * @brief QFlashCards::on_actionExit_triggered
 *
 * Well, exit the application when the exit menu is selected
 */
void QFlashCards::on_actionExit_triggered()
{
    exit(0);
}
