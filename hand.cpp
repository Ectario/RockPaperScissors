#include "Hand.h"

int battle(Hand h1, Hand h2){
    switch (h1)
    {
        case Hand::PAPER:
            switch (h2) {
                case Hand::PAPER: return EQUAL;
                case Hand::ROCK:     return WIN;
                case Hand::SCISSORS: return LOOSE;
                default: return UNDEFINED;
            };
        case Hand::ROCK:
            switch (h2) {
                case Hand::PAPER: return LOOSE;
                case Hand::ROCK:     return EQUAL;
                case Hand::SCISSORS: return WIN;
                default: return UNDEFINED;
            };
        case Hand::SCISSORS:
            switch (h2) {
                case Hand::PAPER: return WIN;
                case Hand::ROCK:     return LOOSE;
                case Hand::SCISSORS: return EQUAL;
                default: return UNDEFINED;
            };
        default: return UNDEFINED;
    }
}
