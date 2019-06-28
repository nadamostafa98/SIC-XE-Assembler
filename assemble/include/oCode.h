#ifndef OCODE_H
#define OCODE_H
#include <cstring>
#define BASE_16 16
#include <bits/stdc++.h>
using namespace std;

class oCode
{
    public:
        oCode();
        vector<string> operationBits(vector<string> operation);
        vector<string> addressingModeBits(vector<string> operation, vector <string> operand,vector<string> labels);
        vector<string> displacement(vector<string> labels,vector<string> operation, vector <string> operand, vector<string> address);
        string hexToBinary(string hex);
        int binaryToDecimal(string binary);
        string binaryToHex(string binary);
        int twosComplement(int dec , int bits);
        bool pc;
        bool f4;
        vector<bool> pcrelative;
        vector<string> allCode (vector<string> p1, vector<string> p2, vector<string> p3,vector<string> operation,vector<string> operand);
        string registers(string s);
        string decimalToHex(int decimal);
        int hexToDecimal(string hexadecimal);
    protected:

    private:
};

#endif // OCODE_H
