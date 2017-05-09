#ifndef RPGGAME_H
#define RPGGAME_H
#include <randomgenerator.h>
#include <list>

class RPGGame
{
    RandomGenerator* rg;

public:
    RPGGame();
    void start();
    unsigned int getRandomNumber();
};

#endif // RPGGAME_H
