#include <stdio.h>

typedef enum WeekDay{
    SUNDAY=1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
}WeekDay;

typedef enum Month
{
    JANUARY=1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
} Month;

void printMonth(Month m)
{
    switch(m)
    {
        case JANUARY:
            printf("JANUARY\n");
            break;
        case FEBRUARY:
            printf("FEBRUARY\n");
            break;
        case MARCH:
            printf("MARCH\n");
            break;
        case APRIL:
            printf("APRIL\n");
            break;
        case MAY:
            break;
        case JUNE:
            printf("JUNE\n");
            break;
        case JULY:
            printf("JULY\n");
            break;
        case AUGUST:
            printf("AUGUST\n");
            break;
        case SEPTEMBER:
            printf("SEPTEMBER\n");
            break;
        case OCTOBER:
            printf("OCTOBER\n");
            break;
        case NOVEMBER:
            printf("NOVEMBER\n");
            break;
        case DECEMBER:
            printf("DECEMBER\n");
            break;
    };
}
void printWeekDay(WeekDay wd)
{
    switch(wd)
    {
        case SUNDAY:
            printf("SUNDAY\n");
            break;
        case MONDAY:
            printf("MONDAY\n");
            break;
        case TUESDAY:
            printf("TUESDAY\n");
            break;
        case WEDNESDAY:
            printf("WEDNESDAY\n");
            break;
        case THURSDAY:
            printf("THURSDAY\n");
            break;
        case FRIDAY:
            printf("FRIDAY\n");
            break;
        case SATURDAY:
            printf("SATURDAY\n");
            break;
    };
}

void printWeekAndMonth(WeekDay wd, Month m)
{
    printWeekDay(wd);
    printMonth(m);
}

int main()
{
    WeekDay wd = SUNDAY;
    Month month = JANUARY;
    // printWeekAndMonth(APRIL,MONDAY); // throws warnings
    printWeekAndMonth(MONDAY, APRIL);
    //printWeekAndMonth(2,4); // works but wrong way to implement.
    printf("Sizeof Month:%lu\n WeekDay:%lu\n",sizeof(Month), sizeof(WeekDay));
}