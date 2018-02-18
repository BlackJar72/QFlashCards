#ifndef CHOICEBOX_H
#define CHOICEBOX_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLabel>
#include <QGridLayout>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
#include "cardentry.h"

class ChoiceBox : public QWidget
{
    Q_OBJECT
	
public:
    explicit ChoiceBox(QWidget *parent = 0);
    void setData(CardEntry* data);
	void showAnswer() const;

signals:

public slots:

private:
	QLabel* question;
    std::array<QRadioButton*, 4> choiceButtons;
    QButtonGroup* grouping;
    std::array<QLabel*, 4> choiceLabels;
	QGridLayout* layout;
    int correctChoice;
};

#endif // CHOICEBOX_H
