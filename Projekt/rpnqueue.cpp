/**
 * \file rpnqueue.cpp
 * \brief Plik implementacji modułu \a rpnqueue
 *
 * Moduł \a rpnqueue zawiera definicję struktury RPNQueue
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej w postacji kolejki
 *
 * \see rpnqueue.h
 */

#include "rpnqueue.h"

bool freeQueueRPN(RPNQueue *q)  //zwalnia kolejke
{
    if(q!=NULL)
    {
        delete q;
        q = NULL;
    }
    return true;
}

bool createEmptyQueueRPN(RPNQueue *&q)  //tworzy pusta kolejke
{

    freeQueueRPN(q);
    q = new RPNQueue;
    q->qrpnlist = NULL;
    createEmptyListRPN(q->qrpnlist);
    return true;
}

bool queuePushRPN(RPNQueue *&q, std::string data)  //dodaje do kolejki (na koniec)
{
    if(q==NULL)
    {
        createEmptyQueueRPN(q);
    }
    return addElementByValueRPN(q->qrpnlist,data);
}

std::string queuePopRPN(RPNQueue *&q)  //pobiera z kolejki (pierwszy element)
{
    if(q==NULL) return "";
    std::string res = getFirstElementValueRPN(q->qrpnlist);
    deleteFirstElementRPN(q->qrpnlist);
    return res;
}
