#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

class Menu {
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

public:
    static char wybierzOpcjeZMenuEdycja();
    void wyswietl();

};

#endif // MENU_H
