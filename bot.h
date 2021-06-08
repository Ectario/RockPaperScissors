#include <hand.h>
#ifndef BOT_H
#define BOT_H

class Bot
{
public:
    Bot();
    void chooseHand();
    Hand getHand();
private:
    Hand hand;
};

#endif // BOT_H
