#include "monty.h"
#include "ops.h"


static int ln = 1;

void init_interpreter(monty_t **monty, int argc, char **argv)
{
	char buffer[1024];
	FILE *fptr;

	*monty = (monty_t *)malloc(sizeof(monty_t));

	(*monty)->mode = 0;
	(*monty)->monty_stack = NULL;
	(*monty)->tail = NULL;

	init_ops_list(&((*monty)->opcodes));

	fptr = fopen(argv[1], "r");

	if (fptr != NULL)
	{
		while (fgets(buffer, 1024, fptr) != NULL)
		{
			// buffer[strcspn(buffer, "\n")] = '\0';
			parse_command(buffer, *monty, ln);
			ln += 1;
		}
		fclose(fptr);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	UNUSED(argc);
	UNUSED(argv);
}

void init_ops_list(ops_list_t **ops_list)
{
	*ops_list = malloc(sizeof(ops_list_t));
	(*ops_list)->head = NULL;
	(*ops_list)->count = 0;

	if (*ops_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	ops_add_op("push", op_push);
	ops_add_op("pall", op_pall);
	ops_add_op("pint", op_pint);
	ops_add_op("pop", op_pop);
	
	/* Add support for more opcodes here */
}

void handle_command(char **args, int ln)
{
	monty->top = args;

	if (args[0][0] != '#')
	{

		op_node_t *opnode = ops_search(args[0]);

		if (opnode != NULL)
		{
			opnode->instruction->f(&(monty->monty_stack), ln);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, args[0]);
			exit(EXIT_FAILURE);
		}
	}
}
