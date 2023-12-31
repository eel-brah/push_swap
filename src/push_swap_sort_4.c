/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:04:51 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 19:52:28 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	up_opperations(t_stack *a, t_stack *b, t_instractions insts)
{
	while (insts.rr)
	{
		rr(a, b);
		insts.rr--;
	}
	while (insts.ra)
	{
		ra(a);
		insts.ra--;
	}
	while (insts.rb)
	{
		rb(b);
		insts.rb--;
	}
}

static void	down_opperations(t_stack *a, t_stack *b, t_instractions insts)
{
	while (insts.rrr)
	{
		rrr(a, b);
		insts.rrr--;
	}
	while (insts.rra)
	{
		rra(a);
		insts.rra--;
	}
	while (insts.rrb)
	{
		rrb(b);
		insts.rrb--;
	}
}

void	applay_opperations(t_stack *a, t_stack *b, t_instractions insts)
{
	up_opperations(a, b, insts);
	down_opperations(a, b, insts);
	pa(b, a);
}
