#ifndef MATCH_H
#define MATCH_H

#include "saheader.h"
#include "print.h"

class match{
    //Danger SetNumber Niz.
        public:
	bool exist;
	int year;
	int month;
	int day;
	int res;      // 1:Team 1 | 2:Team 2 | 3: Draw
	int t1_prs[11];
	int t2_prs[11];
	int t1_tt;
	int t2_tt;
	int t1_tvz[3];
	int t2_tvz[3];
	int mom[2][2];
	int t1_goals;
	int t2_goals;
	int t1_possess;
	int t2_possess;
	int t1_shots[2];
	int t2_shots[2];
	int t1_fouls[2];
	int t2_fouls[2];
	int t1_corners;
	int t2_corners;
	int t1_fk;
	int t2_fk;
	int t1_pass_c;
	int t2_pass_c;
	int t1_cross;
	int t2_cross;
	int t1_interc;
	int t2_interc;
	int t1_tackles;
	int t2_tackles;
	int t1_saves;
	int t2_saves;
	int t1_tc[3];      //[0]:Yellow [1]:Red [2]:Sum
	int t2_tc[3];
	int tg;
	int tcards;
	int cards[28][5];
	int goals[30][5];
	char t1_conf[1200];
	char t2_conf[1200];
	char temp[20];
        
	public:
	match(){
		exist=0;
		year=0; month=0; day=0;
		for(int i=0; 11>i; i++) t1_prs[i]=0;
		for(int i=0; 11>i; i++) t2_prs[i]=0;
		t1_tt=0; t2_tt=0;
		for(int i=0; 3>i; i++) t1_tvz[i]=0;
		for(int i=0; 3>i; i++) t2_tvz[i]=0;
		for(int i=0; 2>i; i++) mom[0][i]=0;
		for(int i=0; 2>i; i++) mom[1][i]=0;
		t1_goals=0; t2_goals=0; t1_possess=0; t2_possess=0;
		for(int i=0; 2>i; i++) t1_shots[i]=0;
		for(int i=0; 2>i; i++) t2_shots[i]=0;
		for(int i=0; 2>i; i++) t1_fouls[i]=0;
		for(int i=0; 2>i; i++) t2_fouls[i]=0;
		t1_corners=0; t2_corners=0; t1_fk=0; t2_fk=0;
		t1_pass_c=0; t2_pass_c=0; t1_cross=0; t2_cross=0; t1_interc=0; t2_interc=0;
		t1_tackles=0; t2_tackles=0; t1_saves=0; t2_saves=0;
		for(int i=0; 3>i; i++) t1_tc[i]=0;
		for(int i=0; 3>i; i++) t2_tc[i]=0;
		tg=0;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=0;
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=0;
		*t1_conf=0; *t2_conf=0;
	}
        
	void set_goals(team,team);
	void set_possess_shots(team,team);
	void set_fouls_corners(team,team);
	void set_fk_passc_cross(team,team);
	void set_ic_tackle_save(team,team);
	void setLineup(team,bool);
	void set_goals_scorers(team,team);
	void set_tcards(team,team);
	void set_cards(team,team);
	void set_mom(team,team);
	void set_conf(team,team);
	void setPlayersHatTricks(team &,team &);
        
        
	bool sendexist(void){ return exist;}
	int getResult(){ return res;}
	
