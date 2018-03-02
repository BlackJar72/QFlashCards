#include "qflashcards.h"
#include "ui_qflashcards.h"
#include "cardgroup.h"
#include "cardmanager.h"
#include "cardentry.h"
#include "centrallabel.h"
#include <QLabel>
#include <QSizePolicy>
#include <QFileDialog>
#include <QTextBrowser>
#include <QDesktopServices>
#include <QUrl>
#include "filehandler.h"

const QString GPL("https://www.gnu.org/licenses/gpl-3.0.en.html");
const QUrl GPLURL(GPL);

QFlashCards::QFlashCards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFlashCards)
{
    ui->setupUi(this);
    show();
}

QFlashCards::~QFlashCards()
{
    delete ui;
}


void QFlashCards::setWorkingDir(QString dir) {
    this->dir = dir;
}


void QFlashCards::showSpecialText(MessageType msg, CardType caller) {
    CentralLabel* label = new CentralLabel(this);
    label->setMessage(msg);
    label->setCardType(caller);
    connect(label, &CentralLabel::signalTryAgain, this, &QFlashCards::gotoCard);
    connect(label, &CentralLabel::signalNextCard, this, &QFlashCards::gotoNextCard);
    connect(label, &CentralLabel::signalShowAnswer, this, &QFlashCards::gotoShowAnswer);
    setCentralWidget(label);
}

/**
 * @brief QFlashCards::on_actionExit_triggered
 *
 * Well, exit the application when the exit menu is selected
 */
void QFlashCards::on_actionExit_triggered()
{
    exit(0);
}

void QFlashCards::on_actionReview_triggered()
{
    reviewCard = new ReviewCard(this);
    CardManager::getCardManager()->shuffle();
    CardManager::getCardManager()->reset();
    reviewCard->setData(CardManager::getCardManager()->getCard());
    setCentralWidget(reviewCard);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionFree_Responce_triggered()
{
    freeResponceCard = new InputCard(this);
    CardManager::getCardManager()->shuffle();
    CardManager::getCardManager()->reset();
    freeResponceCard->setData(CardManager::getCardManager()->getCard());
    setCentralWidget(freeResponceCard);
    connect(freeResponceCard, &InputCard::writeToStatus,
            this, &QFlashCards::showSpecialText);
    centralWidget()->showNormal();
}

void QFlashCards::on_actionNewCards_triggered()
{
    createNewCards = new CreateCard(this);
    CardManager::getCardManager()->sort();
    CardManager::getCardManager()->reset();
    createNewCards->setData(CardManager::getCardManager()->getNewCard());
    setCentralWidget(createNewCards);
    centralWidget()->showNormal();	
	setWindowTitle(tr("Flash Cards").append(" - untitled");
}

void QFlashCards::on_actionEdit_Cards_triggered()
{
    editCards = new EditingCard(this);
    CardManager::getCardManager()->sort();
    CardManager::getCardManager()->preset();
    CardEntry* aCard = CardManager::getCardManager()->getCard();
    editCards->setData(aCard);
    setCentralWidget(editCards);    
    CardManager::getCardManager()->sort();
    centralWidget()->showNormal();
}


void QFlashCards::gotoCard(CardType card) {
    switch(card) {
        case CardType::INPUT:
            gotoFreeResponce();
            break;
        default:
            break;
    }
}



void QFlashCards::gotoNextCard(CardType card) {
    switch(card) {
        case CardType::INPUT:            
			freeResponceCard = new InputCard(this);			
			freeResponceCard->setData(CardManager::getCardManager()->getCard());
			setCentralWidget(freeResponceCard);
			connect(freeResponceCard, &InputCard::writeToStatus,
					this, &QFlashCards::showSpecialText);
			centralWidget()->showNormal();
            break;
        default:
            break;
    }
}



void QFlashCards::gotoShowAnswer(CardType card) {
    switch(card) {
        case CardType::INPUT:
            freeResponceCard = new InputCard(this);
            freeResponceCard->setData(CardManager::getCardManager()->getCurrentCard());
            setCentralWidget(freeResponceCard);
            connect(freeResponceCard, &InputCard::writeToStatus,
                    this, &QFlashCards::showSpecialText);
            freeResponceCard->showAnswer();
            centralWidget()->showNormal();
            break;
        default:
            break;
    }
}

void QFlashCards::gotoFreeResponce()
{
    freeResponceCard = new InputCard(this);
    freeResponceCard->setData(CardManager::getCardManager()->getCurrentCard());
    setCentralWidget(freeResponceCard);
    connect(freeResponceCard, &InputCard::writeToStatus,
            this, &QFlashCards::showSpecialText);
    centralWidget()->showNormal();
}


void QFlashCards::on_actionLoad_triggered()
{
    QString fileName
            = QFileDialog::getOpenFileName(
                this, tr("Open File"),
                dir,
                tr("Flashcards (*.qfcml)"));
    FileHandler handler;
    handler.readFile(fileName);
	setWindowTitle(tr("Flash Cards").append(" - ").append(fileName));
}

void QFlashCards::on_actionSave_triggered()
{
    QString fileName
            = QFileDialog::getSaveFileName(
                this, tr("Save Flashcards"),
                dir,
                tr("Flashcards (*.qfcml)"));
	if(fileName.isEmpty()) {
		fileName = QString(tr("untitled");
	}
    FileHandler handler;
    handler.saveFile(fileName);
	setWindowTitle(tr("Flash Cards").append(" - ").append(fileName));
}

void QFlashCards::on_actionNew_triggered()
{
    CardManager::getCardManager()->newCardGroup();
    on_actionNewCards_triggered();
}

void QFlashCards::on_actionHelp_triggered()
{
    QTextBrowser* helpview = new QTextBrowser;
    helpview->setEnabled(true);
    helpview->setSource(QString("qrc:///html/help.html"));
    setCentralWidget(helpview);
}

void QFlashCards::on_actionAbout_triggered()
{
    QTextBrowser* helpview = new QTextBrowser;
    helpview->setEnabled(true);
    helpview->setSource(QString("qrc:///html/about.html"));
    setCentralWidget(helpview);
}

void QFlashCards::on_actionLicense_triggered()
{
    QDesktopServices::openUrl(GPLURL);
}
