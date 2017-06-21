#include <iostream>
#include "CzujnikC.h"
#include <cstdlib>

using std::string;
using std::ostream;

CzujnikC::CzujnikC(const string& lok, const string& id) : Czujnik(czujnik_cisnienia, lok, id) {}

void CzujnikC::WypiszInfo(ostream& wyjscie)
{
    double wartosc = (double)((rand() % 200) + 9900)/10;
    wyjscie << "Czujnik cisnienia: " << PobierzId() <<  "\n";
    wyjscie << "W lokalizacji: " << WczytajLok() <<  "\n";
    wyjscie << "Aktualne cisnienie to: " << wartosc << "hPa\n\n";
}
