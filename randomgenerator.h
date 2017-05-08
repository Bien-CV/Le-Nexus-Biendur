#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <random>
#include <list>
#include <iostream>
#include <chrono>


class RandomGenerator
{

public:
    std::minstd_rand0 gen;
    unsigned int seed;

    RandomGenerator();
    RandomGenerator(unsigned int userSeed);
    unsigned int getRandomInt();
    std::list<unsigned int> getListOfRandomInt(unsigned int n);
    std::list<unsigned int> printListOfRandomInt(std::list<unsigned int> listeRandom);
    void randomListUI(void);
    unsigned int getSeed();
    void compareSeedsUI();
    float getRandomFloat();
    void test();
    unsigned int getRandomInt(unsigned int max);
};

#endif // RANDOMGENERATOR_H
