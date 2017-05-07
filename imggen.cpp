#include "imggen.h"
#include <sstream>

ImgGen::ImgGen()
{

}

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void ImgGen::encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

//Example 2
//Encode from raw pixels to an in-memory PNG file first, then write it to disk
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void ImgGen::encodeTwoSteps(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
  std::vector<unsigned char> png;

  unsigned error = lodepng::encode(png, image, width, height);
  if(!error) lodepng::save_file(png, filename);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

//saves random image to directory.
void ImgGen::randomSample()
{
  std::cout<<"ImgGenStarting"<<std::endl;
  //NOTE: this sample will overwrite files without warning!
  const char* filename = "random.png";

  //generate some image
  unsigned width = 1920, height = 1080;
  std::vector<unsigned char> image;
  image.resize(width * height * 4);
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++)
  {
    //Red channel
    image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
    //Green channel
    image[4 * width * y + 4 * x + 1] = rg.getRandomInt()%255* !(x & y);
    //Blue channel
    image[4 * width * y + 4 * x + 2] = x | y;
    //Alpha channel
    image[4 * width * y + 4 * x + 3] = 255;
  }

  encodeOneStep(filename, image, width, height);
}
bool ImgGen::isInCircle(unsigned x, unsigned y , unsigned centerX, unsigned centerY, unsigned radius){
    if(x==centerX){
        if(y==centerY){
            return true;
        }
    }
    return false;
}

void ImgGen::gen()
{
  std::cout<<"ImgGenStarting"<<std::endl;
  //NOTE: this sample will overwrite files without warning!

  //string filenameBuffer= "random"+rg.getSeed()+".png";
  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Making" << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  //generate some image
  unsigned width = 1920, height = 1080;
  std::vector<unsigned char> image;
  image.resize(width * height * 4);
  //first pass
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++)
  {
    //Red channel
    image[4 * width * y + 4 * x + 0] = 0;
    //Green channel
    image[4 * width * y + 4 * x + 1] = 0;
    //Blue channel
    image[4 * width * y + 4 * x + 2] = 0;
    //Alpha channel
    image[4 * width * y + 4 * x + 3] = 0;
  }

  //second pass
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++)
  {
    if(isInCircle(x,y,width/2,height/2,20)){
        //Red channel
        image[4 * width * y + 4 * x + 0] = rg.getRandomInt()%255;
        //Green channel
        image[4 * width * y + 4 * x + 1] = rg.getRandomInt()%255;
        //Blue channel
        image[4 * width * y + 4 * x + 2] = rg.getRandomInt()%255;
        //Alpha channel
        image[4 * width * y + 4 * x + 3] = 255;
    }
  }

  encodeOneStep(filename, image, width, height);
}
