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

signals:

public slots:

private:
    MutableButton* button1;
    MutableButton* button2;
    MutableButton* button3;
    MutableButton* button4;
    QHBoxLayout* layout;
};

#endif // BUTTONPANEL_H
