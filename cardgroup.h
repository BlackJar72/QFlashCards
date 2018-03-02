#ifndef CARDGROUP_H
#define CARDGROUP_H

#include <QObject>
#include <QList>
#include "cardentry.h"
#include <algorithm>
#include <random>
#include <chrono>


/**
 * This class represents a set of flash cards that can be
 * used for study.  All cards currently in memory will be 
 * part of this structure.
 *
 * @brief The CardGroup class
 */
class CardGroup : public QObject
{
    Q_OBJECT

public:
    explicit CardGroup(QObject *parent = 0);
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


signals:

public slots:

private:
    int current;
    bool atEnd;
    QList<CardEntry*>* cards;
    CardGroup();
};

#endif // CARDGROUP_H
