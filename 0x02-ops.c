#include "monty.h"

/**
 * op_mul - Multiplies the top two elements of the stack
 *
 * This function multiplies the top two elements of the stack and replaces them
 * with the result of the multiplication. It takes a pointer to a stack (stack)
 * and the line number (line_number) where the operation is
 * encountered as parameters.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the mul operation is encountered.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	int s1, s2, product;

	UNUSED(stack);
	UNUSED(line_number);

	if (!(monty->monty_stack && (monty->monty_stack->next)))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", monty->current_line);
		exit(EXIT_FAILURE);
	}

	s1 = monty->monty_stack->n;
	s2 = monty->monty_stack->next->n;
	product = s1 * s2;

	list_pop_front(&(monty->monty_stack));

	monty->monty_stack->n = product;
}

/**
 * op_div - Divides the second top element of the stack by the top element
 *
 * This function divides the second top element of the stack by the top
 * element and replaces them with the result of the division. It takes
 * a pointer to a stack (stack) and the line number (line_number)
 * where the operation is encountered as parameters.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the div operation is encountered.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	int s1, s2, div;

	UNUSED(stack);
	UNUSED(line_number);

	if (!(monty->monty_stack && (monty->monty_stack->next)))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", monty->current_line);
		exit(EXIT_FAILURE);
	}

	s1 = monty->monty_stack->n;
	s2 = monty->monty_stack->next->n;
	if (s1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", monty->current_line);
		exit(EXIT_FAILURE);
	}
	div = s2 / s1;

	list_pop_front(&(monty->monty_stack));

	monty->monty_stack->n = div;
}

/**
 * op_mod - Computes the remainder of the division of the second
 * top element by the top element
 * This function computes the remainder of the division of the
 * second top element by the top element and replaces them with
 * the result. It takes a pointer to a stack (stack) and the line number
 * (line_number) where the operation is encountered as parameters.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the mod operation is encountered.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	int s1, s2, mod;

	UNUSED(stack);
	UNUSED(line_number);

	if (!(monty->monty_stack && (monty->monty_stack->next)))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", monty->current_line);
		exit(EXIT_FAILURE);
	}

	s1 = monty->monty_stack->n;
	s2 = monty->monty_stack->next->n;
	if (s1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", monty->current_line);
		exit(EXIT_FAILURE);
	}
	mod = s1 - s2;

	list_pop_front(&(monty->monty_stack));

	monty->monty_stack->n = mod;
}

/**
 * op_pchar - Prints the character value at the top of the stack
 *
 * This function prints the character value represented by the topelement of
 * the stack. It takes a pointer to a stack (stack) and the
 * line number (line_number) where the operation is encountered as parameters.
 * The function prints the character followed by a newline.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the pchar operation is encountered.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr = monty->monty_stack;

	UNUSED(stack);
	UNUSED(line_number);

	if (!(monty->monty_stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", monty->current_line);
		exit(EXIT_FAILURE);
	}

	while (stack_ptr != NULL)
	{
		printf("%c\n", stack_ptr->n);
		stack_ptr = stack_ptr->next;
	}
}

/**
 * op_pstr - Prints the string starting from the top of the stack
 *
 * This function prints the string represented by the values on
 * the stack starting from the top element. It continues printing characters
 * until a non-printable character or the end of the stack is encountered.
 * It takes a pointer to a stack (stack) and the line number (line_number)
 * where the operation is encountered as parameters. The function prints
 * the characters followed by a newline.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the pstr operation is encountered.
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr = monty->monty_stack;

	UNUSED(stack);
	UNUSED(line_number);

	if (!(monty->monty_stack))
	{
		fprintf(stderr, "\n");
	}

	while (stack_ptr != NULL)
	{
		if (stack_ptr->n == 0)
			break;
		else if (is_in_ascii_range(stack_ptr->n))
		{
			printf("%c", stack_ptr->n);
		}
		stack_ptr = stack_ptr->next;
	}
	printf("\n");
}
