#include "search_algos.h"

/**
  * linear_search - Searches for a int value in an array
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  * Description: Prints a value every time it is compared in the array.
  */
int linear_search(int *array, size_t size, int value)
{
	size_t counter;

	if (array == NULL)
		return (-1);

	for (counter = 0; counter < size; counter++)
	{
		printf("Value checked array[%ld] = [%d]\n", counter, array[counter]);
		if (array[counter] == value)
			return (counter);
	}

	return (-1);
}
