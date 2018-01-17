#include "saheader.h"

void match::set_goals(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
	int choice,error=0;
	cout<<"\nEnter Goals Respectively (According to ID)\n";
	t1_goals=nextInt();
        t2_goals=nextInt();
	temp1.str("");
	temp2.str("");
        if(t1_goals<0 || t1_goals>20){ temp1<<"Null"; error=1;} else if(t1_goals>=0) temp1<<t1_goals;
	if(t2_goals<0 || t2_goals>20){ temp2<<"Null"; error=1;} else if(t2_goals>=0) temp2<<t2_goals;
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<" "; ccsPrint(temp1); cout<<" - "; ccsPrint(temp2); cout<<" "<<tm2.name; setColor("RESET"); cout<<endl;
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Invalid Value For Goals. Try again.\n"; setColor("RESET");
		set_goals(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_goals(tm1,tm2); return;}
	if(t1_goals>t2_goals) res=1; else if(t2_goals>t1_goals) res=2; else if(t1_goals==t2_goals) res=3;
        tg=t1_goals+t2_goals;
}
void match::set_possess_shots(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Possession Respectively:\n"; cin>>t1_possess>>t2_possess; cin.ignore();
	cout<<"\nEnter Shots(On Target) Respectively"<<endl<<"Help: T1_Shots | T1_On_Target | T2_Shots | T2_On_Target:\n"; cin>>t1_shots[0]>>t1_shots[1]>>t2_shots[0]>>t2_shots[1]; cin.ignore();
	if(t1_possess==-2) temp1<<"UK"; else if(t1_possess<0){ temp1<<"Null"; error=1;} else if(t1_possess>=0) temp1<<t1_possess;
	if(t2_possess==-2) temp2<<"UK"; else if(t2_possess<0){ temp2<<"Null"; error=1;} else if(t2_possess>=0) temp2<<t2_possess;
	if(t1_shots[0]==-2) temp3<<"UK"; else if(t1_shots[0]<0){ temp3<<"Null"; error=1;} else if(t1_shots[0]>=0) temp3<<t1_shots[0];
	if(t1_shots[1]==-2) temp4<<"UK"; else if(t1_shots[1]<0){ temp4<<"Null"; error=1;} else if(t1_shots[1]>=0) temp4<<t1_shots[1];
	if(t2_shots[0]==-2) temp5<<"UK"; else if(t2_shots[0]<0){ temp5<<"Null"; error=1;} else if(t2_shots[0]>=0) temp5<<t2_shots[0];
	if(t2_shots[1]==-2) temp6<<"UK"; else if(t2_shots[1]<0){ temp6<<"Null"; error=1;} else if(t2_shots[1]>=0) temp6<<t2_shots[1];
	if(t1_shots[0]<t1_shots[1] || t2_shots[0]<t2_shots[1]) error=1;
	setColor("BOLDBLUE"); cout<<endl<<"Possession: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Shots (On Target): "<<tm1.name<<": "; ccsPrint(temp3); cout<<"("; ccsPrint(temp4); cout<<")"<<" | "<<tm2.name<<": "; ccsPrint(temp5); cout<<"("; ccsPrint(temp6); cout<<")"<<endl; setColor("RESET");
	if(t1_possess!=-2 && t2_possess!=-2 && t1_possess+t2_possess!=100){ cout<<endl; setColor("BOLDYELLOW"); cout<<"Error In Possession\n"; setColor("RESET"); cout<<endl; set_possess_shots(tm1,tm2); return;}
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_possess_shots(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_possess_shots(tm1,tm2); return;}	
}
void match::set_fouls_corners(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Fouls(Offsides) Respectively:\n"; cin>>t1_fouls[0]>>t1_fouls[1]>>t2_fouls[0]>>t2_fouls[1]; cin.ignore();
	cout<<"\nEnter Corners Respectively"<<endl; cin>>t1_corners>>t2_corners; cin.ignore();
	if(t1_fouls[0]==-2) temp1<<"UK"; else if(t1_fouls[0]<0){ temp1<<"Null"; error=1;} else if(t1_fouls[0]>=0) temp1<<t1_fouls[0];
	if(t1_fouls[1]==-2) temp2<<"UK"; else if(t1_fouls[1]<0){ temp2<<"Null"; error=1;} else if(t1_fouls[1]>=0) temp2<<t1_fouls[1];
	if(t2_fouls[0]==-2) temp3<<"UK"; else if(t2_fouls[0]<0){ temp3<<"Null"; error=1;} else if(t2_fouls[0]>=0) temp3<<t2_fouls[0];
	if(t2_fouls[1]==-2) temp4<<"UK"; else if(t2_fouls[1]<0){ temp4<<"Null"; error=1;} else if(t2_fouls[1]>=0) temp4<<t2_fouls[1];
	if(t1_corners==-2) temp5<<"UK"; else if(t1_corners<0){ temp5<<"Null"; error=1;} else if(t1_corners>=0) temp5<<t1_corners;
	if(t2_corners==-2) temp6<<"UK"; else if(t2_corners<0){ temp6<<"Null"; error=1;} else if(t2_corners>=0) temp6<<t2_corners;
	cout<<endl; setColor("BOLDBLUE"); cout<<"Fouls (Offsides): "<<tm1.name<<": "; ccsPrint(temp1); cout<<"("; ccsPrint(temp2); cout<<")"<<" | "<<tm2.name<<": "; ccsPrint(temp3); cout<<"("; ccsPrint(temp4); cout<<")"<<endl;
	cout<<"Corners: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_fouls_corners(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_fouls_corners(tm1,tm2); return;}	
}
void match::set_fk_passc_cross(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Freekicks Respectively:\n"; cin>>t1_fk>>t2_fk; cin.ignore();
	cout<<"\nEnter Passess Completed Respectively:"<<endl; cin>>t1_pass_c>>t2_pass_c; cin.ignore();
	cout<<"\nEnter Crossess Respectively:"<<endl; cin>>t1_cross>>t2_cross; cin.ignore();
	if(t1_fk==-2) temp1<<"UK"; else if(t1_fk<0){ temp1<<"Null"; error=1;} else if(t1_fk>=0) temp1<<t1_fk;
	if(t2_fk==-2) temp2<<"UK"; else if(t2_fk<0){ temp2<<"Null"; error=1;} else if(t2_fk>=0) temp2<<t2_fk;
	if(t1_pass_c==-2) temp3<<"UK"; else if(t1_pass_c<0){ temp3<<"Null"; error=1;} else if(t1_pass_c>=0) temp3<<t1_pass_c;
	if(t2_pass_c==-2) temp4<<"UK"; else if(t2_pass_c<0){ temp4<<"Null"; error=1;} else if(t2_pass_c>=0) temp4<<t2_pass_c;
	if(t1_cross==-2) temp5<<"UK"; else if(t1_cross<0){ temp5<<"Null"; error=1;} else if(t1_cross>=0) temp5<<t1_cross;
	if(t2_cross==-2) temp6<<"UK"; else if(t2_cross<0){ temp6<<"Null"; error=1;} else if(t2_cross>=0) temp6<<t2_cross;
	setColor("BOLDBLUE"); cout<<endl<<"Freekicks: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Passess Completed: "<<tm1.name<<": "; ccsPrint(temp3); cout<<"% | "<<tm2.name<<": "; ccsPrint(temp4); cout<<"%"<<endl;
	cout<<"Crossess: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	if(t1_pass_c>100 || t2_pass_c>100){ setColor("BOLDYELLOW"); cout<<"Error In Passes Completed\n"<<endl; setColor("RESET"); set_fk_passc_cross(tm1,tm2); return;}
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_fk_passc_cross(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_fk_passc_cross(tm1,tm2); return;}	
}
void match::set_ic_tackle_save(team tm1,team tm2){
	int choice,error=0;
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
	cout<<"\nEnter Interceptions Respectively:\n"; cin>>t1_interc>>t2_interc; cin.ignore();
	cout<<"\nEnter Tackles Respectively:"<<endl; cin>>t1_tackles>>t2_tackles; cin.ignore();
	cout<<"\nEnter Saves Respectively:"<<endl; cin>>t1_saves>>t2_saves; cin.ignore();
	if(t1_interc==-2) temp1<<"UK"; else if(t1_interc<0){ temp1<<"Null"; error=1;} else if(t1_interc>=0) temp1<<t1_interc;
	if(t2_interc==-2) temp2<<"UK"; else if(t2_interc<0){ temp2<<"Null"; error=1;} else if(t2_interc>=0) temp2<<t2_interc;
	if(t1_tackles==-2) temp3<<"UK"; else if(t1_tackles<0){ temp3<<"Null"; error=1;} else if(t1_tackles>=0) temp3<<t1_tackles;
	if(t2_tackles==-2) temp4<<"UK"; else if(t2_tackles<0){ temp4<<"Null"; error=1;} else if(t2_tackles>=0) temp4<<t2_tackles;
	if(t1_saves==-2) temp5<<"UK"; else if(t1_saves<0){ temp5<<"Null"; error=1;} else if(t1_saves>=0) temp5<<t1_saves;
	if(t2_saves==-2) temp6<<"UK"; else if(t2_saves<0){ temp6<<"Null"; error=1;} else if(t2_saves>=0) temp6<<t2_saves;
	setColor("BOLDBLUE"); cout<<endl<<"Interceptions: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Tackles: "<<tm1.name<<": "; ccsPrint(temp3); cout<<" | "<<tm2.name<<": "; ccsPrint(temp4); cout<<endl;
	cout<<"Saves: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_ic_tackle_save(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_ic_tackle_save(tm1,tm2); return;}		
}
void match::setLineup(team tm,bool first){
        int *inputArray;
        int *otherArray;
        int tedad;
        
        start:
        if(first){
            if(tm.sendid()==1) inputArray=t1_prs;
            else if(tm.sendid()==2) inputArray=t2_prs;
            tedad=11;
        }
        else{
            if(tm.sendid()==1){
                otherArray=t1_prs;
                inputArray=t1_tvz;
                cout<<endl<<"Enter Number Of "<<tm.getName()<<" Subs: ";
                t1_tt=inputChoice(0,3);
                tedad=t1_tt;
            }
            else if(tm.sendid()==2){
                otherArray=t2_prs;
                inputArray=t2_tvz;
                cout<<endl<<"Enter Number Of "<<tm.getName()<<" Subs: ";
                t2_tt=inputChoice(0,3);
                tedad=t2_tt;
            }
        }
        
        if(!first && tedad==0){
            if(sure()){
                for(int i=0; 3>i; i++) inputArray[i]=-1;
                return;
            }
            else goto start;
        }
        
	int choice,j,error,secondError;
        int err[11];
        
	if(first) cout<<"\nEnter 11 Numbers For "<<tm.getName()<<" First Line Up\n";
        else cout<<"\nEnter "<<tedad<<" Numbers For "<<tm.getName()<<" Substitutes Players\n";
        
	for(int i=0; tedad>i; i++){ inputArray[i]=nextInt();}
        
        
	printplayers:
        for(int i=0; tedad>i; i++) err[i]=0;
	cout<<endl;
        setColor("BOLDBLUE");
        bool existEr=false;
	for(int i=0; tedad>i; i++){
		if(inputArray[i]==-2){
                    setColor("BOLDBLACK");
                    cout<<i+1<<": ";
                    cout<<"UK";
                    setColor("RESET");
                }
                else if(inputArray[i]>(INT_MAX-2)){
                    setColor("RED");
                    cout<<i+1<<": ";
                    cout<<"Null";
                    err[i]=1;
                    existEr=true;
                    setColor("RESET");
                }
		else if(!tm.existNumber(inputArray[i])){
                    setColor("RED");
                    cout<<i+1<<": ";
                    cout<<"Null";
                    err[i]=2;
                    existEr=true;
                    setColor("RESET");
                }
		else if(tm.existNumber(inputArray[i])){
                    setColor("BOLDBLUE");
                    cout<<i+1<<": ";
                    cout<<tm.getPrFromNumber(inputArray[i]).sendname();
                    setColor("RESET");
                }
		cout<<endl;
	}
	error=0;
        secondError=0;
	for (int i=0; tedad>i; i++){
		if(inputArray[i]!=-2 && err[i]==0){
                    for(int j=i+1; tedad>j; j++){
                        if(inputArray[i]==inputArray[j]){
                            error=1;
                            break;
                        }
                    }
                    if(!first){
                        for(int j=0; 11>j; j++){
                            if(inputArray[i]==otherArray[j]){
                                secondError=1;
                                break;
                            }
                        }
                    }
                    
                }
	}
        
        
        bool oneEndl=false;
        for(int i=0; 11>i; i++){
            if(!oneEndl) cout<<endl;
            oneEndl=true;
            if(err[i]==1){
                char sprTemp[70];
                sprintf(sprTemp,"Player %d: Entering Non Numerical String\n",i+1);
                printError(sprTemp);
            }
            else if(err[i]==2){
                char sprTemp[70];
                sprintf(sprTemp,"Player %d: There is No Player with This Number\n",i+1);
                printError(sprTemp);
            }
        }
        if(error==1) printError("Same Players In Line Up!\n");
        if(secondError==1) printError("Same Players In First Line Up And Substitutes Line Up!\n");
        
	cout<<endl;
        setColor("BOLDRED");
        cout<<"Do you want to edit a Player?\n";
        setColor("RESET");
        cout<<"1: No\n2: Yes\n3: Enter Line Up From The Beginning\n";
        cout<<endl<<"Enter Your Choice: ";
        choice=inputChoice(1,3);
        if(choice==3) goto start;
	if(choice==2){
		cout<<"Shomare Bazikon?: ";
                j=inputChoice(1,tedad);
		cout<<"Enter ID: ";
		inputArray[j-1]=nextInt();
		goto printplayers;
	}
	if(error==1 || secondError || existEr){
                cout<<endl;
                if(error==1) printError("Same Players In Line Up!\n");
                if(existEr) printError("Invalid Values In Line Up!\n");
                if(secondError==1) printError("Same Players In First Line Up And Substitutes Line Up!\n");
		setColor("BOLDYELLOW"); cout<<"Please Enter Line Up From The Beginning\n"; setColor("RESET");
		goto start;
	}
}


