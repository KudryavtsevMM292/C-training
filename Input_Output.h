#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

const int IgnoreRange=100;

int PromtValue(int* x);
int PromtValue(double* x);
int PromtValue(string* x);

void PrintValue(int x);
void PrintValue(double x);
void PrintValue(string x);

int PromtValue(int* x)
{
  string userinp;
  try
    {
      cin >> userinp;
      if (istringstream(userinp) >> *x) return 1;
      else throw 100;
    }
  catch(...)
    {
      cin.ignore(IgnoreRange,'\n');
      cin.clear();
      cout << "Integer value required\n";
      return 0;
    }
}

int PromtValue(double* x)
{
  string userinp;
  try
    {
      cin >> userinp;
      if (istringstream(userinp) >> *x) return 1;
      else throw 100;
    }
  catch(...)
    {
      cin.ignore(IgnoreRange,'\n');
      cin.clear();
      cout << "Floating-point value required\n";
      return 0;
    }
}

int PromtValue(string* x)
{
  string userinp;  
  try
    {
      if (cin >> *x) return 1;
      else throw 100;
    }
    catch(...)
    {
      cin.ignore(IgnoreRange,'\n');
      cin.clear();
      cout << "String required\n";
      return 0;
    }
}

void PrintValue(int x)
{
  cout << x <<endl;
}

void PrintValue(double x)
{
  cout << x <<endl;
}

void PrintValue(string x)
{
  cout << x <<endl;
}