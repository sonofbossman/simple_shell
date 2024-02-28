#include "shell.h"

/**
 * _strlen - returns length of a string
 * @s: the string whose length to check
 *
 * Return: length(int) of string
 */
int _strlen(const char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
 * _strcmp - Compare two strings.
 * @s1: first string to compare.
 * @s2: second string to compare.
 * Return: 0 if @s1 = @s2,
 *         a -ve value if @s1 < @s2,
 *         or a +ve value if @s1 > @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int) (*s1) - (*s2));
}

/**
 * _strncmp - Compare two strings up to a specified length.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 when strings are equal up to n chars, -ve value
 *         if s1 < s2, or +ve value if s1 is > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1, c2;

	while (n-- > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;

		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break;
	}

	return (0);
}
