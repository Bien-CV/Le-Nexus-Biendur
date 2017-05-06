#include "randomgenerator.h"


RandomGenerator::RandomGenerator()
{
    std::random_device rd;
    this->seed=rd();
    this->gen.seed(seed);
}

RandomGenerator::RandomGenerator(unsigned int userSeed)
{
    this->seed=userSeed;
    this->gen.seed(seed);
}

unsigned int RandomGenerator::getRandomInt(){
     return this->gen();
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
