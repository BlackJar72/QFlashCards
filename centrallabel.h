#ifndef CENTRALLABEL_H
#define CENTRALLABEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "buttonpanel.h"

class CentralLabel : public QWidget
{
    Q_OBJECT

public:
    explicit CentralLabel(QWidget *parent = 0);
    void setText(QString text);

signals:

public slots:

private:
    QLabel* label;
    ButtonPanel* buttons;
    QVBoxLayout* layout;
};

#endif // CENTRALLABEL_H
