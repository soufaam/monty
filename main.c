#include "monty.h"
#define MAX_LINE_LENGTH 1024

var_t lt = {NULL, NULL};
/**
 * main - entry point
 * @argc: The number of argument
 * @argv: the arguements vector
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	int i = 1;
	size_t numberchar;
	char str[MAX_LINE_LENGTH], **grid;
	stack_t *header = NULL;

	error_handling(argc, argv, &lt.file);
	while (fgets(str, sizeof(str), lt.file))
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
	fclose(lt.file);
	free_stack(header);
	exit(EXIT_SUCCESS);
	return (0);
}
