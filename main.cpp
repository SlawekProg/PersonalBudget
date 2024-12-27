#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;


/*
void addUserElementToXml(CMarkup xml)
{
    string login,userID,password;

    xml.AddElem("UserId",userID);
    xml.AddElem("Login", login);
    xml.AddElem("Password", password);

}
void addItemElementToXml(CMarkup xml)
{
    string date,item,incomeId,amount;

    xml.AddElem("Date",date);
    xml.AddElem("Item",item);
    xml.AddElem("IncomeId",incomeId);
    xml.AddElem("Amount",amount);
}
*/
int main()
{
    Utils utils;
    BudgetMainApp budgetMainApp("users.xml","incomes.xml","expenses.xml");

    char choice = '9';
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

/*
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();

    xml.AddElem("UserId","123");
    xml.AddElem("Login", "154.55");
    xml.AddElem("Password", "2024-12-12");


    xml.Save("users.xml");
*/
    return 0;
}
