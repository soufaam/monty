#include "monty.h"

/**
* reverstack - rotr function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void reverstack(stack_t **header, unsigned int line_number)
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

/**
* rotr - rotr function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void rotr(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int store0 = 0, store1, flag = 0;

	if (!tmp)
		return;
	store0 = tmp->n;
	while (tmp)
	{
		if (!tmp->next)
		{
			(*header)->n = store0;
			return;
		}
		if (!flag)
		{
			store0 = tmp->n;
			flag = 1;
		}
		store1 = tmp->next->n;
		tmp->next->n = store0;
		store0 = store1;
		tmp = tmp->next;
	}
	line_number++;
}
