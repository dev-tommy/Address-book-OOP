#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) :
    plikZAdresatami(nazwaPlikuZAdresatami),
    ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {

    adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}
void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;
    adresat = podajDaneNowegoAdresata(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

void AdresatMenedzer::usunAdresata() {
    int idAdresataDoUsuniecia;
    char znak;
    bool czyIstniejeAdresat = false;
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID adresata do usuniecia: ";
    cin.sync();
    cin >> idAdresataDoUsuniecia;
    cout << endl;

    for (int i=0; i<adresaci.size(); i++) {
        if ( idAdresataDoUsuniecia == adresaci[i].pobierzId()) {
            wyswietlDaneAdresata(adresaci[i]);
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                adresaci = plikZAdresatami.usunAdresataZPliku(idAdresataDoUsuniecia, ID_ZALOGOWANEGO_UZYTKOWNIKA);
                return;
            } else {
                cout << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << "Adresat o podanym ID nie zostal znaleziony! " << endl;
        system("pause");
    }
}

void AdresatMenedzer::edytujAdresata() {
    int idAdresataDoEdycji;
    Adresat adresatTymczasowy;
    char wybor;
    bool czyIstniejeAdresat = false;
    system("cls");
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID adresata do edycji: ";
    cin.sync();
    cin >> idAdresataDoEdycji;
    cout << endl;
    for (int i=0; i<adresaci.size(); i++) {
        if ( idAdresataDoEdycji == adresaci[i].pobierzId()) {
            wyswietlDaneAdresata(adresaci[i]);
            czyIstniejeAdresat = true;
            adresatTymczasowy = adresaci[i];
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            wybor = MetodyPomocnicze::wczytajZnak();
            if (wybor == 't') {
                system("cls");
                cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
                cout << "---------------------------" << endl;
                cout << "Ktore dane zaktualizowac: " << endl;
                cout << "1 - Imie" << endl;
                cout << "2 - Nazwisko" << endl;
                cout << "3 - Numer telefonu" << endl;
                cout << "4 - Email" << endl;
                cout << "5 - Adres" << endl;
                cout << "6 - Powrot " << endl;
                cout << endl << "Twoj wybor: ";

                wybor = MetodyPomocnicze::wczytajZnak();

                system("cls");
                cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

                switch (wybor) {
                case '1':
                    cout << "Podaj nowe imie: ";
                    adresatTymczasowy.ustawImie(MetodyPomocnicze::wczytajLinie());
                    //adresaci[i].imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].imie);
                    //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                case '2':
                    cout << "Podaj nowe nazwisko: ";
                    adresatTymczasowy.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                    //adresaci[i].nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].nazwisko);
                    //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                case '3':
                    cout << "Podaj nowy numer telefonu: ";
                    adresatTymczasowy.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                    //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                case '4':
                    cout << "Podaj nowy email: ";
                    adresatTymczasowy.ustawEmail(MetodyPomocnicze::wczytajLinie());
                    //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                case '5':
                    cout << "Podaj nowy adres zamieszkania: ";
                    adresatTymczasowy.ustawAdres(MetodyPomocnicze::wczytajLinie());
                    //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                case '6':
                    cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                    break;
                }
                wyswietlDaneAdresata(adresatTymczasowy);
                adresaci = plikZAdresatami.edytujAdresataWPliku(adresatTymczasowy, ID_ZALOGOWANEGO_UZYTKOWNIKA);
                return;
            } else {
                cout << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << "Adresat o podanym ID nie zostal znaleziony! " << endl;
        system("pause");
    }
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    system("cls");
    cout << ">>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    cin.clear();
    cin.sync();
    cout << "Podaj imie: ";
    getline(cin, imie);
    adresat.ustawImie(imie);
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    getline(cin, nazwisko);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    getline(cin, numerTelefonu);
    adresat.ustawNumerTelefonu(numerTelefonu);
    cout << "Podaj email: ";
    getline(cin, email);
    adresat.ustawEmail(email);
    cout << "Podaj adres: ";
    getline(cin, adres);
    adresat.ustawAdres(adres);
    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    system("cls");
    cout << ">>> WYSWIETLANIE WSZYSTKICH ADRESATOW <<<" << endl << endl;
    if ((!adresaci.empty())) {
        for (int i = 0; i < adresaci.size(); i++) {
            wyswietlDaneAdresata(adresaci[i]);
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresataPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    bool czyZnaleziono = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (int i=0; i<adresaci.size(); i++) {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(adresaci[i]);
                czyZnaleziono = true;
            }
        }
        if (!czyZnaleziono)
            cout << "Nie znaleziono adresata o imieniu: " << imiePoszukiwanegoAdresata << endl;

    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresataPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    bool czyZnaleziono = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (int i=0; i<adresaci.size(); i++) {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(adresaci[i]);
                czyZnaleziono = true;
            }
        }
        if (!czyZnaleziono)
            cout << "Nie znaleziono adresata o nazwisku: " << nazwiskoPoszukiwanegoAdresata << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

