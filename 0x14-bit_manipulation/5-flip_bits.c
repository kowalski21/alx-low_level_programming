#include "main.h"
/**
 * flip_bits - function that returns the number of bits you flipped
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int maverick = n ^ m;
unsigned long int t;
int i = 0;
int count = 0;



for (i = 63; i >= 0; i--)
{
	t = maverick >> i;
	if (t & 1)
		count++;
}

	return (count);
}
