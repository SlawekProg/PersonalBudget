#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string.h>

using namespace std;

class Utils
{
public:
    static char getCharacter();
    static string readLine();
    static bool validateInput(string input);
};

#endif
