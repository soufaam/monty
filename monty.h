#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * var - opcode and its function
 * @val: the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct var
{
	char *val;
	char **grid;
	char **biggrid;
	FILE *file;
}var_t;

extern var_t lt;


void free_grid(char **grid);
void free_stack(stack_t *head);
char *_strdup(char *str);
int _strlen(char *s);
char **strtow(char *str, char delimeter);
int _strcmp(char *s1, char *s2);
void error_handling(int argc, char **argv, FILE **file);
void readlinee(int fd);
void _push(stack_t **header, unsigned int number);
void _pop(stack_t **header, unsigned int line_number);
void printall(stack_t ** header, unsigned int line_number);
void printop(stack_t **header, unsigned int line_number);
void exec_cmd(stack_t **header, char **grid, int line_number);
void _swap(stack_t **header, unsigned int line_number);
void  prinInt(int var);
void _add(stack_t **header, unsigned int line_number);
void _nop(stack_t **header, unsigned int line_number);

#endif
