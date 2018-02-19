#ifndef QFLASHCARDS_H
#define QFLASHCARDS_H

#include <QMainWindow>
#include "reviewcard.h"
#include "inputcard.h"
#include "createcard.h"
#include "buttonpanel.h"
#include "editcard.h"
#include "enumcardtype.h"

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
    void showSpecialText(MessageType msg, CardType caller);
    void on_actionExit_triggered();
    void on_actionReview_triggered();
    void on_actionFree_Responce_triggered();
    void on_actionNewCards_triggered();
    void on_actionEdit_Cards_triggered();
    void gotoCard(CardType card);
    void gotoNextCard(CardType card);
    void gotoShowAnswer(CardType card);

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionNew_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_actionLicense_triggered();

private:
    Ui::QFlashCards *ui;
    ReviewCard* reviewCard;
    InputCard* freeResponceCard = 0;
    CreateCard* createNewCards;
    EditingCard* editCards;
    ButtonPanel* buttons;
    void gotoFreeResponce();
};

#endif // QFLASHCARDS_H
