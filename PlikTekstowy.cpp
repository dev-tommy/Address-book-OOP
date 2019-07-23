#include "PlikTekstowy.h"
PlikTekstowy::PlikTekstowy(string nazwaPliku) :
    NAZWA_PLIKU(nazwaPliku) {
}

bool PlikTekstowy::czyPlikJestPusty() {
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);
    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            return false;
        else
            return true;
        plikTekstowy.close();
    }
}


string PlikTekstowy::pobierzNazwePliku() {
    return NAZWA_PLIKU;
}
