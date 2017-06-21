#pragma once
#include <vector>
#include "CzujnikT.h"
#include "CzujnikC.h"
#include "CzujnikW.h"

using std::vector;

class Wyswietlacz
{
    vector<Czujnik*> sensory;
    void DodajCzujnik();
    void WypiszStan();
    void ZapiszPlik() const;
public:
    Wyswietlacz();
    void sterowanie();
    ~Wyswietlacz();
};

