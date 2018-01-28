#include "reviewcard.h"
#include <QVBoxLayout>
#include <iostream>

#include "cardentry.h"

ReviewCard::ReviewCard(QWidget *parent) : QWidget(parent)
{    
    question = new QLabel(this);
    answer  = new QLabel(this);
    buttons = new ButtonPanel(this);

    layout = new QVBoxLayout;
    layout->addWidget(question);
    layout->addWidget(answer);
    layout->addWidget(buttons);
    this->setLayout(layout);

    this->show();
}


void ReviewCard::setData(const CardEntry* data) {
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}
