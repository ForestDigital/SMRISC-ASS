#ifndef maslabel_h
#define maslabel_h 1
//------------------------------------------------------------------
//File maslabel.h defines class Label 
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
//class Label resolves labels to addresses
//------------------------------------------------------------------
class Label {
    struct Descriptor {
        bool defined;
        string label;
        int address;
        List* L;
        Descriptor():defined(false),label(""),address(0),L(0){}
       ~Descriptor(){if (L) delete L;}
    };
    int size;                //Number of available label descriptors
    int count;               //Number of occupied label descriptors
    Descriptor* D;           //Points to an array of label descriptors
public:
    Label(int sz=100);
   ~Label();
    bool IsFull(void);       //Determine if the Label Table is full.
    void Define              //Define label l. If it doesn't exist add it to the Label Table
         (string l           //If it does exits then resolve all reference to the label.
         ,unsigned short a
         ,int M[]
         );
    int Find(string l);      //Find label l in the list of Descriptors
                             //Return a valid index 0<=i<count if label l
                             //is found or -1 if the label is not found
    void DefinedInsert       //Insert defined label l into the table
        (string l
        ,int adr
        );
    void UndefinedInsert     //Insert a reference to label l into the Label Table
        (string l
        ,int adr
        );
    int Reference            //Find the label and its defined address
        (string l            //or enter the reference address for later
        ,int adr             //resolution
        );
    void Print(ostream& o);  //Print the Label Table
    
};
#endif 
