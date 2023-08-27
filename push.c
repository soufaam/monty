#include "monty.h"


/**
* _push - push function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _push(stack_t **header, unsigned int line_number)
{
	stack_t *node = NULL, *tmp = *header;
	int num = 0;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		write(STDERR_FILENO, "Error: malloc failed\n",
		_strlen("Error: malloc failed\n"));
		exit(EXIT_FAILURE);
	}
	if (lt.val)
		num = atoi(lt.val);
	else
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": usage: push integer\n",
		_strlen(": usage: push integer\n"));
		free_stack(node);
		exit(EXIT_FAILURE);
	}
	if (tmp)
	{
		node->next = tmp;
		tmp->prev = node;
	}
	else
		node->next = NULL;
	node->prev = NULL;
	node->n = num;
	*header = node;
}

/**
* _swap - swap function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _swap(stack_t **header, unsigned int line_number)
{
	stack_t *header_tmp = *header, *tmp = *header;
	int i = 0;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't swap, stack too short\n",
		_strlen(": can't swap, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	*header = header_tmp->next;
	header_tmp->next = (*header)->next;
	(*header)->next = header_tmp;
	(*header)->prev = NULL;
	header_tmp->prev = *header;
}

/**
* _add - _add function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _add(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int i = 0, sum = 0;

	while (tmp)
	{
		i++;
		sum += tmp->n;
		if (i >= 2)
			break;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't add, stack too short\n",
		_strlen(": can't add, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	(*header)->n = sum;
}
