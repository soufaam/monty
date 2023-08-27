#include "monty.h"


/**
* print_cmd_notfound - ENTRYPOINT
* @line_number: third param
* @cmd: command
* @h: header
* Return: 0 success or uint
*/
void print_cmd_notfound(int line_number, char **cmd, stack_t *h)
{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": unknown instruction ",
		_strlen(": unknown instruction "));
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, "\n", 1);
		free_stack(h);
		fclose(lt.file);
		free_grid(cmd);
		exit(EXIT_FAILURE);
}
/**
* print_push_error - ENTRYPOINT
* @line_number: third param
* Return: 0 success or uint
*/
void print_push_error(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": usage: push integer\n",
	_strlen(": usage: push integer\n"));
	exit(EXIT_FAILURE);
}
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
		{"pint", printop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};
	lt.val = grid[1];
	for (index = 0; opcode_tab[index].opcode != NULL; index++)
	{
		if (grid && _strcmp(opcode_tab[index].opcode, grid[0]) == 0)
		{
			if (index == 0)
				if (!grid[1])
					print_push_error(line_number);
			opcode_tab[index].f(header, line_number);
			break;
		}
	}
	if (opcode_tab[index].f == NULL)
		print_cmd_notfound(line_number, grid, *header);
}
