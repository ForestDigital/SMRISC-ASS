//------------------------------------------------------------------
//File masutilities.cpp implements utilities needed by the MARIE Assembler
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
#include "masutilities.h"
//------------------------------------------------------------------
//------------------------------------------------------------------
int hextoint(string s)      //Converts a string containing only hexadecimal digits
{   int rv=0;
    for (int a=0;a<s.length();a++) {
        rv=rv*16;
        if ('0'<= s[a] && s[a] <= '9') rv=rv+s[a]-'0';
        if ('a'<= s[a] && s[a] <= 'f') rv=rv+10+s[a]-'a';
    }
    return rv;
}
int dectoint(string s)      //Converts a string containing only decimal digits
{   int rv=0;
    for (int a=0;a<s.length();a++) {
        rv=rv*10;
        if ('0'<= s[a] && s[a] <= '9') rv=rv+s[a]-'0';
    }
    return rv;
}
