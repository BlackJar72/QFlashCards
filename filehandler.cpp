#include "filehandler.h"
#include <iostream>
#include "cardmanager.h"
#include "cardgroup.h"
#include "cardentry.h"
#include <QXmlStreamWriter>
#include <QList>


FileHandler::FileHandler(QObject *parent) : QObject(parent){}


void FileHandler::readFile(QString fileName) {
    QFile file(fileName);
    if(!file.exists()) {
        std::cerr << "An ERROR has occured; file "
                 << "\"" << qPrintable(fileName) << "\""
                 << " does not seem to exist!! " << std::endl
                 << qPrintable(file.errorString()) << std::endl;
        return;

    }
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "An ERROR has occured; cannot open the file "
                 << "\"" << qPrintable(fileName) << "\"" << std::endl
                 << qPrintable(file.errorString()) << std::endl;
        return;
    }
    CardManager::getCardManager()->newCardGroup();
    // TODO: Read file.
}


void FileHandler::saveFile(QString fileName) {
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        std::cerr << "An ERROR has occured; cannot write to file "
                 << "\"" << qPrintable(fileName) << "\"" << std::endl
                 << qPrintable(file.errorString()) << std::endl;
        return;
    }
    CardManager* manager = CardManager::getCardManager();
    manager->sort();
    manager->reset();    
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    int i = 0;
    CardEntry* card = manager->getCardAt(i++);
    while(card) {
        std::clog << "card = " << card << std::endl;
        std::clog << " \t Question = " << qPrintable(card->getQuestion()) << std::endl;
        std::clog << " \t   Answer = " << qPrintable(card->getAnswer()) << std::endl << std::endl;
        writer.writeStartElement("card");
        writer.writeTextElement("question", card->getQuestion());
        writer.writeTextElement("answer", card->getAnswer());
        writer.writeEndElement();
        card = manager->getCardAt(i++);
    }
    writer.writeEndDocument();
    file.close();
}

