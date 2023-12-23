#include <stdio.h>
#include <stdlib.h>

int	*combine(int *p1, int *p2, int size, int size_1, int size_2, char c)
{
	int *tmp_array;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	tmp_array = malloc(sizeof(int) * size);
	if (!tmp_array)
		return (NULL);
	while (j < size_2 && i < size_1)
	{
		if (c == 'k')
		{
			if (p1[i] > p2[j])
				tmp_array[k] = p1[i++];
			else
				tmp_array[k] = p2[j++];
		}
		else
		{
			if (p1[i] < p2[j])
				tmp_array[k] = p1[i++];
			else
				tmp_array[k] = p2[j++];
		}
		k++;
	}
	if (j < i)
	{
		while (j < size_2)
			tmp_array[k++] = p2[j++];
	}
	else
	{
		while (i < size_1)
			tmp_array[k++] = p1[i++];
	}
	return (tmp_array);
}

void merge(int *tmp_array, int *ptr, int size)
{
	int x = 0;
	while (x < size)
	{
		ptr[x] = tmp_array[x];
		x++;
	}
}

int  *merge_sort(int *ptr , int size, char c)
{
	int size_1;
	int size_2;
	int *p1;
	int *p2;
	int *tmp_array;

	if (size <= 1)
		return (ptr);
	size_1 = size - size / 2;
	size_2 = size / 2;
	p1 = merge_sort(ptr, size_1, c);
	p2 = merge_sort(ptr + size_1, size_2, c);
	tmp_array = combine(p1, p2, size, size_1, size_2, c);
	if (!tmp_array)
		return (NULL);
	merge(tmp_array, ptr, size);
	free(tmp_array);
	return ptr;
}

// #include <limits.h>
// int main()
// {
// 	int array[] = {-1, INT_MAX, INT_MIN , 9, 1, 55, 'a', 'i', 0, 888, 22222};

// 	int size = sizeof(array) / sizeof(int);
// 	int i = 0;
// 	while(i < size)
// 		printf("%i, ", array[i++]);
// 	printf("\n");
// 	merge_sort(array, size);
// 	i = 0;
// 	while(i < size)
// 		printf("%i, ", array[i++]);
// 	printf("\n");
// }
