/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:19:29 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 15:19:29 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*push(t_stack *a, int x)
{
	t_node	*new;

	if (!a)
		return (NULL);
	new = new_node(x);
	if (!new)
		return (NULL);
	return (insert(a, new));
}

t_node	*pop(t_stack *a)
{
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	if (!a || !a->head)
		return (NULL);
	if (a->head == a->head->next)
	{
		node = a->head;
		a->head = NULL;
		a->size -= 1;
		return (node);
	}
	node = a->head;
	head = node->next;
	tail = node->prev;
	tail->next = head;
	head->prev = tail;
	a->head = head;
	a->size -= 1;
	node->next = node;
	node->prev = node;
	return (node);
}

t_stack	*insert(t_stack *s, t_node *node)
{
	t_node	*head;
	t_node	*tail;

	if (!s || !node)
		return (s);
	head = s->head;
	if (head)
	{
		tail = head->prev;
		tail->next = node;
		head->prev = node;
		node->next = head;
		node->prev = tail;
	}
	s->head = node;
	s->size += 1;
	return (s);
}
