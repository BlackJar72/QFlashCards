#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "cardgroup.h"
#include "cardentry.h"
#include <QList>

/**
 * This class hold a reference to the in-use CardGroup, 
 * allowing a consistent and transparent access to the 
 * CardGroup which may actually be replaced or recreated 
 * behind the scenes.  Most methods of this class simply 
 * wrap methods of the same name hidden in the CardGroup. 
 * Exceptions are those that act as getters for the 
 * CardGroup's pointer or its own singleton pointer.
 */
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
    void preset();
    void addCard(CardEntry* in);
    CardEntry* getNewCard();
    void removeCard(CardEntry* in);
    CardEntry* removeCurrent();
    QList<CardEntry*>* getDataModel();
    void newCardGroup();

private:
    CardGroup* cardGroup;
};

#endif // CARDMANAGER_H
