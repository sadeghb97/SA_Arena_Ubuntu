#ifndef COMPETITION_H
#define COMPETITION_H

#include "saheader.h"

class competition{
	team teamOne;
	team teamTwo;
	match games[200];
        
	
	int * getStreak(team tm,int state){
		//state:    1:Unbeaten Streak | 2:Winning Streak
		if(state!=1 && state!=2) throw -1;
		
		int start;
		int streak=0;
		int * maxStreak;
		maxStreak=new int[3];    //0:Streak | 1:Start | 2:End
		for(int i=0; 3>i; i++) maxStreak[i]=0;
		
		int i;
		for(i=0; games[i].sendexist() && 200>i; i++){
			if(streak==0) start=i;
			if(games[i].getResult()==tm.sendid() || (state==1 && games[i].getResult()==3)) streak++;
			else{
				if(streak>maxStreak[0]){
					maxStreak[0]=streak;
					maxStreak[1]=start;
					maxStreak[2]=i-1;
				}
				streak=0;
			}
		}
		
		if(streak>maxStreak[0]){
			maxStreak[0]=streak;
			maxStreak[1]=start;
			maxStreak[2]=i-1;
		}
		
		return maxStreak;
	}
	
	int getNumGames(){
		int num;
		for(num=0; games[num].sendexist(); num++);
		return num;
	}
		
	int * getUnbeatenStreak(team tm){
		return getStreak(tm,1);
	}
	
	int * getWinningStreak(team tm){
		return getStreak(tm,2);
	}
	
	void printStreak(int *streak){
		if(streak[0]==0) cout<<"0 Match";
		else if(streak[0]==1) cout<<"1 Match | Game "<<streak[1]+1;
		else if(streak[0]>1) cout<<streak[0]<<" Match | Games: ["<<streak[1]+1<<","<<streak[2]+1<<"]";
		 setColor("RESET");
	}
	
	
	//competition(){}
	public:
	competition(team t1,team t2,match m[200]){
		teamOne=t1;
		teamTwo=t2;
		for(int i=0; 200>i; i++) games[i]=m[i];
	}
	
	int ** getAllGoals(){
		int tg=0;
		for(int i=0; games[i].sendexist() && 200>i; i++) tg+=games[i].dynamicGet("tg");
		int **goals;
		goals=new int *[tg];
		for(int i=0; tg>i; i++) goals[i]=new int[6];
		if(tg==0){
			goals[0][0]=0;
			return goals;
		}
		for(int i=0,j=0; games[i].sendexist() && 200>i; i++){
			int **scores;
			scores=games[i].getGoals();
			for(int k=0; games[i].dynamicGet("tg")>k; k++,j++){
				goals[j][0]=i;
				for(int m=1; 5>=m; m++) goals[j][m]=scores[k][m-1];
			}
		}
		return goals;
	}
	
