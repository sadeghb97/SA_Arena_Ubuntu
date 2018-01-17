#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using namespace std;
int easycheck(int,int,int);
int checkchoice(char[],int,int);
void strwhere(const char*,int,int);
void space(int);
void cadr_dash(int);
void swap(int &,int &);
void swap(int [],int [],int n);

class player;
class team;
class match;
class competition;
struct teamGameStat;
struct date;


void save(team,team, match *);
void load(team &, team &, match *);
int exist_players(int,int[],int[]);
int menu(team,team);
void team_manage(team &);
void add_game(match *,team &,team &);
void update_after_game(team &,team &,match);
void showTableStats(teamGameStat, teamGameStat ,date ,bool, bool, bool);
void print_passage(char *);
void details_repair(match *, team &,team &);
void compare(team,team,double,double,int,int);
void competition_stats(team ,team ,match []);
void compare_teams(team,team);
void subsume_players(team,team);
void show_game(match *,team,team);
void moratab(int[][3],int,int,int);

stringstream temp1;
stringstream temp2;
stringstream temp3;
stringstream temp4;
stringstream temp5;
stringstream temp6;

struct date{
	bool isEmpty;
	int year;
	int month;
	int day;
	
	date(){
		isEmpty=true;
	}
	date(int y, int m, int d){
		year=y;
		month=m;
		day=d;
		isEmpty=false;
	}
};

class player{
	int exist;
	char name[30];
	int id;
	int post;
	int apps;
	int goals;
	int assists;
	int mom;
	int rc;
	int yc;
	char temp[10];
	public:
	player(){
		exist=0; apps=0; goals=0; assists=0; mom=0; rc=0; yc=0; id=0;
	}
	void add(void){
		cout<<"\nEnter name then post(1-5)\n";
		cin >>name >>temp;
		if(checkchoice(temp,1,5)!=0) post=checkchoice(temp,1,5);
		while(checkchoice(temp,1,5)==0){
			cout<<"Enter Post Again\n";
			cin >>temp;
			if(checkchoice(temp,1,5)!=0) post=checkchoice(temp,1,5);
		}
		exist=1;
	}
	void zero(void){
		apps=0; goals=0; assists=0; mom=0; rc=0; yc=0;
	}
	int sendexist(void){ return exist;}
	int sendgoals(void){ return goals;}
	int sendapps(void){ return apps;}
	int sendass(void){ return assists;}
	int sendmom(void){ return mom;}
	int sendrc(void){ return rc;}
	int sendyc(void){ return yc;}
	char* sendname(void){ return name;}
	void change_id(int t){ id=t;}
	void del(void){ exist=-1;}
	void app_p(void){ apps++;}
	void goal_p(void){ goals++;}
	void ass_p(void){ assists++;}
	void mom_p(void){ mom++;}
	void rc_p(void){ rc++;}
	void yc_p(void){ yc++;}
	void show(void){
		if(exist==1){
			cout<<endl <<"Name: " <<name <<endl;
			cout<<"Post: " <<post <<endl;
			cout<<"Tedade Bazi: " <<apps <<endl;
			cout<<"Goals: " <<goals <<endl;
			cout<<"Assists: " <<assists <<endl;
			cout<<"Man Of The Match: " <<mom <<endl;
			cout<<"Yellow Card: " <<yc <<endl;
			cout<<"Red Card: " <<rc <<endl;
		}
		else if(exist==0) cout<< "This player does not exist !"<<endl;
		else if(exist==-1) cout<< "This Player Deleted Already"<<endl;
	}
	friend class team;
	friend class match;
};
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
		for(int i=0; 200>i; i++) pr[i].change_id(i+1);
	}
	void add(void){
		cout<<"Enter name then ID(1-2)\n";
		cin >>name >>temp;
		if(checkchoice(temp,1,2)!=0) id=checkchoice(temp,1,2);
		while(checkchoice(temp,1,2)==0){
			cout<<"Enter ID Again\n";
			cin >>temp;
			if(checkchoice(temp,1,2)!=0) id=checkchoice(temp,1,2);
		}
		exist=1;
	}
	void zero(void){
		apps=0; goals=0; rc=0; yc=0; wins=0; lose=0; draw=0;
		possess=0; corners=0; fk=0; pass_c=0; cross=0; interc=0; tackles=0; saves=0;
		for(int i=0; 2>i; i++){
			shots[i]=0;
			fouls[i]=0;
		}
	}
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
	void printname(void){ cout<<name;}
	void show(void){
		cout<<BOLDRED<<"\nName: "<<name<<RESET<<endl;
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
	void show_mini_prs(void){
		if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
		else{
			cout<<BOLDGREEN<<"\nMini Players List:\n"<<RESET;
			for(int i=0; pr[i].exist!=0; i++){
				cout<<pr[i].id<<":  ";
				if(pr[i].sendexist()==-1) cout<<"Deleted"<<endl;
				else cout<<pr[i].name<<endl;
			}
		}
	}
	void show_det_prs(void){
		if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
		else{
			cout<<BOLDGREEN<<"\nDetailed Players List:\n"<<RESET;
			for(int i=0; pr[i].exist!=0; i++){	
				cout<<BOLDGREEN<<endl<<"Player "<<i+1<<":  "<<RESET;
				pr[i].show();
			}
		}
	}
	void add_prs(void){
		char temp[10];
		int c,i;
		do{
			for(i=0; pr[i].sendexist()!=0; i++);
			if(i<200){cout<<"\nPlayer "<<i+1 <<":"; pr[i].add();} else{ cout<<"\nError!!! Full Capacity\n"; break;}
			cout<<"\nContinue? (1:Yes | 2:No)\n";
			do cin>>temp; while(checkchoice(temp,1,3)==0);
			c=checkchoice(temp,1,3);
		} while(c==1);
	}
	friend class match;
	friend class competition;
	friend void compare(team,team,double,double,int,int);
	friend void compare_teams(team,team);
	friend void top_scorers(team,team);
};

struct teamGameStat{
	char name[40];
	double nSub;
	double nGoals;
	double possess;
	double shots[2];
	double fouls[2];
	double corners;
	double fk;
	double passC;
	double cross;
	double interc;
	double tackles;
	double saves;
	double nCards[2];
	
	//teamGameStat(){}
	teamGameStat(char teamName[],int defValue){
		strcpy(name,teamName);
		nSub=defValue; nGoals=defValue; possess=defValue; shots[0]=defValue; shots[1]=defValue;
		fouls[0]=defValue; fouls[1]=defValue; corners=defValue; fk=defValue; passC=defValue;
		cross=defValue; interc=defValue; tackles=defValue; saves=defValue; nCards[0]=defValue; nCards[1]=defValue;
	}
	
	bool isComplete(){
		if(nSub>=0 && nGoals>=0 && possess>=0 && shots[0]>=0 && shots[1]>=0 && fouls[0]>=0 && fouls[1]>=0 && corners>=0
		&& fk>=0 && passC>=0 && cross>=0 && interc>=0 && tackles>=0 && saves>=0 && nCards[0]>=0 && nCards[1]>=0){
			return true;
		}
		return false;
	}
	
	void convertToPerGame(int number){
		nSub/=number; nGoals/=number; possess/=number; shots[0]/=number; shots[1]/=number;
		fouls[0]/=number; fouls[1]/=number; corners/=number; fk/=number; passC/=number;
		cross/=number; interc/=number; tackles/=number; saves/=number; nCards[0]/=number; nCards[1]/=number;
	}
};

class match{
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
	char t1_conf[300];
	char t2_conf[300];
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
	bool sendexist(void){ return exist;}
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
	void set_date(void){
		int bar,error,choice;
		cout<<"\nEnter Date of Match (Year | Month | Day)\n";
		bar=0;
		do{
			error=0;
			bar++;
			if(bar>1) cout<<endl<<BOLDYELLOW<<"Adade vorudi Na motabarand. Try Again\n"<<RESET<<endl;
			cin>>year>>month>>day;
			if(((year<1300 || year>1500) && year !=-2) || ((month<1 || month>12) && month!=-2) || ((day<1 || day>31) && day!=-2)) error=1;
		} while (error==1);
		if(year==-2){ month=-2; day=-2;}
		if(month==-2) day=-2;
		cout<<endl<<BOLDBLUE<<"Date Of Match: ";
		if(year!=-2) cout<<year<<"/"; else cout<<"UK"<<"/";
		if(month!=-2 && month>9) cout<<month<<"/"; else if(month!=-2 && month<10)cout<<"0"<<month<<"/"; else cout<<"UK"<<"/";
		if(day!=-2 && day>9) cout<<day<<RESET<<endl; else if(day!=-2 && day<10)cout<<"0"<<day<<RESET<<endl; else cout<<"UK"<<RESET<<endl;
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2) set_date();
	}	
	void set_goals(team,team);
	void set_possess_shots(team,team);
	void set_fouls_corners(team,team);
	void set_fk_passc_cross(team,team);
	void set_ic_tackle_save(team,team);
	void set_tm1_first_lineup(team);
	void set_tm2_first_lineup(team);
	void set_tedad_taviz(team,team);
	void set_tvz_lineup(team,team);
	void set_goals_scorers(team,team);
	void set_tcards(team,team);
	void set_cards(team,team);
	void set_mom(team,team);
	void set_conf(team,team);
	void input_game(team tm1,team tm2){
		set_date();
		set_goals(tm1,tm2);
		set_possess_shots(tm1,tm2);
		set_fouls_corners(tm1,tm2);
		set_fk_passc_cross(tm1,tm2);
		set_ic_tackle_save(tm1,tm2);
		set_tm1_first_lineup(tm1);
		set_tm2_first_lineup(tm2);
		set_tedad_taviz(tm1,tm2);
		set_tvz_lineup(tm1,tm2);
		set_goals_scorers(tm1,tm2);
		set_tcards(tm1,tm2);
		set_cards(tm1,tm2);
		set_mom(tm1,tm2);
		set_conf(tm1,tm2);
		exist=1;
		cout<<endl<<BOLDGREEN<<"Game Entered Succsessfuly.\n"<<RESET;
	}
	void show(team,team);
	//void print_goals(team,team);
	void update_after_game(team &,team &);
	friend class competition;
	friend void add_game(match *,team &,team &);
	//friend void print_all_goals(match *m,team tm1,team tm2);
};
class competition{
	team teamOne;
	team teamTwo;
	match games[200];
	
	//competition(){}
	public:
	competition(team t1,team t2,match m[200]){
		teamOne=t1;
		teamTwo=t2;
		for(int i=0; 200>i; i++) games[i]=m[i];
	}
	
