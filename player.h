#ifndef PLAYER_H
#define PLAYER_H

#include "saheader.h"

class player{
	bool exist;
	char name[30];
	int id;
    int number;
    int overallRating;
	int post;
	int apps;
	int goals;
	int assists;
	int hatTricks;
	int mom;
	int rc;
	int yc;
	char temp[10];
	public:
	player(){
        overallRating=0;
        exist=0; apps=0; goals=0; assists=0;
        hatTricks=0;
        mom=0; rc=0; yc=0; id=0;
	}
        
    player(player* pr){
		exist=pr->sendexist();
		strcpy(name,pr->sendname());
		id=pr->getId();
		number=pr->getNumber();
        post=pr->getPost(); 
		
        overallRating=pr->overallRating;
		apps=pr->sendapps();
		goals=pr->sendgoals();
		assists=pr->sendass();
		hatTricks=pr->getHatTricks();
		mom=pr->sendmom();
		rc=pr->sendrc();
		yc=pr->sendyc(); 
	}
	
	void input(char *str,int n,int num,int idInput){
		if(easycheck(n,1,5)==0) throw -1;
		if(strcasecmp(str,"")==0) throw -1;
		strcpy(name,str);
		post=n;
        number=num;
        id=idInput;
        exist=1;
        overallRating=-2;
	}
        
	void edit(char *str,int n){
		if(easycheck(n,1,5)==0) throw -1;
		if(strcasecmp(str,"")==0) throw -1;
		strcpy(name,str);
		post=n;
        exist=1;
	}
        
    player clone(){
        return player(this);
    }
        
    void remove(){
        exist=0; name[0]=0; post=0;
        overallRating=0;
        apps=0; goals=0; assists=0;
        hatTricks=0;
        mom=0; rc=0; yc=0; id=0;
    }
	
	void zero(void){
        overallRating=-2;
        apps=0; goals=0; assists=0; mom=0; rc=0; yc=0;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<name<<endl;
		f1<<id<<endl;
        f1<<overallRating<<endl;
        f1<<number<<endl;
		f1<<post<<endl;
		f1<<apps<<endl;
		f1<<goals<<endl;
		f1<<assists<<endl;
		f1<<hatTricks<<endl;
		f1<<mom<<endl;
		f1<<rc<<endl;
		f1<<yc<<endl;
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1.ignore();
		f1.getline(name,30);
		f1>>id;
        f1>>overallRating;
        f1>>number;
		f1>>post;
		f1>>apps;
		f1>>goals;
		f1>>assists;
		f1>>hatTricks;
		f1>>mom;
		f1>>rc;
		f1>>yc;
		f1.ignore();
	}
        
    void setNumber(int n){
        number=n;
    }
	
	bool sendexist(void){ return exist;}
    int getOverallRating(){ return overallRating;}
	int sendgoals(void){ return goals;}
	int sendapps(void){ return apps;}
	int sendass(void){ return assists;}
	int sendmom(void){ return mom;}
	int sendrc(void){ return rc;}
	int sendyc(void){ return yc;}
    int getId(void){ return id;}
    int getNumber(){ return number;}
    int getPost(void){ return post;}
	int getHatTricks(){ return hatTricks;}
	char* sendname(void){ return name;}
	void change_id(int t){ id=t;}
	void app_p(void){ apps++;}
	void goal_p(void){ goals++;}
	void ass_p(void){ assists++;}
	void momPlus(){ mom+=2;}
    void secondMomPlus(){ mom++;}
	void rc_p(void){ rc++;}
	void yc_p(void){ yc++;}
	void hatTrikPlus(int p){
		if(p<1) throw -1;
		hatTricks+=p;
	}
	
    void setOverall(int ov){
        if(!ukEasycheck(ov,1,109)) throw -1; 
        overallRating=ov;
    }
    
    int dynamicGet(const char* index){
		if(strcasecmp(index,"number")==0) return number;
		else if (strcasecmp(index,"post")==0) return post;
		else if (strcasecmp(index,"overallRating")==0) return overallRating;
		else throw -1;
	}
        
    static void printPost(int post){
        if(post<1 || post>5) throw -1;
        switch(post){
            case 1: setColor("BOLDBLACK"); cout<<"GoalKeaper"; break;
            case 2: setColor("BOLDCYAN"); cout<<"Defender"; break;
            case 3: setColor("BOLDGREEN"); cout<<"Central Midfielder"; break;
            case 4: setColor("BOLDGREEN"); cout<<"Attacking Midfielder"; break;
            case 5: setColor("BOLDRED"); cout<<"Forward"; break;
        }
        setColor("RESET");
    }
        
	static void printOverallRating(int ov){
	    if(!ukEasycheck(ov,1,109)) throw -1;
	    if(ov==-2){
			cout<<"UK";
			return;
	    }
	    if(ov>74 && ov<80) setColor("GREEN");
	    else if(ov<85) setColor("YELLOW");
	    else if(ov<90) setColor("BOLDYELLOW");
	    else if(ov>=90) setColor("BOLDRED");
	    cout<<ov;
	    setColor("RESET");
	}
	
	static string getOverallString(double ov){
		stringstream temp;
		string ss;
	    if(ov==-2){
			ss="UK";
			return ss;
	    }
	    if(ov<75) temp<<"$$BLK"; 
	    else if(ov<80) temp<<"$0GRN";
	    else if(ov<85) temp<<"$0YEL";
	    else if(ov<90) temp<<"$$YEL";
	    else if(ov>=90) temp<<"$$RED";
		temp<<setprecision(3)<<ov;
		temp<<"$0RST";
		ss=temp.str();
		return ss;
	}
        
	void show(void){
        if(exist==1){
            cout<<endl <<"Name: " <<name <<endl;
            cout<<"Number: " <<number<<endl;
            cout<<"ID: " <<id<<endl;
            cout<<"Post: "; printPost(post); cout<<endl;
            cout<<"Overall Rating: "; cout<<"("; printOverallRating(overallRating); cout<<")"; cout<<endl;
            cout<<"Tedade Bazi: " <<apps <<endl;
            cout<<"Goals: " <<goals <<endl;
            cout<<"Assists: " <<assists <<endl;
            cout<<"Hat Tricks: " <<hatTricks <<endl;
            cout<<"Man Of The Match: " <<mom <<endl;
            cout<<"Yellow Card: " <<yc <<endl;
            cout<<"Red Card: " <<rc <<endl;
        }
        else if(exist==0) cout<< "This player does not exist !"<<endl;
	}
        
    void namePostShow(){
        if(number>0){
            setColor("BOLDMAGENTA");
            cout<<number;
            setColor("RESET");
            cout<<" | ";
        }
        setColor("BOLDBLUE");
        cout<<name;
        setColor("RESET");
        cout<<" | ";
        printPost(post);
		if(overallRating!=-2){
			cout<<" | ";
			printOverallRating(overallRating);
		}
    }
    
	friend class team;
	friend class match;
};

#endif	// PLAYER_H

