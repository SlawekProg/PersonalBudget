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

public:
    UserManager(string userFileName):userFile(userFileName){
        users = userFile.loadUserFromFile();
    };

    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif
