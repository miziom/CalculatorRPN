/**
 * \file conwerterparser.cpp
 * \brief Plik implementacji modułu \a konwertera
 *
 * Moduł \a conwerterparser zawiera funkcje niezbędne,
 * aby konwerter dzialal poprawnie
 *
 * \see conwerterparser.h
 */

#include "functionlist.h"
#include "functionqueue.h"
#include "conwerterparser.h"
#include "interface.h"
#include "rpn.h"
#include "counting.h"
#include <string>
#include <sstream>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include <cmath>
#include <cstdlib>
#include <iostream>


int funPos(std::string InputString, std::string FunName)    //znajuje pozycje funkcji
{
    return InputString.find(FunName,0);
}
int firstRoundBracketPosition(std::string InputString, int InputPosition)   //znajduje pierwszy nawias dla funkcji
{
    return InputString.find("(",InputPosition);
}
int secondRoundBracketPosition(std::string InputString, int InputPosition)  //znajduje drugi nawias dla funckji
{
    return InputString.find(")", InputPosition);
}


std::string variable(std::string InputString, int StartPos, int FinishPos)  //zwraca argumenty odzielone np. przecinkami
{
    return InputString.substr(StartPos+1,FinishPos-StartPos-1);
}

std::string spaceDelete(std::string InputString)    //usuwa spacje ze stringa
{
    while(InputString.find(" ") != string::npos)    //kiedy znajduje spacje
        InputString.erase(InputString.find(" "), 1);    //usuwa spacje
    return InputString;
}

bool isThereLetter(std::string FunDef)  //czy są w wyrażeniu litery
{
    int counter=0;
    for(int i=0; i<FunDef.size();i++)
    {
        if(FunDef[i]>= 'a' && FunDef[i]<= 'z')
            counter++;
    }
    if(counter == 0)
        return false;
    else
        return true;
}

std::string firstLetter(std::string FunDef)     //zwraca litere będącą najwcześniej w alfabecie
{
    string help="z";

    for(int i=0; i<FunDef.size(); i++)
    {
        if(FunDef[i]>= 'a' && FunDef[i]<= 'z')
        {
            if(FunDef[i]<=help[0])
                help[0]=FunDef[i];
        }
    }
    return help;
}

std::string arg(std::string InputString, std::string &OutVariable)  //zwraca argument podany liczbą
{
    for(int i=0; i<InputString.size();i++)
    {

        int lastPos = InputString.find(",",0);
        if(lastPos != -1)
        {
        std::string arg = InputString.substr(0,lastPos);
        OutVariable = InputString.erase(0,lastPos+1);
        return arg;
        }
        else
        {
            return InputString.substr(0, string::npos);
        }
    }
}

int numberOfArg(std::string FunDef) //zwraca liczbe argumentow
{
    int counter = 0;
    hashTrygFun(FunDef);
    while(isThereLetter(FunDef)==true)
    {
        std::string help = firstLetter(FunDef);
        while(FunDef.find(help) != string::npos)
            FunDef.erase(FunDef.find(help), 1);
        counter++;
    }
    noHashTrygFun(FunDef);
    return counter;
}

bool varriablesComma(std::string varriable)     //sprawdza, czy argumenty na pewno oddziela ','
{
    for(int i=0; i<varriable.size(); i++)
        if(varriable[i] == ';')
            return false;
    else return true;
}

bool goodNumberOfArg(std::string FunDef, std::string varriables) //sprawdza, czy liczba podnanych argumentow odpowiada liczbie zdefiniowanych argumentow
{
    if(varriablesComma(varriables) == false)
        return false;
    int numberArg = numberOfArg(FunDef);
    int counter = 0;
    for(int i=0; i<varriables.size(); i++)
    {
        if(varriables[i] == ',')
            counter++;
    }
    if(counter != numberArg-1)
        return false;
    else return true;
}

