#include "rpggame.h"
#include <iostream>


using namespace std;

RPGGame::RPGGame()
{
    rg= new RandomGenerator();
}

RPGGame::start()
{
    unsigned int consoleInput;
    cout<<"Combien de nombres pseudo-aleatoires veux tu ?"<<endl;
    cout<<"Ecrivez 0 pour quitter."<<endl;

    while(consoleInput!=0 ){

        cin>>consoleInput;

        std::list<unsigned int> l=rg->getListOfRandomInt(consoleInput);

        rg->printListOfRandomInt(l);
    }

    return 0;
}

unsigned int RPGGame::getRandomNumber()
{
    return rg->getRandomInt();
}
