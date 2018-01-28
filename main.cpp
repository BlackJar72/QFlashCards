#include "qflashcards.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/IndexCard32.png"));
    QFlashCards w;
    w.setWindowTitle("Flash Cards");
    w.show();

    return a.exec();
}
