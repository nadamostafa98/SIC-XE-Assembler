#ifndef OPROGRAM_H
#define OPROGRAM_H
#include <cstring>
#define BASE_16 16
#include <bits/stdc++.h>
using namespace std;


class oProgram
{
    public:
        oProgram();
        vector<string> textRecords (vector<string> address, vector<string> objectCode,vector<string> operation);
        string headRecord(vector<string> address, vector<string> labels, vector<string> operation);
        string endRecord(vector<string> address, vector<string> objectCode);
    protected:

    private:
};

#endif // OPROGRAM_H
