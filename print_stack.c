#include "monty.h"

/**
* printall - ENTRYPOINT
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void printall(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	line_number += line_number;
}

/**
* printop - ENTRYPOINT
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void printop(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	if (!*header || !header)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't pint, stack empty\n",
		_strlen(": can't pall, stack empty\n"));
		free_stack(*header);
		free_grid(lt.grid);
		fclose(lt.file);
		free_grid(lt.biggrid);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
	tmp = tmp->next;
}
