/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:09:45 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/15 18:26:30 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
