#include "saheader.h"

void team::sortPrsByDebut(match *m){
	int selected[200];
	for(int i=0; 200>i; i++) selected[i]=0;
		
	int index=0;
	for(int i=0; m[i].sendexist() && 200>i; i++){
		int *prs;
		int *tvz;
		if(id==1){
			prs=m[i].t1_prs;
			tvz=m[i].t1_tvz;
		}
		else if(id==2){
			prs=m[i].t2_prs;
			tvz=m[i].t2_tvz;
		}
		else throw -1;
			
		for(int j=0; 11>j; j++){
			if(prs[j]>0){
				if(findIndexInIntArray(prs[j],selected,200)>=0) continue;
				else{
					int secondInd=getPrIndexFromId(prs[j]);
					player temp=pr[index].clone();
					pr[index]=pr[secondInd].clone();
					pr[secondInd]=temp;
					selected[index]=prs[j];
					index++;
				}
			}
		}

		for(int j=0; 3>j; j++){
			if(tvz[j]>0){
				if(findIndexInIntArray(tvz[j],selected,200)>=0) continue;
				else{
					int secondInd=getPrIndexFromId(tvz[j]);
					player temp=pr[index].clone();
					pr[index]=pr[secondInd].clone();
					pr[secondInd]=temp;
					selected[index]=tvz[j];
					index++;
				}
			}
		}
	}
}

void team::showSqadList(match *m){
	if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
	else{
		while(true){
			setColor("BOLDGREEN");
			cout<<"\nSquad List:\n";
			setColor("RESET");
			for(int i=0; pr[i].exist!=0; i++){
				pr[i].namePostShow();
				cout<<endl;
			}
				
			int num=0;
			cout<<endl;
			setColor("BOLDRED");
			cout<<"Next Work?"<<endl;
			setColor("RESET");
			cout<<++num<<": Show a Player Details\n";
			cout<<++num<<": Sort by Numbers\n";
			cout<<++num<<": Sort by Posts\n";
			cout<<++num<<": Sort by Overall Ratings\n";
			cout<<++num<<": Sort by Debut\n";
			cout<<++num<<": Back To Team Menu\n";
			cout<<endl<<"Enter Your Choice: ";
			int choice=inputChoice(1,num);
			if(choice==1){
				show_a_player:
				int ind;
				cout<<endl<<"Enter Player Club Number: ";
				ind=nextInt();
					
				try{
					getPrFromNumber(ind).show();
				}
				catch(int ex){
					cout<<endl<<"There is no Player with this Number!"<<endl;
				}
					
				cout<<endl;
				setColor("BOLDRED");
				cout<<"Next Work?"<<endl;
				setColor("RESET");
				cout<<"1: Show Squad List\n2: Show another Player Details\n3: Back To Team Menu\n";
				cout<<"Enter Your Choice: ";
				int choice=inputChoice(1,3);
				if(choice==2) goto show_a_player;
				else if(choice==3) return;
			}
			else if(choice==2) sortPrs("number");
			else if(choice==3) sortPrs("post");
			else if(choice==4) sortPrs("overallRating",true);
			else if(choice==5) sortPrsByDebut(m);
			else if(choice==6) return;
		}
	}
}

void team::teamManage(team other,match *m){
	int choice;
	while(1){
		cout<<"\n";
		setColor("BOLDRED");
		printname();
		cout<<" Session:\n";
		setColor("RESET");
		cout<<"1: Show Team Results\n";
		cout<<"2: Add Players\n";
		cout<<"3: Edit Players\n";
		cout<<"4: Change Player Numbers\n";
		cout<<"5: Show Squad List \n";
		cout<<"6: Show Detailed Player List\n";
		cout<<"7: Back to main\n";
			
		cout<<endl<<"Enter your choice: ";
		choice=inputChoice(1,7);
			
		switch(choice){
			case 1: show(); break;
			case 2: add_prs(other); break;
			case 3: editPrs(other); break;
			case 4: editPrNumbers(); break;
			case 5: showSqadList(m); break;
			case 6: show_det_prs(); break;
		}
		if (choice==7) break;
	}
}