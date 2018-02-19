#include "mutablebutton.h"

MutableButton::MutableButton(QWidget *parent) : QPushButton(parent) {
    QSizePolicy keepSpace = sizePolicy();
    keepSpace.setRetainSizeWhenHidden(true);
    setSizePolicy(keepSpace);
}


void MutableButton::setEffect(char* text, unsigned int effect) {
    setText(text);
    effectState = effect;
}


void MutableButton::setEffect(QString text, unsigned int effect) {
    setText(text);
    effectState = effect;

}


unsigned int MutableButton::getEffect() const {
    return effectState;
}
