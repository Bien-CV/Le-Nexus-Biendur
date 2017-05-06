#include "prsn.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Prsn::Prsn() : playability(0)
{
    string answer;
    cout << "Welcome to Kult's character creation !" << endl << "Is this character a NPC ?" << endl << "Y/N : ";
    cin >> answer;
    if (answer=="y" || answer=="Y")
    {
        cout<<"ok1";
    }
    else if (answer=="n" || answer=="N")
    {
        cout<<"ok2";
    }
    else
    {
        cout << "Please press either Y or N.";
    }
}
