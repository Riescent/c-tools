#include <stdbool.h>
#include <stdio.h>
#include "random-riescent.h"

// Used to get the size of an array
#define arrsize(arr) sizeof(arr) / sizeof(arr[0])

//#include "random-riescent.h"
// Randomize all member of an int array in a set range (min and max are included)
void randomize_arr_int(int *arr, const int arr_size, const int min, const int max)
{
	for (int i = 0; i < arr_size; i++)
		arr[i] = random_range(min, max);
}

//#include <stdbool.h>
// Sorts an int array from lower to bigger
void sort_arr_int(int *ptr_arr, const int arr_size)
{
	bool changed_something = false;
	int temp;
	while (1)
	{
		changed_something = false;
		for (int i = 0; i < arr_size - 1; i++)
		{
			if (ptr_arr[i] > ptr_arr[i + 1])
			{
				temp = ptr_arr[i + 1];
				ptr_arr[i + 1] = ptr_arr[i];
				ptr_arr[i] = temp;
				changed_something = true;
			}
		}
		if (changed_something == false)
			break;
	}
}

// Does a binary search for 'target' on an int array
int bi_search_arr_int(const int target, const int *arr, const int arr_size)
{
	int mid;
	int high = arr_size - 1;
	int low = 0;

	while (high - low > 1)
	{
		mid = (high + low) / 2;
		if ((arr[mid]) > target)
			high = mid;
		else
			low = mid;
	}
	if (arr[mid] == target)
		return (mid);
	else
		return (-1);
}

//#include <stdio.h>
// Prints all members of an int arr
void print_arr_int(const int *arr, const int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf("%i\n", arr[i]);
}
