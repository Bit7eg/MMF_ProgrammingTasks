#include <stdio.h>

int main()
{
    int minute, hour, passed_minutes = 0;
    scanf("%i%i", &hour, &minute);
    hour = (hour * 5 + minute / 12) % 60;
    if (minute % 12 >= 6)
    {
        hour++;
    }
    while (hour != minute)
    {
        minute++;
        passed_minutes++;
        if (minute==60)
        {
            minute = 0;
        }
        if (minute % 12 == 6)
        {
            hour++;
        }
        if (hour == 60)
        {
            hour = 0;
        }
    }
    hour = (hour - minute / 12) / 5;
    printf("\n%ih %im\n", hour, minute);
    printf("%i minutes passed\n", passed_minutes);
}