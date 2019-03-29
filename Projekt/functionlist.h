/**
 * \file functionlist.h
 * \brief Plik nagłówkowy modułu \a functionlist
 *
 * Moduł \a functionlist zawiera definicję struktury FUNListElement oraz FUNList
 * i zestaw funkcji służących do zarządzania listą funkcji
 *
 * \see functionlist.cpp
 */

#ifndef FUNCTIONLIST_H
#define FUNCTIONLIST_H
#include <string>
using namespace std;

/**
 * @brief Element listy dynamicznej funckji
 *
 *Definicja elementu jednokierunowej listy funkcji
 */
struct FUNListElement
{
    /// Nazwa funkcji
    std::string functionName;
    /// Definicja funkcji
    std::string functionDefining;
    ///Wskaznik na nastepny element listy
    FUNListElement *next;

};

/**
 * @brief Struktura przechowujaca pierwszy element listy funckji
 *
 * Dzieki wskaznikowi na poczatek list, mamy latwa mozliwosc oblsugi listy,
 * w szybki sposob mozemy dostac sie do elemntu, ktory mamu usunac, czy zmienic
 * oraz dzieki temu mozemy dodac element na koniec, czy poczatek listy
 */
struct FUNList
{
    /// Wskaznik na poczatek listy
    FUNListElement *head;
    /// Liczba elementow w liscie
    int numberOfElements;
};

/**
 * @brief Prcedura usuwa element
 * @param elem - wskaznikd do struktury FUNListElement
 * @return true kiedy sie udalo
 */
bool deleteElementFUN(FUNListElement *elem);

/**
 * @brief Procedura zmienia wartosc elementu
 * @param elem - wskaznik do rekordu FUNListElement gdzie ma byc zmiana
 * @param functionName - nazwa funkcji
 * @param functionDefinig - definicja funkcji
 * @return  treu kiedy sie udalo
 */
bool changeElementDataFUN(FUNListElement *elem, std::string functionName, std::string functionDefinig);

/**
 * @brief Procedura tworzy element rekordu FUNListElement
 * @param elem - wskaznik do rekordu FUNListElement
 * @param functionName - nazwa funkcji
 * @param functionDefinig - definicja funkcji
 * @return true kiedy sie udalo
 */
bool createElementFUN(FUNListElement *&elem, std::string functionName, std::string functionDefinig);

/**
 * @brief Procedura pobiera wartosc elementu FunListElement
 * @param elem - wskaznik do rekordu FUNListElement
 * @param functionNameValue - 'wartosc' nazwy funkcji
 * @param functionDefinigValue - 'wartosc' definicji funkcji
 * @param functionName - nazwa funkcji ktorej chcemy wartosci
 * @return true kiedy sie udalo
 */
bool getElementValueFUN(FUNListElement *elem, std::string &functionNameValue, std::string &functionDefinigValue, std::string functionName);

/**
 * @brief Procedura laczy elementy
 * @param elem - wskaznik do pierwszego elementu
 * @param next - wskaznik na drugi element
 * @return true kiedy sie udalo
 */
bool attachElementFUN(FUNListElement *elem, FUNListElement *next);

/**
 * @brief Procedura tworzy miejsce pod liste funkcji
 * @param list - wskaznik na pierwszy element listy funkcji
 * @return true kiedy sie udalo
 */
bool freeListFUN(FUNList* list);

/**
 * @brief Procedura usuwa ostatni element listy funkcji
 * @param list - wskaznik na pierwszy element listy funkcji
 * @return true kiedy sie udalo
 */
bool deleteLastElementFUN(FUNList *list);

/**
 * @brief Procedura ktora rekurencyjnie usuwa cala liste funkcji
 * @param list - wskaznik na liste funkcji
 * @return true kiedy sie udalo
 */
bool deleteListFUN(FUNList *list);

/**
 * @brief Procedura tworzy pusta liste funkcji
 * @param list - wskaznik na liste funkcji
 * @return true kiedy sie udalo
 */
bool createEmptyListFUN(FUNList *&list);

/**
 * @brief Procedura ktora pozwala dotrzec do ostatniego elementu listy funkcji
 * @param list  - wskaznik na poczatek listy funkcji
 * @param elem - wskaznik na ostatni element funkcji
 * @return true kiedy sie udalo
 */
bool getLastElementFUN(FUNList *list, FUNListElement *&elem);

/**
 * @brief Procedura ktora pozwala dodac element na koniec listy
 * @param list - wskaznik na poczatek listy funkcji
 * @param elem - wskaznik na rekord FUNListElement
 * @return  true kiedy sie uda
 */
bool addElementFUN(FUNList *list, FUNListElement *elem);

/**
 * @brief Procedura ktora pozwala dodac wartosci do elementu
 * @param list - wskaznik na poczatk listy funkcji
 * @param functionNameValue - nazwa funkcji
 * @param functionDefinigValue - definicja funkcji
 * @return true kiedy sie uda
 */
bool addElementByValueFUN(FUNList *list, std::string functionNameValue, std::string functionDefinigValue);

/**
 * @brief Procedura pozwala dostac sie do pierwszego elementu listy funkcji
 * @param list - wskaznik do listy funkcji
 * @param elem - wskaznik do pierwszego elementu list funkcji
 * @return   true kiedy sie uda
 */
bool getFirstElementFUN(FUNList *list, FUNListElement *&elem);

/**
 * @brief Procedura pozwala dostac sie do definicji porzadanej funkcji
 * @param list - wskaznik na liste funkcji
 * @param functionNameFind - nazwa szukanej funkcji
 * @return definicja szukanej funkcji
 */
string getElementDefiningValueFUN(FUNList *list, std::string functionNameFind);

#endif // FUNCTIONLIST_H
