#include "monty.h"

monty_t *monty = NULL;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv:  Array of program arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	init_interpreter(&monty, argc, argv);

	return (0);
}
