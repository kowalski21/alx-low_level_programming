#include "main.h"

/**
 * print_binary - prints binary equivalent of decimal number
 * @n: input argument of type long int
 */
void print_binary(unsigned long int n)
{
	int track_counter = 0;
	int j = 0;
	unsigned long int shift_num;
	/* unsigned integer range */

	for (j = 63; j >= 0; j--)

	{
		shift_num = n >> j;

		if (shift_num & 1)
		{
			_putchar('1');
			track_counter++;
		}
		else if (track_counter)
			_putchar('0');
	}
	if (!track_counter)
		_putchar('0');
}