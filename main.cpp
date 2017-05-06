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
        cout<<"<";
        getline(cin, consoleInput);
        if(consoleInput=="exit"){
            exiting=true;
            exit(0);
        }
        if(consoleInput=="rpg"){
            RPGGame game;
            game.start();
        }
    }
    return a.exec();
}
