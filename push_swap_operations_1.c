/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:09:45 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/14 00:10:44 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
	printf("rr\n");
}
