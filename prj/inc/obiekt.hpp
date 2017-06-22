#ifndef OBIEKT_HPP
#define OBIEKT_HPP
/*!
 * \file obiekt.hpp
 *
 * Plik zawiera informacje dotyczace klasy obiekt (graficzny)
 */
#include <fstream>
#include "figura.hpp"
#include "wektor.hpp"
/*!
 * \brief Klasa modelujaca pojecie obiektu (graficznego). 
 * Klasa modelujaca pojecie obiektu - jego graficznego 
 * odwzorowania - w postaci wierzchołków globalnych,
 * nazwy, ID (rodzaj/typ obiektu).
 */
class obiekt
{ // Część prywatna klasy

/*! Strumień odpowiadający za pracę z plikiem */
  std::fstream _plik;
/*! Obiekt posiada wierzchołki globalne (klasy figura) */
  figura _obiekt;
/*! ID - zwykle posiada nr identyfikujący rodzaj klasy pochodnej */
  int _ID;
/*! Nazwa konkretnego obiektu graficznego */
  std::string _nazwa;

protected: // Część protected klasy
// Konstruktory i destruktory

/*!
 * \brief Konstruktor bezparametryczny.
 * Konstruktor bezparametryczny inicjuje obiekt
 * z pomocą listy inicjalizacyjnej.
 */
  obiekt() : _ID(), _nazwa() {}
/*!
 * \brief Konstruktor obiektu o 2 parametrach.
 * Konstruktor tworzy instancje posiadającą ID i nazwę podane
 * w parametrach konstruktora wykorzystując listę inicjalizacyjną.
 * \param ID 	- Identyfikator klasy pochodnej.
 * \param nazwa	- Nazwa tworzonego obiektu graficznego.
 */
  obiekt(int ID, std::string nazwa) : _ID(ID), _nazwa(nazwa) {}
/*!
 * \brief Konstruktor kopiujący
 * Konstruktor kopiujący obiektu.
 * \param &obiektKopiowany - obiekt który jest kopiowany
 */
  obiekt(const obiekt &obiektKopiowany) : _ID(obiektKopiowany.Get_ID()), _nazwa(obiektKopiowany.nazwa()) {}
/*!
 * \brief Destruktor obiektu.
 * Destruktor obiektu. 
 */
  ~obiekt() {}

// Metody prywatne

/*!
 * \brief Metoda ustawiająca nowe wierzchołki globalne.
 * Metoda ustawiająca nowe wierzchołki globalne obiektu na podstawie
 * przekazywanej listy wierzchołków (obiektu klasy figura).
 * \param F - Nowy zestaw współrzędnych globalnych.
 */
  void set(figura F) { _obiekt = F; }

public: // Część public klasy

/*!
 * \brief Metoda zwracająca wierzchołki (const)
 * Metoda zwracająca wierzchołki globalne, uniemożliwiająca jednocześnie
 * modyfikacje znajdujących się w nich wartości.
 */
  figura globalne() const { return _obiekt; }
/*!
 * \brief Metoda zwracająca wierzchołki
 * Metoda zwracająca wierzchołki globalne, umożliwiająca modyfikacje 
 * znajdujących się w nich wartości.
 */
  figura &globalne() { return _obiekt; }
/*!
 * \brief Metoda zwracająca nazwę (const)
 * Metoda zwracająca nazwę, uniemożliwiając jednocześnie jej modyfikacje.
 */
  std::string nazwa() const { return _nazwa; }
/*!
 * \brief Metoda zwracająca nazwę 
 * Metoda zwracająca nazwę obiektu, umożliwiając jej modyfikacje.
 */
  std::string &nazwa() { return _nazwa; }
/*!
 * \brief Metoda zwracająca identyfikator (const)
 * Metoda zwracająca identyfikator obiektu, uniemożliwiając jego modyfikacje.
 */
  int Get_ID() const {return _ID;}
/*!
 * \brief Metoda zapisująca obiekt do pliku.
 * Metoda zapisująca wierzchołki obiektu do pliku o nazwie identycznej do
 * nazwy obiektu (z końcówką .dat).
 */
  void save();
/*!
 * \brief Metoda zapisująca ponownie obiekt do pliku.
 * Metoda zapisująca ponownie wierzchołki obiektu do pliku o nazwie 
 * identycznej do nazwy obiektu (z końcówką .dat).
 */
  void resave();

};

#endif
