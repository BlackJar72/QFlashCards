#include "qflashcards.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFlashCards w;
    w.show();

    return a.exec();
}
