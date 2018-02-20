#include "cardentry.h"
/**
 * This default constructor.
 */
CardEntry::CardEntry(QObject *parent) : QObject(parent)
{
    question = QString("");
    answer   = QString("");

    reversable = true;
    canBeFree  = true;
}


/**
 * The method for setting all the data for the card, used both in 
 * creating new cards, editing cards, and loading for file.
 *
 * Note that the two boolean values are not saved in the actually 
 * card's data but not actually used at this time.  They are here 
 * for possible future use; for now they should simply be true 
 * for consistency.
 */
void CardEntry::setData(const QString& question, const QString& answer,
                        bool reversable = true, bool canBeFree = true) {
    this->question   = question;
    this->answer     = answer;
    this->reversable = reversable;
    this->canBeFree  = canBeFree;
}


/**
 * Returns the "question" of the cards (which may or may not be 
 * a literal questions).  
 * 
 * This is used for presentation of the cards, as well as saving 
 * to files.
 */
QString CardEntry::getQuestion() const {
    return question;
}


/**
 * Returns the "answer" of the card, meaning the second part, that 
 * which the user must answer in quiz mode.
 *
 * This is used both for card presentation and for checking user 
 * responses, as well as saving the data to files.
 */
QString CardEntry::getAnswer() const {
    return answer;
}


/**
 * Returns one of the currently unused booleans
 */
bool CardEntry::isFreeReversable() const {
    return reversable;
}


/**
 * Returns one of the currently unused booleans
 */
bool CardEntry::isGoodForInput() const {
    return canBeFree;
}

