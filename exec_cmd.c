#include "monty.h"

/**
* exec_cmd - ENTRYPOINT
* @header: constant
* @grid: second param
* @line_number: third param
* Return: 0 success or uint
*/

void exec_cmd(stack_t **header, char **grid, int line_number)
{
	int index = 0;

	instruction_t opcode_tab[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", printall},
		{NULL, NULL}
	};
	lt.val = grid[1];
	for (index = 0; opcode_tab[index].opcode != NULL; index++)
	{
		if (grid && _strcmp(opcode_tab[index].opcode, grid[0]) == 0)
		{
			if (index == 0)
			{
				if (!grid[1])
				{
					write(STDERR_FILENO, "L", 1);
					prinInt(line_number);
					write(STDERR_FILENO, ": usage: push integer\n",
					_strlen(": usage: push integer\n"));
					exit(EXIT_FAILURE);
				}
			}
			opcode_tab[index].f(header, line_number);
			break;
		}
	}
	if (opcode_tab[index].f == NULL)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": unknown instruction\n",
		_strlen(": unknown instruction\n"));
		exit(EXIT_FAILURE);
	}
}
