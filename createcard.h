#ifndef CREATECARD_H
#define CREATECARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

#include "cardentry.h"
#include "buttonpanel.h"

class CreateCard : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCard(QWidget *parent = 0);
    void setData(CardEntry* data);

signals:

public slots:
    void updateCardData();
    void makeNewCard();

private:
    CardEntry* card;
    QTextEdit* question;
    QTextEdit* answer;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
};

#endif // CREATECARD_H
