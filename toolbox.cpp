#include "toolbox.h"

Toolbox::Toolbox()
{

}

int askForIntParameter(string message)
{
    cout<<message<<endl;
    int parameter;
    cin>>parameter;
    return parameter;
}

