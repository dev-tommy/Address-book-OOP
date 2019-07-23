#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class PlikTekstowy {
    const string NAZWA_PLIKU;

public:
    PlikTekstowy(string nazwaPliku);
    bool czyPlikJestPusty();
    string pobierzNazwePliku();
};


#endif // PLIKTEKSTOWY_H
