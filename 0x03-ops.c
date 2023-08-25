#include "monty.h"



/**
 * op_rotl - Rotates the stack to the top
 *
 * This function rotates the stack to the top, moving the top element to the
 * bottom of the stack. The second element becomes the new top. It takes a
 * pointer to a stack (stack) and the line number (line_number) where the
 * operation is encountered as parameters.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the rotl operation is encountered.
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}


/**
 * op_rotr - Rotates the stack to the bottom
 *
 * This function rotates the stack to the bottom, moving the bottom element to
 * the top of the stack. The top element becomes the new second element.
 * It takes a pointer to a stack (stack) and the line number
 * (line_number) where the operation is encountered as parameters.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the rotr operation is encountered.
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}


/**
 * op_stack_queue - Switches the stack mode to queue mode and vice versa
 *
 * This function switches the mode of the stack between stack mode (LIFO) and
 * queue mode (FIFO). It takes a pointer to a stack (stack) and the line number
 * (line_number) where the operation is encountered as parameters.
 *
 * @stack: Pointer to a pointer to the stack.
 * @line_number: Line number where the stack/queue operation is encountered.
 */
void op_stack_queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