	void WinnerAgLooser(){
		int numberGames=0;
		char winName[40];
		char looseName[40];
		strcpy(winName,"Winner");
		strcpy(looseName,"Looser");
		teamGameStat win(winName,0);
		teamGameStat loose(looseName,0);
		
		for(int i=0; 200>i && games[i].exist==true; i++){
			if(games[i].res>2) continue;
			numberGames++;
			
			if(games[i].res==1){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t1_goals;
					loose.nGoals+=games[i].t2_goals;
				}
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t1_tt;
					loose.nSub+=games[i].t2_tt;
				}
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t1_possess;
					loose.possess+=games[i].t2_possess;
				}
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t1_shots[0]; win.shots[1]+=games[i].t1_shots[1];
					loose.shots[0]+=games[i].t2_shots[0]; loose.shots[1]+=games[i].t2_shots[1];
				}
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t1_fouls[0]; win.fouls[1]+=games[i].t1_fouls[1];
					loose.fouls[0]+=games[i].t2_fouls[0]; loose.fouls[1]+=games[i].t2_fouls[1];
				}
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t1_corners;
					loose.corners+=games[i].t2_corners;
				}
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t1_fk;
					loose.fk+=games[i].t2_fk;
				}
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t1_pass_c;
					loose.passC+=games[i].t2_pass_c;
				}
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t1_cross;
					loose.cross+=games[i].t2_cross;
				}
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t1_interc;
					loose.interc+=games[i].t2_interc;
				}
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t1_tackles;
					loose.tackles+=games[i].t2_tackles;
				}
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t1_saves;
					loose.saves+=games[i].t2_saves;
				}
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t1_tc[0]; win.nCards[1]+=games[i].t1_tc[1];
					loose.nCards[0]+=games[i].t2_tc[0]; loose.nCards[1]+=games[i].t2_tc[1];
				}
			}
			
			if(games[i].res==2){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t2_goals;
					loose.nGoals+=games[i].t1_goals;
				}
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t2_tt;
					loose.nSub+=games[i].t1_tt;
				}
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t2_possess;
					loose.possess+=games[i].t1_possess;
				}
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t2_shots[0]; win.shots[1]+=games[i].t2_shots[1];
					loose.shots[0]+=games[i].t1_shots[0]; loose.shots[1]+=games[i].t1_shots[1];
				}
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t2_fouls[0]; win.fouls[1]+=games[i].t2_fouls[1];
					loose.fouls[0]+=games[i].t1_fouls[0]; loose.fouls[1]+=games[i].t1_fouls[1];
				}
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t2_corners;
					loose.corners+=games[i].t1_corners;
				}
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t2_fk;
					loose.fk+=games[i].t1_fk;
				}
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t2_pass_c;
					loose.passC+=games[i].t1_pass_c;
				}
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t2_cross;
					loose.cross+=games[i].t1_cross;
				}
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t2_interc;
					loose.interc+=games[i].t1_interc;
				}
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t2_tackles;
					loose.tackles+=games[i].t1_tackles;
				}
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t2_saves;
					loose.saves+=games[i].t1_saves;
				}
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t2_tc[0]; win.nCards[1]+=games[i].t2_tc[1];
					loose.nCards[0]+=games[i].t1_tc[0]; loose.nCards[1]+=games[i].t1_tc[1];
				}
			}
			
						
			
		}
		temp1.str("");
		cout<<endl<<BOLDWHITE;
		temp1<<"Number of Games: "<<numberGames;
		space(29); cout<<temp1.str()<<RESET;
		temp1.str("");
		win.convertToPerGame(numberGames);
		loose.convertToPerGame(numberGames);
		//cout<<endl<<"WinnerGoals: "<<win.nGoals<<" | LooserGoals: "<<loose.nGoals<<endl;
		date emptyDate;
		showTableStats(win,loose,emptyDate,true,false,false);
	}
};



int main(){
	int choice;
	char temp[10];
	team t1,t2;
	match *game;
	game = new match[200];
	cout<<BOLDRED<<"Be name khoda\n"<<RESET;
	cout<<"Wellcome to SA-Arena\n\n";
	cout<<BOLDRED<<"Enter your choice\n"<<RESET;
	cout<<"1: Start a new Tornoment\n"<<"2: Load Recent Tornoment\n";
	cin >>temp;
	while (checkchoice(temp,1,2)==0) cin >>temp;
	choice =checkchoice(temp,1,2);
	if(choice==1){
		int i=0;
		do{ 
			if(i>0) cout<<"\nError !!! Try Again.\n";
			cout<<BOLDRED<<"\nTeam 1:\n"<<RESET;
			t1.add();
			cout<<BOLDRED<<"\nTeam 2:\n"<<RESET;
			t2.add();
			i++;
		} while(t1.sendid()==t2.sendid());
	}
	else load(t1,t2,game);
	if(t1.sendid()==t2.sendid()) cout<<BOLDBLACK<<"Warning!!! Error in Team Id\n\n";
	while(1){
		choice=menu(t1,t2);
		switch(choice){
			case 1: team_manage(t1); break;
			case 2: team_manage(t2); break;		
			case 3: add_game(game,t1,t2); break;
			case 4: show_game(game,t1,t2); break;
			case 5: competition_stats(t1,t2,game); break;
			case 6: details_repair(game,t1,t2); break; 
			case 7: save(t1,t2,game); break;
			case 8: load(t1,t2,game); break;
		}
		if(choice==9) break;
	}
	return 0;
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

void space(int s){
	if(s>0) for(int i=0; s>i; i++) cout<<" ";
}
void cadr_dash(int tul){
	for(int i=0; tul>i; i++) cout<<"-";
	cout<<endl;
}
int checkchoice (char a[],int min,int max){
	if (min<0) min=-1000;
	if (max<0) max=1000;
	int t,i,out=0,zarb=1,r;
	for (t=0; a[t]; t++);
	for (i=0; t>i; i++) if(a[i]>57 || a[i]<48){
		cout<< "\nShoma bayad adad vared konid\n";
		return 0;
	}
	for (i=0; t-1>i; i++) zarb=zarb*10;
	for (i=0; t>i; i++){
		r= a[i]-48;
		out=out+r*zarb;
		zarb=zarb/10;
	}
	if(out<min || out>max){
		cout<< "\nNa Motabar. (" <<min << "<=vorudi<=" <<max <<")\n";
		return 0;
	}
	return out;
}
int easycheck (int num, int min, int max){
	if(num<min || num>max) return 0;
	return 1;
}
void print_passage(char *p){
	char space=32;
	for(int i=0; p[i]!=0 || i==0; i++){
		if(i==0){ if(p[i]==0){ cout<<"No Confrence"; break;}}
		if(p[i]==95) cout<<space;
		else cout<<p[i];
	}
}
void strwhere(const char *a,int zarf,int halat=0){
	int len=strlen(a);
	int s=(zarf-len)/2;
	if(halat==0) cout<<RESET;
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}
void save(team tm1,team tm2,match *m){
	int choice;
	char temp[10];
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==1){
		fstream f1("data.bin" , ios::out | ios::binary);
		f1.write((char *)&tm1,sizeof(tm1));
		f1.write((char *)&tm2,sizeof(tm2));
		f1.write((char *)m,sizeof(match)*200);
		f1.close();
		cout<<"Tornoment Saved Successfuly.\n";
	}
}
void load(team &tm1, team &tm2, match *m){
	fstream f1("data.bin" , ios::in | ios::binary);
	f1.read((char *)&tm1, sizeof(tm1));
	f1.read((char *)&tm2, sizeof(tm2));
	f1.read((char *)m, sizeof(match)*200);
	f1.close();
	cout<<"Tornoment Loaded Successfuly.\n";
}
int menu(team t1,team t2){
	char choice[10];
	int c;
	cout<<BOLDRED <<"\nMenu: \n" <<RESET;
	cout<<"1: ";
	t1.printname();
	cout<<"\n2: ";
	t2.printname();
	cout<<"\n3: Add match\n4: Show match\n5: Competition Stats\n6: Repair details\n7: Save\n8: Load\n9: Exit\n";
	cout<<"\nEnter your choice: \n";
	cin>>choice;
	while(checkchoice(choice,1,9)==0) cin>>choice;
	c=checkchoice(choice,1,9);
	return c;
}
void team_manage(team &tm){
	char temp[10];
	int choice;
	while(1){
		cout<<"\n" <<BOLDRED;
		tm.printname();
		cout<<" Session\n"<<RESET;
		cout<<"1: Show Team Results\n2: Add Players\n3: Show Mini Players List \n4: Show Detailed Player List\n5: Back to main\n\nEnter your choice\n";
		do cin>>temp; while(checkchoice(temp,1,5)==0);
		choice=checkchoice(temp,1,5);
		switch(choice){
			case 1: tm.show(); break;
			case 2: tm.add_prs(); break;
			case 3: tm.show_mini_prs(); break;
			case 4: tm.show_det_prs(); break;
		}
		if (choice==5) break;
	}
}

void competition_stats(team tm1,team tm2,match m[200]){
	char temp[10];
	int choice;
	competition league(tm1,tm2,m);
	while(1){
		cout<<"\n" <<BOLDRED;
		cout<<BOLDRED<<"Competition Stats\n"<<RESET;
		cout<<"1: Compare Teams\n2: Subsume Players\n3: Winners Against Loosers\n4: Back to main\n\nEnter your choice\n";
		do cin>>temp; while(checkchoice(temp,1,4)==0);
		choice=checkchoice(temp,1,4);
		switch(choice){
			case 1: compare_teams(tm1,tm2); break;
			case 2: subsume_players(tm1,tm2); break;
			case 3: league.WinnerAgLooser(); break;
		}
		if (choice==4) break;
	}
}


