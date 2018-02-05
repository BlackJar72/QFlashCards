#include "centrallabel.h"

CentralLabel::CentralLabel(QWidget *parent) :
        QWidget(parent),
        label(new QLabel(this)),
        buttons(new ButtonPanel),
        layout(new QVBoxLayout),
        stimulus(CardType::NONE) {

    QSizePolicy policy = label->sizePolicy();
    policy.setVerticalPolicy(QSizePolicy::Expanding);
    buttons->button1->hide();
    buttons->button2->hide();
    buttons->button3->hide();
    buttons->button4->hide();
    label->setSizePolicy(policy);
    layout->addWidget(label);
    layout->addWidget(buttons);
    setLayout(layout);
}



void CentralLabel::setText(QString text) {
    label->setText("<CENTER><H1><B>" + text + "</B></H1></CENTER>");
}


void CentralLabel::setCorrect() {
    setText("Correct!");
    setButton(buttons->button4, "Next", 0);
    buttons->button3->hide();
}


void CentralLabel::setWrong() {
    setText("Wrong!");
    setButton(buttons->button4, "Try Again", 1);
    setButton(buttons->button3, "Show Answer", 1);
}


void CentralLabel::setButton(MutableButton* button, char* text, int value) {
    button->setEffect(text, value);
    button->show();
}


void CentralLabel::setCardType(CardType caller) {
    stimulus = caller;
}


void CentralLabel::setMessage(MessageType msg) {
    switch (msg) {
    case MessageType::CORRECT:
        setCorrect();
        break;
    case MessageType::WRONG:
        setWrong();
        break;
    default:
        break;
    }
}
