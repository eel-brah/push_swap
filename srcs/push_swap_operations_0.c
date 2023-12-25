/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_0.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:19:13 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 15:19:13 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_stack *b, t_stack *a)
{
	if (!a || !b)
		return ;
	push_fr_to(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	push_fr_to(a, b);
	ft_printf("pb\n");
}
