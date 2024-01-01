/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:41 by eel-brah          #+#    #+#             */
/*   Updated: 2024/01/01 15:49:06 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	sorted(t_stack *a)
{
	int		poz;
	t_node	*a_stack;

	poz = 0;
	a_stack = a->head;
	if (a->size <= 1)
		return (1);
	while (poz < a->size - 1)
	{
		if (a_stack->item > a_stack->next->item)
			return (0);
		a_stack = a_stack->next;
		poz++;
	}
	return (1);
}

static int	an_error_2(t_stack *a, t_stack *b, char *ins)
{
	free_stack(a);
	free_stack(b);
	free(ins);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	applay_ins(t_stack *a, t_stack *b, char *ins)
{
	if (ft_strncmp(ins, "sa\n", 4) == 0)
		sa(a);
	else if (ft_strncmp(ins, "sb\n", 4) == 0)
		sb(b);
	else if (ft_strncmp(ins, "ss\n", 4) == 0)
		ss(a, b);
	else if (ft_strncmp(ins, "pa\n", 4) == 0)
		pa(b, a);
	else if (ft_strncmp(ins, "pb\n", 4) == 0)
		pb(a, b);
	else if (ft_strncmp(ins, "ra\n", 4) == 0)
		ra(a);
	else if (ft_strncmp(ins, "rb\n", 4) == 0)
		rb(b);
	else if (ft_strncmp(ins, "rr\n", 4) == 0)
		rr(a, b);
	else if (ft_strncmp(ins, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(ins, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(ins, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (an_error_2(a, b, ins));
	return (0);
}

static int	checker(t_stack *a, t_stack *b)
{
	char	*ins;

	while (1)
	{
		ins = get_next_line(0);
		if (!ins)
			break ;
		if (applay_ins(a, b, ins))
			return (1);
		free(ins);
	}
	if (b->size == 0 && sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = new_stack();
	if (!a)
		return (1);
	if (!push_to_stack(argc - 1, argv, a))
		return (1);
	b = new_stack();
	if (!b)
	{
		free_stack(a);
		return (1);
	}
	if (checker(a, b))
		return (1);
	free_stack(a);
	free_stack(b);
	return (0);
}
