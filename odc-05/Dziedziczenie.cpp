#include <iostream>
#include <cmath>

class Punkt
{
   float x, y;
   std::string nazwa;

public:
   void Wyswietl()
   {
      std::cout << nazwa << "(" << x << ", " << y << ")" << "\n";
   }

   Punkt(std::string n = "S",  float a = 0,  float b = 0)
   {
      nazwa = n;
      x = a;
      y = b;
   }
};

class Kolo : public Punkt //klasa Kolo dziedziczy publicznie z klasy Punkt
{
   float r;
   std::string nazwa;

public:
   void Wyswietl()
   {
      std::cout << "Kolo o nazwie: " << nazwa << "\n";
      std::cout << "Srodek kola: " << "\n";

      Punkt::Wyswietl();
      std::cout << "Promien: " << r << "\n";
      std::cout << "Pole kola : " << M_PI * r * r << "\n";
   }

   Kolo(std::string nk = "Kolko",  std::string np = "S",  float a = 0,  float b = 0,  float pr = 1)
   :Punkt(np, a, b)
   {
      nazwa = nk;
      r = pr;
   }
};

int main()
{
    Kolo k1;
    k1.Wyswietl();

    return 0;
}
