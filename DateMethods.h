#ifndef DATEMETHODS_H
#define DATEMETHODS_H
#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <regex>

using namespace std;

class DateMethods
{
    static int isYearLeap(int year);
public:
    static bool validateDate(string &date);
    static int convertStringDateToInt(const string &dateAsString);
    static string convertIntDateToStringWithDashes(int dateAsInt);
    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();

};

#endif
