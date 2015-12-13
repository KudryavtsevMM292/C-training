#include <vector>
#include "factoryclass.h"
using namespace std;

class warehouse
{
private:
    vector<item*> cargo;
public:
    ~warehouse();
    bool isempty() {return cargo.empty();}
    unsigned int getcount() {return cargo.size();}   
    void additem();
    void moditem(unsigned int index);
    void delitem(unsigned int index);
    void save();
    void load();
    void printall();
    void printhelp();    
};

warehouse::~warehouse()
{
  for (int i=0; i<cargo.size(); i++) delete cargo[i];
  cargo.clear();
}

void warehouse::additem()
{
  int t;
  cout << "Enter new item type(1,2 or 3)\n";
  while ( !(PromtValue(&t)) );
  
  itemfactory factory;
  item* newitem;
  if ( !(newitem=factory.createitem(t)) )
  {
    cout << "Invalid value. Command aborted.\n";
    cin.ignore();
    cin.clear();
    return;    
  }
  
  newitem->setprops();
  cargo.push_back(newitem);
  cout << "Input accepted\n";  
}

void warehouse::delitem(unsigned int index)
{
  delete cargo[index];
  cargo.erase(cargo.begin()+index);
}

void warehouse::moditem(unsigned int index)
{
  cargo[index]->setprops();
}

void warehouse::save()
{
    string userinp;
    cout << "Enter file name without extension (for example: data1)\n";
    while ( !(PromtValue(&userinp)) );
    userinp+=".txt";
    for (unsigned int i=0; i<cargo.size(); i++)
       {
           cargo[i]->savetofile(userinp);
       }      
}

void warehouse::load()
{
    string userinp;
    cout << "Enter file name without extension (for example: data1)\n";
    while ( !(PromtValue(&userinp)) );
    userinp+=".txt";
    ifstream curfile;
    curfile.open(userinp.c_str());
    if (curfile.is_open())
      {
         cargo.clear();
         string line;
         while (curfile)
         {
           getline(curfile,line);
           if (line=="") continue;                 //ignores one empty string at the end of file created with warehouse::save()
           
           itemfactory factory;
           item* newitem;
           if ( !(newitem=factory.createitem(line)) )
           {
             cout << "File is corrupted, command aborted\n";
             curfile.close();
             for (int i=0; i<cargo.size(); i++) delete cargo[i];             
             cargo.clear();
             return;
           }
           
           newitem->loadfromfile(curfile);        
           cargo.push_back(newitem);      
         }
         curfile.close();          
      }
      else cout << "Unable to open file\n";     
}

void warehouse::printall()
{
  for (unsigned int i=0; i<cargo.size(); i++) cargo[i]->getprops();
}

void warehouse::printhelp()
{
    cout << "Command line instructions:\n";
    cout << "  add: append new element to the database\n";
    cout << "  mod_by_number: edit database element with specified number\n";
    cout << "  del_by_number: delete database element with specified number\n";
    cout << "  save: saves current database to disk\n";
    cout << "  load: loads database from disk\n";
    cout << "  print: display contents of the current database\n";
    cout << "  exit: terminate the program\n";
    cout << endl;    
}