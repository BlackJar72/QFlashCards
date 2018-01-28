#include "reviewcard.h"
#include <QVBoxLayout>
#include <iostream>

#include "cardentry.h"

ReviewCard::ReviewCard(QWidget *parent) : QWidget(parent)
{    
    question = new QLabel(this);
    answer  = new QLabel(this);

    layout = new QVBoxLayout;
    layout->addWidget(question);
    layout->addWidget(answer);
    this->setLayout(layout);

    this->show();
}


void ReviewCard::setData(const CardEntry* data) {
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}
