#include "createcard.h"

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

    QObject::connect(question, SIGNAL(textChanged()), this, SLOT(updateCardData()));
    QObject::connect(answer, SIGNAL(textChanged()), this, SLOT(updateCardData()));

    show();
}


void CreateCard::setData(CardEntry* data) {
    card = data;
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}


void CreateCard::updateCardData() {
    card->setData(question->toHtml(), answer->toHtml(), true, true);
}

