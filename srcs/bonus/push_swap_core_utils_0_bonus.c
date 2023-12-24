/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils_0_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:10:35 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/14 00:12:13 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
 
t_stack	*new_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->head = NULL;
	s->size = 0;
	return (s);
}

t_node	*new_node(int x)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->item = x;
	new->next = new;
	new->prev = new;
	return (new);
}

void	free_stack(t_stack *a)
{
	t_node	*node;
	t_node	*tail;
	t_node	*tmp;

	if (!a)
		return ;
	if (a->head)
	{
		node = a->head;
		tail = node->prev;
		while (node != tail)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(tail);
	}
	free(a);
}
