#ifndef COLOR_H
#define COLOR_H

#include "randomgenerator.h"

//Hybrid RGBa/HSLa color class.
//Values are automatically updated when a change is made to the color.
//LABCIE colors are better to work with for image manipulation, but HSL is easier to fully understand and remember.
//Reasons why HSL and HSV aren't ideal can be found following this Wikipedia link : https://en.wikipedia.org/wiki/HSL_and_HSV
class Color
{
    //Used internally by updateRGBvaluesFromHSL()
    float HueToRGB(float v1, float v2, float vH);

    //The hue of the color.
    //Angle in degrees in the color wheel.
    //0° is red, 180° is cyan, 360° is the same as 0°.
    //Usually between 0 and 359. 0° is preferred to 360°.
    int H;
    //The saturation of the color.
    //Between 0.0f and 1.0f.
    //At 0, the color is fully-desaturated, the color is gray, white or black.
    //At 1, the color can be a bright color, saturated dark or light tints, white or black.
    float S;
    //The lightness of the color.
    //Between 0.0f and 1.0f.
    //At 0, the color is black independently of hue and saturation.
    //At 1, the color is white independently of hue and saturation.
    //At 0.5, the color is bright red if H==0 and S==1.0f, medium gray if S==0.0f .
    float L;

    //The red component of the color.
    unsigned char R;
    //The green component of the color.
    unsigned char G;
    //The blue component of the color.
    unsigned char B;

    //The alpha component of the color on one byte.
    unsigned char A;


    public:
    //Makes a color from RGBa values
    Color(unsigned char r,unsigned char g,unsigned char b,unsigned char a);
    //Makes a color from HSLa values
    Color(unsigned int h,float s,float l,unsigned char a);
    //Makes a random opaque color from HSL values converted to RGB.
    Color(RandomGenerator *rg);
    //Makes a random opaque color of the desired hue from HSL values converted to RGB.
    Color(RandomGenerator *rg, unsigned int hue);
    //Makes a random opaque color of the desired lightness from HSL values converted to RGB.
    Color(RandomGenerator *rg, float lightness);
    //Makes a random opaque color of the desired lightness and saturation from HSL values converted to RGB.
    Color(RandomGenerator *rg, float lightness, float saturation);
    Color(RandomGenerator *rg, Color c, unsigned int variation);

    void alterLightness(RandomGenerator *rg, unsigned int variation);
    void alterSaturation(RandomGenerator *rg, unsigned int variation);
    void alterHue(RandomGenerator *rg, unsigned int variation);
    void incHue(RandomGenerator *rg, unsigned int variation);

    void setH(int h);
    void setS(float s);
    void setL(float l);
    void setA(unsigned char a);
    void setR(unsigned char r);
    void setG(unsigned char g);
    void setB(unsigned char b);

    int getH();
    float getS();
    float getL();
    unsigned char getA();
    unsigned char getR();
    unsigned char getG();
    unsigned char getB();

    void updateHSLvaluesFromRGB();
    void updateRGBvaluesFromHSL();
    void makeHueValid();
};

#endif // COLOR_H
