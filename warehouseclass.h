#include <iostream>
#include <sstream>
#include <fstream>
#include "itemclass.h"

class warehouse
{
private:
    unsigned int cap;
    unsigned int count;
    item *cargo;
public:
    warehouse ();
    ~warehouse () {delete [] cargo;}
    bool isempty() {return (count==0);}
    unsigned int getcount() {return count;}
    unsigned int getcap() {return cap;}    
    void expand();
    void additem();
    void moditem(unsigned int index);
    void delitem(unsigned int index);
    void save();
    void load();
    void printall();
    void printhelp();    
};

warehouse::warehouse()
{
    cap=50;
    count=0;
    cargo=new item[cap];
}

void warehouse::expand()
{
    item *temp;
    temp=new item[cap*2];
    for (unsigned int i=0; i<cap ;i++)
        temp[i]=cargo[i];
    delete [] cargo;
    cap*=2;
    cargo=temp; 
}

void warehouse::additem()
{
    std::string userinp;
    std::cout << "Enter new element id\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[count].id;
    
    std::cout << "Enter new element name\n";
    std::cin >> userinp;
    cargo[count].name=userinp;
    
    std::cout << "Enter new element property 1 (floating-point value)\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[count].value1;
    
    std::cout << "Enter new element property 2 (single symbol value)\n";
    std::cin >> cargo[count].value2;
    
    std::cout << "Enter new element quantity\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[count].quan;

    std::cout << "Input accepted\n";
    count++;    
}

void warehouse::delitem(unsigned int index)
{
    for(unsigned int i=index; i<count-1; i++)
        cargo[i]=cargo[i+1];
    count--;
}

void warehouse::moditem(unsigned int index)
{
    std::string userinp;
    std::cout << "Current element id is " << cargo[index].id << std::endl;
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[index].id;
    
    std::cout << "Current element name is " << cargo[index].name << std::endl;
    std::cin >> userinp;
    cargo[index].name=userinp;
    
    std::cout << "Current element property 1 is " << cargo[index].value1 << std::endl;
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[index].value1;
    
    std::cout << "Current element property 2 is " << cargo[index].value2 << std::endl;
    std::cin >> cargo[index].value2;
    
    std::cout << "Current element quantity is " << cargo[index].quan << std::endl;
    std::cin >> userinp;
    std::stringstream(userinp) >> cargo[index].quan;

    std::cout << "Input accepted\n";
}

void warehouse::save()
{
    std::string userinp;
    std::cout << "Enter file name without extension (for example: data1)\n";
    std::cin >> userinp;
    userinp+=".txt";
    std::ofstream curfile;
    curfile.open(userinp.c_str());
    if (curfile.is_open())
      {
         //curfile << "number of elements\n";
         curfile << count << "\n";
         for (unsigned int i=0; i<count; i++)
          {
            curfile << "###\n";
            //curfile << "element " << (i+1) << " id:\n";
            curfile << cargo[i].id << "\n";
            //curfile << "element " << (i+1) << " name:\n";
            curfile << cargo[i].name << "\n";
            //curfile << "element " << (i+1) << " property 1:\n";
            curfile << cargo[i].value1 << "\n";
            //curfile << "element " << (i+1) << " property 2:\n";
            curfile << cargo[i].value2 << "\n";
            //curfile << "element " << (i+1) << " quantity:\n";
            curfile << cargo[i].quan << "\n";
          } 
         curfile.close();
      }
      else std::cout << "Unable to open file\n";    
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
         std::string line;
         getline(curfile,line);                         //read number of elements
         unsigned int tempcount;
         std::stringstream(line) >> tempcount;
         unsigned int tempcap=tempcount*2;
         item *temp;                                    //temporary storage
         temp=new item[tempcap];
         unsigned int c=0;   
         for (unsigned int i=0; i<tempcount; i++)
           {
            if (!getline(curfile,line)) break;                      //read separator
            if (line=="###") c++;
            if (!getline(curfile,line)) break;                      //read id
            std::stringstream(line) >> temp[i].id;            
            if (!getline(curfile,line)) break;                      //read name
            temp[i].name=line;            
            if (!getline(curfile,line)) break;                      //read value 1
            std::stringstream(line) >> temp[i].value1;            
            if (!getline(curfile,line)) break;                      //read value 2
            temp[i].value2=line[0];            
            if (!getline(curfile,line)) break;                      //read quantity
            std::stringstream(line) >> temp[i].quan;
           } 
         curfile.close();
         if (c==tempcount)
           {
             cap=tempcap;
             count=tempcount;
             delete [] cargo;
             cargo=temp;    
           }
           else std::cout << "Data is corrupted, command aborted\n";
      }
      else std::cout << "Unable to open file\n";     
}

void warehouse::printall()
{
    for (unsigned int i=0; i<count; i++)
       {
          std::cout << "element " << (i+1) << " id: " << cargo[i].id << std::endl;
          std::cout << "element " << (i+1) << " name: " << cargo[i].name << std::endl;
          std::cout << "element " << (i+1) << " property 1: " << cargo[i].value1 << std::endl;
          std::cout << "element " << (i+1) << " property 2: " << cargo[i].value2 << std::endl;
          std::cout << "element " << (i+1) << " quantity: " << cargo[i].quan << std::endl;
          std::cout << std::endl;
       }    
}

void warehouse::printhelp()
{
    std::cout << "Element specification:\n";
    std::cout << "   id: positive integer\n";
    std::cout << "   name: string\n";
    std::cout << "   property 1: floating-point\n";
    std::cout << "   property 2: single character\n";
    std::cout << "   quantity: positive integer\n";
    std::cout << std::endl;
    std::cout << "Command line instructions:\n";
    std::cout << "add: append new element to the database\n";
    std::cout << "mod_by_number: edit database element with specified number\n";
    std::cout << "del_by_number: delete database element with specified number\n";
    std::cout << "save: saves current database to disk\n";
    std::cout << "load: loads database from disk\n";
    std::cout << "print: display contents of the current database\n";
    std::cout << "exit: terminate the program\n";
    std::cout << std::endl;    
}