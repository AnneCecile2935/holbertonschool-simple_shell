#include <stdio.h>
#include <unistd.h>
/**
 *
 *
 * 
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int i = 0;
	char c;
	char *linetemp;
	int j;
	size_t new_size;
	ssize_t ret;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*n == 0)
		*n = 128;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while ((ret = read(fileno(stream), &c , 1)) > 0)
	{
		if (i >= *n - 1)
		{
			new_size = *n * 2;
			linetemp = malloc(new_size);
			if (linetemp == NULL)
			{
				return (-1);
			}
			for (j = 0; j < i; j++)
				linetemp[j] = (*lineptr)[j];

			free(*lineptr);
			*lineptr = linetemp;
			*n = new_size;
		}
		(*lineptr)[i++] = c;

		if (c == '\n')
			break;
	}

	if (i == 0)
	return (-1);

	(*lineptr)[i] = '\0';
	return (i);
}
