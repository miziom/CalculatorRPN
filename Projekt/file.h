/**
 * \file file.h
 * \brief Plik nagłówkowy modułu \a oblsugi plikow
 *
 * Moduł \a file zawiera funkcje niezbędne,
 * aby mozna bylo oblugiwac plii w/w
 *
 * \see file.cpp
 */

#ifndef FILE_H
#define FILE_H
#include <string>
#include "functionqueue.h"
using namespace std;


/**
 * @brief Procedura sprawdza czy plik istnieje
 * @return true kiedy istnieje, false jak nie
 */
bool FileGood();

/**
 * @brief Procedura zwraca pozycje lewego nawiasu
 * @param InputString - string w ktorym ma szuakc
 * @return pozycja lewego nawiasu
 */
int FirstBracketPos(std::string InputString);

/**
 * @brief Procedura zwraca pozycje prawego nawiasu
 * @param InputString - string w ktorym ma szuakc
 * @return pozycja prawego nawiasu
 */
int SecondBracketPos(std::string InputString);

/**
 * @brief Procedura zwraca nazwe funkcji zapisanej w pliku
 * @param InputString - string w postaci linii wczytanej z pliku
 * @return nazwa funkcji
 */
std::string funName(std::string InputString);

/**
 * @brief Procedura zwraca definicje funkcji zapisanej w pliku
 * @param InputString - string w postaci lini wczytanej z pliku
 * @return definicja funkcji
 */
std::string funDefining(std::string InputString);

/**
 * @brief Procedura dodaje do pliku nazwe funkcji wraz z jej definicja
 * @param NameFunction - nazwa funkcji
 * @param FunctionDefining - definicja funkcji
 */
void AddFunctionToFile(string NameFunction, string FunctionDefining);

/**
 * @brief Procedura za wszystkie zmienne podstawia wartosc 1
 * @param FunDef - definicja funkcji
 * @return true kiedy zamiana sie powiodla, false kiedy nie
 */
bool parserFile(std::string &FunDef);

/**
 * @brief Procedura sprawdza, czy argument tangens zostal zdefioniowany prawidlowo,
 * po przez obliczenie jego wartosci, po przez podstawienie za wszystkie zmienne 1,
 * a nastepnie zamianie funkcji otrzymana wartoscia
 * @param InputString - string w ktorym ma zamieniac
 * @return wartosc tangensa
 */
int tangensFile(std::string &InputString);

/**
 * @brief Procedura sprawdza, czy argument sinus zostal zdefioniowany prawidlowo,
 * po przez obliczenie jego wartosci, ppo przez podstawienie za wszystkie zmienne 1,
 * a nastepnie zamianie funkcji otrzymana wartoscia
 * @param InputString - string w ktorym ma zamieniac
 * @return wartosc sinusa
 */
int sinusFile(std::string &InputString);

/**
 * @brief Procedura sprawdza, czy argument cosinus zostal zdefioniowany prawidlowo,
 * po przez obliczenie jego wartosci, ppo przez podstawienie za wszystkie zmienne 1,
 * a nastepnie zamianie funkcji otrzymana wartoscia
 * @param InputString - string w ktorym ma zamieniac
 * @return wartosc cosinusa
 */
int cosinusFile(std::string &InputString);

/**
 * @brief Procedura sprawdza, czy argument ctan zostal zdefioniowany prawidlowo,
 * po przez obliczenie jego wartosci, ppo przez podstawienie za wszystkie zmienne 1,
 * a nastepnie zamianie funkcji otrzymana wartoscia
 * @param InputString - string w ktorym ma zamieniac
 * @return wartosc ctan
 */
int ctangensFile(std::string &InputString);

/**
 * @brief Procedura zamienia wszystkie funkcje trygonometryczne zdefiniowane w wyrazeniu,
 * ktore ma zostac dodane do pliku, na wartosci, otrzymanych dla przykladowych argumentow
 * @param InputString - string w ktorym bedzie zamieniac
 * @return treu kiedy sie udalo, false kiedy nie
 */
bool TrygFunFile(std::string &InputString);

/**
 * @brief Procedura wczytuje do listy funkcji funkcje zapisane w pliku
 * @param List - wskaznik do listy funkcji
 */
void file(FUNQueue *&List);

/**
 * @brief Procedura sprawdza poprawnosc zapisu definicji funkcji,
 * ktora ma zostac zapisana w pliku
 * @param FunDef - definicja funkcji
 * @param FunList - wskaznik do listy funkcji
 * @return true kiedy sie udalo, false kiedy nie
 */
bool checkFunDefFile(std::string FunDef, FUNQueue *FunList);

#endif // FILE_H
