#include "monty.h"

/**
* _sub - _sub function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _sub(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int i = 0, sum = 0;

	while (tmp)
	{
		i++;
		sum = tmp->n - sum;
		if (i >= 2)
			break;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't add, stack too short\n",
		_strlen(": can't sub, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	(*header)->next->n = sum;
	_pop(header, line_number);
}

/**
* _div - div function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _div(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int i = 0, result = 1;

	while (tmp)
	{
		i++;
		if (!tmp->n)
			print_zerodiv_error(*header, line_number);
		result = tmp->n / result;
		if (i >= 2)
			break;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't add, stack too short\n",
		_strlen(": can't div, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	(*header)->next->n = result;
	_pop(header, line_number);
}

/**
* _mod - mod function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _mod(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int i = 0, result = 1;

	while (tmp)
	{
		i++;
		if (!tmp->n)
			print_zerodiv_error(*header, line_number);
		if (i >= 2)
			break;
		result = tmp->n;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't add, stack too short\n",
		_strlen(": can't mod, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	(*header)->next->n = tmp->n % result;
	_pop(header, line_number);
}

/**
* _mul - mul function
* @header: header parameter
* @line_number: line number
* Return: 0 success or uint
*/
void _mul(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	int i = 0, result = 1;

	while (tmp)
	{
		i++;
		result = tmp->n * result;
		if (i >= 2)
			break;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		write(STDERR_FILENO, "L", 1);
		prinInt(line_number);
		write(STDERR_FILENO, ": can't add, stack too short\n",
		_strlen(": can't mul, stack too short\n"));
		free_stack(*header);
		free_grid(lt.grid);
		free_grid(lt.biggrid);
		fclose(lt.file);
		exit(EXIT_FAILURE);
	}
	(*header)->next->n = result;
	_pop(header, line_number);
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
	(*header)->next->n = sum;
	_pop(header, line_number);
}
