#ifndef SCIEZKA_HPP
#define SCIEZKA_HPP
/*!
 * \file sciezka.hpp
 *
 * Plik zawiera informacje dotyczace klasy sciezka.
 */

#include "obiekt.hpp"
/*!
 * \brief Klasa modelujaca pojecie scieżki robota. 
 * Klasa modelujaca pojecie ścieżki - obiektu graficznego, 
 * będącym zbiorem współrzędnych punktów "odwiedzonych" przez robota.
 */
class sciezka : public obiekt
{
public:
// Konstruktory i destruktory

/*!
 * \brief Konstruktor ścieżki robota.
 * Konstruktor tworzy instancje posiadającą nazwę podaną w parametrach 
 * konstruktora, a także automatyczne ID odpowiednie swojej klasie 
 * wykorzystując listę inicjalizacyjną.
 * \param nazwa	- Nazwa tworzonej ścieżki.
 */
  sciezka(std::string nazwa);
/*!
 * \brief Konstruktor kopiujący
 * Konstruktor kopiujący ścieżki.
 * \param &sciezkaKopiowana - ścieżka która jest kopiowana
 */
  sciezka(const sciezka &sciezkaKopiowana);
/*!
 * \brief Destruktor obiektu.
 * Destruktor obiektu. 
 */
  ~sciezka() {}

// Przeciążenia operatorów i metody publiczne klasy

/*!
 * \brief Metoda dodająca punkt do ścieżki
 * Metoda dodająca punkt do ścieżki (współrzędne globalne).
 * \param W - wierzchołek dodawany do tablicy wierzchołków.
 */
  void push(wektor W) { globalne().push(W); }
/*!
 * \brief Przeciążenie operatora ()()
 * Przeciążenie operatora ()() zwraca współrzędne wszystkich punktów w ścieżce.
 */
  figura operator()() const { return globalne(); }
};

#endif
