#include <iostream>
#include <fstream>
#include <cmath> // sin(),cos()
#include "wektor.hpp"

using namespace std;

wektor::wektor(const wektor &wektorKopiowany) // konstruktor kopiujacy
{
    for (int i=0; i<IL_OSI; ++i)
	_wektor[i]=wektorKopiowany[i];
    ++_LiczbaStworzonych;
    ++_LiczbaEgzystujaca;
}

ostream &operator<<(ostream &strm, wektor W) // wyswietlanie wspolrzednych wektora
{
    return strm << W[0] << " " << W[1] << endl;
}

istream &operator>>(istream &strm, wektor &W) // pobieranie wspolrzednych wektora
{
    return strm >> W[0] >> W[1];
}

wektor wektor::operator+(wektor W)
{
    W[0] += _wektor[0];
    W[1] += _wektor[1];
    return W;
}

wektor wektor::operator-(wektor W)
{
    W[0] = _wektor[0] - W[0];
    W[1] = _wektor[1] - W[1];
    return W;
}

wektor wektor::operator*(float x)
{
    _wektor[0] *= x;
    _wektor[1] *= x;
    return *this;
}

wektor wektor::obroc(float kat)
{
    wektor tmp;
    tmp[0] = _wektor[0] * cos(kat * M_PI / 180) - _wektor[1] * sin(kat * M_PI / 180);
    tmp[1] = _wektor[0] * sin(kat * M_PI / 180) + _wektor[1] * cos(kat * M_PI / 180);
    _wektor[0] = tmp[0];
    _wektor[1] = tmp[1];
    return *this;
}
