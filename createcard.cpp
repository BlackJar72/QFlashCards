#include "createcard.h"
#include "cardmanager.h"

#include <iostream>


CreateCard::CreateCard(QWidget *parent) : QWidget(parent)
{
    question = new QTextEdit(this);
    answer   = new QTextEdit(this);
    buttons  = new ButtonPanel(this);

    layout = new QVBoxLayout(this);
    layout->addWidget(question);
    layout->addWidget(answer);
    layout->addWidget(buttons);
    this->setLayout(layout);

    buttons->button1->hide();
    buttons->button2->hide();
    buttons->button3->hide();
    buttons->button4->setEffect("Save and &New" , 0);

    QObject::connect(buttons->button4, SIGNAL(clicked()),
                     this, SLOT(makeNewCard()));


    show();
}


void CreateCard::setData(CardEntry* data) {
    card = data;
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}


void CreateCard::updateCardData() {
    card->setData(question->toPlainText(), answer->toPlainText(), true, true);
    CardManager::getCardManager()->addCard(card);
}


void CreateCard::makeNewCard() {
    updateCardData();
    card = CardManager::getCardManager()->getNewCard();
    setData(card);
}

