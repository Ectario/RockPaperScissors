#include <hand.h>
#ifndef BOT_H
#define BOT_H

class Bot
{
public:
    Bot();
    void chooseHand();
    unsigned int getNbVictory();
    Hand getHand();
private:
    unsigned int nbVictory;
    Hand hand;
};

#endif // BOT_H
