#include <iostream>

class Ksztalt
{
public:
  // czysta funkcja wirtualna
  virtual void oblicz_pole()=0;
};

class Kolo : public Ksztalt
{
  float r;
public:
  Kolo(float x)
  {
    r = x;
  }
  virtual void oblicz_pole()
  {
    std::cout << "Pole kola: " << 3.14 * r * r << "\n";
  }
};

class Kwadrat : public Ksztalt
{
  float a;

public:
  Kwadrat(float x)
  {
    a = x;
  }

  virtual void oblicz_pole()
  {
    std::cout << "pole kwadratu: " << a * a << "\n";
  }
};

void obliczenia(Ksztalt *x)
{
   x->oblicz_pole();
}

int main()
{
   Kolo k(1);
   Kwadrat kw(2);

   Ksztalt *wsk;

   wsk = &k;
   wsk->oblicz_pole();

   wsk = &kw;
   wsk->oblicz_pole();

   obliczenia(wsk);

   return 0;
}
