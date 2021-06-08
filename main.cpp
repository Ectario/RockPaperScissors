#include "mainwindow.h"
#include <string.h>
#include <QDebug>
#include <Hand.h>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QVBoxLayout>
#include <bot.h>

using namespace std;

QPushButton* rockButton;
QPushButton* paperButton;
QPushButton* scissorsButton;
QLabel* textLabel;
QWidget* widget;
QVBoxLayout* vlayout;
Bot* bot;
Hand playerHand;


inline const char* handToString(Hand h)
{
    switch (h)
    {
        case Hand::PAPER:    return "Paper";
        case Hand::ROCK:     return "Rock";
        case Hand::SCISSORS: return "Scissors";
        default:             return "[Unknown hand_type]";
    }
}

void handleRockButton();
void handlePaperButton();
void handleScissorsButton();

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);
    MainWindow w;
    bot = new Bot();
    bot->chooseHand();

    //Set the Basic Display in the Window

    w.setWindowTitle("Rock Paper Scissors");
    widget = new QWidget();
    vlayout = new QVBoxLayout(widget);

    rockButton = new QPushButton("Rock");
    rockButton->setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
    vlayout->addWidget(rockButton);

    paperButton = new QPushButton("Paper");
    paperButton->setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
    vlayout->addWidget(paperButton);

    scissorsButton = new QPushButton("Scissors");
    scissorsButton->setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
    vlayout->addWidget(scissorsButton);

    //END Basic Display

    textLabel = new QLabel(("Bot hand :\n\n" + (string) handToString(bot->getHand())).c_str());
    textLabel->setFont(QFont("Comic Sans MS", 48, QFont::Normal, false));
    textLabel->setAlignment(Qt::AlignHCenter);;
    textLabel->setStyleSheet("border-width: 1px; border-style: solid; border-radius: 0px;");
    vlayout->addWidget(textLabel);

    widget->setLayout(vlayout);
    w.setCentralWidget(widget);

    // Connect button signal to appropriate slot
    w.connect(rockButton, &QPushButton::released, w.centralWidget(), &handleRockButton);
    w.connect(paperButton, &QPushButton::released, w.centralWidget(), &handlePaperButton);
    w.connect(scissorsButton, &QPushButton::released, w.centralWidget(), &handleScissorsButton);

    w.show();

    return app.exec();
}


void handleRockButton(){
    qDebug() << handToString(bot->getHand()) << " vs " << handToString(Hand::ROCK) << " : "<< battle(Hand::ROCK, bot->getHand());
    bot->chooseHand();
    textLabel->setText((("Bot hand :\n\n" + (string) handToString(bot->getHand())).c_str()));
}

void handlePaperButton(){
    qDebug() << handToString(bot->getHand()) << " vs " << handToString(Hand::PAPER) << " : "<< battle(Hand::PAPER, bot->getHand());
    bot->chooseHand();
    textLabel->setText((("Bot hand :\n\n" + (string) handToString(bot->getHand())).c_str()));
}

void handleScissorsButton(){
    qDebug() << handToString(bot->getHand()) << " vs " << handToString(Hand::SCISSORS) << " : " << battle(Hand::SCISSORS, bot->getHand());
    bot->chooseHand();
    textLabel->setText((("Bot hand :\n\n" + (string) handToString(bot->getHand())).c_str()));
}
