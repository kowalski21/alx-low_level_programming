#include "search_algos.h"

/**
  *bin_search_recursive - Searches recursively for a value in a sorted
  * @array: A pointer to the first element of the [sub]array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present, -1.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int bin_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t idx;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (idx = left; idx < right; idx++)
		printf("%d, ", array[idx]);
	printf("%d\n", array[idx]);

	idx = left + (right - left) / 2;
	if (array[idx] == value)
		return (idx);
	if (array[idx] > value)
		return (bin_search_recursive(array, left, idx - 1, value));
	return (bin_search_recursive(array, idx + 1, right, value));
}

/**
  * binary_search - Searches for a value in a sorted array
  *                 of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (bin_search_recursive(array, 0, size - 1, value));
}
