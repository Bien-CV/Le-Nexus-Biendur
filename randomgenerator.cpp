#include "randomgenerator.h"

//std::uniform_int_distribution<int> dist(0, 100);

//std::cout << dist(gen) << '\n';

RandomGenerator::RandomGenerator()
{
    std::random_device rd;
    this->seed=rd();
    this->gen.seed(seed);
}

RandomGenerator::getRandomInt(){
     return this->gen();
}