void match::set_goals_scorers(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
	int choice, j, inpg1,inpg2;
        int error;
        
        start:
	while(1){
		if(tg==0){
			for(int i=0; 30>i; i++) for(int k=0; 5>k; k++) goals[i][k]=-1;
			break;
		}
		inpgoals:
		cout<<"\nEnter "<<tg<<" Goals:\n";
		setColor("BOLDYELLOW"); cout<<"Instruction: "; setColor("RESET");
                cout<<"Team-Scorer ID-Assister ID-Minute\n";
                setColor("BOLDYELLOW"); cout<<"Rule: "; setColor("RESET");
                cout<<"If the Goal Has been Scored in Last Minute Of Normal Time\n";
                cout<<"Enter Minute in Two Number (Normal Time Then Extra Time)\n";
                setColor("BOLDGREEN"); cout<<"Rule: "; setColor("RESET");
		cout<<"Without Assist ID=-1;\n";
                rulePrint("Own Goal Number=-1\n");
		for(int i=0; tg>i; i++){
			cout<<endl<<i+1<<": ";
                        if(!enterGoal(i,tm1,tm2)){
                            goto start;
                        }
                        cout<<"Goal "<<i+1<<": ";
                        printGoal(i,tm1,tm2);
		}
                
		chapgoals:
		cout<<endl; setColor("BOLDBLUE"); cout<<"All Goals: \n";
		for(int i=0; tg>i; i++){
                    cout<<"Goal "<<i+1<<": ";
                    printGoal(i,tm1,tm2);
		}
		setColor("RESET"); cout<<endl;
                
                finalquest:
		inpg1=0; inpg2=0;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1) inpg1++; else if(goals[i][0]==2) inpg2++;
		}
                error=0;
		if(t1_goals != inpg1 || t2_goals != inpg2){
                    cout<<endl;
                    printError("Contradiction Between Number Of Goals And These Inputs!!!\n");
                    error=1;
                }

		cout<<endl;
                setColor("BOLDRED"); cout<<"Next Work?\n"; setColor("RESET");
                if(error==0) cout<<"1: Apply And Go to Next Session\n";
                cout<<2-error<<": Edit A Goal\n";
                cout<<3-error<<": Enter Goals From The Beginning\n";
                cout<<4-error<<": Compatible Number Of Goals With Goals Inputs And Apply\n";
                cout<<5-error<<": Go to Number of Goals Session\n";
                cout<<6-error<<": Go To Line Up Session\n";
                cout<<endl<<"Enter Your Choice: ";
                choice=inputChoice(1,6-error);
		if(choice==2-error){
			cout<<"Shomare Goal?: ";
                        j=inputChoice(1,tg);
			j--;
			cout<<"Enter The Goal: ";
                        if(!enterGoal(j,tm1,tm2)){
                            set_goals(tm1,tm2);
                            goto start;
                        }
			goto chapgoals;
		}
                else if(choice==3-error) goto start;
                else if(choice==4-error){
                    setColor("BOLDBLUE");
                    cout<<endl<<tm1.getName()<<" "<<inpg1<<" - "<<inpg2<<" "<<tm2.getName()<<endl;
                    setColor("RESET");
                    
                    cout<<endl<<"Are you sure? (1:Yes | 2:No Cancel It): ";
                    int ch=inputChoice(1,2);
                    if(ch==2) goto finalquest;
                    t1_goals=inpg1;
                    t2_goals=inpg2;
                    setColor("GREEN");
                    cout<<endl<<"Number Of Goals Compatible With Inputs\n";
                    setColor("RESET");
                }
                else if(choice==5-error){
                    set_goals(tm1,tm2);
                    goto start;
                } 
                
                if(choice==6-error){
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
                    if(choice!=4) goto start;
                }
                	
		for(int i=0; 30-tg>i; i++) for(int k=0; 5>k; k++) goals[29-i][k]=-1;
		break;
	}
}

