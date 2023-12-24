/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:11:21 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/15 18:26:35 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	if (!a)
		return ;
	rev_rotate(a);
}

void	rrb(t_stack *b)
{
	if (!b)
		return ;
	rev_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rev_rotate(a);
	rev_rotate(b);
}
