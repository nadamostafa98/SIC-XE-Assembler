#ifndef ADDRESSLIST_H
#define ADDRESSLIST_H
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <unordered_map>
#define BASE_16 16
using namespace std;

class addressList
{
    public:
        addressList();
        vector<string> getAddress(vector<string> operation, vector <string> operand, vector<string>labels);
        int hexToDecimal(string hexadecimal);
        string theResult(string hex, int theInt);
        string decimalToHex(int decimal);
        vector<int> addressDecimal();
        vector<int> addressDe;
        vector<int> error;
        unordered_map<string,pair<string,string>> address_map;
        unordered_map<string,pair<string,string>>getmap();
        vector<int>getError();
    protected:

    private:
};

#endif // ADDRESSLIST_H
