%{
//---------------------------------------------------------------------
//File maspar.y contains a specification for MARIE Assembler Language 
//defined by Thomas R. Turner.
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     October, 2015
//---------------------------------------------------------------------
//Copyright October, 2015 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Application inlcude files
//---------------------------------------------------------------------
#include "maslex.h"
#include "maspar.h"
#include "masopcodes.h"
#include "masutilities.h"
#include "maslist.h"
#include "maslabel.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
void yyerror(const char* m);
void MemoryPrint(ostream& o);
void MemoryTitle(ostream& o);
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
//---------------------------------------------------------------------
//Global Variables
//---------------------------------------------------------------------
int address=0;               //Address of the next instruction
int initialaddress=0;        //Address of the first instruction
int Memory[4096];            //MARIE's memory
Label LT;                    //Label Table for resolving the addresses of labels
//---------------------------------------------------------------------
%}
%union {
  string* token;
  unsigned short integer;
}
%type  <integer> operand
%token <token>   TOKEN_BEGIN
%token <token>   COMMA
%token <token>   RESERVE_WORDS
%token <token>   JNS
%token <token>   LOAD
%token <token>   STORE
%token <token>   ADD
%token <token>   SUBT
%token <token>   INPUT
%token <token>   OUTPUT
%token <token>   HALT
%token <token>   SKIPCOND
%token <token>   JUMP
%token <token>   CLEAR
%token <token>   ADDI
%token <token>   JUMPI
%token <token>   LOADI
%token <token>   STOREI
%token <token>   DEC
%token <token>   HEX
%token <token>   ORG
%token <token>   REGULAR_EXPRESSIONS
%token <token>   IDENTIFIER
%token <token>   HEXLIT
%token <token>   TOKEN_END
%%
program:
  statement_list
  {tfs << endl << "#001 program -> statement_list";
   MemoryPrint(tfs);
   LT.Print(tfs);
  }
statement_list:
  statement
  {tfs << endl << "#002 statement_list -> statement"; 
  } 
statement_list:
  statement_list statement
  {tfs << endl << "#003 statement_list -> statement_list statement"; 
  } 
statement:
  directive   
  {tfs << endl << "#004 statement -> directive"; 
  } 
statement:
  labeled_item
  {tfs << endl << "#005 statement -> labeled_item"; 
  } 
statement:
  item   
  {tfs << endl << "#006 statement -> item"; 
  } 
directive:
  ORG HEXLIT
  {tfs << endl << "#007 directive -> ORG HEXLIT(" << (*$2) << ")"; 
   tfs << endl << (*$2) << "=" << hextoint(*$2) << " decimal";
   initialaddress=hextoint(*$2);
   address=initialaddress;
   tfs << endl << "initialaddress=" << initialaddress;
  } 
labeled_item:
  label item
  {tfs << endl << "#008 labeled_item -> label item"; 
  } 
label:
  IDENTIFIER COMMA
  {tfs << endl << "#009 label -> identifier(" << (*$1) << ")" << "  ,"; 
   LT.Define(*$1,address,Memory);
  } 
item:
  instruction 
  {tfs << endl << "#010 item -> instruction "; 
   tfs << endl << "address=" << address;
   address++;
  } 
item:
  data_definition
  {tfs << endl << "#011 item -> data_definition"; 
   address++;
  } 
instruction:
  JNS operand
  {tfs << endl << "#012 instruction -> JNS operand"; 
   unsigned short operation=op_jns|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  LOAD operand
  {tfs << endl << "#013 instruction -> LOAD operand"; 
   unsigned short operation=op_load|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  STORE operand
  {tfs << endl << "#014 instruction -> STORE operand"; 
   unsigned short operation=op_store|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  ADD operand
  {tfs << endl << "#015 instruction -> ADD operand"; 
   unsigned short operation=op_add|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  SUBT operand
  {tfs << endl << "#016 instruction -> SUBT operand"; 
   unsigned short operation=op_subt|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  INPUT
  {tfs << endl << "#017 instruction -> INPUT"; 
   unsigned short operation=op_input;
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   Memory[address]=operation;
   tfs << dec;
  } 
instruction:
  OUTPUT
  {tfs << endl << "#018 instruction -> OUTPUT"; 
   unsigned short operation=op_output;
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  HALT 
  {tfs << endl << "#019 instruction -> HALT"; 
   unsigned short operation=op_halt;
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  SKIPCOND operand 
  {tfs << endl << "#020 instruction -> SKIPCOND operand"; 
   unsigned short operation=op_skipcond|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  JUMP operand 
  {tfs << endl << "#021 instruction -> JUMP operand"; 
   unsigned short operation=op_jump|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  CLEAR 
  {tfs << endl << "#022 instruction -> CLEAR"; 
   unsigned short operation=op_clear;
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  ADDI operand 
  {tfs << endl << "#023 instruction -> ADDI operand"; 
   unsigned short operation=op_addi|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  JUMPI operand 
  {tfs << endl << "#024 instruction -> JUMPI operand"; 
   unsigned short operation=op_jumpi|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  LOADI operand 
  {tfs << endl << "#025 instruction -> LOADI operand"; 
   unsigned short operation=op_loadi|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
instruction:
  STOREI operand 
  {tfs << endl << "#026 instruction -> STOREI operand"; 
   unsigned short operation=op_storei|($2);
   tfs << endl << "instruction=" << setw(4) << hex << operation;
   tfs << dec;
   Memory[address]=operation;
  } 
operand:
  HEXLIT
  {tfs << endl << "#027 operand -> HEXLIT(" << (*$1) << ")"; 
   $$=hextoint(*$1);
  } 
operand:
  IDENTIFIER
  {tfs << endl << "#028 operand -> IDENTIFIER"; 
   $$=LT.Reference(*$1,address);
  } 
data_definition:
  HEX HEXLIT 
  {tfs << endl << "#029 data_definition -> HEX HEXLIT(" << (*$2) << ")"; 
   tfs << endl << (*$2) << "=" << hextoint(*$2) << " decimal";
   Memory[address]=hextoint(*$2);
  } 
data_definition:
  DEC HEXLIT 
  {tfs << endl << "#030 data_definition -> DEC HEXLIT(" << (*$2) << ")"; 
   tfs << endl << (*$2) << "=" << dectoint(*$2) << " decimal";
   Memory[address]=dectoint(*$2);
  } 
%%
//-----------------------------------------------------------------------
//User function section
//-----------------------------------------------------------------------
void yyerror(const char* m)
{   cout << endl 
         << "line(" << line << ") col(" << col << ") " << m;
    cout << endl;
}
void MemoryTitle(ostream& o)
{   o << endl;
    o << "adr";
    for (int a=0;a<16;a++) {
        o << " ";
        o << "ad";
        o << setfill('0') << hex << setw(2) << a;
    }
    o << setfill(' ') << dec;
}
void MemoryPrint(ostream& o)
{   MemoryTitle(o);
    for (int a=initialaddress;a<address;a++) {
        if (a%16==0) {
            o << endl;
            o << setw(3) << setfill('0') << hex << a;
       }
       o << " ";
       o << setw(4) << setfill('0') << hex << Memory[a];
   }
   o << endl;
   o << setfill(' ') << dec;
}