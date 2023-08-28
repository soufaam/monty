#include "monty.h"

/**
* error_handling - ENTRYPOINT
* @argc: args counter
* @argv: args vector
* @file: file
* Return: 0 success or uint
*/
void error_handling(int argc, char **argv, FILE **file)
{
	FILE *fil;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
	fil = fopen(argv[1], "r");
	if (!fil)
	{
		write(STDERR_FILENO, "Error: Can't open file ",
		_strlen("Error: Can't open file "));
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", _strlen("\n"));
		exit(EXIT_FAILURE);
	}
	*file = fil;
}

/**
* print_zerodiv_error - ENTRYPOINT
* @line_number: line_number
* @h: header
* Return: 0 success or uint
*/
void print_zerodiv_error(stack_t *h, int line_number)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": division by zero\n",
	_strlen(": division by zero"));
	free_stack(h);
	fclose(lt.file);
	free_grid(lt.biggrid);
	exit(EXIT_FAILURE);
}
