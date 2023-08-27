#include "monty.h"


/**
 * free_stack - check the code
 * @head: Head
 * Return: Always EXIT_SUCCESS.
 */

void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	if (!head)
		return;
	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
	head = NULL;
}
