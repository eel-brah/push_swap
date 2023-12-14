/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:07 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/14 22:41:56 by eel-brah         ###   ########.fr       */
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
        printf("%i\n", ptr->item);
        ptr = ptr->next;
    } 
	printf("%i\n", ptr->item);
}
#include <string.h>
#include <ctype.h> 

int	strs_size(char **s)
{
	char	**t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	strs_free(char **s)
{
	char	**t;

	t = s;
	while (*t)
		free(*t++);
	free(*t);
	free(s);
}

void fn()
{
	system("leaks a.out");
}

ssize_t	str_to_int(const char *str)
{
	int		sign;
	ssize_t	nb;

	sign = 1;
	nb = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str++ - '0') * sign;
		if ((nb > 0 && nb > ~(1 << 31)) || (nb < 0 && nb < (1 << 31)))
			return ((ssize_t)~(1 << 31) + 1);
	}
	return (nb);
}

int	is_all_digits(char *s)
{
	int	j;

	j = 0;
	if ((s[j] == '-' || s[j] == '+') && s[j + 1])
		j++;
	while(s[j])
	{
		if (!ft_isdigit(s[j]))
			return (0);
		j++;
	}
	return (1);
}

int	is_exist(t_stack *s, int x)
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

int	an_error(char **s, t_stack *a)
{
	strs_free(s);
	free_stack(a);
	printf("ERROR\n");
	return (0);
}

int	push_to_stack_2(t_stack *a, int size, char **s)
{
	ssize_t	nb;

	if (!is_all_digits(s[size - 1]))
		return (an_error(s, a));
	nb = str_to_int(s[size - 1]);
	if (nb > ~(1 << 31))
		return (an_error(s, a));
	if (!is_exist(a, nb))
		return (an_error(s, a));
	push(a, nb);
	return (1);
}

int	push_to_stack(int args, char **argv, t_stack *a)
{
	int size;
	char **s;

	while (args)
	{
		s = ft_split(argv[args], ' ');
		size = strs_size(s);
		if (size < 1)
			return (an_error(s, a));
		while (size)
		{
			if (!push_to_stack_2(a, size, s))
				return (0);
			size--;
		}
		args--;
		strs_free(s);
	}
	return (1);
}

int main(int argc, char **argv)
{   

	atexit(fn);
    t_stack	*a;

	if (argc == 1)
		return (0);
	a = new_stack();
	if (!push_to_stack(argc - 1, argv, a))
		return (1);
	
    // push(a, 4);
	// push(a, 5);
	// push(a, 6);
	// sa(a);
	// rra(a);
	// sb(a);
	// rrb(a);
	print_stack(a);
    
	free_stack(a);
}