void match::set_tcards(team tm1,team tm2){
	int choice,error=0;
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	cout<<"\nEnter Respectively Number of Team1 Yellow Cards | Team1 Red Cards | Team2 Yellow Cards | Team2 Red Cards\n";
	t1_tc[0]=nextInt();
        t1_tc[1]=nextInt();
        t2_tc[0]=nextInt();
        t2_tc[1]=nextInt();
	if((t1_tc[0]>11 || t1_tc[0]<0)){ temp1<<"Null"; error=1;} else temp1<<t1_tc[0];
	if((t1_tc[1]>11 || t1_tc[1]<0)){ temp2<<"Null"; error=1;} else temp2<<t1_tc[1];
	if((t2_tc[0]>11 || t2_tc[0]<0)){ temp3<<"Null"; error=1;} else temp3<<t2_tc[0];
	if((t2_tc[1]>11 || t2_tc[1]<0)){ temp4<<"Null"; error=1;} else temp4<<t2_tc[1];
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<": Yellow cards: "; ccsPrint(temp1); cout<<" | Red cards: "; ccsPrint(temp2); cout<<endl;
	cout<<tm2.name<<": Yellow cards: "; ccsPrint(temp3); cout<<" | Red cards: "; ccsPrint(temp4); cout<<endl; setColor("RESET");
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error!!! Invalid Numbers! Try again.\n"; setColor("RESET");
		set_tcards(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_tcards(tm1,tm2); return;}
	t1_tc[2]=t1_tc[0]+t1_tc[1];
	t2_tc[2]=t2_tc[0]+t2_tc[1];
	tcards=t1_tc[2]+t2_tc[2];
}

