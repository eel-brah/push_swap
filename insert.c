#include "push_swap.h"


void swap_nb(int i, int j, int *array)
{
	int t;
	int	k;

	if (j < 0)
		return ;
	t = array[i];
	while (j < i)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[j] = t;
}

int main()
{
	int i = 0;
	int j = 0;
	int array[] = {45646, 5, 9, 1, 36, 10, 8, 2, 19};
	int arr_size = 9;

	while (i < arr_size)
		printf("%i ", array[i++]);
	printf("\n---\n");
	i = 0;
	while(i < arr_size)
	{
		j = i - 1;
		while (j >= 0 && array[j] > array[i])
			j--;
		swap_nb(i, j + 1, array);
		i++;
	}
	i = 0;
	while (i < arr_size)
		printf("%i ", array[i++]);
}
