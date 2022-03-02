#include <stdio.h>

int part_reverse(int len)
{
	int res = 0;
	char ch = getchar();
	if (ch != '\n')
	{
		if (len > 1)
		{
			res = part_reverse(len - 1);
		}
		putchar(ch);
	}
	else
	{
		res = 1;
	}
	return res;
}

void ruled_reversing(int num) {
	if (!part_reverse(num + 5))
	{
		ruled_reversing(num);
	}
}

int main()
{
	int N = 0;
	ruled_reversing(N);
}