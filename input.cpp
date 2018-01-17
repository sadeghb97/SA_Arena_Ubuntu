#include "saheader.h"

int stringToInt(char a[]){
    int t,out=0,zarb=1,r;
    int first;
    if(a[0]=='-') first=1;
    else first=0;
    if(a[first]==0) return INT_MAX;
    for (t=0; a[t]; t++);
    
    for (int i=first; t>i; i++) if(a[i]>57 || a[i]<48){
            return INT_MAX;
    }
    if(t-first>9) return INT_MAX-1;
    for (int i=first; t-1>i; i++) zarb=zarb*10;
    for (int i=first; t>i; i++){
            r= a[i]-48;
            out=out+r*zarb;
            zarb=zarb/10;
    }
    
    if(first==1) out=-(out);
    return out;
}

int nextInt(){
    char numch[60];
    cin>>numch;
    cin.ignore();
    int out=stringToInt(numch);
    return out;
}

bool printCheckChoice (int a,int min,int max){
    if (min<0) min = 0;
    if (max<0) max = INT_MAX-2;
    if(a==INT_MAX){
        printError("You most Enter an Integer Number\n");
        return false;
    }
    if(a<min || a>max){
        setColor("BOLDRED");
        cout<<endl<<"Error: ";
        setColor("RESET");
        cout<<"Invalid Number. Your Num Most be Between "<<min<<","<<max<<endl;
        return false;
    }
    return true;
}

bool easycheck (int num, int min, int max){
    if(num<min || num>max) return false;
    return true;
}

bool ukEasycheck (int num, int min, int max,bool waAccept){
    if(num==-2) return true;
    if(waAccept && num==-1) return true;
    if(num<min || num>max) return false;
    return true;
}

bool ukEasycheck (int num, int min, int max){
    ukEasycheck(num,min,max,false);
}

int inputChoice(int min,int max){
    int out;
    bool first=true;
    do{
        if(!first) cout<<endl<<"Enter Your Choice Again: ";
        out=nextInt();
        first=false;
    } while(!printCheckChoice(out,min,max));
    return out;
}

bool sure(){
    cout<<endl<<"Are you sure? (1:Yes | 2:No): ";
    return inputChoice(1,2)==1;
}

