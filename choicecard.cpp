#include "choicecard.h"

ChoiceCard::ChoiceCard(QWidget *parent) : QWidget(parent)
{
	question = new QLabel(this);
	grouping = new QButtonGroup(this);
	layout = new QGridLayout;
	layout->addItem(question, 0, 0, 2, 2);
	for(int i = 0; i < 4; i++) {
		// FIXME: Question? Are the buttons becoming children of 
		// grouping making assigning them to this pointless?
		choiceButtons[i] = new QRadionButton(this);
		grouping->add(choiceButtons[i], i);
		choiceLabels[i] = new QLabel(this);
		// Hiding these for now; if they get text they will 
		// then be shown.
		choiceButtons[i]->hide();
		choiceLabels[i]->hide();
		layout->addItem(choiceButtons[i], 0, 2 + i, 1, 1);
		layout->addItem(choiceLabels[i], 1, 2 + + i, 1, 1);
	}
	setLayout(layout);
	show();
}


void ChoiceCard::setData(const CardEntry* data) {
	question->setText(data->getQuestion());
	QList<CardEntry*>* distractorList 
		= CardManager::getCardManager()->getDataModel();
	distractorList->removeAll(data);	
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(distractorList->begin(), distractorList->end(),
             std::default_random_engine(seed));
	int i = distractorList->length();
	int j = 0;
	int k;
	if(i < 4) {
		k = i;
	} else {
		k = 4;
	}	
	correctChoice = rand() % k;
	// FIXME: This looks messy/overcomplicated and has unneeded logic
	while((i > -1) && (j < k)) {
		if(k == correctChoice) {
			choiceLables[j]->setText(data->getAnswer());
		} else {
			choiceLabels[j]->setText(distractorList->takeLast()->getAnswer());
		}
		choiceButtons[j]->show();
		choiceLabels[j]->show();
		k++;
	}
	delete distractorList;
}


void ChoiceCard::showAnswer() const {
	for(int i = 0; i < 4; i++ {
		if(i == correctChoice) {
			choiceButtons[i]->setDown(true);
		} else {
			choiceButtons[i]->hide();
			choiceLabels[i]->hide();
		}
	}
}
