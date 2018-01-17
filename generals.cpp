#include "saheader.h"

int doubleToInt(double d){
	int sum=0;
	char temp[30];
	sprintf(temp,"%f",d);
	for(int i=0; temp[i]!=0 && temp[i]!='.'; i++){
		sum=(sum*10)+(temp[i]-48);
	}
	return sum;
}

int compareDoubleDecimals(double d1,double d2){
	char temp1[30];
	char temp2[30];
	sprintf(temp1,"%f",d1);
	sprintf(temp2,"%f",d2);
	
	int ind1,ind2;
	for(ind1=0; temp1[ind1]!='.'; ind1++);
	for(ind2=0; temp2[ind2]!='.'; ind2++);
	ind1++;
	ind2++;
	
	for(int i=0; 6>i; i++,ind1++,ind2++){
		if(temp1[ind1]==0 && temp2[ind2]==0) return 0;
		else if(temp1[ind1]==0) return 2;
		else if(temp2[ind2]==0) return 1;
		else{
			if(temp1[ind1]>temp2[ind2]) return 1;
			else if(temp1[ind1]<temp2[ind2]) return 2;
		}
	}
	
	return 0;
}

bool isInt(double d1){
	char temp1[30];
	sprintf(temp1,"%f",d1);
	int ind1;
	for(ind1=0; temp1[ind1]!='.'; ind1++);
	ind1++;
	for(int i=0; 6>i; i++,ind1++){
		if(temp1[ind1]!=48) return false;
	}
	return true;
}

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void swap(int a[],int b[],int n){
	for(int i=0; n>i; i++){
		int temp;
		temp=a[i];
		a[i]=b[i];
		b[i]=temp;
	}
}

bool randYesNo(){
    int min=0,max=1;
    return (min + (rand() % (int)(max - min + 1)));
}

void space(int s){
	if(s>0) for(int i=0; s>i; i++) cout<<" ";
}

void cadr_dash(int tul,bool noEndl){
	for(int i=0; tul>i; i++) cout<<"-";
	if(!noEndl) cout<<endl;
}

void print_passage(char *p){
	char space=32;
	for(int i=0; p[i]!=0 || i==0; i++){
		if(i==0){ if(p[i]==0){ cout<<"No Confrence"; break;}}
		if(p[i]==95) cout<<space;
		else cout<<p[i];
	}
}

void colorStringPrint(string str){
	if(str.find("$")>str.size()){
		cout<<str;
		return;
	}
	else{
		unsigned int size=str.size();
		for(unsigned int i=0; size>i; i++){
			if(size-4>i && str[i]=='$'){
				int num;
				string codeColor;
				codeColor=str.substr(i+2,3);
				num=getColorNum(codeColor);
				if(num>0 || (num==0 && str[i+1]=='0')){
					if(str[i+1]=='0'){
						setColor(num,false);
						i+=4;
					}
					else if(str[i+1]=='$'){
						setColor(num,true);
						i+=4;
					}
					else{
						cout<<str[i];
					}
				}
				else{
					cout<<str[i];
				}
			}
			else cout<<str[i];
		}
	}
}

int getColorNum(string color){
	if(color.compare("RST")==0) return 0;
	else if(color.compare("BLU")==0) return 1;
	else if(color.compare("GRN")==0) return 2;
	else if(color.compare("CYN")==0) return 3;
	else if(color.compare("RED")==0) return 4;
	else if(color.compare("MAG")==0) return 5;
	else if(color.compare("YEL")==0) return 6;
	else if(color.compare("WHT")==0) return 7;
	else if(color.compare("BLK")==0) return 8;
	else return -1;
}

void setColor(int num,bool bold){
    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"      // Black
    #define RED     "\033[31m"      // Red
    #define GREEN   "\033[32m"      // Green
    #define YELLOW  "\033[33m"      // Yellow
    #define BLUE    "\033[34m"      // Blue
    #define MAGENTA "\033[35m"      // Magenta
    #define CYAN    "\033[36m"      // Cyan
    #define WHITE   "\033[37m"      // White
    #define BOLDBLACK   "\033[1m\033[30m"      // Bold Black
    #define BOLDRED     "\033[1m\033[31m"      // Bold Red
    #define BOLDGREEN   "\033[1m\033[32m"      // Bold Green
    #define BOLDYELLOW  "\033[1m\033[33m"      // Bold Yellow
    #define BOLDBLUE    "\033[1m\033[34m"      // Bold Blue
    #define BOLDMAGENTA "\033[1m\033[35m"      // Bold Magenta
    #define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan
    #define BOLDWHITE   "\033[1m\033[37m"      // Bold White
    
	if(num<0 || num>8) throw -1;
	if(bold){
		if(num==0) throw -1;
		else if(num==1) cout<<BOLDBLUE;
		else if(num==2) cout<<BOLDGREEN;
		else if(num==3) cout<<BOLDCYAN;
		else if(num==4) cout<<BOLDRED;
		else if(num==5) cout<<BOLDMAGENTA;
		else if(num==6) cout<<BOLDYELLOW;
		else if(num==7) cout<<BOLDWHITE;
		else if(num==8) cout<<BOLDBLACK;
	}
	else{
		if(num==0) cout<<RESET;
		else if(num==1) cout<<BLUE;
		else if(num==2) cout<<GREEN;
		else if(num==3) cout<<CYAN;
		else if(num==4) cout<<RED;
		else if(num==5) cout<<MAGENTA;
		else if(num==6) cout<<YELLOW;
		else if(num==7) cout<<WHITE;
		else if(num==8) cout<<BLACK;
	}
}

