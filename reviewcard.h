#ifndef REVIEWCARD_H
#define REVIEWCARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

class ReviewCard : public QWidget
{
    Q_OBJECT
public:
    explicit ReviewCard(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel* question;
    QLabel* answer;
    QVBoxLayout* layout;
};

#endif // REVIEWCARD_H
