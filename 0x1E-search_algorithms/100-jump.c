#include "search_algos.h"

/**
  * jump_search - Search item in array using jump
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  * Description: Prints a value every time it is compared in the array.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t idx, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (idx = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		idx = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", idx, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; idx < jump && array[idx] < value; idx++)
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
	printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);

	return (array[idx] == value ? (int)idx : -1);
}
