#include "PlikZAdresatami.h"

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


vector<Adresat> PlikZAdresatami::usunAdresataZPliku(int idAdresataDoUsuniecia, int idZalogowanegoUzytkownika) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    vector<Adresat> adresaciPoUsunieciu;
    string wczytanaLinia = "";
    Adresat adresatTymczasowy;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "AdresaciUsuwanie.tmp";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if ( (odczytywanyPlikTekstowy.good() == true) &&(tymczasowyPlikTekstowy.good() == true) && (idAdresataDoUsuniecia != 0) ) {
        getline(odczytywanyPlikTekstowy, wczytanaLinia);
        adresatTymczasowy = pobierzDaneAdresata(wczytanaLinia);

        if ( (adresatTymczasowy.pobierzId() != idAdresataDoUsuniecia) && (adresatTymczasowy.pobierzIdUzytkownika() == idZalogowanegoUzytkownika) ) {
            tymczasowyPlikTekstowy << wczytanaLinia;
            adresaciPoUsunieciu.push_back(pobierzDaneAdresata(wczytanaLinia));
        }
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            adresatTymczasowy = pobierzDaneAdresata(wczytanaLinia);
            if ( (adresatTymczasowy.pobierzIdUzytkownika() == idZalogowanegoUzytkownika) ) {
                if (adresatTymczasowy.pobierzId() == idAdresataDoUsuniecia) {
                    continue;
                } else {
                    tymczasowyPlikTekstowy << endl;
                    tymczasowyPlikTekstowy << wczytanaLinia;
                    adresaciPoUsunieciu.push_back(pobierzDaneAdresata(wczytanaLinia));
                }
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
        cout << "Usunieto adresata o ID: " << idAdresataDoUsuniecia << endl;

    }

    if (odczytywanyPlikTekstowy.good())
        odczytywanyPlikTekstowy.close();
    if (tymczasowyPlikTekstowy.good())
        tymczasowyPlikTekstowy.close();

    return adresaciPoUsunieciu;
}

vector<Adresat> PlikZAdresatami::edytujAdresataWPliku(Adresat adresatTymczasowy, int idZalogowanegoUzytkownika) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    vector<Adresat> adresaciPoEdycji;
    string wczytanaLinia = "";
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "AdresaciEdycja.tmp";
    int idAdresataDoEdycji = adresatTymczasowy.pobierzId();
    Adresat pobranyAdresat;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
    if ( (odczytywanyPlikTekstowy.good() == true) &&(tymczasowyPlikTekstowy.good() == true) && (idAdresataDoEdycji != 0) ) {
        getline(odczytywanyPlikTekstowy, wczytanaLinia);
        pobranyAdresat = pobierzDaneAdresata(wczytanaLinia);
        if ((pobranyAdresat.pobierzId() != idAdresataDoEdycji) && (adresatTymczasowy.pobierzIdUzytkownika() == idZalogowanegoUzytkownika)) {
            tymczasowyPlikTekstowy << wczytanaLinia;
        } else {
            tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresatTymczasowy);
        }
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            pobranyAdresat = pobierzDaneAdresata(wczytanaLinia);
            if ((pobranyAdresat.pobierzIdUzytkownika() == idZalogowanegoUzytkownika) &&  (pobranyAdresat.pobierzId() == idAdresataDoEdycji)) {
                tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresatTymczasowy);
                adresaciPoEdycji.push_back(adresatTymczasowy);
            } else {
                tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << wczytanaLinia;
                adresaciPoEdycji.push_back(pobierzDaneAdresata(wczytanaLinia));
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
        cout << "Nadpisano adresata o ID: " << idAdresataDoEdycji << endl;

    }

    if (odczytywanyPlikTekstowy.good())
        odczytywanyPlikTekstowy.close();
    if (tymczasowyPlikTekstowy.good())
        tymczasowyPlikTekstowy.close();

    return adresaciPoEdycji;

}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    bool pustyPlik = czyPlikJestPusty();
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (pustyPlik) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }

    system("pause");
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    idOstatniegoAdresata = 0;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
            if (idZalogowanegoUzytkownika == adresat.pobierzIdUzytkownika())
                adresaci.push_back(adresat);
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    } else
        idOstatniegoAdresata = 0;
    return adresaci;
}


int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