void setColor(int num){
    setColor(num,false);
}

void setColor(const char *color){
    if(strcasecmp(color,"RESET")==0) setColor(0);
    else if(strcasecmp(color,"BLUE")==0) setColor(1);
    else if(strcasecmp(color,"GREEN")==0) setColor(2);
    else if(strcasecmp(color,"CYAN")==0) setColor(3);
    else if(strcasecmp(color,"RED")==0) setColor(4);
    else if(strcasecmp(color,"MAGENTA")==0) setColor(5);
    else if(strcasecmp(color,"YELLOW")==0) setColor(6);
    else if(strcasecmp(color,"WHITE")==0) setColor(7);
    else if(strcasecmp(color,"BLACK")==0) setColor(8);
    
    else if(strcasecmp(color,"BOLDBLUE")==0) setColor(1,true);
    else if(strcasecmp(color,"BOLDGREEN")==0) setColor(2,true);
    else if(strcasecmp(color,"BOLDCYAN")==0) setColor(3,true);
    else if(strcasecmp(color,"BOLDRED")==0) setColor(4,true);
    else if(strcasecmp(color,"BOLDMAGENTA")==0) setColor(5,true);
    else if(strcasecmp(color,"BOLDYELLOW")==0) setColor(6,true);
    else if(strcasecmp(color,"BOLDWHITE")==0) setColor(7,true);
    else if(strcasecmp(color,"BOLDBLACK")==0) setColor(8,true);
    else throw -1;
}

void ccsPrint(stringstream &s1){
	string str=s1.str();
	colorStringPrint(str);
}

int sstreamLength(stringstream &s1){
    string str;
    str=s1.str();
    int length=0;
	if(str.find("$")>str.size()){
            length=str.size();
		return length;
	}
	else{
		unsigned int size=str.size();
		for(unsigned int i=0; size>i; i++){
			if(size-4>i && str[i]=='$'){
				int num;
				string codeColor;
				codeColor=str.substr(i+2,3);
				num=getColorNum(codeColor);
				if(num>0 || (num==0 && str[i+1]=='0')){
					if(str[i+1]=='0'){
						i+=4;
					}
					else if(str[i+1]=='$'){
						i+=4;
					}
					else{
                        length++;
					}
				}
				else{
                    length++;
				}
			}
			else length++;
		}
	}
        return length;
}

void beforeStrWhere(stringstream &a,int zarf){
	int len=sstreamLength(a);
	int s=(zarf-len)/2;
	for(int i=0; s>i; i++) cout<<" ";
	ccsPrint(a);
}

void strwhere(stringstream &a,int zarf,int halat){
	int len=sstreamLength(a);
	int s=(zarf-len)/2;
	if(halat==0) setColor("RESET");
	for(int i=0; s>i; i++) cout<<" ";
	ccsPrint(a);
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}

void strwhere(stringstream &a,int zarf){
    strwhere(a,zarf,0);
}

void beforeStrWhere(const char*a,int zarf){
	int len=strlen(a);
	int s=(zarf-len)/2;
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
}

void strwhere(const char *a,int zarf,int halat){
	int len=strlen(a);
	int s=(zarf-len)/2;
	if(halat==0) setColor("RESET");
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}

void strwhere(const char *a,int zarf){
    strwhere(a,zarf,0);
}

int generateNewPrId(team tm1,team tm2){
    bool correct;
    int min=1000;
    int max=9999;
    int id;
    do{
        correct=true;
        id = min + (rand() % (int)(max - min + 1));
        for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++){
            if(tm1.getPrFromIndex(i).getId()==id){
                correct=false;
                continue;
            }
        }
        for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++){
            if(tm2.getPrFromIndex(i).getId()==id){
                correct=false;
                continue;
            }
        }
    } while(!correct);
    return id;
}

bool existFile(char* fileName){
	fstream f1(fileName , ios::in | ios::binary);
    if(!f1){
        f1.close();
        return false;
    }
    f1.close();
    return true;
}

bool isDataFileAndReady(istream& f1){
    string type;
    int size;
    char *buf;
	f1.read(reinterpret_cast<char *>(&size), sizeof(int));
	buf = new char[size];
	f1.read(buf, size);
	type = "";
	type.append(buf, size);
    if(type.compare("SA_SaveData")==0){
        return true;
    }
    return false;
}

bool isDataFile(char* fileName){
    if(!existFile(fileName)) return false;
    fstream f1(fileName , ios::in | ios::binary);
    if(isDataFileAndReady(f1)){
        f1.close();
        return true;
    }
    f1.close();
    return false;
}

