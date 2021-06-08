#include "bot.h"
#include <Hand.h>
#include <random>
#include <time.h>

Bot::Bot()
{
    srand(time(NULL));
    unsigned int nbVictory = 0;
    Hand hand;
    chooseHand();
}

Hand Bot::getHand()
{
    return this->hand;
}

void Bot::addVictory()
{
    this->nbVictory++;
}

void Bot::chooseHand()
{
    this->hand = static_cast<Hand>(rand() % (int) (Hand::HAND_COUNT));
}

unsigned int Bot::getNbVictory()
{
    return this->nbVictory;
}
