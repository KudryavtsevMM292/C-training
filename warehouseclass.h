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
    for (unsigned int i=0; i<cap-1 ;i++)
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
    std::cout << "print: display contents of the entire database\n";
    std::cout << "exit: terminate the program\n";
    std::cout << std::endl;    
}