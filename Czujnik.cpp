#include "Czujnik.h"

using std::string;

Czujnik::Czujnik(TypCzujnika t, const string& lok, const string& id) : typ(t), lok(lok), id(id) {}

string Czujnik::PobierzId() const
{
     return id;
}
void Czujnik::UstawId(const string& n)
{
    id = n;
}
string Czujnik::WczytajLok() const
{
    return lok;
}