bool isDataFile(const char* fileName){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return isDataFile(newFileName);
}

bool lostDataWarning(team tm1,team tm2,match *m, inputProfile inpSettings,bool showWarn){
    int choice;
    start:
    if(!IS_SAVED){
        cout<<endl;
        typeWarning();
		if(showWarn) cout<<"Unsaved Data will not shown!"<<endl;
        cout<<"Do You Want to Save Changes? (1:Yes | 2:No | 3:Cancel): ";
        choice=inputChoice(1,3);
        if(choice==1){
            if(strcmp(DATA_FILE_NAME,NULL_PATH_STRING)==0) saveAs(tm1,tm2,m,inpSettings);
            else save(DATA_FILE_NAME,tm1,tm2,m,inpSettings);
            if(!IS_SAVED) goto start;
        }
        else if(choice==3) return false;
    }
    return true;
}


bool saveAs(team tm1,team tm2, match *m, inputProfile inpSettings){
    char newPath[256];
    cout<<endl<<"Enter File Name: ";
    cin.getline(newPath,256);
    if(existFile(newPath)){
        cout<<endl;
        typeWarning();
        cout<<"A file Named "<<newPath<<" Already Exists!\n";
        cout<<"Do you Want to Replace It? (1:Yes | 2:No): ";
        if(inputChoice(1,2)==2) return false;
    }
    save(newPath,tm1,tm2,m,inpSettings);
    return true;
}

bool save(char* fileName,team tm1,team tm2,match *m, inputProfile inpSettings){
    fstream f1(fileName , ios::in | ios::binary);
    int choice=1;
    if(f1){
        cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
    }
    
	if(choice==1){
        string type("SA_SaveData");
        int size = (type.size());
		fstream f1(fileName , ios::out | ios::binary);
        f1.write(reinterpret_cast<char *>(&size), sizeof(int));
        f1.write(type.c_str(), size);
        
        f1.write((char *)&inpSettings,sizeof(inpSettings));
		f1.write((char *)&tm1,sizeof(tm1));
		f1.write((char *)&tm2,sizeof(tm2));
		f1.write((char *)m,sizeof(match)*200);
        f1.flush();
		f1.close();
        
        strcpy(DATA_FILE_NAME,fileName);
        FileNames flnames;
        flnames.load();
        flnames.append(fileName);
		
        IS_SAVED=true;
        
        setColor("BOLDGREEN");
		cout<<"Tournament Saved Successfuly.\n";
        setColor("RESET");
        return true;
	}
    return false;
}

bool save(const char* fileName,team tm1,team tm2,match *m, inputProfile inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return save(newFileName,tm1,tm2,m,inpSettings);
}

bool saveTxt(char* fileName,team tm1,team tm2,match *m,inputProfile inpSettings){
	int choice;
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
    choice=inputChoice(1,2);
	if(choice==1){
		fstream f1("data.txt" , ios::out);
        inpSettings.saveTxt(f1);
		tm1.saveTxt(f1);
		tm2.saveTxt(f1);
		int t;
		for(t=0; m[t].sendexist(); t++);
		f1<<t<<endl;
		for(int i=0; t>i; i++) m[i].saveTxt(f1);
		f1.close();
        setColor("BOLDGREEN");
		cout<<"Tournament Saved Successfuly.\n";
        setColor("RESET");
        return true;
	}
    return false;
}

bool saveTxt(const char* fileName,team tm1,team tm2,match *m,inputProfile inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return saveTxt(newFileName,tm1,tm2,m,inpSettings);
}


bool load(team &tm1, team &tm2, match *m,inputProfile& inpSettings){
    if(!lostDataWarning(tm1,tm2,m,inpSettings)) return false;
    
    char fileName[256];
    FileNames flnames;
    flnames.load();
    if(!flnames.choiceMenu(fileName)) return false;
    
    fstream f1(fileName , ios::in | ios::binary);
    if(!isDataFileAndReady(f1)) throw-1;
    
    f1.read((char *)&inpSettings, sizeof(inpSettings));
    f1.read((char *)&tm1, sizeof(tm1));
    f1.read((char *)&tm2, sizeof(tm2));
    f1.read((char *)m, sizeof(match)*200);
    f1.close();
    setColor("BOLDGREEN");
    cout<<fileName<<" Loaded Successfully.\n";
    setColor("RESET");
    strcpy(DATA_FILE_NAME,fileName);
	IS_SAVED=true;
    return true;
}

/*bool load(const char* fileName,team &tm1, team &tm2, match *m){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return load(newFileName,tm1,tm2,m);
}*/

bool loadTxt(char* fileName,team &tm1, team &tm2, match *m, inputProfile &inpSettings){
	fstream f1("data.txt" , ios::in);
    if(!f1){
        printError("Save File (data.txt) Not Found!\n");
        return false;
    }
        
	int choice;
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
    choice=inputChoice(1,2);
	if(choice==1){
        inpSettings.loadTxt(f1);
        tm1.loadTxt(f1);
        tm2.loadTxt(f1);
        int t;
        f1>>t;
        f1.ignore();
        for(int i=0; t>i; i++) m[i].loadTxt(f1); 
        f1.close();
        setColor("BOLDGREEN");
        cout<<"Tornoment Loaded Successfuly.\n";
        setColor("RESET");
        return true;
    }
    return false;
}

