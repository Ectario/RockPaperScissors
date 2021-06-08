#include "mainwindow.h"
#include <QDebug>
#include <Hand.h>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QVBoxLayout>
#include <bot.h>

QPushButton* rockButton;
QPushButton* paperButton;
QPushButton* scissorsButton;
QLabel* textLabel;
QWidget* widget;
QVBoxLayout* vlayout;
Bot* bot;

inline const char* ToString(Hand h)
{
    switch (h)
    {
        case Hand::PAPER:    return "Paper";
        case Hand::ROCK:     return "Rock";
        case Hand::SCISSORS: return "Scissors";
        default:             return "[Unknown hand_type]";
    }
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    bot = new Bot();
    bot->chooseHand();
    qDebug() << ToString(bot->getHand());

    //Set the Basic Display

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

    textLabel = new QLabel(ToString(bot->getHand()));
    textLabel->setFont(QFont("Comic Sans MS", 48, QFont::Normal, false));
    vlayout->addWidget(textLabel);

    widget->setLayout(vlayout);
    w.setCentralWidget(widget);
    w.show();

    return app.exec();
}
