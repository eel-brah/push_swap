/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_0_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:27:21 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/14 00:10:20 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap(a);
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
}

void	pa(t_stack *b, t_stack *a)
{
	if (!a || !b)
		return ;
	push_fr_to(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	push_fr_to(a, b);
}
