#include <iostream>
#include <cstring>
#include <unistd.h>
#include "obiekt.hpp"
#include "figura.hpp"
#include "robot.hpp"
#include "przeszkoda.hpp"
#include "wektor.hpp"
#include "sciezka.hpp"
#include "scena.hpp"

#include "lacze_do_gnuplota.hpp"

using namespace std;

int wektor::_LiczbaStworzonych = 0; // deklaracja wartosci statycznych
int wektor::_LiczbaEgzystujaca = 0;

int scena::_iloscrobotow=0;
int scena::_iloscprzeszkod=0;

scena 		scena;

void wyswietlMenu()
{
  cout << "Aktualna ilosc robotow: " << scena.Get_iloscrobotow() << endl
       << "Aktualna ilosc przeszkod: " << scena.Get_iloscprzeszkod() << endl
       << endl;
  cout << "Laczna ilosc stworzonych obiektow klasy wektor: " << wektor::Get_LiczbaStworzonych << endl;
  cout << "Ilosc istniejacych obiektow klasy wektor: " << wektor::Get_LiczbaStworzonych << endl 
       << endl;
  cout << "n - stworzenie nowego robota wraz z sciezka" << endl
       << "l - stworzenie nowej przeszkody" << endl
       << "w - wybor uzywanego robota" << endl
       << "p - zmiana szybkosci ruchu robota" << endl
       << "j - jazda na wprost" << endl
       << "o - obrot robota" << endl 
       << endl
//       << "t - wykonaj translacje sceny" << endl 
       << "m - wyswietl menu" << endl 
       << endl
       << "k - koniec dzialania programu" << endl 
       << endl;
}


int main()
{
  wektor 	W;
  char 		wybor;

  wyswietlMenu();
    
  while (true)
  {
    cout << "Twoj wybor? (m - menu) > _\b";
    cin >> wybor;
    if(strchr("nwpojtlmk", wybor))
    {
      if (wybor == 'n')
      {
	scena.Tworz_Roboty();
      }
      if (wybor == 'l')
      {
	scena.Tworz_Przeszkody();
      }
      else if (wybor == 'w')
      {
	scena.Wybierz_Robota();
      }
      else if (wybor == 'p')
      {
        scena.Ustaw_Predkosc();
      }
      else if (wybor == 'o')
      {
	scena.Obroc_Robota();
      }
      else if (wybor == 'j')
      {
	scena.Jazda();
      }
      else if (wybor == 't')
      {
	scena.Translacja();
      }
      else if (wybor == 'm')
      {
	wyswietlMenu();
      }
      else if (wybor == 'k')
      {
	cout << "Koniec dzialania programu!\n";
	system("rm -f *.dat");
	system("rm -f *sciezka");
	exit(1);
      }
    }
    else
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cerr << "Nieporawne polecenie\n";
      wybor = ' ';
      wyswietlMenu();
    }
  }
}
