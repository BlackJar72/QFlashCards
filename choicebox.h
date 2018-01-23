#ifndef CHOICEBOX_H
#define CHOICEBOX_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>

class ChoiceBox : public QWidget
{
    Q_OBJECT
public:
    explicit ChoiceBox(QWidget *parent = 0);

signals:

public slots:

private:
    // TODO: Consider learning / using Qt collections instead of
    // a raw array (or stl?).
    QRadioButton* choices; // Should be 4 elements array (for now)
    QButtonGroup* grouping;
};

#endif // CHOICEBOX_H
