#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <iostream>

using namespace std;

class Toolbox
{
public:
    Toolbox();
    showWelcomeMessage(char* name);
};

int askForIntParameter(string message);

#endif // TOOLBOX_H