bool loadTxt(const char* fileName,team &tm1, team &tm2, match *m, inputProfile &inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return loadTxt(newFileName,tm1,tm2,m,inpSettings);
}

bool exitApp(team tm1,team tm2,match *m,inputProfile inpSettings){
    if(lostDataWarning(tm1,tm2,m,inpSettings)) return true;
    return false;
}

bool enterTeams(team& tm1,team& tm2){
    int i=0;
    do{ 
        if(i>0){
            cout<<endl;
            printError("Two Id Are The Same !!! Try Again.\n");
        }
        setColor("BOLDRED");
        cout<<"\nTeam 1:\n";
        setColor("RESET");
        if(!tm1.input()) return false;
        setColor("BOLDRED");
        cout<<"\nTeam 2:\n";
        setColor("RESET");
        if(!tm2.input()) return false;
        i++;
    } while(tm1.sendid()==tm2.sendid());
    return true;
}

bool mainMenu(team& t1,team& t2,match *games,inputProfile& inpSettings,const char* arg){
    while(true){
        int num=0;
        bool canSave=strcmp(DATA_FILE_NAME,NULL_PATH_STRING)!=0;
        setColor("BOLDRED");
        cout<<"\nMenu: \n";
        setColor("RESET");
        cout<<++num<<": ";
        t1.printname();
        cout<<"\n"<<++num<<": ";
        t2.printname();
        cout<<endl<<++num<<": External Squads\n";
		cout<<++num<<": Add match\n";
        cout<<++num<<": Edit Match\n";
        cout<<++num<<": Show match\n";
        cout<<++num<<": Competition Stats\n";
        cout<<++num<<": Repair details\n";
        cout<<++num<<": Game Input Settings\n";
        cout<<++num<<": New Tournament\n";
        cout<<++num<<": Load\n";
        if(canSave) cout<<num+1<<": Save\n";
        cout<<num+1+canSave<<": Save As\n";
        cout<<num+2+canSave<<": Exit\n";
        
        cout<<"\nEnter your choice: ";
        int choice = inputChoice(1,num+2+canSave);
        if(choice==1) t1.teamManage(t2);
        else if(choice==2) t2.teamManage(t1);
		else if(choice==3 && lostDataWarning(t1,t2,games,inpSettings,true)) externalShowAllPrs(arg);
        else if(choice==4) add_game(games,t1,t2,inpSettings);
        else if(choice==5) editGame(games,t1,t2);
        else if(choice==6) show_game(games,t1,t2);
        else if(choice==7) competition_stats(t1,t2,games);
        else if(choice==8) details_repair(games,t1,t2);
        else if(choice==9) inpSettings.settings();
        else if(choice==10 && exitApp(t1,t2,games,inpSettings)) return false;
        
        else if(choice==11) load(t1,t2,games,inpSettings);
        //else if(choice==10) loadTxt("data.txt",t1,t2,games,inpSettings);
        
        else if(choice==11+1 && canSave) save(DATA_FILE_NAME,t1,t2,games,inpSettings);
        else if(choice==11+1+canSave) saveAs(t1,t2,games,inpSettings);
        //else if(choice==10+1) saveTxt("data.txt",t1,t2,games,inpSettings);
        
        else if(choice==(11+2+canSave) && exitApp(t1,t2,games,inpSettings)) return true;
    }
}

void competition_stats(team tm1,team tm2,match m[200]){
	int choice;
	competition league(tm1,tm2,m);
	
	if(!m[0].sendexist()){
		cout<<endl<<"No Recorded Match For Stats!"<<endl;
	}
	
	while(1){
		cout<<"\n";
		setColor("BOLDRED");
        cout<<"Competition Stats:\n";
        setColor("RESET");
		cout<<"1: Compare Teams\n2: Results Graph\n3: See Most\n4: Goals Times\n5: Best Solo Performance\n"
		<<"6: Subsume Players\n7: Winners Against Loosers\n8: Back to main\n\nEnter your choice: ";
        choice=inputChoice(1,8);
		switch(choice){
			//case 1: league.compareTeams(); break;
			case 1: league.revCompareTeams(); break;
			case 2: league.printGraphResults(); break;
			case 3: league.printMost(); break;
			case 4: league.printGoalTimes(); break;
			case 5: league.printBestSoloPerformance(); break;
			case 6: league.subsumePlayers(); break;
			case 7: league.WinnerAgLooser(); break;
		}
		if (choice==8) break;
	}
}

int getNumGames(match *m){
	int num;
	for(num=0; m[num].sendexist(); num++);
	return num;
}

