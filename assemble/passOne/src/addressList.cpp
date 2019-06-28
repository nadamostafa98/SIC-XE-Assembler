#include "addressList.h"
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include<stdio.h>
#include<string.h>
#include <regex>
#define BASE_16 16
using namespace std;

addressList::addressList()
{
}
vector<int> addressDe;
unordered_map<string,pair<string,string>>address_map;
vector<int> errors;
vector<string> addressList ::getAddress(vector<string> operation, vector <string> operand,vector <string> labels)
{

    string locCtr = "";
    string r = "";
    unordered_map<string,pair<int,string>> m;
    vector<string> m2;
    m2.push_back("BYTE");
    m2.push_back("WORD");
    m2.push_back("RESW");
    m2.push_back("RESB");
    m2.push_back("END");

    // m2[]
    m["ADD"]=make_pair(3,"18");
    m["+ADD"]=make_pair(3,"18");
    m["ADDR"]=make_pair(2,"90");
    m["ADDF"]=make_pair(3,"58");
    m["+ADDF"]=make_pair(4,"58");
    m["AND"]=make_pair(3,"40");
    m["+AND"]=make_pair(4,"40");
    m["CLEAR"]=make_pair(2,"B4");
    m["COMP"]=make_pair(3,"28");
    m["+COMP"]=make_pair(4,"28");
    m["COMPF"]=make_pair(3,"88");
    m["+COMPF"]=make_pair(4,"88");
    m["COMPR"]=make_pair(2,"A0");
    m["DIV"]=make_pair(3,"24");
    m["+DIV"]=make_pair(4,"24");
    m["DIVF"]=make_pair(3,"64");
    m["+DIVF"]=make_pair(4,"64");
    m["DIVR"]=make_pair(2,"9C");
    m["FIX"]=make_pair(1,"C0");
    m["FLOAT"]=make_pair(1,"C4");
    m["HIO"]=make_pair(1,"F4");
    m["J"]=make_pair(3,"3C");
    m["+J"]=make_pair(4,"3C");
    m["JEQ"]=make_pair(3,"30");
    m["+JEQ"]=make_pair(4,"30");
    m["JGT"]=make_pair(3,"34");
    m["+JGT"]=make_pair(4,"34");
    m["JLT"]=make_pair(3,"38");
    m["+JLT"]=make_pair(4,"38");
    m["JSUB"]=make_pair(3,"48");
    m["+JSUB"]=make_pair(4,"48");
    m["LDA"]=make_pair(3,"00");
    m["+LDA"]=make_pair(4,"00");
    m["LDB"]=make_pair(3,"68");
    m["+LDB"]=make_pair(4,"68");
    m["LDCH"]=make_pair(3,"50");
    m["+LDCH"]=make_pair(4,"50");
    m["LDF"]=make_pair(3,"70");
    m["+LDF"]=make_pair(4,"70");
    m["LDL"]=make_pair(3,"08");
    m["+LDL"]=make_pair(4,"08");
    m["LDS"]=make_pair(3,"6C");
    m["+LDS"]=make_pair(4,"6C");
    m["LDT"]=make_pair(3,"74");
    m["+LDT"]=make_pair(4,"74");
    m["LDX"]=make_pair(3,"04");
    m["+LDX"]=make_pair(4,"04");
    m["LPS"]=make_pair(3,"D0");
    m["+LPS"]=make_pair(4,"D0");
    m["MUL"]=make_pair(3,"20");
    m["+MUL"]=make_pair(4,"20");
    m["MULF"]=make_pair(3,"60");
    m["+MULF"]=make_pair(4,"60");
    m["MULR"]=make_pair(2,"98");
    m["OR"]=make_pair(3,"44");
    m["+OR"]=make_pair(4,"44");
    m["RD"]=make_pair(3,"D8");
    m["+RD"]=make_pair(4,"D8");
    m["NORM"]=make_pair(1,"C8");
    m["RMO"]=make_pair(2,"AC");
    m["RSUB"]=make_pair(3,"4C");
    m["+RSUB"]=make_pair(4,"4C");
    m["SHIFTL"]=make_pair(2,"A4");
    m["SHIFTR"]=make_pair(2,"A8");
    m["SIO"]=make_pair(1,"F0");
    m["SSK"]=make_pair(3,"EC");
    m["+SSK"]=make_pair(4,"EC");
    m["STA"]=make_pair(3,"0C");
    m["+STA"]=make_pair(4,"0C");
    m["STB"]=make_pair(3,"78");
    m["+STB"]=make_pair(4,"78");
    m["STCH"]=make_pair(3,"54");
    m["+STCH"]=make_pair(4,"54");
    m["STF"]=make_pair(3,"80");
    m["+STF"]=make_pair(4,"80");
    m["STI"]=make_pair(3,"D4");
    m["+STI"]=make_pair(4,"D4");
    m["STL"]=make_pair(3,"14");
    m["+STL"]=make_pair(4,"14");
    m["STS"]=make_pair(3,"7C");
    m["+STS"]=make_pair(4,"7C");
    m["STSW"]=make_pair(3,"E8");
    m["+STSW"]=make_pair(4,"E8");
    m["STT"]=make_pair(3,"84");
    m["+STT"]=make_pair(4,"84");
    m["STX"]=make_pair(3,"10");
    m["+STX"]=make_pair(4,"10");
    m["SUB"]=make_pair(3,"1C");
    m["+SUB"]=make_pair(4,"1C");
    m["SUBF"]=make_pair(3,"5C");
    m["+SUBF"]=make_pair(4,"5C");
    m["TD"]=make_pair(3,"E0");
    m["+TD"]=make_pair(4,"E0");
    m["TIX"]=make_pair(3,"2C");
    m["+TIX"]=make_pair(4,"2C");
    m["WD"]=make_pair(3,"DC");
    m["+WD"]=make_pair(4,"DC");
    m["SUBR"]=make_pair(2,"94");
    m["SVC"]=make_pair(2,"B0");
    m["TIO"]=make_pair(1,"F8");
    m["TIXR"]=make_pair(2,"B8");
    string start_addr = "";
    vector<string> address;
    bool eqBool = false;
    int y = 0;
    while(operation.at(y) != "START") {
        address.push_back("");
        y++;
    }
    // cout<<operand.at(0)<<"   the operand"<<endl;
  cout<<"starttt address->"<<operand.at(y)<<endl;
    string start = operand.at(y);
    int size_addr = start.length();
    int i = size_addr;
    string z = "";
    while(i < 6) {
        z = z+'0';
        i++;
    }
    start_addr = z+start;
    i = y;
    address.push_back(start_addr);
    locCtr = start_addr;
    if(labels.at(i) != "" && labels.at(i) != "comment" && labels.at(i).at(0) != '.') {
        address_map[labels.at(i)] = make_pair(address.at(i),"relative");
    }
    address.push_back(start_addr);
    regex b("((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?(([A-Z])([0-9]|[A-Z])*)|(\\d+)))\\s*");
    smatch match;
    while(i < operand.size()) {
            string q1 = operation.at(i);
         if(labels.at(i) != "" && labels.at(i) != "comment" && labels.at(i).find("ERROR") == std::string::npos && labels.at(i).at(0) != '.' && q1 !="EQU") {
                      //  cout<<"LLLABEEL-----------------------------------------------------------------------> "+labels.at(i)<<endl;
                //cout<<"adresss back at mapppppppppppppppppppppppppppppppppppppppppp-------------------> "<<address.back().back()<<endl;
            address_map[labels.at(i)] = make_pair(address.back(),"relative");
        }
        locCtr = address.back();
        //cout<<"adresssssss baccccccccccccccccccccccccccccccccccck--->>"<<address.back()<<endl;
        if(labels.at(i).substr(0,4) == "****") {
            cout<<"BARAAAAAAA--->"<<endl;
            //address.push_back(address.back());

           //cout<<"adresss----.>>"<<address.at(i)<<endl;
           //address.pop_back();
            address.push_back(address.back());
            i++;
            continue;
        }
        //cout<<"location counter-->>> "<<locCtr<<" at operation--> "<<operation.at(i)<<"previous address--->> "<<address.back()<<endl;
        //cout<<"mmmmmmmmmmmmmmm"<<endl;

        if (regex_match(operand[i],b)) {
            bool bb = regex_search(operand[i],match,b);
          //  cout<<"REGEXXXXX"<<endl;
            string gp1=match[2];
            string gp2=match[8];
            string expOP = match[7];
            string address1;
            string address2;
            string type1;
            string type2;
            int counter = i-1;
            if(gp1.at(0)=='@'|| gp1.at(0)=='#') {
                gp1= gp1.substr(1,gp1.length());
            }
            while(counter>0) {
                if(gp1 == labels.at(counter)) {
                    auto tofind = address_map.find(labels.at(counter));
                    if(tofind != address_map.end()) {
                        address1 = tofind->second.first;
                        type1 = tofind->second.second;
                        break;
                    }
                }
                counter--;
            }
            counter = i-1;
            if(gp2.at(0)=='@'|| gp2.at(0)=='#') {
                gp2= gp2.substr(1,gp2.length());
            }

            if (!isdigit(gp2.at(0))) {
                while(counter>0) {
                    if(gp2 == labels.at(counter)) {
                        auto tofind = address_map.find(labels.at(counter));
                        if(tofind != address_map.end()) {
                            address2 = tofind->second.first;
                            type2 = tofind->second.second;
                            break;
                        }
                    }
                    counter--;
                }
            } else {
                type2 = "absolute";
                address2 = gp2;
            }
            cout<<"type111 "<<type1<<" type22 "<<type2<<endl;
            int myAddress;
            int int1;
            int int2;
            int1 = hexToDecimal(address1);
            if(!isdigit(gp2.at(0))) {
                int2 = hexToDecimal(address2);
            } else {
                stringstream is (address2);
                is >> int2;
            }
            if(type1 == "absolute" && type2 == "absolute") {
                if(expOP=="+") {
                    myAddress= int1+int2;
                } else if(expOP=="-") {
                    myAddress= int1-int2;
                } else if(expOP=="*") {
                    myAddress= int1*int2;
                } else if(expOP=="/") {
                    myAddress= int1/int2;
                }
                string myAdd = decimalToHex(myAddress);
                if(q1 == "EQU") {
                    //locctr = myAdd;
                    address_map[labels.at(i)] = make_pair(myAdd,"absolute");
                    address.push_back(address.back());
                } else if (q1 == "ORG") {
                    locCtr = myAdd;
                    address.push_back(locCtr);
                }
            } else if (type1 == "relative" && type2 == "relative" && expOP == "-") {
                myAddress= int1-int2;
                string myAdd = decimalToHex(myAddress);
                if(q1 == "EQU") {
                    address_map[labels.at(i)] = make_pair(myAdd,"absolute");
                    address.push_back(address.back());
                } else if (q1 == "ORG") {
                    errors.push_back(i);
                }
            } else if(type1 == "relative" && isdigit(gp2.at(0)) && expOP == "+") {
                cout<<"RELATIVE + NUMBER ----->";
                myAddress= int1+int2;
                string myAdd = decimalToHex(myAddress);
                if(q1 == "EQU") {
                    address_map[labels.at(i)] = make_pair(myAdd,"absolute");
                    address.push_back(address.back());
                } else if (q1 == "ORG") {
                    locCtr = myAdd;
                    address.push_back(locCtr);
                }
            } else if(type1 == "relative" && type2 == "absolute" && (expOP == "-"||expOP == "+")) {
                //cout<<"SA7777777777777777777777777777777777777777777777777777777777"<<endl;
                if(expOP == "-") {
                    myAddress = int1-int2;
                } else {
                    myAddress = int1+int2;
                }
                string myAdd = decimalToHex(myAddress);
                if(q1 == "EQU") {
                    address_map[labels.at(i)] = make_pair(myAdd,"absolute");
                    address.push_back(address.back());
                } else if (q1 == "ORG") {
                    // cout<<"ORGGGGGGGGGGGGGGGGGGGGGGGGGGGG"<<endl;
                    locCtr = myAdd;
                    address.push_back(locCtr);
                    //  cout<<"ORGGGGGGGGGGGGGGGG22222GGGGGGGGGGGG"<<endl;
                }
            } else if(type1 == "absolute" && type2 == "relative" && expOP == "+") {
                myAddress = int1+int2;
                string myAdd = decimalToHex(myAddress);
                if(q1 == "EQU") {
                    address_map[labels.at(i)] = make_pair(myAdd,"absolute");
                    address.push_back(address.back());
                } else if (q1 == "ORG") {
                    locCtr = myAdd;
                    address.push_back(locCtr);
                }
            } else {
                cout<<"ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRORSSS"<<endl;
                errors.push_back(i);
                address.push_back(address.back());
                i++;
                continue;
            }
        }
        //cout<<"3la2"<<endl;
        int s = q1.length();
        char tochar [s];
        for(int y = 0; y < q1.length(); y++) {
            tochar[y] = q1.at(y);
        }
        int result = strcmp(tochar, "comment");
        if(result == 0) {
            //cout << "commenttttttttda5al" << endl;
            address.push_back(address.back());
        } else if(q1 == "BASE") {
            address.push_back(address.back());
        } else {
            // cout << "elseeeeeeda5al" << endl;
            auto search = m.find(q1);
            //  cout << "qqqqqqqqqq" <<q1<< endl;
            if(search != m.end()) {
                // cout<<"mawgodaaa--->"<<q1<<endl;
                // cout<<"mawgodaaa--->"<<q1<<endl;
                int x = search->second.first;
                // cout<<"b333d searchhh"<<endl;
                //////////////////ERRRRORRRRR
                r = theResult(address.back(),x);
                //   cout<<"RRRRRR---->"<<endl;
                int si = r.length();
                //  cout<<"abl while"<<endl;
                string zz = "";
                while(si < 6) {
                    zz = zz+'0';
                    si++;
                }
                r = zz+r;
                //  cout<<"b3d while"<<endl;
                address.push_back(r);
                locCtr = r;
                //    cout<<r<<"   rrrrrr  *****   "<<endl;
            } else if (find(m2.begin(), m2.end(), q1) != m2.end()) {
                // cout << "da5al else if" << endl;
                string operandS = operand .at(i);
                if(q1.at(0) == 'B') {
                    if(operandS.at(0) == 'C') {
                        //  cout << "da5al ccccccc" << endl;
                        r = theResult(address.back(),operandS.length()-3);
                    } else if (operandS.at(0) == 'X') {
                        r = theResult(address.back(),1);
                    }
                } else if (q1.at(0) == 'W') {
                    r = theResult(address.back(),3);
                } else if (q1.at(0) == 'R') {
                    int ss = q1.length();
                    if(q1.at(ss-1)== 'W') {
                        int num ;
                        stringstream is (operandS);
                        is >> num;
                        num = num * 3;
                        r = theResult(address.back(),num);
                    } else if (q1.at(ss-1) == 'B') {
                        int num ;
                        stringstream is (operandS);
                        is >> num;
                        r = theResult(address.back(),num);
                    }
          //          cout<<"doneeee"<<endl;
                }
                int si = r.length();
                string zz = "";
                while(si < 6) {
                    zz = zz+'0';
                    si++;
                }
                r = zz+r;
                address.push_back(r);
                //cout<<"rrrrrrrrrrrrrrr==== "<<endl;
                locCtr = r;
                // cout<<r<<"  rrrr   *****   "<<endl;
            }

            else if (q1 == "ORG" && !regex_match(operand[i],b)) {
                string newAddr = operand.at(i);
                int counter = i-1;
                if(newAddr.at(0)=='@'|| newAddr.at(0)=='#') {
                    newAddr= newAddr.substr(1,newAddr.length());
                }
                while(counter>0) {
                    //        cout<<" gwa while org"<<endl;
                    if(newAddr == labels.at(counter)) {
                        auto tofind = address_map.find(labels.at(counter));
                        if(tofind != address_map.end()) {
                            string x = tofind->second.first;
                            locCtr = x;
                            address.push_back(locCtr);
                            break;
                        }
                    }
                    counter--;
                }
            } else if (q1 == "EQU"&& !regex_match(operand[i],b)) {
                cout<<"EQUATEEEEEEEEEEEE"<<endl;
                address.push_back(locCtr);
                string newAddr = operand.at(i);
                if(newAddr == "*"){
                    address_map[labels.at(i)] = make_pair(address.back(),"relative");
                }else{
                if(newAddr.at(0) == '#' || newAddr.at(0) == '@') {
                    newAddr = newAddr.substr(1,newAddr.length());
                }
                if(isdigit(newAddr.at(0))) {
                    cout<<"new addrrr  "<<newAddr<<endl;
                 int sizeAdd = newAddr.length();
                    int a = sizeAdd;
                    string z = "";
                    while(a < 6) {
                        z = z+'0';
                        a++;
                    }
                    newAddr = z+newAddr;
                    stringstream stream (newAddr);
                    int x = 0;
                    stream >> x;
                    string b = decimalToHex(x);
                    address_map[labels.at(i)] = make_pair(b,"absolute");
                } else {
                    auto tofind = address_map.find(operand.at(i));
                    if(tofind != address_map.end()) {
                        string x = tofind->second.first;
                        address_map[labels.at(i)] = make_pair(x,"relative");
                    }
                }
            }
            }

        }


        //cout<<"xxxxxxxxxxxxx"<<endl;
        locCtr = address.back();
        //cout<<"yyyyyyyyyyyyyyy"<<endl;
       // cout<<"ADDRESSSSS AT THE ENDD --->>"<<address.at(i)<<endl;

        i++;
////////////////////////
    }
    return address;

}
int addressList ::hexToDecimal(string hex)
{
    long long decimalNumber=0;
    // Digits of hexadecimal number system. From 0 to 9 and from A to F
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                          '9', 'A', 'B', 'C', 'D', 'E', 'F'
                         };
    char hexadecimal[6];
    ///////////////////////
    for(int y = 0; y < 6; y++) {
        hexadecimal[y] = hex.at(y);
    }
    //////////////////
    int i, j, power=0, digit;
    for(i=(hex.length())-1; i >= 0; i--) {
        //cout<<"II"<<i;
        // search currect character in hexDigits array
        for(j=0; j<16; j++) {
            //cout<<"JJ"<<j;
            if(hexadecimal[i] == hexDigits[j]) {
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }
    //cout<< "RETURN--DECIMAL---->>"<<decimalNumber<<"<-----";;

    return decimalNumber;
}
string addressList ::theResult(string hex, int theInt)
{
    ///hnaaaa
    int myS = (hexToDecimal(hex));
    string myStr = decimalToHex(hexToDecimal(hex) + theInt );
    return myStr;
}
string addressList ::decimalToHex(int decimal)
{
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                          '9', 'A', 'B', 'C', 'D', 'E', 'F'
                         };
    string toreverse="";
    char hexadecimal[40];
    int index, remaindar;
    index = 0;
    // Convert Decimal Number to Hexadecimal Numbers
    while(decimal != 0) {
        remaindar = decimal % BASE_16;
        hexadecimal[index] = hexDigits[remaindar];
        toreverse+=hexDigits[remaindar];
        decimal /= BASE_16;
        index++;
    }
    hexadecimal[index] = '\0';
    reverse(toreverse.begin(), toreverse.end());
    int si = toreverse.length();
    string zz = "";
    while(si < 6) {
        zz = zz+'0';
        si++;
    }
    toreverse = zz+toreverse;
    return toreverse;
}
vector<int> addressList ::addressDecimal()
{
    return addressDe;
}
unordered_map<string,pair<string,string>> addressList :: getmap()
{
    return address_map;
}
vector<int> addressList :: getError(){
    return errors;
}
