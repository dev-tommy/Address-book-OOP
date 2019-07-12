#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"

using namespace std;

class PlikZUzytkownikami {
    bool czyPlikJestPusty(fstream &plikTekstowy);
    const string nazwaPlikuZUzytkownikami;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : nazwaPlikuZUzytkownikami(nazwaPlikuZUzytkownikami) {}
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif // PLIKZUZYTKOWNIKAMI_H
