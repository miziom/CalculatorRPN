/**
 * \file rpn.h
 * \brief Plik nagłówkowy modułu \a Odwrotnej Notacji Polskiej
 *
 * Moduł \a rpn zawiera funkcje niezbędne,
 * aby mozna bylo skonwertowac wyrazenie w postacji algebraicznej
 *do wyrazenia ONP wraz ze sprawdzeniem jego poprawnosi
 *
 * \see rpn.cpp
 */

#ifndef RPN_H
#define RPN_H
#include "rpnqueue.h"
#include "rpnstack.h"
#include <string>
#include "conwerterparser.h"
using namespace std;

/**
 * @brief Procedura sprawdza, czy zadany element jest operatorem
 * @param elem - element do sprawdzenia
 * @return true kiedy to jest operator
 */
bool ifOperator(char elem);

/**
 * @brief Procedura sprawdza, czy zadany element jest lewym nawiasem
 * @param elem - element do sprawdznia
 * @return true kiedy to jest lewy nawias
 */
bool ifLBracket(char elem);

/**
 * @brief Procedura sprawdza, czy zadany element jest prawym nawiasem
 * @param elem - element do sprawdzenia
 * @return true kiedy to jest prawy nawias
 */
bool ifRBracket(char elem);

/**
 * @brief Procedura sprawdza, czy zadany element jest operatorem procz minusa
 * @param elem - element do sprawdzenia
 * @return true kiedy jest to operator opocz minusa
 */
bool ifOperatorButMinus(char elem);

/**
 * @brief Procedura sprawdza, czy zadanye wyrazenie to tylko liczba
 * @param InputString - string do sprawdzenia
 * @return treu kiedy jest to liczba
 */
bool NumberCorrect(std::string InputString);

/**
 * @brief Procedura ktora znajduje miejsce, gdzie wystepuje prawy skrajny nawias dla zadanego wyrazenia
 * @param InputString - string ktory ma sprawdzac
 * @param startPos - pozycja do ktorej ma zaczac czukac
 * @param leftBracketPos - pozycja lewego nawiasu
 * @return pozycja prawego skrajnego nawiasu
 */
int rightBracketPos(std::string InputString, int startPos, int &leftBracketPos);

/**
 * @brief Procedura sprawdza czy w wyrazeniu jest prawidlowa liczba nawiasow
 * @param InputString - wyrazenie ktore bedzie sprawdzac
 * @return true kiedy liczba nawiasow jest poprawna
 */
bool goodBracketsNumber(std::string InputString);

/**
 * @brief Procedura nadaje wartosc priorytetu danemu operatoroi
 * @param elem - operator
 * @return wartosc operatora
 */
int setPriority(char elem);

/**
 * @brief Procedura sprawdza, czy wartosc pierwszego operatora jest wieksza od drugiego
 * @param elem1 - pierwszy operator
 * @param elem2 - drugi operator
 * @return true kiedy pierwszy operator ma wieksza wartosc od drugiego
 */
bool priority(char elem1, char elem2);

/**
 * @brief Procedura ktora ustawia operatory w odpowiedniej kolejnosci,
 * porownujac ich priorytety
 * @param stack - wskaznic do stosu Odwrotnej Notacji Polskiej
 * @param queue - wskaznik do kolejki ONP
 * @param elem - operator
 */
void insertAlignedStack(RPNStack *&stack, RPNQueue *&queue, std::string elem);

/**
 * @brief Procedura sprawdzajace bledy przy konwersji wyrazenia algenraicznego
 * do wyrazenia przedstaionego w Odwrotnej Notacji Polskiej
 * @param Queue - wskaznik do kolejki ONP
 * @param InputString - string ktory jest sprawdzany
 * @return 0 kiedy fragment nie sklada sie TYLKO z liczb i operatorow lub kiedy ostantni element to operator
 * 1 kiedy wystapila tylko jedna liczba
 * 2 w kazdym innym przypadku
 */
int CheckOtherErrorRPN(RPNQueue *&Queue, std::string InputString);

/**
 * @brief Procedura sprawdza czy w wyrazeniu wystepuja niedozwolone nawiasu lub separatory
 * @param InputString - string ktory bedzie sprawdzany
 * @return true kiedy wszystko jest w porzadku
 */
bool bracketAndComaCheck(std::string InputString);

/**
 * @brief Procedura sprawdza czy zadany element to cyfra
 * @param elem - element
 * @return true kiedy jest cyfra
 */
bool ifNumber(char elem);

/**
 * @brief Procedura sprawdza, czy sasiadujace ze soba elementy nie sa elementami,
 * ktore nie moga wystepowac po sobie
 * @param elem1 - element pierwszy
 * @param elem2 - element drugi
 * @return true kiedy wszystko jest w porzadku
 */
bool charRpnErrorCheck(char elem1, char elem2);

/**
 * @brief Procedura ktora 'konwertuje' wyrazenie zapisane w postaci algebraicznej do postaci
 * wyrazenia Odwrotnej Notacji Polskiej, sprawdzajac czy zadane wyrazenie w postaci algebraicznej
 * jest poprawnie zapisane. Wyrazenie ONP jest przedstawione w postaci kolejki ONP.
 * @param InputString - wyrazenie w postaci algebraicznej
 * @param Queue - wskaznik do kolejki ONP
 * @return true kiedy udalo sie skonwertowac
 */
bool RPN(std::string InputString, RPNQueue *&Queue);


#endif // RPN_H
