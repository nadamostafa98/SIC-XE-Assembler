#include "../../include/oCode.h"
#include <cstring>
#define BASE_16 16
#include <cmath>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
oCode::oCode()
{
}
bool pc = true;
bool f4 = false;
vector<bool> pcrelative;
string oCode::hexToBinary(string hex)
{
    string outputStr = "";
    for(int k = 0; k < hex.length(); k++)
    {
        char n = hex.at(k);
        switch (n)
        {
        case '0':
            outputStr = outputStr+"0000";
            break;
        case '1':
            outputStr = outputStr+"0001";
            break;
        case '2':
            outputStr = outputStr+"0010";
            break;
        case '3':
            outputStr = outputStr+"0011";
            break;
        case '4':
            outputStr = outputStr+"0100";
            break;
        case '5':
            outputStr = outputStr+"0101";
            break;
        case '6':
            outputStr = outputStr+"0110";
            break;
        case '7':
            outputStr = outputStr+"0111";
            break;
        case '8':
            outputStr = outputStr+"1000";
            break;
        case '9':
            outputStr = outputStr+"1001";
            break;
        case 'A':
        case 'a':
            outputStr = outputStr+"1010";
            break;
        case 'B':
        case 'b':
            outputStr = outputStr+"1011";
            break;
        case 'C':
        case 'c':
            outputStr = outputStr+"1100";
            break;
        case 'D':
        case 'd':
            outputStr = outputStr+"1101";
            break;
        case 'E':
        case 'e':
            outputStr = outputStr+"1110";
            break;
        case 'F':
        case 'f':
            outputStr = outputStr+"1111";
            break;
        }
    }
    return outputStr;

}
string oCode::binaryToHex(string binary)
{
    string outputStr = "";
    if(binary == "0000")
    {
        outputStr = "0";
    }
    else if(binary == "0001")
    {
        outputStr = "1";
    }
    else if(binary == "0010")
    {
        outputStr = "2";
    }
    else if(binary == "0011")
    {
        outputStr = "3";
    }
    else if(binary == "0100")
    {
        outputStr = "4";
    }
    else if(binary == "0101")
    {
        outputStr = "5";
    }
    else if(binary == "0110")
    {
        outputStr = "6";
    }
    else if(binary == "0111")
    {
        outputStr = "7";
    }
    else if(binary == "1000")
    {
        outputStr = "8";
    }
    else if(binary == "1001")
    {
        outputStr = "9";
    }
    else if(binary == "1010")
    {
        outputStr = "A";
    }
    else if(binary == "1011")
    {
        outputStr = "B";
    }
    else if(binary == "1100")
    {
        outputStr = "C";
    }
    else if(binary == "1101")
    {
        outputStr = "D";
    }
    else if(binary == "1110")
    {
        outputStr = "E";
    }
    else if(binary == "1111")
    {
        outputStr = "F";
    }
    return outputStr;

}
int oCode :: binaryToDecimal(string binary)
{
    int counter;
    int size;
    double decimal;
    decimal = 0;
    size = binary.length();

    for (int counter = 0; counter < size; counter++)
    {
        if (binary.at(counter) == '1')
            decimal = (decimal + pow(2.0,counter));
        else
            decimal = (decimal + pow(0.0,counter));
    }
    return decimal;

}
vector<string> oCode::operationBits(vector<string> operation)
{
    unordered_map<string,pair<int,string>> m;
    vector<string> m2;
    vector<string> partOne;
    m2.push_back("BYTE");
    m2.push_back("WORD");
    m2.push_back("RESW");
    m2.push_back("RESB");
    m2.push_back("END");
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
    for(int i = 0; i < operation.size(); i++)
    {
        string oper = operation.at(i);

        auto search = m.find(oper);
        string outputStr = "";
        if(search != m.end())
        {
            string result = search->second.second;
            outputStr = hexToBinary(result);
            outputStr.erase(outputStr.length() - 2,outputStr.length());
        }
        partOne.push_back(outputStr);
    }
    return partOne;
}
string oCode::registers(string s)
{
    string out;
    if(s == "A")
    {
        out = "0";
    }
    else if(s == "X")
    {
        out = "1";
    }
    else if(s == "L")
    {
        out = "2";
    }
    else if(s == "B")
    {
        out = "3";
    }
    else if(s == "S")
    {
        out = "4";
    }
    else if(s == "T")
    {
        out = "5";
    }
    else if(s == "F")
    {
        out = "6";
    }
    else if(s == "PC")
    {
        out = "8";
    }
    else if(s == "SW")
    {
        out = "9";
    }
    return out;
}
vector<string> oCode::addressingModeBits(vector<string>operation, vector<string> operand,vector<string> labels)
{
    vector<string> p2;
    for(int k = 0; k < operation.size(); k++)
    {
        bool immediate = false;
        bool format4 = false;
        //bool pCounter = pc;
        string operationStr = operation.at(k);
        if(operationStr == "START" || operationStr == "END" || operationStr == "EQU" || operationStr == "ORG" || operationStr == "BASE" || operationStr == "NOBASE" || operationStr == "RESW" ||operationStr == "RESB" || operationStr =="" ||operationStr ==" "||operationStr =="comment")
        {
            p2.push_back("");
            continue;
        }

        string operandStr = operand.at(k);
        string sub = operandStr;
        int num = operandStr.find(',');
        if(num > -1)
        {
            string sFirst (operandStr.begin(), find(operandStr.begin(), operandStr.end(), ','));
            string sSecond(find(operandStr.begin(), operandStr.end(), ',') + 1, operandStr.end());
            vector<string>::iterator it;
            it = find (labels.begin(), labels.end(), sFirst);
            if(it != labels.end())
            {
                sub = sFirst;
            }
            else
            {
                p2.push_back("register");
                continue;
            }
        }
        string n = "1";
        string i = "1";
        string x = "0";
        string b = "0";
        string p = "0";
        string e = "0";


        if(operandStr != "")
        {
            if(operandStr.at(0) == '#')
            {
                sub = operandStr.substr(1,operandStr.length()-1);
                int k = 0;
                while( k < sub.size())
                {
                    if (!isdigit(sub.at(k)))
                    {
                        break;
                    }
                    k++;
                }
                if(k == sub.size())
                {
                    immediate = true;
                }
                else
                {
                    immediate = false;
                }
            }
        }
        num = operationStr.find("+");
        if(num > -1)
        {
            format4 = true;
            e = "1";
        }
        else
        {
            format4 = false;
        }
        num = operandStr.find("@");
        if(num > -1)
        {
            n = "1";
            i = "0";
            sub = operandStr.substr(1,operandStr.length()-1);
        }
        num = operandStr.find("#");
        if(num > -1)
        {
            n = "0";
            i = "1";
            sub = operandStr.substr(1,operandStr.length()-1);
        }
        num = operandStr.find(",X");
        if(num > -1)
        {
            x = "1";
        }

        if(pcrelative.at(k) == true && immediate == false && format4 == false)
        {
            p = "1";
        }
        else if ( format4 == false && immediate == false)
        {
            b = "1";
        }
        if(sub == "A" || sub == "X" || sub == "L" || sub == "B" || sub == "S" || sub == "T" || sub == "F" || sub == "PC" || sub == "SW")
        {
            p2.push_back("register1");
            continue;
        }

        if(operationStr == "RSUB" || operationStr == "+RSUB")
        {
            b = "0";
            p = "0";
            x = "0";
        }
        string result = n+i+x+b+p+e;

       // cout << result << "   b  "<<b<<"  p  "<<p << "  " << operationStr<<endl;
        p2.push_back(result);
    }
    return p2;

}
vector<string> oCode::displacement(vector<string> labels, vector<string> operation, vector <string> operand, vector<string> address)
{
    vector<string> displace;

    bool pcRelative = true;
    bool format4 = false;
    pc = pcRelative;
    f4 = format4;
    int flagBase = 0;
    for(int i = 0; i < operation.size(); i++)
    {
        string operationStr = operation.at(i);
        if(operationStr == "START" || operationStr == "END" || operationStr == "EQU" || operationStr == "ORG"|| operationStr == "RESW" ||operationStr == "RESB"|| operationStr =="" ||operationStr ==" "||operationStr =="comment")
        {
            displace.push_back("");
            pcrelative.push_back("");
            continue;
        }
        string operandStr = operand.at(i);
        string disp = "";
        // cout << "da5allll      "<< i <<endl;
        if(operandStr != "")
        {
            if(operationStr.at(0)=='+')
            {
                format4 = true;
                pc = pcRelative;
                f4 = format4;
            }
            else
            {
                format4 = false;
                pc = pcRelative;
                f4 = format4;
            }
            if(operationStr == "BASE")
            {
               // cout <<"DA5al BASEEEEEEEEEEEEEEEEEEEEEEEEe"<<endl;
                pcRelative = false;
                pc = pcRelative;
                f4 = format4;
                flagBase = 1;
                displace.push_back("");
                pcrelative.push_back("");
                continue;
            }
            if(operandStr == "NOBASE")
            {
                pcRelative = true;
                pc = pcRelative;
                f4 = format4;
                flagBase = 0;
                displace.push_back("");
                pcrelative.push_back("");
                continue;
            }
            string sub;
            if(operandStr.at(0) == '#')
            {
                sub = operandStr.substr(1,operandStr.length()-1);
                int k = 0;
                while( k < sub.size())
                {
                    if (!isdigit(sub.at(k)))
                    {
                        //  cout << "noooo" <<endl;
                        break;
                    }
                    k++;
                }
                if(k == sub.size())
                {
                    stringstream sStream(sub);
                    int x = 0;
                    sStream >> x;
                    //   pcrelative.push_back(false);
                    disp = decimalToHex(x);
                }
            }
            else if (operandStr.at(0) == '@')
            {
                sub = operandStr.substr(1,operandStr.length()-1);
            }
            else if (operandStr.at(operandStr.length()- 1) == 'X')
            {
                sub = operandStr.substr(0,operandStr.length()-2);
            }
            else
            {
                sub = operandStr;
            }
            if(disp == "")
            {
               // cout<< pc << " pc relativeee" << operationStr << endl;
                if(flagBase == 1)
                {
                    pcRelative = false;
                }
                if(format4 == true)
                {
                    int index = find(labels.begin(), labels.end(), sub) - labels.begin();
                    if(index < labels.size())
                    {
                        string add = address.at(index);
                        int val = hexToDecimal(add);
                        disp = decimalToHex(val);
                        //    pcrelative.push_back(false);
                      //  cout <<hexToDecimal(add)<<"  " <<val << "  " <<disp << "    dispp  " << operandStr << "  "<< add << "  " << address.at(i + 1) << endl;
                    }
                }
                else if(pcRelative == true && format4 == false) //pc relative
                {
                    int index = find(labels.begin(), labels.end(), sub) - labels.begin();
                    if(index < labels.size())
                    {
                        string add = address.at(index);
                        int val = hexToDecimal(add) - hexToDecimal(address.at((i + 1)));
                        if(val < 0)
                        {
                            val = twosComplement(val, 12);
                        }
                        disp = decimalToHex(val);
                        // pcrelative.push_back(true);
                     //   cout <<hexToDecimal(address.at((i + 1)))<<"  " <<hexToDecimal(add)<<"  " <<val << "  " <<disp << "    dispp  " << operationStr << "  "<< add << "  " << address.at(i + 1) << endl;
                    }
                }
                else if (pcRelative == false)
                {

                    int index = find(labels.begin(), labels.end(), sub) - labels.begin();
                    if(index < labels.size())
                    {
                     //   cout<<"DDDDDDDDDDDDDDDDDDDA%ALLLLLLLLL  " << operationStr << "  " << operandStr<<endl;
                        string add = address.at(index);
                        int val = hexToDecimal(add) - hexToDecimal(address.at((i + 1)));
                        int x = val;
                        if(val < 0 && val > -2048)
                        {
                            pcRelative = true;
                            pc = pcRelative;
                            val = twosComplement(val,12);
                        }
                        disp = decimalToHex(val);
                        // int x= al.hexToDecimal(disp);
                   //     cout << x << "  xxxxxxxxx  " <<operationStr<<endl;
                        if (x > 2047 || x < -2048)
                        {
                            pcRelative = false;
                        //    cout<<"INNNNNNNNNNN" << operationStr <<endl;
                            pc = pcRelative;
                            int indexLabel = find(labels.begin(), labels.end(), sub) - labels.begin();
                            string add = address.at(indexLabel);
                            int index = find(operation.begin(), operation.end(), "BASE") - operation.begin();
                            string baseLabel = operand.at(index);
                            int indexLabel2 = find(labels.begin(), labels.end(), baseLabel) - labels.begin();
                            string add2 = address.at(indexLabel2);
                            int val = hexToDecimal(add) - hexToDecimal(add2);
                            if(val < 0)
                            {
                                val = twosComplement(val,12);
                            }
                            disp = decimalToHex(val);
                            if(val > 4095 || val < 0)
                            {
                                disp = "****ERROR";
                            }
                        }
                        else
                        {
                            pcRelative = true;
                            // pcrelative.push_back(true);
                            pc = pcRelative;
                        }
                    }
                }
            }
        }
        pcrelative.push_back(pcRelative);
        displace.push_back(disp);
    }
  //  cout<<pcrelative.size() << " SIZEEE" << displace.size() <<endl;
  /*  for(int l = 0; l < displace.size(); l++)
    {
        cout << displace.at(l) << "    LLLLLLLLLLLLLL   "<< operation.at(l) <<"  " <<pcrelative.at(l)<< endl;
    }*/
    return displace;
}
vector<string> oCode ::allCode(vector<string> p1, vector<string> p2, vector<string> p3,vector<string> operation,vector<string> operand)
{
    bool format4 = false;
    vector<string> finalAns;
    for(int i = 0; i < p1.size(); i++ )
    {
        int num = operation.at(i).find("+");
        if(num > -1)
        {
            format4 = true;
        }
        else
        {
            format4 = false;
        }
        string allStr = "";
        if(operation.at(i) == "BYTE")
        {
           // cout << "BYTEEEEEEEEEEEE" <<endl;
            string operandStr = operand.at(i);
            if(operandStr.at(0) == 'X')
            {
                allStr = operandStr.substr(2,operandStr.length()-3);
            }
            else if(operandStr.at(0) == 'C')
            {
                string s4 = operandStr.substr(2,operandStr.length()-3);
                std::stringstream ss;
                for(int l=0; l<s4.length();l++)
                    ss << std::hex << (int)s4.at(l);
                std::string mystr = ss.str();
                allStr = mystr;
            }
        }
        else if(operation.at(i) == "WORD"){
            string operandStr = operand.at(i);

            int k = 0;
            while( k < operandStr.size())
                {
                    if (!isdigit(operandStr.at(k)))
                    {
                        //  cout << "noooo" <<endl;
                        break;
                    }
                    k++;
                }
                if(k == operandStr.size())
                {
                    stringstream sStream(operandStr);
                    int x = 0;
                    sStream >> x;
                    //   pcrelative.push_back(false);
                    allStr = decimalToHex(x);
                }
        }
        else if(p2.at(i) == "register1")
        {
            string s = registers(operand.at(i));
         //   cout << p1.at(i) << "RRRRRRRRRRRRRRRRR" <<endl;
            string s1 = p1.at(i);
            if(format4 == false)
            {
                s1 = s1 + "0" + "0";
            }
            else
            {
                //format 4 registersss
            }
            string s1Hex1 = s1.substr(0,4);
            string s1Hex2 = s1.substr(4,4);
            s1Hex1 = binaryToHex(s1Hex1);
            s1Hex2 = binaryToHex(s1Hex2);
            allStr = s1Hex1+s1Hex2 + s + "0";
        }
        else if(p2.at(i) == "register")
        {
            string operandStr = operand.at(i);
            int num = operandStr.find(',');
            string sFirst(operandStr.begin(), find(operandStr.begin(), operandStr.end(), ','));
            string sSecond(find(operandStr.begin(), operandStr.end(), ',') + 1, operandStr.end());
            sFirst = registers(sFirst);
            sSecond = registers(sSecond);
            string s1 = p1.at(i);
            if(format4 == false)
            {
                s1 = s1 + "0" + "0";
            }
            else
            {
                //format 4 registersss
            }
            string s1Hex1 = s1.substr(0,4);
            string s1Hex2 = s1.substr(4,4);
            s1Hex1 = binaryToHex(s1Hex1);
            s1Hex2 = binaryToHex(s1Hex2);
            allStr =  s1Hex1+s1Hex2 + sFirst + sSecond;
        }
        else
        {
            allStr = p1.at(i) + p2.at(i);
            cout <<allStr + "  strr"<<endl;
            if(allStr.length() == 12)
            {
                string s1 = allStr.substr(0,4);
                string s1Hex = binaryToHex(s1);
                string s2 = allStr.substr(4,4);
                string s2Hex = binaryToHex(s2);
                string s3 = allStr.substr(8,4);
                string s3Hex = binaryToHex(s3);
                allStr = s1Hex + s2Hex + s3Hex;
                string last = p3.at(i);

                while(last.length() < 3)
                {
                    last = "0"+ last;
                }
                //     cout <<"lasttt  " <<last<<endl;

                if(format4 == true)
                {
                 //   cout<<"F$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
                    while(last.length() < 5)
                    {
                        last = "0"+ last;
                    }
                }
                allStr = allStr + last;
             //   cout <<allStr + "  strr" << s1 << "  " << s2 << "  " << s3<<"  " << last <<endl;

            }
        }
        finalAns.push_back(allStr);
    }
    return finalAns;
}
int oCode ::twosComplement(int dec, int bits)
{
    if(dec >= 0)
    {
        return dec;
    }
    dec = abs(dec);
    int t = 0;
    int start = 1;
    int result = 0;
    while(dec)
    {
        int d = dec % 2;
        dec /= 2;
        if(!d)
            result += start;
        start *= 2;
        t++;
    }
    while(t < bits)
    {
        t++;
        result += start;
        start *= 2;
    }
    return result+1;

}
int oCode ::hexToDecimal(string hex){
    long long decimalNumber=0;
    // Digits of hexadecimal number system. From 0 to 9 and from A to F
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hexadecimal[6];
    ///////////////////////
    for(int y = 0; y < 6;y++){
        hexadecimal[y] = hex.at(y);
    }
    //////////////////
    int i, j, power=0, digit;
    //cout<<"abl el forrr";
    // Converting hexadecimal number to decimal number
    for(i=(hex.length())-1; i >= 0; i--) {
            //cout<<"II"<<i;
        // search currect character in hexDigits array
        for(j=0; j<16; j++){
            //cout<<"JJ"<<j;
            if(hexadecimal[i] == hexDigits[j]){
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }
    //cout<< "RETURN--DECIMAL---->>"<<decimalNumber<<"<-----";;

    return decimalNumber;
}
string oCode ::decimalToHex(int decimal){
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
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

    //strrev(hexadecimal);

   // cout << "Hexadecimal Number : " << hexadecimal;

    return toreverse;
}
