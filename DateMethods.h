#ifndef DATEMETHODS_H
#define DATEMETHODS_H
#include <iostream>
#include <map>
#include <string>

using namespace std;

class DateMethods
{
    void calculateCurrentDate(map<string,int> &currentDate);
    int isYearLeap(int year);
public:
    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
};

#endif
