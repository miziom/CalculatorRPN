/**
 * \file rpnlist.cpp
 * \brief Plik nagłówkowy modułu \a rpnlist
 *
 * Moduł \a rpnlist zawiera definicję struktury RPNListElement oraz RPNList
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej
 *
 * \see rpnlist.h
 */

#include "rpnlist.h"
#include <string>
#include <iostream>


bool deleteElementRPN(RPNListElement *elem)        //usun element
{
    if(elem!=NULL)
    {
        delete elem;
        elem = NULL;
    }
    return true;
}

bool changeElementDataRPN(RPNListElement *elem, std::string data)     //zmien wartosc elementu
{
    if(elem==NULL) return false;
    elem->data = data;
    return true;
}


bool createElementRPN (RPNListElement *&elem, std::string data)       //stworz element
{
    deleteElementRPN(elem);
    elem = new RPNListElement;
    elem->next =NULL;
    elem->data="";
   return changeElementDataRPN(elem,data);
}

bool getElementValueRPN(RPNListElement *elem, std::string &value)     //pobierz wartosc elementu
{
    if(elem==NULL) return false;
    value = elem->data;
    return true;
}

bool attachElementRPN(RPNListElement *elem, RPNListElement *next)        //polacz elemeny
{
    if(elem==NULL || next==NULL) return false;
    elem->next = next;
}

bool freeListRPN(RPNList* list)       //stworz "opakowanie"
{
    if(list!=NULL)
    {
        delete list;
        list = NULL;
    }
    return true;
}

bool deleteLastElementRPN(RPNList *list)      //usun ostatni element
{
    if(list->head==NULL) return false;
    else
    {
        RPNListElement *current=list->head;
        while (current->next != NULL)       //dojdz do konca listy i usun
            current = current->next;
    return deleteElementRPN(current);
    }

}

bool deleteListRPN(RPNList *list)     //usun liste
{
    while(deleteLastElementRPN(list)){}
    freeListRPN(list);
    return true;
}

bool createEmptyListRPN(RPNList *&list)       //stworz pusta liste
{
    freeListRPN(list);
    list = new RPNList;
    list->head = NULL;
    list->numberOfElements = 0;
    return true;
}

bool getLastElementRPN(RPNList* list, RPNListElement *&elem)     //dostan sie do ostatniego elementu listy
{
    RPNListElement *current = list->head;
    if(current==NULL) return false;
    while(current->next!=NULL)
        current=current->next;
    elem = current;
    return true;
}

bool addElementRPN(RPNList *list, RPNListElement *elem)      //dodaj element na koniec
{
    if(elem==NULL) return false;
    if(list==NULL)
    {
        createEmptyListRPN(list);
    }
    if(list->numberOfElements==0)
    {
        list->head = elem;
        list->numberOfElements++;
    }
    else
    {
       RPNListElement *tmp;
       getLastElementRPN(list,tmp);
       attachElementRPN(tmp,elem);
       list->numberOfElements++;
    }
    return true;
}

bool addElementByValueRPN(RPNList *list, std::string value)       //dodaj wartosc do elementu
{
    RPNListElement *elem=NULL;
    createElementRPN(elem,value);
    addElementRPN(list,elem);
    return true;
}

bool getFirstElementRPN(RPNList *list, RPNListElement *&elem)       //dostan sie do pierwszego elementu
{
    if(list == NULL) return false;
    else
        elem=list->head;
    return true;
}

bool addBeforeRPN(RPNList *list, RPNListElement *elem)       //dodaj pierwszy element
{
    if(elem==NULL) return false;
    if(list==NULL)
    {
        createEmptyListRPN(list);
    }
    if(list->numberOfElements==0)
    {
        list->head = elem;
        list->numberOfElements++;
    }
    else
    {
        list->numberOfElements++;
       attachElementRPN(elem,list->head);
       list->head = elem;
    }
    return true;
}

bool addFirstElementByValueRPN(RPNList *list, std::string value)      //dodaj wartosc dla pierwszego elementu
{
    RPNListElement *elem=NULL;
    createElementRPN(elem,value);
    addBeforeRPN(list,elem);
    return true;
}

bool deleteFirstElementRPN(RPNList *list)     //usun pierwszy element
{
    if(list->head==NULL) return false;
    else
    {
        RPNListElement *elem=list->head;
        list->head = elem->next;
        deleteElementRPN(elem);
        return true;
    }

}

string getFirstElementValueRPN(RPNList *list)     //dostan sie do wartosci pierwszego elementu
{
    RPNListElement *elem=NULL;
    std::string result;
    if(!getFirstElementRPN(list,elem)) return "";
    if(!getElementValueRPN(elem,result)) return "";
    return result;
}
