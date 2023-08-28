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
		free_grid(lt.biggrid);
		exit(EXIT_FAILURE);
}
/**
* isInteger - ENTRYPOINT
*@str: string var
* Return: 0 success or uint
*/
int isInteger(char *str)
{
	int length = _strlen(str);
	int i = 0;

	if (!str)
		return (0);
	for (i = 0; i < length; i++)
	{
		if (str[0] == '-')
		continue;
		if (!isdigit(str[i]))
		return (0);
	}
	return (1);
}
/**
* print_push_integer_err - ENTRYPOINT
* @line_number: third param
* @h: header
* @cmd: command
* Return: 0 success or uint
*/
void print_push_integer_err(int line_number, stack_t *h, char **cmd)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": usage: push integer\n",
	_strlen(": usage: push integer\n"));
	free_stack(h);
	fclose(lt.file);
	free_grid(cmd);
	free_grid(lt.biggrid);
	exit(EXIT_FAILURE);

}
/**
* print_push_error - ENTRYPOINT
* @line_number: third param
* @h: header
* @cmd: command
* Return: 0 success or uint
*/
void print_push_error(int line_number, stack_t *h, char **cmd)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": usage: push integer\n",
	_strlen(": usage: push integer\n"));
	free_stack(h);
	fclose(lt.file);
	free_grid(cmd);
	free_grid(lt.biggrid);
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
		{"push", _push}, {"pop", _pop},
		{"pall", printall}, {"pint", printop},
		{"add", _add}, {"sub", _sub}, {"pstr", pstr},
		{"mod", _mod}, {"div", _div}, {"mul", _mul},
		{"nop", _nop}, {"swap", _swap}, {"pchar", _pchar},
		{NULL, NULL}
	};
	lt.val = grid[1];
	for (index = 0; opcode_tab[index].opcode != NULL; index++)
	{
		if (grid && _strcmp(opcode_tab[index].opcode, grid[0]) == 0)
		{
			if (index == 0)
			{
				if (!isInteger(grid[1]))
					print_push_integer_err(line_number, *header, grid);
			}
			opcode_tab[index].f(header, line_number);
			break;
		}
	}
	if (opcode_tab[index].f == NULL)
		print_cmd_notfound(line_number, grid, *header);
}
