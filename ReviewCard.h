#ifndef REVIEWCARD_H
#define REVIEWCARD_H

#include <QWidget>

namespace Ui {
    class ReviewCard;
}

class ReviewCard : public QWidget
{
    Q_OBJECT

public:
    explicit ReviewCard(QWidget *parent = 0);
    ~ReviewCard();

private:
    Ui::ReviewCard *ui;

signals:

public slots:
};

#endif // REVIEWCARD_H