	void WinnerAgLooser(){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
                
		int numGames[15];
		char winName[40];
		char looseName[40];
		strcpy(winName,"Winner");
		strcpy(looseName,"Looser");
		teamGameStat win(winName,0);
		teamGameStat loose(looseName,0);
		
		for(int i=0; 15>i; i++) numGames[i]=0;
		//0: Goals
		//1: Possess
		//2: Shots
		//3: Fouls
		//4: Corners
		//5: Free Kicks
		//6: Passes Completed
		//7: Crosses
		//8: Interception
		//9: Tackles
		//10: Saves
		//11: TCards
		//12: TSubs
		
		for(int i=0; 200>i && games[i].exist==true; i++){
			if(games[i].res>2) continue;
			
			if(games[i].res==1){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t1_goals;
					loose.nGoals+=games[i].t2_goals;
					numGames[0]++;
				}
				
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t1_possess;
					loose.possess+=games[i].t2_possess;
					numGames[1]++;
				}
				
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t1_shots[0]; win.shots[1]+=games[i].t1_shots[1];
					loose.shots[0]+=games[i].t2_shots[0]; loose.shots[1]+=games[i].t2_shots[1];
					numGames[2]++;
				}
				
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t1_fouls[0]; win.fouls[1]+=games[i].t1_fouls[1];
					loose.fouls[0]+=games[i].t2_fouls[0]; loose.fouls[1]+=games[i].t2_fouls[1];
					numGames[3]++;
				}
				
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t1_corners;
					loose.corners+=games[i].t2_corners;
					numGames[4]++;
				}
				
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t1_fk;
					loose.fk+=games[i].t2_fk;
					numGames[5]++;
				}
				
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t1_pass_c;
					loose.passC+=games[i].t2_pass_c;
					numGames[6]++;
				}
				
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t1_cross;
					loose.cross+=games[i].t2_cross;
					numGames[7]++;
				}
				
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t1_interc;
					loose.interc+=games[i].t2_interc;
					numGames[8]++;
				}
				
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t1_tackles;
					loose.tackles+=games[i].t2_tackles;
					numGames[9]++;
				}
				
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t1_saves;
					loose.saves+=games[i].t2_saves;
					numGames[10]++;
				}
				
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t1_tc[0]; win.nCards[1]+=games[i].t1_tc[1];
					loose.nCards[0]+=games[i].t2_tc[0]; loose.nCards[1]+=games[i].t2_tc[1];
					numGames[11]++;
				}
				
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t1_tt;
					loose.nSub+=games[i].t2_tt;
					numGames[12]++;
				}
				
				double tWFirstStrength=games[i].getTeamFirstStrength(1);
				double tLFirstStrength=games[i].getTeamFirstStrength(2);
				if(tWFirstStrength>=0 && tLFirstStrength>=0){
					win.sFOverall+=tWFirstStrength;
					loose.sFOverall+=tLFirstStrength;
					numGames[13]++;
				}
				
				double tWStrength=games[i].getTeamStrength(1);
				double tLStrength=games[i].getTeamStrength(2);
				if(tWStrength>=0 && tLStrength>=0){
					win.sOverall+=tWStrength;
					loose.sOverall+=tLStrength;
					numGames[14]++;
				}
			}
			
			if(games[i].res==2){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t2_goals;
					loose.nGoals+=games[i].t1_goals;
					numGames[0]++;
				}
				
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t2_possess;
					loose.possess+=games[i].t1_possess;
					numGames[1]++;
				}
				
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t2_shots[0]; win.shots[1]+=games[i].t2_shots[1];
					loose.shots[0]+=games[i].t1_shots[0]; loose.shots[1]+=games[i].t1_shots[1];
					numGames[2]++;
				}
				
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t2_fouls[0]; win.fouls[1]+=games[i].t2_fouls[1];
					loose.fouls[0]+=games[i].t1_fouls[0]; loose.fouls[1]+=games[i].t1_fouls[1];
					numGames[3]++;
				}
				
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t2_corners;
					loose.corners+=games[i].t1_corners;
					numGames[4]++;
				}
				
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t2_fk;
					loose.fk+=games[i].t1_fk;
					numGames[5]++;
				}
				
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t2_pass_c;
					loose.passC+=games[i].t1_pass_c;
					numGames[6]++;
				}
				
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t2_cross;
					loose.cross+=games[i].t1_cross;
					numGames[7]++;
				}
				
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t2_interc;
					loose.interc+=games[i].t1_interc;
					numGames[8]++;
				}
				
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t2_tackles;
					loose.tackles+=games[i].t1_tackles;
					numGames[9]++;
				}
				
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t2_saves;
					loose.saves+=games[i].t1_saves;
					numGames[10]++;
				}
				
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t2_tc[0]; win.nCards[1]+=games[i].t2_tc[1];
					loose.nCards[0]+=games[i].t1_tc[0]; loose.nCards[1]+=games[i].t1_tc[1];
					numGames[11]++;
				}
				
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t2_tt;
					loose.nSub+=games[i].t1_tt;
					numGames[12]++;
				}
				
				double tWFirstStrength=games[i].getTeamFirstStrength(2);
				double tLFirstStrength=games[i].getTeamFirstStrength(1);
				if(tWFirstStrength>=0 && tLFirstStrength>=0){
					win.sFOverall+=tWFirstStrength;
					loose.sFOverall+=tLFirstStrength;
					numGames[13]++;
				}
				
				double tWStrength=games[i].getTeamStrength(2);
				double tLStrength=games[i].getTeamStrength(1);
				if(tWStrength>=0 && tLStrength>=0){
					win.sOverall+=tWStrength;
					loose.sOverall+=tLStrength;
					numGames[14]++;
				}
			}
		}
		
		temp1.str("");
		cout<<endl;
		temp1<<"$$WHT"<<"Number of Games: "<<numGames[0]<<"$0RST";
		space(15); beforeStrWhere(temp1,44);  setColor("RESET");
		temp1.str("");
		win.convertToPerGame(numGames);
		loose.convertToPerGame(numGames);
		//cout<<endl<<"WinnerGoals: "<<win.nGoals<<" | LooserGoals: "<<loose.nGoals<<endl;
		showWALTable(win,loose,true,true,true);
	}
	
	bool existKnownData(const char * factor, bool isDouble=false){
		if(!isDouble){
			for(int i=0; games[i].sendexist(); i++){
				if(games[i].dynamicGet(factor)>=0) return true;
			}
		}
		
		else{
			for(int i=0; games[i].sendexist(); i++){
				if(games[i].doubleDynamicGet(factor)>=0) return true;
			}
		}
		return false;
	}
	
	int getMaxMatchIndex(const char * factor,bool isDouble=false){
		int index;
		double max;
		index=0;
		max=-1000;
		
		if(!isDouble){
			int localMax=games[0].dynamicGet(factor);
			for(int i=1; 200>i && games[i].sendexist(); i++){
				if(games[i].dynamicGet(factor)>localMax){
					localMax=games[i].dynamicGet(factor);
					index=i;
				}
				
				else if((strcasecmp(factor,"t1DifGoals")==0 || strcasecmp(factor,"t2DifGoals")==0) &&
				games[i].dynamicGet(factor)==localMax && games[i].dynamicGet("tg")>games[index].dynamicGet("tg")){
					index=i;
				}
			}
			if(localMax==-2) return -1;
		}
		
		else{
			max=games[0].doubleDynamicGet(factor);
			for(int i=1; 200>i && games[i].sendexist(); i++){
				if(games[i].doubleDynamicGet(factor)>max){
					max=games[i].doubleDynamicGet(factor);
					index=i;
				}
			}
			if(max==-2) return -1;
		}
		
		return index;
	}
	
	int getMinMatchIndex(const char * factor,bool isDouble=false){
		int index;
		index=0;
		
		if(!isDouble){
			int localMin=INT_MAX;
			for(int i=0; 200>i && games[i].sendexist(); i++){
				int value=games[i].dynamicGet(factor);
				
				if(value<localMin && value>=0){
					localMin=games[i].dynamicGet(factor);
					index=i;
				}
				
				else if((strcasecmp(factor,"t1DifGoals")==0 || strcasecmp(factor,"t2DifGoals")==0) &&
				value==localMin && games[i].dynamicGet("tg")>games[index].dynamicGet("tg")){
					index=i;
				}
			}
			if(localMin==INT_MAX) return -1;
			return index;
		}
		
		else{
			double min=INT_MAX;
			for(int i=0; 200>i && games[i].sendexist(); i++){
				double value=games[i].doubleDynamicGet(factor);
				if(value<min && value>=0){
					min=value;
					index=i;
				}
			}
			if(min==INT_MAX) return -1;
			return index;
		}
	}
	
	int** getFastestAndLatestGoal(){
		int tg=0;
		int ** twoGoals;
		twoGoals=new int*[2]; //0: Fastest | 1: Latest
		for(int i=0; 2>i; i++) twoGoals[i]=new int[6]; //fast[5] -> game Index
		
		for(int i=0; games[i].sendexist() && 200>i; i++) tg+=games[i].dynamicGet("tg");
		if(tg==0){
			twoGoals[0][0]=0;
			return twoGoals;
		}
		
		bool find=false;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			int **scores;
			scores=games[i].getGoals();
			for(int j=0; games[i].dynamicGet("tg")>j; j++){
				if(scores[j][4]!=-2){
					if(find==false || scores[j][4]<twoGoals[0][4]){
						for(int k=0; 5>k; k++) twoGoals[0][k]=scores[j][k];
						twoGoals[0][5]=i;
					}
					
					if(find==false || scores[j][4]>twoGoals[1][4]){
						for(int k=0; 5>k; k++) twoGoals[1][k]=scores[j][k];
						twoGoals[1][5]=i;
					}
					
					if(!find) find=true;
				}
			}
		}
		return twoGoals;
	}
	
	
	void printMost(){
		if(!games[0].sendexist()) cout<<endl<<"Mosabeghe ei sabt nashode ast!"<<endl;
		else if(teamOne.sendid()==2 && teamTwo.sendid()==1) cout<<endl<<"Error in Teams Order"<<endl;
		else{
			int index;
			cout<<endl; setColor("BOLDRED"); cout<<"Most Stats: "; setColor("RESET"); cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Highest Scoring Game: ";
			index=getMaxMatchIndex("tg");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Most Cards In a Game: ";
			index=getMaxMatchIndex("tcards");
			cout<<games[index].dynamicGet("tcards")<<" Cards"
			<<" | Game "<<index+1; setColor("RESET");
			
			
			int ** twoGoals=getFastestAndLatestGoal();
			if(twoGoals[0][0]!=0){
				int *fast=twoGoals[0];
				cout<<endl; setColor("BOLDBLUE"); cout<<"Fastest Goal: ";
				
				if(fast[0]==1){
					setColor("BOLDMAGENTA");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamOne.getPrFromId(fast[2]).sendname();
					if(fast[3]!=-1 && fast[3]!=-2) cout<<" ("<<teamOne.getPrFromId(fast[3]).sendname()<<")";
					else if(fast[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<fast[4];
				}
				
				else if(fast[0]==2){
					setColor("BOLDCYAN");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamTwo.getPrFromId(fast[2]).sendname();
					if(fast[3]!=-1 && fast[3]!=-2) cout<<" ("<<teamTwo.getPrFromId(fast[3]).sendname()<<")";
					else if(fast[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<fast[4];
				}
				cout<<" | Game "<<fast[5]+1; setColor("RESET");
				
				int *latest=twoGoals[1];
				cout<<endl; setColor("BOLDBLUE"); cout<<"Latest Goal: ";
				if(latest[0]==1){
					setColor("BOLDMAGENTA");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamOne.getPrFromId(latest[2]).sendname();
					if(latest[3]!=-1 && latest[3]!=-2) cout<<" ("<<teamOne.getPrFromId(latest[3]).sendname()<<")";
					else if(latest[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<latest[4];
				}
				
				else if(latest[0]==2){
					setColor("BOLDCYAN");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamTwo.getPrFromId(latest[2]).sendname();
					if(latest[3]!=-1 && latest[3]!=-2) cout<<" ("<<teamTwo.getPrFromId(latest[3]).sendname()<<")";
					else if(latest[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<latest[4];
				}
				cout<<" | Game "<<latest[5]+1; setColor("RESET"); cout<<endl;
				
			}
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Best Result:"; setColor("RESET");
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			index=getMaxMatchIndex("t1DifGoals");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			index=getMaxMatchIndex("t2DifGoals");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Unbeaten Streak:"; setColor("RESET");
			int *streak;
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			streak=getUnbeatenStreak(teamOne);
			printStreak(streak);
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			streak=getUnbeatenStreak(teamTwo);
			printStreak(streak);
			
			cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Winning Streak:"; setColor("RESET");
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			streak=getWinningStreak(teamOne);
			printStreak(streak);
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			streak=getWinningStreak(teamTwo);
			printStreak(streak);
			
			cout<<endl;
			
			if(existKnownData("t1_shotsOne") || existKnownData("t2_shotsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_shotsOne");
					cout<<games[index].dynamicGet("t1_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_shotsOne");
					cout<<games[index].dynamicGet("t2_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_shotsTwo") || existKnownData("t2_shotsTwo")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max On Target Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsTwo")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_shotsTwo");
					cout<<games[index].dynamicGet("t1_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsTwo")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_shotsTwo");
					cout<<games[index].dynamicGet("t2_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_possess") || existKnownData("t2_possess")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Possession:"; setColor("RESET");
				
				if(existKnownData("t1_possess")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_possess");
					cout<<games[index].dynamicGet("t1_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_possess")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_possess");
					cout<<games[index].dynamicGet("t2_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_pass_c") || existKnownData("t2_pass_c")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Pass Completed:"; setColor("RESET");
				
				if(existKnownData("t1_pass_c")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_pass_c");
					cout<<games[index].dynamicGet("t1_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_pass_c")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_pass_c");
					cout<<games[index].dynamicGet("t2_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_interc") || existKnownData("t2_interc")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Interception:"; setColor("RESET");
				
				if(existKnownData("t1_interc")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_interc");
					cout<<games[index].dynamicGet("t1_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_interc")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_interc");
					cout<<games[index].dynamicGet("t2_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_saves") || existKnownData("t2_saves")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Saves:"; setColor("RESET");
				
				if(existKnownData("t1_saves")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_saves");
					cout<<games[index].dynamicGet("t1_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_saves")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_saves");
					cout<<games[index].dynamicGet("t2_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_cross") || existKnownData("t2_cross")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Crosses:"; setColor("RESET");
				
				if(existKnownData("t1_cross")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_cross");
					cout<<games[index].dynamicGet("t1_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_cross")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_cross");
					cout<<games[index].dynamicGet("t2_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_corners") || existKnownData("t2_corners")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Corners:"; setColor("RESET");
				
				if(existKnownData("t1_corners")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_corners");
					cout<<games[index].dynamicGet("t1_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_corners")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_corners");
					cout<<games[index].dynamicGet("t2_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_fk") || existKnownData("t2_fk")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Free Kick:"; setColor("RESET");
				
				if(existKnownData("t1_fk")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_fk");
					cout<<games[index].dynamicGet("t1_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_fk")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_fk");
					cout<<games[index].dynamicGet("t2_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_foulsOne") || existKnownData("t2_foulsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Fouls:"; setColor("RESET");
				
				if(existKnownData("t1_foulsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_foulsOne");
					cout<<games[index].dynamicGet("t1_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_foulsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_foulsOne");
					cout<<games[index].dynamicGet("t2_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_flstrength",true) || existKnownData("t2_flstrength",true)){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max First Line Up Strength:"; setColor("RESET");
				
				if(existKnownData("t1_flstrength",true)){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_flstrength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t1_flstrength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_flstrength",true)){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_flstrength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t2_flstrength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_strength",true) || existKnownData("t2_strength",true)){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Overall Line Up Strength:"; setColor("RESET");
				
				if(existKnownData("t1_strength",true)){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_strength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t1_strength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_strength",true)){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_strength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t2_strength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
		}
	}
	
	void printMins(){
		if(!games[0].sendexist()) cout<<endl<<"Mosabeghe ei sabt nashode ast!"<<endl;
		else if(teamOne.sendid()==2 && teamTwo.sendid()==1) cout<<endl<<"Error in Teams Order"<<endl;
		else{
			int index;
			cout<<endl; setColor("BOLDRED"); cout<<"Minimum Stats: "; setColor("RESET"); cout<<endl;
			
			if(existKnownData("t1_shotsOne") || existKnownData("t2_shotsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_shotsOne");
					cout<<games[index].dynamicGet("t1_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_shotsOne");
					cout<<games[index].dynamicGet("t2_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_shotsTwo") || existKnownData("t2_shotsTwo")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum On Target Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsTwo")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_shotsTwo");
					cout<<games[index].dynamicGet("t1_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsTwo")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_shotsTwo");
					cout<<games[index].dynamicGet("t2_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_possess") || existKnownData("t2_possess")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Possession:"; setColor("RESET");
				
				if(existKnownData("t1_possess")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_possess");
					cout<<games[index].dynamicGet("t1_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_possess")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_possess");
					cout<<games[index].dynamicGet("t2_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_pass_c") || existKnownData("t2_pass_c")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Pass Completed:"; setColor("RESET");
				
				if(existKnownData("t1_pass_c")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_pass_c");
					cout<<games[index].dynamicGet("t1_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_pass_c")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_pass_c");
					cout<<games[index].dynamicGet("t2_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_interc") || existKnownData("t2_interc")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Interception:"; setColor("RESET");
				
				if(existKnownData("t1_interc")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_interc");
					cout<<games[index].dynamicGet("t1_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_interc")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_interc");
					cout<<games[index].dynamicGet("t2_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_saves") || existKnownData("t2_saves")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Saves:"; setColor("RESET");
				
				if(existKnownData("t1_saves")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_saves");
					cout<<games[index].dynamicGet("t1_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_saves")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_saves");
					cout<<games[index].dynamicGet("t2_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_cross") || existKnownData("t2_cross")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Crosses:"; setColor("RESET");
				
				if(existKnownData("t1_cross")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_cross");
					cout<<games[index].dynamicGet("t1_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_cross")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_cross");
					cout<<games[index].dynamicGet("t2_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_corners") || existKnownData("t2_corners")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Corners:"; setColor("RESET");
				
				if(existKnownData("t1_corners")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_corners");
					cout<<games[index].dynamicGet("t1_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_corners")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_corners");
					cout<<games[index].dynamicGet("t2_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_fk") || existKnownData("t2_fk")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Free Kick:"; setColor("RESET");
				
				if(existKnownData("t1_fk")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_fk");
					cout<<games[index].dynamicGet("t1_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_fk")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_fk");
					cout<<games[index].dynamicGet("t2_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_foulsOne") || existKnownData("t2_foulsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Fouls:"; setColor("RESET");
				
				if(existKnownData("t1_foulsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_foulsOne");
					cout<<games[index].dynamicGet("t1_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_foulsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_foulsOne");
					cout<<games[index].dynamicGet("t2_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_flstrength",true) || existKnownData("t2_flstrength",true)){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum First Line Up Strength:"; setColor("RESET");
				
				if(existKnownData("t1_flstrength",true)){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_flstrength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t1_flstrength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_flstrength",true)){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_flstrength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t2_flstrength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_strength",true) || existKnownData("t2_strength",true)){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Minimum Overall Line Up Strength:"; setColor("RESET");
				
				if(existKnownData("t1_strength",true)){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMinMatchIndex("t1_strength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t1_strength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_strength",true)){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMinMatchIndex("t2_strength",true);
					cout<<setprecision(3)<<games[index].doubleDynamicGet("t2_strength")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
		}
	}
	
	int getNumAbsValues(const char * factor,bool isDouble=false){
		int num=0;
		if(!isDouble){
			for (int i=0; games[i].sendexist(); i++){
				if(games[i].dynamicGet(factor)>=0) num++;
			}
		}
		else {
			for (int i=0; games[i].sendexist(); i++){
				if(games[i].doubleDynamicGet(factor)>=0) num++;
			}
		}
		return num;
	}
	
	int getSumValues(const char * factor,bool isDouble=false){
		if(!isDouble){
			int sum=0;
			for (int i=0; games[i].sendexist(); i++){
				if(games[i].dynamicGet(factor)>=0) sum+=games[i].dynamicGet(factor);
			}
			return sum;
		}
		else{
			double sum=0;
			for (int i=0; games[i].sendexist(); i++){
				if(games[i].doubleDynamicGet(factor)>=0) sum+=games[i].doubleDynamicGet(factor);
			}
			return sum;
		}
	}
	
	void compare(double m1,double m2,int s,int h=0){
		for(int i=0; s>i; i++) cout<<" ";
		if(h==0){
			if(m1>m2){ setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<m1; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
			else if(m1<m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<m2; setColor("RESET"); cout<<endl;}
			else if(m1==m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
		}
		else{
			if(m1<m2){ setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<m1; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
			else if(m1>m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<m2; setColor("RESET"); cout<<endl;}
			else if(m1==m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
		}
	}
	
	void compareTeams(){
		int oneNumber,twoNumber, altOneNumber, altTwoNumber;
		cout<<endl<<teamOne.name<<" Against "<<teamTwo.name<<endl;
		cout<<"Apps: "<<teamOne.apps<<endl<<endl;
		cout<<"Wins Percent: "; compare((double)teamOne.wins/teamOne.apps*100,(double)teamTwo.wins/teamTwo.apps*100,23);
		cout<<"Goals Per Game: "; compare((double)teamOne.goals/teamOne.apps,(double)teamTwo.goals/teamTwo.apps,21);
		
		oneNumber=getNumAbsValues("t1YC"); twoNumber=getNumAbsValues("t2YC");
		cout<<"Yellow Cards Per Game: "; compare((double)teamOne.yc/oneNumber,(double)teamTwo.yc/twoNumber,14,1);
		
		oneNumber=getNumAbsValues("t1RC"); twoNumber=getNumAbsValues("t2RC");
		cout<<"Red Cards Per Game: "; compare((double)teamOne.rc/oneNumber,(double)teamTwo.rc/twoNumber,17,1);
		
		oneNumber=getNumAbsValues("t1_possess"); twoNumber=getNumAbsValues("t2_possess");
		cout<<"Possession Per Game: "; compare((double)teamOne.possess/oneNumber,(double)teamTwo.possess/twoNumber,16);
		
		oneNumber=getNumAbsValues("t1_shotsOne"); twoNumber=getNumAbsValues("t2_shotsOne");
		altOneNumber=getNumAbsValues("t1_shotsTwo"); altTwoNumber=getNumAbsValues("t2_shotsTwo");
		cout<<"Shots(On Target) Per Game: ";
		if(teamOne.shots[0]+teamOne.shots[1]>teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "; setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"<<endl;}
		else if(teamOne.shots[0]+teamOne.shots[1]<teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"; setColor("RESET"); cout<<endl;}
		else if(teamOne.shots[0]+teamOne.shots[1]==teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"<<" | "<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"<<endl;}
		
		oneNumber=getNumAbsValues("t1_foulsOne"); twoNumber=getNumAbsValues("t2_foulsOne");
		altOneNumber=getNumAbsValues("t1_foulsTwo"); altTwoNumber=getNumAbsValues("t2_foulsTwo");
		cout<<"Fouls(Offside) Per Game: ";
		if(teamOne.fouls[0]<teamTwo.fouls[0]){ cout<<"            "; setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"<<endl;}
		if(teamOne.fouls[0]>teamTwo.fouls[0]){ cout<<"            "<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"; setColor("RESET"); cout<<endl;}
		if(teamOne.fouls[0]==teamTwo.fouls[0]){ cout<<"            "<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"<<" | "<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"<<endl;}
		
		oneNumber=getNumAbsValues("t1_corners"); twoNumber=getNumAbsValues("t2_corners");
		cout<<"Corners Per Game: "; compare((double)teamOne.corners/oneNumber,(double)teamTwo.corners/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_fk"); twoNumber=getNumAbsValues("t2_fk");
		cout<<"Free Kicks Per Game: "; compare((double)teamOne.fk/oneNumber,(double)teamTwo.fk/twoNumber,16);
		
		oneNumber=getNumAbsValues("t1_pass_c"); twoNumber=getNumAbsValues("t2_pass_c");
		cout<<"Pass Completed Per Game: "; compare((double)teamOne.pass_c/oneNumber,(double)teamTwo.pass_c/twoNumber,12); 
		
		oneNumber=getNumAbsValues("t1_cross"); twoNumber=getNumAbsValues("t2_cross");
		cout<<"Crosses Per Game: "; compare((double)teamOne.cross/oneNumber,(double)teamTwo.cross/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_interc"); twoNumber=getNumAbsValues("t2_interc");
		cout<<"Interception Per Game: "; compare((double)teamOne.interc/oneNumber,(double)teamTwo.interc/twoNumber,14);
		
		oneNumber=getNumAbsValues("t1_tackles"); twoNumber=getNumAbsValues("t2_tackles");
		cout<<"Tackles Per Game: "; compare((double)teamOne.tackles/oneNumber,(double)teamTwo.tackles/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_saves"); twoNumber=getNumAbsValues("t2_saves");
		cout<<"Saves Per Game: "; compare((double)teamOne.saves/oneNumber,(double)teamTwo.saves/twoNumber,21);
	}
	
	void printCompareGraph(double t1val,double t2val,int nStar){
		if(t1val==0 && t2val==0){
			for(int i=0; nStar>i; i++) cout<<"*";
			return;
		}
		
		bool whiteStar=false;
		
		double unit=(t1val+t2val)/nStar;
		double val1=t1val/unit;
		double val2=t2val/unit;
		
		int t1Star=doubleToInt(val1);
		int t2Star=doubleToInt(val2);
		
		if((t1Star+t2Star)!=30){
			whiteStar=(compareDoubleDecimals(val1,val2)==0 && !isInt(val1));
			if(!whiteStar){
				if(compareDoubleDecimals(val1,val2)==1) t1Star++;
				else if(compareDoubleDecimals(val1,val2)==2) t2Star++;
			}
		}
		
		setColor("BOLDMAGENTA");
		for(int i=0; t1Star>i; i++) cout<<"*";
		if(whiteStar){
			setColor("RESET");
			cout<<"*";
		}
		setColor("BOLDCYAN");
		for(int i=0; t2Star>i; i++) cout<<"*";
	}
	
	void printCompareFromFactors(const char*title,const char *t1_factor, const char *t2_factor,int s, int nStar,int valueLen,stringstream &cadr,int prec=2,bool printPH=false, bool fewBetter=false,bool isDouble=false){
		stringstream t1SS,t2SS;
		int t1Sum,t2Sum;
		double t1Avg,t2Avg;
		
		if(strcmp(title,"Wins")==0){
			t1Avg=teamOne.getWins();
			t2Avg=teamTwo.getWins();
		}
		
		else if(isDouble){
			double sum1,sum2;
			if(existKnownData(t1_factor,true)){
				sum1=getSumValues(t1_factor,true);
				t1Avg=(double)sum1/getNumAbsValues(t1_factor,true);
			}
			else t1Avg=-2;
			
			if(existKnownData(t2_factor,true)){
				sum2=getSumValues(t2_factor,true);
				t2Avg=(double)sum2/getNumAbsValues(t2_factor,true);
			}
			else t2Avg=-2;
		}
		
		else{
			if(existKnownData(t1_factor)){
				t1Sum=getSumValues(t1_factor);
				t1Avg=(double)t1Sum/getNumAbsValues(t1_factor);
			}
			else t1Avg=-2;
			
			if(existKnownData(t2_factor)){
				t2Sum=getSumValues(t2_factor);
				t2Avg=(double)t2Sum/getNumAbsValues(t2_factor);
			}
			else t2Avg=-2;
		}
			
		bool UKOne=false;
		bool UKTwo=false;
			
		if(t1Avg==-2){ t1SS<<"UK"; UKOne=true;}		
		if(t2Avg==-2){ t2SS<<"UK"; UKTwo=true;}
			
		if(!UKOne && !UKTwo){
			if((!fewBetter && t1Avg>t2Avg) || (fewBetter && t1Avg<t2Avg)) t1SS<<"$$GRN";
			else if((!fewBetter && t2Avg>t1Avg) || (fewBetter && t2Avg<t1Avg)) t2SS<<"$$GRN";
			t1SS<<setprecision(prec)<<t1Avg;
			t2SS<<setprecision(prec)<<t2Avg;
			if(printPH){
				t1SS<<"%";
				t2SS<<"%";
			}
		}
		else if(!UKOne){
			t1SS<<setprecision(prec)<<t1Avg;
			if(printPH) t1SS<<"%";
		}
		
		else if(!UKTwo){
			t2SS<<setprecision(prec)<<t1Avg;
			if(printPH) t2SS<<"%";
		}
		
		int lineLength=nStar+(valueLen*2);
		space(s); ccsPrint(cadr); cout<<"|"; setColor("BOLDBLUE"); strwhere(title,lineLength,1); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cout<<"|"; strwhere(t1SS,valueLen,0); printCompareGraph(t1Avg,t2Avg,nStar); strwhere(t2SS,valueLen,0); ccsPrint(cadr); cout<<"|";
	}
	
	void revCompareTeams(){
		bool exYTCards=(existKnownData("t1YC") || existKnownData("t2YC"));
		bool exRTCards=(existKnownData("t1RC") || existKnownData("t2RC"));
		bool exPossess=(existKnownData("t1_possess") || existKnownData("t2_possess"));
		bool exShotsOne=(existKnownData("t1_shotsOne") || existKnownData("t2_shotsOne"));
		bool exFoulsOne=(existKnownData("t1_foulsOne") || existKnownData("t2_foulsOne"));
		bool exShotsTwo=(existKnownData("t1_shotsTwo") || existKnownData("t2_shotsTwo"));
		bool exFoulsTwo=(existKnownData("t1_foulsTwo") || existKnownData("t2_foulsTwo"));
		bool exCorners=(existKnownData("t1_corners") || existKnownData("t2_corners"));
		bool exFk=(existKnownData("t1_fk") || existKnownData("t2_fk"));
		bool exPassC=(existKnownData("t1_pass_c") || existKnownData("t2_pass_c"));
		bool exCross=(existKnownData("t1_cross") || existKnownData("t2_cross"));
		bool exInterc=(existKnownData("t1_interc") || existKnownData("t2_interc"));
		bool exTackles=(existKnownData("t1_tackles") || existKnownData("t2_tackles"));
		bool exSaves=(existKnownData("t1_saves") || existKnownData("t2_saves"));
		
		bool exLeft=(existKnownData("t1_left") || existKnownData("t2_left"));
		bool exCenter=(existKnownData("t1_center") || existKnownData("t2_right"));
		bool exRight=(existKnownData("t1_center") || existKnownData("t2_right"));
		
		bool exFLStrength=(existKnownData("t1_flstrength",true) || existKnownData("t2_flstrength",true));
		bool exStrength=(existKnownData("t1_strength",true) || existKnownData("t2_strength",true));
		
		cout<<endl;
		int s=10;
		int nStar=30;
		int valueLen=7;
		int maxLength=nStar+(valueLen*2)+2;
		stringstream cadr;
		cadr<<"$$BLU";
		
		stringstream temp;
		temp<<"$$RED"<<teamOne.getName()<<" Against "<<teamTwo.getName()<<"$0RST";
		space(s); beforeStrWhere(temp,maxLength); cout<<endl;
		temp.str("");
		temp<<"Number Of Games: "<<getNumGames();
		space(s); beforeStrWhere(temp,maxLength); cout<<endl<<endl;
		
		temp.str("");
		temp<<"$$RED"<<"Championship"<<"$0RST";
		space(s); beforeStrWhere(temp,maxLength); cout<<endl;
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		
		printCompareFromFactors("Wins","","",s,nStar,valueLen,cadr); cout<<endl;
		
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		

			
		cout<<endl;
		temp.str("");
		temp<<"$$RED"<<"Stats (Per Game)"<<"$0RST";
		space(s); strwhere(temp,maxLength); cout<<endl;
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		
		printCompareFromFactors("Goals","t1_goals","t2_goals",s,nStar,valueLen,cadr); cout<<endl;
		if(exYTCards){ printCompareFromFactors("Yellow Cards","t1YC","t2YC",s,nStar,valueLen,cadr,2,false,true); cout<<endl;}
		if(exRTCards){ printCompareFromFactors("Red Cards","t1RC","t2RC",s,nStar,valueLen,cadr,2,false,true); cout<<endl;}
		if(exPossess){ printCompareFromFactors("Possession","t1_possess","t2_possess",s,nStar,valueLen,cadr,2,true); cout<<endl;}
		if(exShotsOne){ printCompareFromFactors("Shots","t1_shotsOne","t2_shotsOne",s,nStar,valueLen,cadr); cout<<endl;}
		if(exShotsTwo){ printCompareFromFactors("Shots (On Target)","t1_shotsTwo","t2_shotsTwo",s,nStar,valueLen,cadr); cout<<endl;}
		if(exFoulsOne){ printCompareFromFactors("Fouls","t1_foulsOne","t2_foulsOne",s,nStar,valueLen,cadr,2,false,true); cout<<endl;}
		if(exFoulsTwo){ printCompareFromFactors("Offside","t1_foulsTwo","t2_foulsTwo",s,nStar,valueLen,cadr,2,false,true); cout<<endl;}
		if(exCorners){ printCompareFromFactors("Corners","t1_corners","t2_corners",s,nStar,valueLen,cadr); cout<<endl;}
		if(exFk){ printCompareFromFactors("Free Kick","t1_fk","t2_fk",s,nStar,valueLen,cadr); cout<<endl;}
		if(exPassC){ printCompareFromFactors("Pass Completed","t1_pass_c","t2_pass_c",s,nStar,valueLen,cadr,2,true); cout<<endl;}
		if(exCross){ printCompareFromFactors("Crosses","t1_cross","t2_cross",s,nStar,valueLen,cadr); cout<<endl;}
		if(exInterc){ printCompareFromFactors("Interception","t1_interc","t2_interc",s,nStar,valueLen,cadr); cout<<endl;}
		if(exTackles){ printCompareFromFactors("Tackles","t1_tackles","t2_tackles",s,nStar,valueLen,cadr); cout<<endl;}
		if(exSaves){ printCompareFromFactors("Saves","t1_saves","t2_saves",s,nStar,valueLen,cadr); cout<<endl;}
		
		space(s); setColor("BOLDBLUE"); cadr_dash(maxLength); setColor("RESET");
		
		if(exLeft || exCenter || exRight){
			cout<<endl;
			temp.str("");
			temp<<"$$RED"<<"Attacink Areas (Per Game)"<<"$0RST";
			space(s); strwhere(temp,maxLength); cout<<endl;
			space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
			if(exLeft){ printCompareFromFactors("Left","t1_left","t2_left",s,nStar,valueLen,cadr,2,true); cout<<endl;}
			if(exCenter){ printCompareFromFactors("Center","t1_center","t2_center",s,nStar,valueLen,cadr,2,true); cout<<endl;}
			if(exRight){ printCompareFromFactors("Right","t1_right","t2_right",s,nStar,valueLen,cadr,2,true); cout<<endl;}
			
			space(s); setColor("BOLDBLUE"); cadr_dash(maxLength); setColor("RESET");
		}
		
		if(exFLStrength || exStrength){
			cout<<endl;
			temp.str("");
			temp<<"$$RED"<<"Team Strength (Per Game)"<<"$0RST";
			space(s); strwhere(temp,maxLength); cout<<endl;
			space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
			if(exFLStrength){ printCompareFromFactors("FL Strength","t1_flstrength","t2_flstrength",s,nStar,valueLen,cadr,3,false,false,true); cout<<endl;}
			if(exStrength){ printCompareFromFactors("Overall Strength","t1_strength","t2_strength",s,nStar,valueLen,cadr,3,false,false,true); cout<<endl;}
			
			space(s); setColor("BOLDBLUE"); cadr_dash(maxLength); setColor("RESET");
		}
	}
	
	void printGoalTimes(){
        int *tmOneTimes=new int[7];
        int *tmTwoTimes=new int[7];
        int tmOneNGoals=0;
        int tmTwoNGoals=0;
        for(int i=0; 7>i; i++) tmOneTimes[i]=0;
        for(int i=0; 7>i; i++) tmTwoTimes[i]=0;
        for(int i=0; games[i].sendexist() && 200>i; i++){
			int ** scores;
			scores=games[i].getGoals();
			for(int j=0; games[i].dynamicGet("tg")>j; j++){
				if(scores[j][0]==1){
					tmOneNGoals++;
					if(scores[j][1]==1){
						if(scores[j][4]<=15) tmOneTimes[1]++;
						else if(scores[j][4]<=30) tmOneTimes[2]++;
						else if(scores[j][4]>30) tmOneTimes[3]++;
					}
					else if(scores[j][1]==2){
						if(scores[j][4]<=60) tmOneTimes[4]++;
						else if(scores[j][4]<=75) tmOneTimes[5]++;
						else if(scores[j][4]>75) tmOneTimes[6]++;
					}
					else if(scores[j][1]<0){
						tmOneTimes[0]++;
					}
				}
				else if(scores[j][0]==2){
					tmTwoNGoals++;
					if(scores[j][1]==1){
						if(scores[j][4]<=15) tmTwoTimes[1]++;
						else if(scores[j][4]<=30) tmTwoTimes[2]++;
						else if(scores[j][4]>30) tmTwoTimes[3]++;
					}
					else if(scores[j][1]==2){
						if(scores[j][4]<=60) tmTwoTimes[4]++;
						else if(scores[j][4]<=75) tmTwoTimes[5]++;
						else if(scores[j][4]>75) tmTwoTimes[6]++;
					}
					else if(scores[j][1]<0){
						tmTwoTimes[0]++;
					}
				}
			}
        }
		
        cout<<endl; setColor("BOLDRED"); cout<<"Goal Times: "; setColor("RESET"); cout<<endl;

        cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<" Goal Times: "<<endl;
        cout<<"All Goals: "<<tmOneNGoals<<" Goals"<<endl;
        cadr_dash(15);
        cout<<"Min [0-15]: "<<tmOneTimes[1]<<" Goals"<<endl;
        cout<<"Min [15-30]: "<<tmOneTimes[2]<<" Goals"<<endl;
        cout<<"Min [30-45]: "<<tmOneTimes[3]<<" Goals"<<endl;
        cout<<"Min [45-60]: "<<tmOneTimes[4]<<" Goals"<<endl;
        cout<<"Min [60-75]: "<<tmOneTimes[5]<<" Goals"<<endl;
        cout<<"Min [75-90]: "<<tmOneTimes[6]<<" Goals"<<endl;
        cadr_dash(15);
        if(tmOneTimes[0]>0) cout<<"Unknown: "<<tmOneTimes[0]<<" Goals"<<endl;
        cout<<"First Half: "<<tmOneTimes[1]+tmOneTimes[2]+tmOneTimes[3]<<" Goals"<<endl;
        cout<<"Second Half: "<<tmOneTimes[4]+tmOneTimes[5]+tmOneTimes[6]<<" Goals"<<endl;

        cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<" Goal Times: "<<endl;
        cout<<"All Goals: "<<tmTwoNGoals<<" Goals"<<endl;
        cadr_dash(15);
        cout<<"Min [0-15]: "<<tmTwoTimes[1]<<" Goals"<<endl;
        cout<<"Min [15-30]: "<<tmTwoTimes[2]<<" Goals"<<endl;
        cout<<"Min [30-45]: "<<tmTwoTimes[3]<<" Goals"<<endl;
        cout<<"Min [45-60]: "<<tmTwoTimes[4]<<" Goals"<<endl;
        cout<<"Min [60-75]: "<<tmTwoTimes[5]<<" Goals"<<endl;
        cout<<"Min [75-90]: "<<tmTwoTimes[6]<<" Goals"<<endl;
        cadr_dash(15);
        if(tmTwoTimes[0]>0) cout<<"Unknown: "<<tmTwoTimes[0]<<" Goals"<<endl;
        cout<<"First Half: "<<tmTwoTimes[1]+tmTwoTimes[2]+tmTwoTimes[3]<<" Goals"<<endl;
        cout<<"Second Half: "<<tmTwoTimes[4]+tmTwoTimes[5]+tmTwoTimes[6]<<" Goals"<<endl;
	}
	
	void printGraphResults(){
		if(!games[0].sendexist()){
			cout<<endl<<"Hanuz Bazi ei Bargozar Nashode Ast"<<endl;
			return;
		}
		
		cout<<endl; setColor("BOLDRED"); cout<<"Results Graph: "; setColor("RESET"); cout<<endl;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			if(i/10*10==i){ cout<<endl; setColor("BOLDBLACK"); cout<<"| "; setColor("RESET");}
			switch(games[i].dynamicGet("res")){
				case 1: setColor("BOLDMAGENTA"); break;
				case 2: setColor("BOLDCYAN"); break;
				case 3: setColor("BOLDWHITE"); break;
			}
			if(i<9) cout<<"0";
			cout<<i+1; setColor("BOLDBLACK"); cout<<" | "; setColor("RESET");
		}
		cout<<endl<<endl;
		
		for(int i=0; games[i].sendexist() && 200>i; i++){
			if(i/10*10==i){ setColor("BOLDBLACK"); cout<<endl<<"| "; setColor("RESET");}
			switch(games[i].dynamicGet("res")){
				case 1: setColor("BOLDMAGENTA"); break;
				case 2: setColor("BOLDCYAN"); break;
				case 3: setColor("BOLDWHITE"); break;
			}
			cout<<games[i].dynamicGet("t1_goals")<<"-"<<games[i].dynamicGet("t2_goals");
			setColor("BOLDBLACK"); cout<<" | "; setColor("RESET");
		}
		cout<<endl;
	}
	
	int ** getOrderedSoloPerformance(){
		int tp,tp1;
		for(tp1=0; games[tp1].sendexist() && 200>tp1; tp1++);
		tp=tp1*15;
		int **prStats;
		prStats=new int*[tp];
		for(int i=0; tp>i; i++){
			prStats[i]=new int[6];     //0:Match Index | 1:Team | 2:Player ID | 3:Goals | 4:Assists | 5:Goals+Assists
			for(int j=0; 5>j; j++) prStats[i][j]=0;
		}
		int k=0;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			int **gStats=games[i].getPlayersStats();
			for(int j=0; gStats[j][0]!=0; j++,k++){
				prStats[k][0]=i;
				for(int m=0; 4>m; m++) prStats[k][m+1]=gStats[j][m];
				prStats[k][5]=prStats[k][3]+prStats[k][4];
			}
		}
		if(k==0){
			return prStats;
		}
		
		int number=k;
		int *max;
		max=new int[6];
		int index;
		for(int i=0; number>i && prStats[i][1]!=0; i++){
			index=i;
			for(int m=0; 6>m; m++) max[m]=prStats[i][m];
			for(int j=i+1; number>j && prStats[j][1]!=0; j++){
				if(prStats[j][5]>max[5] || (prStats[j][5]==max[5] && prStats[j][3]>max[3])){
					for(int m=0; 6>m; m++) max[m]=prStats[j][m];
					index=j;
				}
			}
			if(index!=i){
				for(int m=0; 6>m; m++) prStats[index][m]=prStats[i][m];
				for(int m=0; 6>m; m++) prStats[i][m]=max[m];
			}
		}
                
		return prStats;
	}
	
	void printBestSoloPerformance(){
		int **prStats;
		prStats=getOrderedSoloPerformance();
		cout<<endl; setColor("BOLDRED"); cout<<"Best Solo Performance: "; setColor("RESET"); cout<<endl;
		for(int i=0; prStats[i][5]>=3 && prStats[i][1]!=0; i++){
			if(prStats[i][1]==1){
				if(prStats[i][3]>0 && prStats[i][4]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][3]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][4]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
			}
			else if(prStats[i][1]==2){
				if(prStats[i][3]>0 && prStats[i][4]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][3]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][4]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
			}
		}
		cout<<endl;
	}
        
    void moratab(int tmp[][3],int s){
            int tp1,tp2;
            for(tp1=0; teamOne.pr[tp1].sendexist(); tp1++);
            for(tp2=0; teamTwo.pr[tp2].sendexist(); tp2++);
            if(s==1){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendapps();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendapps();
            }
            if(s==2){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendgoals();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendgoals();
            }
            if(s==3){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendass();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendass();
            }
            if(s==4){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].getHatTricks();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].getHatTricks();
            }
            if(s==5){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendmom();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendmom();
            }
            if(s==6){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendyc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendyc();
            }
            if(s==7){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendrc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendrc();
            }
            if(s==8){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendyc()+ 2* teamOne.pr[j].sendrc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendyc()+ 2* teamTwo.pr[j].sendrc();
            }
            int i,j,big,andis,tp[3],anjam;
            for(i=0; 200>i; i++){
                    big=tmp[i][2];
                    anjam=0;
                    for(j=i+1; 200>j; j++){
                            if(tmp[j][2]>big){
                                    big=tmp[j][2];
                                    andis=j;
                                    anjam=1;
                            }
                    }
                    if(anjam==1){
                            tp[0]=tmp[i][0];
                            tp[1]=tmp[i][1];
                            tp[2]=tmp[i][2];
                            tmp[i][0]=tmp[andis][0];
                            tmp[i][1]=tmp[andis][1];
                            tmp[i][2]=tmp[andis][2];
                            tmp[andis][0]=tp[0];
                            tmp[andis][1]=tp[1];
                            tmp[andis][2]=tp[2];
                    }
            }
    }
    
    void subsumePlayers(){
		int choice;
		while(1){
			setColor("BOLDRED"); cout<<"\nSubsumption Players:\n"; setColor("RESET");
			cout<<"1: Most Apps\n2: Top Scorers\n3: Top Assisters\n4: Top HatTrickers\n5: Most MOTM Points\n"
			<<"6: Most yellow cards\n7: Most red cards\n8: Most Violence\n9: Back to main\n\nEnter your choice\n";
			choice=inputChoice(1,9);
			if(choice==9) break;
			else{
				int tmp[300][3],tp1,tp2,i;
				for(tp1=0; teamOne.pr[tp1].sendexist(); tp1++);
				for(tp2=0; teamTwo.pr[tp2].sendexist(); tp2++);
				i=0;
				for(int j=0; tp1>j; i++,j++){
					tmp[i][0]=1;
					tmp[i][1]=j;
				}
				for(int j=0; tp2>j; i++,j++){
					tmp[i][0]=2;
					tmp[i][1]=j;
				}
				for(; 300>i; i++){ tmp[i][0]=0; tmp[i][1]=0; tmp[i][2]=-1;}
				switch(choice){
					case 1: cout<<endl; setColor("BOLDRED"); cout<<"Most Apps:\n"; setColor("RESET"); break;
					case 2: cout<<endl; setColor("BOLDRED"); cout<<"Top Scorers:\n"; setColor("RESET"); break;
					case 3: cout<<endl; setColor("BOLDRED"); cout<<"Top Assisters:\n"; setColor("RESET"); break;
					case 4: cout<<endl; setColor("BOLDRED"); cout<<"Top Hat Trickers:\n"; setColor("RESET"); break;
					case 5: cout<<endl; setColor("BOLDRED"); cout<<"Most MOTM Points:\n"; setColor("RESET"); break;
					case 6: cout<<endl; setColor("BOLDRED"); cout<<"Most Yellow Cards:\n"; setColor("RESET"); break;
					case 7: cout<<endl; setColor("BOLDRED"); cout<<"Most Red Cards:\n"; setColor("RESET"); break;
					case 8: cout<<endl; setColor("BOLDRED"); cout<<"Most Violence:\n"; setColor("RESET"); break;
				}
				moratab(tmp,choice);
				for(int i=0; 200>i; i++){
					if(tmp[i][2]<1) break;
					cout<<i+1<<": ";
					if(tmp[i][0]==1){ setColor("BOLDMAGENTA"); cout<<teamOne.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]; setColor("RESET");}
					else if(tmp[i][0]==2){ setColor("BOLDCYAN"); cout<<teamTwo.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]; setColor("RESET");}
					cout<<endl;
				}
			}
		}
    }
		
};

#endif	// COMPETITION_H