void add_game(match *m,team &tm1,team &tm2, inputProfile & inpSettings){
	int i;
	for(i=0; 200>i && m[i].exist==1; i++);
	if(i==200){
		cout<<endl<<"Zarfiate afzudane bazi vojud nadarad.\n";
	}
	else{
		cout<<"\nGame "<<i+1<<":\n";
		m[i].input_game(tm1,tm2,inpSettings);
		m[i].update_after_game(tm1,tm2);
	}
}

int choiceMatch(match *m,team tm1,team tm2){
	int number;
	cout<<endl;
    setColor("BOLDRED");
    cout<<"Recorded Games:\n";
    setColor("RESET");
    for(number=0; m[number].sendexist(); number++){
		int tm1Goals,tm2Goals;
		tm1Goals=m[number].dynamicGet("t1_goals");
		tm2Goals=m[number].dynamicGet("t2_goals");
		if(tm1Goals>tm2Goals) setColor("BOLDMAGENTA");
		else if(tm1Goals<tm2Goals) setColor("BOLDCYAN");
		else if(tm1Goals==tm2Goals) setColor("BOLDWHITE");
        cout<<number+1<<": ";
		setColor("RESET");
		cout<<tm1.getName()<<" "<<tm1Goals
        <<"-"<<tm2Goals<<" "<<tm2.getName()<<endl;
    }
    cout<<number+1<<": Back to Main Menu\n";
    cout<<endl<<"Enter Your Choice: ";
    int choice=inputChoice(1,number+1);
    if(choice==number+1) return -1;
	return choice;
}

void externalShowAllPrs(const char* arg){
	if(strcmp(DATA_FILE_NAME,NULL_PATH_STRING)==0){
		cout<<endl;
		typeError();
		cout<<"Save Data Not Found!"<<endl;
		return;
	}
	
	char command[150];
	//sprintf(command,"gnome-terminal --command=./%s __players %s",EXE_APP_NAME,DATA_FILE_NAME);
	sprintf(command,"gnome-terminal -e \"./%s __players %s\" --geometry==44x41",arg,DATA_FILE_NAME);
	system(command);
}

void editGame(match *m,team &tm1,team &tm2){
    if(!m[0].sendexist()){
        cout<<endl<<"There is No Recorded Game For Edit!"<<endl;
        return;
    }
    while(true){
		int choice;
		choice=choiceMatch(m,tm1,tm2);
        if(choice==-1) break;
        m[choice-1].editGame(tm1,tm2);
		
		cout<<endl;
		setColor("BOLDRED");
		cout<<"Next Work?"<<endl;
		setColor("RESET");
		cout<<"1: Edit Another Game\n2: Back To Main Menu\n";
		cout<<"Enter Your Choice: ";
		if(inputChoice(1,2)==2) break;
    }
    silentDetailsRepair(m,tm1,tm2);
}

void silentDetailsRepair(match *m,team &tm1,team &tm2){
    for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++) tm1.pr[i].zero();
	for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++) tm2.pr[i].zero();
	tm1.zero();
	tm2.zero();
	for(int i=0; m[i].sendexist(); i++){
		m[i].update_after_game(tm1,tm2,true);
    }
    IS_SAVED=false;
}

void details_repair(match *m,team &tm1,team &tm2){
	int tp1,tp2,choice;
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	cout<<endl<<"Do you want to Repair details? (1:Yes | 2:No)\n";
    choice=inputChoice(1,2);
	if(choice==2) return;
	else{
		for(int i=0; tp1>i; i++) tm1.pr[i].zero();
		for(int i=0; tp2>i; i++) tm2.pr[i].zero();
		tm1.zero();
		tm2.zero();
		for(int i=0; m[i].sendexist()==1; i++){
			cout<<"Game "<<i+1<<": "; 
			m[i].update_after_game(tm1,tm2);
        }
        IS_SAVED=false;
	}
}

void show_game(match *m,team tm1,team tm2){
    if(!m[0].sendexist()){
        cout<<endl<<"There is No Recorded Game For Show!"<<endl;
        return;
    }
    while(true){
		int choice;
		choice=choiceMatch(m,tm1,tm2);
		if(choice==-1) break;
        m[choice-1].show(tm1,tm2);
		
		cout<<endl;
		setColor("BOLDRED");
		cout<<"Next Work?"<<endl;
		setColor("RESET");
		cout<<"1: Show Another Game\n2: Back To Main Menu\n";
		cout<<"Enter Your Choice: ";
		if(inputChoice(1,2)==2) break;
    }
}

