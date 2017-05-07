#include "rpggame.h"
#include <iostream>


using namespace std;

RPGGame::RPGGame()
{
    rg= new RandomGenerator();
}

RPGGame::start()
{
    return 0;
}

unsigned int RPGGame::getRandomNumber()
{
    return rg->getRandomInt();
}
