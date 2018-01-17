#ifndef GENERALS_H
#define GENERALS_H

#include "saheader.h"


const int MAX_GAMES = 200;
extern char* DATA_FILE_NAME;
extern char* NULL_PATH_STRING;
extern bool IS_SAVED;

using namespace std;

int doubleToInt(double);
int compareDoubleDecimals(double,double);
bool isInt(double);

void beforeStrWhere(const char*,int);
void beforeStrWhere(stringstream &,int);
void strwhere(const char*,int,int);
void strwhere(const char*,int);
int sstreamLength(stringstream &);
void strwhere(stringstream &,int,int);
void strwhere(stringstream &,int);
void setConsoleColor(const char *);
void space(int);
void cadr_dash(int,bool noEndl=false);
void swap(int &,int &);
void swap(int [],int [],int n);
void colorStringPrint(string);
void ccsPrint(stringstream &);
int getColorNum(string);
void setColor(int,bool);
void setColor(int);
void setColor(const char *);
bool randYesNo();
int findIndexInIntArray(int,int *,int);

class player;
class team;
class match;
class competition;
struct teamGameStat;
struct date;
class inputProfile;
class FileNames;

bool existFile(char*);
bool isDataFileAndReady(istream&);
bool isDataFile(char*);
bool isDataFile(const char*);
bool save(char*,team,team, match *,inputProfile);
bool save(const char*,team,team, match *,inputProfile);
bool saveAs(team,team, match *,inputProfile);
bool saveTxt(char*,team,team, match *,inputProfile);
bool saveTxt(const char*,team,team, match *,inputProfile);
bool load(team &, team &, match *,inputProfile&);
//bool load(const char*,team &, team &, match *);
bool loadTxt(char*,team &, team &, match *,inputProfile &);
bool loadTxt(const char*,team &, team &, match *,inputProfile &);
bool lostDataWarning(team,team,match *,inputProfile,bool showWarn=false);
bool exitApp(team,team,match *,inputProfile);
bool mainMenu(team&,team&,match *,inputProfile&,const char*);
bool enterTeams(team&,team&);
int generateNewPrId(team,team);
int choiceMatch(match *,team,team);
void externalShowAllPrs(const char*);
int getNumGames(match *);
void add_game(match *,team &,team &, inputProfile &);
void editGame(match *,team &,team &);
void showWALTable(teamGameStat, teamGameStat , bool, bool, bool);
void print_passage(char *);
void details_repair(match *, team &,team &);
void silentDetailsRepair(match *, team &,team &);
void competition_stats(team ,team ,match []);
void subsume_players(team,team);
void show_game(match *,team,team);
void moratab(int[][3],int,int,int);
void newTermPlayers(team,team,match *);
void correctData(team &, team &, match *,inputProfile&);


#endif	// GENERALS_H

