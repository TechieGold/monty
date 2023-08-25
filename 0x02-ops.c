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
	UNUSED(stack);
	UNUSED(line_number);
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
	UNUSED(stack);
	UNUSED(line_number);
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
	UNUSED(stack);
	UNUSED(line_number);
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
	UNUSED(stack);
	UNUSED(line_number);
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
	UNUSED(stack);
	UNUSED(line_number);
}
