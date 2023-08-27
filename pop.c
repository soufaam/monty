#include "monty.h"

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
		exit(EXIT_FAILURE);
	}
}

void _nop(stack_t **header, unsigned int line_number)
{
	(void)header;
	(void)line_number;
}