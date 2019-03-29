/**
 * \file functionqueue.h
 * \brief Plik nagłówkowy modułu \a functionqueue
 *
 * Moduł \a functionlist zawiera definicję struktury FUNQueue
 * i zestaw funkcji służących do zarządzania listą funkcji w postaci kolejki
 *
 * \see functionlist.cpp
 */

#ifndef FUNCTIONQUEUE_H
#define FUNCTIONQUEUE_H
#include "functionlist.h"
#include <string>
using namespace std;

/**
 * @brief Struktura przechowujaca wskaznik do listy funkcji w postaci kolejki
 */
struct FUNQueue
{
    /// Wskaznik na poczatek kolejki
    FUNList *qfunlist;
};

/**
 * @brief Procedura zwalnia kolejke
 * @param q - wskaznik na poczatek kolejki funkcji
 * @return true kiedy sie udalo
 */
bool freeQueueFUN(FUNQueue *q);

/**
 * @brief Procedura tworzy pusta kolejke funkcji
 * @param q - wskaznik na poczatek kolejki funkcji
 * @return true kiedy sie udalo
 */
bool createEmptyQueueFUN(FUNQueue *&q);

/**
 * @brief Procedura dodaje element o zadanych wartosciach na koniec kolejki funkcji
 * @param q - wskaznik na poczatek kolejki funkcji
 * @param functionNameValue - nazwa funkcji do dodania
 * @param functionDefinigValue - definicja funkcji do dodania
 * @return true kiedy sie uda
 */
bool queuePushFUN(FUNQueue *&q, std::string functionNameValue, std::string functionDefinigValue);

/**
 * @brief Procedura pozwala dostac sie do definicji zadanej funkcji
 * @param q - wskaznik na poczatek kolejki funkcji
 * @param functionNameFind - zadana nazwa funkcji
 * @return definicja zadanej funkcji
 */
std::string queuePopDefiningFUN(FUNQueue *q, std::string functionNameFind);


#endif // FUNCTIONQUEUE_H
