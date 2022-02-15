#include <stdio.h>
#include <math.h>

int main()
{
    const double step = 3.0 / 20;
    double sum = 0;
	for (double i = -1 + step / 2; i < 2; i += step)
	{
		sum += (i / ((i * i + 1) + (i * i + 1))) * step;
	}
	printf("%f", sum);
}