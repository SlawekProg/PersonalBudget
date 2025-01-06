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

        User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->login == login)
        {
            for (int tryNumber = 3; tryNumber > 0; tryNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tryNumber << ": ";
                password = Utils::readLine();

                if (itr->password == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr->id;
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");

        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    }
    void UserManager::changeUserPassword(){
        string newPassword = "";
        cout << "Podaj nowe haslo: ";
        newPassword = Utils::readLine();

        for(vector <User> ::iterator itr = users.begin(); itr != users.end(); itr++){
            if(itr->id == loggedUserId){
                itr->password = newPassword;
            }
        }
       if(userFile.changePasswordInFile(loggedUserId, newPassword)) cout << "Haslo zostalo zmienione: ";
       system("pause");
    }
    void UserManager::logoutUser(){
        loggedUserId = 0;
        cout << "Uzytkownik zostal wylogowany";
        cout << loggedUserId;
        system("pause");
    }

    bool UserManager::isUserLoggedIn(){
        if(loggedUserId == 0){
            return false;
        }else return true;
    }
    int UserManager::getLoggedUserId(){
        return loggedUserId;
    }
