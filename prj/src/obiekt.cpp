#include <iostream>
#include "figura.hpp"
#include "obiekt.hpp"
#include <fstream>

using namespace std;

void obiekt::save()
{
    switch (this->_ID)
    {
    case 0:
        break;
    case 1:
        _plik.open(this->nazwa(), ios::out); // otwarcie pliku o nazwie odpowiadajacej nazwie obiektu
        _plik << this->_obiekt; // zapisanie wspolrzednych obiektu
        _plik << *(this->_obiekt.begin() + 1); // dopisanie 2 wspolrzednej
        break;
    case 3:
        _plik.open(this->nazwa(), ios::out);
        _plik << this->_obiekt;
        _plik << *(this->_obiekt.begin());
        break;
    case 2:
        _plik.open(this->nazwa(), ios::app);
        _plik << *(this->globalne().end() - 1);
        break;
    }
    _plik.close();
}

void obiekt::resave()
{
    switch (this->_ID)
    {
    case 0:
        break;
    case 1:
        _plik.open(this->nazwa(), ios::out); // otwarcie pliku o nazwie odpowiadajacej nazwie obiektu
        _plik << this->_obiekt; // zapisanie wspolrzednych obiektu
        _plik << *(this->_obiekt.begin() + 1); // dopisanie 2 wspolrzednej
        break;
    case 3:
        _plik.open(this->nazwa(), ios::out);
        _plik << this->_obiekt;
        _plik << *(this->_obiekt.begin());
        break;
    case 2:
        _plik.open(this->nazwa(), ios::out);
        _plik << this->_obiekt;
        break;
    }
    _plik.close();
}

