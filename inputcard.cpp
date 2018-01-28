#include "inputcard.h"

InputCard::InputCard(QWidget *parent) : QWidget(parent)
{
    question = new QLabel(this);
    answer   = new QTextEdit(this);

    question->setText("Question");
    answer->setText("Answer");

    layout = new QVBoxLayout(this);
    layout->addWidget(question);
    layout->addWidget(answer);
    this->setLayout(layout);

    show();
}


void InputCard::setData(const CardEntry* data) {
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}

