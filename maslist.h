#ifndef maslist_h
#define maslist_h 1
//------------------------------------------------------------------
//File maslist.h defines a list of integers
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
//------------------------------------------------------------------
class List {
    int size;                //Number of available elements
    int count;               //Number of occupied elements
    int* L;                  //Points to an array of integer elements
    int cursor;              //Index of the current element
public:
    List(int sz=10);
   ~List();
    bool IsFull(void);
    bool IsEmpty(void);
    void Insert(int v);
    void First(void);
    void Next(void);
    bool IsEol(void);
    int Element(void);
};
#endif 
