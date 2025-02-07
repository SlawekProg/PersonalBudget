#include "File.h"
using namespace std;

string File::getFileName(){
    return FILE_NAME;
}
int File::getLastId(){
  CMarkup xml;
    string globalName = (FILE_NAME == "incomes.xml") ? "Incomes" : "Expenses";
    string operationName = (FILE_NAME == "incomes.xml") ? "Income" : "Expense";

    if (!xml.Load(FILE_NAME)) {
        cerr << "Failed to load XML file: " << getFileName() << endl;
        return 0;
    }
    if (!xml.FindElem(globalName)) {
        cerr << "No root element found in XML file!" << endl;
        return 0;
    }
    xml.IntoElem();

    int lastId = 0;

    while (xml.FindElem(operationName)) {
        xml.IntoElem();

        if (xml.FindElem("id")) lastId = std::stoi(xml.GetData());
        xml.OutOfElem();
    }
    return lastId;
}

