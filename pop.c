#include "monty.h"

/**
* print_cmd_pop_err - print error
* @h: int parameter
* @line_number: line number
* Return: 0 success or uint
*/
void print_cmd_pop_err(int line_number, stack_t *h)
{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": unknown instruction ",
		_strlen(": unknown instruction "));
		write(STDERR_FILENO, lt.grid[0], _strlen(lt.grid[0]));
		write(STDERR_FILENO, "\n", 1);
		free_stack(h);
		fclose(lt.file);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		exit(EXIT_FAILURE);
}
/**
* _pop - ENTRYPOINT
* @header: int parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _pop(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	if (tmp)
	{
		*header = tmp->next;
		if (*header)
			(*header)->prev = NULL;
		free(tmp);
	}
	else if (tmp == NULL || header == NULL)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't pop an empty stack\n",
		_strlen(": can't pop an empty stack\n"));
		free_stack(*header);
		free_grid(lt.grid);
		fclose(lt.file);
		free_grid(lt.biggrid);
		exit(EXIT_FAILURE);
	}
}

/**
* _nop - ENTRYPOINT
* @header: int parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _nop(stack_t **header, unsigned int line_number)
{
	(void)header;
	(void)line_number;
}
