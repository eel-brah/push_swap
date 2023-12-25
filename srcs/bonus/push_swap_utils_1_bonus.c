/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:23:25 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 14:23:25 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

ssize_t	str_to_int(char *str)
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
			return ((ssize_t) ~ (1 << 31) + 1);
	}
	return (nb);
}

int	is_all_digits(char *s)
{
	int	j;

	j = 0;
	if ((s[j] == '-' || s[j] == '+') && s[j + 1])
		j++;
	while (s[j])
	{
		if (!ft_isdigit(s[j]))
			return (0);
		j++;
	}
	return (1);
}

size_t	tt_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (ptr && *ptr)
		ptr++;
	return (ptr - s);
}
