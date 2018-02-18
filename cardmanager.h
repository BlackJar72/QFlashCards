#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "cardgroup.h"
#include "cardentry.h"
#include <QList>

class CardManager
{
public:
    CardManager();
    static CardManager* getCardManager();
    CardGroup* getCardGroup();
    void makeGroup();
    CardEntry* getCard();
    CardEntry* getPreviousCard();
    CardEntry* getNextCard();
    CardEntry* getCurrentCard();
    CardEntry* getCardAt(int i);
    void shuffle();
    void sort();
    void reset();
    void addCard(CardEntry* in);
    CardEntry* getNewCard();
    void removeCard(CardEntry* in);
    CardEntry* removeCurrent();
    QList<CardEntry*>* getDataModel();

private:
    CardGroup* cardGroup;
};

#endif // CARDMANAGER_H
