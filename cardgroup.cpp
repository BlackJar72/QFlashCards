#include "cardgroup.h"

CardGroup::CardGroup(QObject *parent)
    :  QObject(parent), current(0), atEnd(false), cards(new QList<CardEntry*>()) {}


CardEntry* CardGroup::getCard() {
    if(current < cards->length()) {
        return cards->at(current++);
    } else {
        atEnd = true;
        current = 0;
        return 0; // Should I do this (return null)? Some would say its not "clean."
    }
}


CardEntry* CardGroup::getCardAt(int i) {
    return cards->at(i % cards->length());
}


void CardGroup::sort() {
    std::sort(cards->begin(), cards->end());
}


void CardGroup::reset() {
    current = 0;
    atEnd = false;
}


void CardGroup::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards->begin(), cards->end(),
             std::default_random_engine(seed));
}

void CardGroup::addCard(CardEntry* in) {
    cards->append(in);
}

