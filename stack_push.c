#include "monty.h"

/**
  * push - A function that  pushes as element to the stack.
  * @stack: A double pointer to the stack.
  * @value: Value to be pushed to the stack.
  *
  * Return: Void.
  */
void push(stack_t **stack, int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}
