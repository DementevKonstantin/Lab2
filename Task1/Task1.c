#include <stdio.h>

long get_fibbonachi_via_cycle(long);

int main()
{
	long number;

	scanf("%ld", &number);

	printf("%ld", get_fibbonachi_via_cycle(number));
}

long get_fibbonachi_via_cycle(long number)
{
	long previous_number = 1;
	long res = 1;

	for (long i = 0; i < number - 2; i++)
	{
		res = res + previous_number;
		previous_number = res - previous_number;
	}

	return res;
}