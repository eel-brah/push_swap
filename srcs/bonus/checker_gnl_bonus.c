/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:24:18 by eel-brah          #+#    #+#             */
/*   Updated: 2023/12/25 14:56:44 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_gnl_find_nl(size_t i, char *buf, int *rt, size_t buf_size)
{
	while (i < (size_t)buf_size && buf[i])
	{
		if (buf[i] == 10)
		{
			*rt = 1;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_gnl_free(char **buf, char *line, char cs)
{
	if (cs == -1)
	{
		free (line);
		free (*buf);
		*buf = NULL;
		return (NULL);
	}
	else
	{
		free (*buf);
		*buf = NULL;
		return (line);
	}
}

char	*ft_gnl_generate_line(char **line, size_t r, size_t i, char **buf)
{
	char	*tmp;
	size_t	len;
	size_t	size;

	len = tt_strlen (*line);
	if (len > SIZE_MAX - (i - r) || (len + i - r) > SIZE_MAX - 1)
		return (ft_gnl_free (line, NULL, -1));
	size = len + i - r + 1;
	tmp = malloc (size * sizeof * tmp);
	if (!tmp)
		return (ft_gnl_free (line, NULL, -1));
	if (*line)
	{
		ft_memcpy(tmp, *line, len);
		tmp[len] = 0;
		free(*line);
	}
	*line = tmp;
	ft_memcpy(*line + len, *buf + r, i - r);
	(*line)[len + i - r] = 0;
	return (tmp);
}

char	*ft_gnl_get_line(t_buffer *buffer, int fd, int rt, size_t buf_size)
{
	size_t			r;
	ssize_t			rd;
	char			*line;

	line = NULL;
	while (!rt)
	{
		r = buffer->i;
		if (!(buffer->i && buffer->i < (size_t)buf_size
				&& buffer->buf[buffer->i]))
		{
			r = 0;
			buffer->i = 0;
			rd = read (fd, buffer->buf, buf_size);
			if (rd == -1 || rd == 0)
				return (ft_gnl_free (&(buffer->buf), line, rd));
			if ((size_t)rd < buf_size)
				buffer->buf[rd] = 0;
		}
		buffer->i = ft_gnl_find_nl (buffer->i, buffer->buf, &rt, buf_size);
		line = ft_gnl_generate_line (&line, r, buffer->i, &(buffer->buf));
		if (!line)
			return (ft_gnl_free(&(buffer->buf), line, -1));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	size_t			buf_size;

	buf_size = 3;
	if (fd < 0 || buf_size <= 0)
		return (NULL);
	if (!buffer.buf)
	{
		buffer.buf = malloc (sizeof(char) * buf_size);
		if (!buffer.buf)
			return (NULL);
	}
	return (ft_gnl_get_line (&buffer, fd, 0, buf_size));
}
