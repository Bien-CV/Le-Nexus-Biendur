#ifndef IMGGEN_H
#define IMGGEN_H
#include "lodepng.h"
#include <iostream>
#include <string>
#include <vector>
#include "color.h"
#include "randomgenerator.h"
#include "image.h"
#include "toolbox.h"

using namespace std;

class ImgGen
{

    RandomGenerator rg;

public:
    ImgGen();
    void encodeOneStep(const char *filename, std::vector<unsigned char> &Image, unsigned width, unsigned height);
    void encodeTwoSteps(const char *filename, std::vector<unsigned char> &Image, unsigned width, unsigned height);
    void randomSample();
    bool isInSqr(unsigned x, unsigned y, unsigned centerX, unsigned centerY, unsigned radius);
    void genCircle();
    Image &SBSinit(unsigned width,unsigned height);
    void SBSout(Image &Image);
    void genColorMini();
    void UIStart();
    void genColor(unsigned width, unsigned height);
    void genColorUI();
    void RGBPixel(Image &img, Color c, unsigned x, unsigned y);
    Image &fillRays(Image &img);
    Image &fillMonochrome(Image &img, int hue);
    void SBSout(Image &image, int hue);
    Image &fillColor(Image &img, Color baseColor);
    std::list<Color> &listMonochrome(int hue, unsigned resolution);
    Image &fillDarkMonochrome(Image &img, int hue);
    std::list<Color> &listDarkMonochrome(int hue, unsigned resolution);
    Image &fillLightMonochrome(Image &img, int hue);
};

#endif // IMGGEN_H
