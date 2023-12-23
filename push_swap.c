/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:07 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/23 22:33:32 by eel-brah         ###   ########.fr       */
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
	system("leaks push_swap");
}








int min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int highest(t_stack *a)
{
	int h;
	t_node *a_stack;
	int poz;

	a_stack = a->head;
	h = a_stack->item;
	poz = 0;
	while (poz < a->size)
	{
		if (a_stack->item > h)
			h = a_stack->item;
		a_stack = a_stack->next;
		poz++;
	}
	return (h);
}

int lowest(t_stack *a)
{
	int l;
	t_node *a_stack;
	int poz;

	a_stack = a->head;
	l = a_stack->item;
	poz = 0;
	while (poz < a->size)
	{
		if (a_stack->item < l)
			l = a_stack->item;
		a_stack = a_stack->next;
		poz++;
	}
	return (l);
}

int where_is_it(t_stack *a, int nb)
{
	t_node *a_stack;
	int poz;

	a_stack = a->head;
	poz = 0;
	while (poz < a->size)
	{
		if (a_stack->item == nb)
			return (poz);
		a_stack = a_stack->next;
		poz++;
	}
	return (poz);
}

int find_position_3_3(t_stack *a, int b_item)
{
	t_node	*a_stack;
	int		poz;
	int		h;
	int		l;

	h = highest(a);
	if (b_item >= h)
		return (where_is_it(a, h) + 1);
	l = lowest(a);
	if (b_item <= l)
		return (where_is_it(a, l));
	a_stack = a->head;
	poz = 0;
	while (poz < a->size)
	{
		if (b_item <= a_stack->item && b_item > a_stack->prev->item)
			return (poz);
		a_stack = a_stack->next;
		poz++;
	}
	return (poz);
}

t_instractions a_up_b_up(int b_instractions, int a_instractions)
{
	t_instractions insts;

	insts.rr = min(a_instractions, b_instractions);
	insts.ra = a_instractions - insts.rr;
	insts.rb = b_instractions - insts.rr;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = 0;
	insts.all = max(a_instractions, b_instractions);
	return (insts);
}

t_instractions a_down_b_down(int b_instractions, int a_instractions)
{
	t_instractions insts;

	insts.rr = 0;
	insts.ra = 0;
	insts.rb = 0;
	insts.rrr = min(a_instractions, b_instractions);
	insts.rra = a_instractions - insts.rrr;
	insts.rrb = b_instractions - insts.rrr;
	insts.all = max(a_instractions, b_instractions);
	return (insts);
}


t_instractions a_down_b_up(int b_instractions, int a_instractions)
{
	t_instractions insts;

	insts.rr = 0;
	insts.ra = 0;
	insts.rb = b_instractions;
	insts.rrr = 0;
	insts.rra = a_instractions;
	insts.rrb = 0;
	insts.all = insts.rra + insts.rb;
	return (insts);
}

t_instractions a_up_b_down(int b_instractions, int a_instractions)
{
	t_instractions insts;

	insts.rr = 0;
	insts.ra = a_instractions;
	insts.rb = 0;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = b_instractions;
	insts.all = insts.ra + insts.rrb;
	return (insts);
}

void up_opperations(t_stack *a, t_stack *b, t_instractions insts)
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

void down_opperations(t_stack *a, t_stack *b, t_instractions insts)
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

void applay_opperations(t_stack *a, t_stack *b, t_instractions insts)
{
	up_opperations(a, b, insts);
	down_opperations(a, b, insts);
	pa(b, a);
}

t_instractions	calc_instactions_1(int b_down, int b_up, int a_up, int a_down)
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

t_instractions	calc_instactions_2(int b_down, int b_up, int a_up, int a_down)
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

t_instractions	calc_instactions_0(t_stack *a, int b_size, int b_pz, t_node *b_stack)
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


void	get_the_smallest_to_the_top(t_stack *a)
{
	int	poz;
	int	r;

	poz = find_position_3_3(a, lowest(a));
	r = 0;
	if (poz <= a->size / 2)
	{
		while (r < poz)
		{
			ra(a);
			r++;
		}
	}
	else
	{
		while (r < a->size - poz)
		{
			rra(a);
			r++;
		}
	}
}


int	is_exist_2(int a_item, int *array, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (a_item == array[i++])
			return (1);
	}	
	return (0);
}

