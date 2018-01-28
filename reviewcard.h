#ifndef REVIEWCARD_H
#define REVIEWCARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

#include "cardentry.h"

class ReviewCard : public QWidget
{
    Q_OBJECT

public:
    explicit ReviewCard(QWidget *parent = 0);
    void setData(const CardEntry* data);

signals:

public slots:

private:
    QLabel* question;
    QLabel* answer;
    QVBoxLayout* layout;
};

#endif // REVIEWCARD_H
