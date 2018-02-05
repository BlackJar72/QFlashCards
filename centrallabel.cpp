#include "centrallabel.h"

CentralLabel::CentralLabel(QWidget *parent) :
        QWidget(parent),
        label(new QLabel(this)),
        buttons(new ButtonPanel),
        layout(new QVBoxLayout) {

    QSizePolicy policy = label->sizePolicy();
    policy.setVerticalPolicy(QSizePolicy::Expanding);
    label->setSizePolicy(policy);
    layout->addWidget(label);
    layout->addWidget(buttons);
    setLayout(layout);
}



void CentralLabel::setText(QString text) {
    label->setText("<CENTER><H1><B>" + text + "</B></H1></CENTER>");
}
