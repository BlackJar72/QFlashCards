#ifndef BUTTONPANEL_H
#define BUTTONPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include "mutablebutton.h"

class ButtonPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonPanel(QWidget *parent = 0);
    MutableButton* button1;
    MutableButton* button2;
    MutableButton* button3;
    MutableButton* button4;

signals:

public slots:

private:
    QHBoxLayout* layout;
};

#endif // BUTTONPANEL_H
