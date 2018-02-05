#ifndef CENTRALLABEL_H
#define CENTRALLABEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "buttonpanel.h"
#include "enumcardtype.h"

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

public slots:

private:
    QLabel* label;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
    CardType stimulus;
    void setButton(MutableButton* buttons, char* text, int value);
};

#endif // CENTRALLABEL_H
