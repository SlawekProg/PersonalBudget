#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "UserFile.h"
#include "User.h"
#include "Utils.h"

using namespace std;

class UserManager
{
    int loggedUserId = 0;
    vector <User> users;
    UserFile userFile;

    bool checkIfLoginExist(const string &login);
    User enterUserData();
    void findUserByLogin(const string &login,vector <User>::iterator &itr);
    void findUserById(vector <User>::iterator &itr);

public:
    UserManager(string userFileName):userFile(userFileName){
        users = userFile.loadUserFromFile();

        for (const User& user : users) {

        cout << "UserId: " << user.id << std::endl;
        cout << "FirstName: " << user.firstName << std::endl;
        cout << "LastName: " << user.lastName << std::endl;
        cout << "Login: " << user.login << std::endl;
        cout << "Password: " << user.password << std::endl;
        cout << "------------------------" << std::endl;
    }
    system("pause");
    };

    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif
