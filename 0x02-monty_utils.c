#include "monty.h"


/**
 * list_pop_back - Pops the element from the back of a stack
 *
 * This function removes the element from the back of a stack pointed to by
 * the list parameter. It deallocates memory associated with the
 * removed element.
 * @list: Pointer to a pointer to the stack.
 */
void list_pop_back(stack_t **list)
{
	stack_t *current;

	if (*list == NULL)
	{
		fprintf(stderr, "List is empty\n");
		return;
	}

	current = *list;
	while (current->next != NULL)
	{
		current = current->next;
	}

	if (current->prev != NULL)
	{
		current->prev->next = NULL;
	}
	else
	{
		*list = NULL;
	}

	free(current);
}
