#include "main.h"

/**
 * ExitFree - free all the memory allocated and exit
 * @code: pointer to command memory
 * Return: Nothing.
 */

void ExitFree(char **code)
{
	size_t inte = 0;

	if (code == NULL)
		return;

	while (code[inte])
	{
		free(code[inte]);
		inte++;
	}

	if (code[inte] == NULL)
		free(code[inte]);
	free(code);
	exit(EXIT_FAILURE);
}


/**
 * FreeMember - frees all the memory allocated for command
 * @code: Pointer to allocated memory
 * Return: nothing.
 */
void FreeMember(char **code)
{
	size_t inte = 0;

	if (code == NULL)
		return;

	while (code[inte])
	{
		free(code[inte]);
		inte++;
	}

	if (code[inte] == NULL)
		free(code[inte]);
	free(code);
}
