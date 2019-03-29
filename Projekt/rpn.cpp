/**
 * \file rpn.cpp
 * \brief Plik implementacji modułu \a Odwrotnej Notacji Polskiej
 *
 * Moduł \a rpn zawiera funkcje niezbędne,
 * aby mozna bylo skonwertowac wyrazenie w postacji algebraicznej
 * do wyrazenia ONP wraz ze sprawdzeniem jego poprawnosci
 *
 * \see counting.h
 */

#include "rpn.h"
#include "rpnqueue.h"
#include "rpnstack.h"
#include "interface.h"
#include "conwerterparser.h"
#include <string>

bool ifOperator(char elem)
{
    return elem == '+' || elem == '-' || elem == '*' || elem == '^' || elem == '/';
}

bool ifLBracket(char elem)
{
    return elem == '(';
}

bool ifRBracket(char elem)
{
    return elem == ')';
}

bool ifOperatorButMinus(char elem)
{
    return elem == '+' || elem == '*' || elem == '^' || elem == '/';
}

bool NumberCorrect(std::string InputString)
{
    int counter = 0;
    for(int i=0; i<InputString.size(); i++)
    {
        if(InputString[i] == ',')
            return false;
        if(InputString[i] == '.')
            counter++;
        if(ifOperatorButMinus(InputString[0]))
            return false;
        if(ifOperator(InputString[i+1]))
            return false;
    }
    if(counter<=1)
        return true;
    else return false;
}

int rightBracketPos(std::string InputString, int startPos, int &leftBracketPos)
{
    int counter = 1;

    leftBracketPos = InputString.find("(",startPos);
    int i = leftBracketPos+1;
    int rightPos = leftBracketPos;
        while(counter != 0)
        {
            if(InputString[i] == '(')
                counter++;
            if(InputString[i] == ')')
                counter--;
            rightPos++;
            i++;
        }
    return rightPos;
}

bool goodBracketsNumber(std::string InputString)
{
    int counter = 0;
    for(int i=0; i<InputString.size(); i++)
    {
        if(InputString[i] == '(')
            counter++;
        if(InputString[i] == ')')
            counter--;
    }
    if(counter != 0)    //zwraca false kiedy nie ma parzystej liczby nawiasow
        return false;
    else return true;
}

int setPriority(char elem)    //nadaje wartosc operatorom
{
    if(elem == '(')
        return 0;
    if(elem == '+')
        return 1;
    if(elem == '-')
        return 2;
    if(elem == '*' || elem == '/')
        return 3;
    if(elem == '^')
        return 4;
}

bool priority(char elem1, char elem2)
{
    return setPriority(elem1)>setPriority(elem2);
}

void insertAlignedStack(RPNStack *&stack, RPNQueue *&queue, std::string elem)
{
    if(elem.size()!=1) return;
    if(stack==NULL)
    {
        stackPushRPN(stack,elem);
        return;
    }
    while(true)
    {
        if(stack->srpnlist->head==NULL)
        {
            stackPushRPN(stack,elem);
            return;
        }

        std::string tmp = stackPopRPN(stack);
        if(tmp.size()!=1) return;
        if(!priority(tmp[0],elem[0]))
        {
            stackPushRPN(stack,tmp);
            stackPushRPN(stack,elem);
            return;
        }
        queuePushRPN(queue,tmp);
    }
}

int CheckOtherErrorRPN(RPNQueue *&Queue, std::string InputString)   //sprawdza inne bledy przed wejsciem do RPN
{
    for(int i=0; i<InputString.size(); i++) //zwraca 0 kiedy fragment nie sklada sie TYLKO z liczb i operatorow
    {
        if(!((InputString[i]>='0' && InputString[i]<='9') || InputString[i] == '.' || InputString[i] == '+' || InputString[i] == '-' ||
             InputString[i] == '*' || InputString[i] == '/' || InputString[i] == '^' || InputString[i] == '(' || InputString[i] == ')'))
            return 0;
    }

    int counterNumber =0;
    int counterOperator = 0;
    for(int i=0; i<InputString.size(); i++) //zwraca 1 kiedy wystapila tylko jedna liczba
    {
        if(InputString[i]>='0' && InputString[i]<='9')
            counterNumber++;
        if(InputString[i] == '.')
            counterOperator++;
    }
    if(counterOperator == 1 &&(counterOperator+counterNumber == InputString.size()))
    {
        queuePushRPN(Queue, InputString);
        return 1;
    }
    if(ifOperator(InputString[InputString.size()-1]))   //kiedy ostatni to operator
        return 0;
    return 3;   //w kazdym innym przypadku zwraca 3
}

