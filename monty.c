#include "monty.h"
#include "ops.h"

void init_interpreter(monty_t **monty, int argc, char **argv)
{
	char buffer[1024];
	FILE *fptr;

	if (argc < 2 || argc > 2)
		exit(EXIT_FAILURE);


	*monty = (monty_t *)malloc(sizeof(monty_t));

	(*monty)->mode = 0;
	(*monty)->monty_stack = NULL;
	(*monty)->tail = NULL;
	

	fptr = fopen(argv[1], "r");

	if (fptr != NULL)
	{
		while (fgets(buffer, 1024, fptr) != NULL)
		{
			parse_command(buffer, *monty);
		}
		fclose(fptr);
	}
}

void init_ops_list(ops_list_t **ops_list)
{
	*ops_list = malloc(sizeof(ops_list_t));
	(*ops_list)->head = NULL;
	(*ops_list)->count = 0;

	ops_add_op(*ops_list, "push", op_push);
	/* Add support for more opcodes here */
}


void handle_command(char **args, int ln)
{
	
	if (args[0][0] != '#')
	{
		if (strcmp(args[0], "queue") == 0)
		{
			printf("queue mode\n");
			monty->mode = 1;
		}
		else if (strcmp(args[0], "stack") == 0)
		{
			printf("stack mode\n");
			monty->mode = 0;
		}
		if (strcmp(args[0], "push") == 0)
		{
			monty->top = args;
			op_push(&(monty->monty_stack), ln);
		}
		if (strcmp(args[0], "pall") == 0)
		{
			printf("---\n");
			op_pall(&(monty->monty_stack), ln);
		}
	}
}


