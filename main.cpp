#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"

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
    BudgetMainApp budgetMainApp("users.xml","incomes.xml","expenses.xml");


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
