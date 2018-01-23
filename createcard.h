#ifndef CREATECARD_H
#define CREATECARD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class CreateCard : public QWidget
{
    Q_OBJECT
public:
    explicit CreateCard(QWidget *parent = 0);

signals:

public slots:

private:
    QTextEdit* question;
    QTextEdit* answer;
    QVBoxLayout* layout;
};

#endif // CREATECARD_H
