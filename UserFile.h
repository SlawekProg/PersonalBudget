#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "User.h"
#include "File.h"


using namespace std;

class UserFile : public File
{
public:

    UserFile(string userFileName) : File(userFileName){}

    vector <User> loadUserFromFile();
    bool addUserToFile(const User &user);
    bool changePasswordInFile(int id,const string &password);

};
#endif
