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

using namespace std;

class AdresatMenedzer {
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer();
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

};

#endif // ADRESATMENEDZER_H
