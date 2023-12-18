#include "push_swap.h"


void sheft_put(int i, int j, int *array)
{
	int t;

	if (j < 0 || j == i)
		return ;
	t = array[i];
	while (j < i)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[j] = t;
}
#include <limits.h>

void insertion(int *array, int arr_size)
{
	int i;
	int j;

	i = 0;
	while(i < arr_size)
	{
		j = i - 1;
		while (j >= 0 && array[j] > array[i])
			j--;
		sheft_put(i, j + 1, array);
		i++;
	}
}

int main()
{
	int i = 0;
	int array[] = {-1, INT_MAX, INT_MIN , 9, 1, 55, 'a', 'i', };
	int arr_size = sizeof(array) / sizeof(int);

	while (i < arr_size)
		printf("%i, ", array[i++]);
	printf("\n---\n");
	insertion(array, arr_size);
	i = 0;
	while (i < arr_size)
		printf("%i, ", array[i++]);
	printf("\n");
}
