#include "../../include/output1.h"
#include "../../include/addressList.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

output1:: output1(){
}
output1::print(vector<string> address,vector<string> label, vector<string> opCode, vector<string> operand,unordered_map<string,pair<string,string>> address_map)
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, 10);
    gotoxy(5,0);
    cout << "LINE NO.";
    gotoxy(25,0);
    cout << "ADDRESS";
    gotoxy(50,0);
    cout << "LABEL";
    gotoxy(70,0);
    cout << "MNEMONIC";
    gotoxy(70,1);
    cout << "OP-CODE";
    gotoxy(90,0);
    cout << "OPERANDS";

    SetConsoleTextAttribute(hConsole, saved_attributes);
    int size = opCode.size();
    int flagComment = 0;
    int iNum = 0;
    int ii = 0;
    int flagError = 0;
    for(int i = 0; i < size; i++)
    {
        if(opCode.at(i) != " ")
        {
            if(opCode.at(i) == "comment"){

                flagComment = 1;
            }
        }
       if(label.at(i).find("ERROR1") != std::string::npos){
            gotoxy(40,i + 2);
            cout << label.at(i);
            iNum --;
            flagError = 1;
        }
        else if(label.at(i).find("ERROR2") != std::string::npos){
            continue;
        }
        else if(flagComment == 1){
            gotoxy(5, i + 2);
            cout << iNum + 1;
            gotoxy(25,i + 2);
            cout << address.at(i);
           gotoxy(50,i + 2);
            cout << label.at(i);
        }
        else{
        gotoxy(5, i + 2);
        cout << iNum + 1;
        gotoxy(25,i + 2);
        cout << address.at(i);
        gotoxy(50,i + 2);
        cout << label.at(i);
        gotoxy(70,i + 2);
        cout << opCode.at(i);
        gotoxy(90,i + 2);
        cout << operand.at(i);
        }
        flagComment = 0;
        iNum++;
        ii = i;
    }
    gotoxy(5,ii + 5);
    SetConsoleTextAttribute(hConsole, 10);
    cout <<"> > > > > > > > > > > > > > >  S Y M B O L    T A B L E";
    gotoxy(10,ii + 10);
    cout<< "NAME";
    gotoxy(30,ii + 10);
    cout<< "ADDRESS";
    gotoxy(50,ii + 10);
    cout<< "ABSOL/RELOC";
    SetConsoleTextAttribute(hConsole, saved_attributes);
    int l = 10;
    l = l + 2;
    for(auto it=address_map.begin();it!=address_map.end();it++) {
    addressList al;
       int dec = al.hexToDecimal(it->second.first);
       gotoxy(10,ii + l);
        cout << it->first;
        gotoxy(30,ii + l);
        cout << dec;
        gotoxy(50,ii + l++);
        cout << it ->second.second;

    l++;
}
}
output1::gotoxy(int x1, int y1)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x1, y1 };
    SetConsoleCursorPosition(h,c);

}
