/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:07:44 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 19:46:47 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *a)
{
	int		poz;
	t_node	*a_stack;

	poz = 0;
	a_stack = a->head;
	if (a->size <= 1)
		return (1);
	while (poz < a->size - 1)
	{
		if (a_stack->item > a_stack->next->item)
			return (0);
		a_stack = a_stack->next;
		poz++;
	}
	return (1);
}

static void	sort_three_2(t_node *a_stack, t_stack *a)
{
	if (a_stack->item < a_stack->next->item
		&& a_stack->next->item > a_stack->next->next->item)
		rra(a);
	else if (a_stack->item > a_stack->next->item
		&& a_stack->next->item < a_stack->next->next->item
		&& a_stack->next->next->item > a_stack->item)
		sa(a);
	else if (a_stack->item > a_stack->next->item
		&& a_stack->next->item < a_stack->next->next->item
		&& a_stack->next->next->item < a_stack->item)
		ra(a);
	else if (a_stack->item > a_stack->next->item
		&& a_stack->next->item > a_stack->next->next->item
		&& a_stack->next->next->item < a_stack->item)
	{
		ra(a);
		sa(a);
	}
}

void	sort_three(t_stack *a)
{
	t_node	*a_stack;

	a_stack = a->head;
	if (a->size == 2)
	{
		if (a->head->item > a->head->next->item)
			sa(a);
		return ;
	}
	if (a_stack->item < a_stack->next->item
		&& a_stack->next->item > a_stack->next->next->item
		&& a_stack->next->next->item > a_stack->item)
	{
		sa(a);
		ra(a);
	}
	else
		sort_three_2(a_stack, a);
}

void	sort(t_stack *a)
{
	t_stack	*b;

	if (is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	b = new_stack();
	if (!b)
		return ;
	if (send_from_a_to_b(a, b))
	{
		free_stack(b);
		return ;
	}
	sort_back_to_a(a, b);
	get_the_smallest_to_the_top(a);
	free_stack(b);
}
