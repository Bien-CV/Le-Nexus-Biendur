#ifndef COLOR_H
#define COLOR_H

#include "randomgenerator.h"

class Color
{
public:
    int H;
    float S;
    float L;

    unsigned char R;
    unsigned char G;
    unsigned char B;

    unsigned char A;
    Color(unsigned char r,unsigned char g,unsigned char b,unsigned char a);
    Color(unsigned int h,float s,float l,unsigned char a);

    void updateRGBvaluesFromHSL();
    Color(RandomGenerator *rg);
    Color(RandomGenerator *rg, unsigned int hue);
    Color(RandomGenerator *rg, float lightness);
    Color(RandomGenerator *rg, float lightness, float saturation);
    Color(RandomGenerator *rg, float lightness, float saturation, unsigned int hue, unsigned int variation);
    Color(RandomGenerator *rg, Color c, unsigned int variation);
    void alterLightness(RandomGenerator *rg, unsigned int variation);
    void alterSaturation(RandomGenerator *rg, unsigned int variation);
    void alterHue(RandomGenerator *rg, unsigned int variation);
    void incHue(RandomGenerator *rg, unsigned int variation);
    void setH(int h);
    void setS(float s);
    void setL(float l);
private:
    float HueToRGB(float v1, float v2, float vH);
};

#endif // COLOR_H
