#include <stdio.h>
#include <time.h>

long long int count = 0;
long long int multiply = 0;

void step(int start, int aim)
{
    count++;
    if (count == TMP_MAX)
    {
        multiply++;
        count = 0;
    }
    printf("%i -> %i Step: %lli\n", start, aim, count);
}

void towers(int start, int aim, int num)
{
    if (num>1)
    {
        int buff = 6 - start - aim;
        towers(start, buff, num - 1);
        step(start, aim);
        towers(buff, aim, num - 1);
    }
    else
    {
        step(start, aim);
    }
}

int main()
{
    int start, aim, num;
    scanf("%i%i%i", &start, &aim, &num);
    time_t t_count = time(NULL);
    towers(start, aim, num);
    t_count = time(NULL) - t_count;
    printf("\nSteps count: %lli * TMP_MAX + %lli\nTime: %lli secons\n", multiply, count, t_count);
}