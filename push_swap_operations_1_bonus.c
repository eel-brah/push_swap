/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:09:45 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/15 18:26:30 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
}
