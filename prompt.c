#include "shell.h"

/**
 * prompt -A function that prints shell prompt to stdin stream.
 *
 * Return: void.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
