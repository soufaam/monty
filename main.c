#include "monty.h"
#define MAX_LINE_LENGTH 1024

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
	size_t i = 0;
	size_t numberchar;
	char str[MAX_LINE_LENGTH], **grid;
	stack_t *header = NULL;
	FILE *file;

	error_handling(argc, argv, &file);
	while (fgets(str, sizeof(str), file))
	{
		numberchar = _strlen(str);
		if (numberchar > 0 && str[numberchar - 1] == '\n')
			str[numberchar - 1] = '\0';
		grid = strtow(str, ' ');
		if (!grid)
			continue;
		exec_cmd(&header, grid, i);
		i++;
		free_grid(grid);
	}
	fclose(file);
	free_stack(header);
	exit(EXIT_SUCCESS);
	return (0);
}
