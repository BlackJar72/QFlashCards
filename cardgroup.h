#ifndef CARDGROUP_H
#define CARDGROUP_H

#include <QObject>
#include <QList>
#include "cardentry.h"
#include <algorithm>
#include <random>
#include <chrono>
#include "/home/jared/Libraries/cpp/src/MyLibraries/ArrayContainers/include/ArrayContainers.h"

/**
 * This class represents a set of flash cards that can be
 * used for study.
 *
 * @brief The CardGroup class
 */
class CardGroup : public QObject
{
    Q_OBJECT

public:
    explicit CardGroup(QObject *parent = 0);
    CardEntry* getCard();
    CardEntry* getCardAt(int i);
    void shuffle();
    void sort();
    void reset();
    void addCard(CardEntry* in);


signals:

public slots:

private:
    int current;
    bool atEnd;
    QList<CardEntry*>* cards;
    CardGroup();
};

#endif // CARDGROUP_H
