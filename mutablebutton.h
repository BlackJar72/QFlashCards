#ifndef MUTABLEBUTTON_H
#define MUTABLEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QSizePolicy>

#include <string>

class MutableButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MutableButton(QWidget *parent = 0);
    void setEffect(char* text, unsigned int effect);
    unsigned int getEffect() const;

signals:

public slots:

private:
    unsigned int effectState;
};

#endif // MUTABLEBUTTON_H
