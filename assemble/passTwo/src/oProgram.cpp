#include "oProgram.h"
#include "oCode.h"
#include <cstring>
#define BASE_16 16
#include <cmath>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

oProgram::oProgram()
{

}
vector<string> oProgram :: textRecords(vector<string> address, vector<string> objectCode,vector<string> operation)
{
    vector<string> allText;
    string text = "T";
    string start = "";
    string len;
    string code = "";
    oCode al;
    int k = 0;
    while( k < objectCode.size() && objectCode.at(k) == "")
    {
        k++;
    }
    start = address.at(k);
    while(start.length() < 6){
            start = "0" + start;
        }
    while(k < objectCode.size())
    {
        code = "";
        string temp = "";
        while(k < objectCode.size() && operation.at(k) != "END" && operation.at(k) != "ORG" && operation.at(k) != "EQU" && operation.at(k) != "START" &&operation.at(k) != "RESW" && operation.at(k) != "RESB" && operation.at(k) != "ORG"&& temp.length() < 59)
        {
            code = code + objectCode.at(k);
            temp = code +objectCode.at(k + 1);
            k++;
        }
        if( operation.at(k) == "END")
        {
            int x = al.hexToDecimal(address.at(k)) - al.hexToDecimal(start);
            len = al.decimalToHex(x);
            while(len.size() < 2){
                len = "0" + len;
            }
            string finalText = text + start + len + code;
            allText.push_back(finalText);
        }
        if(!(k < objectCode.size()) || (objectCode.at(k) == "" && operation.at(k) != "ORG" && operation.at(k) != "EQU" && operation.at(k) != "START"&& operation.at(k) != "RESW" && operation.at(k) != "RESB" && operation.at(k) != "ORG"))
        {
            break;
        }
        int x = al.hexToDecimal(address.at(k)) - al.hexToDecimal(start);
        len = al.decimalToHex(x);
        while(len.size() < 2){
                len = "0" + len;
            }
        string finalText = text + start + len + code;
        allText.push_back(finalText);
        while( k < objectCode.size()&& objectCode.at(k) == "")
        {
            k++;
        }

        start = address.at(k);
        while(start.length() < 6){
            start = "0" + start;
        }
    }

    return allText;
}
string oProgram::headRecord(vector<string> address, vector<string> labels , vector<string> operation){
    string operationStr;
    int  i = 0;
    operationStr = operation.at(i);
    i++;
    while(operationStr != "START"){
        operationStr = operation.at(i);
    i++;
    }
    string name = labels.at(i-1);
    while(name.length() < 6){
        name = name +" ";
    }
    string addStart = address.at(0);
    while(addStart.length() < 6){
        addStart = addStart +" ";
    }
    string addFinal = address.at(address.size() - 1);
    oCode al;
    int x = al.hexToDecimal(addFinal) - al.hexToDecimal(addStart);
    string len = al.decimalToHex(x);
    while(len.length() < 6){
        len = "0" + len;
    }
    string header = "H" + name + addStart+len;
    return header;
}
string oProgram::endRecord(vector<string> address, vector<string> objectCode){
    int i = 0;
    string addressFirst;
    while(objectCode.at(i) == ""){
            i++;
    }
    addressFirst = address.at(i);
    while(addressFirst.length() < 6){
        addressFirst =  "0" +addressFirst;
    }
        return "E" +addressFirst;

}
