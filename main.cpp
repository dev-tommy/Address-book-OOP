#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    //cout << "Rejestracja uzytkownika" << endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();

    //cout << endl << "Wypisz wszystkich adresatow:" << endl;
    //ksiazkaAdresowa.wypiszWszystkichAdresatow();


    cout << endl << "Wypisz wszystkich uzytkownikow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //cout << "Zmiana hasla uzytkownika:" << endl;
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    //cout << endl << "Wylogowanie uzytkownika:" << endl;
    //ksiazkaAdresowa.wylogowanieUzytkownika();

    //cout << endl << "Dodaj adresata:" << endl;
    //ksiazkaAdresowa.dodajAdresata();

    cout << endl << "Logowanie uzytkownika:" << endl;
    ksiazkaAdresowa.logowanieUzytkownika();

    cout << endl << "Wypisz wszystkich adresatow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichAdresatow();


    cout << endl << "Dodaj adresata:" << endl;
    ksiazkaAdresowa.dodajAdresata();

    cout << endl << "Dodaj adresata:" << endl;
    ksiazkaAdresowa.dodajAdresata();

    cout << endl << "Wypisz wszystkich adresatow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    cout << endl << "Wylogowanie uzytkownika:" << endl;
    ksiazkaAdresowa.wylogowanieUzytkownika();

    cout << endl << "Wypisz wszystkich adresatow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    //cout << endl << "Zmiana hasla uzytkownika:" << endl;
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    //cout << endl << "Wypisz wszystkich uzytkownikow:" << endl;
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
