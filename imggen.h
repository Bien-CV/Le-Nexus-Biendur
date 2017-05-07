#ifndef IMGGEN_H
#define IMGGEN_H
#include "lodepng.h"
#include <iostream>
#include <string>
#include <vector>
#include "randomgenerator.h"

class ImgGen
{
    RandomGenerator rg;

public:
    ImgGen();
    void encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height);
    void encodeTwoSteps(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height);
    void randomSample();
    void gen();
    bool isInCircle(unsigned x, unsigned y, unsigned centerX, unsigned centerY, unsigned radius);
};

#endif // IMGGEN_H
