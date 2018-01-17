#include "saheader.h"

void printError(const char* er){
    setColor("BOLDRED");
    cout<<"Error: ";
    setColor("RESET");
    cout<<er;
}

void sucPrint(const char* mes){
    setColor("BOLDGREEN");
    cout<<mes;
    setColor("RESET");
}

void rulePrint(const char * mes){
    setColor("BOLDGREEN");
    cout<<"Rule: ";
    setColor("RESET");
    cout<<mes;
}

void blackPrint(const char* mes){
    setColor("BOLDBLACK");
    cout<<mes;
    setColor("RESET");
}