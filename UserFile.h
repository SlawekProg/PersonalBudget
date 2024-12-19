#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "User.h"


using namespace std;

class UserFile
{
public:

    UserFile(string userFileName);

    vector <User> loadUserFromFile();
    bool addUserToFile(const User &user);
    bool changePasswordInFile(int id,const string &password);


};

#endif
