#ifndef masutilities_h
#define masutilities_h 1
//------------------------------------------------------------------
//File masutilities.h defines utilities needed by the MARIE Assembler
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
int hextoint(string s);     //Converts a string containing only hexadecimal digits
int dectoint(string s);     //Converts a string containing only decimal digits
#endif 
