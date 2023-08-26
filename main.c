#include "monty.h"


var_t lt = {"NULL"};

/**
 * main - entry point
 * @argc: The number of argument
 * @argv: the arguements vector
 *
 * Return: Always 0 (Success) 
 */

int main(int argc, char **argv)
{
	size_t buffer_size = 0, i = 0;
	size_t numberchar;
	char *str = NULL, **grid;
	stack_t *header;
	FILE *file;

	error_handling(argc, argv, &file);
	numberchar = getline(&str, &buffer_size, file);
	while (numberchar > 0)
	{
		buffer_size = 0;
		grid = strtow(str, ' ');
		if (!grid)
			continue;
		exec_cmd(&header, grid, i);
		numberchar = getline(&str, &buffer_size, file);
		i++;
		free_grid(grid);
	}
	free_stack(header);
	exit(EXIT_SUCCESS);
	return (0);
}
