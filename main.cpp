#include "saheader.h"

char* DATA_FILE_NAME;
char* NULL_PATH_STRING;
bool IS_SAVED;

int main(int argc, char** argv) {
    DATA_FILE_NAME=new char[256];
    NULL_PATH_STRING=new char[100];
	strcpy(NULL_PATH_STRING,"###NULLPATH###");
    strcpy(DATA_FILE_NAME,NULL_PATH_STRING);
    IS_SAVED=true;
    srand(time(NULL));
    int choice;
    team t1,t2;
    match *games;
    games = new match[200];
    inputProfile inpSettings;
	
	if(argc>=3 && strcmp(argv[1],"__players")==0){
		start_squads:
		fstream f1(argv[2] , ios::in | ios::binary);
		if(!isDataFileAndReady(f1)) return 0;
		f1.read((char *)&inpSettings, sizeof(inpSettings));
		f1.read((char *)&t1, sizeof(t1));
		f1.read((char *)&t2, sizeof(t2));
		f1.read((char *)games, sizeof(match)*200);
		f1.close();
		newTermPlayers(t1,t2,games);
		while(true){
			cout<<endl<<"Enter[R/r] To Reload [Q/q] To Exit: ";
			char temp[20];
			cin.getline(temp,20);
			if(strcmp(temp,"q")==0 || strcmp(temp,"Q")==0) break;
			else if(strcmp(temp,"R")==0 || strcmp(temp,"r")==0){
				goto start_squads;
			}
		}
		return 0;
	}
	
    setColor("BOLDRED");
    cout<<"In The Name Of God\n";
    setColor("RESET");
    cout<<"Welcome to SA-Arena";
    start:
    setColor("BOLDRED");
    cout<<"\n\nEnter your choice\n";
    setColor("RESET");
    cout<<"1: Start a new Tournament\n"<<"2: Load Recent Tournament\n";
    choice=inputChoice(1,2);
    if(choice==1){
        newtour:
        if(!enterTeams(t1,t2)) goto start;
        IS_SAVED=false;
    }
    else{
        if(!load(t1,t2,games,inpSettings)) goto start;
        //if(!loadTxt("data.txt",t1,t2,games,inpSettings)) goto start;
    }
    
    if(t1.sendid()==t2.sendid()){
        setColor("BOLDBLACK");
        cout<<"Warning!!! Error in Team Id\n\n";
        setColor("RESET");
    }
    
    //correctData(t1,t2,games,inpSettings);
    
    if(!mainMenu(t1,t2,games,inpSettings,argv[0])){
		strcpy(DATA_FILE_NAME,NULL_PATH_STRING);
		goto newtour;
	}
    return 0;
}