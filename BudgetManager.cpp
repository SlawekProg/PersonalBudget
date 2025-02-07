#include "BudgetManager.h"

using namespace std;

void BudgetManager::showBalance(int startDate,int endDate){

}
double BudgetManager::calculateBalance(int startDate,int endDate){

}
void BudgetManager::addIncome(){
    Operation income;
    string date;

    income.id = incomeFile.getLastId() + 1;
    income.userId = LOGGED_USER_ID;

    cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";
    date = Utils::readLine();
    income.date = DateMethods::convertStringDateToInt(date);
    cout << "Podaj opis przychodu: ";
    income.item = Utils::readLine();
    income.amount = Utils::getValidatedAmount();

    incomes.push_back(income);
    incomeFile.addOperationToFile(income,"Income");

}
void BudgetManager::addExpense(){
    Operation expense;
    string date;

    expense.id = expenseFile.getLastId() + 1;
    expense.userId = LOGGED_USER_ID;
    cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";
    date = Utils::readLine();
    expense.date = DateMethods::convertStringDateToInt(date);
    cout << "Podaj opis przychodu: ";
    expense.item = Utils::readLine();
    expense.amount = Utils::getValidatedAmount();

    expenses.push_back(expense);
    expenseFile.addOperationToFile(expense,"Expense");
}
void BudgetManager::showCurrentMonthBalance(){

}
void BudgetManager::showPreviousMonthBalance(){

}
void BudgetManager::showCustomPeriodBalance(){

}
