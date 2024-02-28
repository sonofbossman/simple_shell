#include "shell.h"

/**
 * tokenize - parsing user input into arguments
 *            by splits an array string into tokens using a delimiter.
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 *
 * Return: an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **xmp = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		xmp = realloc(xmp, sizeof(char *) * (i + 1));
		if (xmp == NULL)
			return (NULL);

		xmp[i] = malloc(_strlen(token) + 1);
		if (!(xmp[i]))
			return (NULL);

		_strcpy(xmp[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	xmp = realloc(xmp, (i + 1) * sizeof(char *));
	if (!xmp)
		return (NULL);

	xmp[i] = NULL;
	return (xmp);
}

/**
 * tokenize_input - splits a user input string into tokens with tokenize().
 * @input: the user input string to be tokenized
 *
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *templ = NULL;

	templ = _strdup(input);
	if (templ == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(templ, " \t\r\n\a");
	free(templ);

	return (tokens);
}