void match::set_cards(team tm1,team tm2){
	int choice,tp1,tp2,inptc1[2],inptc2[2],j;
        int firstError,secondError,error;
        
        start:
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
		setColor("BOLDYELLOW"); cout<<"Instruction: "; setColor("RESET");
                cout<<"Team-Color-Player ID-Minute\n";
                setColor("BOLDYELLOW"); cout<<"Rule: "; setColor("RESET");
                cout<<"If the Cart Has been Showed in Last Minute Of Normal Time\n";
                cout<<"Enter Minute in Two Number (Normal Time Then Extra Time)\n";
                
		for(int i=0; tcards>i; i++){
                    cout<<endl<<i+1<<": ";
                    if(!enterCard(i,tm1,tm2)){
                        goto start;
                    }
                    cout<<"Card "<<i+1<<": ";
                    printCard(i,tm1,tm2);
                }
                
		chapcards:
		cout<<endl; setColor("BOLDBLUE"); cout<<"All Cards: \n";	
		for(int i=0; tcards>i; i++){
                    cout<<"Card "<<i+1<<": ";
                    printCard(i,tm1,tm2);
		}
		setColor("RESET"); cout<<endl;
                
                
                finalquest:
		inptc1[0]=0; inptc1[1]=0; inptc2[0]=0; inptc2[1]=0;
		for(int i=0; tcards>i; i++){
			if(cards[i][2]==1){ if(cards[i][0]==1) inptc1[0]++; else if(cards[i][0]==2) inptc2[0]++;}
			if(cards[i][2]==2){ if(cards[i][0]==1) inptc1[1]++; else if(cards[i][0]==2) inptc2[1]++;}
		}
		
                firstError=0;
		if(t1_tc[0] != inptc1[0] || t1_tc[1] != inptc1[1] || t2_tc[0] != inptc2[0] || t2_tc[1] != inptc2[1]){
                    cout<<endl;
                    printError("Contradiction Between Number Of Cards And These Inputs!!!\n");
                    firstError=1;
                }
                
                secondError=0;
		for(int i=0; tcards-1>i && secondError==0; i++){
			for(int j=i+1; tcards>j && secondError==0; j++){
				if(cards[i][0]==cards[j][0] && cards[i][2]==cards[j][2] && cards[i][3]==cards[j][3]){
                                    if(error==0) cout<<endl;
                                    printError("There is A player Who get More Than One Yellow Or Red Card!!!\n");
                                    secondError=1;
                                }
			}
		}
                
                if(firstError || secondError) error=1;
                
		cout<<endl;
                setColor("BOLDRED"); cout<<"Next Work?\n"; setColor("RESET");
                if(error==0) cout<<"1: Apply And Go to Next Session\n";
                cout<<2-error<<": Edit A Card\n";
                cout<<3-error<<": Enter Cards From The Beginning\n";
                cout<<4-error<<": Compatible Number Of Cards With Cards Inputs And Apply\n";
                cout<<5-error<<": Go to Number of Cards Session\n";
                cout<<6-error<<": Go To Line Up Session\n";
                cout<<endl<<"Enter Your Choice: ";
                choice=inputChoice(1,6-error);
		if(choice==2-error){
			cout<<"Card Number?: ";
                        j=inputChoice(1,tcards);
			j--;
			cout<<"Enter The Card: ";
                        if(!enterCard(j,tm1,tm2)){
                            set_tcards(tm1,tm2);
                            goto start;
                        }
			goto chapcards;
		}
                else if(choice==3-error) goto start;
                else if(choice==4-error){
                    setColor("BOLDBLUE");
                    cout<<endl<<tm1.name<<": Yellow cards: "<<inptc1[0]<<" | Red cards: "<<inptc1[1]<<endl;
                    cout<<tm2.name<<": Yellow cards: "<<inptc2[0]<<" | Red cards: "<<inptc2[1]<<endl;
                    setColor("RESET");
                    
                    cout<<endl<<"Are you sure? (1:Yes | 2:No Cancel It): ";
                    int ch=inputChoice(1,2);
                    if(ch==2) goto finalquest;
                    t1_tc[0]=inptc1[0];
                    t1_tc[1]=inptc1[1];
                    t1_tc[2]=inptc1[2];
                    t2_tc[0]=inptc2[0];
                    t2_tc[1]=inptc2[1];
                    t2_tc[2]=inptc2[2];
                    setColor("GREEN");
                    cout<<endl<<"Number Of Goals Compatible With Inputs\n";
                    setColor("RESET");
                }
                else if(choice==5-error){
                    set_tcards(tm1,tm2);
                    goto start;
                } 
                
                if(choice==6-error){
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
                    if(choice!=4) goto start;
                }
                						
		for(int i=0; 28-tcards>i; i++) for(int k=0; 5>k; k++) cards[27-i][k]=-1;
		break;
	}
}

