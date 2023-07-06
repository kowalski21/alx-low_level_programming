#include "main.h"


/**
 * recur - recursive function to shift and print bits
 * @num: input argument to my recursive function
*/
void recur(unsigned long int num)
{
if (num > 1)
{
recur(num >> 1);
}
putchar((num & 1) + '0');
}

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
*/
void print_binary(unsigned long int n)
{
if (n == 0)
{
putchar('0');
}
else
{
recur(n);
}
}
