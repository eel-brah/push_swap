/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:41:19 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/24 13:42:09 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instractions	a_up_b_up(int b_instractions, int a_instractions)
{
	t_instractions	insts;

	insts.rr = min(a_instractions, b_instractions);
	insts.ra = a_instractions - insts.rr;
	insts.rb = b_instractions - insts.rr;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = 0;
	insts.all = max(a_instractions, b_instractions);
	return (insts);
}

t_instractions	a_down_b_down(int b_instractions, int a_instractions)
{
	t_instractions	insts;

	insts.rr = 0;
	insts.ra = 0;
	insts.rb = 0;
	insts.rrr = min(a_instractions, b_instractions);
	insts.rra = a_instractions - insts.rrr;
	insts.rrb = b_instractions - insts.rrr;
	insts.all = max(a_instractions, b_instractions);
	return (insts);
}


t_instractions	a_down_b_up(int b_instractions, int a_instractions)
{
	t_instractions	insts;

	insts.rr = 0;
	insts.ra = 0;
	insts.rb = b_instractions;
	insts.rrr = 0;
	insts.rra = a_instractions;
	insts.rrb = 0;
	insts.all = insts.rra + insts.rb;
	return (insts);
}

t_instractions	a_up_b_down(int b_instractions, int a_instractions)
{
	t_instractions	insts;

	insts.rr = 0;
	insts.ra = a_instractions;
	insts.rb = 0;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = b_instractions;
	insts.all = insts.ra + insts.rrb;
	return (insts);
}
