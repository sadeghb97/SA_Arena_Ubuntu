#ifndef MATCH_H
#define MATCH_H

#include "saheader.h"

class match{
    public:
	bool exist;
	int year;
	int month;
	int day;
	int res;      // 1:Team 1 | 2:Team 2 | 3: Draw
	int t1_prs[11];
	int t2_prs[11];
	int t1_pov[11];
	int t2_pov[11];
	int t1_tt;
	int t2_tt;
	int t1_tvz[3];
	int t2_tvz[3];
	int t1_tov[3];
	int t2_tov[3];
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
    int t1_left;
    int t1_center;
    int t1_right;
    int t2_left;
    int t2_center;
    int t2_right;        
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
        for(int i=0; 11>i; i++) t1_pov[i]=0;
        for(int i=0; 11>i; i++) t2_pov[i]=0;
        t1_tt=0; t2_tt=0;
        for(int i=0; 3>i; i++) t1_tvz[i]=0;
        for(int i=0; 3>i; i++) t2_tvz[i]=0;
        for(int i=0; 3>i; i++) t1_tov[i]=0;
        for(int i=0; 3>i; i++) t2_tov[i]=0;
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
        t1_left=0; t1_center=0; t1_right=0;
        t2_left=0; t2_center=0; t2_right=0;
        for(int i=0; 3>i; i++) t1_tc[i]=0;
        for(int i=0; 3>i; i++) t2_tc[i]=0;
        tg=0;
        for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=0;
        for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=0;
        t1_conf[0]=0; t2_conf[0]=0;
	}
        
	void set_goals(team,team,bool edit=false);
	void set_possess_shots(team,team,bool edit=false);
	void set_fouls_corners(team,team,bool edit=false);
	void set_fk_passc_cross(team,team,bool edit=false);
	void set_ic_tackle_save(team,team,bool edit=false);
	void setLineup(team,bool,bool edit=false);
	void set_goals_scorers(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_tcards(team,team,bool edit=false);
	void set_cards(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_mom(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_conf(team,team,bool edit=false);
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
		for(int i=0; 11>i; i++) t1_pov[i]=0;
		for(int i=0; 11>i; i++) t2_pov[i]=0;
		t1_tt=0; t2_tt=0;
		for(int i=0; 3>i; i++) t1_tvz[i]=0;
		for(int i=0; 3>i; i++) t2_tvz[i]=0;
		for(int i=0; 3>i; i++) t1_tov[i]=0;
		for(int i=0; 3>i; i++) t2_tov[i]=0;
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
		t1_left=0; t1_center=0; t1_right=0;
		t2_left=0; t2_center=0; t2_right=0;
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
		for(int i=0; 11>i; i++) f1<<t1_pov[i]<<endl;
		for(int i=0; 11>i; i++) f1<<t2_pov[i]<<endl;
		f1<<t1_tt<<endl;
		f1<<t2_tt<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tvz[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tvz[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tov[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tov[i]<<endl;
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
		f1<<t1_left<<endl;
		f1<<t1_center<<endl;
		f1<<t1_right<<endl;
		f1<<t2_left<<endl;
		f1<<t2_center<<endl;
		f1<<t2_right<<endl;
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
		for(int i=0; 11>i; i++) f1>>t1_pov[i];
		for(int i=0; 11>i; i++) f1>>t2_pov[i];
		f1>>t1_tt;
		f1>>t2_tt;
		for(int i=0; 3>i; i++) f1>>t1_tvz[i];
		for(int i=0; 3>i; i++) f1>>t2_tvz[i];
		for(int i=0; 3>i; i++) f1>>t1_tov[i];
		for(int i=0; 3>i; i++) f1>>t2_tov[i];
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
		f1>>t1_left;
		f1>>t1_center;
		f1>>t1_right;
		f1>>t2_left;
		f1>>t2_center;
		f1>>t2_right;
		for(int i=0; 3>i; i++) f1>>t1_tc[i];
		for(int i=0; 3>i; i++) f1>>t2_tc[i];
		f1>>tg;
		f1>>tcards;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) f1>>cards[i][j];
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) f1>>goals[i][j];
		f1.ignore();
		f1.getline(t1_conf,1200);
		f1.getline(t2_conf,1200);
	}
	
	void set_date(bool edit=false){
		int bar,error,choice;
		cout<<"\nEnter Date of Match (Year | Month | Day)\n";
		bar=0;
		do{
			error=0;
			bar++;
			if(bar>1){ cout<<endl; setColor("BOLDYELLOW"); cout<<"Adade vorudi Na motabarand. Try Again\n"; setColor("RESET"); cout<<endl;}
			if(!edit){
				cin>>year>>month>>day;
				cin.ignore();
			}
			edit=false;
			
			if(((year<1300 || year>1500) && year !=-2) || ((month<1 || month>12) && month!=-2) || ((day<1 || day>31) && day!=-2)){
				error=1;
			}
		} while (error==1);
		
		if(year==-2){ month=-2; day=-2;}
		if(month==-2) day=-2;
		cout<<endl; setColor("BOLDBLUE"); cout<<"Date Of Match: ";
		if(year!=-2) cout<<year<<"/"; else cout<<"UK"<<"/";
		
		if(month!=-2 && month>9) cout<<month<<"/";
		else if(month!=-2 && month<10)cout<<"0"<<month<<"/";
		else cout<<"UK"<<"/";
		
		if(day!=-2 && day>9){
			cout<<day;
			setColor("RESET");
			cout<<endl;
		} 
		else if(day!=-2 && day<10){
			cout<<"0"<<day;
			setColor("RESET");
			cout<<endl;
		} 
		else{
			cout<<"UK";
			setColor("RESET");
			cout<<endl;
		}
		
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		choice=inputChoice(1,2);
		if(choice==2) set_date();
	}
        
    void setAttackingAreas(team tm1,team tm2,bool edit=false){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
        int choice,error=0;
        
        start:
        temp1.str("");
        temp2.str("");
        temp3.str("");
        temp4.str("");
        temp5.str("");
        temp6.str("");
        if(edit){
            edit=false;
            goto finalaproval;
        }

        cout<<"\nEnter "<<tm1.getName()<<" Attacking Areas (Left,Center,Right): ";
        t1_left=nextInt();
        t1_center=nextInt();
        t1_right=nextInt();
        
        cout<<"\nEnter "<<tm2.getName()<<" Attacking Areas (Left,Center,Right): ";
        t2_left=nextInt();
        t2_center=nextInt();
        t2_right=nextInt();

        finalaproval:
        error=0;
        if(t1_left==-2) temp1<<"UK";
        else if(t1_left<0 || t1_left>(INT_MAX-2)) temp1<<"Null";
        else temp1<<t1_left<<"%";
        
        if(t1_center==-2) temp2<<"UK";
        else if(t1_center<0 || t1_center>(INT_MAX-2)) temp2<<"Null";
        else temp2<<t1_center<<"%";
        
        if(t1_right==-2) temp3<<"UK";
        else if(t1_right<0 || t1_right>(INT_MAX-2)) temp3<<"Null";
        else temp3<<t1_right<<"%";
        
        if(t2_left==-2) temp4<<"UK";
        else if(t2_left<0 || t2_left>(INT_MAX-2)) temp4<<"Null";
        else temp4<<t2_left<<"%";
        
        if(t2_center==-2) temp5<<"UK";
        else if(t2_center<0 || t2_center>(INT_MAX-2)) temp5<<"Null";
        else temp5<<t2_center<<"%";
        
        if(t2_right==-2) temp6<<"UK";
        else if(t2_right<0 || t2_right>(INT_MAX-2)) temp6<<"Null";
        else temp6<<t2_right<<"%";
        
        cout<<endl;
        setColor("BOLDBLUE");
        cout<<tm1.getName()<<" Attacking Areas: Left: "; ccsPrint(temp1);
		cout<<" | Center: "; ccsPrint(temp2);
		cout<<" | Right: "; ccsPrint(temp3); cout<<endl;

        cout<<tm2.getName()<<" Attacking Areas: Left: "; ccsPrint(temp4);
		cout<<" | Center: "; ccsPrint(temp5);
		cout<<" | Right: "; ccsPrint(temp6); cout<<endl;
        setColor("RESET");
        
        if(!ukEasycheck(t1_left,1,100) ||
			!ukEasycheck(t1_center,1,100) ||
			!ukEasycheck(t1_right,1,100) ||
			!ukEasycheck(t2_left,1,100) ||
			!ukEasycheck(t2_center,1,100) ||
			!ukEasycheck(t2_right,1,100)
        ){
            cout<<endl;
            typeError();
            cout<<"Invalid Values!\n";
            error=1;
        }
        
        else{
            if(t1_left!=-2 && t1_center!=-2 && t1_right!=-2 && (t1_left+t1_center+t1_right)!=100){
                cout<<endl;
                typeError();
                cout<<"The Sum Of "<<tm1.getName()<<" Attacking Areas Is Not 100\n";
                error=1;
            }
            if(t2_left!=-2 && t2_center!=-2 && t2_right!=-2 && (t2_left+t2_center+t2_right)!=100){
                if(!error) cout<<endl;
                typeError();
                cout<<"The Sum Of "<<tm2.getName()<<" Attacking Areas Is Not 100\n";
                error=1;
            }
        }
        
        if(error==1){
            cout<<endl;
            setColor("BOLDYELLOW");
            cout<<"Attacking Areas Entered by Mistake! Please Try Again.\n";
            setColor("RESET");
            goto start;
        }
            
        
        cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
        if(choice==2){ goto start;}	
    }
    
    void printOverallsPrs(team tm1,team tm2){
        const int scrLength=90;
        int t,c,s;
		stringstream ts1[14];
		stringstream ts2[14];
        stringstream cadr;

		for(int i=0; 14>i; i++){
			ts1[i].str("");
			ts2[i].str("");
		}

		for(int i=0; 11>i; i++){
            ts1[i]<<i+1<<": ";
            if(t1_prs[i]==-2) ts1[i]<<"UK";
            else{
                ts1[i]<<tm1.getPrFromNumber(t1_prs[i]).sendname();
				ts1[i]<<" ("<<player::getOverallString(t1_pov[i])<<")";
            }
        }

		for(int i=0; 11>i; i++){
            ts2[i]<<i+1<<": ";
            if(t2_prs[i]==-2) ts2[i]<<"UK";
            else{
                ts2[i]<<tm2.getPrFromNumber(t2_prs[i]).sendname();
                //if(t2_pov[i]>0) ts2[i]<<" ("<<t2_pov[i]<<")";
                //else ts2[i]<<" (UK)";
				ts2[i]<<" ("<<player::getOverallString(t2_pov[i])<<")";
            }
        }

		for(int i=11; 14>i; i++){
            if(t1_tt>i-11){
				ts1[i]<<i+1<<": ";
                if(t1_tvz[i-11]==-2){
                    ts1[i]<<"UK";
                }
                else{
                    ts1[i]<<tm1.getPrFromNumber(t1_tvz[i-11]).sendname();
                    //if(t1_tov[i-11]>0) ts1[i]<<" ("<<t1_tov[i-11]<<")";
                    //else ts1[i]<<" (UK)";
					ts1[i]<<" ("<<player::getOverallString(t1_tov[i-11])<<")";
                }
            }
		}

		for(int i=11; 14>i; i++){
            if(t2_tt>i-11){
				ts2[i]<<i+1<<": ";
                if(t2_tvz[i-11]==-2) ts2[i]<<"UK";
                else{
                    ts2[i]<<tm2.getPrFromNumber(t2_tvz[i-11]).sendname();
                    //if(t2_tov[i]>0) ts2[i-11]<<" ("<<t2_tov[i-11]<<")";
                    //else ts2[i]<<" (UK)";
					ts2[i]<<" ("<<player::getOverallString(t2_tov[i-11])<<")";
                }
            }
		}

		cout<<endl<<endl;

        cadr<<"$$BLU";
		setColor("BOLDBLUE"); beforeStrWhere("Players Overalls Ratings",scrLength); setColor("RESET");cout<<endl;
		s=21; t=23;
		c=2+(t*2);
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
		for(int i=0; 11>i; i++){
            space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
            strwhere(ts1[i],t,1);
            strwhere(ts2[i],t,1);
            ccsPrint(cadr); cout<<"|"; setColor("RESET"); cout<<endl; 
		}
		
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
		for(int i=11; 14>i; i++){
            space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
            strwhere(ts1[i],t,1);
            strwhere(ts2[i],t,1);
            ccsPrint(cadr); cout<<"|"; setColor("RESET");cout<<endl;		
		}
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
    }
    
    void setOverallPrs(team tm1,team tm2,bool edit=false){
		bool runFunc=false;
		for(int i=0; 11>i && !runFunc; i++){
			if(t1_prs[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 11>i && !runFunc; i++){
			if(t2_prs[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 3>i && !runFunc; i++){
			if(t1_tvz[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 3>i && !runFunc; i++){
			if(t2_tvz[i]>0){
				runFunc=true;
			}
		}

		if(!runFunc) return;
		if(edit){
			if(!runFunc){
				cout<<endl<<"There is no Known Player To Edit Overall Ratings";
				return;
			}
			edit=false;
			goto editing;
		}

        for(int i=0; 11>i; i++){
            if(t1_prs[i]>0){
                t1_pov[i]=tm1.getPrFromNumber(t1_prs[i]).getOverallRating();
            }
            else t1_pov[i]=-1;
        }

        for(int i=0; 11>i; i++){
            if(t2_prs[i]>0){
                t2_pov[i]=tm2.getPrFromNumber(t2_prs[i]).getOverallRating();
            }
            else t2_pov[i]=-1;
        }

        for(int i=0; 3>i; i++){
            if(t1_tvz[i]>0){
                t1_tov[i]=tm1.getPrFromNumber(t1_tvz[i]).getOverallRating();
            }
            else t1_tov[i]=-1;
        }

        for(int i=0; 3>i; i++){
            if(t2_tvz[i]>0){
                t2_tov[i]=tm2.getPrFromNumber(t2_tvz[i]).getOverallRating();
            }
            else t2_tov[i]=-1;
        }

        editing:
        printOverallsPrs(tm1,tm2);
        
		cout<<endl;
        typeRule();
        cout<<"For Edit Overall Rating Of a player: \n";
        cout<<"Enter Team Id | Player List Number | New Overall Rating\n";
        typeRule();
        cout<<"Enter 3 for End of Editing Overall Ratings\n";
        typeRule();
        cout<<"Unknown Overall Rating = -2\n";

        while(true){
            wh:
            int one,two,three;
            cout<<endl;
            cout<<"Enter Team Id or Three to Quit: ";
            one=nextInt();
            if(!easycheck(one,1,3)){
                cout<<endl;
                typeError();
                cout<<"First Input Most be 1 or 2 (Team Id) Or 3 for Quit\n";
                cout<<"Please Try Again.\n";
                goto wh;
            }
            
            if(one==3){
				if(sure()) break;
				else goto wh;
			}
			
            cout<<"Enter Player List Number: ";
            two=nextInt();
            if(one==1){
                if(!easycheck(two,1,11+t1_tt)){
                    cout<<endl;
                    typeError();
                    cout<<"Second Input Most Be Player List Number (1 to "<<11+t1_tt<<"!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
                }
                else if((two<=11 && t1_prs[two-1]<0) || (two>11 && t1_tvz[two-1-11]<0)){
                    cout<<endl;
                    typeError();
					cout<<"This List number's Player Is Unknown!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
				}
            }
            
            else if(one==2){
                if(!easycheck(two,1,11+t2_tt)){
                    cout<<endl;
                    typeError();
                    cout<<"Second Input Most Be Player List Number (1 to "<<11+t2_tt<<"!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
                }
                else if((two<=11 && t2_prs[two-1]<0) || (two>11 && t2_tvz[two-1-11]<0)){
                    cout<<endl;
                    typeError();
					cout<<"This List number's Player Is Unknown!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
				}
            }
            
            cout<<"Enter New Overall Rating: ";
            three=nextInt();
            if(!ukEasycheck(three,1,109)){
                cout<<endl;
                typeError();
                cout<<"Third Input Most Be New Overall Rating (1 to 109) or UK Number(-2)\n";
                cout<<"Please Try Again.\n";
                goto wh;
            }
            
            cout<<endl;
            setColor("BOLDBLUE");
            if(one==1){
                cout<<tm1.getName()<<" - ";
                if(two<=11){
                    cout<<tm1.getPrFromNumber(t1_prs[two-1]).sendname()<<": ";
                    if(t1_pov[two-1]==-2) cout<<"UK -> ";
                    else cout<<t1_pov[two-1]<<" -> ";
                    cout<<three<<endl;
                    t1_pov[two-1]=three;
                }
                else if(two>11){
                    cout<<tm1.getPrFromNumber(t1_tvz[two-1-11]).sendname()<<": ";
                    if(t1_tov[two-1-11]==-2) cout<<"UK -> ";
                    else cout<<t1_tov[two-1-11]<<" -> ";
                    cout<<three<<endl;
                    t1_tov[two-1-11]=three;
                }
            }
            else if(one==2){
                cout<<tm2.getName()<<" - ";
                if(two<=11){
                    cout<<tm2.getPrFromNumber(t2_prs[two-1]).sendname()<<": ";
                    if(t2_pov[two-1]==-2) cout<<"UK -> ";
                    else cout<<t2_pov[two-1]<<" -> ";
                    cout<<three<<endl;
                    t2_pov[two-1]=three;
                }
                else if(two>11){
                    cout<<tm2.getPrFromNumber(t2_tvz[two-1-11]).sendname()<<": ";
                    if(t2_tov[two-1-11]==-2) cout<<"UK -> ";
                    else cout<<t2_tov[two-1-11]<<" -> ";
                    cout<<three<<endl;
                    t2_tov[two-1-11]=three;
                }
            }
            setColor("RESET");
            cout<<endl;
            printOverallsPrs(tm1,tm2);
        }
    }
    
    double getTeamStrength(team tm){
		int sum=0;
		int *pov;
		int *tov;
		int tt;
		int num;
		
		if(tm.sendid()==1){
			pov=t1_pov;
			tov=t1_tov;
			tt=t1_tt;
		}
		else if(tm.sendid()==2){
			pov=t2_pov;
			tov=t2_tov;
			tt=t2_tt;	
		}
		num=11+tt;
		
		for(int i=0; 11>i; i++){
			if(pov[i]>0) sum+=pov[i];
			else return -1;
		}
		
		for(int i=0; tt>i; i++){
			if(tov[i]>0) sum+=tov[i];
			else return -1;
		}
		return (double)sum/num;
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
			if(scorerID!=-2 && scorerID!=-1){
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
		else{
			if(tm.existNumber(number)) checking=number;
			else return false;
		}
            
		if(tm.sendid()==1){
			for(int i=0; 11>i; i++){
				if(t1_prs[i]==checking || t1_prs[i]==-2) return true;
			}
			for(int i=0; 3>i; i++){
				if(t1_tvz[i]==checking || t1_tvz[i]==-2) return true;
			}
			return false;
		}
            
		else if(tm.sendid()==2){
			for(int i=0; 11>i; i++){
				if(t2_prs[i]==checking || t2_prs[i]==-2) return true;
			}
			for(int i=0; 3>i; i++){
				if(t2_tvz[i]==checking || t2_tvz[i]==-2) return true;
			}
			return false;
		}
		throw -1;
	}
        
	bool enterCard(int i,team tm1,team tm2,inputProfile& inpSettings,bool edit=false){
		int temp[5];
		int choice;
		bool error=true;
		bool first=true;
            
		while(error){
			error=false;
			if(edit){
				edit=false;
				temp[0]=cards[i][0];
				temp[1]=cards[i][2];
				temp[2]=cards[i][3];
				if(cards[i][4]==-2) temp[3]=-2;    
				else if(cards[i][1]==1){
					if(cards[i][4]>=45){
						temp[3]=45;
						temp[4]=cards[i][4]-45;
					}
					else{
						temp[3]=cards[i][4];
					}
				}
                        
				else if(cards[i][1]==2){
					if(cards[i][4]>=90){
						temp[3]=90;
						temp[4]=cards[i][4]-90;
					}
					else{
						temp[3]=cards[i][4];
					}
				}
				goto finderror;
			}
                
			if(!first){
				mistake:
				cout<<"\nYou Entered The Card By Mistake!\n";
				setColor("BOLDRED");
				cout<<"\nNext Work?\n";
				setColor("RESET");
				cout<<"1: Try Again\n2: Edit Game Input Settings\n3: Go to Number of Goals Session\n";
				cout<<"4: Go to Line Up Session\n";
				cout<<"\nEnter Your Choice: ";
				choice =inputChoice(1,4);
				if(choice==2){
					inpSettings.settings();
					goto mistake;
				}
                    
				else if(choice==3){
					set_tcards(tm1,tm2);
					return false;
				}
				else if(choice==4){
					setColor("BOLDRED");
					cout<<"\nWorks:\n";
					setColor("RESET");
					cout<<"1: Enter Complete Teams Line Ups\n";
					cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
					cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
					cout<<"4: Cancel And Try Again to Entering Goal\n";
					cout<<"\nEnter Your Choice: ";
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
			
			if(!first) cout<<"Enter The Card: ";
			first=false;
			
			temp[0]=nextInt();
			temp[1]=nextInt();
			temp[2]=nextInt();
			if(inpSettings.getCardsTimes()) temp[3]=nextInt(); else temp[3]=-2;
			if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
			finderror:
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
				if(temp[2]>INT_MAX-2) printError("Player Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[2])) || (temp[0]==2 && !tm2.existNumber(temp[2]))){
					printError("Player: There is No Player With This Number!\n");
					error=true;
				}
				
				else if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
					printError("Player: This Player Not entered This Game!\n");
					error=true;
				}
			}
			
			if(!ukEasycheck(temp[3],1,90)){
				printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
				error=true;
			}
			if((temp[3]==45 || temp[3]==90) && !ukEasycheck(temp[4],0,15)){
				printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
				error=true;
			}
                
		}
		cards[i][0]=temp[0];
		if(temp[3]==-2) cards[i][1]=-2;
		else if(temp[3]<=45) cards[i][1]=1;
		else cards[i][1]=2;
		cards[i][2]=temp[1];
		cards[i][3]=temp[2];
		cards[i][4]=temp[3];
		if(cards[i][4]==45 || cards[i][4]==90) cards[i][4]+=temp[4];
		return true;
	}
        
        
	bool cardErrorAfterEdit(int i,team tm1,team tm2){
		if(!easycheck(cards[i][0],1,2)){
			return true;
		}
            
		if(!easycheck(cards[i][1],1,2)){
			return true;
		}
            
		if(!easycheck(cards[i][2],1,2)){
			return true;
		}
		if(cards[i][3]!=-2){
			if((cards[i][0]==1 && !prCanEnter(cards[i][3],tm1)) || (cards[i][0]==2 && !prCanEnter(cards[i][3],tm2))){
				return true;
			}
		}
		if(!ukEasycheck(cards[i][4],1,105)){
			return true;
		}
		return false;
	}
        
	void printCard(int i,team tm1,team tm2,inputProfile inpSettings){
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
		
		if(cards[i][0]==1) temp1<<tm1.name;
		else if(cards[i][0]==2) temp1<<tm2.name;
		
		if(cards[i][1]==1) temp2<<"First Half";
		else if(cards[i][1]==2) temp2<<"Second Half";
		else if(cards[i][0]==-2) temp2<<"UK";
		
		if(cards[i][2]==1) temp3<<"Yellow";
		else if(cards[i][2]==2) temp3<<"Red";
		
		if(cards[i][3]==-2) temp4<<"UK";
		else if(cards[i][0]==1) temp4<<tm1.getPrFromNumber(cards[i][3]).sendname();
		else if(cards[i][0]==2) temp4<<tm2.getPrFromNumber(cards[i][3]).sendname();
		
		if(cards[i][4]==-2) temp5<<"UK"; else temp5<<cards[i][4];
		ccsPrint(temp1); 
		
		if(inpSettings.getCardsTimes()){
			cout<<" | ";
			ccsPrint(temp2);
		}
		cout<<" | "; ccsPrint(temp3);
		cout<<" | "; ccsPrint(temp4);
		if(inpSettings.getCardsTimes()){ 
			cout<<" | ";
			ccsPrint(temp5);
		}
		cout<<endl;
	}
        
	bool enterGoal(int i,team tm1,team tm2,inputProfile& inpSettings,bool edit=false){
		int temp[5];
		int choice;
		bool error=true;
		bool first=true;
            
		while(error){
			error=false;
			if(edit){
				first=false;
				edit=false;
				temp[0]=goals[i][0];
				temp[1]=goals[i][2];
				temp[2]=goals[i][3];
				if(goals[i][4]==-2) temp[3]=-2;
				else if(goals[i][1]==1){
					if(goals[i][4]>=45){
						temp[3]=45;
						temp[4]=goals[i][4]-45;
					}
					else{
						temp[3]=goals[i][4];
					}
				}
                        
				else if(goals[i][1]==2){
					if(goals[i][4]>=90){
						temp[3]=90;
						temp[4]=goals[i][4]-90;
					}
					else{
						temp[3]=goals[i][4];
					}
				}
				goto finderror;
			}
                
			if(!first){
				mistake:
				cout<<"\nYou Entered The Goal By Mistake!\n";
				setColor("BOLDRED");
				cout<<"\nNext Work?\n";
				setColor("RESET");
				cout<<"1: Try Again\n2: Edit Game Input Settings\n3: Go to Number of Goals Session\n";
				cout<<"4: Go to Line Up Session\n";
				cout<<"\nEnter Your Choice: ";
				choice =inputChoice(1,4);
				if(choice==2){
					inpSettings.settings();
					goto mistake;
				}
                    
				else if(choice==3){
					set_goals(tm1,tm2);
					return false;
				}
				else if(choice==4){
					setColor("BOLDRED");
					cout<<"\nWorks:\n";
					setColor("RESET");
					cout<<"1: Enter Complete Teams Line Ups\n";
					cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
					cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
					cout<<"4: Cancel And Try Again to Entering Goal\n";
					cout<<"\nEnter Your Choice: ";
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
			
			if(!first) cout<<"Enter The Goal: ";
			first=false;
			temp[0]=nextInt();
			temp[1]=nextInt();
			if(inpSettings.getAssists()) temp[2]=nextInt(); else temp[2]=-2;
			if(inpSettings.getGoalsTimes()) temp[3]=nextInt(); else temp[3]=-2;
			if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
			finderror:
			cout<<endl;
			if(!easycheck(temp[0],1,2)){
				printError("Team Id is Invalid (Most Be 1 Or 2)\n");
				cout<<endl<<"KONUN: "<<temp[0]<<endl;
				error=true;
			}

			if(temp[1]!=-2 && temp[1]!=-1){
				if(temp[1]>INT_MAX-2) printError("Scorer Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[1])) || (temp[0]==2 && !tm2.existNumber(temp[1]))){
					printError("Scorer: There is No Player With This Number!\n");
					error=true;
				}
				else if((temp[0]==1 && !prCanEnter(temp[1],tm1)) || (temp[0]==2 && !prCanEnter(temp[1],tm2))){
					printError("Scorer: This Player Not entered This Game!\n");
					error=true;
				}
			}

			if(temp[2]!=-2 && temp[2]!=-1){
				if(temp[2]>INT_MAX-2) printError("Assister Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[2])) || (temp[0]==2 && !tm2.existNumber(temp[2]))){
					printError("Assister: There is No Player With This Number!\n");
					error=true;
				}
				else if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
					printError("Assister: This Player Not entered This Game!\n");
					error=true;
				}
			}

			if(!ukEasycheck(temp[3],1,90)){
				printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
				error=true;
				continue;
			}

			if((temp[3]==45 || temp[3]==90) && !ukEasycheck(temp[4],0,15)){
				printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
				error=true;
			}
		}

		goals[i][0]=temp[0];
		if(temp[3]==-2) goals[i][1]=-2;
		else if(temp[3]<=45) goals[i][1]=1;
		else goals[i][1]=2;
		goals[i][2]=temp[1];
		goals[i][3]=temp[2];
		goals[i][4]=temp[3];
		if(goals[i][4]==45 || goals[i][4]==90) goals[i][4]+=temp[4];
		return true;
	}
        
	bool goalErrorAfterEdit(int i,team tm1, team tm2){
		if(!easycheck(goals[i][0],1,2)){
			return true;
		}
            
		if(!ukEasycheck(goals[i][1],1,2)){
			return true;
		}
            
		if(goals[i][2]!=-2 || goals[i][2]!=-1){
			if((goals[i][0]==1 && !prCanEnter(goals[i][2],tm1)) || (goals[i][0]==2 && !prCanEnter(goals[i][2],tm2))){
				return true;
			}
		}

		if(goals[i][3]!=-2 && goals[i][3]!=-1){
			if((goals[i][0]==1 && !prCanEnter(goals[i][3],tm1)) || (goals[i][0]==2 && !prCanEnter(goals[i][3],tm2))){
				return true;
			}
		}

		if(!ukEasycheck(goals[i][4],1,105)){
			return true;
		}
		return false;
	}
        
	void printGoal(int i,team tm1, team tm2,inputProfile inpSettings){
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
			
		if(goals[i][0]==1) temp1<<tm1.name;
		else if(goals[i][0]==2) temp1<<tm2.name;
			
		if(goals[i][1]==1) temp2<<"First Half";
		else if(goals[i][1]==2) temp2<<"Second Half";
		else if(goals[i][1]==-2) temp2<<"UK";
			
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
		ccsPrint(temp1);
		
		if(inpSettings.getGoalsTimes()){
			cout<<" | ";
			ccsPrint(temp2);
		}
		
		cout<<" | "; ccsPrint(temp3);
		if(inpSettings.getAssists()){
			cout<<" | ";
			ccsPrint(temp4);
		}
		
		if(inpSettings.getGoalsTimes()){
			cout<<" | ";
			ccsPrint(temp5);
		}
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
		
		else if (strcasecmp(index,"t1_left")==0) return t1_left;
		else if (strcasecmp(index,"t2_left")==0) return t2_left;
		else if (strcasecmp(index,"t1_center")==0) return t1_center;
		else if (strcasecmp(index,"t2_center")==0) return t2_center;
		else if (strcasecmp(index,"t1_right")==0) return t1_right;
		else if (strcasecmp(index,"t2_right")==0) return t2_right;
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
        
	void convertIDToNumbers(team tm1,team tm2){
		for(int k=0; 11>k; k++){
			if(t1_prs[k]>0) t1_prs[k]=tm1.getPrFromId(t1_prs[k]).getNumber();
		}
		
		for(int k=0; 11>k; k++){
			if(t2_prs[k]>0) t2_prs[k]=tm2.getPrFromId(t2_prs[k]).getNumber();
		}
        
		for(int k=0; 3>k; k++){
			if(t1_tvz[k]>0) t1_tvz[k]=tm1.getPrFromId(t1_tvz[k]).getNumber();
		}
		
		for(int k=0; 3>k; k++){
			if(t2_tvz[k]>0) t2_tvz[k]=tm2.getPrFromId(t2_tvz[k]).getNumber();
		}
        
		for(int k=0; 2>k; k++){
			if(mom[k][0]>0){
				if(mom[k][1]==1) mom[k][0]=tm1.getPrFromId(mom[k][0]).getNumber();
				else if(mom[k][1]==2) mom[k][0]=tm2.getPrFromId(mom[k][0]).getNumber();
			}
		}
        
		for(int k=0; 28>k; k++){
			if(cards[k][3]>0){
				if(cards[k][0]==1) cards[k][3]=tm1.getPrFromId(cards[k][3]).getNumber();
				if(cards[k][0]==2) cards[k][3]=tm2.getPrFromId(cards[k][3]).getNumber();
			}
		}
        
		for(int k=0; 30>k; k++){
			if(goals[k][2]>0){
				if(goals[k][0]==1) goals[k][2]=tm1.getPrFromId(goals[k][2]).getNumber();
				if(goals[k][0]==2) goals[k][2]=tm2.getPrFromId(goals[k][2]).getNumber();
			}
			if(goals[k][3]>0){
				if(goals[k][0]==1) goals[k][3]=tm1.getPrFromId(goals[k][3]).getNumber();
				if(goals[k][0]==2) goals[k][3]=tm2.getPrFromId(goals[k][3]).getNumber();
			}
		}
	}
        
		
	void input_game(team tm1,team tm2,inputProfile& inpSettings){
		if(inpSettings.getDate()) set_date();
		else setUkDate();
                
		set_goals(tm1,tm2);
                
		if(inpSettings.getStats()){
			set_possess_shots(tm1,tm2);
			set_fouls_corners(tm1,tm2);
			set_fk_passc_cross(tm1,tm2);
			set_ic_tackle_save(tm1,tm2);
		}
		else setUkStats();
            
		if(inpSettings.getAreas()) setAttackingAreas(tm1,tm2);
		else setUkAttackingAreas();
                
		if(inpSettings.getPlayers()){
			setFirstLineup(tm1);
			setFirstLineup(tm2);
			setSubLineup(tm1);
			setSubLineup(tm2);
		}
		else setUkPlayers();
            
		if(inpSettings.getOveralls()) setOverallPrs(tm1,tm2);
		else setUkOveralls();
                
		if(inpSettings.getGoals()) set_goals_scorers(tm1,tm2,inpSettings); else setUkGoalsScorers();
		if(inpSettings.getNumCards()) set_tcards(tm1,tm2); else setUkNumCards();
		if(inpSettings.getCards()) set_cards(tm1,tm2,inpSettings); else setUkCards();
		if(inpSettings.getMom()) set_mom(tm1,tm2,inpSettings); else setUkMom();
		if(inpSettings.getConf()) set_conf(tm1,tm2); else setNoConf();
                
		convertNumbersToID(tm1,tm2);
		exist=1;
		IS_SAVED=false;
		cout<<endl; setColor("BOLDGREEN"); cout<<"Game Entered Succsessfuly.\n"; setColor("RESET");
	}
        
	void setUkDate(){
		year=-2;
		month=-2;
		day=-2;
	}
        
	void setUkStats(){
		t1_possess=-2; t2_possess=-2;
		for(int i=0; 2>i; i++) t1_shots[i]=-2;
		for(int i=0; 2>i; i++) t2_shots[i]=-2;
		for(int i=0; 2>i; i++) t1_fouls[i]=-2;
		for(int i=0; 2>i; i++) t2_fouls[i]=-2;
		t1_corners=-2; t2_corners=-2; t1_fk=-2; t2_fk=-2;
		t1_pass_c=-2; t2_pass_c=-2; t1_cross=-2; t2_cross=-2; t1_interc=-2; t2_interc=-2;
		t1_tackles=-2; t2_tackles=-2; t1_saves=-2; t2_saves=-2;
	}
        
	void setUkAttackingAreas(){
		t1_left=-2; t1_center=-2; t1_right=-2;
		t2_left=-2; t2_center=-2; t2_right=-2;
	}
        
	void setUkPlayers(){
		for(int i=0; 11>i; i++) t1_prs[i]=-2;
		for(int i=0; 11>i; i++) t2_prs[i]=-2;
		t1_tt=-2; t2_tt=-2;
		for(int i=0; 3>i; i++) t1_tvz[i]=-2;
		for(int i=0; 3>i; i++) t2_tvz[i]=-2;
	}
        
	void setUkOveralls(){
		for(int i=0; 11>i; i++){
			if(t1_prs[i]>0) t1_pov[i]=-2;
			else t1_pov[i]=-1;
		}
		
		for(int i=0; 11>i; i++){
			if(t2_prs[i]>0) t2_pov[i]=-2;
			else t2_pov[i]=-1;
		}
		
		for(int i=0; 3>i; i++){
			if(t1_tvz[i]>0) t1_tov[i]=-2;
			else t1_tov[i]=-1;
		}
		
		for(int i=0; 3>i; i++){
			if(t2_tvz[i]>0) t2_tov[i]=-2;
			else t2_tov[i]=-1;
		}
	}
        
	void setUkGoalsScorers(){	
		for(int i=0; tg>i; i++) for(int j=0; 5>j; j++) goals[i][j]=-2;
		for(int i=tg; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=-1;
	}
        
	void setUkNumCards(){
		for(int i=0; 3>i; i++) t1_tc[i]=-2;
		for(int i=0; 3>i; i++) t2_tc[i]=-2;
	}
        
	void setUkCards(){
		if(tcards==-2){
			for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
		}
		
		else{
			for(int i=0; tcards>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
			for(int i=tcards; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
		}
	}
        
	void setUkMom(){
		for(int i=0; 2>i; i++) mom[0][i]=-2;
		for(int i=0; 2>i; i++) mom[1][i]=-2;
	}
        
	void setNoConf(){
		t1_conf[0]=0;
		t2_conf[0]=0;
	}
        
	bool editGame(team tm1,team tm2){
		inputProfile inpSettings;
            
		convertIDToNumbers(tm1,tm2);
            
		while(true){
			int num=0;
			int choice;
			cout<<endl;
			boldRedPrint("Edit Game:\n");
			cout<<++num<<": Date\n";
			cout<<++num<<": Result\n";
			cout<<++num<<": Possession and Shots\n";
			cout<<++num<<": Fouls And Corners\n";
			cout<<++num<<": Free Kicks, Pass Completed And Crosses\n";
			cout<<++num<<": Interception, Tackles And Saves\n";
			cout<<++num<<": Attacking Areas\n";
			cout<<++num<<": "<<tm1.getName()<<" First Line Up\n";
			cout<<++num<<": "<<tm1.getName()<<" Substitution\n";
			cout<<++num<<": "<<tm2.getName()<<" First Line Up\n";
			cout<<++num<<": "<<tm2.getName()<<" Substitution\n";
			cout<<++num<<": Players Overall Ratings\n";
			cout<<++num<<": Goals Scorers\n";
			cout<<++num<<": Number of Cards\n";
			cout<<++num<<": Cards Details\n";
			cout<<++num<<": Man of the Match\n";
			cout<<++num<<": Conference\n";
			cout<<++num<<": Delete Game\n";
			cout<<++num<<": Back to Recent Menu\n";
			cout<<endl<<"Enter Your Choice To Edit: ";
			choice=inputChoice(1,num);
                
			if(choice==1){
				set_date(true);
			}
                
			else if(choice==2){
				set_goals(tm1,tm2,true);
				set_goals_scorers(tm1,tm2,inpSettings,false,true);
			}
                
			else if(choice==3){
				set_possess_shots(tm1,tm2,true);
			}

			else if(choice==4){
				set_fouls_corners(tm1,tm2,true);
			}
                
			else if(choice==5){
				set_fk_passc_cross(tm1,tm2,true);
			}
                
			else if(choice==6){
				set_ic_tackle_save(tm1,tm2,true);
			}
                
			else if(choice==7){
				setAttackingAreas(tm1,tm2,true);
			}
                
			else if(choice==8){
				setLineup(tm1,true,true);
			}
                
			else if(choice==9){
				setLineup(tm1,false,true);
			}
                
			else if(choice==10){
				setLineup(tm2,true,true);
			}
                
			else if(choice==11){
				setLineup(tm2,false,true);
			}
                
			else if(choice==12){
				setOverallPrs(tm1,tm2,true);
			}
                
			else if(choice==13){
				if(tg==0){
					cout<<endl<<"This Game Does not have a Goal\n";
					continue;
				}
                    
				set_goals_scorers(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==14){
				set_tcards(tm1,tm2,true);
				set_cards(tm1,tm2,inpSettings,false,true);
			}
                
			else if(choice==15){
				if(tcards==0){
					cout<<endl<<"This Game Does not have a Card!\n";
					continue;
				}
				
				else if(tcards==-2){
					cout<<endl<<"Number of Cards is Unknown!\n";
					continue;
				}
                    
				set_cards(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==16){
				set_mom(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==17){
				set_conf(tm1,tm2,true);
			}
                
			else if(choice==18){
				convertNumbersToID(tm1,tm2);
				return false;
			}
                
			else if(choice==19){
				convertNumbersToID(tm1,tm2);
				return true;
			}
                
                
			if(choice>=8 && choice<=11){
				bool singleCardError=false;
				bool singleGoalError=false;
				for(int i=0; tg>i; i++){
					if(goalErrorAfterEdit(i,tm1,tm2)){
						singleGoalError=true;
						break;
					} 
				
					
				}
				for(int i=0; tcards>i; i++){
					if(cardErrorAfterEdit(i,tm1,tm2)){
						singleCardError=true;
						break;
					} 
				}
                    
				if(singleGoalError){
					cout<<endl;
					printError("Your Edit Cause Error in Goals Scorers Session\n");
					cout<<endl;
					setColor("BOLDBLUE");
					cout<<"Goals:\n";
					setColor("RESET");
					for(int i=0; tg>i; i++){
						if(goalErrorAfterEdit(i,tm1,tm2)){
							setColor("BOLDRED");
							printGoal(i,tm1,tm2,inpSettings);
						}
						else{
							setColor("BOLDBLUE");
							printGoal(i,tm1,tm2,inpSettings);
						}
						setColor("RESET");
					}
					cout<<endl;
						
					for(int i=0; tg>i; i++){
						if(goalErrorAfterEdit(i,tm1,tm2)){
							cout<<"Goal "<<i+1<<": ";
							enterGoal(i,tm1,tm2,inpSettings,true);
						}
					}
					set_goals_scorers(tm1,tm2,inpSettings,false,true);
				}
                    
				if(singleCardError){
					cout<<endl;
					printError("Your Edit Cause Error in Cards Details Session\n");
					cout<<endl;
					setColor("BOLDBLUE");
					cout<<"Cards:\n";
					setColor("RESET");
					for(int i=0; tcards>i; i++){
						if(cardErrorAfterEdit(i,tm1,tm2)){
							setColor("BOLDRED");
							printCard(i,tm1,tm2,inpSettings);
						}
						else{
							setColor("BOLDBLUE");
							printCard(i,tm1,tm2,inpSettings);
						}
						setColor("RESET");
					}
					cout<<endl;
                        
					for(int i=0; tcards>i; i++){
						if(cardErrorAfterEdit(i,tm1,tm2)){
							cout<<"Card "<<i+1<<": ";
							enterCard(i,tm1,tm2,inpSettings,true);
						}
					}
					set_cards(tm1,tm2,inpSettings,false,true);
				}
                    set_mom(tm1,tm2,inpSettings,false,true);
			}
		}
	}
            
        
	void showConf(team tm,int terLength,int terMarigin, int confMarigin){
		char *conf;
		
		if(tm.sendid()==1) conf=t1_conf;
		else if(tm.sendid()==2) conf=t2_conf;
		else throw -1;
            
		int lineLength=terLength-(2*confMarigin)-2;
            
		space(terMarigin);
		setColor("BOLDBLUE");
		cout<<"|";
		setColor("RESET");
		space(confMarigin);
            
		int nameLen;
		for(nameLen=0; tm.getName()[nameLen]!=0; nameLen++);
            
		if(tm.sendid()==1) setColor("BOLDMAGENTA");
		else if(tm.sendid()==2) setColor("BOLDCYAN");
		cout<<tm.getName()<<": ";
		setColor("RESET");
            
		int lineL=nameLen+2;
            
		int i;
		for(i=0; conf[i]!=0; i++){
			char vocab[50];
			for(int m=0; 50>m; m++) vocab[m]=0;
			int k;
			if(conf[i]==' '){
				vocab[0]=' ';
				k=1;
			}
			
			else{
				int j;
				for(j=i,k=0; conf[j]!=' ' && conf[j]!=0; j++,k++){
					vocab[k]=conf[j];
				}
				vocab[k]=0;
			}

			if(lineL+k<=lineLength){
				cout<<vocab;
				lineL+=k;
			}
			else{
				space(lineLength-lineL);
				space(confMarigin);
				setColor("BOLDBLUE");
				cout<<"|";
				setColor("RESET");
				cout<<endl;
				space(terMarigin);
				setColor("BOLDBLUE");
				cout<<"|";
				setColor("RESET");
				space(confMarigin);
				cout<<vocab;
				lineL=k;
			}
			
			i+=(k-1);
		}
		space(lineLength-lineL);
		space(confMarigin);
		setColor("BOLDBLUE");
		cout<<"|";
		setColor("RESET");
	}

	void showAllConfs(team tm1,team tm2,int scrLength,int terLength,int terMarigin, int confMarigin){
		if(t1_conf[0]==0 && t2_conf[0]==0) return;
	
		cout<<endl;
		cout<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Conferences",scrLength); setColor("RESET");
		if(t1_conf[0]!=0){
			cout<<endl;
			space(terMarigin);
			setColor("BOLDBLUE");
			cadr_dash(terLength);
			setColor("RESET");
			showConf(tm1,terLength,terMarigin,confMarigin);
		}
            
		if(t2_conf[0]!=0){
			cout<<endl;
			space(terMarigin);
			setColor("BOLDBLUE");
			cadr_dash(terLength);
			setColor("RESET");
			showConf(tm2,terLength,terMarigin,confMarigin);
		}
            
		cout<<endl;
		space(terMarigin);
		setColor("BOLDBLUE");
		cadr_dash(terLength);
		setColor("RESET");

	}
        
	void show(team,team);
	//void print_goals(team,team);
	void update_after_game(team &,team &,bool silent=false);
	friend class competition;
	friend void add_game(match *,team &,team &);
	//friend void print_all_goals(match *m,team tm1,team tm2);
};

#endif	// MATCH_H

