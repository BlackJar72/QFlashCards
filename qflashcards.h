#ifndef QFLASHCARDS_H
#define QFLASHCARDS_H

#include <QMainWindow>

namespace Ui {
class QFlashCards;
}

class QFlashCards : public QMainWindow
{
    Q_OBJECT

public:
    explicit QFlashCards(QWidget *parent = 0);
    ~QFlashCards();

private:
    Ui::QFlashCards *ui;
};

#endif // QFLASHCARDS_H
