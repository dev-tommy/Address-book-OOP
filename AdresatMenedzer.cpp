#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    adresaci = plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    idZalogowanegoUzytkownika = 0;

}
void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
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

        if (idZalogowanegoUzytkownika == adresaci[i].pobierzIdUzytkownika()) {
            wyswietlDaneAdresata(adresaci[i]);
        }
    }
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA) {
    idZalogowanegoUzytkownika = ID_ZALOGOWANEGO_UZYTKOWNIKA;
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

