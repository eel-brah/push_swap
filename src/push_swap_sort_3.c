/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:05:04 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 19:56:08 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_instractions	calc_instactions_1(int b_down, int b_up,
							int a_up, int a_down)
{
	t_instractions	insts;
	t_instractions	tmp_insts;

	insts = a_up_b_up(b_up, a_up);
	tmp_insts = a_down_b_up(b_up, a_down);
	if (tmp_insts.all < insts.all)
		insts = tmp_insts;
	tmp_insts = a_down_b_down(b_down, a_down);
	if (tmp_insts.all < insts.all)
		insts = tmp_insts;
	return (insts);
}

static t_instractions	calc_instactions_2(int b_down, int b_up,
							int a_up, int a_down)
{
	t_instractions	insts;
	t_instractions	tmp_insts;

	insts = a_up_b_up(b_up, a_up);
	tmp_insts = a_up_b_down(b_down, a_up);
	if (tmp_insts.all < insts.all)
		insts = tmp_insts;
	tmp_insts = a_down_b_down(b_down, a_down);
	if (tmp_insts.all < insts.all)
		insts = tmp_insts;
	return (insts);
}

static t_instractions	calc_instactions_0(t_stack *a, int b_size,
				int b_pz, t_node *b_stack)
{
	int	poz;

	poz = find_position_3_3(a, b_stack->item);
	if (b_pz <= b_size / 2)
		return (calc_instactions_1(b_size - b_pz, b_pz, poz, a->size - poz));
	else
		return (calc_instactions_2(b_size - b_pz, b_pz, poz, a->size - poz));
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	int				b_pz;
	t_node			*b_stack;
	t_instractions	insts;
	t_instractions	lowest_insts;

	while (b->size)
	{
		b_stack = b->head;
		b_pz = 0;
		while (b_pz < b->size)
		{
			insts = calc_instactions_0(a, b->size, b_pz, b_stack);
			if (b_pz == 0)
				lowest_insts = insts;
			else if (insts.all < lowest_insts.all)
				lowest_insts = insts;
			b_stack = b_stack->next;
			b_pz++;
		}
		applay_opperations(a, b, lowest_insts);
	}
}
