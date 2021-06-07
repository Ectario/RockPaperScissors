#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

QPushButton* rockButton;
QPushButton* paperButton;
QPushButton* scissorsButton;
QWidget * widget;
QVBoxLayout * vlayout;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

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

    widget->setLayout(vlayout);
    w.setCentralWidget(widget);
    w.show();

    return app.exec();
}
