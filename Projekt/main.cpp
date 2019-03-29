/**
 * \mainpage
 * \par Kalkulator ONP
 * \author Mateusz Mizio
 * \version 1.0
 * \par Kontakt:
 * \a mateusz1997-11@o2.pl
*/

/**
 * \file main.cpp
 * \brief Plik z funkcją main(int argc, char* argv[])
 */

#include <iostream>
#include "interface.h"
#include "rpn.h"
#include "rpnlist.h"
#include "rpnqueue.h"
#include "rpnstack.h"
#include "counting.h"
#include "file.h"
#include "conwerterparser.h"
#include "functionlist.h"
#include "functionqueue.h"

using namespace std;

int main(int argc, char *argv[])
{
for(;;)
{
    FUNQueue *FunList=NULL;
    RPNQueue *Queue=NULL;
    file(FunList);
    int FirstDecision = mainMenu();
    std::string CaseOneDecision;
    std::string CaseTwoDecision;
    switch (FirstDecision)
    {
        case 1:
        {
            int decission = CountBlockcase1(CaseOneDecision);
            switch (decission)
            {
                case -1:
                    continue;
                break;
                case -2:
                    exit(0);
                break;
                case -3:
                {
                    CaseOneDecision = ToLower(CaseOneDecision);
                    CaseOneDecision = spaceDelete(CaseOneDecision);
                    bool checkFun = checkFunctions(FunList, CaseOneDecision);
                    if(checkFun == false)
                    {
                        cout<<"Bledne wywolanie funkcji, nacisnij ENTER aby kontynuowac...";
                        cin.get();
                        break;
                    }
                    if(checkFun)
                    {
                        bool ComaDec = bracketAndComaCheck(CaseOneDecision);
                        if(ComaDec == false)
                        {
                            cout<<"Bledny zapis wyrazenia, nacisnij ENTER aby kontynuowac...";
                            cin.get();
                            break;
                        }
                        if(ComaDec)
                        {
                            bool TrygDec = TrygFun(CaseOneDecision);
                            if(TrygDec == false)
                            {
                                cout<<"Blad podania funkcji trygonometrycznej, nacisnij ENTER, aby kontynuowac..";
                                cin.get();
                                break;
                            }
                            if(TrygDec)
                            {
                                if(isThereLetter(CaseOneDecision))
                                {

                                    cout<<"Blad podania wyrazenia, nacisnij ENTER, aby kontynuowac..";
                                    cin.get();
                                    break;
                                }
                                if(isThereLetter(CaseOneDecision) == false)
                                {
                                    bool boolDecision = RPN(CaseOneDecision, Queue);
                                    if(boolDecision == false)
                                    {
                                        cout<<"Bledny zapis wyrazenia, nacisnij ENTER aby kontynuowac...";
                                        cin.get();
                                        break;
                                    }
                                    if(boolDecision == true)
                                    {
                                        cout<<"Wynik: "<<count(Queue)<<endl;
                                        cout<<"Nacisnij ENTER, aby kontynuowac...";
                                        cin.get();
                                        //cin.get();
                                    }
                                }
                            }

                        }
                    }
                }
                break;
            }
        }
            break;

    case 2:
        {
            int decision1 = CountBlockcase2(CaseTwoDecision);
            switch (decision1)
            {
                case -1:
                    continue;
                break;
                case -2:
                    exit(0);
                break;
                case -3:
                {
                    std::string FunName;
                    if(firstIsNotNumber(CaseTwoDecision,FunName) == false)
                    {
                        cout<<"Pierwszy znak nazwy nie moze byc liczba, nacisnij ENTER aby kontynuowac...";
                        cin.get();
                        cin.get();
                        break;
                    }
                    else
                    {
                        int isItBusy = IsItBusy(FunName,FunList);

                        switch(isItBusy)
                        {
                        case -1:
                        {
                            cout<<"W nazwie nie moga wystepowac deklaracje funkcji trygonometryczne ('sin', 'cos', 'tan', 'ctan', nacisnij ENTER, aby kontynuowac...";
                            cin.get();
                            cin.get();
                        } break;
                        case -2:
                        {
                            cout<<"W nazwie nie moga wystepowac znaki specjalne, nacisnij ENTER, aby kontynuowac...";
                            cin.get();
                            cin.get();
                        } break;
                        case -3:
                        {
                            cout<<"Zadeklarowano juz uzywana funkcje, nacisnij ENTER, aby kontunuowac...";
                            cin.get();
                            cin.get();
                        } break;
                        case -4:
                        {
                            std::string FunDefining = FunctionDefining(FunName);
                            FunDefining = spaceDelete(FunDefining);
                            FunDefining = ToLower(FunDefining);;
                            if(checkFunDefFile(FunDefining, FunList) == false)
                            {
                                cout<<"Zle zdefiniowano wyrazenie, nacisni ENTER, aby kontynuowac...";
                                cin.get();
                                cin.get();
                                break;
                            }
                            if(checkFunDefFile(FunDefining, FunList))
                            {
                                AddFunctionToFile(FunName,FunDefining);
                                cout<<"Funckje dodano pomyslnie, wcisnij ENTER, aby kontynuowac ..."<<endl;
                                cin.get();
                                cin.get();
                            }
                        } break;
                        }
                    }
                 }
                break;
            }
        }
            break;
    case 3:
    {
        cout<<"Dodane funckcje:"<<endl;
        addedFunctions(FunList);
        cout<<endl<<"Nacisnij ENTER, aby kontynuowac...";
        cin.get();
        cin.get();
    }break;

    case 4:
    {
        Instruction();
        cout<<endl;
        cout<<"Nacisnij ENTER, aby kontynuowac...";
        cin.get();
        cin.get();
    }break;
    case 5:
            exit(0);
            break;
    }
}
    return 0;
}
