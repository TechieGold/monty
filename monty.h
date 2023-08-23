#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

#define MAX_ARGS 2

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

typedef struct op_node_tag
{
	instruction_t *instruction;
	struct op_node_tag *next;
} op_node_t;

typedef struct ops_list_tag
{
	int count;
	op_node_t *head;
} ops_list_t;

typedef struct monty
{
	ops_list_t *opcodes;
	short mode;
	stack_t *monty_stack;
	stack_t *tail;
	char **top;
} monty_t;


extern monty_t* monty;



void init_interpreter(monty_t **monty,int argc,char ** argv);

void init_ops_list(ops_list_t **ops_list);

int parse_command(char *input, monty_t *monty);

void sanitize_input(char *input);

void trim_input(char *input);

char **tokenize_args(char *line, int *num_tokens);

void handle_command(char **args, int ln);








#endif
