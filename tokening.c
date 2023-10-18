#include "main.h"

/**
 * sstrtok - Split and create a full string command.
 * @sstr: Delimiter for strtok.
 * @buf_size: Pointer to input string.
 * Return: String with full command.
 */
char **sstrtok(char *buf_size, const char *sstr)
{
	char *token = NULL, **commands = NULL;
	size_t bufferSize = 0;
	int i = 0;

	if (buf_size == NULL)
		return (NULL);

	bufferSize = _StringLength(buf_size);
	commands = malloc((bufferSize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Buffer allocation error");
		free(buf_size);
		FreeMember(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buf_size, sstr);
	while (token != NULL)
	{
		commands[i] = malloc(_StringLength(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Buffer allocation error");
			FreeMember(commands);
			return (NULL);
		}
		_StringCopy(commands[i], token);
		token = strtok(NULL, sstr);
		i++;
	}

	commands[i] = NULL;
	return (commands);
}
