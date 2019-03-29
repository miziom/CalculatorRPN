/**
 * \file functionlist.cpp
 * \brief Plik implementacji modułu \a functionlist
 *
 * Moduł \a functionlist zawiera definicję struktury FUNListElement oraz FUNList
 * i zestaw funkcji służących do zarządzania listą funkcji
 *
 * \see functionlist.h
 */

#include "functionlist.h"
#include <string>
#include <iostream>

bool deleteElementFUN(FUNListElement *elem)       //usun element
{
    if(elem!=NULL)
    {
        delete elem;
        elem = NULL;
    }
    return true;
}

bool changeElementDataFUN(FUNListElement *elem, std::string functionName, std::string functionDefinig)     //zmien wartosc elementu
{
    if(elem==NULL) return false;
    elem->functionName = functionName;
    elem->functionDefining = functionDefinig;
    return true;
}

bool createElementFUN(FUNListElement *&elem, std::string functionName, std::string functionDefinig)       //stworz element
{
    deleteElementFUN(elem);
    elem = new FUNListElement;
    elem->next =NULL;
    elem->functionName = "";
    elem->functionDefining = "";
    return changeElementDataFUN(elem, functionName, functionDefinig);
}

bool getElementValueFUN(FUNListElement *elem, std::string &functionNameValue, std::string &functionDefinigValue, std::string functionName)     //pobierz wartosc elementu
{
    FUNListElement *current = elem;
    if(current==NULL) return false;
    while (current != NULL)
    {
    if(current->functionName == functionName)
    {
        functionNameValue = current->functionName;
        functionDefinigValue = current->functionDefining;
        return true;
    }
    current=current->next;
    return false;
    }
}

bool attachElementFUN(FUNListElement *elem, FUNListElement *next)        //polacz elemeny
{
    if(elem==NULL || next==NULL) return false;
    elem->next = next;
}

bool freeListFUN(FUNList* list)       //stworz "opakowanie"
{
    if(list!=NULL)
    {
        delete list;
        list = NULL;
    }
    return true;
}

bool deleteLastElementFUN(FUNList *list)      //usun ostatni element
{
    if(list->head==NULL) return false;
    else
    {
        FUNListElement *current=list->head;
        while (current->next != NULL)       //dojdz do konca listy i usun
            current = current->next;
    return deleteElementFUN(current);
    }
}

bool deleteListFUN(FUNList *list)     //usun liste
{
    while(deleteLastElementFUN(list)){}
    freeListFUN(list);
    return true;
}

bool createEmptyListFUN(FUNList *&list)       //stworz pusta liste
{
    freeListFUN(list);
    list = new FUNList;
    list->head = NULL;
    list->numberOfElements = 0;
    return true;
}

bool getLastElementFUN(FUNList *list, FUNListElement *&elem)     //dostan sie do ostatniego elementu listy
{
    FUNListElement *current = list->head;
    if(current==NULL) return false;
    while(current->next!=NULL)
        current=current->next;
    elem = current;
    return true;
}

bool addElementFUN(FUNList *list, FUNListElement *elem)      //dodaj element na koniec
{
    if(elem==NULL) return false;
    if(list==NULL)
    {
        createEmptyListFUN(list);
    }
    if(list->numberOfElements==0)
    {
        list->head = elem;
        list->numberOfElements++;
    }
    else
    {
       FUNListElement *tmp;
       getLastElementFUN(list,tmp);
       attachElementFUN(tmp,elem);
       list->numberOfElements++;
    }
    return true;
}

bool addElementByValueFUN(FUNList *list, std::string functionNameValue, std::string functionDefinigValue)       //dodaj wartosc do elementu
{
    FUNListElement *elem=NULL;
    createElementFUN(elem, functionNameValue, functionDefinigValue);
    addElementFUN(list,elem);
    return true;
}

bool getFirstElementFUN(FUNList *list, FUNListElement *&elem)       //dostan sie do pierwszego elementu
{
    if(list == NULL) return false;
    else
        elem=list->head;
    return true;
}

string getElementDefiningValueFUN(FUNList *list, std::string functionNameFind)     //dostan sie do definicji funkcji zadanego elementu
{
    FUNListElement *elem=NULL;
    std::string functionName;
    std::string functionDefining;
    if(!getFirstElementFUN(list,elem)) return "Nie znaleziono funkcji";
    if(!getElementValueFUN(elem, functionName, functionDefining, functionNameFind)) return "Nie znaleziono funkcji";
    return functionDefining;
}
