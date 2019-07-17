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

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

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
    for (int i = 0; i < adresaci.size(); i++) {
        wyswietlDaneAdresata(adresaci[i]);
    }
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