void	push_to_b(t_stack *a, t_stack *b, int poz)
{
	int	r;

	r = 0;
	if (poz <= a->size / 2)
	{
		while (r < poz)
		{
			ra(a);
			r++;
		}
	}
	else
	{
		while (r < a->size - poz)
		{
			rra(a);
			r++;
		}
	}
	pb(a, b);
}

t_node	*send_1(t_stack *a, t_stack *b, int *poz, int *i)
{
	push_to_b(a, b, *poz);
	*poz = 0;
	(*i)++;
	return (a->head);
}

t_node	*send_2(t_stack *a, t_stack *b, int *poz)
{
	push_to_b(a, b, *poz);
	rb(b);
	*poz = 0;
	return (a->head);
}

void	send_to_b(t_stack *a, t_stack *b, int *array, int size)
{
	int		i;
	int		poz;
	int		*ptr;
	t_node	*a_stack;

	poz = 0;
	ptr = array + size;
	a_stack = a->head;
	while (a->size != 3)
	{
		i = 0;
		while (a->size != 3 && i < size)
		{
			if (is_exist_2(a_stack->item, ptr, size))
				a_stack = send_1(a, b, &poz, &i);
			else if (is_exist_2(a_stack->item, array, size))
				a_stack = send_2(a, b, &poz);
			else
			{
				a_stack = a_stack->next;
				poz++;
			}
		}
		ptr += size;
	}
}

int	get_size(int a_size)
{
	if (a_size >= 60 && a_size < 150)
		return ((float)a_size / 2.5);
	else if (a_size >= 150 && a_size < 400)
		return ((float)a_size / 2.5);
	else if (a_size >= 400 && a_size < 700)
		return ((float)a_size / 3.5);
	else if (a_size >= 700 && a_size < 900)
		return ((float)a_size / 4.5);
	else 
		return ((float)a_size / 5.5);
}

int	*sub_sort(t_stack *a)
{
	int		*array;
	t_node	*a_stack;
	int		i;

	i = 0;
	a_stack = a->head;
	array = malloc(sizeof(int) * a->size);
	if (!array)
		return (NULL);
	while (i < a->size)
	{
		array[i++] = a_stack->item;
		a_stack = a_stack->next;
	}
	if (!merge_sort(array, a->size, 'k'))
	{
		free (array);
		return (NULL);
	}
	return (array);
}

int	send_from_a_to_b(t_stack *a, t_stack *b)
{
    int	*array;

	array = NULL;
	if (a->size >= 60)
	{ 
		array = sub_sort(a);
		if (!array)
			return (1);
		send_to_b(a, b, array, get_size(a->size));
		sort_three(a);
		free(array);
	}
	else 
	{
		while (a->size - 3)
			pb(a, b);
		sort_three(a);
		if (b->size == 2 && is_sorted(b))
			sb(b);
	}
	return (0);
}




int	is_sorted(t_stack *a)
{
	int	poz;
	t_node *a_stack;

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

void sort_three(t_stack *a)
{
	t_node *a_stack;

	a_stack = a->head;
	if (a->size == 2)
	{
		if(a->head->item > a->head->next->item)
			sa(a);
		return ;
	}
	if(a_stack->item < a_stack->next->item && a_stack->next->item > a_stack->next->next->item && a_stack->next->next->item > a_stack->item)
	{
		sa(a);
		ra(a);
	}
	else if(a_stack->item < a_stack->next->item && a_stack->next->item > a_stack->next->next->item)
		rra(a);
	else if(a_stack->item > a_stack->next->item && a_stack->next->item < a_stack->next->next->item && a_stack->next->next->item > a_stack->item)
		sa(a);
	else if(a_stack->item > a_stack->next->item && a_stack->next->item < a_stack->next->next->item && a_stack->next->next->item < a_stack->item)
		ra(a);
	else if(a_stack->item > a_stack->next->item && a_stack->next->item > a_stack->next->next->item && a_stack->next->next->item < a_stack->item)
	{
		ra(a);
		sa(a);
	}
}

void	sort(t_stack *a)
{
	t_stack	*b;

	if (is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	b = new_stack();
	if (!b)
		return ;
	if (send_from_a_to_b(a, b))
	{
		free_stack(b);
		return ;
	}
	sort_back_to_a(a, b);
	get_the_smallest_to_the_top(a);
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
	sort(a);
	// ft_printf("\n-----\n");
	// print_stack(a);
	free_stack(a);
	return (0);
}
