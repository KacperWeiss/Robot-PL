#include <iostream>
#include <cmath>
#include "przeszkoda.hpp"
#include "figura.hpp"
#include "wektor.hpp"
#include "obiekt.hpp"
#include <cstring>


using namespace std;

przeszkoda::przeszkoda(const przeszkoda &przeszkodaKopiowana) : obiekt(3, std::string("przeszkoda_")+przeszkodaKopiowana.nazwa()+std::string(".dat")) // konstruktor kopiujacy zeby dzialal w tablicy dynamikcznej vektor
{
    globalne() = przeszkodaKopiowana.globalne();
}

przeszkoda::przeszkoda(std::string nazwa, wektor translacjapoczatkowa) : obiekt(3, nazwa) // standardowy konstruktor
{
    wektor W(0, 0);
    _srodek = translacjapoczatkowa;
    _lokalne.push(W(-10, -5));
    _lokalne.push(W(10,-5));
    _lokalne.push(W(10,5));
    _lokalne.push(W(-10,5));
    globalne() = _lokalne + _srodek;
}


