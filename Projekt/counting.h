/**
 * \file counting.h
 * \brief Plik nagłówkowy modułu \a obliczeniowego
 *
 * Moduł \a counting zawiera funkcje niezbędne,
 * aby mozna bylo obliczyc wyrazenie skonwertowane do ONP
 *
 * \see counting.cpp
 */

#ifndef COUNTING_H
#define COUNTING_H
#include <string>
#include "rpnqueue.h"
#include "rpnstack.h"
using namespace std;

/**
 * @brief Procedura sprawdza, czy zadane wyrazenie jest operatorem
 * @param oper - wyrazenie, ktore ma sprawdzic
 * @return treu kiedy to operator, false kiedy nie
 */
bool ifOperator(std::string oper);

/**
 * @brief Procedura obliczajaca wyrazenie sprowadzone do postaci
 * Odwrotnej Notacji Polskiej
 * @param elem - wskaznik do kolejki ONP
 * @return wynik wyrazenia
 */
std::string count(RPNQueue *elem);

#endif // COUNTING_H
