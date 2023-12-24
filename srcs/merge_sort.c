#include <stdio.h>
#include <stdlib.h>

typedef struct s_ary
{
	int	*p;
	int size;
}	t_ary;

void	rem_1(int *tmp_array, int k, t_ary *p2, int j)
{
	while (j < p2->size)
		tmp_array[k++] = p2->p[j++];
}

void	rem_2(int *tmp_array, int k, t_ary *p1, int i)
{
	while (i < p1->size)
		tmp_array[k++] = p1->p[i++];
}

int	*combine(t_ary *p1, t_ary *p2, int size)
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
	while (j < p2->size && i < p1->size)
	{
		if (p1->p[i] > p2->p[j])
			tmp_array[k] = p1->p[i++];
		else
			tmp_array[k] = p2->p[j++];
		k++;
	}
	if (j < i)
		rem_1(tmp_array, k, p2, j);
	else
		rem_2(tmp_array, k, p1, i);
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

int  *merge_sort(int *ptr , int size)
{
	t_ary p1;
	t_ary p2;
	int *tmp_array;

	if (size <= 1)
		return (ptr);
	p1.size = size - size / 2;
	p2.size = size / 2;
	p1.p = merge_sort(ptr, p1.size);
	p2.p = merge_sort(ptr + p1.size, p2.size);
	tmp_array = combine(&p1, &p2, size);
	if (!tmp_array)
		return (NULL);
	merge(tmp_array, ptr, size);
	free(tmp_array);
	return ptr;
}

// #include <limits.h>
// int main()
// {
// 	int array[] = {-1, INT_MAX, INT_MIN , 9, 1, 55, 'a', 'i', 0, 888, 22222, 9999};

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
