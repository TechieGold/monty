#include "monty.h"

/**
  * main - Entry point.
  *
  * Return: Always EXIT_SUCCESS.
  */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: %s\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