bool bracketAndComaCheck(std::string InputString)   //kiedy wystepuja niedozwolone nawiasy lub srednik, zwraca false;
{
    for(int i=0; i<InputString.size(); i++)
    {
        if(InputString[i] == '[' || InputString[i] == ']' || InputString[i] == '{' || InputString[i] == '}' || InputString[i] == ';')
            return false;
    }
    return true;
}

bool ifNumber(char elem)    //zwraca true kiedy jest liczba
{
    if(elem >= '0' && elem <= '9')
        return true;
    return false;
}

bool charRpnErrorCheck(char elem1, char elem2)
{
    if( (ifNumber(elem1) && ifLBracket(elem2)) )    //kiedy po liczbie wystepuje '('
        return false;
    if( (ifOperator(elem1) && ifOperator(elem2)) )      //kiedy wystepuja dwa operatory po sobie
        return false;
    if( (ifLBracket(elem1) && ifRBracket(elem2)) )  //kiedy lewy nawias jest przed prawym
        return false;
    if( (ifRBracket(elem1) && ifLBracket(elem2)))  //kiedy lewy nawias jest po prawym
        return false;
    if( (ifRBracket(elem1) && ifNumber(elem2)) )    //kiedy po prawym nawiasie jest liczba
        return false;
    if( (ifLBracket(elem1) && ifOperatorButMinus(elem2)) )
        return false;
    return true;
}

bool RPN(std::string InputString, RPNQueue *&Queue)
{
    int OtherErrors = CheckOtherErrorRPN(Queue,InputString);
    if(OtherErrors == 0)
        return false;
    if(OtherErrors == 1)
        return true;
    RPNStack *Stack=NULL;
    if(goodBracketsNumber(InputString) == false)
        return false;
    if(isThereLetter(InputString) == true)
        return false;
    bool guard = true;
    int counterStart =0;
    int counterEnd =0;
    if(NumberCorrect(InputString) == true)   //kiedy zczytana liczba jest zapisana poprawnie to dodaje do kolejki
    {
        queuePushRPN(Queue,InputString);
        return true;
    }
    for(int i=0;i<InputString.size();i++)
    {
        char tmp = InputString[i];
        char tmp2 = InputString[i+1];
        if(charRpnErrorCheck(tmp, tmp2) == false)
            return false;
        if(tmp == '-' && guard)
        {
            counterEnd++;
            guard=false;
            continue;
        }
        guard = tmp == '(';
        if(ifOperator(InputString[i]) || ifLBracket(InputString[i]) || ifRBracket(InputString[i]))
        {
            std::string substr;
            if(counterEnd-counterStart>0)
            {
            substr = InputString.substr(counterStart,counterEnd-counterStart);

            if(NumberCorrect(substr) == true)   //kiedy zczytana liczba jest zapisana poprawnie to dodaje do kolejki
                queuePushRPN(Queue,substr);
            else return false;
            }
            if(ifOperator(tmp))
            {
                std::string t;  //konwersja chara do stringa
                t.resize(1);
                t[0] = tmp;
                insertAlignedStack(Stack,Queue, t);
            }
            if(ifLBracket(tmp))
            {
                std::string t;
                t.resize(1);
                t[0] = tmp;
                stackPushRPN(Stack,t);
            }
            else if(ifRBracket(tmp))
            {
                while(stackPopCheck(Stack) != "(")
                {
                    std::string FirstOperator = stackPopRPN(Stack);
                    queuePushRPN(Queue,FirstOperator);
                }
                deleteFirst(Stack);
            }
            substr.clear();
            counterStart = counterEnd+1;
        }
        counterEnd++;
    }
    std::string substr;
    if(counterEnd-counterStart>0)
     {
    substr = InputString.substr(counterStart,counterEnd-counterStart);
    if(NumberCorrect(substr) == false)
        return false;
    queuePushRPN(Queue,substr);
    }
    while(stackPopCheck(Stack) != "(" && Stack->srpnlist->head!=NULL)
    {
        std::string FirstOperator = stackPopRPN(Stack);
        queuePushRPN(Queue,FirstOperator);
    }
    return true;
}
