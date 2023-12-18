/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:16:15 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/17 20:55:40 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	if (!s || !s->head)
		return ;
	if (s->size == 2)
	{
		s->head = s->head->next;
		return ;
	}
	head = s->head;
	tail = head->prev;
	node = head->next;
	tail->next = node;
	head->prev = node;
	head->next = node->next;
	head->next->prev = head;
	node->next = head;
	node->prev = tail;
	s->head = node;
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
