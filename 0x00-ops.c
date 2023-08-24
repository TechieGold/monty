#include <ctype.h>

#include "monty.h"

/**
 * ops_add_op - Adds an operation callback to the operations list
 *
 * This function adds an operation callback function to the operations list
 * associated with the provided code. It allows associating a code with a
 * specific operation callback for later retrieval and execution.
 *
 * @code: Code string associated with the operation.
 * @callback: Operation callback function to be added.
 */
void ops_add_op(char *code, op_callback callback)
{
	op_node_t *node;
	ops_list_t *list;

	list = monty->opcodes;
	node = (op_node_t *)malloc(sizeof(op_node_t));

	if (node != NULL)
	{
		node->instruction = (instruction_t *)malloc(sizeof(instruction_t));
		node->instruction->opcode = (char *)malloc(sizeof(char)
			* (strlen(code) + 1));
		strcpy(node->instruction->opcode, code);
		node->instruction->f = callback;
		node->next = NULL;
	}
	if (list->head == NULL)
	{
		list->head = node;
	}
	else
	{
		op_node_t *current = list->head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}

	list->count++;
}

/**
 * ops_search - Searches for an operation node in the operations list
 *
 * This function searches for an operation node in the operations list
 * based on the provided opcode. If a matching operation node is found,
 * it returns a pointer to that node; otherwise, it returns NULL.
 *
 * @opcode: Opcode string to search for in the operations list.
 *
 * Return: Pointer to the operation node if found, NULL otherwise.
 */
op_node_t *ops_search(const char *opcode)
{
	op_node_t *node;

	node = monty->opcodes->head;
	while (node != NULL)
	{
		if (strcmp(node->instruction->opcode, opcode) == 0)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * op_push - Pushes a value onto the stack
 *
 * This function pushes a value onto the stack. It takes a pointer to a stack
 * (stack) and the line number (line_number) where the operation is encountered
 * as parameters. The value to be pushed is typically provided in the context
 * of the operation being executed.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the push operation is encountered.
 */
void op_push(stack_t **stack, unsigned int line_number)
{

	if (monty->top[1] == NULL || check_digit(monty->top[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (monty->mode == 0)
	{
		list_push_front(stack, atoi(monty->top[1]));
	}
	else
	{
		list_push_back(stack, atoi(monty->top[1]));
	}
}

/**
 * op_pall - Prints all elements of the stack
 *
 * This function prints all elements of the stack. It takes a pointer to a
 * stack (stack) and the line number (line_number) where the operation is
 * encountered as parameters. The function iterates through the stack
 * and prints each element in the order they were pushed.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the pall operation is encountered.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	UNUSED(stack);
	UNUSED(line_number);

	if (monty->mode == 0)
	{
		node = monty->monty_stack;
		while (node != NULL)
		{
			printf("%d\n", node->n);
			node = node->next;
		}
	}
	else
	{
		node = monty->tail;
		while (node != NULL)
		{
			printf("%d\n", node->n);
			node = node->prev;
		}
	}
}

/**
 * op_pint - Prints the top element of the stack
 *
 * This function prints the top element of the stack. It takes
 * a pointer to a stack (stack) and the line number (line_number)
 * where the operation is encountered as parameters. The function
 * prints the value of the top element without removing it.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the pint operation is encountered.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (monty->monty_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", monty->monty_stack->n);
	UNUSED(stack);
}
