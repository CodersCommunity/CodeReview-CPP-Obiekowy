#include <iostream>

class Prostokat;

class Punkt
{
   std::string nazwa;
   float x, y;

public:
   Punkt(std::string="A", float=0, float=0);
   void Wczytaj();

   friend void Sedzia(Punkt &pkt, Prostokat &p);

};

class Prostokat
{
   std::string nazwa;
   float x , y, szerokosc, wysokosc;

public:
   Prostokat(std::string="brak", float=0, float=0, float=1, float=1);
   void Wczytaj();

   friend void Sedzia(Punkt &pkt, Prostokat &p);
};
