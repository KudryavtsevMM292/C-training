#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct STORETYPE
{
    unsigned int id;
    string sname;
    double dvalue1;         //property 1
    char cvalue2;           //property 2
    unsigned int iquan;     //quantity
};

void addunit(STORETYPE *storeunit)
{
    string userinp;
    cout << "Enter new element id" << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> id;
    
    cout << "Enter new element name" << endl;
    cin >> userinp;
    storeunit -> sname=userinp;
    
    cout << "Enter new element property 1 (floating-point value)" << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> dvalue1;
    
    cout << "Enter new element property 2 (single symbol value)" << endl;
    cin >> storeunit -> cvalue2;
    
    cout << "Enter new element quantity" << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> iquan;

    cout << "Input accepted" << endl;    
}

void modunit(STORETYPE *storeunit)
{
    string userinp;
    cout << "Current element id is " << storeunit -> id << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> id;
    
    cout << "Current element name is " << storeunit -> sname << endl;
    cin >> userinp;
    storeunit -> sname=userinp;
    
    cout << "Current element property 1 is " << storeunit -> dvalue1 << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> dvalue1;
    
    cout << "Current element property 2 is " << storeunit -> cvalue2 << endl;
    cin >> storeunit -> cvalue2;
    
    cout << "Current element quantity is " << storeunit -> iquan << endl;
    cin >> userinp;
    stringstream(userinp) >> storeunit -> iquan;

    cout << "Input accepted" << endl;    
}

void printall(STORETYPE *list, unsigned int size)
{
    for (int i=0; i<size; i++)
       {
          cout << "element " << (i+1) << " id: " << list[i].id << endl;
          cout << "element " << (i+1) << " name: " << list[i].sname << endl;
          cout << "element " << (i+1) << " property 1: " << list[i].dvalue1 << endl;
          cout << "element " << (i+1) << " property 2: " << list[i].cvalue2 << endl;
          cout << "element " << (i+1) << " quantity: " << list[i].iquan << endl;
          cout << endl;
       }    
}

void printhelp()
{
    cout << "Element specification:" << endl;
    cout << "   id: positive integer" << endl;
    cout << "   name: string" << endl;
    cout << "   property 1: floating-point" << endl;
    cout << "   property 2: single character" << endl;
    cout << "   quantity: positive integer" << endl;
    cout << endl;
    cout << "Command line instructions:" << endl;
    cout << "add: append new element to the database" << endl;
    cout << "mod_by_number: edit database element with specified number" << endl;
    cout << "print: display contents of the entire database" << endl;
    cout << "exit: terminate the program" << endl;
    cout << endl;    
}

int main(int argc, char **argv)
{
    STORETYPE *warehouse;
    unsigned int n=0;               //Database length in elements 
    string userinp;
    cout << "Welcome to warehouse management program.\nType ""help"" for a list of avaliable commands" << endl;
    for(;;)
    {
        cin >> userinp;
        if (userinp=="help")
        {
           printhelp();
           cout << "Type next command" << endl;
        }   
        else if (userinp=="add")
        {    
            if (n==0)  //database is empty, creating a new one
              {
                  warehouse=new STORETYPE[1];
                  n=1;
              }
              else 
                 {  //"realloc" existing array to a new size (add 1 uninitialized element)
                    n++;
                    STORETYPE *temp;
                    temp=new STORETYPE[n];
                    for (int i=0; i<n-1 ;i++)
                        temp[i]=warehouse[i];
                    delete [] warehouse;                        
                    warehouse=temp;  
                 }
            addunit(&warehouse[n-1]);
            cout << "Type next command" << endl;
        }
        else if (userinp=="print")
        {
           if (n>0) printall(warehouse,n);
              else cout << "Database is empty" <<endl;
           cout << "Type next command" << endl;
        }
        else if (userinp=="mod_by_number")
        {
           if (n==0) cout << "Database is empty" <<endl;
             else
             {
                cout << "There are currently " << n << " elements in database." << endl;
                cout << "Enter the number of required element (ranging from 1 to " << n << ")" <<endl;
                cin >> userinp;
                unsigned int k=0;
                stringstream(userinp) >> k;
                if ((k>=1)&&(k<=n)) 
                    modunit(&warehouse[k-1]);
                    else cout << "Value out of range. Command aborted." << endl;
             }   
           cout << "Type next command" << endl;
        }        
        else if (userinp=="exit")
        {
           if (n>0) delete [] warehouse;            
           return 0;
        }        
        else cout << "Invalid command. Type ""help"" for a list of avaliable commands" <<endl;
        
    }
    if (n>0) delete [] warehouse;
    return 0;
}
