#ifndef INPUTPROFILE_H
#define INPUTPROFILE_H

#include "saheader.h"

class inputProfile{
    bool numCards;
    bool date;
    bool stats;
    bool areas;
    bool players;
    bool overalls;
    bool goals;
    bool assists;
    bool goalsTimes;
    bool cards;
    bool cardsTimes;
    bool mom;
    bool conf;
    
    public:
    inputProfile(){
        date=true;
        stats=true;
        areas=true;
        players=true;
        overalls=true;
        goals=true;
        assists=true;
        goalsTimes=true;
        numCards=true;
        cards=true;
        cardsTimes=true;
        mom=true;
        conf=true;
    }
    
    bool getDate(){ return date;}
    bool getStats(){ return stats;}
    bool getAreas(){ return areas;}
    bool getPlayers(){ return players;}
    bool getOveralls(){ return overalls;}
    bool getGoals(){ return goals;}
    bool getAssists(){ return assists;}
    bool getGoalsTimes(){ return goalsTimes;}
    bool getNumCards(){ return numCards;}
    bool getCards(){ return cards;}
    bool getCardsTimes(){ return cardsTimes;}
    bool getMom(){ return mom;}
    bool getConf(){ return conf;}
    
    int getNumSettings(){ return 13;}
    
    void saveTxt(ostream &f1){
        f1<<numCards<<endl;
        f1<<date<<endl;
        f1<<stats<<endl;
        f1<<areas<<endl;
        f1<<players<<endl;
        f1<<overalls<<endl;
        f1<<goals<<endl;
        f1<<assists<<endl;
        f1<<goalsTimes<<endl;
        f1<<cards<<endl;
        f1<<cardsTimes<<endl;
        f1<<mom<<endl;
        f1<<conf<<endl;
    }
    
    void loadTxt(istream &f1){
        f1>>numCards;
        f1>>date;
        f1>>stats;
        f1>>areas;
        f1>>players;
        f1>>overalls;
        f1>>goals;
        f1>>assists;
        f1>>goalsTimes;
        f1>>cards;
        f1>>cardsTimes;
        f1>>mom;
        f1>>conf;
        f1.ignore();
    }
    
    void enableAll(){
        date=true;
        stats=true;
        areas=true;
        players=true;
        overalls=true;
        goals=true;
        assists=true;
        goalsTimes=true;
        numCards=true;
        cards=true;
        cardsTimes=true;
        mom=true;
        conf=true;
    }
    
    void disableAll(){
        date=false;
        stats=false;
        areas=false;
        players=false;
        overalls=false;
        goals=false;
        assists=false;
        goalsTimes=false;
        numCards=false;
        cards=false;
        cardsTimes=false;
        mom=false;
        conf=false;
    }
    
    void printSettings(){
        int num=0;
        cout<<++num<<": "; if(date) boldGreenPrint("Date\n"); else noBoldBlackPrint("Date (Disabled)\n");
        cout<<++num<<": "; if(stats) boldGreenPrint("Game Stats\n"); else noBoldBlackPrint("Game Stats (Disabled)\n");
        cout<<++num<<": "; if(areas) boldGreenPrint("Attacking Areas\n"); else noBoldBlackPrint("Attacking Areas (Disabled)\n");
        cout<<++num<<": "; if(players) boldGreenPrint("Teams Line Ups\n"); else noBoldBlackPrint("Teams Line Ups (Disabled)\n");
        cout<<++num<<": "; if(overalls) boldGreenPrint("Players Overall Ratings\n"); else noBoldBlackPrint("Players Overall Ratings (Disabled)\n");
        cout<<++num<<": "; if(goals) boldGreenPrint("Goals Scorers\n"); else noBoldBlackPrint("Goals Scorers (Disabled)\n");
        cout<<"----"<<++num<<": "; if(assists) boldGreenPrint("Assists\n"); else noBoldBlackPrint("Assists (Disabled)\n");
        cout<<"----"<<++num<<": "; if(goalsTimes) boldGreenPrint("Goals Time\n"); else noBoldBlackPrint("Goals Time (Disabled)\n");
        cout<<++num<<": "; if(numCards) boldGreenPrint("Number Of Cards\n"); else noBoldBlackPrint("Number Of Cards (Disabled)\n");
        cout<<++num<<": "; if(cards) boldGreenPrint("Cards Details\n"); else noBoldBlackPrint("Cards Details (Disabled)\n");
        cout<<"----"<<++num<<": "; if(cardsTimes) boldGreenPrint("Cards Time\n"); else noBoldBlackPrint("Cards Time (Disabled)\n");
        cout<<++num<<": "; if(mom) boldGreenPrint("Man Of The Match\n"); else noBoldBlackPrint("Man Of The Match (Disabled)\n");
        cout<<++num<<": "; if(conf) boldGreenPrint("Conference\n"); else noBoldBlackPrint("Conference (Disabled)\n");
    }
    
    void settings(){
        int n=getNumSettings();
        int choice;
        cout<<endl;
        boldRedPrint("Game Input Settings Session:\n");
        typeRule(); cout<<"Enter 1 To "<<n<<" For Toggle\n";
        typeRule(); cout<<"Enter "<<n+1<<" For Enable All\n";
        typeRule(); cout<<"Enter "<<n+2<<" For Disable All\n";
        typeRule(); cout<<"Enter "<<n+3<<" For Quit\n";
        while(true){
            cout<<endl;
            boldRedPrint("Game Input Settings:\n");
            printSettings();
            cout<<endl<<"Enter Your Choice: ";
            choice=inputChoice(1,n+3);
            switch(choice){
                case 1: date=!date; break;
                case 2: stats=!stats; break;
                case 3: areas=!areas; break;
                case 4: players=!players; break;
                case 5: overalls=!overalls; break;
                case 6: goals=!goals; break;
                case 7: assists=!assists; break;
                case 8: goalsTimes=!goalsTimes; break;
                case 9: numCards=!numCards; break;
                case 10: cards=!cards; break;
                case 11: cardsTimes=!cardsTimes; break;
                case 12: mom=!mom; break;
                case 13: conf=!conf; break;
                case 14: enableAll(); break;
                case 15: disableAll(); break;
            }
            if(choice==n+3) break;
        }
    }
};


#endif /* INPUTPROFILE_H */

