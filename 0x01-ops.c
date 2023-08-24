#include "utils.h"

/**
 * op_pop - Removes the top element from the stack
 *
 * This function removes the top element from the stack. It takes a pointer to
 * a stack (stack) and the line number (line_number) where the operation is
 * encountered as parameters. The function deallocates memory associated with
 * the removed element.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the pop operation is encountered.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *list = monty->monty_stack;

	if (list == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	list_pop_front(&list);

	UNUSED(stack);
	UNUSED(line_number);
}


/**
 * op_nop - Does nothing
 *
 * This function is a no-operation (nop) operation. It does not
 * perform any action and simply returns. It takes a pointer to
 * a stack (stack) and the line number (line_number) where the
 * operation is encountered as parameters.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the nop operation is encountered.
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}


/**
 * op_add - Adds the top two elements of the stack
 *
 * This function adds the top two elements of the stack and replaces them with
 * the sum. It takes a pointer to a stack (stack) and the line number
 * (line_number) where the operation is encountered as parameters.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the add operation is encountered.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int s1, s2, sum;

	UNUSED(stack);
	UNUSED(line_number);

	s1 = monty->monty_stack->n;
	s2 = monty->monty_stack->next->n;
	sum = s1 + s2;

	list_pop_front(&(monty->monty_stack));

	monty->monty_stack->n = sum;
}


/**
 * op_swap - Swaps the top two elements of the stack
 *
 * This function swaps the positions of the top two elements of the stack.
 * It takes a pointer to a stack (stack) and the line number (line_number)
 * where the operation is encountered as parameters.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the swap operation is encountered.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{

	stack_t *t1 = NULL;
	stack_t *t2 = NULL;

	t1 = monty->monty_stack;
	t2 = t1->next;

	if (t2 == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", monty->current_line);
		exit(EXIT_FAILURE);
	}

	printf("T1: %d\n", t1->n);
	printf("T2: %d\n", t2->n);

	UNUSED(stack);
	UNUSED(line_number);
}
