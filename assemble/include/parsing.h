#ifndef PARSING_H
#define PARSING_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<regex>
using namespace std;

class parsing
{
    public:
        parsing();
        text(string fileName);
        vector<string> getOperation();
        vector<string> getOperand();
        vector<string> getLable();
        vector<string> getLines();
        vector<int> getIndex();
        vector<string> instruction;
        vector<string> operands;
        vector<string> labels;
        vector<string> lines;
        string error;
        int flagString;
    protected:

    private:
};

#endif // PARSING_H
