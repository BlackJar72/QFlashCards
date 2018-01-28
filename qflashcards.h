#ifndef QFLASHCARDS_H
#define QFLASHCARDS_H

#include <QMainWindow>
#include "reviewcard.h"
#include "inputcard.h"
#include "choicecard.h"
#include "createcard.h"
#include "buttonpanel.h"

namespace Ui {
class QFlashCards;
}

class QFlashCards : public QMainWindow
{
    Q_OBJECT

public:
    explicit QFlashCards(QWidget *parent = 0);
    ~QFlashCards();

private slots:
    void on_actionExit_triggered();

    void on_actionReview_triggered();

    void on_actionMultiple_Choice_triggered();

    void on_actionFree_Responce_triggered();

    void on_actionNewCards_triggered();

private:
    Ui::QFlashCards *ui;
    ReviewCard* reviewCard;
    InputCard* freeResponceCard;
    ChoiceCard* multipleChoiceCard;
    CreateCard* createNewCards;
    ButtonPanel* buttons;
};

#endif // QFLASHCARDS_H
