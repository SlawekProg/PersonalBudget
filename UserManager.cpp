#include "UserManager.h"

using namespace std;

    bool UserManager::checkIfLoginExist(const string &login){

         for (int i = 0; i < users.size(); i++){
            if (users[i].login == login);
        }
        return false;
    }

    User UserManager::enterUserData(){

    User user;

    if (users.empty() == true)
        user.id = 1;
    else
        user.id = users.back().id + 1;

    cout << "Podaj imie: ";
    user.firstName = Utils::readLine();
     cout << "Podaj nazwisko: ";
    user.lastName = Utils::readLine();

    do
    {
        cout << "Podaj login: ";
        user.login = Utils::readLine();

    } while (checkIfLoginExist(user.login) == true);

    cout << "Podaj haslo: ";
    user.password = Utils::readLine();

    return user;
    }

    void UserManager::findUserByLogin(const string &login,vector <User>::iterator &itr){

    }
    void UserManager::findUserById(vector <User>::iterator &itr){

    }

    void UserManager::registerUser(){

        User user = enterUserData();
        users.push_back(user);
        userFile.addUserToFile(user);

    }
    void UserManager::loginUser(){

    }
    void UserManager::changeUserPassword(){

    }
    void UserManager::logoutUser(){

    }

    bool UserManager::isUserLoggedIn(){

    }
    int UserManager::getLoggedUserId(){
        return loggedUserId;
    }
