#include <iostream>
#include "Event.h"

void Event::Load()
{
  std::cout << "Nazwa wydarzenia: ";
  std::cin >> name;

  std::cout << "Dzien: ";
  std::cin >> day;

  std::cout << "Miesiac: ";
  std::cin >> month;

  std::cout << "Rok: ";
  std::cin >> year;

  std::cout << "Godzina: ";
  std::cin >> hour;

  std::cout << "Minut: ";
  std::cin >> minutes;
}

void Event::Show()
{
  std::cout << name 
            << " " << day << "." 
            << month << "." << year
            << " " << hour << ":" << minutes << "\n";
}

Event::Event(std::string n, int d, int m, int y, int h, int mins)
{
  name = n;
  day = d;
  month = m;
  year = y;
  hour = h;
  minutes = mins;
}

Event::~Event()
{
  std::cout << "To ja,  destruktor sie nazywam";
  std::cout << " kasuje obiekty,  slowa przepraszam nie uzywam\n";
}