void match::set_mom(team tm1,team tm2){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
	int choice,bar,error=0;
        
        start:
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
        setColor("BOLDRED");
        cout<<endl<<"Do you want Enter Man Of the Match And Second Player Of the Match?\n";
        setColor("RESET");
        cout<<"1: Yes Both of Them\n";
        cout<<"2: Yes Only Man Of The Match\n";
        cout<<"3: No\n";
        cout<<"\nEnter Your Choice: ";
        choice=inputChoice(1,3);
        if(choice==3){
            if(sure()){
                for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) mom[i][j]=-1;
                return;
            }
            else goto start;
        }
        else if(choice==2){
            mom[1][0]=-1;
            mom[1][1]=-1;
        }
	cout<<"\nEnter Number Of Man of The Match(2 Points)\n";
        if(choice==1) cout<<"Then Second Player Of The Match (1 Points)\n";
	if(choice==1) rulePrint("Help: MOTM - Team - Second Player - Team\n");
        else if(choice==2) rulePrint("Help: MOTM - Team\n");

        
        
	error=0;
                
        mom[0][0]=nextInt();
        mom[0][1]=nextInt();
        if(choice==1){
            mom[1][0]=nextInt();
            mom[1][1]=nextInt();
        }
               
	if(easycheck(mom[0][1],1,2)==0){
            if(error==0) cout<<endl;
            error=1;
            printError("Invalid MOTM Team Id\n");
        }
                
	if(choice==1 && easycheck(mom[1][1],1,2)==0){
            if(error==0) cout<<endl;
            error=1;
            printError("Invalid SPOTM Team Id\n");
        }
                
	if((mom[0][1]==1 && !prCanEnter(mom[0][0],tm1)) || (mom[0][1]==2 && !prCanEnter(mom[0][0],tm2))){
            if(error==0) cout<<endl;
            error=1;
            if(mom[0][0]>INT_MAX-2) printError("Invalid Value For MOTM Number\n");
            else printError("MOTM: This Player Not entered This Game!\n");
        }
                
	if(choice==1 && (mom[1][1]==1 && !prCanEnter(mom[1][0],tm1)) || (mom[1][1]==2 && !prCanEnter(mom[1][0],tm2))){
            if(error==0) cout<<endl;
            error=1;
            if(mom[1][0]>INT_MAX-2) printError("Invalid Value For SPOTM Number\n");
            else printError("SPOTM: This Player Not entered This Game!\n");
        }
                
	if(choice==1 && mom[0][1]==mom[1][1] && mom[0][0]==mom[1][0]){
            if(error==0) cout<<endl;
            error=1;
            printError("Same Inputs For MOTM and SPOTM\n");
        }
        
        if(error){
            setColor("BOLDYELLOW");
            cout<<"You are wrong! Try Again\n";
            goto start;
        }
        
	cout<<endl; setColor("BOLDBLUE"); cout<<"Man of the match: ";
	if(mom[0][1]==1) cout<<tm1.getPrFromNumber(mom[0][0]).sendname()<<" from "<<tm1.name<<endl;
	else if(mom[0][1]==2) cout<<tm2.getPrFromNumber(mom[0][0]).sendname()<<" from "<<tm2.name<<endl;
        if(choice==1){
            cout<<"Second Player of the match: ";
            if(mom[1][1]==1){ cout<<tm1.getPrFromNumber(mom[1][0]).sendname()<<" from "<<tm1.name<<endl;}
            else if(mom[1][1]==2){ cout<<tm2.getPrFromNumber(mom[1][0]).sendname()<<" from "<<tm2.name<<endl;}
        }
        setColor("RESET");
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
	if(choice==2){ set_mom(tm1,tm2); return;}
}
void match::set_conf(team tm1,team tm2){
	int choice,bar=0;
	tm1_conf:
	while(1){
		cout<<endl<<tm1.name<<": Aya Conferans midahid? (1:Yes | 2:No): ";
                choice=inputChoice(1,2);
		if(choice==2){
			t1_conf[0]=0;
			break;
		}
		cin.getline(t1_conf,1200);
		break;
	}
	while(1){
		bar++;
		tm2_conf:
		if(bar>1) break;
		cout<<endl<<tm2.name<<": Aya Conferans midahid? (1:Yes | 2:No): ";
                choice=inputChoice(1,2);
		if(choice==2){
			t2_conf[0]=0;
			break;
		}
		cin.getline(t2_conf,1200);
		break;
	}
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<": ";
	print_passage(t1_conf);
	cout<<endl;
	cout<<endl<<tm2.name<<": ";
	print_passage(t2_conf);
	cout<<endl; setColor("RESET");
	cout<<endl<<"Do you want to edit? (1:No | 2:"<<tm1.name<<" | 3:"<<tm2.name<<")\n";
        choice=inputChoice(1,3);
	if(choice==2) goto tm1_conf;
	else if(choice==3) goto tm2_conf;
}