void newTermPlayers(team tm1,team tm2,match *m){
	int numPrs1=tm1.getNumPrs();
	int numPrs2=tm2.getNumPrs();
	int maxNumPrs;
	if(numPrs1>numPrs2) maxNumPrs=numPrs1;
	else maxNumPrs=numPrs2;
	
	cout<<endl;
	char charCommand[80];
	sprintf(charCommand,"resize -s %d %d",maxNumPrs+5,44);
	system(charCommand);
	cout<<endl;
	
	system("reset");
	
	bool t1PrintedPrs[200];
	bool t2PrintedPrs[200];
	int t1Ids[200];
	int t2Ids[200];
	for(int i=0; 200>i; i++) t1PrintedPrs[i]=false;
	for(int i=0; 200>i; i++) t2PrintedPrs[i]=false;
	
	int numGames=getNumGames(m);
	int t1Index=0;
	int t2Index=0;
	for(int i=1; 5>=i && numGames-i>=0 ;i++){
		for(int j=0; 11>j; j++){
			if(m[numGames-i].t1_prs[j]>0){
				int Id=m[numGames-i].t1_prs[j];
				int Index=tm1.getPrIndexFromId(Id);
				if(t1PrintedPrs[Index]) continue;
				t1PrintedPrs[Index]=true;
				t1Ids[t1Index++]=Id;
			}
		}
		
		for(int j=0; 11>j; j++){
			if(m[numGames-i].t2_prs[j]>0){
				int Id=m[numGames-i].t2_prs[j];
				int Index=tm2.getPrIndexFromId(Id);
				if(t2PrintedPrs[Index]) continue;
				t2PrintedPrs[Index]=true;
				t2Ids[t2Index++]=Id;
			}
		}
		
		for(int j=0; 3>j; j++){
			if(m[numGames-i].t1_tvz[j]>0){
				int Id=m[numGames-i].t1_tvz[j];
				int Index=tm1.getPrIndexFromId(Id);
				if(t1PrintedPrs[Index]) continue;
				t1PrintedPrs[Index]=true;
				t1Ids[t1Index++]=Id;
			}
		}
		
		for(int j=0; 3>j; j++){
			if(m[numGames-i].t2_tvz[j]>0){
				int Id=m[numGames-i].t2_tvz[j];
				int Index=tm2.getPrIndexFromId(Id);
				if(t2PrintedPrs[Index]) continue;
				t2PrintedPrs[Index]=true;
				t2Ids[t2Index++]=Id;
			}
		}
	}
	
	
	for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++){
		int Index=i;
		int Id=tm1.getPrFromIndex(i).getId();
		if(t1PrintedPrs[Index]) continue;
		t1PrintedPrs[Index]=true;
		t1Ids[t1Index++]=Id;
	}
	
	for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++){
		int Index=i;
		int Id=tm2.getPrFromIndex(i).getId();
		if(t2PrintedPrs[Index]) continue;
		t2PrintedPrs[Index]=true;
		t2Ids[t2Index++]=Id;
	}
	
	int t1NumPrs=t1Index;
	int t2NumPrs=t2Index;
	
	
	int t=20;
	int tDash=42;
	stringstream cadr;
	cadr<<"$$BLU";
	setColor("BOLDBLUE");
	beforeStrWhere("Teams Squad List",tDash);
	setColor("RESET");
	cout<<endl;
	ccsPrint(cadr); space(1); cadr_dash(tDash); setColor("RESET");
	for(int i=0; t1NumPrs>i || t2NumPrs>i; i++){
		stringstream p1;
		stringstream p2;
		p1<<"$0MAG";
		p2<<"$0CYN";
		
		if(t1NumPrs>i) p1<<tm1.getPrFromId(t1Ids[i]).getNumber()<<": "<<tm1.getPrFromId(t1Ids[i]).sendname()<<"$0RST";
		else p1<<"$0RST";
		
		if(t2NumPrs>i) p2<<tm2.getPrFromId(t2Ids[i]).getNumber()<<": "<<tm2.getPrFromId(t2Ids[i]).sendname()<<"$0RST";
		else p2<<"$0RST";
		
		ccsPrint(cadr);
		cout<<" |";
		setColor("RESET");
		
		strwhere(p1,t,1);
		strwhere(p2,t,1);	

		ccsPrint(cadr);
		cout<<"|";
		setColor("RESET");
		cout<<endl;
	}
	ccsPrint(cadr); space(1); cadr_dash(tDash); setColor("RESET");
}


