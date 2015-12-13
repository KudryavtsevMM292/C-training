#ifndef ITEMBASECLASS_H
#define ITEMBASECLASS_H

#include "Input_Output.h"
using namespace std;

class item
{   
  public: 
    virtual void setprops()=0;
    virtual void getprops()=0;
    virtual void savetofile(string fname)=0;
    virtual void loadfromfile(ifstream& tfile)=0;
};

#endif