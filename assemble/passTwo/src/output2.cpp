#include "../../include/output2.h"
#include "../../include/addressList.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

output2:: output2(){
}
output2::print(vector<string> address,vector<string> label, vector<string> opCode, vector<string> operand,vector<string>objectCode,vector<string>textRecords,string header,string ending,unordered_map<string,pair<string,string>> address_map,vector<string>lines,vector<int> index,vector<int> error2)
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
    cout << "OP-CODE";
    gotoxy(90,0);
    cout << "OPERANDS";
    gotoxy(110,0);
    cout << "OBJECT CODE";

    SetConsoleTextAttribute(hConsole, saved_attributes);
    int size = opCode.size();
    string add;
    string lab;
    string op;
    string oper;
    string obCode;
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
         vector<int>::iterator it;
         vector<int>::iterator it2;
        it = find(index.begin(), index.end(), i);
        it2 = find(error2.begin(), error2.end(), i);
       if(label.at(i).find("ERROR2") != std::string::npos){
            gotoxy(40,i + 2);
            cout << label.at(i);
            iNum --;
            flagError = 1;
       }
        else if(label.at(i).find("ERROR1") != std::string::npos){
            continue;
        }
        else if (it != index.end() && it2 != error2.end())
        {
            gotoxy(40,i + 2);
            cout << "****ERROR2: INCORRECT EXPRESSION AND LABEL DOES NOT EXIST";
            iNum --;
            flagError = 1;
        }
        else if (it != index.end())
        {
            gotoxy(40,i + 2);
            cout << "****ERROR2: INCORRECT EXPRESSION";
            iNum --;
            flagError = 1;
        }
        else if (it2 != error2.end())
        {
            gotoxy(40,i + 2);
            cout << "****ERROR2: LABEL DOES NOT EXIST";
            iNum --;
            flagError = 1;
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
        gotoxy(110,i + 2);
        cout << objectCode.at(i);
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
if(flagError == 0){
    l = l + 5;
    SetConsoleTextAttribute(hConsole, 10);
    gotoxy(5,ii + l);
    cout <<"> > > > > > > > > > > > > > >  O B J E C T    P R O G R A M";
    SetConsoleTextAttribute(hConsole, saved_attributes);
    l = l + 5;
    gotoxy(10,ii + l++);
    cout << header;
    for(int m = 0; m < textRecords.size(); m++){
        gotoxy(10,ii +  l++);
        cout << textRecords.at(m);
    }
    gotoxy(10,ii + l);
    cout << ending;
}
else{
    l = l + 5;
    SetConsoleTextAttribute(hConsole, 10);
    gotoxy(5,ii + l);
    cout <<"> > > > > > > > > > > > > > >  E R R O R   I N   P A S S 2  ,  C O U L D N ' T   G E N E R A T E   O B J E C T   P R O G R A M";
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
    gotoxy(10,ii + l + 10);
    cout << "";

}
output2::gotoxy(int x1, int y1)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x1, y1 };
    SetConsoleCursorPosition(h,c);

}
