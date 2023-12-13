#include "search_algos.h"

/**
  * interpolation_search - Search using interpolation
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *
  * Description: Prints a value every time it is compared in the array..
  */
int interpolation_search(int *array, size_t size, int value)
{
	size_t ix, l, re;

	if (array == NULL)
		return (-1);

	for (l = 0, re = size - 1; re >= l;)
	{
		ix = l + (((double)(re - l) / (array[re] - array[l])) * (value - array[l]));
		if (ix < size)
			printf("Value checked array[%ld] = [%d]\n", ix, array[ix]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", ix);
			break;
		}

		if (array[ix] == value)
			return (ix);
		if (array[ix] > value)
			re = ix - 1;
		else
			l = ix + 1;
	}

	return (-1);
}
