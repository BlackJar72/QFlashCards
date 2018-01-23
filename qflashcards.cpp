#include "qflashcards.h"
#include "ui_qflashcards.h"

#include <iostream>

QFlashCards::QFlashCards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFlashCards)
{
    ui->setupUi(this);

    show();
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

void QFlashCards::on_actionReview_triggered()
{
    reviewCard = new ReviewCard(this);
    setCentralWidget(reviewCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionMultiple_Choice_triggered()
{
    multipleChoiceCard = new ChoiceCard(this);
    setCentralWidget(multipleChoiceCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionFree_Responce_triggered()
{
    freeResponceCard = new InputCard(this);
    setCentralWidget(freeResponceCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionNewCards_triggered()
{
    createNewCards = new CreateCard(this);
    setCentralWidget(createNewCards);
    centralWidget()->showNormal();
}
