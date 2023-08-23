#include "ops.h"
#include "utils.h"


void ops_add_op(ops_list_t *list, char *code, op_callback callback)
{
	op_node_t *node;

	node = (op_node_t *)malloc(sizeof(op_node_t));

	if (node != NULL)
	{
		node->instruction = (instruction_t *)malloc(sizeof(instruction_t));
		node->instruction->opcode = (char *)malloc(sizeof(char) * (strlen(code) + 1));
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

op_node_t *ops_search(const char *opcode)
{
	UNUSED(opcode);
	return NULL;
}


void op_push(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	if (monty->mode == 0)
		list_push_front(stack, atoi(monty->top[1]));
	else
		list_push_back(stack, atoi(monty->top[1]));
}

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


