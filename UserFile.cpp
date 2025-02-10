#include "UserFile.h"

using namespace std;

    vector <User> UserFile::loadUserFromFile(){

        vector <User> users;
        CMarkup xml;

        if (!xml.Load(getFileName())) {
            cerr << "Failed to load XML file: " << getFileName() << endl;
        }
        if (!xml.FindElem("Users")) {
            cerr << "No 'Users' root element found in XML file!" << endl;
        }

        xml.IntoElem();

        while (xml.FindElem("User")) {
            User user;
            xml.IntoElem();

            if (xml.FindElem("UserId")) {
                user.id = std::stoi(xml.GetData());
            }
            if (xml.FindElem("FirstName")) {
                user.firstName = xml.GetData();
            }
            if (xml.FindElem("LastName")) {
                user.lastName = xml.GetData();
            }
            if (xml.FindElem("Login")) {
                user.login = xml.GetData();
            }
            if (xml.FindElem("Password")) {
                user.password = xml.GetData();
            }

            xml.OutOfElem();

            users.push_back(user);
        }
        return users;
}

    bool UserFile::addUserToFile(const User &user){

            CMarkup xml;
            bool fileExists = xml.Load( getFileName() );
            if (!fileExists)
            {
                xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
                xml.AddElem("Users");
            }

            xml.FindElem();
            xml.IntoElem();
            xml.AddElem("User");
            xml.IntoElem();

            xml.AddElem("UserId",user.id);
            xml.AddElem("FirstName",user.firstName);
            xml.AddElem("LastName",user.lastName);
            xml.AddElem("Login", user.login);
            xml.AddElem("Password", user.password);

            xml.Save(getFileName());
    }

    bool UserFile::changePasswordInFile(int id,const string &password){

        CMarkup xml;
        bool fileExists = xml.Load(getFileName());
        if (!fileExists) {
            cout << "File not found or cannot be loaded!" << endl;
            return false;
        }

        if (!xml.FindElem("Users")) {
            cout << "No <Users> element in XML!" << std::endl;
            return false;
        }
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            if (xml.FindElem("UserId") && stoi(xml.GetData()) == id) {
                if (xml.FindElem("Password")) {
                    xml.SetData(password);
                    xml.Save(getFileName());
                    return true;
                }
            }
            xml.OutOfElem();
        }
        return false;
    }

