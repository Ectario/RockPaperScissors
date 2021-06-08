#include "bot.h"
#include <Hand.h>
#include <random>
#include <time.h>

Bot::Bot()
{
    srand(time(NULL));
    Hand hand;
    chooseHand();
}

Hand Bot::getHand()
{
    return this->hand;
}


void Bot::chooseHand()
{
    this->hand = static_cast<Hand>(rand() % (int) (Hand::HAND_COUNT));
}

