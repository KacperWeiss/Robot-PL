#ifndef ROBOT_HPP
#define ROBOT_HPP
/*!
 * \file robot.hpp
 *
 * Plik zawiera informacje dotyczace klasy robot.
 */
#include "obiekt.hpp"
/*!
 * \brief Klasa modelujaca pojecie robota. 
 * Klasa modelujaca pojecie robota - obiektu graficznego, 
 * zdolnego do poruszania się i wykrywania kolizji. Posiada
 * zarówno współrzędne globalne (dziedziczone z klasy obiekt) i 
 * lokalne - jego kształt
 */
class robot : public obiekt
{
/*! Aktualny kąt obrotu wierzchołków lokalnych */
  float _kat;
/*! Wierzchołki lokalne */
  figura _lokalne;
public:
// Konstruktory i destruktory

/*!
 * \brief Konstruktor robota.
 * Konstruktor tworzy instancje posiadającą nazwę podaną w parametrach 
 * konstruktora, a także automatyczne ID odpowiednie swojej klasie 
 * wykorzystując listę inicjalizacyjną.
 * \param nazwa	- Nazwa tworzonego robota.
 */
  robot(std::string nazwa);
/*!
 * \brief Konstruktor kopiujący
 * Konstruktor kopiujący robota.
 * \param &robotKopiowany - robot który jest kopiowany
 */
  robot(const robot &robotKopiowany);
/*!
 * \brief Destruktor obiektu.
 * Destruktor obiektu. 
 */
  ~robot() {}

// Przeciążenia operatorów i metody publiczne klasy

/*!
 * \brief Przeciążenie operatora ()()
 * Przeciążenie operatora ()() zwraca współrzędne środka robota.
 */
  wektor operator()() const { return *globalne().begin(); }
/*!
 * \brief Metoda zwracająca współrzędne lokalne.
 * Metoda zwracająca współrzędne lokalne.
 */
  figura lokalne() const {return _lokalne;}
/*!
 * \brief Metoda zwracająca kąt.
 * Metoda zwracająca kąt.
 */
  float kat() const {return _kat;}
/*!
 * \brief Metoda obrotu robota
 * Obraca robota o podany kąt i zmienia wartość aktualnej wartości _kat.
 * \param kat - kąt o który zostanie obrócony robot
 */
  void obroc(float kat);
/*!
 * \brief Metoda przemieszczająca robota.
 * Metoda umożliwiająca przemieszczenie robota na wprost o określoną odległość.
 * \param odl - odległość przemieszczenia.
 */
  void move(float odl);
};


#endif
