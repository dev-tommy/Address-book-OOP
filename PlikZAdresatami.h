#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "PlikTekstowy.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    int pobierzIdOstatniegoAdresata();
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), PlikTekstowy(nazwaPlikuZAdresatami) {}
    void dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    vector<Adresat> usunAdresataZPliku(int idAdresataDoUsuniecia, int idZalogowanegoUzytkownika);
    vector<Adresat> edytujAdresataWPliku(Adresat adresatTymczasowy, int idZalogowanegoUzytkownika);
};

#endif // PLIKZADRESATAMI_H
