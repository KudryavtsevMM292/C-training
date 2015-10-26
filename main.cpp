#include <iostream>
#include <sstream>
#include "warehouseclass.h"
using namespace std;

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
           cout << "Type next command" << endl;
        }   
        else if (userinp=="add")
        {    
           if (whouse.getcount()>=whouse.getcap())
               whouse.expand();
           whouse.additem();
           cout << "Type next command" << endl;
        }
        else if (userinp=="print")
        {
           if (!whouse.isempty()) whouse.printall();
              else cout << "Database is empty" <<endl;
           cout << "Type next command" << endl;
        }
        else if (userinp=="mod_by_number")
        {
           if (whouse.isempty()) cout << "Database is empty" <<endl;
             else
             {
                cout << "There are currently " << whouse.getcount() << " elements in database." << endl;
                cout << "Enter the number of required element (ranging from 1 to " << whouse.getcount() << ")\n";
                cin >> userinp;
                unsigned int k=0;
                stringstream(userinp) >> k;
                if ( (k>=1)&&(k<=whouse.getcount()) ) 
                    whouse.moditem(k-1);
                    else cout << "Value out of range. Command aborted." << endl;
             }   
           cout << "Type next command" << endl;
        }        
        else if (userinp=="exit")
        {          
           return 0;
        }        
        else cout << "Invalid command. Type ""help"" for a list of avaliable commands" <<endl;
        
    }
}
