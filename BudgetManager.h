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
     };


     void addIncome();
     void addExpense();
     void showCurrentMonthBalance();
     void showPreviousMonthBalance();
     void showCustomPeriodBalance();


};


#endif
