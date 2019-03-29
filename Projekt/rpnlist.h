/**
 * \file rpnlist.h
 * \brief Plik nagłówkowy modułu \a rpnlist
 *
 * Moduł \a rpnlist zawiera definicję struktury RPNListElement oraz RPNList
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej
 *
 * \see rpnlist.cpp
 */

#ifndef RPNLIST_H
#define RPNLIST_H
#include <string>
using namespace std;

/**
 * @brief Element listy dynamicznej Odwrotnej Notacji Polskiej
 *
 * Definicja elementu jednkierunkowej listy ONP
 */
struct RPNListElement
{
    /// Dane w postaci fragmentu wejsciowego stringa,
    /// ktory byl wyrazeniem w postaci algebraicznej
    std::string data;
    /// Wskaznik na nasteoony element listy
    RPNListElement *next;

};

/**
 * @brief Struktura przechowujaca pierwszy element listy Odwrotnej Notacji Polskiej
 *
 * Dzieki wskaznikowi na poczatek list, mamy latwa mozliwosc oblsugi listy,
 * w szybki sposob mozemy dostac sie do elemntu, ktory mamu usunac, czy zmienic
 * oraz dzieki temu mozemy dodac element na koniec, czy poczatek listy
 */
struct RPNList
{
    /// Wskaznik na poczatek listy
    RPNListElement *head;
    /// Liczba elementow w liscie
    int numberOfElements;
};



/**
 * @brief Prcedura usuwa element
 * @param elem - wskaznikd do struktury RPNListElement
 * @return true kiedy sie udalo
 */
bool deleteElementRPN(RPNListElement* elem);

/**
 * @brief Procedura zmienia wartosci elementu
 * @param elem - wskaznik do rekordu RPNListElement
 * @param data - dane
 * @return treu kiedy sie uda
 */
bool changeElementDataRPN(RPNListElement *elem, std::string data);

/**
 * @brief Procedura tworzy element rekordu RPNListElement
 * @param elem - wskaznik do rekordu RPNListElement
 * @param data - dane
 * @return treu kiedy sie uda
 */
bool createElementRPN(RPNListElement *&elem, std::string data);

/**
 * @brief Procedura pobiera wartosc elementu RPNListElement
 * @param elem - wskaznik do rekordu FUNListElement
 * @param value - 'wartosc' danych
 * @return true kiedy sie uda
 */
bool getElementValueRPN(RPNListElement *elem, std::string &value);

/**
 * @brief Procedura laczy elementy
 * @param elem - wskaznik do pierwszego elementu
 * @param next - wskaznik na drugi element
 * @return  true kiedy sie udalo
 */
bool attachElementRPN(RPNListElement *elem, RPNListElement *next);

/**
 * @brief Procedura tworzy miejsce pod liste ONP
 * @param list - wskaznik na liste ONP
 * @return  true kiedy sie uda
 */
bool freeListRPN(RPNList* list);

/**
 * @brief Procedura usuwa ostatni element listy ONP
 * @param list - wskaznik na pierwszy element listy ONP
 * @return  true kiedy sie udalo
 */
bool deleteLastElementRPN(RPNList *list);

/**
 * @brief Procedura usuwa rekurencyjnie liste ONP
 * @param list - wskaznik na poczatek liesty ONP
 * @return  true kiedy sie udalo
 */
bool deleteListRPN(RPNList *list);

/**
 * @brief Procedura tworzy pusta liste ONP
 * @param list - wskaznik na pierwszy element listy ONP
 * @return true kiedy sie udalo
 */
bool createEmptyListRPN(RPNList *&list);

/**
 * @brief Procedura pozwala dostac sie do ostatniego elementu listy ONP
 * @param list - wskaznik na pierwszy element listy ONP
 * @param elem - wskaznik na ostatni element listy ONP
 * @return  true kiedy sie udalo
 */
bool getLastElementRPN(RPNList* list, RPNListElement *&elem);

/**
 * @brief Procedura dodaje element na koniec listy ONP
 * @param list - wskaznik na poczatk listy ONP
 * @param elem - wskaznik do rekordu RPNListElement
 * @return  true kiedy sie udalo
 */
bool addElementRPN(RPNList *list, RPNListElement *elem);

/**
 * @brief Procedura ktora pozwala dodac wartosci do elementu
 * @param list - wskaznik na poczatek listy ONP
 * @param value - dane
 * @return true kiedy sie udalo
 */
bool addElementByValueRPN(RPNList *list, std::string value);

/**
 * @brief Procedura pozwala dostac sie do pierwszego elementu listy funkcji
 * @param list - wskaznik do listy OPN
 * @param elem - wskaznik do pierwszego elementu listy ONP
 * @return  treu kiedy sie udalo
 */
bool getFirstElementRPN(RPNList *list, RPNListElement *&elem);

/**
 * @brief Procedura dodaje na poczatk listy ONP
 * @param list - wskaznik na pierwszy element listy ONP
 * @param elem - wskaznik na element ktory chcemy dodac
 * @return true kiedy sie udalo
 */
bool addBeforeRPN(RPNList *list, RPNListElement *elem);

/**
 * @brief Procedura dodaje wartosci do pierwszego elementu
 * @param list - wskaznik na liste ONP
 * @param value - wartosc
 * @return true kiedy sie udalo
 */
bool addFirstElementByValueRPN(RPNList *list, std::string value);

/**
 * @brief Procedura ktora usuwa pierwszy elememnt list ONP
 * @param list - wskaznik na pierwszy element listy ONP
 * @return true kiedy sie udalo
 */
bool deleteFirstElementRPN(RPNList *list);

/**
 * @brief Procedura pozwala dostac sie do wartosci pierwszego elementu
 * @param list - wskaznik na poczatek listy ONP
 * @return wartosc pierwszego elementu
 */
std::string getFirstElementValueRPN(RPNList *list);

#endif // RPNLIST_H