std::string tanArg(std::string InputString, int &RBracketPos)
{
    int TanPos = InputString.find("tan",0);
    int LeftBracketPos;
    RBracketPos = rightBracketPos(InputString,TanPos,LeftBracketPos);
    return InputString.substr(LeftBracketPos+1,RBracketPos-LeftBracketPos-1);
}

std::string ctanArg(std::string InputString, int &RBracketPos)
{
    int TanPos = InputString.find("ctan",0);
    int LeftBracketPos;
    RBracketPos = rightBracketPos(InputString,TanPos,LeftBracketPos);
    return InputString.substr(LeftBracketPos+1,RBracketPos-LeftBracketPos-1);
}

std::string sinArg(std::string InputString, int &RBracketPos)
{
    int TanPos = InputString.find("sin",0);
    int LeftBracketPos;
    RBracketPos = rightBracketPos(InputString,TanPos,LeftBracketPos);
    return InputString.substr(LeftBracketPos+1,RBracketPos-LeftBracketPos-1);
}

std::string cosArg(std::string InputString, int &RBracketPos)
{
    int TanPos = InputString.find("cos",0);
    int LeftBracketPos;
    RBracketPos = rightBracketPos(InputString,TanPos,LeftBracketPos);
    return InputString.substr(LeftBracketPos+1,RBracketPos-LeftBracketPos-1);
}

bool afterTrygFun(std::string InputString, int FunPos)
{
    int counterLBracket = 0;
    int counterRBracket = 0;
    int counterOperator = 0;
    for(int i=FunPos; i<InputString.size(); i++)
    {
        if(ifOperator(InputString[i]))
            counterOperator++;
        if(InputString[i] == '(')
            counterLBracket++;
        if(InputString[i] == ')')
            counterRBracket++;
        if(counterOperator>counterLBracket)
            return false;
        if((counterLBracket !=0 && counterRBracket !=0) && (counterLBracket == counterRBracket))
            return true;
    }
    if(counterLBracket == 0)
        return false;
    if(counterRBracket == 0)
        return false;
    return true;
}

