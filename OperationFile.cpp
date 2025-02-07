#include "OperationFile.h"

using namespace std;

vector<Operation> OperationFile::loadOperationFromFile(const int loggedUserId,string operationName) {

    vector<Operation> operations;
    CMarkup xml;
     string globalName = (operationName == "Income") ? "Incomes" : "Expenses";

    if (!xml.Load(getFileName())) {
        cerr << "Failed to load XML file: " << getFileName() << endl;
        return operations;
    }
    if (!xml.FindElem(globalName)) {
        cerr << "No 'operation' root element found in XML file!" << endl;
        return operations;
    }
    xml.IntoElem();

    while (xml.FindElem(operationName)) {
        xml.IntoElem();

        int userId = 1;

        if (xml.FindElem("userId")) userId = std::stoi(xml.GetData());
        if (userId != loggedUserId) {
            xml.OutOfElem();
            continue;
        }

        Operation operation;
        operation.userId = userId;

        xml.ResetMainPos();
        if (xml.FindElem("id")) operation.id = std::stoi(xml.GetData());
        if (xml.FindElem("date")) operation.date = std::stoi(xml.GetData());
        if (xml.FindElem("item")) operation.item = xml.GetData();
        if (xml.FindElem("amount")) operation.amount = std::stod(xml.GetData());

        xml.OutOfElem();
        operations.push_back(operation);
    }
    return operations;
}
bool OperationFile::addOperationToFile(const Operation &operation, string operationName) {
    CMarkup xml;
    string globalName = (operationName == "Income") ? "Incomes" : "Expenses";
    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(globalName);
    }

    if (!xml.FindElem(globalName)) {
        cerr << "Error: Could not find root element '" << globalName << "' in XML file!" << endl;
        return false;
    }

    xml.IntoElem();
    xml.AddElem(operationName);
    xml.IntoElem();

    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);

    ostringstream stream;
    stream << fixed << setprecision(2) << operation.amount;
    xml.AddElem("amount", stream.str());

    if (!xml.Save(getFileName())) {
        cerr << "Error: Failed to save XML file!" << endl;
        return false;
    }
    return true;
}



