#include <iostream>
#include <cstdlib>
#include "Wyswietlacz.h"
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

Wyswietlacz::Wyswietlacz()
{
    srand(time(NULL));
}

void Wyswietlacz::DodajCzujnik()
{
    string typ, lok, wyjdz, id;
    system ("CLS");
    do
    {
    wyjdz="";
    cout << "Wybierz lokalizacje czujnika z listy:\nDom [D]\nOgrod [O]\n";
    cin >> lok;
    if(lok=="D")
        {
            system ("CLS");
            lok="Dom";
            wyjdz="wychodzezsiebie";
        }
        else if(lok=="O")
        {
            system ("CLS");
            lok="Ogrod";
            wyjdz="wychodzezsiebie";
        }
        else
        {
            system ("CLS");
            cout << "Nie ma takiej lokalizacji!\n";
        }
    }while(wyjdz!="wychodzezsiebie");
    cout << "Podaj ID czujnika: ";
    cin >> id;
    system ("CLS");
    cout << "Wybierz typ czujnika z listy:\nCzujnik temperatury [T]\nCzujnik cisnienia [C]\nCzujnik wilgotnosci [W]\n";
    cin >> typ;
    Czujnik* temp;
    if(typ=="T")
    {
        system ("CLS");

        cout << "Utworzono czujnik temperatury o ID " << id << " w lokalizacji " << lok << "\n\n";
        temp=new CzujnikT(lok, id);
    }
    else if(typ=="C")
    {
        system ("CLS");
        cout << "Utworzono czujnik cisnienia o ID " << id << " w lokalizacji " << lok << "\n\n";
        temp=new CzujnikC(lok, id);
    }
    else if(typ=="W")
    {
        system ("CLS");
        cout << "Utworzono czujnik wilgotnosci o ID " << id << " w lokalizacji " << lok << "\n\n";
        temp=new CzujnikW(lok, id);
    }
    else
    {
        system ("CLS");
        cout << "Nie ma takiego typu!\n";
    }
    sensory.push_back(temp);
}

void Wyswietlacz::WypiszStan()
{
    for(Czujnik* czujnik : sensory)
    {

        czujnik->WypiszInfo(cout);
    }
}

void Wyswietlacz::ZapiszPlik() const {
    SYSTEMTIME obecnie;
    GetLocalTime(&obecnie);
    int g = obecnie.wHour;
    int s = obecnie.wSecond;
    int m = obecnie.wMinute;
    string nazwa = to_string(g) + "-" + to_string(m) + "-" + to_string(s) + ".txt";

    ofstream wyjscie(nazwa);

    for(Czujnik* czujnik : sensory) {
        czujnik->WypiszInfo(wyjscie);
    }

    wyjscie.close();
}
void Wyswietlacz::sterowanie()
{
    int wybor = 0;
    do
    {
        cout << "[1] Dodaj czujnik\n[2] Wypisz stan\n[3] Zapisz do pliku\n[4] Wyjdz\n";
        cin>>wybor;
        switch(wybor)
        {
        case 1:
            DodajCzujnik();
            break;
        case 2:
            system ("CLS");
            WypiszStan();
            cout << "\n";
            break;
        case 3:
            system ("CLS");
            ZapiszPlik();
            break;
        case 4:
            system ("CLS");
            cout << "Papa\n";
            break;
        default:
            system ("CLS");
            cout << "Wybrana opcja nie istnieje. Sprobuj ponownie\n";
        }
    }while(wybor!=4);

}

Wyswietlacz::~Wyswietlacz()
    {
        for(Czujnik* czujnik : sensory)
        {
            delete czujnik;
        }
    }
