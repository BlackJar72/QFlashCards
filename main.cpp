#include "qflashcards.h"
#include <QApplication>
#include <iostream>
#include <QString>
#include "filehandler.h"

int main(int argc, char *argv[])
{
    if(argc > 1) {
        QString inFile(argv[1]);
        FileHandler loader;
        loader.readFile(inFile);
    }
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/IndexCard32.png"));
    QFlashCards w;
    w.setWindowTitle("Flash Cards");
    w.show();

    return a.exec();
}
