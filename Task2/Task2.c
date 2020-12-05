#include <stdio.h>

long get_fibbonachi_via_recursion(long);

int main()
{
	long number;

	scanf("%d", &number);

	printf("%ld", get_fibbonachi_via_recursion(number));
}

long get_fibbonachi_via_recursion(long number)
{
	if (number == 0)
	{
		return 0;
	}

	else if (number == 1 || number == 2)
	{
		return 1;
	}

	static long cache[] = { 1, 1 };

	if (cache[number] == 0)
	{
		cache[number] = get_fibbonachi_via_recursion(number - 1) + get_fibbonachi_via_recursion(number - 2);
	}

	return cache[number];
}
