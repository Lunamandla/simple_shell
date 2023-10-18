#include "main.h"

/**
  * shift_folder -  function that changes working directory
  *
  * @way: The new current working directory
  *
  * Return: 0 on success, -1 on failure.
  */

int shift_folder(const char *way)
{
	char *buf = NULL;
	size_t size = 1024;

	if (way == NULL)
		way = getcwd(buf, size);
	if (chdir(way) == -1)
	{
		perror(way);
		return (98);
	}
	return (1);
}


/**
 * child_pid - Function that creates a sub process.
 * @order: Pointer to tokenized command
 * @form: Pointer to shell name.
 * @envir: Enviromental variables pointer.
 * @loops: No of executed cicles.
 * Return: Nothing.
 */
void child_pid(char **order, char *form, char **envir, int loops)
{
	int p_i_d = 0;
	int status = 0;
	int waitError = 0;

	p_i_d = fork();
	if (p_i_d < 0)
	{
		perror("Error: ");
		ExitFree(order);
	}
	else if (p_i_d == 0)
	{
		Execute(order, form, envir, loops);
		FreeMember(order);
	}
	else
	{
		waitError = waitpid(p_i_d, &status, 0);
		if (waitError < 0)
		{
			ExitFree(order);
		}
		FreeMember(order);
	}
}
