#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <random>
#include <list>
#include <iostream>

class RandomGenerator
{
unsigned int seed;
std::mt19937 gen;

public:
    RandomGenerator();
    RandomGenerator(unsigned int userSeed);
    unsigned int getRandomInt();
    std::list<unsigned int> getListOfRandomInt(unsigned int n);
    std::list<unsigned int> printListOfRandomInt(std::list<unsigned int> listeRandom);
};

#endif // RANDOMGENERATOR_H
