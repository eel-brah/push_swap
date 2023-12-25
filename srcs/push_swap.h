/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:32:38 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/19 22:59:04 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

typedef struct s_ary
{
	int	*p;
	int	size;
}	t_ary;

typedef struct s_instractions
{
	int	all;
	int	rr;
	int	ra;
	int	rb;
	int	rrr;
	int	rra;
	int	rrb;
}	t_instractions;

t_stack			*new_stack(void);
t_node			*new_node(int x);
void			free_stack(t_stack *a);
t_stack			*push(t_stack *a, int x);
t_node			*pop(t_stack *a);
t_stack			*insert(t_stack *s, t_node *node);
void			swap(t_stack *a);
void			push_fr_to(t_stack *from, t_stack *to);
void			rotate(t_stack *s);
void			rev_rotate(t_stack *s);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *b, t_stack *a);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				is_exist(t_stack *s, int x);
int				an_error(char **s, t_stack *a);
int				push_to_stack_2(t_stack *a, char*s);
int				push_to_stack(int args_nb, char **args, t_stack *a);
int				is_all_digits(char *s);
ssize_t			str_to_int(char *str);
void			strs_free(char **s);
int				strs_size(char **s);
int				*merge_sort(int *ptr, int size);
void			merge(int *tmp_array, int *ptr, int size);
int				*combine(t_ary *p1, t_ary *p2, int size);
void			rem_2(int *tmp_array, int k, t_ary *p1, int r);
void			rem_1(int *tmp_array, int k, t_ary *p2, int r);
void			sort(t_stack *a);
void			sort_three(t_stack *a);
int				is_sorted(t_stack *a);
int				send_from_a_to_b(t_stack *a, t_stack *b);
int				*sub_sort(t_stack *a);
int				get_size(int a_size);
void			send_to_b(t_stack *a, t_stack *b, int *array, int size);
t_node			*send_2(t_stack *a, t_stack *b, int *poz);
t_node			*send_1(t_stack *a, t_stack *b, int *poz, int *i);
void			push_to_b(t_stack *a, t_stack *b, int poz);
int				is_exist_2(int a_item, int *array, int end);
void			get_the_smallest_to_the_top(t_stack *a);
void			sort_back_to_a(t_stack *a, t_stack *b);
t_instractions	calc_instactions_0(t_stack *a, int b_size,
					int b_pz, t_node *b_stack);
t_instractions	calc_instactions_2(int b_down, int b_up,
					int a_up, int a_down);
t_instractions	calc_instactions_1(int b_down, int b_up, int a_up, int a_down);
void			applay_opperations(t_stack *a, t_stack *b,
					t_instractions insts);
void			down_opperations(t_stack *a, t_stack *b, t_instractions insts);
void			up_opperations(t_stack *a, t_stack *b, t_instractions insts);
t_instractions	a_up_b_down(int b_instractions, int a_instractions);
t_instractions	a_down_b_up(int b_instractions, int a_instractions);
t_instractions	a_down_b_down(int b_instractions, int a_instractions);
t_instractions	a_up_b_up(int b_instractions, int a_instractions);
int				find_position_3_3(t_stack *a, int b_item);
int				where_is_it(t_stack *a, int nb);
int				lowest(t_stack *a);
int				highest(t_stack *a);
int				max(int n1, int n2);
int				min(int n1, int n2);
#endif