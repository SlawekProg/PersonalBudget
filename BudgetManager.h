#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "OperationFile.h"
#include "Operation.h"
#include "Type.h"
#include <vector>

using namespace std;

class BudgetManager
{
    int const LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate,int endDate);
    double calculateBalance(int startDate,int endDate,const Type &type);
 public:
     BudgetManager(string incomeFileName,string expenseFileName,int loggedUserId)
     :incomeFile(incomeFileName),expenseFile(expenseFileName),LOGGED_USER_ID(loggedUserId){};


     void addIncome();
     void addExpense();
     void showCurrentMonthBalance();
     void showPreviousMonthBalance();
     void showCustomPeriodBalance();


};


#endif
