#include "monty.h"

/**
 * init_interpreter - Initializes the Monty interpreter
 *
 * This function initializes the Monty interpreter by setting up the necessary
 * structures and configurations based on the program arguments.
 *
 * @monty: Double pointer to a Monty structure pointer.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 */
void init_interpreter(monty_t **monty, int argc, char **argv)
{
	size_t n;
	char *buffer;
	FILE *fptr;

	*monty = (monty_t *)malloc(sizeof(monty_t));

	if (monty == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	buffer = NULL;
	n = 0;
	(*monty)->mode = 0;
	(*monty)->monty_stack = NULL;
	(*monty)->tail = NULL;
	(*monty)->current_line = 1;

	init_ops_list(&((*monty)->opcodes));

	fptr = fopen(argv[1], "r");

	if (fptr != NULL)
	{
		while (getline(&buffer, &n, fptr) != -1)
		{
			parse_command(buffer, *monty, (*monty)->current_line);
			(*monty)->current_line += 1;
		}
		fclose(fptr);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	free(buffer);
	UNUSED(argc);
	UNUSED(argv);
}

/**
 * init_ops_list - Initializes an operations list
 *
 * This function initializes an operations list by allocating memory for the
 * ops_list_t structure and initializing its fields.
 *
 * @ops_list: Double pointer to an operations list structure pointer.
 */
void init_ops_list(ops_list_t **ops_list)
{
	*ops_list = malloc(sizeof(ops_list_t));

	if (*ops_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*ops_list)->head = NULL;
	(*ops_list)->count = 0;

	ops_add_op("push", op_push);
	ops_add_op("pall", op_pall);
	ops_add_op("pint", op_pint);
	ops_add_op("pop", op_pop);
	ops_add_op("nop", op_nop);
	ops_add_op("swap", op_swap);
	ops_add_op("add", op_add);
	ops_add_op("sub", op_sub);
	ops_add_op("mul", op_mul);
	ops_add_op("div", op_div);
	ops_add_op("mod", op_mod);
	ops_add_op("pchar", op_pchar);
	ops_add_op("pstr", op_pstr);
	ops_add_op("stack", op_stack_queue);
	ops_add_op("queue", op_stack_queue);

	/* Add support for more opcodes here */
}

/**
 * handle_command - Handles a command with its arguments
 *
 * This function processes a command along with its arguments. It takes the
 * command arguments as an array of strings (args) and the line number (ln)
 * where the command is encountered. The function typically interprets and
 * executes the command based on the provided arguments and context.
 *
 * @args: Array of strings containing the command and its arguments.
 * @ln: Line number where the command is encountered.
 */
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

/**
 * parse_command - Parses and processes a command from input
 *
 * This function takes an input string (input), a Monty interpreter structure
 * (monty), and the line number (ln) where the input is encountered. It parses
 * the input string to extract and process the command along with its
 * arguments. The function typically interprets and executes the
 * command based on the provided input and context.
 *
 * @input: Input string containing the command and its arguments.
 * @monty: Pointer to the Monty interpreter structure.
 * @ln: Line number where the input is encountered.
 *
 * Return: 0 if parsing and processing succeeded, -1 otherwise.
 */
int parse_command(char *input, monty_t *monty, int ln)
{
	char **args = NULL;
	int status = 0;
	int i;
	char *delim_space;
	int num_tokens = 0;

	UNUSED(delim_space);
	UNUSED(monty);

	trim_input(input);
	sanitize_input(input);

	if (!input || input[0] == '\0' || input[0] == '\n'
		|| is_blank_str(input) == 1 || strlen(input) == 0)
	{
		return (0);
	}

	delim_space = strchr(input, ' ');
	sanitize_input(input);

	args = tokenize_args(input, &num_tokens);
	if (args == NULL)
		return (0);

	handle_command(args, ln);

	input = NULL;

	for (i = 0; i < num_tokens; i++)
	{
		free(args[i]);
		args[i] = NULL;
	}
	free(args);
	args = NULL;
	return (status);
}

/**
 * cleanup - Performs cleanup tasks before program exit
 *
 * This function is intended to perform cleanup tasks and release resources
 * before the program exits. It can be used to release allocated memory,
 * close open files, free resources, and perform any necessary finalization.
 */
void cleanup(void)
{
	op_node_t *opnode = monty->opcodes->head;
	stack_t *stack = monty->monty_stack;

	if (opnode != NULL)
	{
		while (opnode != NULL)
		{
			op_node_t *next = opnode->next;

			free(opnode->instruction->opcode);
			free(opnode->instruction);
			free(opnode);
			opnode = next;
		}
	}

	if (monty->monty_stack != NULL)
	{
		while (stack != NULL)
		{
			stack_t *next = stack->next;

			free(stack);
			stack = next;
		}
	}

	free(monty->opcodes);
	free(monty);
}
