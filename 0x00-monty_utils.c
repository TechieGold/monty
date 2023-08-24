#include <string.h>
#include <ctype.h>

#include "monty.h"



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
	len = strlen(str) + 1;
	s_str = malloc(len);
	if (s_str == NULL)
	{
		return (NULL);
	}

	memcpy(s_str, str, len);

	return (s_str);
}


/**
 * tokenize_args - Tokenizes a string into an array of arguments
 *
 * This function takes a pointer to an input string (line) and tokenizes it
 * into an array of arguments. It uses whitespace characters (' ', '\n') as
 * delimiters to separate the input string into individual tokens. The function
 * dynamically allocates memory for the array of argument strings and returns
 * the array along with the number of tokens found.
 *
 * @line: Pointer to the input string to be tokenized.
 * @num_tokens: Pointer to an integer to store the number of tokens found.
 *
 * Return: Array of pointers to argument strings.
 */
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


/**
 * trim_input - Trims newline character from the end of the input string
 *
 * This function takes a pointer to an input string (input) and trims the
 * newline character (`\n`) from the end of the string if it exists. The
 * function modifies the input string in-place if necessary.
 *
 * @input: Pointer to the input string to be trimmed.
 */
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


/**
 * sanitize_input - Sanitizes input string by replacing consecutive
 * spaces with a single space
 * This function takes a pointer to an input string (input) and sanitizes it by
 * replacing consecutive spaces with a single space. It processes the
 * input string in-place, modifying it to remove extra spaces.
 *
 * @input: Pointer to the input string to be sanitized.
 */
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


/**
 * is_blank_str - Checks if a string consists of only whitespace characters
 *
 * This function takes a string (string) as input and checks if the string
 * consists of only whitespace characters. It returns true if the string is
 * composed entirely of whitespace characters, and false otherwise.
 *
 * @string: Input string to be checked.
 *
 * Return: true if the string is blank (only contains whitespace),
 * false otherwise.
 */
int is_blank_str(const char *string)
{
	int is_empty = 1;

	if (string == NULL)
	{
		return (0);
	}

	while (*string)
	{
		if (!isspace((unsigned char)*string))
		{
			is_empty = 0;
			break;
		}
		string++;
	}

	return (is_empty);
}


