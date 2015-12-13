#include "warehouseclass.h"
using namespace std;

unsigned int requestelementnumber(warehouse &whouse)
{
  if (whouse.isempty()) 
  {
    cout << "Database is empty" <<endl;
    return 0;
  }
  else
    {
      cout << "There are currently " << whouse.getcount() << " elements in database." << endl;
      cout << "Enter the number of required element (ranging from 1 to " << whouse.getcount() << ")\n";
      int k=0;
      while ( !(PromtValue(&k)) );
      if ( (k>=1)&&(k<=whouse.getcount()) ) return(k);      
      else
        {
          cout << "Value out of range. Command aborted." << endl;
          cin.ignore();
          cin.clear();
          return 0;
        }
    }     
}

void printstatus(warehouse &whouse)
{
   cout << "Currently " << whouse.getcount() << " elements in database." << endl;
   cout << "Type next command" << endl;
   cin.ignore();
   cin.clear();
}    

int main(int argc, char **argv)
{
    warehouse whouse;
    string userinp;
    cout << "Welcome to warehouse management program.\nType ""help"" for a list of avaliable commands" << endl;
    for(;;)
    {
        cin >> userinp;
        if (userinp=="help")
        {
           whouse.printhelp();
           printstatus(whouse);
        }   
        else if (userinp=="add")
        {    
           whouse.additem();
           printstatus(whouse);
        }
        else if (userinp=="print")
        {
           if (!whouse.isempty()) whouse.printall();
              else cout << "Database is empty" <<endl;
           printstatus(whouse);
        }
        else if (userinp=="mod_by_number")
        {
           int k=requestelementnumber(whouse); 
           if (k!=0) whouse.moditem(k-1);
           printstatus(whouse);
        }
        else if (userinp=="del_by_number")
        {
           int k=requestelementnumber(whouse); 
           if (k!=0) whouse.delitem(k-1);
           printstatus(whouse);
        }
        else if (userinp=="save")
        {
           if (!whouse.isempty()) whouse.save();
              else cout << "Database is empty" <<endl;
           printstatus(whouse);
        }
        else if (userinp=="load")
        {
           whouse.load();
           printstatus(whouse);
        }         
        else if (userinp=="exit")
        {          
           return 0;
        }        
        else 
        {
           cout << "Invalid command. Type ""help"" for a list of avaliable commands" <<endl;
           cin.ignore();
           cin.clear();
        }
        
    }
}
