#include "imggen.h"
#include <sstream>
#define WID 1920
#define HEI 1080

//TODO : getRandomPixelCoordinates
//TODO : drawColorsFrom(std::list<Color> colorList)

ImgGen::ImgGen()
{

}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void ImgGen::encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

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

Image & ImgGen::fillRays(Image & img)
{

  Color baseColor(&rg);
  for(unsigned x = 0; x < img.width; x++)
  {
      Color c(&rg,baseColor,15);
      for(unsigned y = 0; y < img.height; y++)
      {
            RGBPixel(img,c,x,y);
            baseColor=c;
      }
  }
  return img;
}

Image & ImgGen::fillColor(Image & img,Color baseColor)
{


  for(unsigned x = 0; x < img.width; x++)
  {
      for(unsigned y = 0; y < img.height; y++)
      {
            RGBPixel(img,baseColor,x,y);
      }
  }
  return img;
}

Image & ImgGen::fillMonochrome(Image & img,int hue)
{

  Color c(hue,1.0f,1.0f,255);
  Color cy(hue,1.0f,1.0f,255);
  for(unsigned x = 0; x < img.width; x++)
  {
      cy=c;
      for(unsigned y = 0; y < img.height; y++)
      {

            RGBPixel(img,cy,x,y);
            cy.setS(cy.S-(1.0f/img.height));
      }


      c.setL(c.L-(1.0f/img.width));


  }

  return img;
}
Image & ImgGen::fillDarkMonochrome(Image & img,int hue)
{

  Color c(hue,1.0f,0.5f,255);
  Color cy(hue,1.0f,0.5f,255);
  for(unsigned x = 0; x < img.width; x++)
  {
      cy=c;
      for(unsigned y = 0; y < img.height; y++)
      {

            RGBPixel(img,cy,x,y);
            cy.setS(cy.S-(1.0f/img.height));
      }


      c.setL(c.L-(0.5f/img.width));


  }

  return img;
}

Image & ImgGen::fillLightMonochrome(Image & img,int hue)
{

  Color c(hue,1.0f,0.5f,255);
  Color cy(hue,1.0f,0.5f,255);
  for(unsigned x = 0; x < img.width; x++)
  {
      cy=c;
      for(unsigned y = 0; y < img.height; y++)
      {

            RGBPixel(img,cy,x,y);
            cy.setS(cy.S-(1.0f/img.height));
      }


      c.setL(c.L+(0.5f/img.width));


  }

  return img;
}

//TODO: check if working or not
std::list<Color>& ImgGen::listMonochrome(int hue,unsigned resolution)
{
  std::list<Color>* colorList=new std::list<Color>() ;
  std::list<Color> & ref=*colorList;
  Color c(hue,1.0f,1.0f,255);
  Color cy(hue,1.0f,1.0f,255);
  for(unsigned x = 0; x < resolution; x++)
  {
      cy=c;
      for(unsigned y = 0; y < resolution; y++)
      {
            colorList->push_back(cy);
            cy.setS(cy.S-(1.0f/resolution));
      }


      c.setL(c.L-(1.0f/resolution));


  }

  return ref;
}

//TODO: check if working or not
std::list<Color>& ImgGen::listDarkMonochrome(int hue,unsigned resolution)
{
  std::list<Color>* colorList=new std::list<Color>() ;
  std::list<Color> & ref=*colorList;
  Color c(hue,1.0f,0.5f,255);
  Color cy(hue,1.0f,0.5f,255);
  for(unsigned x = 0; x < resolution; x++)
  {
      cy=c;
      for(unsigned y = 0; y < resolution; y++)
      {
            colorList->push_back(cy);
            cy.setS(cy.S-(1.0f/resolution));
      }


      c.setL(c.L-(0.5f/resolution));


  }

  return ref;
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
        cout<<"2- successive steps"<<endl;
        cout<<"3- Monochrome"<<endl;
        cout<<"4- Dark monochrome"<<endl;
        cout<<"5- Light monochrome"<<endl;

        cout<<"<";
        getline(cin, consoleInput);
        if(consoleInput=="0"){
            exiting=true;
            exit(0);
        }
        if(consoleInput=="1"){
            genColorUI();
        }
        if(consoleInput=="2"){
            int width = askForIntParameter("Width?");
            int height = askForIntParameter("Height?");
            int nbOfImages = askForIntParameter("How many images do you want to generate?");
            for (int i=0;i<nbOfImages;++i){
                SBSout(fillRays(SBSinit(width,height)));
                rg.Reseed();
            }
        }
        if(consoleInput=="3"){
            int width = askForIntParameter("Width?");
            int height = askForIntParameter("Height?");
            int hue = askForIntParameter("Hue?");
            SBSout(fillMonochrome(SBSinit(width,height),hue),hue);
        }
        if(consoleInput=="4"){
            int width = askForIntParameter("Width?");
            int height = askForIntParameter("Height?");
            int hue = askForIntParameter("Hue?");
            SBSout(fillDarkMonochrome(SBSinit(width,height),hue),hue);
        }
        if(consoleInput=="5"){
            int width = askForIntParameter("Width?");
            int height = askForIntParameter("Height?");
            int hue = askForIntParameter("Hue?");
            SBSout(fillLightMonochrome(SBSinit(width,height),hue),hue);
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

void ImgGen::SBSout(Image & image)
{
  std::stringstream buffer;
  buffer << std::to_string(rg.getSeed()) << ".png";

  std::cout<< "Generated " << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  encodeOneStep(filename, image.image, image.width, image.height);
}

void ImgGen::SBSout(Image & image,int hue)
{
  std::stringstream buffer;
  buffer << "Images\\" <<image.width<<"x"<<image.height<<"hue"<< hue << ".png";

  std::cout<< "Generated " << buffer.str().c_str() <<std::endl;

  const char* filename = buffer.str().c_str();

  encodeOneStep(filename, image.image, image.width, image.height);
}
