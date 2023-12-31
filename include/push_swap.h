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
	size_t	all;
	size_t	rr;
	size_t	ra;
	size_t	rb;
	size_t	rrr;
	size_t	rra;
	size_t	rrb;
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
int				push_to_stack(int args_nb, char **args, t_stack *a);
int				is_all_digits(char *s);
ssize_t			str_to_int(char *str);
void			strs_free(char **s);
int				strs_size(char **s);
int				*merge_sort(int *ptr, int size);
void			sort(t_stack *a);
void			sort_three(t_stack *a);
int				is_sorted(t_stack *a);
int				send_from_a_to_b(t_stack *a, t_stack *b);
void			send_to_b(t_stack *a, t_stack *b, int *array, int size);
void			get_the_smallest_to_the_top(t_stack *a);
void			sort_back_to_a(t_stack *a, t_stack *b);
void			applay_opperations(t_stack *a,
					t_stack *b, t_instractions insts);
t_instractions	a_up_b_down(int b_instractions, int a_instractions);
t_instractions	a_down_b_up(int b_instractions, int a_instractions);
t_instractions	a_down_b_down(int b_instractions, int a_instractions);
t_instractions	a_up_b_up(int b_instractions, int a_instractions);
int				find_position_3_3(t_stack *a, int b_item);
int				max(int n1, int n2);
int				min(int n1, int n2);
#endif
