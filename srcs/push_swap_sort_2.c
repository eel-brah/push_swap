/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:06:02 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 19:50:02 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_exist_2(int a_item, int *array, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		if (a_item == array[i++])
			return (1);
	}
	return (0);
}

static void	push_to_b(t_stack *a, t_stack *b, int poz)
{
	int	r;

	r = 0;
	if (poz <= a->size / 2)
	{
		while (r < poz)
		{
			ra(a);
			r++;
		}
	}
	else
	{
		while (r < a->size - poz)
		{
			rra(a);
			r++;
		}
	}
	pb(a, b);
}

static t_node	*send_1(t_stack *a, t_stack *b, int *poz, int *i)
{
	push_to_b(a, b, *poz);
	*poz = 0;
	(*i)++;
	return (a->head);
}

static t_node	*send_2(t_stack *a, t_stack *b, int *poz)
{
	push_to_b(a, b, *poz);
	rb(b);
	*poz = 0;
	return (a->head);
}

void	send_to_b(t_stack *a, t_stack *b, int *array, int size)
{
	int		i;
	int		poz;
	int		*ptr;
	t_node	*a_stack;

	poz = 0;
	ptr = array + size;
	a_stack = a->head;
	while (a->size != 3)
	{
		i = 0;
		while (a->size != 3 && i < size)
		{
			if (is_exist_2(a_stack->item, ptr, size))
				a_stack = send_1(a, b, &poz, &i);
			else if (is_exist_2(a_stack->item, array, size))
				a_stack = send_2(a, b, &poz);
			else
			{
				a_stack = a_stack->next;
				poz++;
			}
		}
		ptr += size;
	}
}
