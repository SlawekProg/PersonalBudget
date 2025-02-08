#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"
#include "Utils.h"
#include <locale>

using namespace std;

int main()
{
    Utils utils;
    BudgetMainApp budgetMainApp("users.xml","incomes.xml","expenses.xml");

    char choice = '0';

	while (true)
	{
		if (!budgetMainApp.isUserLoggedIn())
		{

            system("cls");

            cout << "    >>>  Menu Logowania  <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << "---------------------------" << endl;
            cout << "Wybierz pozycje z menu: ";

            choice = utils.getCharacter();

            switch(choice){
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                budgetMainApp.loginUser();
                break;
            case '9':
                exit(0);
            }
		}
		else
		{
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

            choice = utils.getCharacter();

            switch (choice){
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.showCustomPeriodBalance();
                break;
            case '7':
                budgetMainApp.changeUserPassword();
                break;
            case '8':
                budgetMainApp.logoutUser();
                break;
            }

        }
	}
	return 0;
}
