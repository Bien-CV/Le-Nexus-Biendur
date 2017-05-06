#include "prsn.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Prsn::Prsn() : playability(false)
{
    string answer;
    cout << "Welcome to Kult's character creation !" << endl << "To go back, type \"exit\"" << endl << "Is this character a NPC ?" << endl << "Y/N : ";
    do
    {
        cin >> answer;
        if (answer=="y" || answer=="Y")
        {
            playability=1;
        }
        else if (answer=="n" || answer=="N")
        {
            cout<<"ok2";
        }
        else if(answer=="exit" || answer=="EXIT" || answer=="Exit")
        {
            exit(0);
        }
        else
        {
            cout << "Please press either Y or N." << endl;
        }
    }
    while (true);

}

void Prsn::SetBasicInfo()
{
    cin >> playerName;
    cin >> name;
    cin >> surname;
    cin >> age;
    cin >> height;
    cin >> weight;

    /*
    //Actions per round
    if (1<=AGL<=15)
    {
        actionsPerRound=2;
    }
    if (16<=AGL<=19)
    {
        actionsPerRound=3;
    }
    if (20<=AGL<=29)
    {
        actionsPerRound=4;
    }
    if (30<=AGL<=39)
    {
        actionsPerRound=5;
    }
    if (40<=AGL<=49)
    {
        actionsPerRound=6;
    }


    //Initiative B/M from AGL
    if (AGL==1)
    {
        initiativeBM=-7;
    }
    if (AGL==2)
    {
        initiativeBM=-6;
    }
    if (AGL==3)
    {
        initiativeBM=-5;
    }
    if (AGL==4)
    {
        initiativeBM=-4;
    }
    if (AGL==5)
    {
        initiativeBM=-3;
    }
    if (AGL==6)
    {
        initiativeBM=-2;
    }
    if (AGL==7)
    {
        initiativeBM=-1;
    }
    if (8<=AGL<=12)
    {
        initiativeBM=0;
    }
    if (AGL==13)
    {
        initiativeBM=1;
    }
    if (AGL==14)
    {
        initiativeBM=2;
    }
    if (AGL==15)
    {
        initiativeBM=3;
    }
    if (AGL==16)
    {
        initiativeBM=4;
    }
    if (AGL==17)
    {
        initiativeBM=5;
    }
    if (AGL==18)
    {
        initiativeBM=6;
    }
    if (AGL==19)
    {
        initiativeBM=7;
    }
    if (AGL==20)
    {
        initiativeBM=8;
    }


    //Damage B/M
    if (3<=(FOR+AGL)<=6)
    {
        dmgBM=-3;
    }
    if (7<=(FOR+AGL)<=10)
    {
        dmgBM=-2;
    }
    if (11<=(FOR+AGL)<=14)
    {
        dmgBM=-1;
    }
    if (15<=(FOR+AGL)<=20)
    {
        dmgBM=0;
    }
    if (21<=(FOR+AGL)<=24)
    {
        dmgBM=1;
    }
    if (25<=(FOR+AGL)<=28)
    {
        dmgBM=2;
    }
    if (29<=(FOR+AGL)<=32)
    {
        dmgBM=3;
    }
    if (33<=(FOR+AGL)<=40)
    {
        dmgBM=4;
    }
    if (41<=(FOR+AGL)<=46)
    {
        dmgBM=5;
    }
    if (47<=(FOR+AGL)<=54)
    {
        dmgBM=6;
    }
    if (55<=(FOR+AGL)<=60)
    {
        dmgBM=7;
    }


    //Ego throws B/M
    if (EGO==1)
    {
        egoBM=-7;
    }
    if (EGO==2)
    {
        egoBM=-6;
    }
    if (EGO==3)
    {
        egoBM=-5;
    }
    if (EGO==4)
    {
        egoBM=-4;
    }
    if (EGO==5)
    {
        egoBM=-3;
    }
    if (EGO==6)
    {
        egoBM=-2;
    }
    if (EGO==7)
    {
        egoBM=-1;
    }
    if (8<=EGO<=12)
    {
        egoBM=0;
    }
    if (EGO==13)
    {
        egoBM=1;
    }
    if (EGO==14)
    {
        egoBM=2;
    }
    if (EGO==15)
    {
        egoBM=3;
    }
    if (EGO==16)
    {
        egoBM=4;
    }
    if (EGO==17)
    {
        egoBM=5;
    }
    if (EGO==18)
    {
        egoBM=6;
    }
    if (EGO==19)
    {
        egoBM=7;
    }
    if (EGO==20)
    {
        egoBM=8;
    }

    movement= AGL/2;
    overload= STR;
    */
}

void Prsn::CreateChar(bool playability)
{
    if (playability==true)
    {

    }


}
