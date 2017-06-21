#pragma once
#include <string>

using std::string;
using std::ostream;

enum TypCzujnika
{
    czujnik_temperatury,
    czujnik_cisnienia,
    czujnik_wilgotnosci
};

class Czujnik
{
protected:
    double stan;
    string id;
    string lok;
    TypCzujnika typ;
public:
    Czujnik(TypCzujnika t, const string& lok, const string& id);
    double ImportStanu() const;
    void UstawStan(double wartosc);
    string PobierzId() const;
    void UstawId(const string& id);
    string WczytajLok() const;
    virtual void WypiszInfo(ostream& wyjscie) = 0;
};
