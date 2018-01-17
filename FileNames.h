#ifndef FILENAMES_H
#define FILENAMES_H

#include "saheader.h"

class FileNames{
    int length;
    string fn[300];
    
	public:
    
    FileNames(){
        length=0;
    }
    
    void delOlds(){
        if(length<=200) return;
        int step=length-200;
        for(int i=0; 200>i; i++){
            fn[i]=fn[i+step];
        }
        length=200;
    }
    
    bool choiceMenu(char* inputFN){
        int printIndex=0;
        int choice;
        string isfd[300];
        
        start:
        cout<<endl;
        setColor("BOLDBLUE");
        cout<<"Load:\n";
        setColor("RESET");
		
        for(int i=0; length>i; i++){
            char tempFN[256];
            strcpy(tempFN,fn[i].c_str());
            if(isDataFile(tempFN)){
                isfd[printIndex]=fn[i];
                setColor("BOLDBLUE");
                cout<<++printIndex<<": ";
                setColor("RESET");
                cout<<fn[i]<<endl;
            }
        }
        
        setColor("BOLDBLUE");
        cout<<printIndex+1<<": ";
        setColor("RESET");
        cout<<"Enter Another File Name\n";
        setColor("BOLDBLUE");
        cout<<printIndex+2<<": ";
        setColor("RESET");
        cout<<"Cancel\n";
        cout<<endl<<"Enter Your Choice: ";
        choice=inputChoice(1,printIndex+2);
		
        if(choice<=printIndex){
            strncpy(inputFN,isfd[choice-1].c_str(),256);
            append(inputFN);
            return true;
        }
        
        else if(choice==printIndex+1){
            userinput:
            char userFN[256];
            cout<<endl<<"Enter File Name: ";
            cin.getline(userFN,256);
            if(isDataFile(userFN)){
                string str(userFN);
                append(str);
                strncpy(inputFN,userFN,256);
                return true;
            }
            
            else{
                cout<<endl;
                if(existFile(userFN)) printError("Invalid File!\n");
                else printError("File Not Found!\n");
                cout<<endl;
                setColor("BOLDRED");
                cout<<"Next Work?\n";
                setColor("RESET");
                cout<<"1: Try Again\n";
                cout<<"2: Go to File Names Menu\n";
                cout<<"3: Cancel\n";
                cout<<endl;
                cout<<"Enter Your Choice: ";
                int choice=inputChoice(1,3);
                if(choice==1) goto userinput;
                else if(choice==2) goto start;
                else return false;
            }
        }
        
        else if(choice==printIndex+2) return false;
		
		throw -1;
    }
    
    void append(string str){
        if(length==299) delOlds();
        int index;
        for(index=0; length>index && fn[index].compare(str)!=0; index++);
        if(index<length){
            for(int i=index; i>0; i--){
                fn[i]=fn[i-1];
            }
            fn[0]=str;
        }
        else{
            fn[index]=str;
            length++;
        }
        save();
    }
    
    void save(){
        fstream f1("configs.bin" , ios::out | ios::binary);
        f1.write(reinterpret_cast<char *>(&length), sizeof(length));
        for(int i=0; length>i; i++){
            int size = (fn[i].size());
            f1.write(reinterpret_cast<char *>(&size), sizeof(int));
            f1.write(fn[i].c_str(), size);
	}
        f1.close();
    }
    
    void load(){
        fstream f1("configs.bin" , ios::in | ios::binary);
        if(f1){
            f1.read(reinterpret_cast<char *>(&length), sizeof(length));
            for(int i=0; length>i; i++){
                int size;
                char *buf;
                f1.read(reinterpret_cast<char *>(&size), sizeof(int));
                buf = new char[size];
                f1.read(buf, size);
                fn[i] = "";
                fn[i].append(buf, size);
            }
            f1.close();
        }
    }
};



#endif /* FILENAMES_H */

