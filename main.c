#include "monty.h"

void hello(void);
monty_t *monty = NULL;

/**
 * main - Entry point
 *
 * This is the main function that serves as the entry point of the program.
 * It takes the number of command-line arguments (argc) and an array of
 * command-line argument strings (argv) as parameters. It typically contains
 * the program's logic and functionality.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: The exit status of the program (usually 0 for success).
 */
int main(int argc, char **argv)
{

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_interpreter(&monty, argc, argv);
	cleanup();

	return (0);
}
