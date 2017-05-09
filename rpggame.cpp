#include "rpggame.h"
#include <iostream>


using namespace std;

RPGGame::RPGGame()
{
    rg= new RandomGenerator();
}

void RPGGame::start()
{
    return;
}

unsigned int RPGGame::getRandomNumber()
{
    return rg->getRandomInt();
}
