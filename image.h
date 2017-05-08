#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

class Image
{
public:
    std::vector<unsigned char> image;
    unsigned width;
    unsigned height;
    Image(unsigned aWidth, unsigned anHeight);
};

#endif // IMAGE_H
