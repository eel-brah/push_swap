/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:23:34 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 14:23:34 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static int	is_exist(t_stack *s, int x)
{
	t_node	*ptr;
	t_node	*tail;

	if (!s || !s->head)
		return (1);
	ptr = s->head;
	tail = s->head->prev;
	while (ptr != tail)
	{
		if (x == ptr->item)
			return (0);
		ptr = ptr->next;
	}
	if (x == ptr->item)
		return (0);
	return (1);
}

static int	an_error(char **s, t_stack *a)
{
	strs_free(s);
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	push_to_stack_2(t_stack *a, char*s)
{
	ssize_t	nb;

	if (!is_all_digits(s))
		return (0);
	nb = str_to_int(s);
	if (nb > ~(1 << 31))
		return (0);
	if (!is_exist(a, nb))
		return (0);
	push(a, nb);
	return (1);
}

int	push_to_stack(int args_nb, char **args, t_stack *a)
{
	int		size;
	char	**s;

	while (args_nb)
	{
		s = ft_split(args[args_nb], ' ');
		if (!s)
			return (an_error(s, a));
		size = strs_size(s);
		if (size < 1)
			return (an_error(s, a));
		while (size)
		{
			if (!push_to_stack_2(a, s[size - 1]))
				return (an_error(s, a));
			size--;
		}
		args_nb--;
		strs_free(s);
	}
	return (1);
}
