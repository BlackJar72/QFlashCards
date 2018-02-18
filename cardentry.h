#ifndef CARDENTRY_H
#define CARDENTRY_H

#include <QObject>
#include <QString>


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
class CardEntry : public QObject
{
    Q_OBJECT

public:
    explicit CardEntry(QObject *parent = 0);
    void setData(const QString& question, const QString& answer,
                 bool reversable, bool canBeFree);
    QString getQuestion() const;
    QString getAnswer() const;
    bool isFreeReversable() const;
    bool isGoodForInput() const;

signals:

public slots:

private:
    QString question;
    QString answer;
    bool reversable;
    bool canBeFree;
};

#endif // CARDENTRY_H
