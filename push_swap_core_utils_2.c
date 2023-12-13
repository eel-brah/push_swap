/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:16:15 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/13 18:16:47 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	if (!a || !a->head)
		return ;
	head = a->head;
	tail = head->prev;
	node = head->next;
	tail->next = node;
	head->prev = node;
	head->next = node->next;
	head->next->prev = head;
	node->next = head;
	node->prev = tail;
	a->head = node;
}

void	push_fr_to(t_stack *from, t_stack *to)
{
	if (!from || !from->head)
		return ;
	to = insert(to, pop(from));
}

void	rotate(t_stack *s)
{
	if (!s || !s->head)
		return ;
	s->head = s->head->next;
}

void	rev_rotate(t_stack *s)
{
	if (!s || !s->head)
		return ;
	s->head = s->head->prev;
}
