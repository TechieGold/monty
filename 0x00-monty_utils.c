#include "monty.h"
#include "ops.h"

#include <string.h>
#include <ctype.h>

static int ln = 0;


/**
 * _strdup - A function that returns a pointer
 * Description: A function that returns a pointer
 * to newly allocated space in memory, which contains
 * a copy of the given string as a parameter
 * @str: Copied string
 * Return: String
 */

char *_strdup(char *str)
{
	size_t len;
	char *s_str;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str) +  1;
	s_str = malloc(len);
	if (s_str == NULL)
	{
		return (NULL);
	}

	memcpy(s_str, str, len);

	return (s_str);

}


char **tokenize_args(char *line, int *num_tokens)
{
	int bufsize;
	char **args;
	char *token;

	bufsize = MAX_ARGS;
	args = malloc(bufsize * sizeof(char *));
	token = strtok(line, " \n");
	(*num_tokens) = 0;

	while (token != NULL)
	{
		args[*num_tokens] = _strdup(token);
		(*num_tokens)++;
		token = strtok(NULL, " \n");
	}

	return (args);
}

void trim_input(char *input)
{
	if (input != NULL)
	{
		size_t len = strlen(input);

		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}
	}
}

void sanitize_input(char *input)
{
	char *src;

	char *dest = input;
	int prev_space = 0;

	for (src = input; *src != '\0'; ++src)
	{
		if (isspace((unsigned char)*src))
		{
			if (!prev_space)
			{
				*dest++ = ' ';
				prev_space = 1;
			}
		}
		else
		{
			*dest++ = *src;
			prev_space = 0;
		}
	}

	*dest = '\0';
}

int parse_command(char *input, monty_t *monty)
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

	if (!input || input[0] == '\0' || input[0] == '\n')
		return (0);

	delim_space = strchr(input, ' ');

	args = tokenize_args(input, &num_tokens);
	if (args == NULL)
		return 0;
	ln += 1;
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
