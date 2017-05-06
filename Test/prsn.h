#ifndef PRSN_H
#define PRSN_H

#include "gm.h"

class Prsn
{
    /*Liste skills
     * Liste currentWounds
     * Liste maxWounds
     * Liste magic*/
    int actionsPerRound;
    int movement;
    int initiative;

    bool playability;  //0=non joué  1=joué
    std::string playerName;
    std::string name;
    std::string surname;
    int age;
    int height;
    int weight;
    int overload;
    int initiativeBM;
    int dmgBM;
    int egoBM;
    std::string profession;
    std::string employer;
    int livingStandard;
    int savings;
    int netIncomeAvailable;
    int monthlyIncome;
    int maxCredit;
    int mentalBalance;
    std::string mentality;
    std::string darkSecrets;
    std::string relationships;
    int expPts;
    int heroPts;

public:
    Prsn();
    void CreateChar(bool);
    void SetBasicInfo();
    void SetCaracteristics();
    void SetMoney();
    void SetMentalInfos();
};

#endif // PRSN_H
