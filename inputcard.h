#ifndef INPUTCARD_H
#define INPUTCARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>

#include "cardentry.h"
#include "buttonpanel.h"
#include "enumcardtype.h"

class InputCard : public QWidget
{
    Q_OBJECT
	
public:
    explicit InputCard(QWidget *parent = 0);
    void setData(const CardEntry* data);

signals:
    void writeToStatus(MessageType msg, CardType identity);

public slots:
    void trButton3();
    void trButton4();

private:
    QLabel* question;
    QTextEdit* answer;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
    QString correct;
    void checkAnswer();
    void nextCard();
    void showAnswer();
};

#endif // INPUTCARD_H
