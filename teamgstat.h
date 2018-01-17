#ifndef TEAMGSTAT_H
#define TEAMGSTAT_H

#include "saheader.h"

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
	double sOverall;
	double sFOverall;
	double nCards[2];
	
	//teamGameStat(){}
	teamGameStat(char teamName[],int defValue){
		strcpy(name,teamName);
		nSub=defValue; nGoals=defValue; possess=defValue; shots[0]=defValue; shots[1]=defValue;
		fouls[0]=defValue; fouls[1]=defValue; corners=defValue; fk=defValue; passC=defValue;
		cross=defValue; interc=defValue; tackles=defValue; saves=defValue; nCards[0]=defValue; nCards[1]=defValue;
		sOverall=defValue; sFOverall=defValue;
	}
	
	bool isComplete(){
		if(nSub>=0 && nGoals>=0 && possess>=0 && shots[0]>=0 && shots[1]>=0 && fouls[0]>=0 && fouls[1]>=0 && corners>=0
		&& fk>=0 && passC>=0 && cross>=0 && interc>=0 && tackles>=0 && saves>=0 && nCards[0]>=0 && nCards[1]>=0
		&& sOverall>=0 && sFOverall>=0){
			return true;
		}
		return false;
	}
	
	void convertToPerGame(int number[]){
		int num=-1;
		if(number[++num]>0){ nGoals/=number[num];} else{ nGoals=-2;}
		if(number[++num]>0){ possess/=number[num];} else{ possess=-2;}
		
		if(number[++num]>0){ shots[0]/=number[num]; shots[1]/=number[num];}
		else{ shots[0]=-2; shots[1]=-2;}
			
		if(number[++num]>0){ fouls[0]/=number[num]; fouls[1]/=number[num];}
		else{ fouls[0]=-2; fouls[1]=-2;}
		
		if(number[++num]>0){ corners/=number[num];} else{ corners=-2;}
		if(number[++num]>0){ fk/=number[num];} else{ fk=-2;}
		if(number[++num]>0){ passC/=number[num];} else{ passC=-2;}
		if(number[++num]>0){ cross/=number[num];} else{ cross=-2;}
		if(number[++num]>0){ interc/=number[num];} else{ interc=-2;}
		if(number[++num]>0){ tackles/=number[num];} else{ tackles=-2;}
		if(number[++num]>0){ saves/=number[num];} else{ saves=-2;}
		
		if(number[++num]>0){ nCards[0]/=number[num]; nCards[1]/=number[num];}
		else{ nCards[0]=-2; nCards[1]=-2;}
		
		if(number[++num]>0){ nSub/=number[num];} else{ nSub=-2;}
		if(number[++num]>0){ sFOverall/=number[num];} else{ sFOverall=-2;}
		if(number[++num]>0){ sOverall/=number[num];} else{ sOverall=-2;}
	}
};

#endif	// TEAMGSTAT_H

