#pragma once
#include "Czujnik.h"

using std::string;
using std::ostream;

class CzujnikW : public Czujnik
{
public:
    CzujnikW(const string& lok, const string& id);
    void WypiszInfo(ostream& wyjscie);
};
