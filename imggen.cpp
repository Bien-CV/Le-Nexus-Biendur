#include "imggen.h"
#include <sstream>
#define WID 1920
#define HEI 1080

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
  unsigned width = WID, height = HEI;
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

bool ImgGen::isInSqr(unsigned x, unsigned y , unsigned centerX, unsigned centerY, unsigned radius){
    if( ( x>=centerX-radius ) && ( x<=centerX+radius ) ){
        if( ( y>=centerY-radius ) && ( y<=centerY+radius ) ){
            return true;
        }
    }
    return false;
}

void ImgGen::genColor(unsigned width,unsigned height)
{

  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Making" << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  Image im(width,height);
  Image & img=im;

  Color baseColor(&rg);
  for(unsigned x = 0; x < width; x++)
  {
      Color c(&rg,baseColor,15);
      for(unsigned y = 0; y < height; y++)
      {
            RGBPixel(img,c,x,y);
            baseColor=c;
      }
  }
  encodeOneStep(filename, img.image, img.width, img.height);
}

void ImgGen::genColorMini()
{
  std::cout<<"ImgGenStarting"<<std::endl;
  //NOTE: this sample will overwrite files without warning!

  //string filenameBuffer= "random"+rg.getSeed()+".png";
  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Making" << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  //generate some image
  unsigned width = WID, height = HEI;
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
    /*
    unsigned int hue =rg.getRandomInt()%360;
    float lightness=0.5f;
    float saturation=1.0f;
    */
  Color baseColor(0,1.0f,0.5f,255);
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++)
  {
        Color c(&rg,baseColor,10);
        //Red channel
        image[4 * width * y + 4 * x + 0] = c.R;
        //Green channel
        image[4 * width * y + 4 * x + 1] = c.G;
        //Blue channel
        image[4 * width * y + 4 * x + 2] = c.B;
        //Alpha channel
        image[4 * width * y + 4 * x + 3] = c.A;
        baseColor=c;
  }
  encodeOneStep(filename, image, width, height);
}

Image & ImgGen::SBSinit(unsigned width,unsigned height)
{
    Image* img=new Image(width,height);
    Image & image=*img;

  return image;
}

void ImgGen::RGBPixel(Image & img,Color c, unsigned x,unsigned y){


    //Red channel
    img.image[4 * img.width * y + 4 * x + 0] = c.R;
    //Green channel
    img.image[4 * img.width * y + 4 * x + 1] = c.G;
    //Blue channel
    img.image[4 * img.width * y + 4 * x + 2] = c.B;
    //Alpha channel
    img.image[4 * img.width * y + 4 * x + 3] = c.A;
}

void ImgGen::UIStart(void){
    cout<<"Welcome to the Image Generator command interface."<<endl;


    bool exiting = false;
    string consoleInput;

    while(!exiting){
        cout<<"0- exit"<<endl;
        cout<<"1- genColor"<<endl;
        cout<<"2- "<<endl;
        cout<<"3- "<<endl;
        cout<<"4- "<<endl;
        cout<<"5- "<<endl;

        cout<<"<";
        getline(cin, consoleInput);
        if(consoleInput=="0"){
            exiting=true;
            exit(0);
        }
        if(consoleInput=="1"){
            genColorUI();
        }
    }
}
void ImgGen::genColorUI(void){
    int width = askForIntParameter("Width?");
    int height = askForIntParameter("Height?");
    int nbOfImages = askForIntParameter("How many images do you want to generate?");
    for (int i=0;i<nbOfImages;++i){
        genColor(width,height);
        rg.Reseed();
    }
}

void ImgGen::SBSout(Image image)
{
  //NOTE: this sample will overwrite files without warning!

  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Generated " << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  encodeOneStep(filename, image.image, image.width, image.height);
}


void ImgGen::genCircle()
{
  std::cout<<"ImgGenStarting"<<std::endl;
  //NOTE: this sample will overwrite files without warning!

  //string filenameBuffer= "random"+rg.getSeed()+".png";
  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Making" << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  //generate some image
  unsigned width = WID, height = HEI;
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
    if(isInSqr(x,y,width/2,height/2,20)){
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
