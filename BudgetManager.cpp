#include "BudgetManager.h"

using namespace std;

void BudgetManager::showBalance(int startDate,int endDate){

    double totalIncome = 0.0, totalExpense = 0.0;

    cout << "Przychody od " << startDate << " do " << endDate << ":\n";
    cout << "-------------------------------------------------\n";
    for (const auto &inc : incomes) {
        if (inc.date >= startDate && inc.date <= endDate) {
            cout << "Data: " << inc.date
                      << " | Opis: " << inc.item
                      << " | Kwota: " << fixed << setprecision(2) << inc.amount << " PLN\n";
            totalIncome += inc.amount;
        }
    }

    cout << "\nWydatki od " << startDate << " do " << endDate << ":\n";
    cout << "-------------------------------------------------\n";
    for (const auto &exp : expenses) {
        if (exp.date >= startDate && exp.date <= endDate) {
            cout << "Data: " << exp.date
                      << " | Opis: " << exp.item
                      << " | Kwota: " << fixed << setprecision(2) << exp.amount << " PLN\n";
            totalExpense += exp.amount;
        }
    }

    double balance = totalIncome - totalExpense;

    cout << "\n-------------------------------------------------\n";
    cout << "Laczne przychody: " << totalIncome << " PLN\n";
    cout << "Laczne wydatki: " << totalExpense << " PLN\n";
    cout << "Saldo: " << balance << " PLN\n";
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
    int startDate = DateMethods::getCurrentMonthFirstDayDate();
    int endDate = DateMethods::getCurrentDate();

    showBalance(startDate, endDate);
}
void BudgetManager::showPreviousMonthBalance(){
    int startDate = DateMethods::getPreviousMonthFirstDayDate();
    int endDate = DateMethods::getPreviousMonthLastDayDate();

    showBalance(startDate, endDate);
}
void BudgetManager::showCustomPeriodBalance(){
    string date;
    cout << "Podaj date poczatkowa w formacie rrrr-mm-dd: ";
    date = Utils::readLine();
    int startDate = DateMethods::convertStringDateToInt(date);

    cout << "Podaj date koncowa w formacie rrrr-mm-dd: ";
    date = Utils::readLine();
    int endDate = DateMethods::convertStringDateToInt(date);

    showBalance(startDate, endDate);
}
