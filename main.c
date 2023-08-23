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
	init_interpreter(&monty, argc, argv);
	init_ops_list(&(monty->opcodes));

	return (0);
}
