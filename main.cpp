#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"
#include "Utils.h"
#include "Menus.h"
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
            Menus::loginMenu();
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
            Menus::userMenu();
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
