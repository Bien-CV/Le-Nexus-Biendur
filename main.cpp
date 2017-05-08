#include <QCoreApplication>
#include <iostream>
#include <rpggame.h>
#include <randomgenerator.h>
#include <imggen.h>

using namespace std;

int main(int argc, char *argv[])
{
    bool exiting = false;
    string consoleInput;
    QCoreApplication a(argc, argv);
    cout<<"Bienvenue dans le nexus bien dur"<<endl;

    while(!exiting){
        cout<<"0- exit"<<endl;
        cout<<"1- rpg"<<endl;
        cout<<"2- rdlist"<<endl;
        cout<<"3- imggen"<<endl;
        cout<<"4- compareSeeds"<<endl;
        cout<<"5- testRandom"<<endl;

        cout<<"<";
        getline(cin, consoleInput);
        if(consoleInput=="0"){
            exiting=true;
            exit(0);
        }
        if(consoleInput=="1"){
            RPGGame game;
            game.start();
        }
        if(consoleInput=="2"){
            RandomGenerator rg;
            rg.randomListUI();
        }
        if(consoleInput=="3"){
            ImgGen imgGen;
            imgGen.UIStart();
        }
        if(consoleInput=="4"){
            RandomGenerator rg;
            rg.compareSeedsUI();
        }
        if(consoleInput=="5"){
            RandomGenerator rg;
            rg.test();
        }


    }
    return a.exec();
}
