#include "cardmanager.h"

// Why settle for private when it can be invisible.
// Its still just a wrapped global, though.
CardManager* singleton = new CardManager();
CardEntry*   tmpCard   = new CardEntry;

CardManager::CardManager() : cardGroup(new CardGroup(0)) {}

/**
 * Gets a pointer to the current CardGroup.
 * This should be alwats used to access the
 * CardGroup and its functions, and the output
 * should never be cached.  This should keep
 * all references to cards current and avoid
 * dangling pointers when new card groups are
 * loaded or created.
 *
 * @brief CardManager::getCardGroup
 * @return
 */
CardGroup* CardManager::getCardGroup() {
    return cardGroup;
}

CardManager* CardManager::getCardManager() {
    return singleton;
}

void CardManager::makeGroup() {
    delete cardGroup;
    cardGroup = new CardGroup(0);
}

CardEntry* CardManager::getCard() {
    CardEntry* out = cardGroup->getCard();
    if(out == 0) {
        out = new CardEntry;
        cardGroup->addCard(out);
    }
    return out;
}

CardEntry* CardManager::getPreviousCard() {
    CardEntry* out = cardGroup->getPreviousCard();
    if(out == 0) {
        out = new CardEntry;
        cardGroup->addCard(out);
    }
    return out;
}

CardEntry* CardManager::getNextCard() {
    CardEntry* out = cardGroup->getNextCard();
    if(out == 0) {
        out = new CardEntry;
        cardGroup->addCard(out);
    }
    return out;
}

CardEntry* CardManager::getCurrentCard() {
    CardEntry* out = cardGroup->getCurrentCard();
    if(out == 0) {
        out = new CardEntry;
        cardGroup->addCard(out);
    }
    return out;
}

CardEntry* CardManager::getCardAt(int i) {
    return cardGroup->getCardAt(i);
}


void CardManager::removeCard(CardEntry* in) {
    cardGroup->removeCard(in);
}


CardEntry* CardManager::removeCurrent() {
    cardGroup->removeCurrent();
}

void CardManager::shuffle() {
    cardGroup->shuffle();
}

void CardManager::sort() {
    cardGroup->shuffle();
}

void CardManager::reset() {
    cardGroup->reset();
}

void CardManager::addCard(CardEntry* in) {
    cardGroup->addCard(in);
}

CardEntry* CardManager::getNewCard() {
    return cardGroup->getNewCard();
}

QList<CardEntry*>* CardManager::getDataModel() {
	return cardGroup->getDataModel();
}
