#ifndef FIGURA_HPP
#define FIGURA_HPP
/*!
 * \file figura.hpp
 *
 * Plik zawiera informacje dotyczace klasy figura (zbiór wierzchołków)
 */
#include <iostream>
#include <vector>
#include "wektor.hpp"

/*!
 * \brief Klasa modelujaca pojecie figury. 
 * Klasa modelujaca pojecie figury - zbioru wierzcholków klasy wektor.
 */
class figura
{
/*! Figura zawarta jest w tablicy dynamicznej wektorów */
  std::vector<wektor> _wierzcholek;

public:
/*!
 * \brief Konstruktor bezparametryczny
 * Konstruktor bezparametryczny inicjuje figurę.
 */
  figura() {}
/*!
 * \brief Destruktor figury
 * Destruktor figury.
 */
  ~figura() {}
/*!
 * \brief Przeciążenie operatora dodawania.
 * Przeciążenie to dodaje wektor do wszystkich punktów figury.
 */
  figura operator+(wektor);
/*!
 * \brief Metoda pomagająca przeszukiwaniu tablicy
 * Funkcja pomagająca przeszukiwaniu tablicy - początek
 */
  std::vector<wektor>::iterator begin() { return _wierzcholek.begin(); }
/*!
 * \brief Metoda pomagająca przeszukiwaniu tablicy
 * Funkcja pomagająca przeszukiwaniu tablicy - koniec
 */
  std::vector<wektor>::iterator end() { return _wierzcholek.end(); }
/*!
 * \brief Metoda dodajaca zmienna klasy Wektor 
 * Metoda dodajaca zmienna (do tablicy dynamicznej) klasy Wektor
 * \param W - Wektor dodawany do tablicy dynamicznej
 */
  void push(wektor W) { _wierzcholek.push_back(W); }
/*!
 * \brief Metoda dodajaca 2 zmienne float w postaci wektora
 * Metoda dodajaca 2 zmienne float (do tablicy dynamicznej) w postaci klasy Wektor
 * \param x - współrzędna x wektora dodawanego do tablicy dynamicznej
 * \param x - współrzędna y wektora dodawanego do tablicy dynamicznej
 */
  void push(float x, float y) {wektor W(x,y); _wierzcholek.push_back(W);}
/*!
 * \brief Metoda usuwającą zmienną z tablicy 
 * Metoda usuwająca zmienną (z tablicy dynamicznej) klasy Wektor
 */
  void pop() {_wierzcholek.pop_back();}
/*!
 * \brief Metoda pomagająca w przeszukiwaniu tablicy
 * Zwraca wielkość tablicy dynamicznej.
 */
  int size() const { return _wierzcholek.size(); }
/*!
 * \brief Przeciążenie (const) operatora indeksującego
 * Zwraca wartośc const podanego wierzchołka
 * \param Idx - Index wybranego wierzchołka
 */
  wektor operator[](int Idx) const {return _wierzcholek.at(Idx);}
/*!
 * \brief Przeciążenie operatora indeksującego
 * Zwraca wartośc podanego wierzchołka, a także pozwala na jej modyfikacje
 * \param Idx - Index wybranego wierzchołka
 */
  wektor &operator[](int Idx) {return _wierzcholek.at(Idx);}
};
/*!
 * /brief Przeciążenie operatora <<
 * Przeciazenie operatora << ktory umozliwia wypisanie wierzchołków do strumienia wyjsciowego
 * w odpowiednim formacie.
 */
std::ostream &operator<<(std::ostream &, figura);

#endif
