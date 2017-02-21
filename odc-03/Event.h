#include <iostream>

class Event
{
public:
   Event(std::string="brak", int=1, int=1, int=2015, int=12, int=0);
   ~Event();

   void Load();
   void Show();

private:
   int day, month, year;
   int hour, minutes;
   std::string name;
};
