#ifndef WEKTOR_HPP
#define WEKTOR_HPP
/*!
 * \file wektor.hpp
 *
 * Plik zawiera informacje dotyczace klasy wektor.
 */
#define IL_OSI 2

#include <iostream>
#include <cmath> // sqrt(),pow()

/*!
 * \brief Klasa modelujaca pojecie Wektora 2D 
 * Klasa modelujaca pojecie Wektora 2D.
 */
class wektor
{
/*! Wektor zawarty jest w dwuelementowej tablicy typu float */
    float _wektor[IL_OSI];
/*! Licznik wszytkich istniejacych wektorow */
    static int _LiczbaStworzonych;
/*! Licznik wszytkich "Egzystujących" wektorow */
    static int _LiczbaEgzystujaca;

  public:
  /*!
   * \brief Konstruktor bezparametryczny Wektora.
   * przypisanie zmiennym wektora wartosci zerowych
   *_wektor[0] = 0 -- wartosc zerowa dla zmiennej X
   *_wektor[1] = 0 -- wartosc zerowa dla zmiennej Y  
   */
    wektor()
    {
        _wektor[0] = 0;
        _wektor[1] = 0;
	++_LiczbaStworzonych;
	++_LiczbaEgzystujaca;
    }
  /*!
   * \brief Konstruktor Wektora o dwóch parametrach typu float.
   * przypisanie zmiennym wektora konkretnych wartosci
   * \param x - wartość która zostanie przypisana _wektor[0]
   * \param y - wartość która zostanie przypisana _wektor[1]
   */
    wektor(float x, float y)
    {
        _wektor[0] = x;
        _wektor[1] = y;
	++_LiczbaStworzonych;
	++_LiczbaEgzystujaca;
    }
  /*!
   * \brief Konstruktor kopiujący Wektora.
   * Konstruktor kopiujący współrzędne x,y.  
   * Inkrementuje wartości liczników obiektów.
   */
    wektor(const wektor &wektorKopiowany);
  /*!
   * \brief Destruktor Wektora.
   * Zmniejsza wartość licznika obiektów "Egzystujących". 
   */
    ~wektor() {--_LiczbaEgzystujaca;}
  /*!
   * \brief Przeciążenie (const) operatora indeksującego
   * Zwraca wartośc const podanej współrzędnej
   * \param i - wybrana oś: [0] -- X, [1] -- Y.
   */
    float operator[](int i) const { return _wektor[i]; }
  /*!
   * \brief Przeciążenie operatora indeksującego
   * Zwraca wartość podanej współrzędnej, a także pozwala na jej modyfikacje
   * \param i - wybrana oś: [0] -- X, [1] -- Y.
   */
    float &operator[](int i) { return _wektor[i]; }
   /*!
    * \brief Operator funkcyjny podmienia wartosci wektora i zwraca ten wektor
    * 
    * Przeciążenie operatora funkcyjnego podmienia wartosci wektora i zwraca ten wektor
    * \param x - wartość która zostanie przypisana _wektor[0]
    * \param y - wartość która zostanie przypisana _wektor[1]
    */
    wektor &operator()(float x, float y)
    {
        _wektor[0] = x;
        _wektor[1] = y;
        return *this;
    }
  /*!
   * \brief Przeciążenie liczace dlugosc wektora.
   * Metoda liczaca dlugosc wektora.
   */
    float operator&(wektor W) { return sqrt(pow(_wektor[0] - W[0], 2) + pow(_wektor[1] - W[1], 2)); }
  /*!
   * \brief Przeciązenie sumujące Wektory.
   * Przeciazenie pozwala sumowac dwa wektory.
   */
    wektor operator+(wektor);
  /*!
   * \brief Przeciązenie odejmujące Wektory.
   * Przeciazenie pozwalające obliczyć różnice dwóch wektorów.
   */
    wektor operator-(wektor);
  /*!
   * \brief Przeciązenie mnożąca Wektor przez skale.
   * Przeciążenie mnożące współrzędne przez skalę.
   */
    wektor operator*(float x);
  /*!
   * \brief Metoda odpowiadajaca za obracanie wektora.
   * Metoda odpowiadajaca za obracanie wektora (potrzebne do obrotu robota)
   */
    wektor obroc(float kat);

/*!
 * \brief Metoda zwraca ilość stworzonych obiektów.
 * Metoda statyczna zwracająca ilość stworzonych obiektów w trakcie działania programu.
 */
  static int Get_LiczbaStworzonych() {return _LiczbaStworzonych;}
/*!
 * \brief Metoda zwraca ilość egzystujących obiektów.
 * Metoda statyczna zwracająca ilość egzystujących - wciąż "żywych" obiektów w trakcie działania programu.
 */
  static int Get_LiczbaEgzystujaca() {return _LiczbaEgzystujaca;}
};
/*!
 * /brief Przeciążenie operatora <<
 * Przeciazenie operatora << ktory umozliwia wypisanie wektora do strumienia wyjsciowego
 */
std::ostream &operator<<(std::ostream &, wektor);
/*!
 * /brief Przeciążenie operatora >>
 * Przeciazenie operatora >> ktory umozliwia pobieranie wektora ze strumienia wejsciowego
 */
std::istream &operator>>(std::istream &, wektor &);

#endif
