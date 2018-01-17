#ifndef TEAM_H
#define TEAM_H

#include "saheader.h"

class team{
	static int count;
	bool exist;
	char temp[10];
	char name[30];
	int id;
	int apps;
	int goals;
	int rc;
	int yc;
	int wins;
	int lose;
	int draw;
	int possess;
	int shots[2];
	int fouls[2];
	int corners;
	int fk;
	int pass_c;
	int cross;
	int interc;
	int tackles;
	int saves;
	
	public:
	player pr[200];
	
	team(){
		exist=0; id=0; apps=0; goals=0; rc=0; yc=0; wins=0; lose=0; draw=0;
		possess=0; corners=0; fk=0; pass_c=0; cross=0; interc=0; tackles=0; saves=0;
		for(int i=0; 2>i; i++){
			shots[i]=0;
			fouls[i]=0;
		}
	}
       
        
	int getNumPrs(){
		int num;
		for(num=0; pr[num].sendexist(); num++);
		return num;
	}

        
	bool input(void){
		int choice;
		choice=0;
		input:
		if(choice==2) cout<<endl;
		cout<<"Enter name: ";
		cin.getline(name,30);
                
		do{
			cout<<"Enter ID (1 Or 2): ";
			id=nextInt();
		}while(!printCheckChoice(id,1,2));
            
		setColor("BOLDBLUE");
		cout<<"\nName: "<<name<<" | ID: "<<id<<endl;
		setColor("RESET");
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes | 3:Cancel Entering Team)\n";
		choice=inputChoice(1,3);
		if(choice==2) goto input;
		if(choice==3) return false;
		exist=1;
		return true;
	}
            
	void zero(void){
		apps=0; goals=0; rc=0; yc=0; wins=0; lose=0; draw=0;
		possess=0; corners=0; fk=0; pass_c=0; cross=0; interc=0; tackles=0; saves=0;
		for(int i=0; 2>i; i++){
			shots[i]=0;
			fouls[i]=0;
		}
	}
        
	int generateRandomNumber(int post){
		if(post<1 || post>5) throw -1;
		int gk[]={1,12,23,31,51,0};
		int cb[]={2,3,4,5,21,25,29,30,33,0};
		int cmf[10]={6,16,26,24,22,28,0};
		int amf[10]={7,8,17,27,13,18,32,0};
		int cf[10]={9,10,11,19,20,14,15,0};
		bool used[201];
		for(int i=1; 201>i; i++) used[i]=false;
		int tp;
		tp=getNumPrs();
		for(int i=0; tp>i; i++) used[getPrFromIndex(i).getNumber()]=true;
		int *nums;
		switch(post){
			case 1: nums=gk; break;
			case 2: nums=cb; break;
			case 3: nums=cmf; break;
			case 4: nums=amf; break;
			case 5: nums=cf; break;
		}
            
		bool empty=false;
		for(int i=0; nums[i]!=0; i++){
			if(!used[nums[i]]){
				empty=true;
				if(randYesNo()) return nums[i];
			}
			if(nums[i+1]==0 && empty) i=-1;
		}
            
		empty=false;
		for(int i=34; 201>i; i++){
			if(!used[i]){
				empty=true;
				if(randYesNo()) return i;
			}
			if(i+1==201 && empty) i=0;
		}
		throw -1;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<name<<endl;
		f1<<id<<endl;
		f1<<apps<<endl;
		f1<<goals<<endl;
		f1<<rc<<endl;
		f1<<yc<<endl;
		f1<<wins<<endl;
		f1<<lose<<endl;
		f1<<draw<<endl;
		f1<<possess<<endl;
		f1<<shots[0]<<endl;
		f1<<shots[1]<<endl;
		f1<<fouls[0]<<endl;
		f1<<fouls[1]<<endl;
		f1<<corners<<endl;
		f1<<fk<<endl;
		f1<<pass_c<<endl;
		f1<<cross<<endl;
		f1<<interc<<endl;
		f1<<tackles<<endl;
		f1<<saves<<endl;
		int t;
		for(t=0; pr[t].sendexist(); t++);
		f1<<t<<endl;
		for(int i=0; t>i; i++) pr[i].saveTxt(f1);
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1.ignore();
		f1.getline(name,30);
		f1>>id;
		f1>>apps;
		f1>>goals;
		f1>>rc;
		f1>>yc;
		f1>>wins;
		f1>>lose;
		f1>>draw;
		f1>>possess;
		f1>>shots[0];
		f1>>shots[1];
		f1>>fouls[0];
		f1>>fouls[1];
		f1>>corners;
		f1>>fk;
		f1>>pass_c;
		f1>>cross;
		f1>>interc;
		f1>>tackles;
		f1>>saves;
		int t;
		f1>>t;
		f1.ignore();
		for(int i=0; t>i; i++) pr[i].loadTxt(f1);
	}
	
	int getWins(){ return wins;}
	bool sendexist(void){ return exist;}
	int sendid(void){ return id;}
	void app_p(void){ apps++;}
	void goal_p(void){ goals++;}
	void rc_p(void){ rc++;}
	void yc_p(void){ yc++;}
	void win_p(void){ wins++;}
	void lose_p(void){ lose++;}
	void draw_p(void){ draw++;}
	void possess_p(int a){ possess+=a;}
	void shots0_p(int a){ shots[0]+=a;}
	void fouls0_p(int a){ fouls[0]+=a;}
	void shots1_p(int a){ shots[1]+=a;}
	void fouls1_p(int a){ fouls[1]+=a;}
	void corners_p(int a){ corners+=a;}
	void fk_p(int a){ fk+=a;}
	void pass_c_p(int a){ pass_c+=a;}
	void cross_p(int a){ cross+=a;}
	void interc_p(int a){ interc+=a;}
	void tackles_p(int a){ tackles+=a;}
	void saves_p(int a){ saves+=a;}
	char* getName(){return name;}
	void printname(void){ cout<<name;}
	
	void sortPrsByDebut(match *);
	void showSqadList(match *);
	void teamManage(team,match *);
	
	void show(void){
		setColor("BOLDRED");
		cout<<"\nName: "<<name;
		setColor("RESET");
		cout<<endl;
		cout<<"ID: "<<id<<endl;
		if(apps==0) cout<<"\nIn team hanuz mosabeghat ra shoru nakarde ast.\n";
		else{
			cout<<"Apps: "<<apps<<endl;
			cout<<"Wins: "<<wins<<endl;
			cout<<"Draws: "<<draw<<endl;
			cout<<"Loses: "<<lose<<endl;
			cout<<"Wins Percent: "<<(double)wins/apps*100<<"%"<<endl;
			cout<<"Goals: "<<goals<<endl;
			cout<<"Goals Per Game: "<<(double)goals/apps<<endl;
			cout<<"Yellow Cards: "<<yc<<endl;
			cout<<"Yellow Cards Per Game: "<<(double)yc/apps<<endl;
			cout<<"Red Cards: "<<rc<<endl;
			cout<<"Red Cards Per Game: "<<(double)rc/apps<<endl;
			cout<<"Possession Per Game: "<<(double)possess/apps<<endl;
			cout<<"Shots(On Target): "<<shots[0]<<"("<<shots[1]<<")"<<endl;
			cout<<"Shots(On Target) Per Game: "<<(double)shots[0]/apps<<"("<<(double)shots[1]/apps<<")"<<endl;
			cout<<"Fouls(Offside): "<<fouls[0]<<"("<<fouls[1]<<")"<<endl;
			cout<<"Fouls(Offside) Per Game: "<<(double)fouls[0]/apps<<"("<<(double)fouls[1]/apps<<")"<<endl;
			cout<<"Corners: "<<corners<<endl;
			cout<<"Corners Per Game: "<<(double)corners/apps<<endl;
			cout<<"Free Kicks: "<<fk<<endl;
			cout<<"Free Kicks Per Game: "<<(double)fk/apps<<endl;
			cout<<"Pass Completed Per Game: "<<(double)pass_c/apps<<endl;
			cout<<"Crosses: "<<cross<<endl;
			cout<<"Crosses Per Game: "<<(double)cross/apps<<endl;
			cout<<"Interception: "<<interc<<endl;
			cout<<"Interception Per Game: "<<(double)interc/apps<<endl;
			cout<<"Tackles: "<<tackles<<endl;
			cout<<"Tackles Per Game: "<<(double)tackles/apps<<endl;
			cout<<"Saves: "<<saves<<endl;
			cout<<"Saves Per Game: "<<(double)saves/apps<<endl;
			
		}
	}
	
    void sortPrs(const char* sortBy, bool moreToFewer=false){
		for(int i=0; getPrFromIndex(i).sendexist(); i++){
			int first=getPrFromIndex(i).dynamicGet(sortBy);
			int newIndex=-1;
			for(int j=i+1; getPrFromIndex(j).sendexist(); j++){
				if((moreToFewer && getPrFromIndex(j).dynamicGet(sortBy)>first)	
				|| (!moreToFewer && getPrFromIndex(j).dynamicGet(sortBy)<first)){
					newIndex=j;
					first=getPrFromIndex(j).dynamicGet(sortBy);
				}
			}
			
			if(newIndex!=-1){
				player temp=getPrFromIndex(i).clone();
				pr[i]=getPrFromIndex(newIndex).clone();
				pr[newIndex]=temp;
			}
		}	
	}
	
	static void sortPrs(player *argPrs,const char* sortBy, bool moreToFewer=false){
		for(int i=0; argPrs[i].sendexist(); i++){
			int first=argPrs[i].dynamicGet(sortBy);
			int newIndex=-1;
			for(int j=i+1; argPrs[j].sendexist(); j++){
				if((moreToFewer && argPrs[j].dynamicGet(sortBy)>first)	
				|| (!moreToFewer && argPrs[j].dynamicGet(sortBy)<first)){
					newIndex=j;
					first=argPrs[j].dynamicGet(sortBy);
				}
			}
			
			if(newIndex!=-1){
				player temp=argPrs[i].clone();
				argPrs[i]=argPrs[newIndex].clone();
				argPrs[newIndex]=temp;
			}
		}	
	}
	
	void printPlayersNumbersTable(){
		int s,t,lineNum,maxLength;
		stringstream cadr;
		stringstream prColor;
		player tmpPrs[200];
		for(int i=0; 200>i; i++) tmpPrs[i]=pr[i].clone();
		
		s=3;
		t=20;
		lineNum=3;
		maxLength=2+(lineNum*t);
		cadr<<"$$BLU";
		prColor<<"$0MAG";
		
		cout<<endl;
		sortPrs(tmpPrs,"number");
		
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		for(int i=0; tmpPrs[i].sendexist(); i+=lineNum){
			space(s); ccsPrint(cadr); cout<<"|"; ccsPrint(prColor);
			int j;
			for(j=i; j-i<lineNum && tmpPrs[j].sendexist(); j++){
				stringstream prNow;
				prNow<<tmpPrs[j].getNumber()<<": "<<tmpPrs[j].sendname();
				strwhere(prNow,t,1);
			}
			if(j-i!=lineNum){
				for(int k=0; lineNum-(j-i)>k; k++) space(t);
			}
			ccsPrint(cadr); cout<<"|"<<endl;
		}
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
	}
	
	void show_det_prs(void){
		if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
		else{
			setColor("BOLDGREEN");
            cout<<"\nDetailed Players List:\n";
            setColor("RESET");
			for(int i=0; pr[i].exist!=0; i++){	
				setColor("BOLDGREEN");
                cout<<endl<<"Player "<<i+1<<":  ";
                setColor("RESET");
				pr[i].show();
			}
		}
	}
        
    player& getPrFromIndex(int index){
        return pr[index];
    }
        
    player& getPrFromId(int id){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getId()==id) return pr[i]; 
        }
        throw -1;
    }
        
    player& getPrFromNumber(int number){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getNumber()==number) return pr[i]; 
        }
        throw -1;
    }
        
    int getPrIdFromNumber(int number){
        return getPrFromNumber(number).getId();
    }
        
    int getPrIndexFromNumber(int number){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getNumber()==number) return i; 
        }
        throw -1;
    }
    
    int getPrIndexFromId(int Id){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getId()==Id) return i; 
        }
        throw -1;
    }
	
	int getPlayerID(char *str){
		for(int i=0; pr[i].sendexist(); i++){
			if(strcasecmp(pr[i].sendname(), str)==0) return i;
		}
		return -1;
	}
       
	bool existNumber(int number){
		for(int i=0; pr[i].sendexist(); i++){
			if(pr[i].getNumber()==number) return true; 
		}
		return false;
	}
        
	bool prAllowDelete(int index){
		if(!pr[index].sendexist()) throw -1;
		return pr[index].sendapps()<=0;
	}
        
    void inputPrDetails(char nameVar[],int& post,int& number,int index){
        input:
        cout<<"\nPlayer "<<index+1 <<":\n";
		cout<<"Enter Name: ";
		cin.getline(nameVar,30);
		if(getPlayerID(nameVar)!=-1){
            printError("This Player has already bean Added\n");
			cout<<"\nTry Again? (1:Yes | 2:No)\n";
            int choice=inputChoice(1,2);
            if(choice==1) goto input;
			else return;
		}
        cout<<"Enter Post (1-5): ";
        post=inputChoice(1,5);
		if(number==-1){
			cout<<"Enter Shirt Number (0 To Random): ";
			number=inputChoice(0,200);
			if(number==0) number=generateRandomNumber(post);
		}
    }
	
	void add_prs(team other){
		int choice,i,post,number;
		int numSecond;
		char nameVar[30];
		do{
			for(i=0; pr[i].sendexist()!=0; i++);
			if(i>=200){
				cout<<"\nError!!! Full Capacity\n"; 
				break;
			}
                        
            input:
            numSecond=-1;
			number=-1;
			inputPrDetails(nameVar,post,number,i);
                        
            setColor("BOLDBLUE");
            cout<<endl<<"Name: "<<nameVar<<" | Post: ";
            player::printPost(post);
			setColor("BOLDBLUE");
			cout<<" | Number: ";
			setColor("BOLDMAGENTA");
			cout<<number<<endl;
			setColor("RESET");
			if(existNumber(number)){
				numSecond=generateRandomNumber(getPrFromNumber(number).getPost());
				typeWarning();
				cout<<getPrFromNumber(number).sendname()<<": "<<number<<" -> "<<numSecond<<endl;
			}
                        
            setColor("BOLDRED");
            cout<<endl<<"Next Work?\n";
            setColor("RESET");
            cout<<"1: Apply And Enter Another Player\n2: Edit Entry\n3: Refuse Last Entry And Back\n4: Apply And Back To Recent Menu\n\n";
            cout<<"Enter Your Choice: ";
            choice=inputChoice(1,4);
            if(choice==2) goto input;
            if(choice==3) return;
			if(numSecond!=-1){
				getPrFromNumber(number).setNumber(numSecond);
			}
			pr[i].input(nameVar,post,number,generateNewPrId(*this,other));
            IS_SAVED=false;
		} while(choice==1);
	}
	
	void editPrNumbers(){
		int index,otherIndex;
		printPlayersNumbersTable();
		cout<<endl;
        typeRule();
        cout<<"For Edit Number Of a player: \n";
        cout<<"Enter Player Number | New Player Number | And Then Apply\n";
        typeRule();
        cout<<"Enter 0 for End of Editing Numbers\n";
        while(true){
            wh:
            int one,two;
            cout<<endl;
            cout<<"Enter Player Number or Zero to Quit: ";
            one=nextInt();
			if(one==0) return;
			if(one<0 || one>200){
				cout<<endl;
				typeError();
				cout<<"Invalid Number! Try again.\n";
				goto wh;
			}
			if(!existNumber(one)){
				cout<<endl;
				typeError();
				cout<<"There is No Player With This Number! Try again.\n";
				goto wh;
			}
			else index=getPrIndexFromNumber(one);
			
			cout<<"Enter New Player Number: ";
			two=nextInt();
			if(two<0 || two>200){
				cout<<endl;
				typeError();
				cout<<"Invalid Player Number! Try again.\n";
				goto wh;
			}
			
			otherIndex=-1;
            if(existNumber(two)){
                otherIndex=getPrIndexFromNumber(two);
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> <- "<<pr[otherIndex].getNumber()<<") "<<pr[otherIndex].sendname();
                setColor("RESET");
                cout<<endl;
            }
            else{
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> "<<two<<")"<<endl;
                setColor("RESET");
            }
            
            cout<<"Do You Apply (1:Yes | 2:No): ";
			if(inputChoice(1,2)==2) goto wh;

            pr[index].setNumber(two);
            if(otherIndex>=0) pr[otherIndex].setNumber(one);
            char temp[70];
            sprintf(temp,"%s Number Changed From %d to %d\n",pr[index].sendname(),one,two);
            sucPrint(temp);
            IS_SAVED=false;
            cout<<endl;
            printPlayersNumbersTable();
		}
	}
        
    void editPrs(team other){
        int inpNumber;
        int choice;
        start:
        if(getNumPrs()==0){
            cout<<"\nThere is No Player to Edit\n";
            return;
        }
        
        cout<<endl<<"Enter the Number of the Player that you want to Edit: ";
        inpNumber=nextInt();
        while(!existNumber(inpNumber)){
            cout<<endl;
            if(inpNumber>INT_MAX-2) printError("Invalid Id Input!\n");
            else printError("There is No Player With This Number\n");
            cout<<endl<<"Next Work? (1:Try Again | 2: Cancel Editing): ";
            choice=inputChoice(1,2);
            if(choice==2) return;
            cout<<endl<<"Enter the Number of the Player that you want to Edit: ";
            inpNumber=nextInt();
        }
        int index=getPrIndexFromNumber(inpNumber);
            
            
        cout<<endl;
        pr[index].namePostShow();
        cout<<endl;
            
        int preCh=2;
        int aftCh=2;
        int canDel=0;
        int tch;
        cout<<endl;
        setColor("BOLDRED");
        cout<<"Next Work?\n";
        setColor("RESET");
        cout<<"1: Edit Name And Post\n";
        cout<<"2: Change Number\n";
        if(prAllowDelete(index)){
            canDel=1;
        }
            
        if(canDel) cout<<preCh+1<<": Delete This Player\n";
        cout<<preCh+2-(canDel==0)<<": Edit Another Player\n";
        cout<<preCh+3-(canDel==0)<<": Cancel And Back to Recent Menu\n";
            
        tch=preCh+aftCh+canDel;
        cout<<"\nEnter Your Choice: ";
        choice=inputChoice(1,tch);
        if(choice==tch) return;
        if(choice==tch-1) goto start;
        else if(choice==1){
			char nameVar[30];
            int post;
			int num=getPrFromIndex(index).getNumber();
            input:
			inputPrDetails(nameVar,post,num,index);
            cout<<endl;      
            setColor("BOLDBLUE");
            cout<<endl<<"Name: "<<nameVar<<" | Post: ";
            player::printPost(post);
            cout<<endl;
            sucPrint("The Player Edited Successfully\n");
                        
            cout<<endl;
            setColor("BOLDRED");
            cout<<"Next Work?\n";
            setColor("RESET");
            cout<<"1: Edit Another Player\n";
            cout<<"2: Edit Again\n";
            cout<<"3: Back\n";
            cout<<"4: Cancel This Edit\n";
            cout<<endl<<"Enter Your Choice: ";
            choice=inputChoice(1,4);
            if(choice==2) goto input;
            if(choice==4){
                cout<<endl;
                sucPrint("Changes Of This Player Ignored!\n");
                return;
            }
            pr[index].edit(nameVar,post);
            IS_SAVED=false;
            if(choice==1){
                goto start;
            }
            return;
		}
            
        else if(choice==2){
            changenumber:
            int newNum;
            int otherIndex=-1;
            cout<<endl<<"Enter new Number: ";
            newNum=inputChoice(1,200);
            if(existNumber(newNum)){
                otherIndex=getPrIndexFromNumber(newNum);
                cout<<endl;
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> <- "<<pr[otherIndex].getNumber()<<") "<<pr[otherIndex].sendname();
                setColor("RESET");
                cout<<endl;
            }
            else{
                cout<<endl;
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> "<<newNum<<")"<<endl;
                setColor("RESET");
            }
            cout<<endl;
            setColor("BOLDRED");
            cout<<"Are you sure?\n";
            setColor("RESET");
            cout<<"1: Yes\n";
            cout<<"2: Enter New Number\n";
            cout<<"3: Edit Another Player\n";
            cout<<"4: Cancel the Change And Back\n";
            cout<<"\nEnter Your Choice: ";
            int choice=inputChoice(1,4);
            if(choice==2) goto changenumber;
            else if(choice==3){
                IS_SAVED=false;
                goto start;
            }
            else if(choice==4) return;
            else if(choice==1){
                int oldNumber=pr[index].getNumber();
                pr[index].setNumber(newNum);
                if(otherIndex>=0) pr[otherIndex].setNumber(oldNumber);
                cout<<endl;
                char temp[70];
                sprintf(temp,"%s Number Changed From %d to %d\n",pr[index].sendname(),oldNumber,newNum);
                sucPrint(temp);
                IS_SAVED=false;
                            
                cout<<endl;
                setColor("BOLDRED");
                cout<<"Next Work?\n";
                setColor("RESET");
                cout<<"1: Edit Another Player\n";
                cout<<"2: Back\n";
                choice=inputChoice(1,2);
                if(choice==1) goto start;
                if(choice==2) return;
            }
        }
            
        else if(canDel && choice==(preCh+1)){
            cout<<endl<<"Are You Sure? (1:Yes 2:No): ";
            choice=inputChoice(1,2);
            if(choice==1){
                int i;
                char printName[30];
                strcpy(printName,pr[index].sendname());
                for(i=index; pr[i+1].sendexist(); i++) pr[i]=pr[i+1].clone();
                pr[i].remove();
                cout<<endl;
                setColor("GREEN");
                cout<<printName<<" Deleted From This Team\n";
                setColor("RESET");
                    
                cout<<endl<<"Next Work? (1:Edit Another Player | 2: Back)\n";
                choice=inputChoice(1,2);
                if(choice==1) goto start;
                return;
            }
                
        }
            
    }

        
	friend class match;
	friend class competition;
	friend void compare(team,team,double,double,int,int);
	friend void compare_teams(team,team);
	friend void top_scorers(team,team);
};

#endif	// TEAM_H

