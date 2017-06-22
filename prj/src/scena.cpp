#include <iostream>
#include <fstream>
#include "scena.hpp"
#include <cstring>

using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::endl;

scena::scena()
{
  Lacze.ZmienTrybRys(PzG::TR_2D);
  for (int i=0;i<3;++i)
  {
    int nri = i;
    wektor translacja(27,27);
    string nr = to_string(nri);
    if (i==1) {translacja(35,160);}
    if (i==2) {translacja(175,82);}
    _Przeszkody.push_back(przeszkoda(string(nr), translacja)); // dodanie przeszkody o podanej wczesniej nazwie i przeszunieciu
    _Przeszkody.at(_iloscprzeszkod).save();
    Lacze.DodajNazwePliku(_Przeszkody.at(_iloscprzeszkod).nazwa().c_str(), PzG::RR_Ciagly, 3);
    ++_iloscprzeszkod;
  }
  string nazwa;
  cout << "Podaj nazwe pierwszego robota: " << endl;
  cin >> nazwa;
  _Roboty.push_back(robot(nazwa)); // dodanie nowego robota do tablicy
  _Sciezki.push_back(sciezka(nazwa)); // dodanie nowej sciezki do tablicy
  _Roboty.at(_iloscrobotow).save();
  _Sciezki.at(_iloscrobotow).save();
  Lacze.DodajNazwePliku(_Roboty.at(_iloscrobotow).nazwa().c_str(), PzG::RR_Ciagly, 2); // dodanie pliku z nazwa robota
  Lacze.DodajNazwePliku(_Sciezki.at(_iloscrobotow).nazwa().c_str(), PzG::RR_Ciagly, 1); // dodanie pliku z nazwa sciezki
  ++_iloscrobotow;
  _wybranyrobot=0;
  _predkosc=10;
  Lacze.Rysuj();
}


void scena::Tworz_Roboty()
{
  string nazwa;
  cout << "Podaj nazwe robota: " << endl;
  cin >> nazwa;
  _Roboty.push_back(robot(nazwa));
  _Sciezki.push_back(sciezka(nazwa));
  _Roboty.at(_iloscrobotow).save();
  _Sciezki.at(_iloscrobotow).save();
  Lacze.DodajNazwePliku(_Roboty.at(_iloscrobotow).nazwa().c_str(), PzG::RR_Ciagly, 2);
  Lacze.DodajNazwePliku(_Sciezki.at(_iloscrobotow).nazwa().c_str(), PzG::RR_Ciagly, 1);
  ++_iloscrobotow;
  Lacze.Rysuj();
}


void scena::Tworz_Przeszkody()
{
  int nr = _iloscprzeszkod;
  ++nr;
  string nazwa = to_string(nr);
  wektor translacja;
  cout << "Tworzysz przeszkode nr: " << nazwa << endl;
  cout << "Podaj wspolrzedne x i y srodka przeszkody: " << endl;
  cin >> translacja;
  _Przeszkody.push_back(przeszkoda(nazwa, translacja)); // dodanie przeszkody o podanej wczesniej nazwie i przeszunieciu
  _Przeszkody.at(_iloscprzeszkod).save();
  Lacze.DodajNazwePliku(_Przeszkody.at(_iloscprzeszkod).nazwa().c_str(), PzG::RR_Ciagly, 3);
  ++_iloscprzeszkod;
  Lacze.Rysuj();
}


void scena::Wybierz_Robota()
{
  cout << "Wybierz nr robota: _\b"; // wybor robota
  cin >> _wybranyrobot;
  cout << "Wybrano robota nr: " << _wybranyrobot << endl;
  _wybranyrobot=_wybranyrobot-1;
}


void scena::Ustaw_Predkosc()
{
  cout << "Predkosc aktualna  " << _predkosc << "  j/s" << endl; // zmiana predkosci
  cout << "Predkosc [j/s]: __\b\b";
  cin >> _predkosc;
}


void scena::Obroc_Robota()
{
  int kat;
  cout << "Podaj wartosc kata obrotu robota w stopniach.\nKat obrotu: __\b\b"; // obrot robota
  cin >> kat;
  _Roboty.at(_wybranyrobot).obroc(kat);
  _Roboty.at(_wybranyrobot).save();
  Lacze.Rysuj();
}

void scena::Jazda()
{
  int blad=0;
  int odleglosc;
  cout << "Podaj dlugosc drogi ruchu robota na wprost.\nDlugosc drogi: ___\b\b\b";
  cin >> odleglosc;
  for (int i = 0; i<odleglosc; ++i)
  {
    _Roboty.at(_wybranyrobot).move(1);
    if (_iloscprzeszkod!=0)
    {
      for (int k=0;k<_iloscprzeszkod;++k) // kolizja z przeszkodami stworzonymi
      {
        for (wektor &elem : _Roboty.at(_wybranyrobot).globalne())
        {
	  if (elem[1] > _Przeszkody.at(k).globalne()[0][1] && elem[0] > _Przeszkody.at(k).globalne()[0][0] && elem[0] < _Przeszkody.at(k).globalne()[2][0] && elem[1] < _Przeszkody.at(k).globalne()[2][1])
	  blad++;
	}
      }
    } 
    if (_iloscrobotow!=1)
    {
      for (int j=0;j<_iloscrobotow;++j)
      {
        if (_wybranyrobot!=j)
        {
	  if (14>sqrt(pow(_Roboty.at(_wybranyrobot).globalne()[0][0] - _Roboty.at(j).globalne()[0][0], 2) + pow(_Roboty.at(_wybranyrobot).globalne()[0][1] - _Roboty.at(j).globalne()[0][1], 2)))
	  blad++;
	}
      }
    }
    if(blad!=0)
    {
      _Roboty.at(_wybranyrobot).move(-1);
      blad=0;
      cout << "KOLIZJA!" << endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000/_predkosc));
      break;
    }
    _Sciezki.at(_wybranyrobot).push(_Roboty.at(_wybranyrobot)()); // dodaje kolejny punkt do sciezki wybranego robota
    _Sciezki.at(_wybranyrobot).save();
    _Roboty.at(_wybranyrobot).save();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/_predkosc));
    Lacze.Rysuj();
  }
}

void scena::Translacja()
{
  wektor translacja;
  cout << "Podaj wektor translacji x y: ";
  cin >> translacja;
  for (robot &Robot : _Roboty)
  {
    for (wektor &elem : Robot.globalne())
    {
      elem = elem + translacja;
    }
    Robot.save();
  }
for (sciezka &Sciezka : _Sciezki)
  {
    for (wektor &elem : Sciezka.globalne())
    {
      elem = elem + translacja;
    }
    Sciezka.resave();
  }
for (przeszkoda &Przeszkoda : _Przeszkody)
  {
    for (wektor &elem : Przeszkoda.globalne())
    {
      elem = elem + translacja;
    }
    Przeszkoda.save();
  }
  Lacze.Rysuj();
}
