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

    }
    void BudgetMainApp::changeUserPassword(){

    }
    void BudgetMainApp::logoutUser(){

    }

    void BudgetMainApp::addIncome(){

    }
    void BudgetMainApp::addExpense(){

    }
    void BudgetMainApp::showCurrentMonthBalance(){

    }
    void BudgetMainApp::showPreviousMonthBalance(){

    }
    void BudgetMainApp::showCustomPeriodBalance(){

    }
