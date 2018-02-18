#include "choicebox.h"
#include <QHBoxLayout>

ChoiceBox::ChoiceBox(QWidget *parent) : 
			QWidget(parent), 
            choices(new QRadioButton[4]),
            labels(new QLabel[4]),
			grouping(new QButtonGroup) {
	QHBoxLayout l2;
	for(int i = 0; i < 4; i++) {
		
	}
}