void match::setPlayersHatTricks(team &tm1,team &tm2){
	if(tg<3) return;
	int **prStats;
	prStats=getPlayersStats();
	for(int i=0; prStats[i][0]!=0 && 28>i; i++){
		if(prStats[i][2]>=3){
			int p=prStats[i][2]/3;
			if(prStats[i][0]==1){
				tm1.getPrFromId(prStats[i][1]).hatTrikPlus(p);
			}
			else if(prStats[i][0]==2){
				tm2.getPrFromId(prStats[i][1]).hatTrikPlus(p);	
			}
		}
	}
}

void match::update_after_game(team &tm1,team &tm2){
	if(exist==1){ tm1.app_p(); tm2.app_p();}
	if(res==1){ tm1.win_p(); tm2.lose_p();}
	else if(res==2){ tm2.win_p(); tm1.lose_p();}
	else if(res==3){ tm1.draw_p(); tm2.draw_p();}

	for(int i=0; 11>i; i++) if(t1_prs[i]!=-2) tm1.getPrFromId(t1_prs[i]).app_p();
	for(int i=0; 11>i; i++) if(t2_prs[i]!=-2) tm2.getPrFromId(t2_prs[i]).app_p();
	for(int i=0; t1_tt>i; i++) if(t1_tvz[i]!=-2) tm1.getPrFromId(t1_tvz[i]).app_p();
	for(int i=0; t1_tt>i; i++) if(t2_tvz[i]!=-2) tm2.getPrFromId(t2_tvz[i]).app_p();
        
        if(mom[0][0]!=-1){
            if(mom[0][1]==1) tm1.getPrFromId(mom[0][0]).momPlus();
            else if(mom[0][1]==2) tm2.getPrFromId(mom[0][0]).momPlus();
        }
        if(mom[1][0]!=-1){
            if(mom[1][1]==1) tm1.getPrFromId(mom[1][0]).secondMomPlus();
            else if(mom[1][1]==2) tm2.getPrFromId(mom[1][0]).secondMomPlus();
        }
        
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
		if(cards[i][0]==1){ if(cards[i][2]==1 && cards[i][3]!=-2) tm1.getPrFromId(cards[i][3]).yc_p();}
		if(cards[i][0]==1){ if(cards[i][2]==2 && cards[i][3]!=-2) tm1.getPrFromId(cards[i][3]).rc_p();}
		if(cards[i][0]==2){ if(cards[i][2]==1 && cards[i][3]!=-2) tm2.getPrFromId(cards[i][3]).yc_p();}
		if(cards[i][0]==2){ if(cards[i][2]==2 && cards[i][3]!=-2) tm2.getPrFromId(cards[i][3]).rc_p();}
	}
        
	for(int i=0; tg>i; i++){
		if(goals[i][0]==1){
			if(goals[i][2]!=-2 && goals[i][2]!=-1) tm1.getPrFromId(goals[i][2]).goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm1.getPrFromId(goals[i][3]).ass_p();
		}
		else if(goals[i][0]==2){
			if(goals[i][2]!=-2 && goals[i][2]!=-1) tm2.getPrFromId(goals[i][2]).goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm2.getPrFromId(goals[i][3]).ass_p();
		}
	}
        
	setPlayersHatTricks(tm1,tm2);
	setColor("BOLDGREEN"); cout<<"Teams and Players Details Updated.\n"; setColor("RESET"); cout<<endl;
}

