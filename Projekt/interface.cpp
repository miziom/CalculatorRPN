/**
 * \file interface.cpp
 * \brief Plik implementacji modułu \a interface
 *
 * Moduł \a interface zawiera funkcje niezbędne
 * do komunikacji z użytkownikiem poprzez konsolę
 * tekstową
 *
 * \see interface.h
 */

#include "interface.h"
#include "conwerterparser.h"
#include "rpn.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>

void paragraph()
{
    cout<<"Kalkulator ONP"<<endl;
    cout<<"--------------------------"<<endl;
    return;
}
void paragraph1()
{
    paragraph();
    cout<<"P - POWROT      Q -WYJSCIE"<<endl;
    cout<<"--------------------------"<<endl<<endl;
    return;
}

void printMainMenu()
{
    system("cls");
    paragraph();
    cout<<"1. Licz."<<endl;
    cout<<"2. Dodaj funkcje."<<endl;
    cout<<"3. Dodane funkcje"<<endl;
    cout<<"4. Instrukcje i informacje o autorze"<<endl;
    cout<<"5. Wyjscie."<<endl<<endl;
    cout<<"WYBIERZ: ";
    return;
}

int getDecision()  // sprawdza decyzje
{
   std::string x;
   cin>>x;
   if(x.size()!=1)
   {
       return -1; // nie jest pojednynczym znakiem
   }
   if(x[0]< '0' || x[0]> '9')
   {
       return -2; // nie jest liczba
   }
   if(x[0]!= '1' && x[0]!= '2' && x[0]!= '3' && x[0]!= '4' && x[0]!= '5')
   {
       return -3; // nie jest 1, 2, 3, 4, 5
   }
   return std::atoi(x.c_str());  //konwersja string do int
}

void errorHandling(int errorCode)
{
   switch(errorCode)
   {
   case -1:
        std::cout<< "Nie podano dokladnie jednego znaku, wcisnij dowolny kalwisz aby kontynuowac ..."<<std::endl;
   break;
   case -2:
        std::cout<< "Nie podano liczby, wcisnij dowolny kalwisz aby kontynuowac ..."<<std::endl;
   break;
   case -3:
        std::cout<< "Decyzja nie jest wspierana, wcisnij dowolny kalwisz aby kontynuowac ..."<<std::endl;
   break;
   }
   cin.get();
   cin.get();
}

int mainMenu()
{
    for(;;)
    {
        printMainMenu();
        int decision = getDecision();
        if(decision<0)
        {
            errorHandling(decision);
        }
        else
        {
            return decision;
        }
    }
}

int BackOrExitDecision(std::string inputString)  //decyzja powrotu lub wyjscia
{
    if((inputString[0]=='p' && inputString.size()==1) || (inputString[0]=='P' && inputString.size()==1))
        {
            return -1;
        }
    else if ((inputString[0]=='q' && inputString.size()==1) || (inputString[0]=='Q' && inputString.size()==1))
        {
            return -2;
        }
    else
        {
            return -3;
        }
}

int CountBlockcase1(std::string &inputString)  //decyzja powrotu, wyjscia, czy liczenia dalej
{
    system("cls");
    paragraph1();
    std::cout<<"LICZ"<<std::endl;
    std::cout<<"Podaj wyrazenie:"<<std::endl;
    do
    {
        std::getline(std::cin,inputString);
    }
    while(inputString=="");
    int a = BackOrExitDecision(inputString);
    return a;
}

int CountBlockcase2(std::string &inputString)  //decyzja powrotu, wyjscia lub dodania nazwy funkcji
{
    system("cls");
    paragraph1();
    std::cout<<"DODAJ FUNKCJE"<<std::endl;
    std::cout<<"Podaj nazwe funkcji lub decyzje P/Q"<<std::endl;
    do
    {
        std::getline(std::cin,inputString);
    }
    while(inputString=="");
    int a = BackOrExitDecision(inputString);
    return a;
}

std:: string ToLower(std::string InputString)  //konwersja do malych liter
{
    for(int i=0; i<InputString.size(); i++)
    {
        InputString[i]=tolower(InputString[i]);
    }
    return InputString;
}

bool firstIsNotNumber(std::string InputString, std::string &FunName)    //sprawdza czy pierwszy
{
    FunName = spaceDelete(InputString);
    FunName = ToLower(FunName);
    if(FunName[0]<'0' || FunName[0]>'9')
        return true;
    else return false;
}

bool isThereTrygFun(std::string InputString)
{
    int tanPos = InputString.find("tan",0);
    int ctanPos = InputString.find("ctan", 0);
    int sinPos = InputString.find("sin",0);
    int cosPos = InputString.find("cos",0);
    if(tanPos != -1 || ctanPos != -1 || sinPos != -1 || cosPos != -1)
        return true;        //zwraca prawde, kiedy znajdzie funkcje
    else return false;  //zwraca false, kiedy nie znajdie funkcjii
}

bool isInList(std::string InputString, FUNQueue *elem)
{
    FUNListElement *current = elem->qfunlist->head;
    if(current==NULL) return false; //zwraca falsz kiedy nie ma listy
    while(current != NULL)
    {
        if(current->functionName == InputString)
            return true;    //zwraca true kiedy napotkal w liscie
        current = current->next;
    }
    return false;   //zwraca false kiedy nie napotkal w liscie
}

int IsItBusy(std::string InputString, FUNQueue *elem)  //sprawdzenie, czy nazwa funkcji nie jest juz zajeta
{
    for(int i=0; i<InputString.size(); i++)
    {
        if(InputString[i] == '+' || InputString[i] == '-' || InputString[i] ==  '*' || InputString[i] == '/' ||
                InputString[i] == '^' || InputString[i] == '#' || InputString[i] == '{' || InputString[i] == '}' ||
                InputString[i] == '(' || InputString[i] == ')' || InputString[i] == ']' || InputString[i] == '[' || InputString[i] == ',' ||
                InputString[i] == ';')
            return -2;  //Kiedy wystepuja znaki specjalne zwraca -2
    }
    if(isThereTrygFun(InputString) == true) //kiedy wystepuje funkcja trygonometryczna to zraca -1
        return -1;
    if(elem!=NULL)  //sprawdza, czy elem nie jest pusty
    {
        if(isInList(InputString,elem)==true)    //kiedy wystepuje w liscie to zwraca -3
            return -3;
        if(isInList(InputString,elem)==false)   //kieddy nie wystepuje w liscie to zwraca -4
            return -4;
    }

    else return -4; //kiedy nie ma nic zlego to zwraca -4
}

std::string FunctionDefining(std::string FunctionName)
{
    system("cls");
    std::string FunctionDef;
    paragraph();
    std::cout<<"DODAJ FUNKCJE"<<std::endl;
    std::cout<<"Nazwe funckji: "<<FunctionName<<std::endl;
    std::cout<<"Zdefiniuj funckje"<<std::endl;    
    std::getline (std::cin,FunctionDef);
    return FunctionDef;
}

void Instruction()
{
    system("cls");
    fstream file;
    file.open("instruction.txt", ios::in);
    std::string line;
    while(getline(file, line))
    {
        cout<<line<<endl;
    }
}

void addedFunctions(FUNQueue *FunList)
{
    system("cls");
    FUNListElement *current = FunList->qfunlist->head;
    if(current == NULL)
        return;
    cout<<"Nazwa \t"<<"Definicja"<<endl;
    while(current != NULL)
    {
        if(current->functionName != "zxcvbnmkljhgfdsaqwertghyfcv")
        {
            cout<<current->functionName<<"\t"<<current->functionDefining<<endl;
        }
        current = current->next;
    }
}
