#include "editcard.h"
#include "cardmanager.h"

EditingCard::EditingCard(QWidget *parent) : QWidget(parent) {

    answer = new QTextEdit(this);
    question = new QTextEdit(this);
    buttons = new ButtonPanel(this);
    layout = new QVBoxLayout(this);

    layout->addWidget(question);
    layout->addWidget(answer);
    layout->addWidget(buttons);
    setLayout(layout);

    buttons->button1->setEffect(tr("&Back"), 0);
    buttons->button2->setEffect(tr("Delete"), 0);
    buttons->button3->setEffect(tr("&Save"), 0);
    buttons->button4->setEffect(tr("&Next"), 0);

    QObject::connect(buttons->button1, SIGNAL(clicked()),
                     this, SLOT(previousCard()));
    QObject::connect(buttons->button2, SIGNAL(clicked()),
                     this, SLOT(removeCard()));
    QObject::connect(buttons->button3, SIGNAL(clicked()),
                     this, SLOT(saveCard()));
    QObject::connect(buttons->button4, SIGNAL(clicked()),
                     this, SLOT(nextCard()));
}


void EditingCard::setData(CardEntry* data) {
    card = data;
    question->setText(data->getQuestion());
    answer->setText(data->getAnswer());
}


void EditingCard::previousCard() {
    card = CardManager::getCardManager()->getPreviousCard();
    setData(card);
}

void EditingCard::removeCard() {
    card = CardManager::getCardManager()->removeCurrent();
    setData(card);
}

void EditingCard::saveCard() {    
    card->setData(question->toPlainText(), answer->toPlainText());
}

void EditingCard::nextCard() {
    card = CardManager::getCardManager()->getNextCard();
    setData(card);
}

