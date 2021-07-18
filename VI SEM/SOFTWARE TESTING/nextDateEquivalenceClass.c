#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main()
{
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    int nextDay, nextMonth, nextYear;
    int numDaysInMonth;


    printf("Enter the date, month and year: ");
    scanf("%d%d%d", &day, &month, &year);

    bool isvalid = true;    

    if (year < 1812 || year > 2012)
    {
        printf("Year not in range [1812..2012]!\n");
        isvalid = false;
    }
    
    if (month < 1 || month > 12)
    {
        printf("Month not in range [1..12]\n");
        isvalid = false;
    }

    if (day < 1 || day > 31)
    {
        printf("Day not in range [1..31]\n");
        isvalid = false;
    }
    
    if (!isvalid) return 0;


    if (month == 2 && isLeapYear(year)) numDaysInMonth = 29;
    else if (month >= 1 && month <= 12) numDaysInMonth = monthDays[month - 1];

    if (day > numDaysInMonth) {
        printf("Invalid input day\n");
        return 0;
    }


    nextDay = day+1;
    nextMonth = month;
    nextYear = year;

    if (nextDay > numDaysInMonth) {
        nextDay = 1;
        nextMonth++;
    }

    if (nextMonth > 12) {
        nextMonth = 1;
        nextYear++;
    }

    printf("Given date is %d-%d-%d\n", day, month, year);
    printf("Next date is %d-%d-%d\n", nextDay, nextMonth, nextYear);
    return 0;
}