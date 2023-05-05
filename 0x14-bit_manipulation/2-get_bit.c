#include "main.h"

/**
 * get_bit - to  returns the value of a bit at a given index.
 * @n: number for search
 * @index: index of the bit
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int result;

	if ((int) index < 0 || index >= sizeof(int) * 8)
		return (-1);

result = (n >> index) && 1;

	return (result);
}
