#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "cardgroup.h"
#include "cardentry.h"

class CardManager
{
public:
    CardManager();
    static CardManager* getCardManager();
    CardGroup* getCardGroup();
    void makeGroup();
    CardEntry* getCard();
    CardEntry* getCardAt(int i);
    void shuffle();
    void sort();
    void reset();
    void addCard(CardEntry* in);

private:
    CardGroup* cardGroup;
};

#endif // CARDMANAGER_H
