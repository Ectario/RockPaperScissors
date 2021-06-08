#ifndef HAND_H
#define HAND_H


const int WIN = 1;
const int EQUAL = 0;
const int LOOSE = -1;
const int UNDEFINED = 2;


enum class Hand {
    PAPER,
    ROCK,
    SCISSORS,
    HAND_COUNT = 3 //used just for the random generation
};

int battle(Hand h1, Hand h2); //It's relative to h1, so return WIN if h1 win the battle.

#endif // HAND_H
