# Dlaczego nie C++ Builder?

W tym "wpisie" chcialbym wyjasnic dlaczego nie przepisuje kodu do bardziej poprawnej wersji w C++ Builder 6, lecz uzwyam innych narzedzi.

Wbrew zapewnieniom Miroslawa Zelenta w odcinku 6 nie jestem w stanie zgodzic sie z wieloma cechami, ktore rzekomo ma C++ Builder. Ponizej przedstawiam krotki listing cech buildera:

**Jaki jest C++ Builder 6?**

+ prosty w obsludzie
+ darmowy w wersji do nauki
- nie jest uzywany "na produkcji"
- nie wspierany od lat
- slaba dokumentacja
- wersja C++ jest kulawa proteza na [Delphi](https://en.wikipedia.org/wiki/Delphi_(programming_language))
- czesciowe wsparcie tylko dla Windows (nowsze wersje systemu: 8,10 potrafia robic problemy)
- masa bugow, dosc mocno [problematyczny](https://forum.pasja-informatyki.pl/search?q=C%2B%2B+builder)


## Dlaczego Qt?

Do aplikacji okienkowych uzylem [Qt](https://qt.io) w wersji z [Qt Creator](https://www.qt.io/ide/) ktore jest IDE wspierajacym wszystkie feature'y biblioteki Qt. Pozwala ono edytowac okienka na zasadzie drag & drop (podobnie jak Builder).

+ prosty w obsludze (minimalnie trudniejszy od Buildera)
+ darmowy dla narzedzi opartch o licencje GPL, LGPL, open-source
+ aktywnie uzywany w pracy (duzo produktow uzywa wlasnie Qt do swoich aplikacji)
+ multiplatformowy 
+ wspierany, posiadajacy swietna dokumentacje i mase przykladow gotowych do odpalenia
+ masa feature'ow, daje ogrom mozliwosci
- (nie potrafie znalezc wad porownujac go do buildera)


## Dlaczego SFML?

Do przykladow "growych" uzylem biblioteki SFML, z prostego powodu: gry w dzisiejszych czasach tworzy sie odpowiednio dostosowanymi do tego narzedziami. Jezeli cos robimy, to robmy to raz, a dobrze.

Nieco wiecej o builderze w kontekscie gamdevu napisalem w watku na forum: [CPP Builder, a pisanie gier](https://forum.pasja-informatyki.pl/147265/borland-cpp-builder-6-a-pisanie-gier).


