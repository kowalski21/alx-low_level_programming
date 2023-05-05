#include "main.h"
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{

	unsigned int result = 0;
	int j = 0;

	if (!b)
		return (0);

	for (j = 0; b[j] != '\0'; j++)
	{
		if (!(b[j] >= '0' && b[j] <= '1'))
			return (0);
		result = (result << 1) | (b[j] - '0');

	}

	return (result);
}

