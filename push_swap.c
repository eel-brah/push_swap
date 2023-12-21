/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:07 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/20 06:29:27 by eel-brah         ###   ########.fr       */
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
	size_t poz;
	size_t half;
	size_t r;
	t_node *tmp;

	while (a->size - 1)
		pb(a, b);
	while (b->size)
	{
		if (a->head->item > b->head->item)
		{
			pa(b, a);
		}
		else 
		{
			
			tmp = a->head;
			poz = 0;
			while (tmp->item < b->head->item && poz < a->size)
			{
				tmp = tmp->next;
				poz++;
			}

			if (poz == 1)
			{
				pa(b, a);
				sa(a);
			}
			else if (poz == a->size)
			{
				pa(b, a);
				ra(a);
			}
			else
			{
				half = a->size / 2;
				if (poz <= half)
				{
					r = 0;
					while (r < poz - 1)
					{
						ra(a);
						r++;
					}
					pa(b, a);
					sa(a);
					r = 0;
					while (r < poz - 1)
					{
						rra(a);
						r++;
					}
				}
				else
				{
					r = 0;
					while (r < a->size +  - poz)
					{
						rra(a);
						r++;
					}
					pa(b, a);
					r = 0;
					while (r < a->size - poz)
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

size_t find_position(t_stack *a, t_stack *b)
{
	size_t poz;
	t_node *tmp;
	size_t s;

	tmp = a->head;
	poz = 0;
	int x = 0;
	int xx = b->head->item - tmp->item;
	if (xx < 0)
		xx *= -1;
	int n = tmp->item;
	s = 0;
	while (poz < a->size)
	{
		x = b->head->item - tmp->item;
		if (x < 0)
			x *= -1;
		if (x < xx)
		{
			xx = x;
			s = poz;
			n = tmp->item;
		}
		tmp = tmp->next;
		poz++;
	}
	if (b->head->item > n)
		s++;
	return (s);
}

void	sort_2(t_stack *a)
{
	t_stack *b = new_stack();
	if (!b)
		return ;
	size_t poz;
	size_t half;
	size_t r;
	t_node *tmp;
	size_t s = 0;

	while (a->size - 2)
		pb(a, b);
	while (b->size)
	{
		poz = find_position(a, b);
		half = a->size / 2;
		if (poz <= half)
		{
			r = 0;
			while (r < poz)
			{
				ra(a);
				r++;
			}
			pa(b, a);
		}
		else
		{
			r = 0;
			while (r < a->size - poz)
			{
				rra(a);
				r++;
			}
			pa(b, a);
		}
	}
	// return ;
	poz = 0;
	tmp = a->head;
	int min = tmp->item;
	s = 0;
	
	while (poz < a->size)
	{
		if (min > tmp->item)
		{
			min = tmp->item;
			s = poz;
		}
		tmp = tmp->next;
		poz++;
	}
	poz = s;
	// printf("%li-------", s);
	// return ;
	half = a->size / 2;
	if (poz <= half)
	{
		r = 0;
		while (r < poz)
		{
			ra(a);
			r++;
		}
	}
	else
	{
		r = 0;
		while (r < a->size - poz)
		{
			rra(a);
			r++;
		}
	}
	free_stack(b);
}

int ins_nbr(size_t size, size_t poz)
{
	size_t half = size / 2;
	if (poz <= half)
		return poz;
	else
		return size - poz;
}

typedef struct s_instractions // check norms name
{
	size_t all;
	size_t rr;
	size_t ra;
	size_t rb;
	size_t rrr;
	size_t rra;
	size_t rrb;
	// char a_drc;
	// char b_drc;
} t_instractions;

size_t min(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

size_t max(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

size_t find_position_3(t_stack *a, int b_item)
{
	size_t poz;
	t_node *a_stack;
	size_t b_poz;
	int sub;
	int sub_2;
	int item;

	a_stack = a->head;
	sub_2 = b_item - a_stack->item;
	if (sub_2 < 0)
		sub_2 *= -1;
	item = a_stack->item;
	b_poz = 0;
	poz = 1;
	a_stack = a_stack->next;
	while (poz < a->size)
	{
		sub = b_item - a_stack->item;
		if (sub < 0)
			sub *= -1;
		if (sub < sub_2)
		{
			sub_2 = sub;
			b_poz = poz;
			item = a_stack->item;
		}
		a_stack = a_stack->next;
		poz++;
	}
	if (b_item > item)
		b_poz++;
	return (b_poz);
}

int highest(t_stack *a)
{
	int h;
	t_node *a_stack;
	size_t poz;

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
	size_t poz;

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

size_t where_is_it(t_stack *a, int nb)
{
	t_node *a_stack;
	size_t poz;

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

size_t find_position_3_3(t_stack *a, int b_item)
{
	t_node *a_stack;
	size_t poz;
	int h;
	int l;

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

size_t	calc_instactions(t_stack *a, int b_item, char *dirc)
{
	size_t poz;
	
	poz = find_position_3_3(a, b_item);
	if (poz <= a->size / 2)
	{
		*dirc = 'u'; // a is up or down
		return poz;
	}
	else
	{
		*dirc = 'd';
		return a->size - poz;
	}
}

t_instractions a_up_b_up(size_t b_instractions, size_t a_instractions)
{
	t_instractions insts;

	insts.rr = min(a_instractions, b_instractions);
	insts.ra = a_instractions - insts.rr;
	insts.rb = b_instractions - insts.rr;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = 0;
	insts.all = max(a_instractions, b_instractions);
	// insts.all = insts.rr + insts.ra + insts.rb;
	return (insts);
}

t_instractions a_down_b_down(size_t b_instractions, size_t a_instractions)
{
	t_instractions insts;

	insts.rr = 0;
	insts.ra = 0;
	insts.rb = 0;
	insts.rrr = min(a_instractions, b_instractions);
	insts.rra = a_instractions - insts.rrr;
	insts.rrb = b_instractions - insts.rrr;
	insts.all = max(a_instractions, b_instractions);
	// insts.all = insts.rrr + insts.rra + insts.rrb;
	return (insts);
}


t_instractions a_down_b_up(size_t b_instractions, size_t a_instractions)
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

t_instractions a_up_b_down(size_t b_instractions, size_t a_instractions)
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

void applay_opperations(t_stack *a, t_stack *b, t_instractions lowest_insts)
{
	while (lowest_insts.rr)
	{
		rr(a, b);
		lowest_insts.rr--;
	}
	while (lowest_insts.ra)
	{
		ra(a);
		lowest_insts.ra--;
	}
	while (lowest_insts.rb)
	{
		rb(b);
		lowest_insts.rb--;
	}
	while (lowest_insts.rrr)
	{
		rrr(a, b);
		lowest_insts.rrr--;
	}
	while (lowest_insts.rra)
	{
		rra(a);
		lowest_insts.rra--;
	}
	while (lowest_insts.rrb)
	{
		rrb(b);
		lowest_insts.rrb--;
	}
	pa(b, a);
}

void sort_three(t_stack *a)
{
	t_node *a_stack;

	a_stack = a->head;
	if (a->size < 1)
		return ;
	if (a->size == 2)
	{
		if (a_stack->item < a_stack->next->item)
			return;
		else if(a_stack->item > a_stack->next->item)
			sa(a);
		return ;
	}
	if (a_stack->item < a_stack->next->item && a_stack->next->item < a_stack->next->next->item )
		return;
	else if(a_stack->item < a_stack->next->item && a_stack->next->item > a_stack->next->next->item && a_stack->next->next->item > a_stack->item)
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

void get_the_smallest_to_the_top(t_stack *a)
{
	size_t poz;
	size_t r;

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

void	sort_3(t_stack *a)
{
	t_stack *b;
	t_node *b_stack;
	size_t b_pz;
	size_t poz;
	t_instractions insts;
	size_t a_instractions_up;
	size_t a_instractions_down;
	t_instractions lowest_insts;
	t_instractions tmp_insts;

	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	b = new_stack();
	if (!b)
		return ;
	while (a->size - 3)
		pb(a, b);
	sort_three(a);
	while (b->size)
	{
		b_stack = b->head;
		b_pz = 0;
		while (b_pz < b->size)
		{
			poz = find_position_3_3(a, b_stack->item);
			a_instractions_up = poz;
			a_instractions_down = a->size - poz;
			if (b_pz <= b->size / 2) // b up
			{
				insts = a_up_b_up(b_pz, a_instractions_up);
				tmp_insts = a_down_b_up(b_pz, a_instractions_down);
				if (tmp_insts.all < insts.all)
					insts = tmp_insts;
				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
				if (tmp_insts.all < insts.all)
					insts = tmp_insts;
				// tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
				// if (tmp_insts.all < insts.all)
				// 	insts = tmp_insts;
			}
			else // b down
			{
				insts = a_up_b_up(b_pz, a_instractions_up);
				tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
				if (tmp_insts.all < insts.all)
					insts = tmp_insts;
				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
				if (tmp_insts.all < insts.all)
					insts = tmp_insts;
				// tmp_insts = a_down_b_up(b_pz, a_instractions_down);
				// if (tmp_insts.all < insts.all)
				// 	insts = tmp_insts;
			}
			if (b_pz == 0)
				lowest_insts = insts;
			else
			{
				if (insts.all < lowest_insts.all)
					lowest_insts = insts;
			}
			b_stack = b_stack->next;
			b_pz++;
		}
		applay_opperations(a, b, lowest_insts);
	}
	get_the_smallest_to_the_top(a);
	free_stack(b);
}

void	sort_3_old(t_stack *a)
{
	t_node *b_stack;
	size_t b_pz;
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	// create stack b and push all - 2 to it
	t_stack *b = new_stack();
	if (!b)
		return ;
	while (a->size - 3)
		pb(a, b);
	t_instractions insts;
	size_t a_instractions;
	char dirc;
	t_instractions lowest_insts;
	t_instractions tmp_insts;
	sort_three(a);
	// loop in b and push one by one to a
	while (b->size)
	{
		b_stack = b->head;
		b_pz = 0;
		// find the number with min insts to push it from b to a
		while (b_pz < b->size)
		{
			// find the number of insts to push it in a
			a_instractions = calc_instactions(a, b_stack->item, &dirc);
			// find the number of insts to pop it from b, the number of all insts, and what insts
			if (b_pz <= b->size / 2) // b up
			{
				if (dirc == 'u') // if a up and b up
					insts = a_up_b_up(b_pz, a_instractions);
				else // if a down and b up
				{
					insts = a_down_b_down(b->size - b_pz, a_instractions);
					tmp_insts = a_down_b_up(b_pz, a_instractions);
					if (tmp_insts.all < insts.all)
						insts = tmp_insts;
				}
			}
			else // b down
			{
				if (dirc == 'u') // if a up and b down
				{
					insts = a_up_b_up(b_pz, a_instractions);
					tmp_insts = a_up_b_down(b->size - b_pz, a_instractions);
					if (tmp_insts.all < insts.all)
						insts = tmp_insts;
				}
				else // if a down and b down
					insts = a_down_b_down(b->size - b_pz, a_instractions);
			}
			if (b_pz == 0)
				lowest_insts = insts;
			else
			{
				if (insts.all < lowest_insts.all)
					lowest_insts = insts;
			}
			b_stack = b_stack->next;
			b_pz++;
		}
		applay_opperations(a, b, lowest_insts);
	}
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
	// sort_10(a);
	// sort_10(a);
	sort_3(a);
	// ft_printf("\n-----\n");
	// print_stack(a);
	free_stack(a);
	return (0);
}
