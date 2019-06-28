#ifndef OUTPUT1_H
#define OUTPUT1_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class output1
{
    public:
        output1();
        print(vector<string>address, vector<string>label, vector<string>opCode, vector<string>operand,unordered_map<string,pair<string,string>> address_map);
        gotoxy(int x, int y);
        int x;
        int y;
    protected:

    private:
};

#endif // OUTPUT_H
