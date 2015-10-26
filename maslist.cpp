//------------------------------------------------------------------
//File maslist.cpp implements a list of integers
//------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   October, 2015
//------------------------------------------------------------------
//Copyright October, 2015 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//------------------------------------------------------------------
//C++ Standard include files
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
//------------------------------------------------------------------
//Application include files
//------------------------------------------------------------------
#include "maslist.h"
//------------------------------------------------------------------
//------------------------------------------------------------------
struct ListException {
    ListException(const char* m)
    {   cout << endl;
        cout << "I am the List and I am " << m << ".";
    }
};
//------------------------------------------------------------------
//------------------------------------------------------------------
List::List(int sz):size(sz),count(0),cursor(0){L=new int[size];}
List::~List(){if (L) delete[] L;}
bool List::IsFull(void){return count>=size;}
bool List::IsEmpty(void){return count<=0;}
void List::Insert(int v)
{   if (IsFull()) throw ListException("full");
    L[count++]=v;
}
void List::First(void){cursor=0;}
void List::Next(void){if (cursor<count) cursor++;}
bool List::IsEol(void){return cursor>=count;}
int List::Element(void){return L[cursor];}
