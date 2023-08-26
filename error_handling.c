#include "monty.h"


void error_handling(int argc, char **argv, FILE **file)
{
	FILE * fil;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
	fil = fopen(argv[1], "r");
	if (!fil)
	{
		write(STDERR_FILENO, "Error: Can't open file", _strlen("Error: Can't open file"));
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", _strlen("\n"));
		exit(EXIT_FAILURE);
	}
	*file = fil;
}
