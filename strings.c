#include "main.h"

/**
 * _StringCompare - Compares two strings
 * @string1: comparison string 1
 * @string2: string 2 for comparison
 * Return: if same, 0 if not
 */

int _StringCompare(char *string1, char *string2)
{
	unsigned int inte = 0;

	while (string1[inte])
	{
		if (string1[inte] != string2[inte])
			return (0);
		inte++;
	}

	return (1);
}


/**
 * _StringLength - Finds the length of a string
 * @string: string pointer
 * Return: length of the string
 */
unsigned int _StringLength(char *string)
{
	int lenght = 0;

	if (!string)
		return (0);

	while (*string++)
		lenght++;
	return (lenght);
}


/**
 * _StringCopy - copies a string to another string
 * @destination: pointer to copied string destination
 * @source: pointer to string copied from
 * Return: Pointer to copied string
 */

char *_StringCopy(char *destination, char *source)
{
	char *aux = destination;

	while (*source)
		*destination++ = *source++;
	*destination = '\0';
	return (aux);
}


/**
 * _StringConcatinate - Function that concatenates two strings.
 * @destination: destination for concatenation
 * @source: an input string
 * Return: pointer to the resulting string
 */

char *_StringConcatinate(char *destination, char *source)
{
	char *temp = destination;

	while (*destination)
		destination++;

	*destination++ = '/';
	while (*source)
		*destination++ = *source++;
	return (temp);
}


/**
 * _AtoI - Function that converts string to integer.
 * @string: Input string.
 * Return: integer equivalent.
 */
int _AtoI(char *string)
{
	int st;
	int sign = 1, str_f = 0, output;
	unsigned int result = 0;

	for (st = 0;  string[st] != '\0' && str_f != 2; st++)
	{
		if (string[st] == '-')
			sign *= -1;

		if (string[st] >= '0' && string[st] <= '9')
		{
			str_f = 1;
			result *= 10;
			result += (string[st] - '0');
		}
		else if (str_f == 1)
			str_f = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
