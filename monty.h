#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

#define MAX_ARGS 1024

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
 * struct op_node_tag - Operation node for operations list
 * @instruction: Pointer to an instruction structure.
 * @next: Pointer to the next operation node.
 *
 * Description: The `op_node_t` structure represents a node
 * in the operations list used in the Monty interpreter. It contains
 * a pointer to an instruction structure that associates an opcode with
 * its corresponding function, and a pointer to the next operation
 * node in the linked list.
 */
typedef struct op_node_tag
{
	instruction_t *instruction;
	struct op_node_tag *next;
} op_node_t;


/**
 * struct ops_list_tag - Operations list structure
 * @count: Number of operation nodes in the list.
 * @head: Pointer to the head operation node.
 *
 * Description: The `ops_list_t` structure represents a list of
 * operation nodes used in the Monty interpreter. It keeps track
 * of the number of operation nodes in the list and provides a
 * pointer to the head operation node.
 */
typedef struct ops_list_tag
{
	int count;
	op_node_t *head;
} ops_list_t;


/**
 * struct monty - Monty interpreter structure
 * @opcodes: Pointer to the operations list containing opcode callbacks.
 * @mode: Mode of operation (LIFO or FIFO).
 * @monty_stack: Pointer to the stack data structure.
 * @tail: Pointer to the tail of the stack (used for queues).
 * @top: Pointer to the top of the stack (used for stack).
 * @current_line: Current line number being processed.
 * @fptr: File object
 * @buffer: Reader buffer
 * Description: The `monty_t` structure represents the Monty interpreter's
 * state and configuration. It contains information about the operations list,
 * the mode of operation (LIFO or FIFO), the stack data structure,
 * and pointers to the top and tail elements of the stack.
 */
typedef struct monty
{
	ops_list_t *opcodes;
	short mode;
	stack_t *monty_stack;
	stack_t *tail;
	char **top;
	int current_line;
	FILE *fptr;
	char *buffer;
} monty_t;

extern monty_t *monty;

void init_interpreter(monty_t **monty, int argc, char **argv);

void init_ops_list(ops_list_t **ops_list);

int parse_command(char *input, monty_t *monty, int ln);

void handle_command(char **args, int ln, int num_tokens);

void cleanup(void);



/* Utility functions to support the program */

char *_strdup(char *str);

void sanitize_input(char *input);

void trim_input(char *input);

char **tokenize_args(char *line, int *num_tokens);

int is_blank_str(const char *string);

int is_in_ascii_range(int value);

int check_digit(const char *number);

void list_push_front(stack_t **stack, int n);

void list_push_back(stack_t **stack, int n);

void list_pop_front(stack_t **stack);

void list_pop_back(stack_t **stack);



/* Functions for the opcode management */

typedef void (*op_callback)(stack_t **stack, unsigned int line_number);

void ops_add_op(char *code, op_callback callback);

op_node_t *ops_search(const char *opcode);


void op_push(stack_t **stack, unsigned int line_number);

void op_pall(stack_t **stack, unsigned int line_number);

void op_pint(stack_t **stack, unsigned int line_number);

void op_pop(stack_t **stack, unsigned int line_number);

void op_swap(stack_t **stack, unsigned int line_number);

void op_add(stack_t **stack, unsigned int line_number);

void op_nop(stack_t **stack, unsigned int line_number);

void op_sub(stack_t **stack, unsigned int line_number);

void op_mul(stack_t **stack, unsigned int line_number);

void op_div(stack_t **stack, unsigned int line_number);

void op_mod(stack_t **stack, unsigned int line_number);

void op_pchar(stack_t **stack, unsigned int line_number);

void op_pstr(stack_t **stack, unsigned int line_number);

void op_rotl(stack_t **stack, unsigned int line_number);

void op_rotr(stack_t **stack, unsigned int line_number);

void op_stack_queue(stack_t **stack, unsigned int line_number);

#endif
