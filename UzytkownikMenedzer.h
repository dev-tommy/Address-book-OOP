#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    int pobierzIdZalogowanegoUzytkownika();
    bool czyZalogowany;
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami);
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wylogowanieUzytkownika();
    void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif // UZYTKOWNIKMENEDZER_H
