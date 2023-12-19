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

int ins_nbr(size_t size, int poz)
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

size_t find_position_3(t_stack *a, int b)
{
	size_t poz;
	t_node *tmp;
	size_t s;

	tmp = a->head;
	poz = 0;
	int x = 0;
	int xx = b - tmp->item;
	if (xx < 0)
		xx *= -1;
	int n = tmp->item;
	s = 0;
	while (poz < a->size)
	{
		x = b - tmp->item;
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
	if (b > n)
		s++;
	return (s);
}


void	sort_3(t_stack *a)
{
	// create stack b and push all - 2 to it
	t_stack *b = new_stack();
	if (!b)
		return ;
	while (a->size - 2)
		pb(a, b);
	size_t poz;
	t_node *b_stack;
	t_instractions insts;
	size_t b_pz;
	size_t a_instractions;
	size_t b_instractions;
	char dirc;
	t_instractions lowest_insts;
	
	size_t half;
	size_t r;
	t_node *tmp;
	size_t s = 0;

	size_t tt;
	// loop in b and push one by one to a
	insts.rr = 0;
	insts.ra = 0;
	insts.rb = 0;
	insts.rrr = 0;
	insts.rra = 0;
	insts.rrb = 0;
	insts.all = 0;
	while (b->size)
	{
		b_stack = b->head;
		b_pz = 0;
		// find the number with min insts to push it from b to a
		while (b_pz < b->size)
		{
			// find the number of insts to push it in a
			poz = find_position_3(a, b_stack->item);
			if (poz <= a->size / 2)
			{
				a_instractions = poz;
				dirc = 'u'; // a is up or down
			}
			else
			{
				a_instractions = a->size - poz;
				dirc = 'd';
			}
			// find the number of insts to pop it from b, the number of all insts, and what insts
			if (b_pz <= b->size / 2) // b up
			{
				if (dirc == 'u') // if a up and b up
				{	
					//printf("aaaaaaaaaaaaaaaaaa\n");
					b_instractions = b_pz;
					insts.rr = min(a_instractions, b_instractions);
					insts.ra = a_instractions - insts.rr;
					insts.rb = b_instractions - insts.rr;
					insts.rrr = 0;
					insts.rra = 0;
					insts.rrb = 0;
					insts.all = max(insts.rb, insts.ra) + insts.rr;
				}
				else // if a down and b up
				{
					if (max(a_instractions, b_pz) - min(a_instractions, b_pz) < b_pz) // best for b to go down
					{
						//printf("bbbbbbbbbbbbbbbbbb\n");

						b_instractions = b->size - b_pz;
						insts.rr = 0;
						insts.ra = 0;
						insts.rb = 0;
						insts.rrr = min(a_instractions, b_instractions);
						insts.rra = a_instractions - insts.rrr;
						insts.rrb = b_instractions - insts.rrr;
						insts.all = max(insts.rrb, insts.rra) + insts.rrr;
					}
					else
					{
						// printf("ccccccccccccccccccc\n");

						b_instractions = b_pz;
						insts.rr = 0;
						insts.ra = 0;
						insts.rb = b_instractions;
						insts.rrr = 0;
						insts.rra = a_instractions;
						insts.rrb = 0;
						insts.all = a_instractions + b_instractions;
					}
				}
			}
			else // b down
			{
				if (dirc == 'u') // if a up and b down
				{
					if (max(a_instractions, b_pz) - min(a_instractions, b_pz) < b_pz) // best for b to go up
					{	
						// printf("dddddddddddddddddd\n");

						b_instractions = b_pz;
						insts.rr = min(a_instractions, b_instractions);
						insts.ra = a_instractions - insts.rr;
						insts.rb = b_instractions - insts.rr;
						insts.rrr = 0;
						insts.rra = 0;
						insts.rrb = 0;
						insts.all = max(insts.rb, insts.ra) + insts.rr;
					}
					else 
					{
						// printf("eeeeeeeeeeeeeeeeeee\n");

						b_instractions = b->size - b_pz;
						insts.rr = 0;
						insts.ra = a_instractions;
						insts.rb = 0;
						insts.rrr = 0;
						insts.rra = 0;
						insts.rrb = b_instractions;
						insts.all = a_instractions + b_instractions;
					}
				}
				else // if a down and b down
				{
						// printf("fffffffffffffffffff\n");

					b_instractions = b->size - b_pz;
					insts.rr = 0;
					insts.ra = 0;
					insts.rb = 0;
					insts.rrr = min(a_instractions, b_instractions);
					insts.rra = a_instractions - insts.rrr;
					insts.rrb = b_instractions - insts.rrr;
					insts.all = max(insts.rrb, insts.rra) + insts.rrr;
				}
			}
			// printf("all: %li\n", insts.all);
			// printf("rr: %li\n", insts.rr);
			// printf("ra: %li\n", insts.ra);
			// printf("rb: %li\n", insts.rb);
			// printf("rrr: %li\n", insts.rrr);
			// printf("rra: %li\n", insts.rra);
			// printf("rrb: %li\n", insts.rrb);
			// printf("\n");
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
		
		// exit(0);
		// applay
	
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
