#include <iostream>
#include "Przyjaciele.h"

void Sedzia(Punkt &pkt, Prostokat &p)
{
  p.nazwa = "PODMIANA";

  if(pkt.x >= p.x && 
     pkt.x <= p.x + p.szerokosc && 
     pkt.y >= p.y && 
     pkt.y <= p.y + p.wysokosc)
  {
    std::cout << "Punkt " << pkt.nazwa << " nalezy do prostokata: " << p.nazwa << "\n";
  }
  else
  {
    std::cout << "Punkt " << pkt.nazwa << " lezy POZA prostokatem: " << p.nazwa << "\n";
  }
}

int main()
{
  Punkt pkt1("A", 3, 17);
  //pkt1.wczytaj();

  Prostokat p1("Prostokat", 0, 0, 6, 4);
  //p1.wczytaj();

  Sedzia(pkt1, p1);

  p1.Wczytaj();
  return 0;
}
