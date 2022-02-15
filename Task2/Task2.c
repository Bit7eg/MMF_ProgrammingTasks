#include <stdio.h>
#include <math.h>

int main()
{
	const int accuracy = 20;
	double sum = 0, step = 3.0 / accuracy;
	for (double i = -1 + step / 2; i < 2; i += step)
	{
		sum += (i / ((i * i + 1) * (i * i + 1))) * step;
	}
	printf("%f", sum);
}