#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be
 * @n: The number.
 * @m: The number to flip n to.
 * Return: The necessary number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor = n ^ m;
unsigned long int result = 0;

while (xor != 0)
{
result += (xor & 1);
xor >>= 1;
}

return (result);
}
