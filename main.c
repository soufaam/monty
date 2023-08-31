#include "monty.h"
#define MAX_LINE_LENGTH 1024

var_t lt = {NULL, NULL, NULL, NULL, 0};
/**
 * main - entry point
 * @argc: The number of argument
 * @argv: the arguements vector
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	int i = 1, index;
	size_t numberchar;
	char str[MAX_LINE_LENGTH];
	stack_t *header = NULL;

	error_handling(argc, argv, &lt.file);
	while (fgets(str, sizeof(str), lt.file))
	{
		numberchar = _strlen(str);
		if (numberchar > 0 && str[numberchar - 1] == '\n')
			str[numberchar - 1] = '\0';
		lt.biggrid = strtow(str, ';');
		for (index = 0; lt.biggrid && lt.biggrid[index]; index++)
		{
			lt.grid = strtow(lt.biggrid[index], ' ');
			if (!lt.grid || lt.grid[0][0] == '#')
			{
				free_grid(lt.grid);
				continue;
			}
			exec_cmd(&header, lt.grid, i + index);
			free_grid(lt.grid);
		}
		if (!lt.biggrid)
			index++;
		i += index;
		free_grid(lt.biggrid);
	}
	fclose(lt.file);
	free_stack(header);
	exit(EXIT_SUCCESS);
	return (0);
}
