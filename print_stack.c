#include "monty.h"


void printall(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	if (!*header || !header)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't pall, stack empty\n", _strlen(": can't pall, stack empty\n"));
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}