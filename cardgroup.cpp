#include "cardgroup.h"
#include <iostream>

CardGroup::CardGroup(QObject *parent)
        :  QObject(parent),
           current(0),
           atEnd(false),
           cards(new QList<CardEntry*>()) {}


CardEntry* CardGroup::getCard() {
    CardEntry* out;
    if(cards->isEmpty()) {
        out = new CardEntry;
    } else {
        current++;
        if(current >= cards->length()) {
            shuffle();
            reset();
        }
        out = cards->at(current);
    }
    return out;
}


CardEntry* CardGroup::getPreviousCard() {
    CardEntry* out;
    if(cards->isEmpty()) {
        out = new CardEntry;
    } else {
        if(--current < 0) {
            current = cards->length() - 1;
        }
        out = cards->at(current);
    }
    return out;
}


CardEntry* CardGroup::getNextCard() {
    CardEntry* out;
    if(cards->isEmpty()) {
        out = new CardEntry;
    } else {
        current = (++current) % cards->length();
        out = cards->at(current);
    }
    return out;
}


CardEntry* CardGroup::getCurrentCard() {
    return cards->at(current);
}


CardEntry* CardGroup::getCardAt(int i) {
    return cards->at(i % cards->length());
}


void CardGroup::sort() {
    std::sort(cards->begin(), cards->end());
}


void CardGroup::reset() {
    current = -1;
    atEnd = false;
}


void CardGroup::removeCard(CardEntry* in) {
    cards->removeAll(in);
}


CardEntry* CardGroup::removeCurrent() {
    cards->removeAt(current);
    if(current > cards->length()) {
        current = 0;
    }
    return cards->at(current);
}


void CardGroup::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards->begin(), cards->end(),
             std::default_random_engine(seed));
}

void CardGroup::addCard(CardEntry* in) {
    in->setParent(this);
    cards->append(in);
}


CardEntry* CardGroup::getNewCard() {
    CardEntry* out = new CardEntry;
    return out;
}

