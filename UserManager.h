#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    bool checkIfLoginExist(const string &login);
    User enterUserData();
    void findUserByLogin(const string &login,vector <User>::iterator &itr);
    void findUserById(vector <User>::iterator &itr);

public:
    UserManager(string userFileName)
    : userFile(userFileName){};

    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif
