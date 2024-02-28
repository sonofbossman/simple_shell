#include "shell.h"

/**
 * find_in_path - Looks for a command in each directory specified in the PATH
 *                environment variable
 * @command: pointer to `command` string to look for.
 *
 * Return: pointer to string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
*/
char *find_in_path(char *command)
{
	struct stat st;
	int stat_xmp, j;
	char buf[PATH_MAX_LENGTH], *path, *xmp, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (j = 0; dir[j]; j++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, dir[j]);
		_strcat(buf, "/");
		_strcat(buf, command);
		stat_xmp = stat(buf, &st);
		if (stat_xmp == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(dir);
			xmp = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!xmp)
				return (NULL);
			strcpy(xmp, buf);
			return (xmp);
		}
	}
	if (stat_xmp == -1)
		free_tokens(dir);
	return (NULL);
}
