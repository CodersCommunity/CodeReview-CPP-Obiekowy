#include <iostream>
#include <string>

class Zwierze
{
public:
  std::string gatunek;
  std::string imie;
	int wiek;

  void dodaj_zwierze()
  {
		std::cout << "DODAWANIE NOWEGO ZWIERZECIA DO BAZY: \n";
    std::cout << "Podaj gatunek: \n";
    std::cin >> gatunek;
    std::cout << "Podaj imie: \n";
    std::cin >> imie;
    std::cout << "Podaj wiek: \n";
    std::cin >> wiek;
	}
		
  void daj_glos()
  {
    if (gatunek == "kot")
      std::cout << imie << " lat " << wiek << ": Miau!\n";
    else if (gatunek == "koza") 
      std::cout << imie << " lat " << wiek << ": Beeeee!\n";
    else if (gatunek == "krowa")
      std::cout << imie << " lat " << wiek << ": Muuuuu!\n";
    else 
      std::cout << "nieznany gatunek! Moze jakies UFO?!\n";
  }
};

int main()
{
  Zwierze z1;
  z1.dodaj_zwierze();
  z1.daj_glos();

  Zwierze z2;
  z2.dodaj_zwierze();
  z2.daj_glos();

  return 0;
}
