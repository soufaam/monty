#include "monty.h"



void _push(stack_t **header, unsigned int line_number)
{
	stack_t *node, *tmp = *header;
	int num = 0;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", _strlen("Error: malloc failed\n"));
		exit(EXIT_FAILURE);
	}
	if (lt.val)
		num = atoi(lt.val);
	else
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": usage: push integer\n", _strlen(": usage: push integer\n"));
		free_stack(node);
		exit(EXIT_FAILURE);
	}
	node->next = tmp;
	if (tmp)
		tmp->prev = node;
	node->prev = NULL;
	node->n = num;
	*header = node;
}