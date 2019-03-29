/**
 * \file file.cpp
 * \brief Plik implementacji modułu \a oblsugi plikow
 *
 * Moduł \a file zawiera funkcje niezbędne,
 * aby mozna bylo oblugiwac plii w/w
 *
 * \see file.cpp
 */


#include "file.h"
#include "functionqueue.h"
#include "rpn.h"
#include "counting.h"
#include "conwerterparser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

bool FileGood()      //sprawdza czy plik istnieje
{
    fstream file;
    file.open("function.txt", ios::in);
    if(file.good()==true)           //jezeli jest to zwraca 1
        return true;
    else return false;      //jezeli nie ma to zwraca 0
}

int FirstBracketPos(std::string InputString)    //zwraca pozycje '{'
{
    return InputString.find("{",0);
}

int SecondBracketPos(std::string InputString)       //zwraca pozycje '}'
{
    return InputString.find("}",0);
}

std::string funName(std::string InputString)        //zwraca nazwe funkcji
{
    int BracketPos = FirstBracketPos(InputString);
    return InputString.substr(0, BracketPos);
}

std::string funDefining(std::string InputString)        //zwraca zdefiniowana funkcje
{
    int FirstPos = FirstBracketPos(InputString);
    int SecondPos = SecondBracketPos(InputString);
    return InputString.substr(FirstPos+1, SecondPos-FirstPos-1);
}

void AddFunctionToFile(string NameFunction, string FunctionDefining)
{
    fstream file;
    file.open("function.txt",ios::out | ios::app);
    file<<NameFunction<<"{"<<FunctionDefining<<"}"<<endl;
    file.close();
}

bool parserFile(std::string &FunDef) //uzupelnia podany argument '1'
{
    int argNumber = numberOfArg(FunDef);
    int counter =0;
    while(counter != argNumber)
    {
            std::string letter = firstLetter(FunDef);
            while(FunDef.find(letter) != string::npos)
                FunDef.replace(FunDef.find(letter,0),1,"1.00");
            counter++;
    }
    if(isThereLetter(FunDef))
        return false;
    return true;
}

int tangensFile(std::string &InputString)
{
    int PosTan = InputString.find("tan",0);
    while(PosTan!= -1)
    {
        RPNQueue *queue=NULL;
        PosTan = InputString.find("tan",0);
        int RBracketPos=0;
        if(afterTrygFun(InputString,PosTan) == false)
            return 2;
        string Arg = tanArg(InputString, RBracketPos);
        if(isThereTrygFun(Arg) == true)
            return 0;
        if(parserFile(Arg) == false)
            return 0;
        if(RPN(Arg,queue) == false)
            return 0;
        if(RPN(Arg, queue) == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = tan(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
            InputString = InputString.replace(PosTan,RBracketPos-PosTan+1, resultString);
            PosTan = InputString.find("tan",0);
            //return 1;
        }

    }
    return 1;
}

int sinusFile(std::string &InputString)
{
    int PosSin = InputString.find("sin",0);
    while(PosSin!= -1)
    {
        RPNQueue *queue=NULL;
        PosSin = InputString.find("sin",0);
        int RBracketPos=0;
        if(afterTrygFun(InputString,PosSin) == false)
            return 2;
        string Arg = sinArg(InputString, RBracketPos);
        if(isThereTrygFun(Arg) == true)
            return 0;
        if(parserFile(Arg) == false)
            return 0;

        if(RPN(Arg,queue) == false)
            return 0;
        if(RPN(Arg, queue) == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = sin(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
            InputString = InputString.replace(PosSin,RBracketPos-PosSin+1, resultString);
            PosSin = InputString.find("sin",0);
            //return true;
        }

    }
    return 1;
}

int cosinusFile(std::string &InputString)
{
    int PosCos = InputString.find("cos",0);
    while(PosCos!= -1)
    {
        RPNQueue *queue=NULL;
        PosCos = InputString.find("cos",0);
        int RBracketPos=0;
        if(afterTrygFun(InputString,PosCos) == false)
            return 2;
        string Arg = cosArg(InputString, RBracketPos);
        if(isThereTrygFun(Arg) == true)
            return 0;
        if(parserFile(Arg) == false)
            return 0;
        if(RPN(Arg,queue) == false)
            return 0;
        if(RPN(Arg, queue) == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = cos(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
            InputString = InputString.replace(PosCos,RBracketPos-PosCos+1, resultString);
            PosCos = InputString.find("cos",0);
            //return true;
        }

    }
    return 1;
}

int ctangensFile(std::string &InputString)
{
    int PosCtan = InputString.find("ctan",0);
    while(PosCtan!= -1)
    {
        RPNQueue *queue=NULL;
        PosCtan = InputString.find("ctan",0);
        int RBracketPos=0;
        if(afterTrygFun(InputString,PosCtan) == false)
            return 2;
        string Arg = ctanArg(InputString, RBracketPos);
        if(isThereTrygFun(Arg) == true)
            return 0;
        if(parserFile(Arg) == false)
            return 0;
        if(RPN(Arg,queue) == false)
            return 0;
        if(RPN(Arg, queue) == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = 1/tan(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
            InputString = InputString.replace(PosCtan,RBracketPos-PosCtan+1, resultString);
            PosCtan = InputString.find("ctan",0);
            //return true;
        }

    }
    return 1;
}

bool TrygFunFile(std::string &InputString)
{
    if(sinusFile(InputString) == 2)
        return false;
    while(sinusFile(InputString) != 1);
    if(cosinusFile(InputString) == 2)
        return false;
    while(cosinusFile(InputString) != 1);
    if(ctangensFile(InputString) == 2)
        return false;
    while(ctangensFile(InputString) != 1);
    if(tangensFile(InputString) == 2)
        return false;
    while(tangensFile(InputString) != 1);
    return true;
}

void file(FUNQueue *&List)     //wczytanie funkcji do kolejki
{
    int IsGood = FileGood();
    switch(IsGood)
    {
    case false:
    {
        AddFunctionToFile("zxcvbnmkljhgfdsaqwertghyfcv","");
        fstream file;
        file.open("function.txt", ios::in);
        std::string line;
        while(getline(file, line))
        {
            std::string fName = funName(line);
            std::string fDefining = funDefining(line);
            queuePushFUN(List, fName, fDefining);
        }
        break;
    }
    case true:
    {
        fstream file;
        file.open("function.txt", ios::in);
        std::string line;
        while(getline(file, line))
        {
            std::string fName = funName(line);
            std::string fDefining = funDefining(line);
            queuePushFUN(List, fName, fDefining);
        }
        break;
    }
    }
}

bool checkFunDefFile(std::string FunDef, FUNQueue *FunList)
{
    RPNQueue *Queue = NULL;
    bool ZeroBool = checkFunctions(FunList,FunDef);
    if(ZeroBool == false)
        return false;
    if(ZeroBool)
    {
        bool FirstBool = bracketAndComaCheck(FunDef);
        if(FirstBool == false)
            return false;
        if(FirstBool)
        {
            bool SecondBool = TrygFunFile(FunDef);
            if(SecondBool == false)
                return false;
            if(SecondBool)
            {
                bool ThirdBool = parserFile(FunDef);
                if(ThirdBool == false)
                    return false;
                if(ThirdBool)
                {
                    bool FourthBool = RPN(FunDef, Queue);
                    if(FourthBool == false)
                        return false;
                    if(FourthBool)
                        return true;
                }
            }

        }
    }
}
