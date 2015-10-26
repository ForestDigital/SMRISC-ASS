#ifndef masopcodes_h
#define masopcodes_h 1
//------------------------------------------------------------------
//File masopcodes.h defines MARIE opcodes 
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
//------------------------------------------------------------------
//------------------------------------------------------------------
enum opCode 
    {op_jns       = 0x0000
    ,op_load      = 0x1000
    ,op_store     = 0x2000
    ,op_add       = 0x3000
    ,op_subt      = 0x4000
    ,op_input     = 0x5000
    ,op_output    = 0x6000
    ,op_halt      = 0x7000
    ,op_skipcond  = 0x8000
    ,op_jump      = 0x9000
    ,op_clear     = 0xA000
    ,op_addi      = 0xB000
    ,op_jumpi     = 0xC000
    ,op_loadi     = 0xD000
    ,op_storei    = 0xE000
    };

#endif 
