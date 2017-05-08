#include "randomgenerator.h"

using namespace std;
//Use a portable implementation of random_device to seed the generator

RandomGenerator::RandomGenerator()
{
    gen= new std::minstd_rand0;
    this->seed=chrono::high_resolution_clock::now().time_since_epoch().count();
    this->gen->seed(seed);
}

void RandomGenerator::Reseed()
{
    gen= new std::minstd_rand0;
    this->seed=chrono::high_resolution_clock::now().time_since_epoch().count();
    this->gen->seed(seed);
}

RandomGenerator::RandomGenerator(unsigned int userSeed)
{
    this->seed=userSeed;
    this->gen->seed(seed);
}

unsigned int RandomGenerator::getRandomInt(){
    unsigned int generatedNumber=gen->operator ()();
    //std::cout<<generatedNumber<<std::endl;
    return generatedNumber;
}
unsigned int RandomGenerator::getRandomInt(unsigned int max){
    return gen->operator ()()%(max+1);
}
float RandomGenerator::getRandomFloat(){
    return ( (getRandomInt()*1.0f) /gen->max());
}

void RandomGenerator::randomListUI(void){
    RandomGenerator rg;
    unsigned int consoleInput;
    cout<<"Combien de nombres pseudo-aleatoires veux tu ?"<<endl;
    cout<<"Ecrivez 0 pour quitter."<<endl;

    while(consoleInput!=0 ){

        cin>>consoleInput;

        std::list<unsigned int> l=rg.getListOfRandomInt(consoleInput);

        rg.printListOfRandomInt(l);
    }
    return;
}
void RandomGenerator::compareSeedsUI(void){
    RandomGenerator* rg;

    for(int i=0;i<20;++i ){

        rg = new RandomGenerator;

        cout<<" seed : "<<rg->getSeed()<<endl;

    }
    return;
}

void RandomGenerator::test(void){
    RandomGenerator* rg;
    rg = new RandomGenerator;
    int results[43];
    for(int i=0;i<43;++i){
        results[i]=0;
    }
    for(int i=0;i<9000;++i ){


        results[rg->getRandomInt() % (41)]++;
    }
    for(int i=0;i<43;++i){
        cout<<i<<" : "<<results[i]<<endl;
    }
    return;
}

//
unsigned int RandomGenerator::getSeed()
{
    return this->seed;
}

std::list<unsigned int> RandomGenerator::getListOfRandomInt(unsigned int n){
    std::list<unsigned int> listeRandom;
    for(unsigned int i=0; i<n ; ++i){
        listeRandom.push_back(getRandomInt());
    }

   return listeRandom;
}


std::list<unsigned int> RandomGenerator::printListOfRandomInt(std::list<unsigned int> listeRandom){

    std::list<unsigned int>::const_iterator lit (listeRandom.begin()), lend(listeRandom.end());
      for(;lit!=lend;++lit) {
          std::cout << *lit << ' ';
      }
      std::cout << std::endl;

      return listeRandom;
}
