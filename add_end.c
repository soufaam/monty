#include "monty.h"

/**
 * add_dnodeint_end - check the code
 * @head: Head
 * @n: number
 * Return: Always EXIT_SUCCESS.
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
		return (NULL);
	if (tmp == NULL)
	{
		node->n = n;
		node->next = tmp;
		node->prev = NULL;
		*head = node;
		return (*head);
	}
	while (tmp)
	{
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
	node->n = n;
	node->next = NULL;
	node->prev = tmp;
	tmp->next = node;
	return (*head);
}
