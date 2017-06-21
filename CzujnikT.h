#pragma once
#include "Czujnik.h"

using std::string;
using std::ostream;

class CzujnikT : public Czujnik
{
public:
    CzujnikT(const string& lok, const string& id);
    void WypiszInfo(ostream& wyjscie);
};
