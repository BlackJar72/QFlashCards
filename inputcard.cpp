#include "inputcard.h"
#include "cardmanager.h"

#include <QDebug>

const QString correctText("Correct");
const QString wrongText("Wrong");


InputCard::InputCard(QWidget *parent) : QWidget(parent)
{
    question = new QLabel(this);
    answer   = new QTextEdit(this);
    buttons = new ButtonPanel(this);

    question->setText("Question");
    answer->setText("Answer");

    layout = new QVBoxLayout(this);
    layout->addWidget(question);
    layout->addWidget(answer);
    layout->addWidget(buttons);
    this->setLayout(layout);

    buttons->button1->hide();
    buttons->button2->hide();
    buttons->button3->setEffect("show", 0);
    buttons->button3->hide();
    buttons->button4->setEffect("Check", 0);

    connect(buttons->button3, SIGNAL(clicked()),
            this, SLOT(trButton3()));
    connect(buttons->button4, SIGNAL(clicked()),
            this, SLOT(trButton4()));

    show();
}


void InputCard::setData(const CardEntry* data) {
    question->setText(data->getQuestion());
    answer->setText("");
    correct = data->getAnswer();
}


void InputCard::checkAnswer() {
    if(correct == answer->toPlainText()) {
        emit writeToStatus(correctText);
        buttons->button4->setEffect("Next", 1);
    } else {
        emit writeToStatus(wrongText);
        buttons->button3->show();
    }
}


void InputCard::nextCard() {
    buttons->button4->setEffect("Check", 0);
    buttons->button3->hide();
    CardEntry* card = CardManager::getCardManager()->getCard();
    setData(card);
}


void InputCard::showAnswer() {
    answer->setText(correct);
}


void InputCard::trButton3() {
    showAnswer();
}


void InputCard::trButton4() {
    if(buttons->button4->getEffect()) {
        nextCard();
    } else {
        checkAnswer();
    }
}

