#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami):
    uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
    adresatMenedzer = NULL;
}
KsiazkaAdresowa::~KsiazkaAdresowa() {
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->dodajAdresata();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }

}

void KsiazkaAdresowa::usunAdresata() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->usunAdresata();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }

}

void KsiazkaAdresowa::edytujAdresata() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->edytujAdresata();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->wyszukajAdresataPoImieniu();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->wyszukajAdresataPoNazwisku();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer->wypiszWszystkichAdresatow();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}

bool KsiazkaAdresowa::czyUzytkownikZalogowany() {
    return uzytkownikMenedzer.czyZalogowany;
}
