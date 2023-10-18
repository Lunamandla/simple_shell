#include "main.h"

/**
 * main - shell kernel
 * @num_of_inp_args: Number of inputed args.
 * @arr_of_inp_args: Pointer to array of inputed args.
 * @env: Pointer to array of env variables.
 * Return: 0.
 */

int main(int num_of_inp_args, char **arr_of_inp_args, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cicles = 0;
	(void)num_of_inp_args;

	while (1)
	{
		cicles++;
		_prompt();
		signal(SIGINT, _handle);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EndOfFile(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_StringLength(buffer) - 1] = '\0';
			command = sstrtok(buffer, " \0");
			free(buffer);
			if (_StringCompare(command[0], "exit") != 0)
				_shell_exit(command);
			else if (_StringCompare(command[0], "cd") != 0)
				shift_folder(command[1]);
			else
				child_pid(command, arr_of_inp_args[0], env, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * _handle - Handle Ctr + C signal.
 * @_prompt: prompt to handle.
 * Return: Nothing.
 */

void _handle(int _prompt)
{
	(void)_prompt;
	write(STDOUT_FILENO, "\n(NMshell) $ ", 14);
}


/**
 * _prompt - Prints the prompt
 * Return: Nothing
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(NMshell) $ ", 13);
}


/**
 * _shell_exit - Exits the shell.
 * @command: Pointer to tokenized command.
 * Return: nothing
 */
void _shell_exit(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		FreeMember(command);
		exit(EXIT_SUCCESS);
	}

	status = _AtoI(command[1]);
	FreeMember(command);
	exit(status);
}


/**
 * _EndOfFile - Chaecks if buffer is EOF
 * @buffer_str: Pointer to the input string.
 * Return: Nothing
 */
void _EndOfFile(char *buffer_str)
{
	if (buffer_str)
	{
		free(buffer_str);
		buffer_str = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer_str);
	exit(EXIT_SUCCESS);
}
