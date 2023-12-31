/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:06:22 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 19:48:35 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_size(int a_size)
{
	if (a_size >= 60 && a_size < 150)
		return ((float)a_size / 2.5);
	else if (a_size >= 150 && a_size < 400)
		return ((float)a_size / 2.5);
	else if (a_size >= 400 && a_size < 700)
		return ((float)a_size / 3.5);
	else if (a_size >= 700 && a_size < 900)
		return ((float)a_size / 4.5);
	else
		return ((float)a_size / 5.5);
}

static int	*sub_sort(t_stack *a)
{
	int		*array;
	t_node	*a_stack;
	int		i;

	i = 0;
	a_stack = a->head;
	array = malloc(sizeof(int) * a->size);
	if (!array)
		return (NULL);
	while (i < a->size)
	{
		array[i++] = a_stack->item;
		a_stack = a_stack->next;
	}
	if (!merge_sort(array, a->size))
	{
		free (array);
		return (NULL);
	}
	return (array);
}

int	send_from_a_to_b(t_stack *a, t_stack *b)
{
	int	*array;

	array = NULL;
	if (a->size >= 60)
	{
		array = sub_sort(a);
		if (!array)
			return (1);
		send_to_b(a, b, array, get_size(a->size));
		sort_three(a);
		free(array);
	}
	else
	{
		while (a->size - 3)
			pb(a, b);
		sort_three(a);
		if (b->size == 2 && is_sorted(b))
			sb(b);
	}
	return (0);
}
