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

    connect(buttons->button3, SIGNAL(clicked()),
            this, SLOT(trButton3()));
    connect(buttons->button4, SIGNAL(clicked()),
            this, SLOT(trButton4()));
}


/**
 * Sets what text will be displayed.
 */
void CentralLabel::setText(QString text) {
    label->setText("<CENTER><H1><B>" + text + "</B></H1></CENTER>");
}


/**
 * A convenience function, this will will set the text for 
 * a correct response.
 */
void CentralLabel::setCorrect() {
    setText("Correct!");
    setButton(buttons->button4, "Next", MessageType::CORRECT);
    buttons->button3->hide();
}


/**
 * A convenience function, this will will set the text for 
 * an incorrect response.
 */
void CentralLabel::setWrong() {
    setText("Wrong!");
    setButton(buttons->button4, "Try Again", MessageType::WRONG);
    setButton(buttons->button3, "Show Answer", MessageType::WRONG);
}


/**
 * Sets properties for one the buttons in its buttons.
 */
void CentralLabel::setButton(MutableButton* button, char* text, int value) {
    button->setEffect(tr(text), value);
    button->show();
}


/**
 * Sets what kind of cards it will be.
 */
void CentralLabel::setCardType(CardType caller) {
    stimulus = caller;
}


/**
 * Sets the message for either a correct of incorrect 
 * responce based on enum data.
 */
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


void CentralLabel::trButton3() {
    emit signalShowAnswer(stimulus);
}


void CentralLabel::trButton4() {
    switch(buttons->button4->getEffect()) {
        case MessageType::CORRECT:
            emit signalNextCard(stimulus);
            break;
        case MessageType::WRONG:
            emit signalTryAgain((stimulus));
            break;
        default:
            break;
    }
}
