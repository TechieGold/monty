#include "utils.h"



/**
 * _isdigit - Checks if a character is a digit
 *
 * This function takes a character (c) as input and checks if it represents
 * a numeric digit (0-9). It returns true if the character is a digit and
 * false otherwise.
 *
 * @c: Character to be checked.
 *
 * Return: true if the character is a digit, false otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}



/**
 * check_digit - Checks if a string represents a valid integer
 *
 * This function takes a string (number) as input and checks if it represents
 * a valid integer. It examines the characters in the string and determines
 * if they form a valid integer value. The function returns true if the string
 * is a valid integer representation and false otherwise.
 *
 * @number: Input string to be checked.
 *
 * Return: true if the string represents a valid integer, false otherwise.
 */
int check_digit(const char *number)
{
	if (number == NULL || *number == '\0')
	{
		return (0);
	}

	if (*number == '-')
	{
		number++;
	}

	while (*number != '\0')
	{
		if (!_isdigit(*number))
		{
			return (0);
		}
		number++;
	}

	return (1);
}


/**
 * list_push_front - Pushes a new element to the front of a stack
 *
 * This function adds a new element with the specified value to the front of
 * a stack pointed to by the list parameter.
 *
 * @list: Pointer to a pointer to the stack.
 * @n: The value to be stored in the new element.
 */
void list_push_front(stack_t **list, int n)
{
	stack_t *new_node;

	UNUSED(list);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = monty->monty_stack;

	if (monty->monty_stack == NULL)
	{
		monty->monty_stack = new_node;
	}
	else
	{
		monty->monty_stack->prev = new_node;
		monty->monty_stack = new_node;
	}

	if (monty->tail == NULL)
	{
		monty->tail = new_node;
	}
}

/**
 * list_push_back - Pushes a new element to the back of a stack
 *
 * This function adds a new element with the specified value to the back of
 * a stack pointed to by the list parameter.
 *
 * @list: Pointer to a pointer to the stack.
 * @n: The value to be stored in the new element.
 */
void list_push_back(stack_t **list, int n)
{
	stack_t *new_node;

	UNUSED(list);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;

	if (monty->monty_stack == NULL)
	{
		new_node->prev = NULL;
		monty->monty_stack = new_node;
	}
	else
	{
		stack_t *current = monty->monty_stack;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}

	if (monty->tail == NULL)
	{
		monty->tail = new_node;
	}
}


/**
 * list_pop_front - Pops the element from the front of a stack
 *
 * This function removes the element from the front of a
 * stack pointed to by the list parameter. It deallocates
 * memory associated with the removed element.
 * @list: Pointer to a pointer to the stack.
 */
void list_pop_front(stack_t **list)
{
	stack_t *temp;

	if (*list == NULL)
	{
		fprintf(stderr, "List is empty\n");
		return;
	}

	temp = *list;
	*list = (*list)->next;

	if (*list != NULL)
	{
		(*list)->prev = NULL;
	}

	free(temp);
}


