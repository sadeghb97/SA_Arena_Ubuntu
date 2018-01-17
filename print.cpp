#include "saheader.h"

void printError(const char* er){
    typeError();
    cout<<er;
}

void sucPrint(const char* mes){
    setColor("BOLDGREEN");
    cout<<mes;
    setColor("RESET");
}

void rulePrint(const char * mes){
    typeRule();
    cout<<mes;
}

void blackPrint(const char* mes){
    setColor("BOLDBLACK");
    cout<<mes;
    setColor("RESET");
}

void typeWarning(){
    setColor("BOLDYELLOW");
    cout<<"Warning: ";
    setColor("RESET"); 
}

void typeRule(){
    setColor("BOLDGREEN");
    cout<<"Rule: ";
    setColor("RESET"); 
}

void typeError(){
    setColor("BOLDRED");
    cout<<"Error: ";
    setColor("RESET"); 
}

void noBoldBlackPrint(const char* mes){
    setColor("BLACK");
    cout<<mes;
    setColor("RESET");
}

void boldGreenPrint(const char* mes){
    setColor("BOLDGREEN");
    cout<<mes;
    setColor("RESET");
}

void boldRedPrint(const char* mes){
    setColor("BOLDRED");
    cout<<mes;
    setColor("RESET");
}