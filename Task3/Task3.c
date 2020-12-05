#include <stdio.h>
#include <string.h>

char int_to_char(int);
int power(int, int, int);

int main()
{
	int number; 
	int source; 
	int target;

	scanf("%d %d %d", &number, &source, &target);

	if (target > 36 || source > 10)
	{
		printf("ERROR!");
	}

	else
	{
		power(number, source, target);
	}

	return 0;
}

char int_to_char(int number)
{
	if (number >= 0 && number <= 9)
	{
		return number + '0';
	}

	else if (number >= 10 && number <= 36)
	{
		return number - 10 + 'A';
	}

	else
	{
		return ' ';
	}
}

int power(int number, int source, int target)
{
	int result_in_ten = 0;

	char res[30];

	for (int q = 0; q < 30; q++)
	{
		res[q] = 0;
	}

	while (number > 0)
	{
		static int pow = 1;

		result_in_ten += number % 10 * pow;

		pow *= source;

		number /= 10;

		if (number <= 0)
		{
			pow = 1;
		}
	}

	while (result_in_ten > 0)
	{
		static int q = 0;

		res[q++] = int_to_char(result_in_ten % target);

		result_in_ten /= target;

		if (result_in_ten <= 0)
		{
			q = 0;
		}
	}

	int length = strlen(res);

	for (long int q = 0; q < length / 2; q++)
	{
		res[q] += res[length - 1 - q];

		res[length - 1 - q] = res[q] - res[length - q - 1];

		res[q] -= res[length - 1 - q];
	}

	printf("%s\n\n\n\n\n", res);

	return 0;
}