/**
 * \file interface.h
 * \brief Plik nagłówkowy modułu \a interface
 *
 * Moduł \a interface zawiera funkcje niezbędne
 * do komunikacji z użytkownikiem poprzez konsolę
 * tekstową
 *
 * \see interface.cpp
 */

#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "functionlist.h"
#include "functionqueue.h"
#include <fstream>
using namespace std;


void paragraph();
void paragraph1();
void printMainMenu();

/**
 * @brief Procedura sprawdza co uzytkownik wprowadzil
 * @return -1 kiedy nie jest pojedynczym znakiem, -2 kiedy nie jest liczba, -3 kiedy nie jest 1,2,3,4 lub 5
 */
int getDecision();

/**
 * @brief Procedura w zaleznosci od argumentu wywoluje rozne komunikaty dla uzytkownika
 * @param errorCode - decyzja
 */
void errorHandling(int errorCode);

/**
 * @brief Główna procedura interfejsu.
*
* Procedura realizująca komunikacją z użytkownikiem
* poprzez interfejs konsolowy.
 * @return decyzja uzytkownika
 */
int mainMenu();

/**
 * @brief Procedura sprawdza, czy uzytkownik che powrocic do menu glownego
 * lub wyjsc z programu
 * @param inputString - decyzja
 * @return -1 kiedy chce powrotu, -2 kiedy chce wyjsc, -3 kiedy chce przejsc dalej
 */
int BackOrExitDecision(std::string inputString);

/**
 * @brief Procedura ktora sprawdza, czy uzytkownik chce powrocic, wyjsc,
 * czy liczyc wyrazenie
 * @param inputString - dane wprowadzone przez uzytkownika
 * @return -1 kiedy chce powrotu, -2 kiedy chce wyjsc, -3 kiedy chce przejsc dalej
 */
int CountBlockcase1(std::string &inputString);

/**
 * @brief Procedura ktora sprawdza, czy uzytkownik chce powrocic do menu glownego, wyjsc
 * czy dodaj funckje
 * @param inputString - dane wprowadzone przez uzytkownika
 * @return -1 kiedy chce powrotu, -2 kiedy chce wyjsc, -3 kiedy chce przejsc dalej
 */
int CountBlockcase2(std::string &inputString);

/**
 * @brief Procedura ujednolica wyrazenie tak, aby znajdowaly sie w nim
 * tylko male litery
 * @param InputString - string, ktory ma zmienic
 * @return wyrazenie ze wszystkimi malymi literami, o ile taki wystepuja
 */
std:: string ToLower(std::string InputString);

/**
 * @brief Procedura ktora sprawdza, czy pierwszy znak jest cyfra
 * @param InputString - string, ktory bedzie spradzany
 * @param FunName - nazwa funkcji
 * @return treu kiedy nie jest liczba
 */
bool firstIsNotNumber(std::string InputString, std::string &FunName);

/**
 * @brief Procedura, ktora sprawdza czy w podanym wyrazeniu
 * wystepuja funkcje trygonometryczne
 * @param InputString - string ktory bedzie sprawdzany
 * @return true kiedy wystapily funkcje trygonometryczne
 */
bool isThereTrygFun(std::string InputString);

/**
 * @brief Procedura sprawdza, czy w liscie funkcji nie wystepuje juz funkcja,
 * ktora sprawdzamy
 * @param InputString - nazwa funkcji
 * @param elem - wskaznik do listy funkcji
 * @return true kiedy jest juz taka nazwa funkcji
 */
bool isInList(std::string InputString, FUNQueue *elem);

/**
 * @brief Procedura sprawdza, czy podana nazwa funkcji jest poprawna
 * @param InputString - nazwa funkcji
 * @param elem - wskaznik do listy funkcji
 * @return -1 kiedy w nazwie wystepuje definicja funkcji trygonometrycznej,
 * -2 kiedy wsytepuje znaki specjalne,
 * -3 kiedy taka nazwa funkcji zostala juz zdefiniowana
 * -4 kiedy taka nazwa funkcji nie zostala juz zdefiniowana
 */
int IsItBusy(std::string InputString, FUNQueue *elem);

/**
 * @brief Funckja zwraca definicje funkcji, ktora podal uzytkownik
 * @param FunctionName - nazwa funkcji, ktora teraz definiuje uzytkownik
 * @return definicja funkcji
 */
std::string FunctionDefining(std::string FunctionName);

/**
 * @brief Procedura ktora drkuje instrukcje programu
 * oraz informacje o autorze
 */
void Instruction();

/**
 * @brief Procedura drukuje pod soba nazwe wraz z definicja
 * funkcji, ktore zostaly zdefiniowane wczesniej
 * @param FunList - wskazni do listy funkcji
 */
void addedFunctions(FUNQueue *FunList);

#endif // INTERFACE_H
