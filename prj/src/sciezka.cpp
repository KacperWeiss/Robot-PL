#include <iostream>
#include "sciezka.hpp"

using namespace std;

sciezka::sciezka(const sciezka &sciezkaKopiowana) : obiekt(2, sciezkaKopiowana.nazwa()+std::string(".dat"))
{
    globalne()=sciezkaKopiowana.globalne();
    resave();
}

sciezka::sciezka(std::string nazwa) : obiekt(2, nazwa+std::string("sciezka"))
{
    wektor W;
    globalne().push(W);
    save();
}
