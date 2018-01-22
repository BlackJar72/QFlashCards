#include "ReviewCard.h"

ReviewCard::ReviewCard(QWidget *parent = 0) :
    QWidget(parent),
    ui(new Ui::ReviewCard)
{
    ui->setupUi(this);
}

ReviewCard::~ReviewCard() {
    delete ui;
}


