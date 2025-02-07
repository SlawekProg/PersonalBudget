#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H
#include "Operation.h"
#include <iostream>
#include <vector>
#include "File.h"
#include "Markup.h"
#include <iomanip>
#include <sstream>

using namespace std;

class OperationFile:public File
{
public:

    OperationFile(string fileName):File(fileName){};
    vector <Operation> loadOperationFromFile(const int loggedUserId,string operationName);
    bool addOperationToFile(const Operation &operation,string operationName);
};

#endif
