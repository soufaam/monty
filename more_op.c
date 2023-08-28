#include "monty.h"

/**
* print_pchr_err - print_pchr_err function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void print_pchr_err(stack_t **header, int line_number)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": can't pchar, stack empty\n",
	_strlen(": can't pchar, stack empty\n"));
	free_stack(*header);
	free_grid(lt.grid);
	fclose(lt.file);
	free_grid(lt.biggrid);
	exit(EXIT_FAILURE);
}
/**
* print_ascii_err - print_pchr_err function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void print_ascii_err(stack_t **header, int line_number)
{
	write(STDERR_FILENO, "L", 1);
	prinInt(line_number);
	write(STDERR_FILENO, ": can't pchar, value out of range\n",
	_strlen(": can't pchar, value out of range\n"));
	free_stack(*header);
	free_grid(lt.grid);
	fclose(lt.file);
	free_grid(lt.biggrid);
	exit(EXIT_FAILURE);
}
/**
* _pchar - _pchar function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _pchar(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	/* char c; */

	if (!*header || !header)
		print_pchr_err(header, line_number);
	if (tmp->n < 0 || tmp->n > 127)
		print_ascii_err(header, line_number);
	/* c = tmp->n + '0'; */
	printf("%c\n", tmp->n);
}


/**
* pstr - pstr function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void pstr(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	while (tmp)
	{
		if (tmp->n < 0 || tmp->n > 127)
			break;
		else if (tmp->n == 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	line_number++;
}


/**
* rotl - rotl function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void rotl(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	stack_t *store = *header;
	int i = 0;

	while (tmp)
	{
		i++;
		if (i >= 2)
			break;
		tmp = tmp->next;
	}
	if (i > 2)
	while (tmp)
	{
		if (!tmp->next)
		{
			*header = (*header)->next;
			(*header)->prev = NULL;
			tmp->next = store;
			store->prev = tmp;
			store->next = NULL;
			return;
		}
		tmp = tmp->next;
	}
	line_number++;
}
