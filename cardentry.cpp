#include "cardentry.h"

/**
 * This is a class for holding data for a given flash card.
 * Data includes the question and answer as QString, along
 * with boolean flags telling whether this makes sense for
 * for use with in free responce mode and both forward and
 * when reversed (free responces should not involve entire
 * paragraphs, as this they must be entered verbatim).
 *
 * It stores its members directly.  In addition, it uses
 * copying for initializing and returning data; the data
 * size should never be huge and this helps to protect the
 * integrity of the stored information by not allowing
 * it to referenced externally through pointers.
 *
 * @brief CardEntry::CardEntry
 * @param parent
 */
CardEntry::CardEntry(QObject *parent) : QObject(parent)
{
    question = QString("");
    answer   = QString("");

    reversable = true;
    canBeFree  = true;
}

void CardEntry::setData(const QString& question, const QString& answer,
                        bool reversable, bool canBeFree) {
    this->question   = question;
    this->answer     = answer;
    this->reversable = reversable;
    this->canBeFree  = canBeFree;
}

const QString CardEntry::getQuestion() const {
    return question;
}

const QString CardEntry::getAnswer() const {
    return answer;
}

const bool CardEntry::isFreeReversable() const {
    return reversable;
}

const bool CardEntry::isGoodForInput() const {
    return canBeFree;
}

