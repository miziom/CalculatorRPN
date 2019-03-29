/**
 * \file functionqueue.cpp
 * \brief Plik implementacji modułu \a functionqueue
 *
 * Moduł \a functionlist zawiera definicję struktury FUNQueue
 * i zestaw funkcji służących do zarządzania listą funkcji w postaci kolejki
 *
 * \see functionlist.h
 */

#include "functionqueue.h"
#include "functionlist.h"

bool freeQueueFUN(FUNQueue *q)  //zwalnia kolejke
{
    if(q!=NULL)
    {
        delete q;
        q = NULL;
    }
    return true;
}

bool createEmptyQueueFUN(FUNQueue *&q)  //tworzy pusta kolejke
{

    freeQueueFUN(q);
    q = new FUNQueue;
    q->qfunlist = NULL;
    createEmptyListFUN(q->qfunlist);
    return true;
}

bool queuePushFUN(FUNQueue *&q, std::string functionNameValue, std::string functionDefinigValue)  //dodaje do kolejki (na koniec)
{
    if(q==NULL)
    {
        createEmptyQueueFUN(q);
    }
    return addElementByValueFUN(q->qfunlist, functionNameValue, functionDefinigValue);
}

std::string queuePopDefiningFUN(FUNQueue *q, std::string functionNameFind)  //pobiera z kolejki definicje funkcji zadanego elelemtu zadany element
{
    if(q==NULL) return "";
    std::string res = getElementDefiningValueFUN(q->qfunlist, functionNameFind);
    return res;
}
