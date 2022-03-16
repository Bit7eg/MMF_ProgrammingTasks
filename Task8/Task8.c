#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} date;

int main()
{
    int interval, sum;
    date entered;
    scanf("%i%i%i%i", &entered.day, &entered.month, &entered.year, &interval);
    while (interval > 0)
    {
        sum = entered.day + interval;
        switch (entered.month) {
        case 2: {
            if ((entered.year % 400 == 0) || ((entered.year % 100 != 0) && (entered.year % 4 == 0)))
            {
                if (sum > 29)
                {
                    interval -= 30 - entered.day;
                    entered.day = 1;
                    entered.month++;
                }
                else
                {
                    entered.day = sum;
                    interval = 0;
                }
            }
            else
            {
                if (sum > 28)
                {
                    interval -= 29 - entered.day;
                    entered.day = 1;
                    entered.month++;
                }
                else
                {
                    entered.day = sum;
                    interval = 0;
                }
            }
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if (sum > 30)
            {
                interval -= 31 - entered.day;
                entered.day = 1;
                entered.month++;
            }
            else
            {
                entered.day = sum;
                interval = 0;
            }
            break;
        }
        case 12: {
            if (sum > 31)
            {
                interval -= 32 - entered.day;
                entered.day = 1;
                entered.month = 1;
                entered.year++;
            }
            else
            {
                entered.day = sum;
                interval = 0;
            }
            break;
        }
        default: {
            if (sum > 31)
            {
                interval -= 32 - entered.day;
                entered.day = 1;
                entered.month++;
            }
            else
            {
                entered.day = sum;
                interval = 0;
            }
            break;
        }
        }
    }
    printf("%.2i.%.2i.%i", entered.day, entered.month, entered.year);
}