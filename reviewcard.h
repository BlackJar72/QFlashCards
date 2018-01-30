#ifndef REVIEWCARD_H
#define REVIEWCARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

#include "cardentry.h"
#include "buttonpanel.h"

class ReviewCard : public QWidget
{
    Q_OBJECT

public:
    explicit ReviewCard(QWidget *parent = 0);
    void setData(const CardEntry* data);

signals:

public slots:
    void nextCard();
    void lastCard();

private:
    QLabel* question;
    QLabel* answer;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
};

#endif // REVIEWCARD_H
