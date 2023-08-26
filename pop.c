#include "monty.h"


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
		write(STDERR_FILENO, ": can't pop an empty stack\n", _strlen("L : can't pop an empty stack\n"));
	}
}