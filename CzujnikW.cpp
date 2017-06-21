#include <iostream>
#include "CzujnikW.h"
#include <cstdlib>

using std::string;
using std::ostream;

CzujnikW::CzujnikW(const string& lok, const string& id) : Czujnik(czujnik_wilgotnosci, lok, id) {}

void CzujnikW::WypiszInfo(ostream& wyjscie)
{
    double wartosc = (double)(rand() % 1000)/10;
    wyjscie << "Czujnik wilgotnosci: " << PobierzId() << "\n";
    wyjscie << "W lokalizacji: " << WczytajLok() <<  "\n";
    wyjscie << "Aktualna wilgotnosc to: " << wartosc << "%\n\n";
}
