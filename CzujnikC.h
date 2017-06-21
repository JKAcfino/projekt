#pragma once
#include "Czujnik.h"

using std::string;
using std::ostream;

class CzujnikC : public Czujnik
{
public:
    CzujnikC(const string& lok, const string& id);
    void WypiszInfo(ostream& wyjscie);
};
