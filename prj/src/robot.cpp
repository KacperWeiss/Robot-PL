#include <iostream>
#include <cmath> // fmod()
#include "robot.hpp"
#include "figura.hpp"
#include "wektor.hpp"
#include "obiekt.hpp"
#include <cstring>


using namespace std;

robot::robot(const robot &robotKopiowany) : obiekt(1, robotKopiowany.nazwa())
{
    _kat = robotKopiowany.kat();
    _lokalne = robotKopiowany.lokalne();
    globalne() = robotKopiowany.globalne();
}

robot::robot(std::string nazwa) : obiekt(1, nazwa/*+string(".dat")*/)
{
    wektor W(0, 0);
    _kat = 90;
    _lokalne.push(W);
    _lokalne.push(W(0, 7));
    _lokalne.push(W.obroc(45));
    _lokalne.push(W.obroc(90));
    _lokalne.push(W.obroc(90));
    _lokalne.push(W.obroc(90));
    globalne() = _lokalne;
}

void robot::obroc(float kat)
{
    wektor tmp = *globalne().begin();
    _kat += kat;
    _kat = fmod(_kat, 360);
    for (wektor &elem : _lokalne)
        elem.obroc(kat);
    globalne() = _lokalne;
    globalne() = globalne() + tmp;
}

void robot::move(float odl)
{

    	wektor tmp(odl, 0);
    	tmp.obroc(_kat);
    	for (wektor &elem : globalne())
        elem = elem + tmp;


}


