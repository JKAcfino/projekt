#include <iostream>
#include "CzujnikT.h"
#include <cstdlib>

using std::string;
using std::ostream;

CzujnikT::CzujnikT(const string& lok, const string& id) : Czujnik(czujnik_temperatury, lok, id) {}

void CzujnikT::WypiszInfo(ostream& wyjscie)
{
    double wartosc = (double)((rand() % 200) + 140)/10;
    wyjscie << "Czujnik temperatury: " << PobierzId() << "\n";
    wyjscie << "W lokalizacji: " << WczytajLok() <<  "\n";
    wyjscie << "Aktualna temperatura to: " << wartosc << "'C\n\n";
}
