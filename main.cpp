#include "qflashcards.h"
#include <QApplication>
#include <iostream>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include "filehandler.h"


void getGoodName(QString& name) {
    int dot = name.lastIndexOf(".");
    int len = name.length() - dot;
    if(dot > - 1) {
        name.remove(dot, len);
    }
}


int main(int argc, char *argv[])
{
    QString dir = QDir::homePath();
    QString title("Flash Cards");
    if(argc > 1) {
		// If called on a file, try to open the file and 
		// keep the current directory (likely that of the 
		// file, though not necessarily).
        QString inFile(argv[1]);
        QFile file(inFile);
        QFileInfo info(file);
        if(info.isDir()) {
            dir = inFile;
        } else {
            FileHandler loader;
            loader.readFile(inFile);
            dir = info.canonicalPath();
            title.append(" - ");
            QString name = info.fileName();
            getGoodName(name);
            title.append(name);
        }
    }
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/IndexCard32.png"));
    QFlashCards w;
	QDir::setCurrent(dir);
    w.setWorkingDir(dir);
    w.setWindowTitle(title);
    w.show();

    return a.exec();
}
