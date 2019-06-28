#include "../../include/parsing.h"
#include "../../include/output1.h"
#include <iostream>
#include <string>
#include <regex>
#include <bits/stdc++.h>
#include <fstream>
using namespace std ;
string error;
vector<string> instruction;
vector<string> operands;
vector<string> labels;
vector<string> lines;
vector<int> error2_List;

parsing::parsing()
{
}

parsing:: text(string fileName)
{
    int errflag=0;
    vector<string> word1 = {"FIX","FLOAT","HIO","NORM","+RSUB","RSUB","SIO","TIO"};
    vector<string> word2= {"TD","CLEAR","ADD","+ADD","+ADDF","+AND","AND","+COMP","+COMPF","COMP","COMPF","+DIV","+DIVF","DIV","DIVF","+J","+JEQ","+JGT","+JLT","+JSUB","+LDA","+LDB","+LDCH","+LDF","+LDL","+LDS","+LDT","+LDX","+LPS","+MUL","+MULF","+OR","+RD","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","OR","+SUB","RD","SSK","+SSK","+STA","+STB","+STCH","+STF","+STI","+STS","+STL","+STSW","+STT","+STX","+TD","+TIX","+WD","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SVC","TD","TIX","TIXR","WD"};
    vector<string> word2Dash= {"TD","CLEAR","ADD","AND","COMP","COMPF","DIV","DIVF","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","OR","RD","SSK","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SVC","TD","TIX","TIXR","WD"};
    vector<string> word3= {"ADDR","COMPR","DIVR","MULR","RMO","SHIFTL","SHIFTR","SUBR"};
    vector<string> word2forindexing={"ADD","+ADD","+ADDF","+AND","AND","+COMP","+COMPF","COMP","COMPF","+DIV","+DIVF","DIV","DIVF","+LDA","+LDB","+LDCH","+LDF","+LDL","+LDS","+LDT","+LDX","+LPS","+MUL","+MULF","+OR","+RD","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","OR","+SUB","RD","SSK","+SSK","+STA","+STB","+STCH","+STF","+STI","+STS","+STL","+STSW","+STT","+STX","+TD","+TIX","+WD","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SVC","TD","TIX","TIXR","WD"};
    string startAddress="";
    string lineOfCode;
     bool checkEnd= false ;
     int counter =0;
     int check_lb=0;
    instruction.clear();
    operands.clear();
    labels.clear();
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {


            lineOfCode=line.c_str();
lines.push_back(lineOfCode);
    regex b1("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(START)\\s*((\\d|[A-Z])*)\\s*");
    regex b2("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([+]?([A-Z]+))\\s*");
    regex b3("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([+]?([A-Z]+))\\s+((([A-Z])([0-9]|[A-Z])*)|[#](\\d+|(([A-Z])([0-9]|[A-Z])*))|[@](([A-Z])([0-9]|[A-Z])*))\\s*");
    regex b3Dash("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([+]?([A-Z]+))\\s+((([A-Z])([0-9]|[A-Z])*)[,]([X]))\\s*");
    regex b4("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([+]?([A-Z]+))\\s+(([A]|[X]|[L]|[B]|[S]|[T]|[F]|[PC]|[SW])[,]([A]|[X]|[L]|[B]|[S]|[T]|[F]|[PC]|[SW]|\\d+))\\s*");
    regex b5("\\s*([\.]).*");
    regex b6("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(WORD|RESW|RESB)\\s+(\\d+)\\s*");
    regex b7("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(BYTE)\\s+([X]['](..*)[']|[C]['](..*)['])\\s*");
    regex b8("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(END)(\\s+([#]?(([A-Z])([0-9]|[A-Z])*)))?\\s*");
    regex b9("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([J])\\s+([*])\\s*");
    regex b10("\\s*(ORG)\\s+(([@]|[#])?(([A-Z])([0-9]|[A-Z])*))\\s*");
    regex b11("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(EQU)\\s+(([#]|[@])?(([A-Z])([0-9]|[A-Z])*)|([#]|[@])?(\\d+)|[*])\\s*");
    regex b12("\\s*(BASE)\\s+((([A-Z])([0-9]|[A-Z])*)|[#](\\d+|(([A-Z])([0-9]|[A-Z])*))|[@](([A-Z])([0-9]|[A-Z])*))\\s*");
    regex b13 ("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?(EQU)\\s+((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?(([A-Z])([0-9]|[A-Z])*)|(\\d+)))\\s*");
    regex b14 ("\\s*(ORG)\\s+((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?(([A-Z])([0-9]|[A-Z])*)|(\\d+)))\\s*");
    regex b15("\\s*((([A-Z])([0-9]|[A-Z])*)\\s+)?([+]?([A-Z]+))\\s+((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?(([A-Z])([0-9]|[A-Z])*)|(\\d+)))\\s*");

            //Start line
            // string a1 = "   START  000";

            smatch match;

          if ( regex_match(lineOfCode,b1)){
                check_lb=1;
                checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b1);
         string label=match[2];
        string instruct=match[5];
        startAddress=match[6];
        labels.push_back(label);
        instruction.push_back(instruct);
        operands.push_back(startAddress);
           if (!(startAddress.size()<7)){
            error= "****ERROR1:start address is more than 6 characters";
            labels.pop_back();
            labels.push_back(error);

           }
            if (counter!=0){
            error= "****ERROR1:Syntax error";
            labels.pop_back();
            labels.push_back(error);

           }
    }

    //END
 else if ( regex_match(lineOfCode,b8)){
        check_lb=1;
        checkEnd= true ;
        bool bb = regex_search(lineOfCode,match,b8);
        string label=match[2];
        string instruct=match[5];
        string operand=match[7];
        labels.push_back(label);
        instruction.push_back(instruct);
        operands.push_back(operand);
         int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
    }
    //   comment
    else if ( regex_match(lineOfCode,b5)){
        check_lb=1;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b5);
        string comment=match[0];
        labels.push_back(comment);
        instruction.push_back("comment");
        operands.push_back("comment");
    }
    //ORG
   else if ( regex_match(lineOfCode,b10)){
       check_lb=1;
        counter++;
    checkEnd= false ;
    bool bb = regex_search(lineOfCode,match,b10);
    string label={""};
    string instruct=match[1];
    string operand=match[2];
    labels.push_back(label);
    instruction.push_back(instruct);
    operands.push_back(operand);
}

 //ORG   LABEL-+* LABEL
   else if ( regex_match(lineOfCode,b14)){
        counter++;
        check_lb=1;
    checkEnd= false ;
    bool bb = regex_search(lineOfCode,match,b14);
    string label={""};
    string instruct=match[1];
    string operand=match[2];
    labels.push_back(label);
    instruction.push_back(instruct);
    operands.push_back(operand);
}

 //BASE
   else if ( regex_match(lineOfCode,b12)){
        counter++;
        check_lb=1;
    checkEnd= false ;
    bool bb = regex_search(lineOfCode,match,b12);
    string label={""};
    string instruct=match[1];
    string operand=match[2];
    labels.push_back(label);
    instruction.push_back(instruct);
    operands.push_back(operand);
}
    //EQU
      else if ( regex_match(lineOfCode,b11)){
            check_lb=1;
        checkEnd= false ;
        counter++;
        bool bb = regex_search(lineOfCode,match,b11);
        string label=match[2];
        string instruct=match[5];
        string operand=match[6];
        labels.push_back(label);
        instruction.push_back(instruct);
        operands.push_back(operand);
         int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
}
    //EQU   LABEL +*/- LABEL
      else if ( regex_match(lineOfCode,b13)){
        checkEnd= false ;
        check_lb=1;
        counter++;
        bool bb = regex_search(lineOfCode,match,b13);
        string label=match[2];
        string instruct=match[5];
        string operand=match[6];
        labels.push_back(label);
        instruction.push_back(instruct);
        operands.push_back(operand);
         int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
}

    //   Jump  *
    else if ( regex_match(lineOfCode,b9)){
            check_lb=1;
        counter++;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b9);
        string label=match[2];
        string variableType=match[5];
        string value=match[6];
        labels.push_back(label);
        instruction.push_back(variableType);
        operands.push_back(value);
         int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(variableType);
                                  operands.push_back(value);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }

    }
    //word , resw, resb
     else if ( regex_match(lineOfCode,b6)){
            check_lb=1;
            counter++;
            checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b6);
        string label=match[2];
        string variableType=match[5];
        string value=match[6];
        int flagfor=0;
        labels.push_back(label);
        instruction.push_back(variableType);
        operands.push_back(value);
        for (int i=0;i<labels.size()-1;i++){
            if(label==labels[i]){
                error= "****ERROR1:Symbol' " + label + " ' already defined";
                // labels.pop_back();
                 labels.push_back(error);
lines.push_back(lineOfCode);
                 instruction.push_back(variableType);
                 operands.push_back(value);
                 flagfor=1;
            }
            if (flagfor==1){
                break;
            }
        }
        }

    //BYTE

  else if ( regex_match(lineOfCode,b7)){
        check_lb=1;
        counter++;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b7);
        string label=match[2];
        string variableType=match[5];
        string value=match[6];
        int flagfor2=0;
        labels.push_back(label);
        instruction.push_back(variableType);
        operands.push_back(value);
        for (int i=0;i<labels.size()-1;i++){
            if(label==labels[i]){
                error="****ERROR1:Symbol' " + label + " ' already defined";
                 labels.pop_back();
            labels.push_back(error);
lines.push_back(lineOfCode);
            instruction.push_back(variableType);
            operands.push_back(value);
            flagfor2=1;
            }
             if (flagfor2==1){
                break;
            }
        }


    }


  //three word
   // string  a4 = "   SHIFTR   A,X";

    else if (regex_match(lineOfCode,b4)){
            check_lb=1;
            counter++;
            checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b4);

        int flag3word =0;
        string label=match[2];
        string instruct=match[5];
        string operand=match[7];
        string operand1=match[8];
        string operand2=match[9];
           //     cout <<"********"<<instruct<<endl;
        for(int i=0;i<word3.size();i++){
           if (instruct==(word3[i])){
                flag3word=1;
                instruction.push_back(instruct);
                operands.push_back(operand);
                labels.push_back(label);
                if(match[5] ==("SHIFTL") || match[5]== ("SHIFTR")){
                       bool num = false;
                    for (int i =0 ; i<operand2.length();i++){
                        if (!(isdigit(operand2[i]))){
                            num=true;
                            }
                    }
                    if (num){
                        error="****ERROR1:the second operand is not a number";
                         labels.pop_back();
                         labels.push_back(error);

                    }
                }
           }
           if (flag3word==1){
            break;
           }
        }
        if(flag3word==0){
           error="****ERROR1:UNSUPPORTED INSTRUCTION";
            instruction.push_back(instruct);
            operands.push_back(" ");
            labels.push_back(error);
           }

            int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }

    }
     // TWO WORDS OF INDEX   ,X
    else if (regex_match(lineOfCode,b3Dash)){
            check_lb=1;
            counter++;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b3Dash);
        string label=match[2];
        string instruct=match[5];
        string operand=match[7];
        int flag2word=0;
        for(int i=0;i<word2forindexing.size();i++){
           if (instruct==(word2forindexing[i])){
                flag2word=1;
            labels.push_back(label);
            instruction.push_back(instruct);
            operands.push_back(operand);
           }
           if(flag2word==1){
            break;
           }
        }
        if(flag2word==0){
           error="****ERROR1:UNSUPPORTED INSTRUCTION";
           instruction.push_back(instruct);
            operands.push_back(" ");
            labels.push_back(error);
           }
            int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
    }




    //two words regex

   // string  a3 = "   ADD   #66";

    else if (regex_match(lineOfCode,b3)){
            check_lb=1;
        counter++;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b3);
        string label=match[2];
        string instruct=match[5];
        string operand=match[7];
        int flag2word=0;
