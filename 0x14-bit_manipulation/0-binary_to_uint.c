#include "main.h"
/**
* binary_to_uint - Convert a binary number to an unsigned integer
* @b: A pointer to char takes 0 and 1
*
* Return: converted number or 0
*  if b is null or if string is not 0 or 1
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;
int i = 0;
int len = 0;
if (*b == '\0')
{
	return (0);
}

while (b[len])
{
if (b[len] != '0' && b[len] != '1')
{
return (0);
}
len++;
}
for (i = 0; b[i]; i++)
{
num <<= 1;
if (b[i] == '1')
{
num |= 1;
}
}
return (num);

}
