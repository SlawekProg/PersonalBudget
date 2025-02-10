#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include <string>

using namespace std;

class Menus
{
public:

    static void loginMenu(){

        system("cls");
        cout << "    >>>  Menu Logowania  <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "9. Zakoncz program" << endl;
        cout << "---------------------------" << endl;
        cout << "Wybierz pozycje z menu: ";
    }
    static void userMenu(){

        system("cls");
        cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Dodaj przychod" << endl;
        cout << "2. Dodaj wydatek" << endl;
        cout << "3. Bilans z biezacego miesiaca" << endl;
        cout << "4. Bilans z poprzedniego miesiaca" << endl;
        cout << "5. Bilans z wybranego okresu" << endl;

        cout << "---------------------------" << endl;
        cout << "7. Zmien haslo" << endl;
        cout << "8. Wyloguj" << endl;
        cout << "---------------------------" << endl;
        cout << "Wybierz pozycje z menu: ";
    }

};

#endif
