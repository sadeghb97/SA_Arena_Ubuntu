#include "saheader.h"

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
void cadr_dash(int tul){
	for(int i=0; tul>i; i++) cout<<"-";
	cout<<endl;
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

bool save(team tm1,team tm2,match *m){
	int choice;
	char temp[10];
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
	if(choice==1){
		fstream f1("data.bin" , ios::out | ios::binary);
		f1.write((char *)&tm1,sizeof(tm1));
		f1.write((char *)&tm2,sizeof(tm2));
		f1.write((char *)m,sizeof(match)*200);
		f1.close();
                setColor("BOLDGREEN");
		cout<<"Tornoment Saved Successfuly.\n";
                setColor("RESET");
                return true;
	}
        return false;
}

bool saveTxt(team tm1,team tm2,match *m){
	int choice;
	char temp[10];
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
	if(choice==1){
		fstream f1("data.txt" , ios::out);
		tm1.saveTxt(f1);
		tm2.saveTxt(f1);
		int t;
		for(t=0; m[t].sendexist(); t++);
		f1<<t<<endl;
		for(int i=0; t>i; i++) m[i].saveTxt(f1); 
		f1.close();
                setColor("BOLDGREEN");
		cout<<"Tornoment Saved Successfuly.\n";
                setColor("RESET");
                return true;
	}
        return false;
}


bool load(team &tm1, team &tm2, match *m){
	fstream f1("data.bin" , ios::in | ios::binary);
        if(!f1){
            printError("Save File (data.bin) Not Found!\n");
            return false;
        }
        
	int choice;
	char temp[10];
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
	if(choice==1){
            f1.read((char *)&tm1, sizeof(tm1));
            f1.read((char *)&tm2, sizeof(tm2));
            f1.read((char *)m, sizeof(match)*200);
            f1.close();
            setColor("BOLDGREEN");
            cout<<"Tornoment Loaded Successfuly.\n";
            setColor("RESET");
            return true;
        }
        return false;
}

bool loadTxt(team &tm1, team &tm2, match *m){
	fstream f1("data.txt" , ios::in);
        if(!f1){
            printError("Save File (data.txt) Not Found!\n");
            return false;
        }
        
	int choice;
	char temp[10];
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
	if(choice==1){
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

void mainMenu(team& t1,team& t2,match *games){
    while(true){
	cout<<BOLDRED;
        cout<<"\nMenu: \n";
        setColor("RESET");
	cout<<"1: ";
	t1.printname();
	cout<<"\n2: ";
	t2.printname();
	cout<<"\n3: Add match\n4: Show match\n5: Competition Stats\n6: Repair details\n7: Save\n8: Load\n9: Exit\n";
	cout<<"\nEnter your choice: \n";
	int choice = inputChoice(1,9);
        switch(choice){
            case 1: team_manage(t1,t2); break;
            case 2: team_manage(t2,t1); break;		
            case 3: add_game(games,t1,t2); break;
            case 4: show_game(games,t1,t2); break;
            case 5: competition_stats(t1,t2,games); break;
            case 6: details_repair(games,t1,t2); break; 
            case 7: save(t1,t2,games); break;
            case 8: load(t1,t2,games); break;
        }
        if(choice==9) break;
    }
}
void team_manage(team &tm,team other){
	char temp[10];
	int choice;
	while(1){
		cout<<"\n";
                cout<<BOLDRED;
		tm.printname();
		cout<<" Session:\n";
                setColor("RESET");
		cout<<"1: Show Team Results\n2: Add Players\n3: Edit Players\n4: Show Mini Players List \n5: Show Detailed Player List\n6: Back to main\n\nEnter your choice\n";
                choice=inputChoice(1,6);
		switch(choice){
			case 1: tm.show(); break;
			case 2: tm.add_prs(other); break;
                        case 3: tm.editPrs(other); break;
			case 4: tm.show_mini_prs(); break;
			case 5: tm.show_det_prs(); break;
		}
		if (choice==6) break;
	}
}

void competition_stats(team tm1,team tm2,match m[200]){
	char temp[10];
	int choice;
	competition league(tm1,tm2,m);
	while(1){
		cout<<"\n";
		cout<<BOLDRED;
                cout<<"Competition Stats:\n";
                setColor("RESET");
		cout<<"1: Compare Teams\n2: Results Graph\n3: See Most\n4: Goals Times\n5: Best Solo Performance\n"
		<<"6: Subsume Players\n7: Winners Against Loosers\n8: Back to main\n\nEnter your choice\n";
                choice=inputChoice(1,8);
		switch(choice){
			case 1: league.compareTeams(); break;
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

void add_game(match *m,team &tm1,team &tm2){
	int i;
	for(i=0; 200>i && m[i].exist==1; i++);
	if(i==200){
		cout<<endl<<"Zarfiate afzudane bazi vojud nadarad.\n";
	}
	else{
		cout<<"\nGame "<<i+1<<":\n";
		m[i].input_game(tm1,tm2);
		m[i].update_after_game(tm1,tm2);
	}
}


void details_repair(match *m,team &tm1,team &tm2){
	int tp1,tp2,choice;
	char temp[10];
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	cout<<endl<<"Do you want to Repair details? (1:Yes | 2:No)\n";
        choice=inputChoice(1,2);
	while(1){
		if(choice==2) break;
		else{
			for(int i=0; tp1>i; i++) tm1.pr[i].zero();
			for(int i=0; tp2>i; i++) tm2.pr[i].zero();
			tm1.zero();
			tm2.zero();
			for(int i=0; m[i].sendexist()==1; i++){
				cout<<"Game "<<i+1<<": "; 
				m[i].update_after_game(tm1,tm2);
			}
		}
		break;
	}
}

void show_game(match *g,team tm1,team tm2){
	char temp[10];
	int choice,tedad;
	for(tedad=0; g[tedad].sendexist()==1; tedad++);
	cout<<endl<<"Enter Number of Game: ";
        choice=inputChoice(1,tedad);
	choice--;
	g[choice].show(tm1,tm2);
}


void showTableStats(teamGameStat teamOne,teamGameStat teamTwo,date gameDate,bool perGame, bool showCards, bool showSubs){
	int s,t,c;
	stringstream ts1[11];
	stringstream ts2[11];
	stringstream cadr;
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	if(perGame==false){
		if(teamOne.nGoals==-2) ts1[0]<<"UK"; else ts1[0]<<teamOne.nGoals;
		if(teamTwo.nGoals==-2) ts2[0]<<"UK"; else ts2[0]<<teamTwo.nGoals;
		if(teamOne.possess==-2) ts1[1]<<"UK"; else ts1[1]<<teamOne.possess<<"%";
		if(teamTwo.possess==-2) ts2[1]<<"UK"; else ts2[1]<<teamTwo.possess<<"%";
		if(teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) ts1[2]<<teamOne.shots[0]<<"("<<teamOne.shots[1]<<")";
		if(teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2) ts2[2]<<teamTwo.shots[0]<<"("<<teamTwo.shots[1]<<")";
		if(teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) ts1[3]<<teamOne.fouls[0]<<"("<<teamOne.fouls[1]<<")";
		if(teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2) ts2[3]<<teamTwo.fouls[0]<<"("<<teamTwo.fouls[1]<<")";
		if(teamOne.corners==-2) ts1[4]<<"UK"; else ts1[4]<<teamOne.corners;
		if(teamTwo.corners==-2) ts2[4]<<"UK"; else ts2[4]<<teamTwo.corners;
		if(teamOne.fk==-2) ts1[5]<<"UK"; else ts1[5]<<teamOne.fk;
		if(teamTwo.fk==-2) ts2[5]<<"UK"; else ts2[5]<<teamTwo.fk;
		if(teamOne.passC==-2) ts1[6]<<"UK"; else ts1[6]<<teamOne.passC<<"%";
		if(teamTwo.passC==-2) ts2[6]<<"UK"; else ts2[6]<<teamTwo.passC<<"%";
		if(teamOne.cross==-2) ts1[7]<<"UK"; else ts1[7]<<teamOne.cross;
		if(teamTwo.cross==-2) ts2[7]<<"UK"; else ts2[7]<<teamTwo.cross;
		if(teamOne.interc==-2) ts1[8]<<"UK"; else ts1[8]<<teamOne.interc;
		if(teamTwo.interc==-2) ts2[8]<<"UK"; else ts2[8]<<teamTwo.interc;
		if(teamOne.tackles==-2) ts1[9]<<"UK"; else ts1[9]<<teamOne.tackles;
		if(teamTwo.tackles==-2) ts2[9]<<"UK"; else ts2[9]<<teamTwo.tackles;
		if(teamOne.saves==-2) ts1[10]<<"UK"; else ts1[10]<<teamOne.saves;
		if(teamTwo.saves==-2) ts2[10]<<"UK"; else ts2[10]<<teamTwo.saves;
		if(teamOne.shots[0]==-2 || teamOne.shots[1]==-2){
			if(teamOne.shots[0]==-2 && teamOne.shots[1]==-2) ts1[2]<<"Uk"; else if(teamOne.shots[0]==-2) ts1[2]<<"Uk("<<teamOne.shots[1]<<")"; else ts1[2]<<teamOne.shots[0]<<"(UK)";
		}
		if(teamTwo.shots[0]==-2 || teamTwo.shots[1]==-2){
			if(teamTwo.shots[0]==-2 && teamTwo.shots[1]==-2) ts2[2]<<"Uk"; else if(teamTwo.shots[0]==-2) ts2[2]<<"Uk("<<teamTwo.shots[1]<<")"; else ts2[2]<<teamTwo.shots[0]<<"(UK)";
		}
		if(teamOne.fouls[0]==-2 || teamOne.fouls[1]==-2){
			if(teamOne.fouls[0]==-2 && teamOne.fouls[1]==-2) ts1[2]<<"Uk"; else if(teamOne.fouls[0]==-2) ts1[2]<<"Uk("<<teamOne.fouls[1]<<")"; else ts1[2]<<teamOne.fouls[0]<<"(UK)";
		}
		if(teamTwo.fouls[0]==-2 || teamTwo.fouls[1]==-2){
			if(teamTwo.fouls[0]==-2 && teamTwo.fouls[1]==-2) ts2[2]<<"Uk"; else if(teamTwo.fouls[0]==-2) ts2[2]<<"Uk("<<teamTwo.fouls[1]<<")"; else ts2[2]<<teamTwo.fouls[0]<<"(UK)";
		}
	}
	
	else{
		int nDecimal=1;
		if(teamOne.nGoals==-2) ts1[0]<<"UK"; else ts1[0]<<fixed<<setprecision(nDecimal)<<teamOne.nGoals;
		if(teamTwo.nGoals==-2) ts2[0]<<"UK"; else ts2[0]<<fixed<<setprecision(nDecimal)<<teamTwo.nGoals;
		if(teamOne.possess==-2) ts1[1]<<"UK"; else ts1[1]<<fixed<<setprecision(nDecimal)<<teamOne.possess<<"%";
		if(teamTwo.possess==-2) ts2[1]<<"UK"; else ts2[1]<<fixed<<setprecision(nDecimal)<<teamTwo.possess<<"%";
		if(teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) ts1[2]<<fixed<<setprecision(nDecimal)<<teamOne.shots[0]<<"("<<fixed<<setprecision(nDecimal)<<teamOne.shots[1]<<")";
		if(teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2) ts2[2]<<fixed<<setprecision(nDecimal)<<teamTwo.shots[0]<<"("<<fixed<<setprecision(nDecimal)<<teamTwo.shots[1]<<")";
		if(teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) ts1[3]<<fixed<<setprecision(nDecimal)<<teamOne.fouls[0]<<"("<<fixed<<setprecision(nDecimal)<<teamOne.fouls[1]<<")";
		if(teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2) ts2[3]<<fixed<<setprecision(nDecimal)<<teamTwo.fouls[0]<<"("<<fixed<<setprecision(nDecimal)<<teamTwo.fouls[1]<<")";
		if(teamOne.corners==-2) ts1[4]<<"UK"; else ts1[4]<<fixed<<setprecision(nDecimal)<<teamOne.corners;
		if(teamTwo.corners==-2) ts2[4]<<"UK"; else ts2[4]<<fixed<<setprecision(nDecimal)<<teamTwo.corners;
		if(teamOne.fk==-2) ts1[5]<<"UK"; else ts1[5]<<fixed<<setprecision(nDecimal)<<teamOne.fk;
		if(teamTwo.fk==-2) ts2[5]<<"UK"; else ts2[5]<<fixed<<setprecision(nDecimal)<<teamTwo.fk;
		if(teamOne.passC==-2) ts1[6]<<"UK"; else ts1[6]<<fixed<<setprecision(nDecimal)<<teamOne.passC<<"%";
		if(teamTwo.passC==-2) ts2[6]<<"UK"; else ts2[6]<<fixed<<setprecision(nDecimal)<<teamTwo.passC<<"%";
		if(teamOne.cross==-2) ts1[7]<<"UK"; else ts1[7]<<fixed<<setprecision(nDecimal)<<teamOne.cross;
		if(teamTwo.cross==-2) ts2[7]<<"UK"; else ts2[7]<<fixed<<setprecision(nDecimal)<<teamTwo.cross;
		if(teamOne.interc==-2) ts1[8]<<"UK"; else ts1[8]<<fixed<<setprecision(nDecimal)<<teamOne.interc;
		if(teamTwo.interc==-2) ts2[8]<<"UK"; else ts2[8]<<fixed<<setprecision(nDecimal)<<teamTwo.interc;
		if(teamOne.tackles==-2) ts1[9]<<"UK"; else ts1[9]<<fixed<<setprecision(nDecimal)<<teamOne.tackles;
		if(teamTwo.tackles==-2) ts2[9]<<"UK"; else ts2[9]<<fixed<<setprecision(nDecimal)<<teamTwo.tackles;
		if(teamOne.saves==-2) ts1[10]<<"UK"; else ts1[10]<<fixed<<setprecision(nDecimal)<<teamOne.saves;
		if(teamTwo.saves==-2) ts2[10]<<"UK"; else ts2[10]<<fixed<<setprecision(nDecimal)<<teamTwo.saves;
		if(teamOne.shots[0]==-2 || teamOne.shots[1]==-2){
			if(teamOne.shots[0]==-2 && teamOne.shots[1]==-2) ts1[2]<<"Uk"; else if(teamOne.shots[0]==-2) ts1[2]<<"Uk("<<fixed<<setprecision(nDecimal)<<teamOne.shots[1]<<")"; else ts1[2]<<fixed<<setprecision(nDecimal)<<teamOne.shots[0]<<"(UK)";
		}
		if(teamTwo.shots[0]==-2 || teamTwo.shots[1]==-2){
			if(teamTwo.shots[0]==-2 && teamTwo.shots[1]==-2) ts2[2]<<"Uk"; else if(teamTwo.shots[0]==-2) ts2[2]<<"Uk("<<fixed<<setprecision(nDecimal)<<teamTwo.shots[1]<<")"; else ts2[2]<<fixed<<setprecision(nDecimal)<<teamTwo.shots[0]<<"(UK)";
		}
		if(teamOne.fouls[0]==-2 || teamOne.fouls[1]==-2){
			if(teamOne.fouls[0]==-2 && teamOne.fouls[1]==-2) ts1[2]<<"Uk"; else if(teamOne.fouls[0]==-2) ts1[2]<<"Uk("<<fixed<<setprecision(nDecimal)<<teamOne.fouls[1]<<")"; else ts1[2]<<fixed<<setprecision(nDecimal)<<teamOne.fouls[0]<<"(UK)";
		}
		if(teamTwo.fouls[0]==-2 || teamTwo.fouls[1]==-2){
			if(teamTwo.fouls[0]==-2 && teamTwo.fouls[1]==-2) ts2[2]<<"Uk"; else if(teamTwo.fouls[0]==-2) ts2[2]<<"Uk("<<fixed<<setprecision(nDecimal)<<teamTwo.fouls[1]<<")"; else ts2[2]<<fixed<<setprecision(nDecimal)<<teamTwo.fouls[0]<<"(UK)";
		}
	}
	temp1.str("");
	cout<<endl;
        cout<<BOLDRED;
	temp1<<teamOne.name<<" Against "<<teamTwo.name;
	if(perGame==false){ space(26); ccsPrint(temp1); setColor("RESET");}
	else{ space(28); ccsPrint(temp1); setColor("RESET");}
	temp1.str("");
	if(gameDate.isEmpty==false && gameDate.year!=-2){
		cout<<endl;
		temp1<<"$$WHT"<<"Date: ";
		temp1<<gameDate.year;
		if(gameDate.month!=-2 && gameDate.month>9) temp1<<"/"<<gameDate.month; else if(gameDate.month!=-2 && gameDate.month<10)temp1<<"/"<<"0"<<gameDate.month;
		if(gameDate.month!=-2 && gameDate.day!=-2 && gameDate.day>9) temp1<<"/"<<gameDate.day<<"$0RST"<<endl; else if(gameDate.day!=-2 && gameDate.day<10)temp1<<"/"<<"0"<<gameDate.day<<"$0RST"<<endl;
		strwhere(temp1,86); cout<<endl;
	}
	cout<<endl<<endl;
	cadr<<"$$BLU";
	s=15;
	if(perGame==true){
		t=13; c=50;
	}
	else{
		t=12; c=48;
	}
	space(s); ccsPrint(cadr); cadr_dash(c);
	space(s); cout<<"|"; cout<<BOLDCYAN; strwhere(teamOne.name,t,1); if(perGame==false){ cout<<BOLDBLUE; strwhere("Stats",22,1);} else{ cout<<BOLDBLUE; strwhere("Stats (Per Game)",22,1);}  cout<<BOLDCYAN; strwhere(teamTwo.name,t,1); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[0],t); strwhere("Goals Scored",22); strwhere(ts2[0],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[1],t); strwhere("Possession",22); strwhere(ts2[1],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[2],t); strwhere("Shots (On Target)",22); strwhere(ts2[2],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[3],t); strwhere("Fouls (Offside)",22); strwhere(ts2[3],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[4],t); strwhere("Corner Kicks",22); strwhere(ts2[4],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[5],t); strwhere("Free Kicks",22); strwhere(ts2[5],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[6],t); strwhere("Passes Completed (%)",22); strwhere(ts2[6],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[7],t); strwhere("Crosses",22); strwhere(ts2[7],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[8],t); strwhere("Interception",22); strwhere(ts2[8],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[9],t); strwhere("Tackles",22); strwhere(ts2[9],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[10],t); strwhere("Saves",22); strwhere(ts2[10],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
}