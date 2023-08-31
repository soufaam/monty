#include "monty.h"

/**
* rotr - rotr function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void rotr(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = tmp->prev;
			tmp->prev = NULL;
			*header = tmp;
			return;
		}
		tmp = tmp->next;
		tmp->prev->next = tmp->prev->prev;
		tmp->prev->prev = tmp;
	}
	line_number++;
}
