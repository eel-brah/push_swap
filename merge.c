#include <stdio.h>
#include <stdlib.h>

int  *merge(int *ptr , int size)
{
	int size1;
	int size2;
	int i;
	int j;
	int *p1;
	int *p2;
	if (size <= 1)
		return (ptr);
	size1 = size - size / 2;
	size2 = size / 2;
	p1 = merge(ptr, size - size2);
	p2 = merge(ptr + size1, size - size1);
	int array[size];
	i = 0;
	j = 0;
	int k = 0;
	while (j < size / 2 && i < size - size / 2 )
	{
		if (p1[i] < p2[j])
		{
			array[k] = p1[i];
			i++;
			k++;
		}
		else
		{
			array[k] = p2[j];
			k++;
			j++;
		}
	}
	if (j < i)
	{
		while (j < size / 2)
		{
			array[k++] = p2[j++];
		}
	}
	else
	{
		while (i < size - size / 2)
		{
			array[k++] = p1[i++];
		}
	}
	int x = 0;
	while (x < size)
	{
		ptr[x] = array[x];
		x++;
	}
	return ptr;
}

int main()
{
	int array[] = {7, 5, 4, 9, 1, 55, 88, 909, 0, 888, 22222};
	int size = sizeof(array) / sizeof(int);
	int i = 0;
	while(i < size)
		printf("%i - ", array[i++]);
	printf("\n");
	merge(array, size);
	i = 0;
	while(i < size)
		printf("%i - ", array[i++]);
	printf("\n");
}
