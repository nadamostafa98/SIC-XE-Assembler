#include "include/parsing.h"
#include "include/addressList.h"
#include "include/output1.h"
#include "include/output2.h"
#include "include/output3.h"
#include "include/oCode.h"
#include "include/oProgram.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<regex>
using namespace std;

int main()
{
    string input;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    string file;
    while(flag1 == 0 && flag2 == 0 && flag3 == 0)
    {
        cout << "PLEASE ENTER FILE PATH"<<endl;
        cin >> input;
        regex filePath("(pass1<)(.*)[>]");
        regex filePath2("(pass2<)(.*)[>]");
        regex filePath3("(assemble<)(.*)[>]");
        smatch match;
        if (regex_match(input,filePath))
        {
            flag1 = 1;
            bool b = regex_search(input,match,filePath);
            file=match[2];
        }
        else if (regex_match(input,filePath2))
        {
            flag2 = 1;
            bool b = regex_search(input,match,filePath2);
            file=match[2];
        }
        else if (regex_match(input,filePath3))
        {
            flag3 = 1;
            bool b = regex_search(input,match,filePath3);
            file=match[2];
        }
        else
        {
            cout << "INCORRECT ENTERY" << endl;
        }
    }
    vector<string> address;
    vector<string> label;
    vector<string> opCode;
    vector<string> operand;
    vector<string> lines;
    vector<int> index;
    vector<int> index2;
    parsing x;
    addressList y;
    x.text(file);

    label = x.getLable();
    opCode = x.getOperation();
    operand = x.getOperand();
     cout << label.size() << "=ff=gybig++++++++++++++++++++"<<endl;
                   cout << opCode.size() << "=ff=gybig++++++++++++++++++++"<<endl;
       cout << operand.size() << "=ff=gybig++++++++++++++++++++"<<endl;
    cout<< "   9999999999999999999999999999999999999999999999999999999" <<endl;

    address = y.getAddress(opCode,operand,label);
    cout << address.size() << "=ff=gybig++++++++++++++++++++"<<endl;
    lines = x.getLines();
    index = y.getError();
    index2 = x.getIndex();
    unordered_map<string,pair<string,string>> address_map = y.getmap();
    if(flag1 == 1)
    {
        output1 z;
        z.print(address,label,opCode,operand,address_map);
    }
    else if(flag2 == 1)
    {
        oCode oc;
        oProgram out;
        output2 z;
        vector<string> p1 =  oc.operationBits(opCode);
        vector<string> p3 =  oc.displacement(label,opCode,operand,address);
        vector<string> p2 = oc.addressingModeBits(opCode,operand,label);
        vector<string> f = oc.allCode(p1,p2,p3,opCode,operand);
        vector<string> allText = out.textRecords(address,f,opCode);
        string h = out.headRecord(address,label,opCode);
        string e = out.endRecord(address,f);
        z.print(address,label,opCode,operand,f,allText,h,e,address_map,lines,index,index2);

    }
    else if(flag3 == 1)
    {
      oCode oc;
        oProgram out;
        output3 z;
        vector<string> p1 =  oc.operationBits(opCode);
        vector<string> p3 =  oc.displacement(label,opCode,operand,address);
        vector<string> p2 = oc.addressingModeBits(opCode,operand,label);
        vector<string> f = oc.allCode(p1,p2,p3,opCode,operand);
        vector<string> allText = out.textRecords(address,f,opCode);
        string h = out.headRecord(address,label,opCode);
        string e = out.endRecord(address,f);
        z.print(address,label,opCode,operand,f,allText,h,e,address_map,lines,index,index2);

    }

    cout << " "<<endl;
    system("pause");
    return 0;
}
