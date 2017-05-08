#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

class Image
{
public:
    std::vector<unsigned char> data;
    unsigned width;
    unsigned height;
    Image();
};

#endif // IMAGE_H
