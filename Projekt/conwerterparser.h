/**
 * \file conwerterparser.h
 * \brief Plik nagłówkowy modułu \a konwertera
 *
 * Moduł \a conwerterparser zawiera funkcje niezbędne,
 * aby konwerter dzialal poprawnie
 *
 * \see conwerterparser.cpp
 */

#ifndef CONWERTERPARSER_H
#define CONWERTERPARSER_H
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include "functionlist.h"
#include "functionqueue.h"
#include "interface.h"
#include "rpn.h"
using namespace std;

/**
 * @brief Procedura lokalizuje miejsce, gdzie wystepuje
 * zadana funkcja
 * @param InputString - wyrazenie w ktorym ma szukac 
 * @param FunName - argument ktory ma znalezc
 * @return pozycja pierwszego argumentu w wyrazeniu
 */
int funPos(std::string InputString, std::string FunName);

/**
 * @brief Procedura lokalizuje pierwszy napotkany lewy nawias
 * od zadanej pozycji
 * @param InputString - wyrazenie w kotrym ma szuakc
 * @param InputPosition - pozycja od ktorej ma zaczac szukac
 * @return pozycja pierwszego lewego nawiasu od zadanej pozucji
 */
int firstRoundBracketPosition(std::string InputString, int InputPosition);

/**
 * @brief Procedura lokalizuje pierwszy napotkany prawy nawias
 * od zadanej pozycji
 * @param InputString - wyrazenie w ktorym ma szukac
 * @param InputPosition - pozycja od ktorej ma zaczac szukac
 * @return  pozycja pierwszego prawego nawiasu od zadanej pozycji 
 */
int secondRoundBracketPosition(std::string InputString, int InputPosition);

/**
 * @brief Procedura zwraca argumenty, ktore maja byc podstawione do funckji
 * @param InputString - string, z ktorego zostana pobrane argumenty
 * @param StartPos - pozycja pierwszgo nawiasu
 * @param FinishPos - pozycja drugiego nawiasu
 * @return Zwraca argumenty odzielone przecinkami
 */
std::string variable(std::string InputString, int StartPos, int FinishPos);

/**
 * @brief Procedura usuwa 'spacje' ze stringa
 * @param InputString - poczatkowy string, z ktorego maja byc usuniete przerwy
 * @return Zwraca poczatkowego stringa bez pustych miejsc ('spacji')
 */
std::string spaceDelete(std::string InputString);

/**
 * @brief Procedura sprawdza, czy w zadanym stringu sa litry
 * @param FunDef - string do sprawdzenia
 * @return true, jesli jest litera
 */
bool isThereLetter(std::string FunDef);

/**
 * @brief Procedura zwraca litere, ktora jest najwczesniej w alfabecie
 * @param FunDef - string, w ktorym ma szukac litery
 * @return litere bedaca najwczesniej w alfabecie
 */
std::string firstLetter(std::string FunDef);

/**
 * @brief Procedura zwraca argument podany liczba
 * @param InputString - string w postaci argumentow
 * w postaci liczb oddzielonych przecinkami 
 * @param OutVariable - argumenty ktore nie zostaly wykorzytstane
 * @return wartosc przyporzadkowana pierwszemu argumentowi
 */
std::string arg(std::string InputString, std::string &OutVariable);

/**
 * @brief Procedura zwraca liczbe argumentow w postaci liter
 * @param FunDef - string w ktorym ma szukac argumentow
 * @return liczba argumentow
 */
int numberOfArg(std::string FunDef);

/**
 * @brief Procedura sprawdza, czy argumenty sa odzielone przecinkiem ','
 * @param varriable - argumenty
 * @return true, kiedy sa odzielone tylko przecinkiem 
 */
bool varriablesComma(std::string varriable);

/**
 * @brief Procedura sprawdza, czy liczba arguemntow zgadza sie
 * z liczba podanych argumentow
 * @param FunDef - zdefiniowana funkcja
 * @param varriables - argumenty
 * @return true, kiedy liczba argumentwo sie zgadza
 */
bool goodNumberOfArg(std::string FunDef, std::string varriables);

/**
 * @brief Procedura zwraca argument napotkanej funkcji tangens
 * @param InputString - string w ktorym ma szukac
 * @param RBracketPos - pozycja prawego nawiasu napotkanego po funkcji tangens
 * @return argument tangensa
 */
std::string tanArg(std::string InputString, int &RBracketPos);

/**
 * @brief Procedura zwraca argument napotkanej funkcji cotangens
 * @param InputString - string w ktorym ma szukac
 * @param RBracketPos - pozycja prawego nawiasu napotkanego po funkcji cotangens
 * @return argument ctg
 */
std::string ctanArg(std::string InputString, int &RBracketPos);

/**
 * @brief Procedura zwraca argument funkcji sinus
 * @param InputString - string w ktorym ma szuakc
 * @param RBracketPos - pozycja prawego nawiasu napotkanego po funkcji sinus
 * @return argument funkcji sinus
 */
