#include "qflashcards.h"
#include "ui_qflashcards.h"

QFlashCards::QFlashCards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFlashCards)
{
    ui->setupUi(this);
}

QFlashCards::~QFlashCards()
{
    delete ui;
}
