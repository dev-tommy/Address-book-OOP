#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa() {
    uzytkownikMenedzer.wczytajUzutkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
