#ifndef CENTRALLABEL_H
#define CENTRALLABEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "buttonpanel.h"
#include "enumcardtype.h"

/**
 * A message giving widget which is used to give large 
 * messages to the user as the central widget.  This is 
 * used to give feedback to answers in quiz mode.
 */
class CentralLabel : public QWidget
{
    Q_OBJECT

public:
    explicit CentralLabel(QWidget *parent = 0);
    void setText(QString text);
    void setCorrect();
    void setWrong();
    void setCardType(CardType caller);
    void setMessage(MessageType msg);

signals:
    void signalNextCard(CardType card);
    void signalTryAgain(CardType card);
    void signalShowAnswer(CardType card);

public slots:
    void trButton3();
    void trButton4();

private:
    QLabel* label;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
    CardType stimulus;
    void setButton(MutableButton* buttons, char* text, int value);
};

#endif // CENTRALLABEL_H
