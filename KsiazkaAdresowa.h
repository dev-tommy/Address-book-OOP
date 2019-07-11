#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <windows.h>

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector <Uzytkownik> uzytkownicy;
public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
private:
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

};
