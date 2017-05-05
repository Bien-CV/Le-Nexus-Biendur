#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    bool exiting = false;
    string consoleInput;
    QCoreApplication a(argc, argv);
    std::cout<<"Bienvenue dans le nexus bien dur."<<endl;

    while(!exiting){
        cout<<"<";
        cin>>consoleInput;
    }
    return a.exec();
}
