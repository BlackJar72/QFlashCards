#include "qflashcards.h"
#include <QApplication>
#include <iostream>
#include <QString>
#include <QDir>
#include "filehandler.h"

int main(int argc, char *argv[])
{
    if(argc > 1) {
		// If called on a file, try to open the file and 
		// keep the current directory (likely that of the 
		// file, though not necessarily).
        QString inFile(argv[1]);
        FileHandler loader;
        loader.readFile(inFile);
    } else {
		// Set path typically, incase globally installed
		// (e.g., installed in /user/bin)
		QDir::setCurrent(QDir::homePath());
	}
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/IndexCard32.png"));
    QFlashCards w;
    w.setWindowTitle("Flash Cards");
    w.show();

    return a.exec();
}
