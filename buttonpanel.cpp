#include "buttonpanel.h"

ButtonPanel::ButtonPanel(QWidget *parent) :
        QWidget(parent),
        button1(new MutableButton),
        button2(new MutableButton),
        button3(new MutableButton),
        button4(new MutableButton),
        layout(new QHBoxLayout(this)) {
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    setLayout(layout);
    show();
}

