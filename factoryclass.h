#include "item1class.h"
#include "item2class.h"
#include "item3class.h"
using namespace std;

class itemfactory
{
  public:
    item* createitem(int type);
    item* createitem(string type);
};

item* itemfactory::createitem(int type)
{
  switch (type)
  {
    case 1:return new item1;
    case 2:return new item2;
    case 3:return new item3;
    default:return 0;
  }   
}

item* itemfactory::createitem(string type)
{
  if (type=="item1") return new item1;
  else if (type=="item2") return new item2;
  else if (type=="item3") return new item3;
  else return 0;
}