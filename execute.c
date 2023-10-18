#include "main.h"

/**
 * GetPath - gets the value from env PATH
 *
 * @environment: env var pointer
 *
 * Return: pathways for commands
 */
char **GetPath(char **environment)
{
	char **pathways = NULL, *pathvalue = NULL;
	unsigned int inte = 0;

	pathvalue = strtok(environment[inte], "=");
	while (environment[inte])
	{
		if (_StringCompare(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = sstrtok(pathvalue, ":");
			return (pathways);
		}
		inte++;
		pathvalue = strtok(environment[inte], "=");
	}
	return (NULL);
}


/**
 * Execute - function that executes a command
 *
 * @code: command pointer
 *
 * @info: shell name
 *
 * @environment: environmental variables pointer
 * @loops: number of executed cicles
 * Return: nothing
 */
void Execute(char **code, char *info, char **environment, int loops)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_StringCompare(code[0], "env") != 0)
		PrintEnvironment(environment);
	if (stat(code[0], &st) == 0)
	{
		if (execve(code[0], code, environment) < 0)
		{
			perror(info);
			ExitFree(code);
		}
	}
	else
	{
		pathways = GetPath(environment);
		while (pathways[i])
		{
			full_path = _StringConcatinate(pathways[i], code[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, code, environment) < 0)
				{
					perror(info);
					FreeMember(pathways);
					ExitFree(code);
				}
				return;
			}
		}
		ErrorMessage(info, loops, code);
		FreeMember(pathways);
	}
}


/**
 * ErrorMessage - Prints message not found
 *
 * @info: shell name
 * @loops: number of cicles
 * @code: tokenized command
 * Return: nothing
 */
void ErrorMessage(char *info, int loops, char **code)
{
	char cee;

	cee = loops + '0';
	write(STDOUT_FILENO, info, _StringLength(info));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cee, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, code[0], _StringLength(code[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}


/**
 * PrintEnvironment - prints all enviromental variable.
 * @environment: enviromental variables pointer
 * return: nothing
 */
void PrintEnvironment(char **environment)
{
	size_t inte = 0, length = 0;

	while (environment[inte])
	{
		length = _StringLength(environment[inte]);
		write(STDOUT_FILENO, environment[inte], length);
		write(STDOUT_FILENO, "\n", 1);
		inte++;
	}
}
