#include "itembaseclass.h"
using namespace std;

class item2:public item
{
    int id;
    string name;
    int quan;      
    int value1;
    string value2;         
  public:
    void setprops();
    void getprops();
    void savetofile(string fname);
    void loadfromfile(ifstream& tfile);    
};

void item2::setprops()
{
    cout << "Enter new element id\n";
    while ( !(PromtValue(&(this->id))) || ((this->id)<=0) )
      cout << "id should be positive, please try again\n";
      
    cout << "Enter new element name\n";
    while ( !(PromtValue(&(this->name))) );

    cout << "Enter new element quantity\n";
    while ( !(PromtValue(&(this->quan))) || ((this->quan)<=0) )
      cout << "quantity should be positive, please try again\n";
      
    cout << "Enter new element property 1 (integer value)\n";
    while ( !(PromtValue(&(this->value1))) );
      
    cout << "Enter new element property 2 (string value)\n";
    while ( !(PromtValue(&(this->value2))) );
}

void item2::getprops()
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
}

void item2::savetofile(string fname)
{
    ofstream curfile;
    curfile.open(fname.c_str(), ios_base::app);
    if (curfile.is_open())
      {
         curfile << "item2\n";
         curfile << this->id << "\n";
         curfile << this->name << "\n";
         curfile << this->quan << "\n";
         curfile << this->value1 << "\n";
         curfile << this->value2 << "\n";     
         curfile.close();
      }
      else cout << "Unable to open file\n";    
}

void item2::loadfromfile(ifstream& tfile)
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
    this->value2=line;   
}
