#ifndef DATE_H
#define DATE_H

#include "saheader.h"

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

#endif	// DATE_H

