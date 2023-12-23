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
	system("leaks push_swap");
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
		// if (a_stack->item < a_stack->next->item)
		// 	return;
		// else 
		if(a_stack->item > a_stack->next->item)
			sa(a);
		return ;
	}
	// if (a_stack->item < a_stack->next->item && a_stack->next->item < a_stack->next->next->item )
	// 	return;
	// else 
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

int	is_sorted(t_stack *a)
{
	size_t	poz;
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

typedef struct s_sorted
{
	int begin;
	int end;
	int begin_poz;
	int end_poz;
	int size;
} t_sorted;

t_sorted find_the_largest_sorted_area(t_stack *a)
{
	size_t	poz;
	t_node *a_stack;
	t_node *a_stack_ptr;
	t_sorted area_1;
	t_sorted area_2;

	poz = 0;
	a_stack = a->head;
	area_1.begin =0;
	area_1.end = 0;
	area_1.size = 0;
	while(poz < a->size)
	{
		a_stack_ptr = a_stack;
		area_1.begin_poz = poz + 1;
		area_1.end_poz = area_1.begin_poz;
		area_1.begin = a_stack_ptr->item;
		area_1.size = 1;
		while (a_stack_ptr->item < a_stack_ptr->next->item)
		{
			a_stack_ptr = a_stack_ptr->next;
			area_1.end_poz++;
			area_1.size++;
		}
		if (area_1.end_poz >= (int)a->size)
			area_1.end_poz = area_1.end_poz - a->size;
		area_1.end = a_stack_ptr->item;
		if (poz == 0)
			area_2 = area_1;
		else if (area_1.size > area_2.size)
			area_2 = area_1;
		a_stack = a_stack->next;
		poz++;
	}
	return (area_2);
}

int is_area_valid(t_stack *a, t_stack *b, t_sorted area)
{
	int a_instractions_up;
	int a_instractions_down;
	// return 0;
	// return 0;
	if (area.size >= 10)
	{
		if (area.end_poz <= (int)a->size / 2)
		{
			a_instractions_up = area.end_poz;
			if (a_instractions_up < area.size)
			{
				while (a_instractions_up)
				{
					ra(a);
					a_instractions_up--;
				}
			}
			else
				return (0);
		}
		else
		{
			a_instractions_down = a->size - area.end_poz;
			if (a_instractions_down < area.size)
			{
				while (a_instractions_down)
				{
					rra(a);
					a_instractions_down--;
				}
			}
			else
				return (0);
		}
		while (a->size - area.size)
			pb(a, b);
	}
	else
		return (0);
	return (1);
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	t_node *b_stack;
	size_t b_pz;
	size_t poz;
	t_instractions insts;
	size_t a_instractions_up;
	size_t a_instractions_down;
	t_instractions lowest_insts;
	t_instractions tmp_insts;

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
}

int	*sub_sort_3(t_stack *a)
{
	int *array;
	t_node *a_stack;
	int i;

	array = malloc(sizeof(int) * a->size);
	if (!array)
		return (NULL); // free all
	a_stack = a->head;
	i = 0;
	while (i < (int)a->size)
	{
		array[i++] = a_stack->item;
		a_stack = a_stack->next;
	}
	merge_sort(array, a->size, 'k'); // if faild free all
	return (array);
}

int	is_exixt(int a_item, int *array, int end)
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

void push_to_b(t_stack *a, t_stack *b, int poz)
{
	int	r;

	r = 0;
	if (poz <= (int)a->size / 2)
	{
		while (r < poz)
		{
			ra(a);
			r++;
		}
		
	}
	else
	{
		while (r < (int)a->size - poz)
		{
			rra(a);
			r++;
		}
	}
	pb(a, b);
}

void	send_to_b(t_stack *a, t_stack *b, int *array, int size)
{
	int poz;
	int saved_size = size;
	t_node *a_stack;
	int *begin= array;

	a_stack = a->head;
	poz = 0;
	int a_size = a->size;
	array += saved_size;
	int i;
	while ((int)b->size < a_size)
	{
		i = 0;
		while (a_stack && i < saved_size)
		{
			if (a_stack && is_exixt(a_stack->item, array, saved_size))
			{
				push_to_b(a, b, poz);
				a_stack = a->head;
				poz = 0;
				i++;
			}
			else if (a_stack && is_exixt(a_stack->item, begin, saved_size))
			{
				push_to_b(a, b, poz);
				rb(b);
				a_stack = a->head;
				poz = 0;
			}
			else
			{
				a_stack = a_stack->next;
				poz++;
			}
			if (a->size == 3)
				return ;
		}
		size += saved_size;
		array += saved_size;
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

void	sort_3(t_stack *a)
{
	t_stack *b;
	int *array = NULL;
	int size;

	if (is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	// t_sorted area = find_the_largest_sorted_area(a);
	b = new_stack();
	if (!b)
		return ;
	if (a->size >= 60)
	{ 
		array = sub_sort_3(a);
		size = get_size(a->size);
		send_to_b(a, b, array, size);
		sort_three(a);
	}
	else 
	{
		while (a->size - 3)
			pb(a, b);
		sort_three(a);
		if (b->size == 2 && is_sorted(b))
			sb(b);
	}

	// if (!is_area_valid(a, b, area))
	// if(1)
	// {
	// 	while (a->size - 3)
	// 		pb(a, b);
	// 	sort_three(a);
	// 	if (b->size == 2 && is_sorted(b))
	// 		sb(b);
	// }

	sort_back_to_a(a, b);
	get_the_smallest_to_the_top(a);
	free(array);
	free_stack(b);
}

// replace size_t with int
// sort it with merge sort and sent them in chanckes
// check if it sorted and there is a big chanck alredy sorted
// check if it is sorted sfter more then 65% back to a
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
	sort_3(a);
	// ft_printf("\n-----\n");
	// print_stack(a);
	free_stack(a);
	return (0);
}
