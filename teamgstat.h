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

#endif	// TEAMGSTAT_H

