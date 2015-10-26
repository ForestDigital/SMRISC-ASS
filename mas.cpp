//-------------------------------------------------------------------
//File mas.cpp contains functions that process command line arguments
//and interface with the lex-generated scanner 
//--------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   October, 2015
//--------------------------------------------------------------------
//Copyright October, 2015 by Thomas R. Turner
//Do not reproduce without permission from Thomas R. Turner
//--------------------------------------------------------------------
//C++ Standard include files
//--------------------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;
//--------------------------------------------------------------------
//Application include files
//--------------------------------------------------------------------
#include "maslex.h"
#include "maspar.h"
//--------------------------------------------------------------------
//Externals
//--------------------------------------------------------------------
ofstream tfs;                     //trace file stream 
//--------------------------------------------------------------------
//BadSuffixException
//--------------------------------------------------------------------
struct BadSuffixException {
    BadSuffixException(char* fn)
    {   cout << endl;
        cout << "Input file \"" << fn << "\" does not have a .mas suffix.";
    }
};
//--------------------------------------------------------------------
//--------------------------------------------------------------------
class FileNameSuffix {
    char* prefix;
public:
    FileNameSuffix(char* fn)
    {   char* p=strstr(fn,".mas");
        if (!p) throw BadSuffixException(fn);
        int n=p-fn;
        if (n+4!=strlen(fn)) throw BadSuffixException(fn);
        prefix=new char[strlen(fn)+1];
        strncpy(prefix,fn,n);
        prefix[n]=0;
    }
    ~FileNameSuffix(){if (prefix) delete[] prefix;}
    void Suffix(char* fn,const char* suffix)
    {   strcpy(fn,prefix);
        strcat(fn,suffix);
    }
};
//--------------------------------------------------------------------
//CommandLineException
//--------------------------------------------------------------------
struct CommandLineException {
    CommandLineException(int m,int a)
    {   cout << endl;
        cout << "Too many arguments on the command line.";
        cout << endl;
        cout << m << " argument(s) are permitted on the command line.";
        cout << endl;
        cout << a << " argument(s) appeared on the command line.";
        cout << endl;
    }
};
//--------------------------------------------------------------------
//FileException
//--------------------------------------------------------------------
struct FileException {
   FileException(const char* fn)
   {   cout << endl;
       cout << "File " << fn << " could not be opened.";
       cout << endl;
   }
};
//--------------------------------------------------------------------
//--------------------------------------------------------------------
void CompilerMgr(FILE* i)
{   Parser P(i);
    int rc=P.Parse();
}
//--------------------------------------------------------------------
//Function main processes command line arguments
//--------------------------------------------------------------------
int main(int argc,char* argv[])
{   try {
        char ifn[255];
        switch (argc) {
            case 1:               //Prompt for the input file name
                cout << "Enter the input file name. ";
                cin >> ifn;
                break;
            case 2:               //Read the input file name
                strcpy(ifn,argv[1]);
                break;
            default:
                throw CommandLineException(1,argc-1);
                break;
    }
    FileNameSuffix F(ifn);        //Find the prefix of the input file name
    char tfn[255];
    F.Suffix(tfn,".trc");         //Create the trace file name
    FILE* i=fopen(ifn,"r");       //Open the input file
    if (!i) throw FileException(ifn);
    tfs.open(tfn); if (!tfs) throw FileException(tfn);
    CompilerMgr(i);
    tfs << endl;                  //Put a new line in the trace file
    tfs.close();                  //Close the trace file
    fclose(i);                    //Close the input file
    } catch (...) {
        cout << endl;
        cout << "Program terminated!";
        cout << endl;
        cout << "I won't be back!";
        cout << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}


