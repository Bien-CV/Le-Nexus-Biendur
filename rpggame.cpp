#include "rpggame.h"
#include <iostream>


using namespace std;

RPGGame::RPGGame()
{
    rg= new RandomGenerator();
}

RPGGame::start()
{
    string consoleInput;
    cout<<"Si tu veux un nouveau nombre pseudo-aléatoire, appuies sur entrée, sinon écrit sortir."<<endl;

    while(consoleInput!="sortir" ){
        getline(cin, consoleInput);
        cout<<getRandomNumber()<<endl;
    }

    return 0;
}

unsigned int RPGGame::getRandomNumber()
{
    return rg->getRandomInt();
}
