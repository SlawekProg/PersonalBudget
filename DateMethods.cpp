#include "DateMethods.h"

using namespace std;

void DateMethods::calculateCurrentDate(map<string,int> &currentDate){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    currentDate["year"] = 1900 + ltm->tm_year;
    currentDate["month"] = 1 + ltm->tm_mon;
    currentDate["day"] = ltm->tm_mday;
}
int DateMethods::isYearLeap(int year){

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}
bool DateMethods::validateDate(string &date){
    regex datePattern(R"(^\d{4}-\d{2}-\d{2}$)");
    int year, month, day;
    if (!regex_match(date, datePattern)){
        return false;
        }
        else
        {
            sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
            int daysInMonth[] = {31, isYearLeap(year)? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int monthDay = daysInMonth[month - 1];

            if (year < 2000 || month < 1 || month > 12 || day < 1 || day > monthDay) {
                return false;
            }
            else
            {
                return true;
            }
        }
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
        time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    return year * 10000 + month * 100 + day;
}
int DateMethods::getCurrentMonthFirstDayDate(){
        time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = 1;
    return year * 10000 + month * 100 + day;
}
int DateMethods::getPreviousMonthFirstDayDate(){
        time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = 1;

    if (month == 1) {
        month = 12;
        year -= 1;
    } else {
        month -= 1;
    }

    return year * 10000 + month * 100 + day;
}
int DateMethods::getPreviousMonthLastDayDate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;

    if (month == 1) {
        month = 12;
        year -= 1;
    } else {
        month -= 1;
    }

    int daysInMonth[] = {31, isYearLeap(year)? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = daysInMonth[month - 1];

    return year * 10000 + month * 100 + day;
}
