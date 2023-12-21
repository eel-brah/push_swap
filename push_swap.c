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

	if (is_sorted(a))
		return ;
	t_sorted area = find_the_largest_sorted_area(a);
	printf("%i\n", area.begin);
	printf("%i\n", area.end);
	printf("%i\n", area.begin_poz);
	printf("%i\n", area.end_poz);
	printf("%i\n", area.size);
	return ;
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
	if (b->size == 2 && is_sorted(b))
		sb(b);
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

// t_instractions inhansed_a_down_b_up(t_stack *a, t_stack *b, size_t b_pz, size_t a_instractions_down)
// // t_instractions inhansed_a_down_b_up(t_stack *b, size_t b_pz)
// {
// 	int *a_array;
// 	int *b_array_1;
// 	int b_item;
// 	int a_item;
// 	int *b_array_2;

// 	size_t poz;
// 	t_node *b_stack;
// 	t_node *a_stack;

// 	b_array_1 = malloc(sizeof(int) * (b->size - 1));
// 	b_array_2 = malloc(sizeof(int) * (b->size - 1));
// 	a_array = malloc(sizeof(int) * (a->size + 1));

// 	poz = 0;
// 	b_stack = b->head;
// 	while (poz < b_pz)
// 	{
// 		if (poz == b_pz-1)
// 			b_item = b_stack->item;
// 		b_stack = b_stack->next;
// 		poz++;
// 	}
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		if (b_item == b_stack->item)
// 			b_stack = b_stack->next;;
// 		b_array_1[poz] = b_stack->item; 
// 		poz++;
// 		b_stack = b_stack->next;
// 	}
// 	print_stack(b);
// 	printf("\n%li\n\n", b_pz);
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		ft_printf("%i ", b_array_1[poz]);
// 		poz++;
// 	}

// 	poz = 0;
// 	b_stack = b->head;
// 	while (poz < b_pz - 2)
// 	{
// 		b_stack = b_stack->next;
// 		poz++;
// 	}
// 	b_item = b_stack->next->item;
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		if (b_item == b_stack->item)
// 			b_stack = b_stack->next;;
// 		b_array_2[poz] = b_stack->item; 
// 		poz++;
// 		b_stack = b_stack->next;
// 	}
// 	printf("\n");
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		ft_printf("%i ", b_array_2[poz]);
// 		poz++;
// 	}

// 	a_array[0] = b_item;
// 	poz = 0;
// 	a_stack = a->head;
// 	while (poz < a_instractions_down)
// 	{
// 		if (poz == a_instractions_down - 1)
// 			a_item = a_stack->item;
// 		a_stack = a_stack->next;
// 		poz++;
// 	}
// 	poz = 1;
// 	while (poz < a->size + 1)
// 	{
// 		if (b_item == a_stack->item)
// 			a_item = a_stack->item;
// 		a_array[poz] = a_stack->item; 
// 		poz++;
// 		a_stack = a_stack->next;
// 	}
// 	printf("\n");
// 	print_stack(a);
// 	printf("\n%li\n\n", a_instractions_down);
// 	poz = 0;
// 	while (poz < a->size + 1)
// 	{
// 		ft_printf("%i ", a_array[poz]);
// 		poz++;
// 	}
// 	free(a_array);
// 	free(b_array_1);
// 	free(b_array_2);
// 	t_instractions t;
// 	t.all = 9;
// 	return (t);
// }

// void	sort_3_2(t_stack *a)
// {
// 	t_stack *b;
// 	t_node *b_stack;
// 	size_t b_pz;
// 	size_t poz;
// 	t_instractions insts;
// 	size_t a_instractions_up;
// 	size_t a_instractions_down;
// 	t_instractions lowest_insts;
// 	t_instractions tmp_insts;

// 	if (is_sorted(a))
// 		return ;
// 	if (a->size <= 3)
// 	{
// 		sort_three(a);
// 		return ;
// 	}
// 	b = new_stack();
// 	if (!b)
// 		return ;
// 	while (a->size - 5)
// 		pb(a, b);
// 	sort_three(a);
// 	if (b->size == 2 && is_sorted(b))
// 		sb(b);
// 	while (b->size)
// 	{
// 		b_stack = b->head;
// 		b_pz = 0;
// 		while (b_pz < b->size)
// 		{
// 			poz = find_position_3_3(a, b_stack->item);
// 			a_instractions_up = poz;
// 			a_instractions_down = a->size - poz;
// 			if (b_pz <= b->size / 2) // b up
// 			{
// 				insts = a_up_b_up(b_pz, a_instractions_up);
// 				tmp_insts = a_down_b_up(b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				// if poz+1 != 1 and only if b up
// 				tmp_insts = inhansed_a_down_b_up(a, b, 4, 5);
// 				// tmp_insts = inhansed_a_down_b_up(b, 3);
// 				return ;
// 				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
// 				// if (tmp_insts.all < insts.all)
// 				// 	insts = tmp_insts;
// 			}
// 			else // b down
// 			{
// 				insts = a_up_b_up(b_pz, a_instractions_up);
// 				tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				// tmp_insts = a_down_b_up(b_pz, a_instractions_down);
// 				// if (tmp_insts.all < insts.all)
// 				// 	insts = tmp_insts;
// 			}
// 			if (b_pz == 0)
// 				lowest_insts = insts;
// 			else
// 			{
// 				if (insts.all < lowest_insts.all)
// 					lowest_insts = insts;
// 			}
// 			b_stack = b_stack->next;
// 			b_pz++;
// 		}
// 		applay_opperations(a, b, lowest_insts);
// 	}
// 	get_the_smallest_to_the_top(a);
// 	free_stack(b);
// }


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
