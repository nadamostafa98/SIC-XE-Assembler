#ifndef OUTPUT3_H
#define OUTPUT3_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class output3
{
    public:
        output3();
        print(vector<string>address, vector<string>label, vector<string>opCode, vector<string>operand,vector<string>objectCode,vector<string>textRecords,string header,string ending,unordered_map<string,pair<string,string>> address_map,vector<string>lines,vector<int> index,vector<int> error2);
        gotoxy(int x, int y);
        int x;
        int y;
    protected:

    private:
};

#endif // OUTPUT3_H
