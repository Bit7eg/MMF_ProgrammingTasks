#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int TEST = 3000;

bool is_simple(int num, int div)
{
	if (div > 1)
	{
		return (num % div != 0) && is_simple(num, div - 1);
	}
	else
	{
		return true;
	}
}

void print_simple_sum_list(int sum, int simple_term)
{
	int simple_term2 = sum - simple_term;
	if (simple_term > 2)
	{
		print_simple_sum_list(sum, simple_term - 1);
	}
	if (is_simple(simple_term, (int)sqrt(simple_term)) && is_simple(simple_term2, (int)sqrt(simple_term2)))
	{
		printf("%i = %i + %i\n", sum, simple_term, simple_term2);
	}
}

bool is_simple_sum(int sum, int simple_term)
{
	bool res = is_simple(simple_term, (int)sqrt(simple_term)) && is_simple(sum - simple_term, (int)sqrt(sum - simple_term));
	if (simple_term > 2)
	{
		return res || is_simple_sum(sum, simple_term - 1);
	}
	else
	{
		return res;
	}
}

int main()
{
	int num;
	scanf("%i", &num);
	if (num > 3)
	{
		print_simple_sum_list(num, num / 2);
	}
	else
	{
		for (num = 4; num < TEST + 1; num += 2)
		{
			if (!is_simple_sum(num, num / 2))
			{
				break;
			}
		}
		printf("%i", (int)(num > TEST));
	}
}