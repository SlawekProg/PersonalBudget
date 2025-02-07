#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "OperationFile.h"
#include "Utils.h"
#include "DateMethods.h"
#include "Operation.h"
#include "File.h"
#include <vector>

using namespace std;

class BudgetManager
{
    int const LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    void showBalance(int startDate,int endDate);
    double calculateBalance(int startDate,int endDate);
 public:
     BudgetManager(string incomeFileName,string expenseFileName,int loggedUserId)
     :incomeFile(incomeFileName),expenseFile(expenseFileName),LOGGED_USER_ID(loggedUserId){

     incomes = incomeFile.loadOperationFromFile(LOGGED_USER_ID,"Income");
     expenses = expenseFile.loadOperationFromFile(LOGGED_USER_ID,"Expense");
             for (const Operation& income : incomes) {

        cout << "Id: " << income.id << std::endl;
        cout << "UserId: " << income.userId << std::endl;
        cout << "Date: " << income.date << std::endl;
        cout << "Item: " << income.item << std::endl;
        cout << "Amount: " << income.amount << std::endl;
        cout << "------------------------" << std::endl;
             }
             system("pause");
                     for (const Operation& expense : expenses) {

        cout << "Id: " << expense.id << std::endl;
        cout << "UserId: " << expense.userId << std::endl;
        cout << "Date: " << expense.date << std::endl;
        cout << "Item: " << expense.item << std::endl;
        cout << "Amount: " << expense.amount << std::endl;
        cout << "------------------------" << std::endl;
                     }
                     system("pause");
     };


     void addIncome();
     void addExpense();
     void showCurrentMonthBalance();
     void showPreviousMonthBalance();
     void showCustomPeriodBalance();


};


#endif