//        cout <<"==========="<<instruct<<endl;
        for(int i=0;i<word2.size();i++){
           if (instruct==(word2[i])){
                flag2word=1;
                labels.push_back(label);
                instruction.push_back(instruct);
                operands.push_back(operand);
           }
           if(flag2word==1){
            break;
           }
        }

        if(flag2word==0){
           error="****ERROR1:UNSUPPORTED INSTRUCTION";
            instruction.push_back(instruct);
            operands.push_back(" ");
            labels.push_back(error);
           }

          int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
    }
 //two words 2 LABELS

   // string  a3 = "   ADD   MMM-NNN ";
    else if (regex_match(lineOfCode,b15)){
            check_lb=1;
        counter++;
        checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b15);
        string label=match[2];
        string instruct=match[5];
        string operand=match[7];
        int flag2word=0;
//        cout <<"==========="<<instruct<<endl;
        for(int i=0;i<word2Dash.size();i++){
           if (instruct==(word2Dash[i])){
                flag2word=1;
                labels.push_back(label);
                instruction.push_back(instruct);
                operands.push_back(operand);

           }
           if(flag2word==1){
            break;
           }
        }
        if(flag2word==0){
           error="****ERROR1:UNSUPPORTED INSTRUCTION";
            instruction.push_back(instruct);
            operands.push_back(" ");
            labels.push_back(error);
           }
            int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(operand);
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
    }

    //one word parser

     //string  a2 = "   FIX  ";


    else if (regex_match(lineOfCode,b2)){
            check_lb=1;
            counter++;
            checkEnd= false ;
        bool bb = regex_search(lineOfCode,match,b2);
        string label=match[2];
        string instruct=match[5];
        //cout <<"%%%%%%"<<instruct<<endl;

        int flag1word=0;
        for(int i=0;i<word1.size();i++){
           if (instruct==(word1[i])){
                flag1word=1;
            instruction.push_back(instruct);
            labels.push_back(label);
            operands.push_back(" ");
           }
           if(flag1word==1){
            break;
           }
        }
        if(flag1word==0){
           error="****ERROR1:UNSUPPORTED INSTRUCTION";
            instruction.push_back(instruct);
            operands.push_back(" ");
            labels.push_back(error);
           }
            int c=0;
           for (int i=0;i<labels.size()-1;i++){
                      if(!(labels[i]=="") && label==labels[i]){
                                  error="****ERROR1:Symbol' " + label + " ' already defined";
                                  labels.push_back(error);
lines.push_back(lineOfCode);
                                  instruction.push_back(instruct);
                                  operands.push_back(" ");
                                  c=1;
                                  }
                                  if(c==1){
                                    break;
                                  }

                 }
    }




    else {
            counter++;
        error="****ERROR1:Syntax error" ;
            labels.push_back(error);
            operands.push_back("");
            instruction.push_back("");
    }
    }
     if (checkEnd == false){
        error= "****ERROR1: last line is not END" ;
        labels.push_back(error);
        operands.push_back("");
        instruction.push_back("");
     }
    file.close();
    }
    else{
        cout<<"FILE DOES NOT EXIST" <<endl;
     }


    regex v("((([A-Z])([0-9]|[A-Z])+)([,]([X]))?)");
    regex x("((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?((([A-Z])([0-9]|[A-Z])*)|(\\d+))))");
    for (int i=0 ;i<operands.size();i++){
      if (!(instruction[i]=="ORG" || instruction[i]=="EQU")){
            int checkk=0;
            if(regex_match(operands[i],v)){
             smatch match;
             bool bb = regex_search(operands[i],match,v);
             for(int j=0 ;j<labels.size();j++){
                 if(match[2]==labels[j]){
                        checkk=1;
                    }
                }
            if (checkk==0){
             error="****ERROR2:VARIABLES OR LOOPS IS NOT DEFINED  ";
              error2_List.push_back(i);
              labels.push_back(error);
              operands.push_back("");
              instruction.push_back("");
             }
            }
            else if(regex_match(operands[i],x)){
              smatch match;
              bool bb = regex_search(operands[i],match,x);
              for(int j=0 ; j<labels.size();j++){
              if(match[4] == labels[j] ){
                string s=match[10];
                    for(int k=0 ; k<labels.size();k++){

                      if(!(isdigit(s.at(0)))){
                          if(s == labels[k]){
                            checkk=1;
                          }
                       }
                       if(isdigit(s.at(0))){
                            checkk=1;
                       }
                    }
            }
          }
          if (checkk==0){
             error="****ERROR2:VARIABLES OR LOOPS IS NOT DEFINED  ";
              error2_List.push_back(i);
              labels.push_back(error);
              operands.push_back("");
              instruction.push_back("");
             }
        }

      }

    }

    regex vv("(([@]|[#])?(([A-Z])([0-9]|[A-Z])*))");
    regex xx("((([#]|[@])?(([A-Z])([0-9]|[A-Z])*))([-]|[+]|[*]|[\/])(([#]|[@])?((([A-Z])([0-9]|[A-Z])*)|(\\d+))))");
    for (int i=0;i<instruction.size();i++){
        //ORG , EQU LABELS
      if (instruction[i] == ("ORG") ||instruction[i] == ("EQU") ){
        int check =0;
        if(regex_match(operands[i],vv)){
        smatch match;
        bool bb = regex_search(operands[i],match,vv);
          for(int j=0 ; j<i;j++){
            if(match[3] == labels[j]){
                check=1;
            }
          }

          if (check==0){
            error="****ERROR2:LOOP OF ORG OR EQU DOESNOT EXIST ABOVE";
              error2_List.push_back(i);
              labels.push_back(error);
              operands.push_back("");
              instruction.push_back("");
        }
        }
        else if(regex_match(operands[i],xx)){
          smatch match;
          bool bb = regex_search(operands[i],match,xx);
          for(int j=0 ; j<i;j++){
          if(match[4] == labels[j] ){
              string s=match[10];
                    for(int k=0 ; k<i;k++){

                      if(!(isdigit(s.at(0)))){
                          if(s == labels[k]){
                            check=1;
                          }
                       }
                       if(isdigit(s.at(0))){
                            check=1;
                       }
                    }
            }
          }

          if (check==0){
            error="****ERROR2:LOOP OF ORG OR EQU DOESNOT EXIST ABOVE";
              error2_List.push_back(i);
              labels.push_back(error);
              operands.push_back("");
              instruction.push_back("");
        }
        }

      }
    }



}




vector<string> parsing::getLable()
{
    return labels;
}
vector<string> parsing::getOperand()
{
    return operands;
}
vector<string> parsing::getOperation()
{
    return instruction;
}
vector<int> parsing::getIndex()
{
    return error2_List;
}
vector<string> parsing::getLines()
{
    return lines;
}

