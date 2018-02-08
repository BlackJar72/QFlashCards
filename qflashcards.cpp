#include "qflashcards.h"
#include "ui_qflashcards.h"
#include "cardgroup.h"
#include "cardmanager.h"
#include "cardentry.h"
#include "centrallabel.h"
#include <QLabel>
#include <QSizePolicy>

QFlashCards::QFlashCards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFlashCards)
{
    ui->setupUi(this);
    show();
}

QFlashCards::~QFlashCards()
{
    delete ui;
}


void QFlashCards::showSpecialText(MessageType msg, CardType caller) {
    CentralLabel* label = new CentralLabel(this);
    label->setMessage(msg);
    label->setCardType(caller);
    setCentralWidget(label);
}

/**
 * @brief QFlashCards::on_actionExit_triggered
 *
 * Well, exit the application when the exit menu is selected
 */
void QFlashCards::on_actionExit_triggered()
{
    exit(0);
}

void QFlashCards::on_actionReview_triggered()
{
    reviewCard = new ReviewCard(this);
    reviewCard->setData(CardManager::getCardManager()->getCard());
    setCentralWidget(reviewCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionMultiple_Choice_triggered()
{
    multipleChoiceCard = new ChoiceCard(this);
    setCentralWidget(multipleChoiceCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionFree_Responce_triggered()
{
    freeResponceCard = new InputCard(this);
    freeResponceCard->setData(CardManager::getCardManager()->getCard());
    setCentralWidget(freeResponceCard);
    connect(freeResponceCard, &InputCard::writeToStatus,
            this, &QFlashCards::showSpecialText);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionNewCards_triggered()
{
    createNewCards = new CreateCard(this);
    createNewCards->setData(CardManager::getCardManager()->getNewCard());
    setCentralWidget(createNewCards);    
    CardManager::getCardManager()->sort();
    centralWidget()->showNormal();
}

void QFlashCards::on_actionEdit_Cards_triggered()
{
    editCards = new EditingCard(this);
    CardEntry* aCard = CardManager::getCardManager()->getCard();
    editCards->setData(aCard);
    setCentralWidget(editCards);    
    CardManager::getCardManager()->sort();
    centralWidget()->showNormal();
}


void QFlashCards::gotoCard(CardType card) {
    switch(card) {
        case CardType::INPUT:
            gotoFreeResponce();
            break;
        default:
            break;
    }
}


void QFlashCards::gotoFreeResponce()
{
    freeResponceCard = new InputCard(this);
    freeResponceCard->setData(CardManager::getCardManager()->getCurrentCard());
    setCentralWidget(freeResponceCard);
    connect(freeResponceCard, &InputCard::writeToStatus,
            this, &QFlashCards::showSpecialText);
    centralWidget()->showNormal();
}



