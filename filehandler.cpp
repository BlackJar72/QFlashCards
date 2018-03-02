#include "filehandler.h"
#include <iostream>
#include "cardmanager.h"
#include "cardgroup.h"
#include "cardentry.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QList>
//#include <QDebug>


FileHandler::FileHandler(QObject *parent) : QObject(parent){}


/**
 * This will read a card into the CardGroup.
 *
 * @brief readCard
 * @param reader
 */
CardEntry* readCard(QXmlStreamReader* reader) {
    CardEntry* card = CardManager::getCardManager()->getNewCard();
    reader->readNext();
    QString question, answer;
    bool done = reader->atEnd();
    while(!done) {
        if(reader->isStartElement()) {
            if(reader->name() == "question") {
                reader->readNext();
                reader->text().appendTo(&question);
            } else if(reader->name() == "answer") {
                reader->readNext();
                reader->text().appendTo(&answer);
            }
        } else if(reader->isEndElement()
                 && (reader->name() == "card")) {
           done = true;
        }
        reader->readNext();
        done = done || reader->atEnd();
    }
    card->setData(question, answer);
    return card;
}


/**
 * This will read a file in, replacing the current set of flash
 * cards with those in the file.  The file must be in an XML
 * format relevant to this app, typically these will end with
 * "*.qfcml" for QFlashCards Mark-up Language.
 *
 * @brief FileHandler::readFile
 * @param fileName
 */
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
    QXmlStreamReader reader(&file);
    while(reader.readNextStartElement()) {
        if(reader.name() == "card") {
            CardManager::getCardManager()->addCard(readCard(&reader));
        } else {
            continue;
        }
    }
    file.close();
}


/**
 * This will save the current set of card to an XML file ending
 * with the extension ".qfcml" (QFlashCard Mark-up Language).
 *
 * @brief FileHandler::saveFile
 * @param fileName
 */
void FileHandler::saveFile(QString fileName) {
    if(!fileName.endsWith(".qfcml")) {
        fileName.append(".qfcml");
    }
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
    writer.writeStartElement("qflashcards");
    while(card) {
        writer.writeStartElement("card");
        writer.writeTextElement("question", card->getQuestion());
        writer.writeTextElement("answer", card->getAnswer());
        writer.writeEndElement();
        card = manager->getCardAt(i++);
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();
}

