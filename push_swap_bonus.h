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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int	size;
}   t_stack;


typedef struct s_instractions // check norms name
{
	int	all;
	int	rr;
	int	ra;
	int	rb;
	int	rrr;
	int	rra;
	int	rrb;
}	t_instractions;

t_stack	*new_stack(void);
t_node	*new_node(int x);
void	free_stack(t_stack *a);
t_stack	*push(t_stack *a, int x);
t_node	*pop(t_stack *a);
t_stack	*insert(t_stack *s, t_node *node);
void	swap(t_stack *a);
void	push_fr_to(t_stack *from, t_stack *to);
void rotate(t_stack *s);
void rev_rotate(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int	is_exist(t_stack *s, int x);
int	an_error(char **s, t_stack *a);
int	push_to_stack_2(t_stack *a, char*s);
int	push_to_stack(int args_nb, char **args, t_stack *a);
int	is_all_digits(char *s);
ssize_t	str_to_int(char *str);
void	strs_free(char **s);
int	strs_size(char **s);


int	sorted(t_stack *a);

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_buffer
{
	char	*buf;
	size_t	i;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_gnl_get_line(t_buffer *buffer, int fd, int rt, size_t buf_size);
char	*ft_gnl_generate_line(char **line, size_t r, size_t i, char **buf);
char	*ft_gnl_free(char **buf, char *line, char cs);
size_t	ft_gnl_find_nl(size_t i, char *buf, int *rt, size_t buf_size);
size_t	tt_strlen(const char *s);


#endif