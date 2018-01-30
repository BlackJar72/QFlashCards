#ifndef EDITCARD_H
#define EDITCARD_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include "buttonpanel.h"
#include "cardentry.h"

class EditingCard : public QWidget
{
    Q_OBJECT

public:
    explicit EditingCard(QWidget *parent = 0);
    void setData(const CardEntry* data);

signals:

public slots:
    void previousCard();
    void removeCard();
    void saveCard();
    void nextCard();

private:
    QTextEdit* answer;
    QTextEdit* question;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
};

#endif // EDITCARD_H