std::string sinArg(std::string InputString, int &RBracketPos);

/**
 * @brief Procedura zwraca argument funkcji cosinus
 * @param InputString - string w ktorym ma szukac
 * @param RBracketPos - pozycja prawego nawiasu napotkanego po funkcji cosinus
 * @return argument funkcji cosinus
 */
std::string cosArg(std::string InputString, int &RBracketPos);

/**
 * @brief Procedura sprawdza poprawnosc zapisu argumentu funckji trygonometrycznej
 * @param InputString - string w ktorym ma szukac
 * @param FunPos - pozycja startowa
 * @return true kiedy argument jest poprawny
 */
bool afterTrygFun(std::string InputString, int FunPos);

/**
 * @brief Procedura zwraca wartosc tangensa dla danej wartosci katowej
 * @param InputString - argument tangesna
 * @return wartosc tan dla argumentu
 */
int tangens(std::string &InputString);

/**
 * @brief Procedura zwraca wartosc sinusa dla danej wartosci katowej
 * @param InputString - argument sin
 * @return wartosc sin dla argumentu
 */
int sinus(std::string &InputString);

/**
 * @brief Procedura zwraca wartosc cosinusa dla danej wartosci katowej
 * @param InputString - argument cosinusa
 * @return  wartosc cos dla argumentu
 */
int cosinus(std::string &InputString);

/**
 * @brief Procedura zwraca wartosc ctangensa dla danej wartosci katowej
 * @param InputString - argument ctg
 * @return wartosc ctg dla argumentu
 */
int ctangens(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane 'sin'
 * wyrazeniem #0#
 * @param InputString - string w ktorym ma zastepowac
 * @return true kiedy wykona
 */
bool sinHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane 'cos'
 * wyrazeniem #1#
 * @param InputString - string w ktorym ma zastepowac
 * @return true kiedy wykona
 */
bool cosHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane 'tan'
 * wyrazeniem #2#
 * @param InputString - string w ktorym ma zastepowac
 * @return true kiedy wykona
 */
bool tanHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane 'ctan'
 * wyrazeniem #3#
 * @param InputString - string w ktorym ma zastepowac
 * @return true kiedy wykona 
 */
bool ctanHash(std::string &InputString);

/**
 * @brief Procedura zamienia napotkane funckcje trygonometryczne 
 * wartosciami dla zadanych katow
 * @param InputString - string w ktorym ma zamieniac
 * @return treu kiedy wykona
 */
bool TrygFun(std::string &InputString);

/**
 * @brief Procedura zamienia wszystkie napotkane funckje trygonometryczne
 * (sin, cos, tan, ctan) odpowiednimi wyrazeniami (#0#, #1#, #2#, #3#)
 * @param InputString - string w ktorym ma zastepowac
 * @return treu kiedy wykona 
 */
bool hashTrygFun(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane '#0#' wyrazeniem 'sin'
 * @param InputString - string w ktorym ma zamieniac
 * @return true kiedy wykona
 */
bool sinNoHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane '#1#' wyrazeniem wyrazeniem 'cos' 
 * @param InputString - string w ktorym ma zamieniac
 * @return true kiedy wykona
 */
bool cosNoHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane '#2#' wyrazeniem wyrazeniem 'tan'
 * @param InputString - string w ktorym ma zamieniac
 * @return true kiedy wykona
 */
bool tanNoHash(std::string &InputString);

/**
 * @brief Procedura zastepuje kazde napotkane '#3#' wyrazeniem wyrazeniem 'ctan'
 * @param InputString - string w ktorym ma zamieniac
 * @return true kiedy wykona
 */
bool ctanNoHash(std::string &InputString);

/**
 * @brief Procedura zamienia wszystkie napotkane funckje trygonometryczne
 * (#0#, #1#, #2#, #3#) odpowiednimi wyrazeniami (sin, cos, tan, ctan)
 * @param InputString - string w ktorym ma zastepowac
 * @return treu kiedy wykona
 */
bool noHashTrygFun(std::string &InputString);

/**
 * @brief Procedura zamienia podaną funkcje na wyrażenie
 * z podmienionymi zdefiniowanymi liczbami za litery
 * @param InputPhrase - string w ktorym bedzie zamienial
 * @param FunName - nazwa funkcji
 * @param FunDef - definicja funkcji
 * @return treu kiedy sie udalo
 */
bool parser(std::string &InputPhrase, std::string FunName, std::string FunDef);

/**
 * @brief Procedura ktora sprawdzi czy w wyrazeniu wystepuja zdefioniowane funkcje, a jezeli tak,
 * to zamieni je na zdefiniowane wyrazenia z podstawionymi liczbami za zmienne
 * @param elem - wskaznik do listy funkcji
 * @param InputString - string w ktorym ma szukac funkcji
 * @return treu kiedy wykona
 */
bool checkFunctions(FUNQueue *elem, std::string &InputString);

#endif // CONWERTERPARSER_H
