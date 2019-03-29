/**
 * \file rpnstack.cpp
 * \brief Plik nagłówkowy modułu \a rpnstack
 *
 * Moduł \a rpnstack zawiera definicję struktury RPNStack
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej w postacji stosu
 *
 * \see rpnstack.h
 */

#include "rpnstack.h"

bool freeStackRPN(RPNStack *q)  //zwalnia stos
{
    if(q!=NULL)
    {
        delete q;
        q = NULL;
    }
    return true;
}


bool createEmptyStackRPN(RPNStack *&q)  //tworzy pusty stos
{

    freeStackRPN(q);
    q = new RPNStack;
    q->srpnlist = NULL;
    createEmptyListRPN(q->srpnlist);
    return true;
}


bool stackPushRPN(RPNStack *&q, std::string data)  //dodaje do stosu (na poczatek)
{
    if(q==NULL)
    {
        createEmptyStackRPN(q);
    }
    return addFirstElementByValueRPN(q->srpnlist,data);
}

std::string stackPopCheck(RPNStack *q)
{
    if(q==NULL) return "";
    std::string res = getFirstElementValueRPN(q->srpnlist);
    return res;
}

bool deleteFirst(RPNStack *&q)
{
    if(q==NULL) return false;
    deleteFirstElementRPN(q->srpnlist);
    return true;
}

std::string stackPopRPN(RPNStack *&q)  //pobiera ze sotsu (pierwszy element)
{
    if(q==NULL) return "";
    std::string res = getFirstElementValueRPN(q->srpnlist);
    deleteFirstElementRPN(q->srpnlist);
    return res;
}
