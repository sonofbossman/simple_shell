#include "shell.h"

/**
 * _strcpy - Function that copies a string
 * @dest: destination
 * @src: source
 *
 * Return: a pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int g = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[g])
	{
		dest[g] = src[g];
		g++;
	}
	dest[g] = 0;
	return (dest);
}

/**
 * _strcat - This function concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: a pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *xmp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (xmp);
}

/**
 * _strdup - This function duplicates a string
 * @str: string to be duplicated
 *
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len_str = 0;
	char *xmp;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len_str++;
	xmp = malloc(sizeof(char) * (len_str + 1));
	if (!xmp)
		return (NULL);
	for (len_str++; len_str--;)
		xmp[len_str] = *--str;
	return (xmp);
}

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strspn - a function that gets the
 *           length of a prefix substring
 *
 * @s: pointer to string input
 * @accept: substring prefix to look for
 *
 * Return: the number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int f, k;

	for (f = 0; s[f]; f++)
	{
		for (k = 0; accept[k]; k++)
		{
			if (s[f] == accept[k])
				break;
		}
		if (!accept[k])
			return (f);
	}

	return (f);
}
