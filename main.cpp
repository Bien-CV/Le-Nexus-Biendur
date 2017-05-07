#include <QCoreApplication>
#include <iostream>
#include <rpggame.h>
#include <randomgenerator.h>

using namespace std;

int main(int argc, char *argv[])
{
    bool exiting = false;
    string consoleInput;
    QCoreApplication a(argc, argv);
    cout<<"Bienvenue dans le nexus bien dur"<<endl;

    while(!exiting){
        cout<<"1- rpg"<<endl;
        cout<<"2- rdlist"<<endl;
        cout<<"3- exit"<<endl;
        cout<<"<";
        getline(cin, consoleInput);
        if(consoleInput=="3"){
            exiting=true;
            exit(0);
        }
        if(consoleInput=="1"){
            RPGGame game;
            game.start();
        }
        if(consoleInput=="2"){
            RandomGenerator rg;
            rg.getRandomInt();
            rg.randomListUI();
        }
    }
    return a.exec();
}
