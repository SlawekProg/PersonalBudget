#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H
#include "Operation.h"
#include <iostream>
#include <vector>

using namespace std;

class OperationFile
{
public:

    OperationFile(string fileName);
    vector <Operation> loadOperationFromFile(const int loggedUserId);
    bool addOperationToFile(const Operation &operation);
};

#endif
