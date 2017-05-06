#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <random>

class RandomGenerator
{
unsigned int seed;
std::mt19937 gen;

public:
    RandomGenerator();
    getRandomInt();
};

#endif // RANDOMGENERATOR_H
