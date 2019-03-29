/**
 * \file rpnqueue.h
 * \brief Plik nagłówkowy modułu \a rpnqueue
 *
 * Moduł \a rpnqueue zawiera definicję struktury RPNQueue
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej w postacji kolejki
 *
 * \see rpnqueue.cpp
 */

#ifndef RPNQUEUE_H
#define RPNQUEUE_H
#include "rpnlist.h"

/**
 * @brief Struktura przechowujaca wskaznik do listy Odwrotnej Notacji Polskiej w postaci kolejki
 */
struct RPNQueue
{
    /// Wskaznik na poczatek kolejki
    RPNList* qrpnlist;
};

/**
 * @brief Procedura zwalnia kolejke
 * @param q - wskaznik na poczatek kolejki ONP
 * @return true kiedy sie udalo
 */
bool freeQueueRPN(RPNQueue* q);

/**
 * @brief Procedura tworzy pusta kolejke
 * @param q - wskaznik na poczatek kolejki ONP
 * @return true kiedy sie udalo
 */
bool createEmptyQueueRPN(RPNQueue*& q);

/**
 * @brief Procedura ktora dodaje na koniec kolejki ONP zadana wartosc
 * @param q - wskaznik na poczatek koljeki ONP
 * @param data - wartosc
 * @return true jesli sie uda
 */
bool queuePushRPN(RPNQueue *&q, std::string data);

/**
 * @brief Procedura pozwala dostac sie do ostatniego elementu w kolejce ONP
 * @param q - wskaznik na poczatek kolejki ONP
 * @return wartosc ostatniego elementu
 */
std::string queuePopRPN(RPNQueue *&q);
#endif // RPNQUEUE_H