void showWALTable(teamGameStat teamOne,teamGameStat teamTwo,bool showCards, bool showSubs){
	int s,t,c,ttitle;
	stringstream ts1[14];
	stringstream ts2[14];
	stringstream cadr;
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	
	bool exGoals=true;
	bool exPossess=(teamOne.possess!=-2 && teamTwo.possess!=-2);
	bool exShots=((teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) && (teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2));
	bool exFouls=((teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) && (teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2));
	bool exCorners=(teamOne.corners!=-2 && teamTwo.corners!=-2);
	bool exFk=(teamOne.fk!=-2 && teamTwo.fk!=-2);
	bool exPassC=(teamOne.passC!=-2 && teamTwo.passC!=-2);
	bool exCross=(teamOne.cross!=-2 && teamTwo.cross!=-2);
	bool exInterc=(teamOne.interc!=-2 && teamTwo.interc!=-2);
	bool exTackles=(teamOne.tackles!=-2 && teamTwo.tackles!=-2);
	bool exSaves=(teamOne.saves!=-2 && teamTwo.saves!=-2);
	bool exCards=((teamOne.nCards[0]!=-2 && teamOne.nCards[1]!=-2)
	&& (teamTwo.nCards[0]!=-2 && teamTwo.nCards[1]!=-2) && showCards);
	bool exSubs=(teamOne.nSub!=-2 && teamTwo.nSub!=-2 && showSubs);
	
	if(teamOne.nGoals==-2) ts1[0]<<"UK"; else ts1[0]<<setprecision(2)<<teamOne.nGoals;
	if(teamTwo.nGoals==-2) ts2[0]<<"UK"; else ts2[0]<<setprecision(2)<<teamTwo.nGoals;
	if(teamOne.possess==-2) ts1[1]<<"UK"; else ts1[1]<<setprecision(2)<<teamOne.possess<<"%";
	if(teamTwo.possess==-2) ts2[1]<<"UK"; else ts2[1]<<setprecision(2)<<teamTwo.possess<<"%";
	
	if(teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) ts1[2]<<setprecision(2)<<teamOne.shots[0]<<"("<<setprecision(2)<<teamOne.shots[1]<<")";
	if(teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2) ts2[2]<<setprecision(2)<<teamTwo.shots[0]<<"("<<setprecision(2)<<teamTwo.shots[1]<<")";
	if(teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) ts1[3]<<setprecision(2)<<teamOne.fouls[0]<<"("<<setprecision(2)<<teamOne.fouls[1]<<")";
	if(teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2) ts2[3]<<setprecision(2)<<teamTwo.fouls[0]<<"("<<setprecision(2)<<teamTwo.fouls[1]<<")";
	
	if(teamOne.corners==-2) ts1[4]<<"UK"; else ts1[4]<<setprecision(2)<<teamOne.corners;
	if(teamTwo.corners==-2) ts2[4]<<"UK"; else ts2[4]<<setprecision(2)<<teamTwo.corners;
	if(teamOne.fk==-2) ts1[5]<<"UK"; else ts1[5]<<setprecision(2)<<teamOne.fk;
	if(teamTwo.fk==-2) ts2[5]<<"UK"; else ts2[5]<<setprecision(2)<<teamTwo.fk;
	if(teamOne.passC==-2) ts1[6]<<"UK"; else ts1[6]<<setprecision(2)<<teamOne.passC<<"%";
	if(teamTwo.passC==-2) ts2[6]<<"UK"; else ts2[6]<<setprecision(2)<<teamTwo.passC<<"%";
	if(teamOne.cross==-2) ts1[7]<<"UK"; else ts1[7]<<setprecision(2)<<teamOne.cross;
	if(teamTwo.cross==-2) ts2[7]<<"UK"; else ts2[7]<<setprecision(2)<<teamTwo.cross;
	if(teamOne.interc==-2) ts1[8]<<"UK"; else ts1[8]<<setprecision(2)<<teamOne.interc;
	if(teamTwo.interc==-2) ts2[8]<<"UK"; else ts2[8]<<setprecision(2)<<teamTwo.interc;
	if(teamOne.tackles==-2) ts1[9]<<"UK"; else ts1[9]<<setprecision(2)<<teamOne.tackles;
	if(teamTwo.tackles==-2) ts2[9]<<"UK"; else ts2[9]<<setprecision(2)<<teamTwo.tackles;
	if(teamOne.saves==-2) ts1[10]<<"UK"; else ts1[10]<<setprecision(2)<<teamOne.saves;
	if(teamTwo.saves==-2) ts2[10]<<"UK"; else ts2[10]<<setprecision(2)<<teamTwo.saves;
	
	if(teamOne.nCards[0]!=-2 && teamOne.nCards[1]!=-2){
		ts1[11]<<setprecision(2)<<teamOne.nCards[0];
		ts1[12]<<setprecision(2)<<teamOne.nCards[1];
	}
	
	if(teamTwo.nCards[0]!=-2 && teamTwo.nCards[1]!=-2){
		ts2[11]<<setprecision(2)<<teamTwo.nCards[0];
		ts2[12]<<setprecision(2)<<teamTwo.nCards[1];
	}
	
	if(teamOne.nSub==-2) ts1[13]<<"UK"; else ts1[13]<<setprecision(2)<<teamOne.nSub;
	if(teamTwo.nSub==-2) ts2[13]<<"UK"; else ts2[13]<<setprecision(2)<<teamTwo.nSub;
	
	/*if(teamOne.shots[0]==-2 || teamOne.shots[1]==-2){
		if(teamOne.shots[0]==-2 && teamOne.shots[1]==-2) ts1[2]<<"UK";
		else if(teamOne.shots[0]==-2) ts1[2]<<"UK("<<setprecision(2)<<teamOne.shots[1]<<")";
		else ts1[2]<<setprecision(2)<<teamOne.shots[0]<<"(UK)";
	}
	
	if(teamTwo.shots[0]==-2 || teamTwo.shots[1]==-2){
		if(teamTwo.shots[0]==-2 && teamTwo.shots[1]==-2) ts2[2]<<"UK";
		else if(teamTwo.shots[0]==-2) ts2[2]<<"UK("<<setprecision(2)<<teamTwo.shots[1]<<")";
		else ts2[2]<<setprecision(2)<<teamTwo.shots[0]<<"(UK)";
	}
	
	if(teamOne.fouls[0]==-2 || teamOne.fouls[1]==-2){
		if(teamOne.fouls[0]==-2 && teamOne.fouls[1]==-2) ts1[3]<<"UK";
		else if(teamOne.fouls[0]==-2) ts1[3]<<"UK("<<setprecision(2)<<teamOne.fouls[1]<<")";
		else ts1[3]<<setprecision(2)<<teamOne.fouls[0]<<"(UK)";
	}
	
	if(teamTwo.fouls[0]==-2 || teamTwo.fouls[1]==-2){
		if(teamTwo.fouls[0]==-2 && teamTwo.fouls[1]==-2) ts2[3]<<"UK";
		else if(teamTwo.fouls[0]==-2) ts2[3]<<"UK("<<setprecision(2)<<teamTwo.fouls[1]<<")";
		else ts2[3]<<setprecision(2)<<teamTwo.fouls[0]<<"(UK)";
	}*/

	cadr<<"$$BLU";
	s=15;
	t=10;
	ttitle=22;
	c=ttitle+(2*t)+2;
	
	temp1.str("");
	cout<<endl;
	temp1<<"$$RED"<<teamOne.name<<" Against "<<teamTwo.name<<"$0RST";
	space(s); beforeStrWhere(temp1,c); cout<<endl<<endl;

	space(s); ccsPrint(cadr); cadr_dash(c);
	space(s); cout<<"|"; setColor("BOLDCYAN"); strwhere(teamOne.name,t,1); setColor("BOLDBLUE"); strwhere("Stats",ttitle,1); setColor("BOLDCYAN"); strwhere(teamTwo.name,t,1); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	
	if(exGoals){ space(s); cout<<"|"; strwhere(ts1[0],t); strwhere("Goals Scored",ttitle); strwhere(ts2[0],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	
	if(exCards){
		space(s); cout<<"|"; strwhere(ts1[11],t); strwhere("Yellow Cards",ttitle); strwhere(ts2[11],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
		space(s); cout<<"|"; strwhere(ts1[12],t); strwhere("Red Cards",ttitle); strwhere(ts2[12],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	}
	if(exSubs){ space(s); cout<<"|"; strwhere(ts1[13],t); strwhere("Number Of Subs",ttitle); strwhere(ts2[13],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	
	if(exPossess){ space(s); cout<<"|"; strwhere(ts1[1],t); strwhere("Possession",ttitle); strwhere(ts2[1],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exShots){ space(s); cout<<"|"; strwhere(ts1[2],t); strwhere("Shots (On Target)",ttitle); strwhere(ts2[2],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exFouls){ space(s); cout<<"|"; strwhere(ts1[3],t); strwhere("Fouls (Offside)",ttitle); strwhere(ts2[3],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exCorners){ space(s); cout<<"|"; strwhere(ts1[4],t); strwhere("Corner Kicks",ttitle); strwhere(ts2[4],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exFk){ space(s); cout<<"|"; strwhere(ts1[5],t); strwhere("Free Kicks",ttitle); strwhere(ts2[5],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exPassC){ space(s); cout<<"|"; strwhere(ts1[6],t); strwhere("Passes Completed (%)",ttitle); strwhere(ts2[6],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exCross){ space(s); cout<<"|"; strwhere(ts1[7],t); strwhere("Crosses",ttitle); strwhere(ts2[7],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exInterc){ space(s); cout<<"|"; strwhere(ts1[8],t); strwhere("Interception",ttitle); strwhere(ts2[8],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exTackles){ space(s); cout<<"|"; strwhere(ts1[9],t); strwhere("Tackles",ttitle); strwhere(ts2[9],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exSaves){ space(s); cout<<"|"; strwhere(ts1[10],t); strwhere("Saves",ttitle); strwhere(ts2[10],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
}

void correctData(team &tm1, team &tm2, match *m,inputProfile &inpSettings){
    for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++) tm1.pr[i].setOverall(-2);
    for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++) tm2.pr[i].setOverall(-2);
    for(int i=0; m[i].sendexist(); i++){
        for(int j=0; 11>j; j++){
            if(m[i].t1_prs[j]==-2) m[i].t1_pov[j]=-1;
            else m[i].t1_pov[j]=-2;
        }
        for(int j=0; 11>j; j++){
            if(m[i].t2_prs[j]==-2) m[i].t2_pov[j]=-1;
            else m[i].t2_pov[j]=-2;
        }
        for(int j=0; 3>j; j++){
            if(m[i].t1_prs[j]<0) m[i].t1_pov[j]=-1;
            else m[i].t1_pov[j]=-2;
        }
        for(int j=0; 3>j; j++){
            if(m[i].t2_prs[j]<0) m[i].t2_pov[j]=-1;
            else m[i].t2_pov[j]=-2;
        }
        m[i].t1_left=-2;
        m[i].t1_center=-2;
        m[i].t1_right=-2;
        m[i].t2_left=-2;
        m[i].t2_center=-2;
        m[i].t2_right=-2;
    }
}