	int ** getGoals(){
		int ** out;
		out=new int*[30];
		for(int i=0; 30>i; i++) out[i]=new int[5];
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) out[i][j]=goals[i][j];
		return out;
	}
	
	void zero(void){
		exist=0;
		year=0; month=0; day=0;
		for(int i=0; 11>i; i++) t1_prs[i]=0;
		for(int i=0; 11>i; i++) t2_prs[i]=0;
		t1_tt=0; t2_tt=0;
		for(int i=0; 3>i; i++) t1_tvz[i]=0;
		for(int i=0; 3>i; i++) t2_tvz[i]=0;
		for(int i=0; 2>i; i++) mom[0][i]=0;
		for(int i=0; 2>i; i++) mom[1][i]=0;
		t1_goals=0; t2_goals=0; t1_possess=0; t2_possess=0;
		for(int i=0; 2>i; i++) t1_shots[i]=0;
		for(int i=0; 2>i; i++) t2_shots[i]=0;
		for(int i=0; 2>i; i++) t1_fouls[i]=0;
		for(int i=0; 2>i; i++) t2_fouls[i]=0;
		t1_corners=0; t2_corners=0; t1_fk=0; t2_fk=0;
		t1_pass_c=0; t2_pass_c=0; t1_cross=0; t2_cross=0; t1_interc=0; t2_interc=0;
		t1_tackles=0; t2_tackles=0; t1_saves=0; t2_saves=0;
		for(int i=0; 3>i; i++) t1_tc[i]=0;
		for(int i=0; 3>i; i++) t2_tc[i]=0;
		tg=0;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=0;
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=0;
		*t1_conf=0; *t2_conf=0;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<year<<endl;
		f1<<month<<endl;
		f1<<day<<endl;
		f1<<res<<endl;
		for(int i=0; 11>i; i++) f1<<t1_prs[i]<<endl;
		for(int i=0; 11>i; i++) f1<<t2_prs[i]<<endl;
		f1<<t1_tt<<endl;
		f1<<t2_tt<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tvz[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tvz[i]<<endl;
		for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) f1<<mom[i][j]<<endl;
		f1<<t1_goals<<endl;
		f1<<t2_goals<<endl;
		f1<<t1_possess<<endl;
		f1<<t2_possess<<endl;
		for(int i=0; 2>i; i++) f1<<t1_shots[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t2_shots[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t1_fouls[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t2_fouls[i]<<endl;
		f1<<t1_corners<<endl;
		f1<<t2_corners<<endl;
		f1<<t1_fk<<endl;
		f1<<t2_fk<<endl;
		f1<<t1_pass_c<<endl;
		f1<<t2_pass_c<<endl;
		f1<<t1_cross<<endl;
		f1<<t2_cross<<endl;
		f1<<t1_interc<<endl;
		f1<<t2_interc<<endl;
		f1<<t1_tackles<<endl;
		f1<<t2_tackles<<endl;
		f1<<t1_saves<<endl;
		f1<<t2_saves<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tc[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tc[i]<<endl;
		f1<<tg<<endl;
		f1<<tcards<<endl;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) f1<<cards[i][j]<<endl;
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) f1<<goals[i][j]<<endl;
		f1<<t1_conf<<endl;
		f1<<t2_conf<<endl;
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1>>year;
		f1>>month;
		f1>>day;
		f1>>res;
		for(int i=0; 11>i; i++) f1>>t1_prs[i];
		for(int i=0; 11>i; i++) f1>>t2_prs[i];
		f1>>t1_tt;
		f1>>t2_tt;
		for(int i=0; 3>i; i++) f1>>t1_tvz[i];
		for(int i=0; 3>i; i++) f1>>t2_tvz[i];
		for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) f1>>mom[i][j];
		f1>>t1_goals;
		f1>>t2_goals;
		f1>>t1_possess;
		f1>>t2_possess;
		for(int i=0; 2>i; i++) f1>>t1_shots[i];
		for(int i=0; 2>i; i++) f1>>t2_shots[i];
		for(int i=0; 2>i; i++) f1>>t1_fouls[i];
		for(int i=0; 2>i; i++) f1>>t2_fouls[i];
		f1>>t1_corners;
		f1>>t2_corners;
		f1>>t1_fk;
		f1>>t2_fk;
		f1>>t1_pass_c;
		f1>>t2_pass_c;
		f1>>t1_cross;
		f1>>t2_cross;
		f1>>t1_interc;
		f1>>t2_interc;
		f1>>t1_tackles;
		f1>>t2_tackles;
		f1>>t1_saves;
		f1>>t2_saves;
		for(int i=0; 3>i; i++) f1>>t1_tc[i];
		for(int i=0; 3>i; i++) f1>>t2_tc[i];
		f1>>tg;
		f1>>tcards;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) f1>>cards[i][j];
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) f1>>goals[i][j];
		f1.ignore();
		f1.getline(t1_conf,300);
		f1.getline(t2_conf,300);
	}
	
	void set_date(void){
		int bar,error,choice;
		cout<<"\nEnter Date of Match (Year | Month | Day)\n";
		bar=0;
		do{
			error=0;
			bar++;
			if(bar>1){ cout<<endl; setColor("BOLDYELLOW"); cout<<"Adade vorudi Na motabarand. Try Again\n"; setColor("RESET"); cout<<endl;}
			cin>>year>>month>>day;
			cin.ignore();
			if(((year<1300 || year>1500) && year !=-2) || ((month<1 || month>12) && month!=-2) || ((day<1 || day>31) && day!=-2)) error=1;
		} while (error==1);
		if(year==-2){ month=-2; day=-2;}
		if(month==-2) day=-2;
		cout<<endl; setColor("BOLDBLUE"); cout<<"Date Of Match: ";
		if(year!=-2) cout<<year<<"/"; else cout<<"UK"<<"/";
		if(month!=-2 && month>9) cout<<month<<"/"; else if(month!=-2 && month<10)cout<<"0"<<month<<"/"; else cout<<"UK"<<"/";
		if(day!=-2 && day>9){ cout<<day; setColor("RESET"); cout<<endl;} else if(day!=-2 && day<10){ cout<<"0"<<day; setColor("RESET"); cout<<endl;} else{ cout<<"UK"; setColor("RESET"); cout<<endl;}
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
                choice=inputChoice(1,2);
		if(choice==2) set_date();
	}
	
	int ** getPlayersStats(){
		int ** prStats;
		prStats=new int*[28];
		for(int i=0; 28>i; i++) prStats[i]=new int[4];    //0:Team | 1:Player ID | 2:Goals | 3:Assists
		for(int i=0; 28>i; i++) for(int j=0; 4>j; j++) prStats[i][j]=0;
		if(tg==0){
			prStats[0][0]=0;
			return prStats;
		}
		for(int i=0; tg>i; i++){
			int scorerID;
			int assisterID;
			int teamID;
			int firstEmptyIndex;
			int scorerIndex=-1;
			int assisterIndex=-1;
			
			teamID=goals[i][0];
			scorerID=goals[i][2];
			assisterID=goals[i][3];
			if(scorerID!=-2){
				for(int j=0; 28>j; j++){
					if(prStats[j][0]==teamID && prStats[j][1]==scorerID){
						scorerIndex=j;
						break;
					}
					else if(prStats[j][0]==0){
						firstEmptyIndex=j;
						break;
					}
				}
				if(scorerIndex==-1){
					prStats[firstEmptyIndex][0]=teamID;
					prStats[firstEmptyIndex][1]=scorerID;
					prStats[firstEmptyIndex][2]=1;
					prStats[firstEmptyIndex][3]=0;
				}
				else{
					prStats[scorerIndex][2]++;
				}
			}
			
			if(assisterID!=-2 && assisterID!=-1){
				for(int j=0; 28>j; j++){
					if(prStats[j][0]==teamID && prStats[j][1]==assisterID){
						assisterIndex=j;
						break;
					}
					else if(prStats[j][0]==0){
						firstEmptyIndex=j;
						break;
					}
				}
				
				if(assisterIndex==-1){
					prStats[firstEmptyIndex][0]=teamID;
					prStats[firstEmptyIndex][1]=assisterID;
					prStats[firstEmptyIndex][2]=0;
					prStats[firstEmptyIndex][3]=1;
				}
				else{
					prStats[assisterIndex][3]++;
				}
			}
		}
		
		/*cout<<endl;
		for(int i=0; prStats[i][0]!=0 && 28>i; i++){
			if(prStats[i][0]==1){
				setColor("BOLDMAGENTA"); cout<<"Team "<<prStats[i][0]<<" | Pr ID: "<<prStats[i][1]<<" | Goals: "<<prStats[i][2]
				<<" | Assists: "<<prStats[i][3]<<endl;
			}
			else if(prStats[i][0]==2){
				setColor("BOLDCYAN"); cout<<"Team "<<prStats[i][0]<<" | Pr ID: "<<prStats[i][1]<<" | Goals: "<<prStats[i][2]
				<<" | Assists: "<<prStats[i][3]<<endl;
			}
		}*/
		return prStats;
	}
        
        bool isPlayedThisId(int team,int input){
            if(team==1){
                for(int i=0; 11>i; i++) if(t1_prs[i]==-2 || t1_prs[i]==input) return true;
                for(int i=0; 3>i; i++) if(t1_tvz[i]==-2 || t1_tvz[i]==input) return true;
                return false;
            }
            else if(team==2){
                for(int i=0; 11>i; i++) if(t2_prs[i]==-2 || t2_prs[i]==input) return true;
                for(int i=0; 3>i; i++) if(t2_tvz[i]==-2 || t2_tvz[i]==input) return true;
                return false;
            }
            throw -1;
        }
        
        
        bool prCanEnter(int number,team tm, bool enteredMatch=false){
            player pr;
            int checking;
            if(enteredMatch){
                try{
                    pr=tm.getPrFromNumber(number);
                }
                catch(int ex){
                    return false;
                }
                int id=tm.getPrIdFromNumber(number);
                checking=id;
            }
            else checking=number;
            
            if(tm.sendid()==1){
                for(int i=0; 11>i; i++){
                    if(t1_prs[i]==checking || t1_prs[i]==-2) return true;
                }
                for(int i=0; 3>i; i++){
                    if(t1_tvz[i]==checking || t1_tvz[i]==-2) return true;
                }
                return false;
            }
            
            if(tm.sendid()==2){
                for(int i=0; 11>i; i++){
                    if(t2_prs[i]==checking || t2_prs[i]==-2) return true;
                }
                for(int i=0; 3>i; i++){
                    if(t2_tvz[i]==checking || t2_tvz[i]==-2) return true;
                }
                return false;
            }
        }
        
        bool enterCard(int i,team tm1,team tm2){
            int temp[5];
            int choice;
            bool error=true;
            bool first=true;
            
            while(error){
                error=false;
                if(!first){
                    cout<<"\nYou Entered The Card By Mistake!\n";
                    cout<<"Next Work? (1:Try Again | 2: Go to Number of Cards Session | 3: Go to Line Up Session): ";
                    choice =inputChoice(1,3);
                    if(choice==2){
                        set_tcards(tm1,tm2);
                        return false;
                    }
                    if(choice==3){
                        setColor("BOLDRED");
                        cout<<"Works:\n";
                        setColor("RESET");
                        cout<<"1: Enter Complete Teams Line Ups\n";
                        cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
                        cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
                        cout<<"4: Cancel And Try Again to Entering Goal\n";
                        choice=inputChoice(1,4);
                        if(choice==1){
                            setFirstLineup(tm1);
                            setFirstLineup(tm2);
                            setSubLineup(tm1);
                            setSubLineup(tm2);
                        }
                        else if(choice==2){
                            setFirstLineup(tm1);
                            setSubLineup(tm1);
                        }
                        else if(choice==3){
                            setFirstLineup(tm2);
                            setSubLineup(tm2);
                        }
                        if(choice!=4) return false;
                    }
                    cout<<endl;
                }
                first=false;
                if(!first) cout<<"Enter The Card: ";
                temp[0]=nextInt();
                temp[1]=nextInt();
                temp[2]=nextInt();
                temp[3]=nextInt();
                if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
                cout<<endl;
                if(!easycheck(temp[0],1,2)){
                    printError("Team Id is Invalid (Most Be 1 Or 2)\n");
                    error=true;
                }
                if(!easycheck(temp[1],1,2)){
                    printError("Card Color is Invalid (Most Be 1 Or 2)\n");
                    error=true;
                }
                if(temp[2]!=-2){
                    if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
                        if(temp[2]>INT_MAX-2) printError("Player Number is Invalid!\n");
                        else printError("Player: This Player Not entered This Game!\n");
                        error=true;
                    }
                }
                if(!easycheck(temp[3],1,90)){
                    printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
                    error=true;
                }
                if((temp[3]==45 || temp[3]==90) && !easycheck(temp[4],0,15)){
                    printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
                    error=true;
                }
                
            }
            cards[i][0]=temp[0];
            if(temp[3]<=45) cards[i][1]=1;
            else cards[i][1]=2;
            cards[i][2]=temp[1];
            cards[i][3]=temp[2];
            cards[i][4]=temp[3];
            if(cards[i][4]==45 || cards[i][4]==90) cards[i][4]+=temp[4];
            return true;
        }
        
        void printCard(int i,team tm1,team tm2){
            stringstream temp1;
            stringstream temp2;
            stringstream temp3;
            stringstream temp4;
            stringstream temp5;
            temp1.str("");
            temp2.str("");
            temp3.str("");
            temp4.str("");
            temp5.str("");
            if(cards[i][0]==1) temp1<<tm1.name; else if(cards[i][0]==2) temp1<<tm2.name;
            if(cards[i][1]==1) temp2<<"First Half"; else if(cards[i][1]==2) temp2<<"Second Half"; else if(cards[i][0]==-2) temp2<<"UK";
            if(cards[i][2]==1) temp3<<"Yellow"; else if(cards[i][2]==2) temp3<<"Red";
            if(cards[i][3]==-2) temp4<<"UK";
            else if(cards[i][0]==1) temp4<<tm1.getPrFromNumber(cards[i][3]).sendname();
            else if(cards[i][0]==2) temp4<<tm2.getPrFromNumber(cards[i][3]).sendname();
            if(cards[i][4]==-2) temp5<<"UK"; else temp5<<cards[i][4];
            ccsPrint(temp1); cout<<" | "; ccsPrint(temp2); cout<<" | "; ccsPrint(temp3); cout<<" | "; ccsPrint(temp4); cout<<" | "; ccsPrint(temp5);
            cout<<endl;
        }
        
        bool enterGoal(int i,team tm1,team tm2){
            int temp[5];
            int choice;
            bool error=true;
            bool first=true;
            
            while(error){
                error=false;
                if(!first){
                    cout<<"\nYou Entered The Goal By Mistake!\n";
                    cout<<"Next Work? (1:Try Again | 2: Go to Number of Goals Session | 3: Go to Line Up Session): ";
                    choice =inputChoice(1,3);
                    if(choice==2){
                        set_goals(tm1,tm2);
                        return false;
                    }
                    if(choice==3){
                        setColor("BOLDRED");
                        cout<<"Works:\n";
                        setColor("RESET");
                        cout<<"1: Enter Complete Teams Line Ups\n";
                        cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
                        cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
                        cout<<"4: Cancel And Try Again to Entering Goal\n";
                        choice=inputChoice(1,4);
                        if(choice==1){
                            setFirstLineup(tm1);
                            setFirstLineup(tm2);
                            setSubLineup(tm1);
                            setSubLineup(tm2);
                        }
                        else if(choice==2){
                            setFirstLineup(tm1);
                            setSubLineup(tm1);
                        }
                        else if(choice==3){
                            setFirstLineup(tm2);
                            setSubLineup(tm2);
                        }
                        if(choice!=4) return false;
                    }
                    cout<<endl;
                }
                first=false;
                if(!first) cout<<"Enter The Goal: ";
                temp[0]=nextInt();
                temp[1]=nextInt();
                temp[2]=nextInt();
                temp[3]=nextInt();
                if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
                cout<<endl;
                if(!easycheck(temp[0],1,2)){
                    printError("Team Id is Invalid (Most Be 1 Or 2)\n");
                    error=true;
                }
                
                if(temp[1]!=-2 || temp[1]!=-1){
                    if((temp[0]==1 && !prCanEnter(temp[1],tm1)) || (temp[0]==2 && !prCanEnter(temp[1],tm2))){
                        if(temp[1]>INT_MAX-2) printError("Scorer ID is Invalid!\n");
                        else printError("Scorer: This Player Not entered This Game!\n");
                        error=true;
                    }
                }
                
                if(temp[2]!=-2 && temp[2]!=-1){
                    if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
                        if(temp[2]>INT_MAX-2) printError("Scorer ID is Invalid!\n");
                        else printError("Assister: This Player Not entered This Game!\n");
                        error=true;
                    }
                }
                
                if(!easycheck(temp[3],1,90)){
                    printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
                    error=true;
                    continue;
                }
                if((temp[3]==45 || temp[3]==90) && !easycheck(temp[4],0,15)){
                    printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
                    error=true;
                }
            }
            
            goals[i][0]=temp[0];
            if(temp[3]<=45) goals[i][1]=1;
            else goals[i][1]=2;
            goals[i][2]=temp[1];
            goals[i][3]=temp[2];
            goals[i][4]=temp[3];
            if(goals[i][4]==45 || goals[i][4]==90) goals[i][4]+=temp[4];
            return true;
        }
        
        void printGoal(int i,team tm1, team tm2){
            stringstream temp1;
            stringstream temp2;
            stringstream temp3;
            stringstream temp4;
            stringstream temp5;
            temp1.str("");
            temp2.str("");
            temp3.str("");
            temp4.str("");
            temp5.str("");
            if(goals[i][0]==1) temp1<<tm1.name; else if(goals[i][0]==2) temp1<<tm2.name;
            if(goals[i][1]==1) temp2<<"First Half"; else if(goals[i][1]==2) temp2<<"Second Half"; else if(goals[i][0]==-2) temp2<<"UK";
            if(goals[i][2]==-1) temp3<<"OG";
            else if(goals[i][2]==-2) temp3<<"UK";
            else if(goals[i][0]==1) temp3<<tm1.getPrFromNumber(goals[i][2]).sendname();
            else if(goals[i][0]==2) temp3<<tm2.getPrFromNumber(goals[i][2]).sendname();
            else temp3<<"Null";
            if(goals[i][3]==-1) temp4<<"WA"; 
            else if(goals[i][3]==-2) temp4<<"UK";
            else if(goals[i][0]==1) temp4<<tm1.getPrFromNumber(goals[i][3]).sendname();
            else if(goals[i][0]==2) temp4<<tm2.getPrFromNumber(goals[i][3]).sendname();
            if(goals[i][4]==-2) temp5<<"UK"; else temp5<<goals[i][4];
            ccsPrint(temp1); cout<<" | "; ccsPrint(temp2); cout<<" | "; ccsPrint(temp3); cout<<" | "; ccsPrint(temp4); cout<<" | "; ccsPrint(temp5);
            cout<<endl;
        }			
		
	
	int dynamicGet(const char * index){
		if(strcasecmp(index,"exist")==0) return exist;
		else if (strcasecmp(index,"res")==0) return res;
		else if (strcasecmp(index,"t1_goals")==0) return t1_goals;
		else if (strcasecmp(index,"t2_goals")==0) return t2_goals;
		else if (strcasecmp(index,"tg")==0) return tg;
		else if (strcasecmp(index,"tcards")==0) return tcards;
		else if (strcasecmp(index,"t1_corners")==0) return t1_corners;
		else if (strcasecmp(index,"t2_corners")==0) return t2_corners;
		else if (strcasecmp(index,"t1_cross")==0) return t1_cross;
		else if (strcasecmp(index,"t2_cross")==0) return t2_cross;
		else if (strcasecmp(index,"t1_fk")==0) return t1_fk;
		else if (strcasecmp(index,"t2_fk")==0) return t2_fk;
		else if (strcasecmp(index,"t1_interc")==0) return t1_interc;
		else if (strcasecmp(index,"t2_interc")==0) return t2_interc;
		else if (strcasecmp(index,"t1_pass_c")==0) return t1_pass_c;
		else if (strcasecmp(index,"t2_pass_c")==0) return t2_pass_c;
		else if (strcasecmp(index,"t1_possess")==0) return t1_possess;
		else if (strcasecmp(index,"t2_possess")==0) return t2_possess;
		else if (strcasecmp(index,"t1_saves")==0) return t1_saves;
		else if (strcasecmp(index,"t2_saves")==0) return t2_saves;
		else if (strcasecmp(index,"t1_shotsOne")==0) return t1_shots[0];
		else if (strcasecmp(index,"t2_shotsOne")==0) return t2_shots[0];
		else if (strcasecmp(index,"t1_shotsTwo")==0) return t1_shots[1];
		else if (strcasecmp(index,"t2_shotsTwo")==0) return t2_shots[1];
		
		else if (strcasecmp(index,"t1_foulsOne")==0) return t1_fouls[0];
		else if (strcasecmp(index,"t2_foulsOne")==0) return t2_fouls[0];
		else if (strcasecmp(index,"t1_foulsTwo")==0) return t1_fouls[1];
		else if (strcasecmp(index,"t2_foulsTwo")==0) return t2_fouls[1];
		else if (strcasecmp(index,"t1_tackles")==0) return t1_tackles;
		else if (strcasecmp(index,"t2_tackles")==0) return t2_tackles;
		else if (strcasecmp(index,"t1DifGoals")==0) return t1_goals-t2_goals;
		else if (strcasecmp(index,"t2DifGoals")==0) return t2_goals-t1_goals;
		else if (strcasecmp(index,"t1YC")==0) return t1_tc[0];
		else if (strcasecmp(index,"t1RC")==0) return t1_tc[1];
		else if (strcasecmp(index,"t2YC")==0) return t2_tc[0];
		else if (strcasecmp(index,"t2RC")==0) return t2_tc[1];
		else throw -1;
	}
	        
        void setFirstLineup(team tm){
            setLineup(tm,true);
        }
        void setSubLineup(team tm){
            setLineup(tm,false);
        }
        
        void convertNumbersToID(team tm1,team tm2){
            for(int k=0; 11>k; k++){
                if(t1_prs[k]>0) t1_prs[k]=tm1.getPrFromNumber(t1_prs[k]).getId();
            }
            for(int k=0; 11>k; k++){
                if(t2_prs[k]>0) t2_prs[k]=tm2.getPrFromNumber(t2_prs[k]).getId();
            }
        
            for(int k=0; 3>k; k++){
                if(t1_tvz[k]>0) t1_tvz[k]=tm1.getPrFromNumber(t1_tvz[k]).getId();
            }
            for(int k=0; 3>k; k++){
                if(t2_tvz[k]>0) t2_tvz[k]=tm2.getPrFromNumber(t2_tvz[k]).getId();
            }
        
            for(int k=0; 2>k; k++){
                if(mom[k][0]>0){
                    if(mom[k][1]==1) mom[k][0]=tm1.getPrFromNumber(mom[k][0]).getId();
                    else if(mom[k][1]==2) mom[k][0]=tm2.getPrFromNumber(mom[k][0]).getId();
                }
            }
        
            for(int k=0; 28>k; k++){
                if(cards[k][3]>0){
                    if(cards[k][0]==1) cards[k][3]=tm1.getPrFromNumber(cards[k][3]).getId();
                    if(cards[k][0]==2) cards[k][3]=tm2.getPrFromNumber(cards[k][3]).getId();
                }
            }
        
            for(int k=0; 30>k; k++){
                if(goals[k][2]>0){
                    if(goals[k][0]==1) goals[k][2]=tm1.getPrFromNumber(goals[k][2]).getId();
                    if(goals[k][0]==2) goals[k][2]=tm2.getPrFromNumber(goals[k][2]).getId();
                }
                if(goals[k][3]>0){
                    if(goals[k][0]==1) goals[k][3]=tm1.getPrFromNumber(goals[k][3]).getId();
                    if(goals[k][0]==2) goals[k][3]=tm2.getPrFromNumber(goals[k][3]).getId();
                }
            }
        }
		
	void input_game(team tm1,team tm2){
		set_date();
		set_goals(tm1,tm2);
		set_possess_shots(tm1,tm2);
		set_fouls_corners(tm1,tm2);
		set_fk_passc_cross(tm1,tm2);
		set_ic_tackle_save(tm1,tm2);
		setFirstLineup(tm1);
                setFirstLineup(tm2);
		setSubLineup(tm1);
                setSubLineup(tm2);
		set_goals_scorers(tm1,tm2);
		set_tcards(tm1,tm2);
		set_cards(tm1,tm2);
		set_mom(tm1,tm2);
		set_conf(tm1,tm2);
                convertNumbersToID(tm1,tm2);
		exist=1;
		cout<<endl; setColor("BOLDGREEN"); cout<<"Game Entered Succsessfuly.\n"; setColor("RESET");
	}
	void show(team,team);
	//void print_goals(team,team);
	void update_after_game(team &,team &);
	friend class competition;
	friend void add_game(match *,team &,team &);
	//friend void print_all_goals(match *m,team tm1,team tm2);
};

#endif	// MATCH_H

