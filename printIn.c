#include "monty.h"

/**
* prinInt - ENTRYPOINT
* @var: int parameter
* Return: 0 success or uint
*/
void  prinInt(int var)
{
	char ch;

	if (var < 0)
	{
		write(STDERR_FILENO, "-", 1);
		if (var == -2147483648)
		{
			var = -147483648;
			write(STDERR_FILENO, "2", 1);
		}
		var = -var;
	}
	if (var / 10)
		prinInt(var / 10);
	ch = var % 10 + '0';
	write(STDERR_FILENO, &ch, 1);
}
