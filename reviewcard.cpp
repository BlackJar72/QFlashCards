#include "reviewcard.h"
#include <QVBoxLayout>
#include <iostream>

ReviewCard::ReviewCard(QWidget *parent) : QWidget(parent)
{    
    question = new QLabel(this);
    answer  = new QLabel(this);

    question->setText("Question");
    answer->setText("Answer");

    layout = new QVBoxLayout;
    layout->addWidget(question);
    layout->addWidget(answer);
    this->setLayout(layout);

    this->show();
}

