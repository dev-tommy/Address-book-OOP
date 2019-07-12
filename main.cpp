#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    cout << "Tworzenie obiektu ksiazkaAdresowa" << endl;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //cout << "Rejestracja uzytkownika" << endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    cout << "Wypisz wszystkich uzytkownikow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //cout << "Zmiana hasla uzytkownika:" << endl;
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    cout << "Wylogowanie uzytkownika:" << endl;
    ksiazkaAdresowa.wylogowanieUzytkownika();
    cout << "Logowanie uzytkownika:" << endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    cout << "Wylogowanie uzytkownika:" << endl;
    ksiazkaAdresowa.wylogowanieUzytkownika();
    cout << "Zmiana hasla uzytkownika:" << endl;
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    cout << "Wypisz wszystkich uzytkownikow:" << endl;
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
