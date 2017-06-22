#include <iostream>
#include "wektor.hpp"
#include "figura.hpp"

using namespace std;

ostream & operator<< (ostream &strm, figura F) // dalo na wybrane wyjscie wszystkie wspolrzedne
{
    for (auto pd = F.begin(); pd != F.end(); pd++) // od poczatku tablicy do jej konca wykonuje ta funkcje
        strm << *pd;
    return strm;
}

figura figura::operator+(wektor W)
{
    for (wektor &elem : this->_wierzcholek)
        elem = elem + W;
    return *this;
}