void match::set_goals(team tm1,team tm2){
	int choice,error=0;
	cout<<"\nEnter Goals Respectively (According to ID)\n";
	cin>>t1_goals>>t2_goals;
	temp1.str("");
	temp2.str("");
	if(t1_goals==-2) temp1<<"UK"; else if(t1_goals<0 || t1_goals>20){ temp1<<"Null"; error=1;} else if(t1_goals>=0) temp1<<t1_goals;
	if(t2_goals==-2) temp2<<"UK"; else if(t2_goals<0 || t2_goals>20){ temp2<<"Null"; error=1;} else if(t2_goals>=0) temp2<<t2_goals;
	cout<<endl<<BOLDBLUE<<tm1.name<<" "<<temp1.str()<<" - "<<temp2.str()<<" "<<tm2.name<<RESET<<endl;
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane goal ha. Try again.\n"<<RESET;
		set_goals(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_goals(tm1,tm2); return;}
	if(t1_goals<0 || t1_goals>20 || t2_goals<0 || t2_goals>20){
		cout<<endl<<BOLDYELLOW<<"Error Dar tedade goal ha. Try Again\n"<<RESET;
		set_goals(tm1,tm2);
		return;
	}
	if(t1_goals>t2_goals) res=1; else if(t2_goals>t1_goals) res=2; else if(t1_goals==t2_goals) res=3;
}
void match::set_possess_shots(team tm1,team tm2){
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Possession Respectively:\n"; cin>>t1_possess>>t2_possess;
	cout<<"\nEnter Shots(On Target) Respectively"<<endl<<"Help: T1_Shots | T1_On_Target | T2_Shots | T2_On_Target:\n"; cin>>t1_shots[0]>>t1_shots[1]>>t2_shots[0]>>t2_shots[1];
	if(t1_possess==-2) temp1<<"UK"; else if(t1_possess<0){ temp1<<"Null"; error=1;} else if(t1_possess>=0) temp1<<t1_possess;
	if(t2_possess==-2) temp2<<"UK"; else if(t2_possess<0){ temp2<<"Null"; error=1;} else if(t2_possess>=0) temp2<<t2_possess;
	if(t1_shots[0]==-2) temp3<<"UK"; else if(t1_shots[0]<0){ temp3<<"Null"; error=1;} else if(t1_shots[0]>=0) temp3<<t1_shots[0];
	if(t1_shots[1]==-2) temp4<<"UK"; else if(t1_shots[1]<0){ temp4<<"Null"; error=1;} else if(t1_shots[1]>=0) temp4<<t1_shots[1];
	if(t2_shots[0]==-2) temp5<<"UK"; else if(t2_shots[0]<0){ temp5<<"Null"; error=1;} else if(t2_shots[0]>=0) temp5<<t2_shots[0];
	if(t2_shots[1]==-2) temp6<<"UK"; else if(t2_shots[1]<0){ temp6<<"Null"; error=1;} else if(t2_shots[1]>=0) temp6<<t2_shots[1];
	if(t1_shots[0]<t1_shots[1] || t2_shots[0]<t2_shots[1]) error=1;
	cout<<BOLDBLUE<<endl<<"Possession: "<<tm1.name<<": "<<temp1.str()<<" | "<<tm2.name<<": "<<temp2.str()<<endl;
	cout<<"Shots (On Target): "<<tm1.name<<": "<<temp3.str()<<"("<<temp4.str()<<")"<<" | "<<tm2.name<<": "<<temp5.str()<<"("<<temp6.str()<<")"<<endl<<RESET;
	if(t1_possess+t2_possess!=100){ cout<<endl<<BOLDYELLOW<<"Error In Possession\n"<<RESET<<endl; set_possess_shots(tm1,tm2); return;}
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. Try again.\n"<<RESET;
		set_possess_shots(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_possess_shots(tm1,tm2); return;}	
}
void match::set_fouls_corners(team tm1,team tm2){
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Fouls(Offsides) Respectively:\n"; cin>>t1_fouls[0]>>t1_fouls[1]>>t2_fouls[0]>>t2_fouls[1];
	cout<<"\nEnter Corners Respectively"<<endl; cin>>t1_corners>>t2_corners;
	if(t1_fouls[0]==-2) temp1<<"UK"; else if(t1_fouls[0]<0){ temp1<<"Null"; error=1;} else if(t1_fouls[0]>=0) temp1<<t1_fouls[0];
	if(t1_fouls[1]==-2) temp2<<"UK"; else if(t1_fouls[1]<0){ temp2<<"Null"; error=1;} else if(t1_fouls[1]>=0) temp2<<t1_fouls[1];
	if(t2_fouls[0]==-2) temp3<<"UK"; else if(t2_fouls[0]<0){ temp3<<"Null"; error=1;} else if(t2_fouls[0]>=0) temp3<<t2_fouls[0];
	if(t2_fouls[1]==-2) temp4<<"UK"; else if(t2_fouls[1]<0){ temp4<<"Null"; error=1;} else if(t2_fouls[1]>=0) temp4<<t2_fouls[1];
	if(t1_corners==-2) temp5<<"UK"; else if(t1_corners<0){ temp5<<"Null"; error=1;} else if(t1_corners>=0) temp5<<t1_corners;
	if(t2_corners==-2) temp6<<"UK"; else if(t2_corners<0){ temp6<<"Null"; error=1;} else if(t2_corners>=0) temp6<<t2_corners;
	cout<<endl<<BOLDBLUE<<"Fouls (Offsides): "<<tm1.name<<": "<<temp1.str()<<"("<<temp2.str()<<")"<<" | "<<tm2.name<<": "<<temp3.str()<<"("<<temp4.str()<<")"<<endl;
	cout<<"Corners: "<<tm1.name<<": "<<temp5.str()<<" | "<<tm2.name<<": "<<temp6.str()<<endl<<RESET;
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. Try again.\n"<<RESET;
		set_fouls_corners(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_fouls_corners(tm1,tm2); return;}	
}
void match::set_fk_passc_cross(team tm1,team tm2){
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Freekicks Respectively:\n"; cin>>t1_fk>>t2_fk;
	cout<<"\nEnter Passess Completed Respectively:"<<endl; cin>>t1_pass_c>>t2_pass_c;
	cout<<"\nEnter Crossess Respectively:"<<endl; cin>>t1_cross>>t2_cross;
	if(t1_fk==-2) temp1<<"UK"; else if(t1_fk<0){ temp1<<"Null"; error=1;} else if(t1_fk>=0) temp1<<t1_fk;
	if(t2_fk==-2) temp2<<"UK"; else if(t2_fk<0){ temp2<<"Null"; error=1;} else if(t2_fk>=0) temp2<<t2_fk;
	if(t1_pass_c==-2) temp3<<"UK"; else if(t1_pass_c<0){ temp3<<"Null"; error=1;} else if(t1_pass_c>=0) temp3<<t1_pass_c;
	if(t2_pass_c==-2) temp4<<"UK"; else if(t2_pass_c<0){ temp4<<"Null"; error=1;} else if(t2_pass_c>=0) temp4<<t2_pass_c;
	if(t1_cross==-2) temp5<<"UK"; else if(t1_cross<0){ temp5<<"Null"; error=1;} else if(t1_cross>=0) temp5<<t1_cross;
	if(t2_cross==-2) temp6<<"UK"; else if(t2_cross<0){ temp6<<"Null"; error=1;} else if(t2_cross>=0) temp6<<t2_cross;
	cout<<BOLDBLUE<<endl<<"Freekicks: "<<tm1.name<<": "<<temp1.str()<<" | "<<tm2.name<<": "<<temp2.str()<<endl;
	cout<<"Passess Completed: "<<tm1.name<<": "<<temp3.str()<<"% | "<<tm2.name<<": "<<temp4.str()<<"%"<<endl;
	cout<<"Crossess: "<<tm1.name<<": "<<temp5.str()<<" | "<<tm2.name<<": "<<temp6.str()<<endl<<RESET;
	if(t1_pass_c>100 || t2_pass_c>100){ cout<<BOLDYELLOW<<"Error In Passes Completed\n"<<endl<<RESET; set_fk_passc_cross(tm1,tm2); return;}
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. Try again.\n"<<RESET;
		set_fk_passc_cross(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_fk_passc_cross(tm1,tm2); return;}	
}
void match::set_ic_tackle_save(team tm1,team tm2){
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Interceptions Respectively:\n"; cin>>t1_interc>>t2_interc;
	cout<<"\nEnter Tackles Respectively:"<<endl; cin>>t1_tackles>>t2_tackles;
	cout<<"\nEnter Saves Respectively:"<<endl; cin>>t1_saves>>t2_saves;
	if(t1_interc==-2) temp1<<"UK"; else if(t1_interc<0){ temp1<<"Null"; error=1;} else if(t1_interc>=0) temp1<<t1_interc;
	if(t2_interc==-2) temp2<<"UK"; else if(t2_interc<0){ temp2<<"Null"; error=1;} else if(t2_interc>=0) temp2<<t2_interc;
	if(t1_tackles==-2) temp3<<"UK"; else if(t1_tackles<0){ temp3<<"Null"; error=1;} else if(t1_tackles>=0) temp3<<t1_tackles;
	if(t2_tackles==-2) temp4<<"UK"; else if(t2_tackles<0){ temp4<<"Null"; error=1;} else if(t2_tackles>=0) temp4<<t2_tackles;
	if(t1_saves==-2) temp5<<"UK"; else if(t1_saves<0){ temp5<<"Null"; error=1;} else if(t1_saves>=0) temp5<<t1_saves;
	if(t2_saves==-2) temp6<<"UK"; else if(t2_saves<0){ temp6<<"Null"; error=1;} else if(t2_saves>=0) temp6<<t2_saves;
	cout<<BOLDBLUE<<endl<<"Interceptions: "<<tm1.name<<": "<<temp1.str()<<" | "<<tm2.name<<": "<<temp2.str()<<endl;
	cout<<"Tackles: "<<tm1.name<<": "<<temp3.str()<<" | "<<tm2.name<<": "<<temp4.str()<<endl;
	cout<<"Saves: "<<tm1.name<<": "<<temp5.str()<<" | "<<tm2.name<<": "<<temp6.str()<<endl<<RESET;
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. Try again.\n"<<RESET;
		set_ic_tackle_save(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_ic_tackle_save(tm1,tm2); return;}		
}
void match::set_tm1_first_lineup(team tm){
	int choice,tp,j,error;
	for(tp=0; tm.pr[tp].sendexist(); tp++);
	cout<<"\nID haye 11 Bazikonae tarkibe aslie "<<tm.name<<" ra vared konid\n";
	for(int i=0; 11>i; i++) cin>>t1_prs[i];
	tm1players:
	error=0;
	for (int i=0; 10>i; i++){
		if(t1_prs[i]!=-2) for(int j=i+1; 11>j; j++) if(t1_prs[i]==t1_prs[j]) error=1;
	}
	cout<<endl<<BOLDBLUE;
	for(int i=0; 11>i; i++){
		cout<<i+1<<": ";
		if(t1_prs[i]==-2) cout<<"UK";
		else if(easycheck(t1_prs[i],1,tp)==0){ cout<<"Null"; error=1;}
		else if(easycheck(t1_prs[i],1,tp)==1) cout<<tm.pr[t1_prs[i]-1].name;
		cout<<endl;
	}
	cout<<endl<<RESET;
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){
		cout<<"Shomare Bazikon?: ";
		do cin>>temp; while(checkchoice(temp,1,11)==0);
		j=checkchoice(temp,1,11);
		cout<<"Enter ID: ";
		cin>>t1_prs[j-1];
		goto tm1players;
	}
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. ID ha ra az ebteda vared konid.\n"<<RESET;
		set_tm1_first_lineup(tm);
		return;
	}
}
void match::set_tm2_first_lineup(team tm){
	int choice,tp,j,error;
	for(tp=0; tm.pr[tp].sendexist(); tp++);
	cout<<"\nID haye 11 Bazikonae tarkibe aslie "<<tm.name<<" ra vared konid\n";
	for(int i=0; 11>i; i++) cin>>t2_prs[i];
	tm2players:
	error=0;
	for (int i=0; 10>i; i++){
		if(t2_prs[i]!=-2) for(int j=i+1; 11>j; j++) if(t2_prs[i]==t2_prs[j]) error=1;
	}
	cout<<endl<<BOLDBLUE;
	for(int i=0; 11>i; i++){
		cout<<i+1<<": ";
		if(t2_prs[i]==-2) cout<<"UK";
		else if(easycheck(t2_prs[i],1,tp)==0){ cout<<"Null"; error=1;}
		else if(easycheck(t2_prs[i],1,tp)==1) cout<<tm.pr[t2_prs[i]-1].name;
		cout<<endl;
	}
	cout<<endl<<RESET;
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){
		cout<<"Shomare Bazikon?: ";
		do cin>>temp; while(checkchoice(temp,1,11)==0);
		j=checkchoice(temp,1,11);
		cout<<"Enter ID: ";
		cin>>t2_prs[j-1];
		goto tm2players;
	}
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. ID ha ra az ebteda vared konid.\n"<<RESET;
		set_tm2_first_lineup(tm);
		return;
	}
}
void match::set_tedad_taviz(team tm1,team tm2){
	int choice;
	temp1.str("");
	temp2.str("");
	cout<<"\nTedad taviz haye do tim ra be tartib vared konid:\n";
	cin>>t1_tt>>t2_tt;
	if(t1_tt==-2) temp1<<"UK"; else if(easycheck(t1_tt,0,3)==0) temp1<<"Null"; else if(easycheck(t1_tt,0,3)==1) temp1<<t1_tt;
	if(t2_tt==-2) temp2<<"UK"; else if(easycheck(t2_tt,0,3)==0) temp2<<"Null"; else if(easycheck(t2_tt,0,3)==1) temp2<<t2_tt;
	cout<<endl<<BOLDBLUE<<"Tedade Taviz ha: "<<tm1.name<<": "<<temp1.str()<<" | "<<tm2.name<<": "<<temp2.str()<<endl<<RESET;
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_tedad_taviz(tm1,tm2); return;}
	if((easycheck(t1_tt,0,3)==0 && t1_tt!=-2) || (easycheck(t2_tt,0,3)==0 && t2_tt!=-2)){
		cout<<BOLDYELLOW<<endl<<"Error Dar Tedade Taviz Ha. Try Again.\n"<<RESET;
		set_tedad_taviz(tm1,tm2);
		return;
	}
}
void match::set_tvz_lineup(team tm1,team tm2){
	int choice,j,tp1,tp2,error;
	while(1){
		if(t1_tt==-2){
			for(int i=0; 3>i; i++) t1_tvz[i]=-2;
			break;
		}
		else if(t1_tt==0){
			for(int i=0; 3>i; i++) t1_tvz[i]=-1;
			break;
		}
		for(int i=0; 3-t1_tt>i; i++) t1_tvz[2-i]=-1;
		tm1_tvz_prs_inp:
		for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
		cout<<"\nBazikonane taviziye "<<tm1.name<<":\n";
		cout<<t1_tt<<" ID be tartib vared konid:\n";
		for(int i=0; t1_tt>i; i++) cin>>t1_tvz[i];
		tm1_tvz_prs:
		error=0;
		for (int i=0; 3>i; i++){
			if(t1_tvz[i]!=-2 && t1_tvz[i]!=-1){
				for(int j=0; 11>j; j++) if(t1_tvz[i]==t1_prs[j]) error=1;
				for(int j=i+1; 3>j; j++) if(t1_tvz[i]==t1_tvz[j]) error=1;
			}
		}
		cout<<endl<<BOLDBLUE;
		for(int i=0; t1_tt>i; i++){
			cout<<i+1<<": ";
			if(t1_tvz[i]==-2) cout<<"UK";
			else if(easycheck(t1_tvz[i],1,tp1)==0){ cout<<"Null"; error=1;}
			else if(easycheck(t1_tvz[i],1,tp1)==1) cout<<tm1.pr[t1_tvz[i]-1].name;
			cout<<endl;
		}
		cout<<endl<<RESET;
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			cout<<"Shomare Bazikon?: ";
			do cin>>temp; while(checkchoice(temp,1,3)==0);
			j=checkchoice(temp,1,3);
			cout<<"Enter ID: ";
			cin>>t1_tvz[j-1];
			goto tm1_tvz_prs;
		}
		if(error==1){
			cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. ID ha ra az ebteda vared konid.\n"<<RESET;
			goto tm1_tvz_prs_inp;
		}
		break;
	}
	while(2){
		if(t2_tt==-2){
			for(int i=1; 3>i; i++) t2_tvz[i]=-2;
			break;
		}
		else if(t2_tt==0){
			for(int i=1; 3>i; i++) t2_tvz[i]=-1;
			break;
		}
		for(int i=0; 3-t2_tt>i; i++) t2_tvz[2-i]=-1;
		tm2_tvz_prs_inp:
		for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
		cout<<"\nBazikonane taviziye "<<tm2.name<<":\n";
		cout<<t2_tt<<" ID be tartib vared konid:\n";
		for(int i=0; t2_tt>i; i++) cin>>t2_tvz[i];
		tm2_tvz_prs:
		error=0;
		for (int i=0; 3>i; i++){
			if(t2_tvz[i]!=-2 && t2_tvz[i]!=-1){
				for(int j=0; 11>j; j++) if(t2_tvz[i]==t2_prs[j]) error=1;
				for(int j=i+1; 3>j; j++) if(t2_tvz[i]==t2_tvz[j]) error=1;
			}
		}
		cout<<endl<<BOLDBLUE;
		for(int i=0; t2_tt>i; i++){
			cout<<i+1<<": ";
			if(t2_tvz[i]==-2) cout<<"UK";
			else if(easycheck(t2_tvz[i],1,tp2)==0){ cout<<"Null"; error=1;}
			else if(easycheck(t2_tvz[i],1,tp2)==1) cout<<tm2.pr[t2_tvz[i]-1].name;
			cout<<endl;
		}
		cout<<endl<<RESET;
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			cout<<"Shomare Bazikon?: ";
			do cin>>temp; while(checkchoice(temp,1,11)==0);
			j=checkchoice(temp,1,11);
			cout<<"Enter ID: ";
			cin>>t2_tvz[j-1];
			goto tm2_tvz_prs;
		}
		if(error==1){
			cout<<endl<<BOLDYELLOW<<"Error Dar Vared kardane Etelaat. ID ha ra az ebteda vared konid.\n"<<RESET;
			goto tm2_tvz_prs_inp;
		}
		break;
	}
}
int exist_players(int input,int first[],int tvz[]){
	for(int i=0; 11>i; i++) if(first[i]==-2 || first[i]==input) return 1;
	for(int i=0; 3>i; i++) if(tvz[i]==-2 || tvz[i]==input) return 1;
	return 0;
}
void match::set_goals_scorers(team tm1,team tm2){
	int choice, j, tp1, tp2, error,bar,inpg1,inpg2;
	int warning_hm[30];
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	while(1){
		if(t1_goals==-2 || t2_goals==-2){
			for(int i=0; 30>i; i++) for(int k=0; 5>k; k++) goals[i][k]=-2;
			break;
		}
		tg=t1_goals+t2_goals;
		if(tg==0){
			for(int i=0; 30>i; i++) for(int k=0; 5>k; k++) goals[i][k]=-1;
			break;
		}
		inpgoals:
		cout<<"\nEnter "<<tg<<" Goals:\n";
		cout<<"Help: Team-Half-Scorer Player ID-Assister Player ID-Minute\n";
		cout<<"Without Assist ID=-1;\n\n";
		for(int i=0; tg>i; i++){
			cout<<endl<<i+1<<": ";
			bar=0;
			do{
				bar++;
				error=0;
				warning_hm[i]=0;
				if(bar>1) cout<<endl<<BOLDYELLOW<<"Error dar vared kardane goal. Try Again.\n\n"<<RESET;
				cin>>goals[i][0]>>goals[i][1]>>goals[i][2]>>goals[i][3]>>goals[i][4];
				/*if(goals[i][0]==-2){
					goals[i][1]=-2; goals[i][2]=-2; goals[i][3]=-2; goals[i][4]=-2;
					break;
				}*/
				if(easycheck(goals[i][0],1,2)==0) error=1;
				if(easycheck(goals[i][1],1,2)==0 && goals[i][1]!=-2) error=1;
				if(error==0){
					if(goals[i][0]==1){ if(easycheck(goals[i][2],1,tp1)==0 && goals[i][2]!=-2) error=1; else if(exist_players(goals[i][2],t1_prs,t1_tvz)==0) error=1;}
					else if(goals[i][0]==2){ if(easycheck(goals[i][2],1,tp2)==0 && goals[i][2]!=-2) error=1; else if(exist_players(goals[i][2],t2_prs,t2_tvz)==0) error=1;}
				}
				if(error==0){
					if(goals[i][0]==1){ if(easycheck(goals[i][3],1,tp1)==0 && goals[i][3]!=-2 && goals[i][3]!=-1) error=1; else if(exist_players(goals[i][3],t1_prs,t1_tvz)==0) error=1;}
					else if(goals[i][0]==2){ if(easycheck(goals[i][3],1,tp2)==0 && goals[i][3]!=-2 && goals[i][3]!=-1) error=1; else if(exist_players(goals[i][3],t2_prs,t2_tvz)==0) error=1;}
					if(goals[i][3]==goals[i][2]) error=1;
				}
				if(goals[i][4]<0 || goals[i][4]>105) error=1;
				if(goals[i][1]==2 && goals[i][4]<45) error=1;
				if(goals[i][1]==1 && goals[i][4]>60) error=1;
				if(goals[i][1]==1 && goals[i][4]>45) warning_hm[i]=1;
			} while	(error==1);
			temp1.str("");
			temp2.str("");
			temp3.str("");
			temp4.str("");
			temp5.str("");
			temp6.str("");
			cout<<"Goal "<<i+1<<": ";
			if(goals[i][0]==1) temp1<<tm1.name; else if(goals[i][0]==2) temp1<<tm2.name;
			if(goals[i][1]==1) temp2<<"First Half"; else if(goals[i][1]==2) temp2<<"Second Half"; else if(goals[i][0]==-2) temp2<<"UK";
			if(goals[i][2]==-2) temp3<<"UK";
			else if(goals[i][0]==1) temp3<<tm1.pr[goals[i][2]-1].name;
			else if(goals[i][0]==2) temp3<<tm2.pr[goals[i][2]-1].name;
			if(goals[i][3]==-1) temp4<<"WA"; 
			else if(goals[i][3]==-2) temp4<<"UK";
			else if(goals[i][0]==1) temp4<<tm1.pr[goals[i][3]-1].name;
			else if(goals[i][0]==2) temp4<<tm2.pr[goals[i][3]-1].name;
			if(goals[i][4]==-2) temp5<<"UK"; else temp5<<goals[i][4];
			if(warning_hm[i]==1) temp6<<BOLDYELLOW<<"Warning: H&M"<<RESET;
			cout<<temp1.str()<<" | "<<temp2.str()<<" | "<<temp3.str()<<" | "<<temp4.str()<<" | "<<temp5.str();
			if(warning_hm[i]==1) cout<<" | "<<temp6.str();
			cout<<endl;
		}
		chapgoals:
		cout<<endl<<BOLDBLUE<<"All Goals: \n";
		for(int i=0; tg>i; i++){
			temp1.str("");
			temp2.str("");
			temp3.str("");
			temp4.str("");
			temp5.str("");
			temp6.str("");
			cout<<"Goal "<<i+1<<": ";
			if(goals[i][0]==1) temp1<<tm1.name; else if(goals[i][0]==2) temp1<<tm2.name;
			if(goals[i][1]==1) temp2<<"First Half"; else if(goals[i][1]==2) temp2<<"Second Half"; else if(goals[i][0]==-2) temp2<<"UK";
			if(goals[i][2]==-2) temp3<<"UK";
			else if(goals[i][0]==1) temp3<<tm1.pr[goals[i][2]-1].name;
			else if(goals[i][0]==2) temp3<<tm2.pr[goals[i][2]-1].name;
			if(goals[i][3]==-1) temp4<<"WA"; 
			else if(goals[i][3]==-2) temp4<<"UK";
			else if(goals[i][0]==1) temp4<<tm1.pr[goals[i][3]-1].name;
			else if(goals[i][0]==2) temp4<<tm2.pr[goals[i][3]-1].name;
			if(goals[i][4]==-2) temp5<<"UK"; else temp5<<goals[i][4];
			if(warning_hm[i]==1) temp6<<BOLDYELLOW<<"Warning: H&M"<<RESET;	
			cout<<temp1.str()<<" | "<<temp2.str()<<" | "<<temp3.str()<<" | "<<temp4.str()<<" | "<<temp5.str();
			if(warning_hm[i]==1) cout<<" | "<<temp6.str();
			cout<<endl;
		}
		cout<<RESET<<endl;
		inpg1=0; inpg2=0;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1) inpg1++; else if(goals[i][0]==2) inpg2++;
		}
		if(t1_goals != inpg1 || t2_goals != inpg2) cout<<BOLDYELLOW<<endl<<"Error dar Tedade goal haye har team!!!\n"<<RESET;
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			cout<<"Shomare Goal?: ";
			do cin>>temp; while(checkchoice(temp,1,tg)==0);
			j=checkchoice(temp,1,tg);
			j--;
			cout<<"Enter The Goal: ";
			bar=0;
			do{
				bar++;
				error=0;
				warning_hm[j]=0;
				if(bar>1) cout<<endl<<BOLDYELLOW<<"Error dar vared kardane goal. Try Again.\n\n"<<RESET;
				cin>>goals[j][0]>>goals[j][1]>>goals[j][2]>>goals[j][3]>>goals[j][4];
				if(easycheck(goals[j][0],1,2)==0) error=1;
				if(easycheck(goals[j][1],1,2)==0 && goals[j][1]!=-2) error=1;
				if(error==0){
					if(goals[j][0]==1){ if(easycheck(goals[j][2],1,tp1)==0 && goals[j][2]!=-2) error=1; else if(exist_players(goals[j][2],t1_prs,t1_tvz)==0) error=1;}
					else if(goals[j][0]==2){ if(easycheck(goals[j][2],1,tp2)==0 && goals[j][2]!=-2) error=1; else if(exist_players(goals[j][2],t2_prs,t2_tvz)==0) error=1;}
				}
				if(error==0){
					if(goals[j][0]==1){ if(easycheck(goals[j][3],1,tp1)==0 && goals[j][3]!=-2 && goals[j][3]!=-1) error=1; else if(exist_players(goals[j][3],t1_prs,t1_tvz)==0) error=1;}
					else if(goals[j][0]==2){ if(easycheck(goals[j][3],1,tp2)==0 && goals[j][3]!=-2 && goals[j][3]!=-1) error=1; else if(exist_players(goals[j][3],t2_prs,t2_tvz)==0) error=1;}
					if(goals[j][3]==goals[j][2]) error=1;
				}
				if(goals[j][4]<0 || goals[j][4]>105) error=1;
				if(goals[j][1]==2 && goals[j][4]<45) error=1;
				if(goals[j][1]==1 && goals[j][4]>60) error=1;
				if(goals[j][1]==1 && goals[j][4]>45) warning_hm[j]=1;
			} while	(error==1);
			goto chapgoals;
		}
		if(t1_goals != inpg1 || t2_goals != inpg2){
			cout<<endl<<BOLDYELLOW<<"Error dar Tedade goal haye har team!!!\nLotfan az ebteda goal ha ra vared konid\n"<<RESET;
			goto inpgoals;
		}	
		for(int i=0; 30-tg>i; i++) for(int k=0; 5>k; k++) goals[29-i][k]=-1;
		break;
	}
}
void match::set_tcards(team tm1,team tm2){
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	cout<<"\nEnter Respectively Number of Team1 Yellow Cards | Team1 Red Cards | Team2 Yellow Cards | Team2 Red Cards\n";
	cin>>t1_tc[0]>>t1_tc[1]>>t2_tc[0]>>t2_tc[1];
	if((t1_tc[0]>11 || t1_tc[0]<0) && t1_tc[0]!=-2){ temp1<<"Null"; error=1;} else if(t1_tc[0]==-2) temp1<<"UK"; else temp1<<t1_tc[0];
	if((t1_tc[1]>11 || t1_tc[1]<0) && t1_tc[1]!=-2){ temp2<<"Null"; error=1;} else if(t1_tc[1]==-2) temp2<<"UK"; else temp2<<t1_tc[1];
	if((t2_tc[0]>11 || t2_tc[0]<0) && t2_tc[0]!=-2){ temp3<<"Null"; error=1;} else if(t2_tc[0]==-2) temp3<<"UK"; else temp3<<t2_tc[0];
	if((t2_tc[1]>11 || t2_tc[1]<0) && t2_tc[1]!=-2){ temp4<<"Null"; error=1;} else if(t2_tc[1]==-2) temp4<<"UK"; else temp4<<t2_tc[1];
	cout<<endl<<BOLDBLUE<<tm1.name<<": Yellow cards: "<<temp1.str()<<" | Red cards: "<<temp2.str()<<endl;
	cout<<tm2.name<<": Yellow cards: "<<temp3.str()<<" | Red cards: "<<temp4.str()<<endl<<RESET;
	if(error==1){
		cout<<endl<<BOLDYELLOW<<"Error!!! Adade vared shode Na motabarand. Try again.\n"<<RESET;
		set_tcards(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_tcards(tm1,tm2); return;}
	if(t1_tc[0]!=-2 && t1_tc[1]!=-2) t1_tc[2]=t1_tc[0]+t1_tc[1]; else t1_tc[2]=-2;
	if(t2_tc[0]!=-2 && t2_tc[1]!=-2) t2_tc[2]=t2_tc[0]+t2_tc[1]; else t2_tc[2]=-2;
	if(t1_tc[2]!=-2 && t2_tc[2]!=-2) tcards=t1_tc[2]+t2_tc[2]; else tcards=-2;
}
void match::set_cards(team tm1,team tm2){
	int choice,tp1,tp2,inptc1[2],inptc2[2],error,bar,j;
	int warning_hm[28];
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	while(1){
		if(t1_tc[0]==-2 || t1_tc[1]==-2 || t2_tc[0]==-2 || t2_tc[1]==-2){
			for(int i=0; 28>i; i++) for(int k=0; 5>k; k++) cards[i][k]=-2;
			break;
		}
		if(tcards==0){
			for(int i=0; 28>i; i++) for(int k=0; 5>k; k++) cards[i][k]=-1;
			break;
		}
		inpcards:
		cout<<"\nEnter "<<tcards<<" Cards:\n";
		cout<<"Help: Team-Half-Color-Player ID-Minute\n\n";
		for(int i=0; tcards>i; i++){
			cout<<endl<<i+1<<": ";
			bar=0;		
			do{
				bar++;
				error=0;
				warning_hm[i]=0;
				if(bar>1) cout<<endl<<BOLDYELLOW<<"Error dar vared kardane cart. Try Again.\n\n"<<RESET;
				cin>>cards[i][0]>>cards[i][1]>>cards[i][2]>>cards[i][3]>>cards[i][4];
				if(easycheck(cards[i][0],1,2)==0) error=1;
				if(easycheck(cards[i][1],1,2)==0 && cards[i][1]!=-2) error=1;
				if(easycheck(cards[i][2],1,2)==0) error=1;
				if(error==0){
					if(cards[i][0]==1){ if(easycheck(cards[i][3],1,tp1)==0 && cards[i][3] != -2) error=1; else if(exist_players(cards[i][3],t1_prs,t1_tvz)==0) error=1;}
					else if(cards[i][0]==2){ if(easycheck(cards[i][3],1,tp2)==0 && cards[i][3] != -2) error=1; else if(exist_players(cards[i][3],t2_prs,t2_tvz)==0) error=1;}
				}
				if(cards[i][4]<0 || cards[i][4]>105) error=1;
				if(cards[i][1]==2 && cards[i][4]<45) error=1;
				if(cards[i][1]==1 && cards[i][4]>60) error=1;
				if(cards[i][1]==1 && cards[i][4]>45) warning_hm[i]=1;
			} while(error==1);
			temp1.str("");
			temp2.str("");
			temp3.str("");
			temp4.str("");
			temp5.str("");
			temp6.str("");
			cout<<"Card "<<i+1<<": ";
			if(cards[i][0]==1) temp1<<tm1.name; else if(cards[i][0]==2) temp1<<tm2.name;
			if(cards[i][1]==1) temp2<<"First Half"; else if(cards[i][1]==2) temp2<<"Second Half"; else if(cards[i][0]==-2) temp2<<"UK";
			if(cards[i][2]==1) temp3<<"Yellow"; else if(cards[i][2]==2) temp3<<"Red";
			if(cards[i][3]==-2) temp4<<"UK";
			else if(cards[i][0]==1) temp4<<tm1.pr[cards[i][3]-1].name;
			else if(cards[i][0]==2) temp4<<tm2.pr[cards[i][3]-1].name;
			if(cards[i][4]==-2) temp5<<"UK"; else temp5<<cards[i][4];
			if(warning_hm[i]==1) temp6<<BOLDYELLOW<<"Warning: H&M"<<RESET;
			cout<<temp1.str()<<" | "<<temp2.str()<<" | "<<temp3.str()<<" | "<<temp4.str()<<" | "<<temp5.str();
			if(warning_hm[i]==1) cout<<" | "<<temp6.str();
			cout<<endl;
		}
		chapcards:
		cout<<endl<<BOLDBLUE<<"All Cards: \n";	
		for(int i=0; tcards>i; i++){
			temp1.str("");
			temp2.str("");
			temp3.str("");
			temp4.str("");
			temp5.str("");
			temp6.str("");
			cout<<"Card "<<i+1<<": ";
			if(cards[i][0]==1) temp1<<tm1.name; else if(cards[i][0]==2) temp1<<tm2.name;
			if(cards[i][1]==1) temp2<<"First Half"; else if(cards[i][1]==2) temp2<<"Second Half"; else if(cards[i][0]==-2) temp2<<"UK";
			if(cards[i][2]==1) temp3<<"Yellow"; else if(cards[i][2]==2) temp3<<"Red";
			if(cards[i][3]==-2) temp4<<"UK";
			else if(cards[i][0]==1) temp4<<tm1.pr[cards[i][3]-1].name;
			else if(cards[i][0]==2) temp4<<tm2.pr[cards[i][3]-1].name;
			if(cards[i][4]==-2) temp5<<"UK"; else temp5<<cards[i][4];
			if(warning_hm[i]==1) temp6<<BOLDYELLOW<<"Warning: H&M"<<BOLDBLUE;
			cout<<temp1.str()<<" | "<<temp2.str()<<" | "<<temp3.str()<<" | "<<temp4.str()<<" | "<<temp5.str();
			if(warning_hm[i]==1) cout<<" | "<<temp6.str();
			cout<<endl;
		}
		cout<<RESET<<endl;
		inptc1[0]=0; inptc1[1]=0; inptc2[0]=0; inptc2[1]=0;
		for(int i=0; tcards>i; i++){
			if(cards[i][2]==1){ if(cards[i][0]==1) inptc1[0]++; else if(cards[i][0]==2) inptc2[0]++;}
			if(cards[i][2]==2){ if(cards[i][0]==1) inptc1[1]++; else if(cards[i][0]==2) inptc2[1]++;}
		}		
		if(t1_tc[0] != inptc1[0] || t1_tc[1] != inptc1[1] || t2_tc[0] != inptc2[0] || t2_tc[1] != inptc2[1]) cout<<BOLDYELLOW<<endl<<"Error dar Tedade cart haye har team!!!\n"<<RESET;
		for(int i=0,err=0; tcards-1>i && err==0; i++){
			for(int j=i+1; tcards>j && err==0; j++){
				if(cards[i][0]==cards[j][0] && cards[i][2]==cards[j][2] && cards[i][3]==cards[j][3]){ cout<<endl<<BOLDYELLOW<<"Error Dar Tedade Cart haye Yek Bazikon\n"<<RESET; err=1;}
			}
		}
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			cout<<"Shomare Cart?: ";
			do cin>>temp; while(checkchoice(temp,1,tcards)==0);
			j=checkchoice(temp,1,tcards);
			j--;
			cout<<"Enter The card: ";
			bar=0;
			do{	
				bar++;
				error=0;
				warning_hm[j]=0;
				if(bar>1) cout<<endl<<BOLDYELLOW<<"Error dar vared kardane cart. Try Again.\n\n"<<RESET;
				cin>>cards[j][0]>>cards[j][1]>>cards[j][2]>>cards[j][3]>>cards[j][4];
				if(easycheck(cards[j][0],1,2)==0) error=1;
				if(easycheck(cards[j][1],1,2)==0 && cards[j][1]!=-2) error=1;
				if(easycheck(cards[j][2],1,2)==0) error=1;
				if(error==0){
					if(cards[j][0]==1){ if(easycheck(cards[j][3],1,tp1)==0 && cards[j][3] != -2) error=1; else if(exist_players(cards[j][3],t1_prs,t1_tvz)==0) error=1;}
					else if(cards[j][0]==2){ if(easycheck(cards[j][3],1,tp2)==0 && cards[j][3] != -2) error=1; else if(exist_players(cards[j][3],t2_prs,t2_tvz)==0) error=1;}
				}
				if(cards[j][4]<0 || cards[j][4]>105) error=1;
				if(cards[j][1]==2 && cards[j][4]<45) error=1;
				if(cards[j][1]==1 && cards[j][4]>60) error=1;
				if(cards[j][1]==1 && cards[j][4]>45) warning_hm[j]=1;
			} while(error==1);
			goto chapcards;
		}
		if(t1_tc[0] != inptc1[0] || t1_tc[1] != inptc1[1] || t2_tc[0] != inptc2[0] || t2_tc[1] != inptc2[1]){
			cout<<endl<<BOLDYELLOW<<"Error dar Tedade cart haye har team!!!\nLotfan az ebteda cart ha ra vared konid\n"<<RESET;
			goto inpcards;
		}
		for(int i=0,err=0; tcards-1>i && err==0; i++){
			for(int j=i+1; tcards>j && err==0; j++){
				if(cards[i][0]==cards[j][0] && cards[i][2]==cards[j][2] && cards[i][3]==cards[j][3]){
					cout<<endl<<BOLDYELLOW<<"Error Dar Tedade Cart haye Yek Bazikon\nLotfan az ebteda cart ha ra vared konid\n"<<RESET;
					err=1;
					goto inpcards;
				}
			}
		}						
		for(int i=0; 28-tcards>i; i++) for(int k=0; 5>k; k++) cards[27-i][k]=-1;
		break;
	}
}
void match::set_mom(team tm1,team tm2){
	int choice,bar,error=0,tp1,tp2;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	cout<<"\nID behtarin bazikone zamin(2 Points) va sepas bazikone shayeste(1 Points) ra vared konid\n";
	cout<<"Help: MOTM - Team - Second Player - Team\n";
	bar=0;
	do{
		error=0;
		bar++;
		if(bar>1) cout<<BOLDYELLOW<<"\nVorudi ha Na motabarand. Try Again\n"<<RESET;
		cin>>mom[0][0]>>mom[0][1]>>mom[1][0]>>mom[1][1];
		if(easycheck(mom[0][1],1,2)==0 || easycheck(mom[1][1],1,2)==0) error=1;
		if(error==0){
			if(mom[0][1]==1){ if(easycheck(mom[0][0],1,tp1)==0 || exist_players(mom[0][0],t1_prs,t1_tvz)==0) error=1;}
			else if(mom[0][1]==2){ if(easycheck(mom[0][0],1,tp2)==0 || exist_players(mom[0][0],t2_prs,t2_tvz)==0) error=1;}
		}
		if(error==0){
			if(mom[1][1]==1){ if(easycheck(mom[1][0],1,tp1)==0 || exist_players(mom[1][0],t1_prs,t1_tvz)==0) error=1;}
			else if(mom[1][1]==2){ if(easycheck(mom[1][0],1,tp2)==0 || exist_players(mom[1][0],t2_prs,t2_tvz)==0) error=1;}
		}
		if(mom[0][1]==mom[1][1] && mom[0][0]==mom[1][0]) error=1;
	} while(error==1);
	cout<<endl<<BOLDBLUE<<"Man of the match: ";
	if(mom[0][1]==1) cout<<tm1.pr[mom[0][0]-1].name<<" from "<<tm1.name<<endl;
	else if(mom[0][1]==2) cout<<tm2.pr[mom[0][0]-1].name<<" from "<<tm2.name<<endl;
	cout<<"Second Player of the match: ";
	if(mom[1][1]==1) cout<<tm1.pr[mom[1][0]-1].name<<" from "<<tm1.name<<endl<<RESET;
	else if(mom[1][1]==2) cout<<tm2.pr[mom[1][0]-1].name<<" from "<<tm2.name<<endl<<RESET;
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
	if(choice==2){ set_mom(tm1,tm2); return;}
}	
void match::set_conf(team tm1,team tm2){
	int choice,bar=0;
	tm1_conf:
	while(1){
		cout<<endl<<tm1.name<<": Aya Conferans midahid? (1:Yes | 2:No): ";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			t1_conf[0]=0;
			break;
		}
		cin>>t1_conf;
		break;
	}
	while(1){
		bar++;
		tm2_conf:
		if(bar>1) break;
		cout<<endl<<tm2.name<<": Aya Conferans midahid? (1:Yes | 2:No): ";
		do cin>>temp; while(checkchoice(temp,1,2)==0);
		choice=checkchoice(temp,1,2);
		if(choice==2){
			t2_conf[0]=0;
			break;
		}
		cin>>t2_conf;
		break;
	}
	cout<<endl<<BOLDBLUE<<tm1.name<<": ";
	print_passage(t1_conf);
	cout<<endl;
	cout<<endl<<tm2.name<<": ";
	print_passage(t2_conf);
	cout<<endl<<RESET;
	cout<<endl<<"Do you want to edit? (1:No | 2:"<<tm1.name<<" | 3:"<<tm2.name<<")\n";
	do cin>>temp; while(checkchoice(temp,1,3)==0);
	choice=checkchoice(temp,1,3);
	if(choice==2) goto tm1_conf;
	else if(choice==3) goto tm2_conf;
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
void match::update_after_game(team &tm1,team &tm2){
	if(exist==1){ tm1.app_p(); tm2.app_p();}
	if(res==1){ tm1.win_p(); tm2.lose_p();}
	else if(res==2){ tm2.win_p(); tm1.lose_p();}
	else if(res==3){ tm1.draw_p(); tm2.draw_p();}
	for(int i=0; 11>i; i++) if(t1_prs[i]!=-2) tm1.pr[t1_prs[i]-1].app_p();
	for(int i=0; 11>i; i++) if(t2_prs[i]!=-2) tm2.pr[t2_prs[i]-1].app_p();
	for(int i=0; 3>i; i++) if(t1_tvz[i]!=-2) tm1.pr[t1_tvz[i]-1].app_p();
	for(int i=0; 3>i; i++) if(t2_tvz[i]!=-2) tm2.pr[t2_tvz[i]-1].app_p();
	if(mom[0][1]==1){ for(int i=0; 2>i; i++) if(mom[0][0]!=-2) tm1.pr[mom[0][0]-1].mom_p();}
	else if(mom[0][1]==2){ for(int i=0; 2>i; i++) if(mom[0][0]!=-2) tm2.pr[mom[0][0]-1].mom_p();}
	if(mom[1][1]==1){ if(mom[1][0]!=-2) tm1.pr[mom[1][0]-1].mom_p();}
	else if(mom[1][1]==2){ if(mom[1][0]!=-2) tm2.pr[mom[1][0]-1].mom_p();}
	if(t1_goals!=-2){ for(int i=0; t1_goals>i; i++) tm1.goal_p();}
	if(t2_goals!=-2){ for(int i=0; t2_goals>i; i++) tm2.goal_p();}
	if(t1_possess!=-2) tm1.possess_p(t1_possess);
	if(t2_possess!=-2) tm2.possess_p(t2_possess);
	if(t1_shots[0]!=-2) tm1.shots0_p(t1_shots[0]);
	if(t1_shots[1]!=-2) tm1.shots1_p(t1_shots[1]);
	if(t2_shots[0]!=-2) tm2.shots0_p(t2_shots[0]);
	if(t2_shots[1]!=-2) tm2.shots1_p(t2_shots[1]);
	if(t1_fouls[0]!=-2) tm1.fouls0_p(t1_fouls[0]);
	if(t1_fouls[1]!=-2) tm1.fouls1_p(t1_fouls[1]);
	if(t2_fouls[0]!=-2) tm2.fouls0_p(t2_fouls[0]);
	if(t2_fouls[1]!=-2) tm2.fouls1_p(t2_fouls[1]);
	if(t1_corners!=-2) tm1.corners_p(t1_corners);
	if(t2_corners!=-2) tm2.corners_p(t2_corners);
	if(t1_tackles!=-2) tm1.tackles_p(t1_tackles);
	if(t2_tackles!=-2) tm2.tackles_p(t2_tackles);
	if(t1_saves!=-2) tm1.saves_p(t1_saves);
	if(t2_saves!=-2) tm2.saves_p(t2_saves);
	if(t1_fk!=-2) tm1.fk_p(t1_fk);
	if(t2_fk!=-2) tm2.fk_p(t2_fk);
	if(t1_interc!=-2) tm1.interc_p(t1_interc);
	if(t2_interc!=-2) tm2.interc_p(t2_interc);
	if(t1_pass_c!=-2) tm1.pass_c_p(t1_pass_c);
	if(t2_pass_c!=-2) tm2.pass_c_p(t2_pass_c);
	if(t1_cross!=-2) tm1.cross_p(t1_cross);
	if(t2_cross!=-2) tm2.cross_p(t2_cross);
	if(t1_tc[0]!=-2) for(int i=0; t1_tc[0]>i; i++) tm1.yc_p();
	if(t1_tc[1]!=-2) for(int i=0; t1_tc[1]>i; i++) tm1.rc_p();
	if(t2_tc[0]!=-2) for(int i=0; t2_tc[0]>i; i++) tm2.yc_p();
	if(t2_tc[1]!=-2) for(int i=0; t2_tc[1]>i; i++) tm2.rc_p();
	for(int i=0; tcards>i; i++){
		if(cards[i][0]==1){ if(cards[i][3]!=-2){ if(cards[i][2]==1) tm1.pr[cards[i][3]-1].yc_p();}}
		if(cards[i][0]==1){ if(cards[i][3]!=-2){ if(cards[i][2]==2) tm1.pr[cards[i][3]-1].rc_p();}}
		if(cards[i][0]==2){ if(cards[i][3]!=-2){ if(cards[i][2]==1) tm2.pr[cards[i][3]-1].yc_p();}}
		if(cards[i][0]==2){ if(cards[i][3]!=-2){ if(cards[i][2]==2) tm2.pr[cards[i][3]-1].rc_p();}}
	}
	for(int i=0; tg>i; i++){
		if(goals[i][0]==1){
			if(goals[i][2]!=-2) tm1.pr[goals[i][2]-1].goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm1.pr[goals[i][3]-1].ass_p();
		}
		else if(goals[i][0]==2){
			if(goals[i][2]!=-2) tm2.pr[goals[i][2]-1].goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm2.pr[goals[i][3]-1].ass_p();
		}
	}
	cout<<BOLDGREEN<<"Teams and Players Details Updated.\n"<<RESET<<endl;
}
void details_repair(match *m,team &tm1,team &tm2){
	int tp1,tp2,choice;
	char temp[10];
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	cout<<endl<<"Do you want to Repair details? (1:Yes | 2:No)\n";
	do cin>>temp; while(checkchoice(temp,1,2)==0);
	choice=checkchoice(temp,1,2);
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
void compare(team tm1,team tm2,double m1,double m2,int s,int h=0){
	for(int i=0; s>i; i++) cout<<" ";
	if(h==0){
		if(m1>m2) cout<<BOLDGREEN<<tm1.name<<": "<<setprecision(2)<<m1<<RESET<<" | "<<tm2.name<<": "<<setprecision(2)<<m2<<endl;
		else if(m1<m2) cout<<tm1.name<<": "<<setprecision(2)<<m1<<" | "<<BOLDGREEN<<tm2.name<<": "<<setprecision(2)<<m2<<RESET<<endl;
		else if(m1==m2) cout<<tm1.name<<": "<<setprecision(2)<<m1<<" | "<<tm2.name<<": "<<setprecision(2)<<m2<<endl;
	}
	else{
		if(m1<m2) cout<<BOLDGREEN<<tm1.name<<": "<<setprecision(2)<<m1<<RESET<<" | "<<tm2.name<<": "<<setprecision(2)<<m2<<endl;
		else if(m1>m2) cout<<tm1.name<<": "<<setprecision(2)<<m1<<" | "<<BOLDGREEN<<tm2.name<<": "<<setprecision(2)<<m2<<RESET<<endl;
		else if(m1==m2) cout<<tm1.name<<": "<<setprecision(2)<<m1<<" | "<<tm2.name<<": "<<setprecision(2)<<m2<<endl;
	}
}
void compare_teams(team tm1,team tm2){
	cout<<endl<<tm1.name<<" Against "<<tm2.name<<endl;
	cout<<"Apps: "<<tm1.apps<<endl<<endl;
	cout<<"Wins Percent: "; compare(tm1,tm2,(double)tm1.wins/tm1.apps*100,(double)tm2.wins/tm2.apps*100,23);
	cout<<"Goals Per Game: "; compare(tm1,tm2,(double)tm1.goals/tm1.apps,(double)tm2.goals/tm2.apps,21);
	cout<<"Yellow Cards Per Game: "; compare(tm1,tm2,(double)tm1.yc/tm1.apps,(double)tm2.yc/tm2.apps,14,1);
	cout<<"Red Cards Per Game: "; compare(tm1,tm2,(double)tm1.rc/tm1.apps,(double)tm2.rc/tm2.apps,17,1);
	cout<<"Possession Per Game: "; compare(tm1,tm2,(double)tm1.possess/tm1.apps,(double)tm2.possess/tm2.apps,16);
	cout<<"Shots(On Target) Per Game: ";
	if(tm1.shots[0]+tm1.shots[1]>tm2.shots[0]+tm2.shots[1]) cout<<"          "<<BOLDGREEN<<tm1.name<<": "<<(double)tm1.shots[0]/tm1.apps<<"("<<(double)tm1.shots[1]/tm1.apps<<")"<<RESET<<" | "<<tm2.name<<": "<<(double)tm2.shots[0]/tm2.apps<<"("<<(double)tm2.shots[1]/tm2.apps<<")"<<endl;
	else if(tm1.shots[0]+tm1.shots[1]<tm2.shots[0]+tm2.shots[1]) cout<<"          "<<tm1.name<<": "<<(double)tm1.shots[0]/tm1.apps<<"("<<(double)tm1.shots[1]/tm1.apps<<")"<<" | "<<BOLDGREEN<<tm2.name<<": "<<(double)tm2.shots[0]/tm2.apps<<"("<<(double)tm2.shots[1]/tm2.apps<<")"<<RESET<<endl;
	else if(tm1.shots[0]+tm1.shots[1]==tm2.shots[0]+tm2.shots[1]) cout<<"          "<<tm1.name<<": "<<(double)tm1.shots[0]/tm1.apps<<"("<<(double)tm1.shots[1]/tm1.apps<<")"<<" | "<<tm2.name<<": "<<(double)tm2.shots[0]/tm2.apps<<"("<<(double)tm2.shots[1]/tm2.apps<<")"<<endl;
	cout<<"Fouls(Offside) Per Game: ";
	if(tm1.fouls[0]<tm2.fouls[0]) cout<<"            "<<BOLDGREEN<<tm1.name<<": "<<(double)tm1.fouls[0]/tm1.apps<<"("<<(double)tm1.fouls[1]/tm1.apps<<")"<<RESET<<" | "<<tm2.name<<": "<<(double)tm2.fouls[0]/tm2.apps<<"("<<(double)tm2.fouls[1]/tm2.apps<<")"<<endl;
	if(tm1.fouls[0]>tm2.fouls[0]) cout<<"            "<<tm1.name<<": "<<(double)tm1.fouls[0]/tm1.apps<<"("<<(double)tm1.fouls[1]/tm1.apps<<")"<<" | "<<BOLDGREEN<<tm2.name<<": "<<(double)tm2.fouls[0]/tm2.apps<<"("<<(double)tm2.fouls[1]/tm2.apps<<")"<<RESET<<endl;
	if(tm1.fouls[0]==tm2.fouls[0]) cout<<"            "<<tm1.name<<": "<<(double)tm1.fouls[0]/tm1.apps<<"("<<(double)tm1.fouls[1]/tm1.apps<<")"<<" | "<<tm2.name<<": "<<(double)tm2.fouls[0]/tm2.apps<<"("<<(double)tm2.fouls[1]/tm2.apps<<")"<<endl;
	cout<<"Corners Per Game: "; compare(tm1,tm2,(double)tm1.corners/tm1.apps,(double)tm2.corners/tm2.apps,19);
	cout<<"Free Kicks Per Game: "; compare(tm1,tm2,(double)tm1.fk/tm1.apps,(double)tm2.fk/tm2.apps,16);
	cout<<"Pass Completed Per Game: "; compare(tm1,tm2,(double)tm1.pass_c/tm1.apps,(double)tm2.pass_c/tm2.apps,12); 
	cout<<"Crosses Per Game: "; compare(tm1,tm2,(double)tm1.cross/tm1.apps,(double)tm2.cross/tm2.apps,19);
	cout<<"Interception Per Game: "; compare(tm1,tm2,(double)tm1.interc/tm1.apps,(double)tm2.interc/tm2.apps,14);
	cout<<"Tackles Per Game: "; compare(tm1,tm2,(double)tm1.tackles/tm1.apps,(double)tm2.tackles/tm2.apps,19);
	cout<<"Saves Per Game: "; compare(tm1,tm2,(double)tm1.saves/tm1.apps,(double)tm2.saves/tm2.apps,21);
}
void moratab(int tmp[][3],int s,team tm1,team tm2){
	int tp1,tp2;
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	if(s==1){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendapps();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendapps();
	}
	if(s==2){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendgoals();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendgoals();
	}
	if(s==3){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendass();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendass();
	}
	if(s==4){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendmom();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendmom();
	}
	if(s==5){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendyc();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendyc();
	}
	if(s==6){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendrc();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendrc();
	}
	if(s==7){
		int i=0;
		for(int j=0; tp1>j; i++,j++) tmp[i][2]=tm1.pr[j].sendyc()+ 2* tm1.pr[j].sendrc();
		for(int j=0; tp2>j; i++,j++) tmp[i][2]=tm2.pr[j].sendyc()+ 2* tm2.pr[j].sendrc();
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
void subsume_players(team tm1,team tm2){
	int choice;
	char temp[10];
	while(1){
		cout<<BOLDRED<<"\nSubsumption Players:\n"<<RESET;;
		cout<<"1: Most Apps\n2: Top Scorers\n3: Top Assisters\n4: Most MOTM Points\n5: Most yellow cards\n6: Most red cards\n7: Most Violence\n8: Back to main\n\nEnter your choice\n";
		do cin>>temp; while(checkchoice(temp,1,8)==0);
		choice=checkchoice(temp,1,8);
		if(choice==8) break;
		else{
			int tmp[200][3],tp1,tp2,i;
			for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
			for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
			i=0;
			for(int j=0; tp1>j; i++,j++){
				tmp[i][0]=1;
				tmp[i][1]=j;
			}
			for(int j=0; tp2>j; i++,j++){
				tmp[i][0]=2;
				tmp[i][1]=j;
			}
			for(; 200>i; i++){ tmp[i][0]=0; tmp[i][1]=0; tmp[i][2]=-1;}
			switch(choice){
				case 1: cout<<endl<<BOLDRED<<"Most Apps:\n"<<RESET; moratab(tmp,1,tm1,tm2); break;
				case 2: cout<<endl<<BOLDRED<<"Top Scorers:\n"<<RESET; moratab(tmp,2,tm1,tm2); break;
				case 3: cout<<endl<<BOLDRED<<"Top Assisters:\n"<<RESET; moratab(tmp,3,tm1,tm2); break;
				case 4: cout<<endl<<BOLDRED<<"Most MOTM Points:\n"<<RESET; moratab(tmp,4,tm1,tm2); break;
				case 5: cout<<endl<<BOLDRED<<"Most Yellow Cards:\n"<<RESET; moratab(tmp,5,tm1,tm2); break;
				case 6: cout<<endl<<BOLDRED<<"Most Red Cards:\n"<<RESET; moratab(tmp,6,tm1,tm2); break;
				case 7: cout<<endl<<BOLDRED<<"Most Violence:\n"<<RESET; moratab(tmp,7,tm1,tm2); break;
			}
			for(int i=0; 200>i; i++){
				if(tmp[i][2]<1) break;
				cout<<i+1<<": ";
				if(tmp[i][0]==1) cout<<BOLDMAGENTA<<tm1.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]<<RESET;
				else if(tmp[i][0]==2) cout<<BOLDCYAN<<tm2.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]<<RESET;
				cout<<endl;
			}
		}
	}
}
void match::show(team tm1,team tm2){
	int s,t,c;
	stringstream ts1[14];
	stringstream ts2[14];
	stringstream gl[30];
	stringstream cs[28];
	stringstream cadr;
	if(t1_goals==-2) ts1[0]<<"UK"; else ts1[0]<<t1_goals;
	if(t2_goals==-2) ts2[0]<<"UK"; else ts2[0]<<t2_goals;
	if(t1_possess==-2) ts1[1]<<"UK"; else ts1[1]<<t1_possess<<"%";
	if(t2_possess==-2) ts2[1]<<"UK"; else ts2[1]<<t2_possess<<"%";
	if(t1_shots[0]!=-2 && t1_shots[1]!=-2) ts1[2]<<t1_shots[0]<<"("<<t1_shots[1]<<")";
	if(t2_shots[0]!=-2 && t2_shots[1]!=-2) ts2[2]<<t2_shots[0]<<"("<<t2_shots[1]<<")";
	if(t1_fouls[0]!=-2 && t1_fouls[1]!=-2) ts1[3]<<t1_fouls[0]<<"("<<t1_fouls[1]<<")";
	if(t2_fouls[0]!=-2 && t2_fouls[1]!=-2) ts2[3]<<t2_fouls[0]<<"("<<t2_fouls[1]<<")";
	if(t1_corners==-2) ts1[4]<<"UK"; else ts1[4]<<t1_corners;
	if(t2_corners==-2) ts2[4]<<"UK"; else ts2[4]<<t2_corners;
	if(t1_fk==-2) ts1[5]<<"UK"; else ts1[5]<<t1_fk;
	if(t2_fk==-2) ts2[5]<<"UK"; else ts2[5]<<t2_fk;
	if(t1_pass_c==-2) ts1[6]<<"UK"; else ts1[6]<<t1_pass_c<<"%";
	if(t2_pass_c==-2) ts2[6]<<"UK"; else ts2[6]<<t2_pass_c<<"%";
	if(t1_cross==-2) ts1[7]<<"UK"; else ts1[7]<<t1_cross;
	if(t2_cross==-2) ts2[7]<<"UK"; else ts2[7]<<t2_cross;
	if(t1_interc==-2) ts1[8]<<"UK"; else ts1[8]<<t1_interc;
	if(t2_interc==-2) ts2[8]<<"UK"; else ts2[8]<<t2_interc;
	if(t1_tackles==-2) ts1[9]<<"UK"; else ts1[9]<<t1_tackles;
	if(t2_tackles==-2) ts2[9]<<"UK"; else ts2[9]<<t2_tackles;
	if(t1_saves==-2) ts1[10]<<"UK"; else ts1[10]<<t1_saves;
	if(t2_saves==-2) ts2[10]<<"UK"; else ts2[10]<<t2_saves;
	if(t1_shots[0]==-2 || t1_shots[1]==-2){
		if(t1_shots[0]==-2 && t1_shots[1]==-2) ts1[2]<<"Uk"; else if(t1_shots[0]==-2) ts1[2]<<"Uk("<<t1_shots[1]<<")"; else ts1[2]<<t1_shots[0]<<"(UK)";
	}
	if(t2_shots[0]==-2 || t2_shots[1]==-2){
		if(t2_shots[0]==-2 && t2_shots[1]==-2) ts2[2]<<"Uk"; else if(t2_shots[0]==-2) ts2[2]<<"Uk("<<t2_shots[1]<<")"; else ts2[2]<<t2_shots[0]<<"(UK)";
	}
	if(t1_fouls[0]==-2 || t1_fouls[1]==-2){
		if(t1_fouls[0]==-2 && t1_fouls[1]==-2) ts1[2]<<"Uk"; else if(t1_fouls[0]==-2) ts1[2]<<"Uk("<<t1_fouls[1]<<")"; else ts1[2]<<t1_fouls[0]<<"(UK)";
	}
	if(t2_fouls[0]==-2 || t2_fouls[1]==-2){
		if(t2_fouls[0]==-2 && t2_fouls[1]==-2) ts2[2]<<"Uk"; else if(t2_fouls[0]==-2) ts2[2]<<"Uk("<<t2_fouls[1]<<")"; else ts2[2]<<t2_fouls[0]<<"(UK)";
	}
	temp1.str("");
	cout<<endl<<BOLDRED;
	temp1<<tm1.name<<" Against "<<tm2.name;
	space(26); cout<<temp1.str()<<RESET;
	temp1.str("");
	if(year!=-2){
		cout<<endl;
		temp1<<BOLDWHITE<<"Date: ";
		temp1<<year;
		if(month!=-2 && month>9) temp1<<"/"<<month; else if(month!=-2 && month<10)temp1<<"/"<<"0"<<month;
		if(month!=-2 && day!=-2 && day>9) temp1<<"/"<<day<<RESET<<endl; else if(day!=-2 && day<10)temp1<<"/"<<"0"<<day<<RESET<<endl;
		strwhere(temp1.str().c_str(),86); cout<<endl;
	}
	cout<<endl<<endl;
	cadr<<BOLDBLUE;
	t=12; c=48; s=15;
	space(s); cout<<cadr.str(); cadr_dash(c);
	space(s); cout<<"|"<<BOLDCYAN; strwhere(tm1.name,t,1); cout<<BOLDBLUE; strwhere("Stats",22,1); cout<<BOLDCYAN; strwhere(tm2.name,t,1); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[0].str().c_str(),t); strwhere("Goals Scored",22); strwhere(ts2[0].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[1].str().c_str(),t); strwhere("Possession",22); strwhere(ts2[1].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[2].str().c_str(),t); strwhere("Shots (On Target)",22); strwhere(ts2[2].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[3].str().c_str(),t); strwhere("Fouls (Offside)",22); strwhere(ts2[3].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[4].str().c_str(),t); strwhere("Corner Kicks",22); strwhere(ts2[4].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[5].str().c_str(),t); strwhere("Free Kicks",22); strwhere(ts2[5].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[6].str().c_str(),t); strwhere("Passes Completed (%)",22); strwhere(ts2[6].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[7].str().c_str(),t); strwhere("Crosses",22); strwhere(ts2[7].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[8].str().c_str(),t); strwhere("Interception",22); strwhere(ts2[8].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[9].str().c_str(),t); strwhere("Tackles",22); strwhere(ts2[9].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[10].str().c_str(),t); strwhere("Saves",22); strwhere(ts2[10].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	for(int i=0; 14>i; i++){
		ts1[i].str("");
		ts2[i].str("");
	}
	for(int i=0; 11>i; i++) if(t1_prs[i]==-2) ts1[i]<<"UK"; else ts1[i]<<tm1.pr[t1_prs[i]-1].name;
	for(int i=0; 11>i; i++) if(t2_prs[i]==-2) ts2[i]<<"UK"; else ts2[i]<<tm2.pr[t2_prs[i]-1].name;
	for(int i=11; 14>i; i++){
		if(t1_tt>i-11){ if(t1_tvz[i-11]==-2) ts1[i]<<"UK"; else ts1[i]<<tm1.pr[t1_tvz[i-11]-1].name;}
	}
	for(int i=11; 14>i; i++){
		if(t2_tt>i-11){ if(t2_tvz[i-11]==-2) ts2[i]<<"UK"; else ts2[i]<<tm2.pr[t2_tvz[i-11]-1].name;}
	}
	cout<<endl<<endl;
	cout<<BOLDBLUE; strwhere("Players",78,1); cout<<RESET<<endl;
	s=21;
	space(s); cout<<cadr.str()<<"------------------------------------"<<RESET<<endl;
	t=17;
	for(int i=0; 11>i; i++){
		space(s); cout<<cadr.str()<<"|"<<RESET; 
		if(mom[0][1]==1 && mom[0][0]==t1_prs[i] && t1_prs[i]!=-2) cout<<BOLDYELLOW;
		if(mom[1][1]==1 && mom[1][0]==t1_prs[i] && t1_prs[i]!=-2) cout<<BOLDGREEN;
		strwhere(ts1[i].str().c_str(),t,1); cout<<RESET;
		if(mom[0][1]==2 && mom[0][0]==t2_prs[i] && t2_prs[i]!=-2) cout<<BOLDYELLOW;
		if(mom[1][1]==2 && mom[1][0]==t2_prs[i] && t2_prs[i]!=-2) cout<<BOLDGREEN;
		strwhere(ts2[i].str().c_str(),t,1); cout<<RESET;
		cout<<cadr.str()<<"|"<<RESET<<endl; 
	}
	space(s); cout<<cadr.str()<<"------------------------------------"<<RESET<<endl;
	for(int i=11; 14>i; i++){
		space(s); cout<<cadr.str()<<"|"<<RESET; 
		if(mom[0][1]==1 && mom[0][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) cout<<BOLDYELLOW;
		if(mom[1][1]==1 && mom[1][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) cout<<BOLDGREEN;
		strwhere(ts1[i].str().c_str(),t,1); cout<<RESET;
		if(mom[0][1]==2 && mom[0][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) cout<<BOLDYELLOW;
		if(mom[1][1]==2 && mom[1][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) cout<<BOLDGREEN;
		strwhere(ts2[i].str().c_str(),t,1); cout<<RESET;
		cout<<cadr.str()<<"|"<<RESET<<endl;		
	}
	space(s); cout<<cadr.str()<<"------------------------------------"<<RESET<<endl;
	if(tg>0){
		for(int i=0; tg>i; i++){
			if(goals[i][4]==-2) gl[i]<<"UK | "; else gl[i]<<goals[i][4]<<" | ";
			if(goals[i][0]==1){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else gl[i]<<tm1.pr[goals[i][2]-1].name<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm1.pr[goals[i][3]-1].name<<")";
			}
			if(goals[i][0]==2){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else gl[i]<<tm2.pr[goals[i][2]-1].name<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm2.pr[goals[i][3]-1].name<<")";
			}
		}
		cout<<endl<<endl;
		cout<<BOLDBLUE; strwhere("Goals",78,1); cout<<RESET<<endl;
		space(17); cout<<cadr.str()<<"----------------------------------------------"<<RESET<<endl;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1){space(20); cout<<BOLDMAGENTA<<gl[i].str()<<RESET<<endl;}
			if(goals[i][0]==2){space(30); cout<<BOLDCYAN<<gl[i].str()<<RESET<<endl;}
		}
		space(17); cout<<cadr.str()<<"----------------------------------------------"<<RESET<<endl;
	}
	if(tcards>0){
		for(int i=0; tcards>i; i++){
			if(cards[i][4]==-2) cs[i]<<"UK | "; else cs[i]<<cards[i][4]<<" | ";
			if(cards[i][2]==1) cs[i]<<BOLDYELLOW<<"Yellow"<<RESET<<" | "; else if(cards[i][2]==2) cs[i]<<BOLDRED<<"Red"<<RESET<<" | ";
			if(cards[i][0]==1){
				if(cards[i][2]==-2) cs[i]<<BOLDMAGENTA<<"UK"; else cs[i]<<BOLDMAGENTA<<tm1.pr[cards[i][3]-1].name;
			}
			if(cards[i][0]==2){
				if(cards[i][2]==-2) cs[i]<<BOLDCYAN<<"UK"; else cs[i]<<BOLDCYAN<<tm2.pr[cards[i][3]-1].name;
			}
		}
		cout<<endl<<endl;
		cout<<BOLDBLUE; strwhere("Cards",78,1); cout<<RESET<<endl;
		space(17); cout<<cadr.str()<<"----------------------------------------------"<<RESET<<endl;
		for(int i=0; tcards>i; i++){
			if(cards[i][0]==1){space(20); cout<<BOLDMAGENTA<<cs[i].str()<<RESET<<endl;}
			if(cards[i][0]==2){space(30); cout<<BOLDCYAN<<cs[i].str()<<RESET<<endl;}
		}					
		space(17); cout<<cadr.str()<<"----------------------------------------------"<<RESET<<endl;
	}			
}
void show_game(match *g,team tm1,team tm2){
	char temp[10];
	int choice,tedad;
	for(tedad=0; g[tedad].sendexist()==1; tedad++);
	cout<<endl<<"Enter Number of Game: ";
	do cin>>temp; while(checkchoice(temp,1,tedad)==0);
	choice=checkchoice(temp,1,tedad);
	choice--;
	g[choice].show(tm1,tm2);
}

void showTableStats(teamGameStat teamOne,teamGameStat teamTwo,date gameDate,bool perGame, bool showCards, bool showSubs){
	int s,t,c;
	stringstream ts1[11];
	stringstream ts2[11];
	stringstream cadr;
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
	cout<<endl<<BOLDRED;
	temp1<<teamOne.name<<" Against "<<teamTwo.name;
	if(perGame==false){ space(26); cout<<temp1.str()<<RESET;}
	else{ space(28); cout<<temp1.str()<<RESET;}
	temp1.str("");
	if(gameDate.isEmpty==false && gameDate.year!=-2){
		cout<<endl;
		temp1<<BOLDWHITE<<"Date: ";
		temp1<<gameDate.year;
		if(gameDate.month!=-2 && gameDate.month>9) temp1<<"/"<<gameDate.month; else if(gameDate.month!=-2 && gameDate.month<10)temp1<<"/"<<"0"<<gameDate.month;
		if(gameDate.month!=-2 && gameDate.day!=-2 && gameDate.day>9) temp1<<"/"<<gameDate.day<<RESET<<endl; else if(gameDate.day!=-2 && gameDate.day<10)temp1<<"/"<<"0"<<gameDate.day<<RESET<<endl;
		strwhere(temp1.str().c_str(),86); cout<<endl;
	}
	cout<<endl<<endl;
	cadr<<BOLDBLUE;
	s=15;
	if(perGame==true){
		t=13; c=50;
	}
	else{
		t=12; c=48;
	}
	space(s); cout<<cadr.str(); cadr_dash(c);
	space(s); cout<<"|"<<BOLDCYAN; strwhere(teamOne.name,t,1); if(perGame==false){ cout<<BOLDBLUE; strwhere("Stats",22,1);} else{ cout<<BOLDBLUE; strwhere("Stats (Per Game)",22,1);}  cout<<BOLDCYAN; strwhere(teamTwo.name,t,1); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[0].str().c_str(),t); strwhere("Goals Scored",22); strwhere(ts2[0].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[1].str().c_str(),t); strwhere("Possession",22); strwhere(ts2[1].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[2].str().c_str(),t); strwhere("Shots (On Target)",22); strwhere(ts2[2].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[3].str().c_str(),t); strwhere("Fouls (Offside)",22); strwhere(ts2[3].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[4].str().c_str(),t); strwhere("Corner Kicks",22); strwhere(ts2[4].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[5].str().c_str(),t); strwhere("Free Kicks",22); strwhere(ts2[5].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[6].str().c_str(),t); strwhere("Passes Completed (%)",22); strwhere(ts2[6].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[7].str().c_str(),t); strwhere("Crosses",22); strwhere(ts2[7].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[8].str().c_str(),t); strwhere("Interception",22); strwhere(ts2[8].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[9].str().c_str(),t); strwhere("Tackles",22); strwhere(ts2[9].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[10].str().c_str(),t); strwhere("Saves",22); strwhere(ts2[10].str().c_str(),t); cout<<cadr.str()<<"|"<<endl; space(s); cadr_dash(c);
}
