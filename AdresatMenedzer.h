#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void usunAdresata();
    void edytujAdresata();
    void wypiszWszystkichAdresatow();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

};

#endif // ADRESATMENEDZER_H
