#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class itemgeneric
{   
  public: 
    virtual void setprops()=0;
    virtual void getprops()=0;
    virtual void savetofile(std::string fname)=0;
    virtual void loadfromfile(std::ifstream& tfile)=0;
};

//************item type 1 definition begins************
class item1:public itemgeneric
{
    unsigned int id;
    std::string name;
    unsigned int quan;       
    double value1;
    int value2;         
    int value3;
  public:
    void setprops();
    void getprops();
    void savetofile(std::string fname);
    void loadfromfile(std::ifstream& tfile);
};

void item1::setprops()
{
    std::string userinp;  
    std::cout << "Enter new element id\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->id; 
 
    std::cout << "Enter new element name\n";
    std::cin >> userinp;
    this->name=userinp;
    
    std::cout << "Enter new element quantity\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->quan;        
    
    std::cout << "Enter new element property 1 (floating-point value)\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->value1;
    
    std::cout << "Enter new element property 2 (integer value)\n";
    std::cin >> userinp;    
    std::stringstream(userinp) >> this->value2;  

    std::cout << "Enter new element property 3 (integer value)\n";
    std::cin >> userinp;    
    std::stringstream(userinp) >> this->value3;      
}

void item1::getprops()
{
    std::cout << "  id: " << this->id << std::endl;
    std::cout << "  name: " << this->name << std::endl;
    std::cout << "  quantity: " << this->quan << std::endl;
    std::cout << "  property 1: " << this->value1 << std::endl;
    std::cout << "  property 2: " << this->value2 << std::endl;
    std::cout << "  property 3: " << this->value3 << std::endl;    
    std::cout << std::endl;    
}

void item1::savetofile(std::string fname)
{
    std::ofstream curfile;
    curfile.open(fname.c_str(), std::ios_base::app);
    if (curfile.is_open())
      {
         curfile << "item1\n";
         curfile << this->id << "\n";
         curfile << this->name << "\n";
         curfile << this->quan << "\n";
         curfile << this->value1 << "\n";
         curfile << this->value2 << "\n";
         curfile << this->value3 << "\n";      
         curfile.close();
      }
      else std::cout << "Unable to open file\n";    
}

void item1::loadfromfile(std::ifstream& tfile)
{
    std::string line;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->id;            
    if (!getline(tfile,line)) return;
    this->name=line;            
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->quan;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->value1;
    if (!getline(tfile,line)) return;                    
    std::stringstream(line) >> this->value2;
    if (!getline(tfile,line)) return;                    
    std::stringstream(line) >> this->value3;    
}
//************item type 1 definition ends************

//************item type 2 definition begins************
class item2:public itemgeneric
{
    unsigned int id;
    std::string name;
    unsigned int quan;      
    int value1;
    std::string value2;         
  public:
    void setprops();
    void getprops();
    void savetofile(std::string fname);
    void loadfromfile(std::ifstream& tfile);    
};

void item2::setprops()
{
    std::string userinp; 
    std::cout << "Enter new element id\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->id; 
  
    std::cout << "Enter new element name\n";
    std::cin >> userinp;
    this->name=userinp;
    
    std::cout << "Enter new element quantity\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->quan;        
    
    std::cout << "Enter new element property 1 (integer value)\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->value1;
    
    std::cout << "Enter new element property 2 (string)\n";
    std::cin >> userinp;
    this->value2=userinp;     
}

void item2::getprops()
{
    std::cout << "  id: " << this->id << std::endl;
    std::cout << "  name: " << this->name << std::endl;
    std::cout << "  quantity: " << this->quan << std::endl;
    std::cout << "  property 1: " << this->value1 << std::endl;
    std::cout << "  property 2: " << this->value2 << std::endl; 
    std::cout << std::endl;    
}

void item2::savetofile(std::string fname)
{
    std::ofstream curfile;
    curfile.open(fname.c_str(), std::ios_base::app);
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
      else std::cout << "Unable to open file\n";    
}

void item2::loadfromfile(std::ifstream& tfile)
{
    std::string line;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->id;            
    if (!getline(tfile,line)) return;
    this->name=line;            
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->quan;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->value1;
    if (!getline(tfile,line)) return;
    this->value2=line;   
}
//************item type 2 definition ends************

//************item type 3 definition begins************
class item3:public itemgeneric
{
    unsigned int id;
    std::string name;
    unsigned int quan;      
    double value1;
    double value2;         
    double value3;
  public:
    void setprops();
    void getprops();
    void savetofile(std::string fname);
    void loadfromfile(std::ifstream& tfile);
};

void item3::setprops()
{
    std::string userinp;  
    std::cout << "Enter new element id\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->id; 
    
    std::cout << "Enter new element name\n";
    std::cin >> userinp;
    this->name=userinp;
    
    std::cout << "Enter new element quantity\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->quan;        
    
    std::cout << "Enter new element property 1 (floating-point value)\n";
    std::cin >> userinp;
    std::stringstream(userinp) >> this->value1;
    
    std::cout << "Enter new element property 2 (floating-point value)\n";
    std::cin >> userinp;    
    std::stringstream(userinp) >> this->value2;  

    std::cout << "Enter new element property 3 (floating-point value)\n";
    std::cin >> userinp;    
    std::stringstream(userinp) >> this->value3;      
}

void item3::getprops()
{
    std::cout << "  id: " << this->id << std::endl;
    std::cout << "  name: " << this->name << std::endl;
    std::cout << "  quantity: " << this->quan << std::endl;
    std::cout << "  property 1: " << this->value1 << std::endl;
    std::cout << "  property 2: " << this->value2 << std::endl;
    std::cout << "  property 3: " << this->value3 << std::endl;    
    std::cout << std::endl;    
}

void item3::savetofile(std::string fname)
{
    std::ofstream curfile;
    curfile.open(fname.c_str(), std::ios_base::app);
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
      else std::cout << "Unable to open file\n";    
}

void item3::loadfromfile(std::ifstream& tfile)
{
    std::string line;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->id;            
    if (!getline(tfile,line)) return;
    this->name=line;            
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->quan;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->value1;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->value2;
    if (!getline(tfile,line)) return;
    std::stringstream(line) >> this->value3;    
}
//************item type 3 definition ends************

class itemgenericfactory
{
    public:
      virtual itemgeneric* createitem()=0;
};

class item1factory:public itemgenericfactory
{
    public:
      itemgeneric* createitem() {return new item1;}   
};

class item2factory:public itemgenericfactory
{
    public:
      itemgeneric* createitem() {return new item2;}   
};

class item3factory:public itemgenericfactory
{
    public:
      itemgeneric* createitem() {return new item3;}   
};