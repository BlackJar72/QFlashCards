#include "cardgroup.h"
#include <iostream>

CardGroup::CardGroup(QObject *parent)
        :  QObject(parent),
           current(0),
           atEnd(false),
           cards(new QList<CardEntry*>()),
           deckName(NameData()) {}


/**
 * This will retrieve the next card for presentations.
 * This will first increment the card to the next index, 
 * and if this exceeds the end of the card list will 
 * reset the index and shuffle the cards to maintain 
 * randomization.
 *
 * Used most notably to get the next cards in quiz mod.
 */
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


/**
 * This will get the previous card, wrapping around to the 
 * end of the current cards when moving past the beginning.
 * This will never cause a card shuffle to occur.
 */
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


/**
 * This will get the next card in the group, wrapping around 
 * to the beginning if the end is exceeded.  This will never 
 * casue the cards to be shuffled.
 */
CardEntry* CardGroup::getNextCard() {
    CardEntry* out;
    if(cards->isEmpty()) {
        out = new CardEntry;
    } else {
        current++;
        current %= cards->length();
        out = cards->at(current);
    }
    return out;
}


/**
 * This will get the currently indexed card, and will 
 * neither move the index or alter the order.  This is 
 * used to return to the current cards after missing 
 * on in quiz mode.
 */
CardEntry* CardGroup::getCurrentCard() {
    return cards->at(current);
}


/**
 * This is a function for alpha-numerically comparing QStrings
 * that are hidden behind pointers.  That is, it allow QString 
 * pointers to be compared in terms of the string data rather 
 * than the address.
 */
bool compQSPtr(CardEntry* a, CardEntry* b) {
    return ((*a).getQuestion().compare((*b).getQuestion()) < 0);
}
bool (*compPtr)(CardEntry*, CardEntry*) = compQSPtr;


/**
 * Sort the cards into alpha-numeric order.  This is done at 
 * saving purely to maintain a consistent order of data in 
 * save files, and also before editing for similar reasons.
 */
void CardGroup::sort() {
    std::sort(cards->begin(), cards->end(), compPtr);
}


/**
 * This resets the index to 0, i.e., returns to the 
 * beginning of the card group.
 */
void CardGroup::reset() {
    current = 0;
    atEnd = false;
}


/**
 * This will reset the card to the first in the group,
 * but will do so by setting the index to -1 rather 
 * than 0, so the methods that increment before return 
 * a card will return the first (index 0).  This is used 
 * when switching modes in order.
 */
void CardGroup::preset() {
    current = -1;
    atEnd = false;
}


/**
 * Used to take a card out for the group. The 
 * card at the given index "in" will be removed.
 */
void CardGroup::removeCard(CardEntry* in) {
    cards->removeAll(in);
}


/**
 * Remove the current card from the group.
 */
CardEntry* CardGroup::removeCurrent() {
    cards->removeAt(current);
    if(current > cards->length()) {
        current = 0;
    }
    return cards->at(current);
}


/**
 * Randomizes the order of the cards.
 */
void CardGroup::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards->begin(), cards->end(),
             std::default_random_engine(seed));
}


/**
 * Adds the supplied card to the group.
 */
void CardGroup::addCard(CardEntry* in) {
    in->setParent(this);
    cards->append(in);
}


/**
 * A factory method which returns new cards; these 
 * cards are not part of the group, but must be added 
 * using CardGroup::addCard().  This is important, as 
 * the card is only added after it has had a chance to 
 * be edited.
 */
CardEntry* CardGroup::getNewCard() {
    CardEntry* out = new CardEntry;
    return out;
}


/**
 * This will get the card at the given index; used 
 * notably for iteration when saving the cards.
 */
CardEntry* CardGroup::getCardAt(int i) {
    if((i >= 0) && (i < cards->length())) {
        return cards->at(i);
    } else return 0;
}


const NameData* CardGroup::getName() const {
    return &deckName;
}


void CardGroup::setName(QString& name) {
    deckName.setName(name);
}

