#ifndef IMGGEN_H
#define IMGGEN_H
#include "lodepng.h"
#include <iostream>
#include <string>
#include <vector>
#include "color.h"
#include "randomgenerator.h"
#include "image.h"

class ImgGen
{
    RandomGenerator rg;

public:
    ImgGen();
    void encodeOneStep(const char *filename, std::vector<unsigned char> &Image, unsigned width, unsigned height);
    void encodeTwoSteps(const char *filename, std::vector<unsigned char> &Image, unsigned width, unsigned height);
    void randomSample();
    bool isInSqr(unsigned x, unsigned y, unsigned centerX, unsigned centerY, unsigned radius);
    void genColor();
    void genCircle();
    std::vector<unsigned char> SBSinit();
    void SBSout(Image Image);
    void genColorMini();
};

#endif // IMGGEN_H
