#ifndef PRZESZKODA_HPP
#define PRZESZKODA_HPP
/*!
 * \file przeszkoda.hpp
 *
 * Plik zawiera informacje dotyczace klasy przeszkoda.
 */
#include <vector>
#include "figura.hpp"
#include "wektor.hpp"
#include "obiekt.hpp"
/*!
 * \brief Klasa modelujaca pojecie przeszkody. 
 * Klasa modelujaca pojecie przeszkody - obiektu graficznego, 
 * niezdolnego do poruszania się, ale zdolnego do wykrywania kolizji. 
 * Posiada zarówno współrzędne globalne (dziedziczone z klasy 
 * obiekt) i lokalne - jej kształt.
 */
class przeszkoda : public obiekt
{
/*! Wierzchołki lokalne - kształt przeszkody */
  figura _lokalne;
/*! Aktualna współrzędna globalna środka przeszkody */
  wektor _srodek;
public:
// Konstruktory i destruktory

/*!
 * \brief Konstruktor przeszkody.
 * Konstruktor tworzy instancje posiadającą nazwę podaną w parametrach 
 * konstruktora, posiadającą środek w podanym miejscu układu współrzędnych
 * a także automatyczne ID odpowiednie swojej klasie 
 * wykorzystując listę inicjalizacyjną.
 * \param nazwa			- Nazwa tworzonego robota.
 * \param translacjapoczatkowa 	- Przemieszczenie względem osi (0,0) środka przeszkody.
 */
  przeszkoda(std::string nazwa, wektor translacjapoczatkowa);
/*!
 * \brief Konstruktor kopiujący
 * Konstruktor kopiujący przeszkody.
 * \param &przeszkodaKopiowany - przeszkoda która jest kopiowana
 */
  przeszkoda(const przeszkoda &przeszkodaKopiowana);
/*!
 * \brief Destruktor obiektu.
 * Destruktor obiektu. 
 */
  ~przeszkoda() {}

// Przeciążenia operatorów i metody publiczne klasy

/*!
 * \brief Przeciążenie operatora ()()
 * Przeciążenie operatora ()() zwraca współrzędne pierwszego punkt przeszkody.
 */
  wektor operator()() const { return *globalne().begin(); }
/*!
 * \brief Metoda zwracająca wpółrzędne środka przeszkody (const)
 * Metoda zwracająca wpółrzędne środka przeszkody,
 * bez możliwości jego modyfikacji.
 */
  wektor Get_srodek() const {return _srodek;}

};

#endif
