#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami):uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    adresatMenedzer.wczytajAdresatowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa:: wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer.dodajAdresata();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }

}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    if (uzytkownikMenedzer.czyZalogowany) {
        adresatMenedzer.wypiszWszystkichAdresatow();
    } else {
        cout << "Uzytkownik nie zalogowany" << endl;
    }
}
