#ifndef SCENA_HPP
#define SCENA_HPP
/*!
 * \file scena.hpp
 *
 * Plik zawiera informacje dotyczace klasy scena.
 */
#include <vector>
#include <thread>
#include <chrono>
#include "robot.hpp"
#include "przeszkoda.hpp"
#include "sciezka.hpp"
#include "figura.hpp"
#include "wektor.hpp"
#include "lacze_do_gnuplota.hpp"

/*!
 * \brief Klasa modelujaca scene. 
 * Klasa modelujaca pojecie sceny. Posiada tablice robotów, ścieżek 
 * i przeszkód (w planach modyfikacja do list <shared_ptr>). Liczniki
 * statyczne robotów, prędkość globalną robotów.
 */
class scena
{
/*! Tablica dynamiczna robotow */
  std::vector<robot> 	_Roboty;
/*! Tablica dynamiczna sciezek */
  std::vector<sciezka> 	_Sciezki;
/*! Tablica dynamiczna przeszkod */
  std::vector<przeszkoda> 	_Przeszkody;

/*! Licznik robotów */
  static int 		_iloscrobotow;
/*! Licznik przeszkód */
  static int 		_iloscprzeszkod;
/*! Prędkość globalna - częstotliwość ruchów robota */
  int 			_predkosc;
/*! Wybór robota z listy */
  int			_wybranyrobot;
public:
// Konstruktor

/*!
 * \brief Konstruktor bezparametryczny sceny.
 * Konstruktor tworzy początkowy układ sceny posiadający
 * robota ze ścieżką i 3 przeszkody. Poprawnie inicjuje łącze.
 */
  scena();

/*! Obiekt służący do obsługi łącza z GNUplotem */
  PzG::LaczeDoGNUPlota Lacze;

/*!
 * \brief Metoda zwraca ilość stworzonych robotów.
 * Metoda statyczna zwracająca ilość stworzonych robotów w trakcie działania programu.
 */
  static int Get_iloscrobotow() {return _iloscrobotow;}
/*!
 * \brief Metoda zwraca ilość stworzonych przeszkód.
 * Metoda statyczna zwracająca ilość stworzonych przeszkód w trakcie działania programu.
 */
  static int Get_iloscprzeszkod() {return _iloscprzeszkod;}
/*!
 * \brief Metoda tworząca roboty.
 * Metoda tworzy roboty i dodaje je do tablicy.
 */
  void Tworz_Roboty();
/*!
 * \brief Metoda tworząca przeszkody.
 * Metoda tworzy przeszkody i dodaje je do tablicy.
 */
  void Tworz_Przeszkody();
/*!
 * \brief Metoda wyboru robota.
 * Metoda służaca do wyboru aktualnie używanego robota.
 */
  void Wybierz_Robota();
/*!
 * \brief Metoda zmiany predkosci.
 * Metoda służaca do zmiany predkości - czestotliwosci ruchow
 * robota o jedna jednostke.
 */
  void Ustaw_Predkosc();
/*!
 * \brief Metoda służaca do obrotu robota.
 * Metoda służaca do obrotu aktualnie uzywanego robota.
 */
  void Obroc_Robota();
/*!
 * \brief Metoda służaca do jazdy robota.
 * Metoda służaca do jazdy aktualnie uzywanym robotem.
 */
  void Jazda();
/*!
 * \brief Metoda służaca do przeniesienia sceny.
 * Metoda służaca do przeniesienia wszystkich elementów sceny o wektor.
 */
  void Translacja();
};

#endif
