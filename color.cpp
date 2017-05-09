#include "color.h"
using namespace std;

//TODO: std::list<Color> generateAnalogousTheme(Color baseColor,unsigned hueDistance)

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    R=r;
    G=g;
    B=b;
    A=a;
}


float Color::HueToRGB(float v1, float v2, float vH) {
    if (vH < 0)
        vH += 1;

    if (vH > 1)
        vH -= 1;

    if ((6 * vH) < 1)
        return (v1 + (v2 - v1) * 6 * vH);

    if ((2 * vH) < 1)
        return v2;

    if ((3 * vH) < 2)
        return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

    return v1;
}

Color::Color(unsigned int h, float s, float l, unsigned char a)
{
    H=h;
    S=s;
    L=l;
    A=a;

    //Convert values to RGB
    updateRGBvaluesFromHSL();

}

void Color::updateRGBvaluesFromHSL(){
    if (S == 0)
    {
        R = G = B = (unsigned char)(L * 255);
    }
    else
    {
        float v1, v2;
        float hue = (float)H / 360;

        v2 = (L < 0.5) ? (L * (1 + S)) : ((L + S) - (L * S));
        v1 = 2 * L - v2;

        R = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
        G = (unsigned char)(255 * HueToRGB(v1, v2, hue));
        B = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
    }
}

Color::Color(RandomGenerator* rg)
{

    H=rg->getRandomInt()%359;
    S=rg->getRandomFloat();
    L=rg->getRandomFloat();
    A=255;

    updateRGBvaluesFromHSL();
}

//fixed hue
Color::Color(RandomGenerator* rg, unsigned int hue)
{

    H=hue;
    S=rg->getRandomFloat();
    L=rg->getRandomFloat();
    A=255;

    updateRGBvaluesFromHSL();
}

//fixed Lightness
Color::Color(RandomGenerator* rg,float lightness)
{

    H=rg->getRandomInt(359);
    S=rg->getRandomFloat();
    L=lightness;
    A=255;

    updateRGBvaluesFromHSL();
}

//fixed Lightness, fixed saturation
Color::Color(RandomGenerator* rg,float lightness,float saturation)
{

    H=rg->getRandomInt(359);
    S=saturation;
    L=lightness;
    A=255;

    updateRGBvaluesFromHSL();
}

//fixed Lightness, fixed saturation, random hue from centered hue
Color::Color(RandomGenerator* rg,float lightness,float saturation,unsigned int hue, unsigned int variation)
{

    H=hue + (rg->getRandomInt(variation));
    S=saturation;
    L=lightness;
    A=255;

    updateRGBvaluesFromHSL();
}
//Color close to the c parameter
Color::Color(RandomGenerator* rg,Color c,unsigned int variation)
{

    H=c.H;
    S=c.S;
    L=c.L;
    A=c.A;

    alterHue(rg,variation);
    alterLightness(rg,variation);
    alterSaturation(rg,variation);

    updateRGBvaluesFromHSL();
}


void Color::alterHue(RandomGenerator* rg, unsigned int variation){
    int intensity= rg->getRandomInt(variation*2) -variation;
    intensity/=2;
    H+=intensity;

    if ( H>360 ) H=H%360;
    if ( H<0 ) H=360-(abs(H)%360);
}
void Color::incHue(RandomGenerator* rg, unsigned int variation){
    int intensity= rg->getRandomInt(variation);
    intensity/=2;
    H=H+intensity;

    if ( H>360 ) H=H%360;
    if ( H<0 ) H=360-(abs(H)%360);
}

void Color::setH(int h)
{
    H=h;
    updateRGBvaluesFromHSL();
}

void Color::setS(float s)
{
    S=s;
    updateRGBvaluesFromHSL();
}

void Color::setL(float l)
{
    L=l;
    updateRGBvaluesFromHSL();
}

void Color::alterLightness(RandomGenerator* rg, unsigned int variation){
    //mult is in [-variation,variation]
    int mult= ( rg->getRandomInt(variation*2)) -variation;
    //cout<<"mult "<<mult<<endl;
    //mult/=3;
    float intensity= mult*1.0f;
    intensity/=1000;
    //cout<<"inten "<<intensity<<endl;
    L+=intensity;
    if ( L>1.0f ) L=1.0f;
    if ( L<0.0f ) L=0.0f;
}

void Color::alterSaturation(RandomGenerator* rg, unsigned int variation){
    int mult= ( rg->getRandomInt(variation*2)) -variation;
    mult/=4;
    float intensity= 0.01f * mult;
    S+=intensity;

    if ( S>1.0f ) S=1.0f;
    if ( S<0.0f ) S=0.0f;
}
