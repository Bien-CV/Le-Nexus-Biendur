#include "image.h"

Image::Image(unsigned aWidth,unsigned anHeight)
{
    width=aWidth;
    height=anHeight;
    image.resize(width * height * 4);
}
