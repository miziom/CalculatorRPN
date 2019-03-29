/**
 * \file rpnstack.h
 * \brief Plik nagłówkowy modułu \a rpnstack
 *
 * Moduł \a rpnstack zawiera definicję struktury RPNStack
 * i zestaw funkcji służących do zarządzania listą Odwrotnej Notacji Polskiej w postacji stosu
 *
 * \see rpnstack.cpp
 */

#ifndef RPNSTACK_H
#define RPNSTACK_H
#include "rpnlist.h"

/**
 * @brief Struktura przechowujaca wskaznik do listy Odwrotnej Notacji Polskiej w postaci stosu
 */
struct RPNStack
{
    /// Wskaznik na poczatek stosu
    RPNList* srpnlist;
};

/**
 * @brief Procedura zwalnia stos
 * @param q - wskaznik na stos ONP
 * @return true kiedy sie udalo
 */
bool freeStackRPN(RPNStack *q);

/**
 * @brief Procedura tworzy pusty stos
 * @param q - wskaznik do stosu ONP
 * @return true kiedy sie udalo
 */
bool createEmptyStackRPN(RPNStack *&q);

/**
 * @brief Procedura dodania wartosci na poczatek stosu ONP
 * @param q - wskaznik na poczatek stosy ONP
 * @param data - wartosc
 * @return true kiedy sie udalo
 */
bool stackPushRPN(RPNStack *&q, std::string data);

/**
 * @brief Procedura dostania sie do pierwszego elementu na stosie ONP
 * @param q - wskaznik na pierwszy element stosu ONP
 * @return wartosc pierwszego elementu
 */
std::string stackPopCheck(RPNStack *q);

/**
 * @brief Procedura usuwa pierwszy element stosu ONP
 * @param q - wskaznik na poczatek stosu ONP
 * @return true kiedy sie udalo
 */
bool deleteFirst(RPNStack *&q);

/**
 * @brief Procedura umozliwia dostanie sie do pierwszego elementu
 * w stosie ONP oraz usuniecie tego elementu
 * @param q - wskaznik na pierwszy element stosu ONP
 * @return wartosc pierwszego elementu stosu ONP
 */
std::string stackPopRPN(RPNStack *&q);

#endif // RPNSTACK_H

