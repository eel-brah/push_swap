/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:07 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/18 04:41:56 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *s)
{
	if (!s || !s->head)
		return ;
	t_node *ptr = s->head;
	t_node *tail = s->head->prev;
    while (ptr != tail)
    {
        ft_printf("%i\n", ptr->item);
        ptr = ptr->next;
    } 
	ft_printf("%i\n", ptr->item);
}

void fn()
{
	system("leaks a.out");
}

void	sort(t_stack *a)
{
	t_stack *b = new_stack();
	if (!b)
		return ;
	int i = 0;
	int t;
	int half;
	int r;
	t_node *tmp;

	while (a->size - 1)
		pb(a, b);
	i = 1;
	while (b->size)
	{
		if (a->head->item > b->head->item)
		{
			pa(b, a);
		}
		else 
		{
			
			tmp = a->head;
			t = 0;
			while (tmp->item < b->head->item && t < a->size)
			{
				tmp = tmp->next;
				t++;
			}

			if (t == 1)
			{
				pa(b, a);
				sa(a);
			}
			else if (t == a->size)
			{
				pa(b, a);
				ra(a);
			}
			else
			{
				half = a->size / 2;
				if (t <= half)
				{
					r = 0;
					while (r < t - 1)
					{
						ra(a);
						r++;
					}
					pa(b, a);
					sa(a);
					r = 0;
					while (r < t - 1)
					{
						rra(a);
						r++;
					}
				}
				else
				{
					r = 0;
					while (r < a->size +  - t)
					{
						rra(a);
						r++;
					}
					pa(b, a);
					r = 0;
					while (r < a->size - t)
					{
						ra(a);
						r++;
					}
				}

			}
		}
	}
	free_stack(b);
}


int main(int argc, char **argv)
{
	// atexit(fn);
	// if (create_stack(argc - 1, argv))
	// 	return (1);
    t_stack	*a;

	if (argc < 2)
		return (0);
	a = new_stack();
	if (!a)
		return (1);
	if (!push_to_stack(argc - 1, argv, a))
		return (1);
	// print_stack(a);
	// sort_10(a);
	// sort_10(a);
	sort(a);
	// ft_printf("\n-----\n");
	print_stack(a);
	free_stack(a);
	return (0);
}
