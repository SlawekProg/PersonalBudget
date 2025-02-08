#include "BudgetMainApp.h"

using namespace std;

bool BudgetMainApp::isUserLoggedIn(){
    if (userManager.getLoggedUserId() > 0)
    return true;
else
    return false;
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}
void BudgetMainApp::loginUser(){
    userManager.loginUser();
    budgetManager = new BudgetManager(INCOME_FILE_NAME,EXPENSE_FILE_NAME,userManager.getLoggedUserId());
}
void BudgetMainApp::changeUserPassword(){
    userManager.changeUserPassword();
}
void BudgetMainApp::logoutUser(){
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::addIncome(){
    budgetManager->addIncome();
}
void BudgetMainApp::addExpense(){
    budgetManager->addExpense();
}
void BudgetMainApp::showCurrentMonthBalance(){
    budgetManager->showCurrentMonthBalance();
}
void BudgetMainApp::showPreviousMonthBalance(){
    budgetManager->showPreviousMonthBalance();
}
void BudgetMainApp::showCustomPeriodBalance(){
    budgetManager->showCustomPeriodBalance();
}
