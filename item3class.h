#include "itembaseclass.h"
using namespace std;

class item3:public item
{
    int id;
    string name;
    int quan;      
    double value1;
    double value2;         
    double value3;
  public:
    void setprops();
    void getprops();
    void savetofile(string fname);
    void loadfromfile(ifstream& tfile);
};

void item3::setprops()
{
    cout << "Enter new element id\n";
    while ( !(PromtValue(&(this->id))) || ((this->id)<=0) )
      cout << "id should be positive, please try again\n";
      
    cout << "Enter new element name\n";
    while ( !(PromtValue(&(this->name))) );

    cout << "Enter new element quantity\n";
    while ( !(PromtValue(&(this->quan))) || ((this->quan)<=0) )
      cout << "quantity should be positive, please try again\n";
      
    cout << "Enter new element property 1 (floating-point value)\n";
    while ( !(PromtValue(&(this->value1))) );
      
    cout << "Enter new element property 2 (floating-point value)\n";
    while ( !(PromtValue(&(this->value2))) );
      
    cout << "Enter new element property 3 (floating-point value)\n";
    while ( !(PromtValue(&(this->value3))) );
}

void item3::getprops()
{
    cout << "  id: ";
    PrintValue(this->id);
    cout << "  name: ";
    PrintValue(this->name);
    cout << "  quantity: ";
    PrintValue(this->quan);
    cout << "  property 1: ";
    PrintValue(this->value1);
    cout << "  property 2: ";
    PrintValue(this->value2);
    cout << "  property 3: ";
    PrintValue(this->value3);
}

void item3::savetofile(string fname)
{
    ofstream curfile;
    curfile.open(fname.c_str(), ios_base::app);
    if (curfile.is_open())
      {
         curfile << "item3\n";
         curfile << this->id << "\n";
         curfile << this->name << "\n";
         curfile << this->quan << "\n";
         curfile << this->value1 << "\n";
         curfile << this->value2 << "\n";
         curfile << this->value3 << "\n";      
         curfile.close();
      }
      else cout << "Unable to open file\n";    
}

void item3::loadfromfile(ifstream& tfile)
{
    string line;
    if (!getline(tfile,line)) return;
    stringstream(line) >> this->id;            
    if (!getline(tfile,line)) return;
    this->name=line;            
    if (!getline(tfile,line)) return;
    stringstream(line) >> this->quan;
    if (!getline(tfile,line)) return;
    stringstream(line) >> this->value1;
    if (!getline(tfile,line)) return;
    stringstream(line) >> this->value2;
    if (!getline(tfile,line)) return;
    stringstream(line) >> this->value3;    
}