void match::show(team tm1,team tm2){
	int s,t,c;
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
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
		if(t1_fouls[0]==-2 && t1_fouls[1]==-2) ts1[3]<<"Uk"; else if(t1_fouls[0]==-2) ts1[3]<<"Uk("<<t1_fouls[1]<<")"; else ts1[3]<<t1_fouls[0]<<"(UK)";
	}
	if(t2_fouls[0]==-2 || t2_fouls[1]==-2){
		if(t2_fouls[0]==-2 && t2_fouls[1]==-2) ts2[3]<<"Uk"; else if(t2_fouls[0]==-2) ts2[3]<<"Uk("<<t2_fouls[1]<<")"; else ts2[3]<<t2_fouls[0]<<"(UK)";
	}
	temp1.str("");
	cout<<endl;
        setColor("BOLDRED");
	temp1<<tm1.name<<" Against "<<tm2.name;
	space(26); ccsPrint(temp1); setColor("RESET");
	temp1.str("");
	if(year!=-2){
		cout<<endl;
		temp1<<"$$WHT"<<"Date: ";
		temp1<<year;
		if(month!=-2 && month>9) temp1<<"/"<<month; else if(month!=-2 && month<10)temp1<<"/"<<"0"<<month;
		if(month!=-2 && day!=-2 && day>9) temp1<<"/"<<day<<"$0RST"<<endl; else if(day!=-2 && day<10)temp1<<"/"<<"0"<<day<<"$0RST"<<endl;
		strwhere(temp1,78); cout<<endl;
	}
	cout<<endl<<endl;
	cadr<<"$$BLU";
	t=12; c=48; s=15;
	space(s); ccsPrint(cadr); cadr_dash(c);
	space(s); cout<<"|"; setColor("BOLDCYAN"); strwhere(tm1.name,t,1); setColor("BOLDBLUE"); strwhere("Stats",22,1); setColor("BOLDCYAN"); strwhere(tm2.name,t,1); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
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
	for(int i=0; 14>i; i++){
		ts1[i].str("");
		ts2[i].str("");
	}
	for(int i=0; 11>i; i++) if(t1_prs[i]==-2) ts1[i]<<"UK"; else ts1[i]<<tm1.getPrFromId(t1_prs[i]).sendname();
	for(int i=0; 11>i; i++) if(t2_prs[i]==-2) ts2[i]<<"UK"; else ts2[i]<<tm2.getPrFromId(t2_prs[i]).sendname();
	for(int i=11; 14>i; i++){
		if(t1_tt>i-11){ if(t1_tvz[i-11]==-2) ts1[i]<<"UK"; else ts1[i]<<tm1.getPrFromId(t1_tvz[i-11]).sendname();}
	}
	for(int i=11; 14>i; i++){
		if(t2_tt>i-11){ if(t2_tvz[i-11]==-2) ts2[i]<<"UK"; else ts2[i]<<tm2.getPrFromId(t2_tvz[i-11]).sendname();}
	}
	cout<<endl<<endl;
	setColor("BOLDBLUE"); strwhere("Players",78,1); setColor("RESET");cout<<endl;
	s=21;
	space(s); ccsPrint(cadr); cout<<"------------------------------------"; setColor("RESET");cout<<endl;
	t=17;
	for(int i=0; 11>i; i++){
		space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
		if(mom[0][1]==1 && mom[0][0]==t1_prs[i] && t1_prs[i]!=-2) setColor("BOLDYELLOW");
		if(mom[1][1]==1 && mom[1][0]==t1_prs[i] && t1_prs[i]!=-2) setColor("BOLDGREEN");
		strwhere(ts1[i],t,1); setColor("RESET");
		if(mom[0][1]==2 && mom[0][0]==t2_prs[i] && t2_prs[i]!=-2) setColor("BOLDYELLOW");
		if(mom[1][1]==2 && mom[1][0]==t2_prs[i] && t2_prs[i]!=-2) setColor("BOLDGREEN");
		strwhere(ts2[i],t,1); setColor("RESET");
		ccsPrint(cadr); cout<<"|"; setColor("RESET"); cout<<endl; 
	}
	space(s); ccsPrint(cadr); cout<<"------------------------------------"; setColor("RESET");cout<<endl;
	for(int i=11; 14>i; i++){
		space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
		if(mom[0][1]==1 && mom[0][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) setColor("BOLDYELLOW");
		if(mom[1][1]==1 && mom[1][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) setColor("BOLDGREEN");
		strwhere(ts1[i],t,1); setColor("RESET");
		if(mom[0][1]==2 && mom[0][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) setColor("BOLDYELLOW");
		if(mom[1][1]==2 && mom[1][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) setColor("BOLDGREEN");
		strwhere(ts2[i],t,1); setColor("RESET");
		ccsPrint(cadr); cout<<"|"; setColor("RESET");cout<<endl;		
	}
	space(s); ccsPrint(cadr); cout<<"------------------------------------"; setColor("RESET");cout<<endl;
	if(tg>0){
		for(int i=0; tg>i; i++){
			if(goals[i][4]==-2) gl[i]<<"UK | "; else gl[i]<<goals[i][4]<<" | ";
			if(goals[i][0]==1){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else gl[i]<<tm1.getPrFromId(goals[i][2]).sendname()<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm1.getPrFromId(goals[i][3]).sendname()<<")";
			}
			if(goals[i][0]==2){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else gl[i]<<tm2.getPrFromId(goals[i][2]).sendname()<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm2.getPrFromId(goals[i][3]).sendname()<<")";
			}
		}
		cout<<endl<<endl;
		setColor("BOLDBLUE"); strwhere("Goals",78,1); setColor("RESET"); cout<<endl;
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1){space(20); setColor("BOLDMAGENTA"); ccsPrint(gl[i]); setColor("RESET");cout<<endl;}
			if(goals[i][0]==2){space(30); setColor("BOLDCYAN"); ccsPrint(gl[i]); setColor("RESET");cout<<endl;}
		}
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
	}
	if(tcards>0){
		for(int i=0; tcards>i; i++){
			if(cards[i][4]==-2) cs[i]<<"UK | "; else cs[i]<<cards[i][4]<<" | ";
			if(cards[i][2]==1) cs[i]<<"$$YEL"<<"Yellow"<<"$0RST"<<" | "; else if(cards[i][2]==2) cs[i]<<"$$RED"<<"Red"<<"$0RST"<<" | ";
			if(cards[i][0]==1){
				if(cards[i][2]==-2) cs[i]<<"$$MAG"<<"UK"; else cs[i]<<"$$MAG"<<tm1.getPrFromId(cards[i][3]).sendname();
			}
			if(cards[i][0]==2){
				if(cards[i][2]==-2) cs[i]<<"$$CYN"<<"UK"; else cs[i]<<"$$CYN"<<tm2.getPrFromId(cards[i][3]).sendname();
			}
		}
		cout<<endl<<endl;
		setColor("BOLDBLUE"); strwhere("Cards",78,1); setColor("RESET");cout<<endl;
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
		for(int i=0; tcards>i; i++){
			if(cards[i][0]==1){space(20); setColor("BOLDMAGENTA"); ccsPrint(cs[i]); setColor("RESET");cout<<endl;}
			if(cards[i][0]==2){space(30); setColor("BOLDCYAN"); ccsPrint(cs[i]); setColor("RESET");cout<<endl;}
		}					
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
	}			
}
