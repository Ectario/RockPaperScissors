#include "mainwindow.h"
#include <string>
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
void refreshText();

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

    textLabel = new QLabel("Waiting results");
    textLabel->setFont(QFont("Comic Sans MS", 35, QFont::Normal, false));
    textLabel->setAlignment(Qt::AlignCenter);;
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

void refreshText(int BATTLE_ISSUE){
    string result;
    switch (BATTLE_ISSUE) {
        case WIN : result = "Won"; break;
        case LOOSE: result = "Lose"; break;
        case EQUAL: result = "Equal"; break;
        default: result = "Undefined"; break;
    }
    textLabel->setText((("Last Bot hand :\n" + (string) handToString(bot->getHand())) + "\n" + "Results : " + result).c_str());
}

void handleRockButton(){
    int result = battle(Hand::ROCK, bot->getHand());
    refreshText(result);
    bot->chooseHand();
}

void handlePaperButton(){
    int result = battle(Hand::PAPER, bot->getHand());
    refreshText(result);
    bot->chooseHand();
}

void handleScissorsButton(){
    int result = battle(Hand::SCISSORS, bot->getHand());
    refreshText(result);
    bot->chooseHand();
}

