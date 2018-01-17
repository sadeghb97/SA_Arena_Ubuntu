#ifndef GENERALS_H
#define GENERALS_H

#include "saheader.h"


const int MAX_GAMES = 200;

using namespace std;
void strwhere(const char*,int,int);
void strwhere(const char*,int);
int sstreamLength(stringstream &);
void strwhere(stringstream &,int,int);
void strwhere(stringstream &,int);
void setConsoleColor(const char *);
void space(int);
void cadr_dash(int);
void swap(int &,int &);
void swap(int [],int [],int n);
void colorStringPrint(string);
void ccsPrint(stringstream &);
int getColorNum(string);
void setColor(int,bool);
void setColor(int);
void setColor(const char *);
bool randYesNo();

class player;
class team;
class match;
class competition;
struct teamGameStat;
struct date;

bool save(team,team, match *);
bool saveTxt(team,team, match *);
bool load(team &, team &, match *);
bool loadTxt(team &, team &, match *);
void mainMenu(team&,team&,match *);
bool enterTeams(team&,team&);
int generateNewPrId(team,team);
void team_manage(team &,team);
void add_game(match *,team &,team &);
void showTableStats(teamGameStat, teamGameStat ,date ,bool, bool, bool);
void print_passage(char *);
void details_repair(match *, team &,team &);
void competition_stats(team ,team ,match []);
void subsume_players(team,team);
void show_game(match *,team,team);
void moratab(int[][3],int,int,int);


#endif	// GENERALS_H

