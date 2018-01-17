#include "saheader.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    int choice;
    char temp[10];
    team t1,t2;
    match *games;
    games = new match[200];
    setColor("BOLDRED");
    cout<<"Be name khoda\n";
    setColor("RESET");
    cout<<"Welcome to SA-Arena";
    start:
    setColor("BOLDRED");
    cout<<"\n\nEnter your choice\n";
    setColor("RESET");
    cout<<"1: Start a new Tournament\n"<<"2: Load Recent Tournament\n";
    choice=inputChoice(1,2);
    if(choice==1){
        if(!enterTeams(t1,t2)) goto start;
    }
    else{
        bool isLoad = load(t1,t2,games);
        if(!isLoad) goto start;
    }
    
    if(t1.sendid()==t2.sendid()){
        setColor("BOLDBLACK");
        cout<<"Warning!!! Error in Team Id\n\n";
        setColor("RESET");
    }
    
    mainMenu(t1,t2,games);
    return 0;
}