int tangens(std::string &InputString)
{
    int PosTan = InputString.find("tan",0);
    while(PosTan!= -1)
    {
        RPNQueue *queue=NULL;
        PosTan = InputString.find("tan",0);
        if(afterTrygFun(InputString,PosTan) == false)
            return 2;
        int RBracketPos=0;
        string Arg = tanArg(InputString, RBracketPos);
        bool rpn = RPN(Arg,queue);
        if(rpn == false)
            return 0;
        if(rpn == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = tan(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
            InputString = InputString.replace(PosTan,RBracketPos-PosTan+1, resultString);
            PosTan = InputString.find("tan",0);
            return 1;
        }

    }
    return 0;
}

int sinus(std::string &InputString)
{
    int PosSin = InputString.find("sin",0);
    while(PosSin!= -1)
    {
        RPNQueue *queue=NULL;
        PosSin = InputString.find("sin",0);
        if(afterTrygFun(InputString, PosSin) == false)
                return 2;
        int RBracketPos=0;
        string Arg = sinArg(InputString, RBracketPos);
        bool rpn = RPN(Arg,queue);
        if(rpn == false)
            return 0;
        if(rpn == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            if(argDouble == 90)
            {
                InputString = InputString.replace(PosSin,RBracketPos-PosSin+1, "1");
                PosSin = InputString.find("sin",0);
                return 1;
            }
            double res = sin(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
           // resultString = resultString.substr(0,resultString.find(".",0)+20);
            InputString = InputString.replace(PosSin,RBracketPos-PosSin+1, resultString);
            PosSin = InputString.find("sin",0);
            return 1;
        }

    }
    return 0;
}

int cosinus(std::string &InputString)
{
    int PosCos = InputString.find("cos",0);
    while(PosCos!= -1)
    {
        RPNQueue *queue=NULL;
        PosCos = InputString.find("cos",0);
        if(afterTrygFun(InputString, PosCos) == false)
                return 2;
        int RBracketPos=0;
        string Arg = cosArg(InputString, RBracketPos);
        bool rpn = RPN(Arg,queue);
        if(rpn == false)
            return 0;
        if(rpn == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            if(argDouble == 90)
            {
                InputString = InputString.replace(PosCos,RBracketPos-PosCos+1, "1");
                PosCos = InputString.find("cos",0);
                return 1;
            }
            double res = cos(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
           // resultString = resultString.substr(0,resultString.find(".",0)+20);
            InputString = InputString.replace(PosCos,RBracketPos-PosCos+1, resultString);
            PosCos = InputString.find("cos",0);
            return 1;
        }

    }
    return 0;
}

int ctangens(std::string &InputString)
{
    int PosCtan = InputString.find("ctan",0);
    while(PosCtan!= -1)
    {
        RPNQueue *queue=NULL;
        PosCtan = InputString.find("ctan",0);
        if(afterTrygFun(InputString, PosCtan) == false)
                return 2;
        int RBracketPos=0;
        string Arg = ctanArg(InputString, RBracketPos);
        bool rpn = RPN(Arg,queue);
        if(rpn == false)
            return 0;
        if(rpn == true)
        {
            Arg = count(queue);
            double argDouble = strtod(Arg.c_str(), NULL);
            double res = 1/tan(argDouble*M_PI/180.0);
            std::ostringstream strs;
            strs << res;
            std::string resultString = strs.str();
           // resultString = resultString.substr(0,resultString.find(".",0)+20);
            InputString = InputString.replace(PosCtan,RBracketPos-PosCtan+1, resultString);
            PosCtan = InputString.find("ctan",0);
            return 1;
        }
    }
    return 0;
}

bool sinHash(std::string &InputString)
{
    int sinPos = InputString.find("sin",0);
    std::string sinHash = "#0#";
    int Npos = InputString.find("n", sinPos);
    while(sinPos != -1)
    {
        InputString = InputString.replace(sinPos, Npos-sinPos+1,sinHash);
        sinPos= InputString.find("sin",0);
    }
    return true;
}

bool cosHash(std::string &InputString)
{
    int cosPos = InputString.find("cos",0);
    std::string cosHash = "#1#";
    int Spos = InputString.find("s", cosPos);
    while(cosPos != -1)
    {
        InputString = InputString.replace(cosPos, Spos-cosPos+1,cosHash);
        cosPos= InputString.find("cos",0);
    }
    return true;
}

bool tanHash(std::string &InputString)
{
    int tanPos = InputString.find("tan",0);
    std::string tanHash = "#2#";
    int Npos = InputString.find("n",tanPos);
    while(tanPos != -1)
    {
        InputString = InputString.replace(tanPos, Npos-tanPos+1,tanHash);
        tanPos= InputString.find("tan",0);
    }
    return true;
}

bool ctanHash(std::string &InputString)
{
    int ctanPos = InputString.find("ctan",0);
    std::string ctanHash = "#3#";
    int Npos = InputString.find("n", ctanPos);
    while(ctanPos != -1)
    {
        InputString = InputString.replace(ctanPos, Npos-ctanPos+1,ctanHash);
        ctanPos= InputString.find("ctan",0);
    }
    return true;
}


bool TrygFun(std::string &InputString)
{
    if(sinus(InputString) == 2)
        return false;
    while(sinus(InputString) == 1);
    if(cosinus(InputString) == 2)
        return false;
    while(cosinus(InputString) == 1);
    if(ctangens(InputString) == 2)
        return false;
    while(ctangens(InputString) == 1);
    if(tangens(InputString) == 2)
        return false;
    while(tangens(InputString) == 1);
    return true;
}

bool hashTrygFun(std::string &InputString)
{
    if(isThereTrygFun(InputString) == false)
        return true;
    if(isThereTrygFun(InputString))
    {
        while(sinHash(InputString) == false);
        while(cosHash(InputString) == false);
        while(tanHash(InputString) == false);
        while(ctanHash(InputString) == false);
        return true;
    }
}

bool sinNoHash(std::string &InputString)
{
    int sinHashPos = InputString.find("#0#",0);
    std::string sin = "sin";
    int Lastpos = InputString.find("#", sinHashPos+1);
    while(sinHashPos != -1)
    {
        InputString = InputString.replace(sinHashPos, Lastpos-sinHashPos+1,sin);
        sinHashPos= InputString.find("#0#",0);
    }
    return true;
}

bool cosNoHash(std::string &InputString)
{
    int cosHashPos = InputString.find("#1#",0);
    std::string cos = "cos";
    int Lastpos = InputString.find("#", cosHashPos+1);
    while(cosHashPos != -1)
    {
        InputString = InputString.replace(cosHashPos, Lastpos-cosHashPos+1,cos);
        cosHashPos= InputString.find("#1#",0);
    }
    return true;
}

bool tanNoHash(std::string &InputString)
{
    int tanHashPos = InputString.find("#2#",0);
    std::string tan = "tan";
    int Lastpos = InputString.find("#",tanHashPos+1);
    while(tanHashPos != -1)
    {
        InputString = InputString.replace(tanHashPos, Lastpos-tanHashPos+1,tan);
        tanHashPos= InputString.find("#2#",0);
    }
    return true;
}

bool ctanNoHash(std::string &InputString)
{
    int ctanHashPos = InputString.find("#3#",0);
    std::string ctan = "ctan";
    int Lastpos = InputString.find("#", ctanHashPos+1);
    while(ctanHashPos != -1)
    {
        InputString = InputString.replace(ctanHashPos, Lastpos-ctanHashPos+1,ctan);
        ctanHashPos= InputString.find("#3#",0);
    }
    return true;
}

bool noHashTrygFun(std::string &InputString)
{
        while(sinNoHash(InputString) == false);
        while(cosNoHash(InputString) == false);
        while(ctanNoHash(InputString) == false);
        while(tanNoHash(InputString) == false);
        return true;
}

bool parser(std::string &InputPhrase, std::string FunName, std::string FunDef) //zamienia podaną funkcje na wyrażenie z podmienionymi zdefiniowanymi liczbami za litery
{
    int posFun = funPos(InputPhrase, FunName);  //szuka pozycji funkcji
    int FirstBracket = firstRoundBracketPosition(InputPhrase,posFun);
    int SecondBracket = secondRoundBracketPosition(InputPhrase,posFun);
    std::string varriables = variable(InputPhrase,FirstBracket,SecondBracket);

    if(goodNumberOfArg(FunDef, varriables) == false)
        return false;

    while(isThereLetter(FunDef)==true)
    {
        std::string OutVariables;
        if(varriables.size() !=0)
        {
            std::string letter = firstLetter(FunDef);
            std::string arg1 = arg(varriables,OutVariables);
            varriables = OutVariables;
            while(FunDef.find(letter) != string::npos)
                FunDef.replace(FunDef.find(letter,0),1,arg1);

        }
    }
    InputPhrase = InputPhrase.replace(posFun,SecondBracket-posFun+1,"("+FunDef+")");
    return true;
}

bool checkFunctions(FUNQueue *elem, std::string &InputString)    //true kiedy sie udalo, false kiedy napotkalo trudnosci w wywolanie funkcji
{

    FUNListElement *current = elem->qfunlist->head;
    if(current==NULL) return true;
    while(current != NULL)
    {
        std::string funName = current->functionName;
        int pos = InputString.find(funName,0);
        while(pos != -1)
        {
            std::string FunName = current->functionName;
            std::string FunDef = current->functionDefining;
            if(checkFunctions(elem, FunDef))
            {
            hashTrygFun(FunDef);
            if(parser(InputString,FunName,FunDef) == false)
            {
                noHashTrygFun(FunDef);
                return false;
            }
            noHashTrygFun(FunDef);
            noHashTrygFun(InputString);
            pos = InputString.find(FunName);
            }
            else return false;
        }
        current=current->next;
    }
    return true;
}
