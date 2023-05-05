#include "main.h"

/**
 * get_endianness - check endianess of the machine
 * Return: 1 for little, 0 for small
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *c = (char *) &j;

	return (*c);
}
