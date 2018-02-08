#ifndef CHOICEBOX_H
#define CHOICEBOX_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLabel>
#include <QGridLayout>
#inlucde <array>
#include <algorithm>
#include <random>
#include <chrono>

class ChoiceBox : public QWidget
{
    Q_OBJECT
	
public:
    explicit ChoiceBox(QWidget *parent = 0);
	void setData(const CardEntry* data);
	void showAnswer() const;

signals:

public slots:

private:
	QLabel* question;
    array<QRadioButton*, 4> choiceButtons; 
    QButtonGroup* grouping;
	array<QLabel*, 4> choiceLabels;
	QGridLayout* layout;
	int correctChoice;
};

#endif // CHOICEBOX_H
