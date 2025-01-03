#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;

int main()
{
    Utils utils;
    BudgetMainApp budgetMainApp("users.xml","incomes.xml","expenses.xml");

    char choice = '0';
     system("cls");

     cout << "    >>>  MAIN MENU  <<<" << endl;
     cout << "---------------------------" << endl;
     cout << "1. Regisration" << endl;
     cout << "2. Log in" << endl;
     cout << "9. End program" << endl;
     cout << "---------------------------" << endl;
     cout << "Your choice: ";

	while (true)
	{
		if (!budgetMainApp.isUserLoggedIn())
		{
			choice = utils.getCharacter();

			if (choice == '1') budgetMainApp.registerUser();
			else if (choice == '2') budgetMainApp.loginUser();
			else if (choice == '9') exit(0);
		}
		else
		{
		      system("cls");

              cout << " >>> USER MENU <<<" << endl;
              cout << "---------------------------" << endl;
              cout << "1. Add Income" << endl;
              cout << "2. Add Expense" << endl;
              cout << "3. Show Current Month Balance" << endl;
              cout << "4. Show Previous Month Balance" << endl;
              cout << "5. Show Custom Period Balance" << endl;

              cout << "---------------------------" << endl;
              cout << "7. Change User Password" << endl;
              cout << "8. Logout User" << endl;
              cout << "---------------------------" << endl;
              cout << "Your choice: ";

			while (true)
			{
				choice = utils.getCharacter();

				if (choice == '1') budgetMainApp.addIncome();
				else if (choice == '2') budgetMainApp.addExpense();
				else if (choice == '3') budgetMainApp.showCurrentMonthBalance();
				else if (choice == '4') budgetMainApp.showPreviousMonthBalance();
				else if (choice == '5') budgetMainApp.showCustomPeriodBalance();
				else if (choice == '7') budgetMainApp.changeUserPassword();
				else if (choice == '8') { budgetMainApp.logoutUser(); break; }
			}
		}
	}
	return 0;
}
