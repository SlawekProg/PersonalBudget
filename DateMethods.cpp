#include "DateMethods.h"

using namespace std;

void DateMethods::calculateCurrentDate(map<string,int> &currentDate){

}
int DateMethods::isYearLeap(int year){

}
bool DateMethods::validateDate(string &date){

}
int DateMethods::convertStringDateToInt(const string &dateAsString){
    return stoi(dateAsString.substr(0, 4) + dateAsString.substr(5, 2) + dateAsString.substr(8, 2));
}
string DateMethods::convertIntDateToStringWithDashes(int dateAsInt){
    string dateStr = to_string(dateAsInt);

    if (dateStr.length() != 8) {
        throw invalid_argument("Invalid date format");
    }

    return dateStr.substr(0, 4) + "-" + dateStr.substr(4, 2) + "-" + dateStr.substr(6, 2);
}
int DateMethods::getCurrentDate(){

}
int DateMethods::getCurrentMonthFirstDayDate(){

}
int DateMethods::getPreviousMonthFirstDayDate(){

}
int DateMethods::getPreviousMonthLastDayDate(){

}
