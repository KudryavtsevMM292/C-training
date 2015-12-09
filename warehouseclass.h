#include <vector>
#include <typeinfo>
#include "itemclass.h"

class warehouse
{
private:
    std::vector<itemgeneric*> cargo;
public:
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

void warehouse::additem()
{
    int t;
    std::cout << "Enter new item type(1,2 or 3)\n";
    std::cin >> t;
    itemgeneric* newitem;
    switch (t)
      {
       case 1:{item1factory factory;
               newitem=factory.createitem();  //had to create here (instead of after switch) because factory object is local       
               break;
              } 
       case 2:{item2factory factory;
               newitem=factory.createitem();               
               break;
              } 
       case 3:{item3factory factory;
               newitem=factory.createitem();               
               break;
              } 
       default:std::cout << "Invalid value. Command aborted.\n";
               std::cin.clear();
               return;
      } 
    newitem->setprops();
    cargo.push_back(newitem);
    std::cout << "Input accepted\n";  
}

void warehouse::delitem(unsigned int index)
{
    cargo.erase(cargo.begin()+index);
}

void warehouse::moditem(unsigned int index)
{
    cargo[index]->setprops();
}

void warehouse::save()
{
    std::string userinp;
    std::cout << "Enter file name without extension (for example: data1)\n";
    std::cin >> userinp;
    userinp+=".txt";
    for (unsigned int i=0; i<cargo.size(); i++)
       {
            itemgeneric* p=cargo[i];
            if (typeid(*p)==typeid(item1)) dynamic_cast<item1*>(p);
            if (typeid(*p)==typeid(item2)) dynamic_cast<item2*>(p);
            if (typeid(*p)==typeid(item3)) dynamic_cast<item3*>(p);
            p->savetofile(userinp);
       }      
}

void warehouse::load()
{
    std::string userinp;
    std::cout << "Enter file name without extension (for example: data1)\n";
    std::cin >> userinp;
    userinp+=".txt";
    std::ifstream curfile;
    curfile.open(userinp.c_str());
    if (curfile.is_open())
      {
         cargo.clear();
         std::string line;
         while (curfile)
         {
            itemgeneric* newitem;
            getline(curfile,line);
            if (line=="item1")
            {
               item1factory factory;
               newitem=factory.createitem();
            }
            else if (line=="item2")
            {
               item2factory factory;
               newitem=factory.createitem();
            }
            else if (line=="item3")
            {
               item3factory factory;
               newitem=factory.createitem();
            }
            else if (line=="") continue;        //ignores one empty string at the end of file created with warehouse::save()
            else
            {
               std::cout << "File is corrupted, command aborted\n";
               curfile.close();
               cargo.clear();
               return;
            }
            newitem->loadfromfile(curfile);
            cargo.push_back(newitem);         
         }
         curfile.close();          
      }
      else std::cout << "Unable to open file\n";     
}

void warehouse::printall()
{
    for (unsigned int i=0; i<cargo.size(); i++)
       {
            itemgeneric* p=cargo[i];
            if (typeid(*p)==typeid(item1)) dynamic_cast<item1*>(p);
            if (typeid(*p)==typeid(item2)) dynamic_cast<item2*>(p);
            if (typeid(*p)==typeid(item3)) dynamic_cast<item3*>(p);
            p->getprops();
       }    
}

void warehouse::printhelp()
{
    std::cout << "Command line instructions:\n";
    std::cout << "  add: append new element to the database\n";
    std::cout << "  mod_by_number: edit database element with specified number\n";
    std::cout << "  del_by_number: delete database element with specified number\n";
    std::cout << "  save: saves current database to disk\n";
    std::cout << "  load: loads database from disk\n";
    std::cout << "  print: display contents of the current database\n";
    std::cout << "  exit: terminate the program\n";
    std::cout << std::endl;    
}