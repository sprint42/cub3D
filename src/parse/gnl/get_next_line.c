/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:41:21 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 20:44:55 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	nl_index(const char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

static char	*read_line(char *ptr, int fd)
{
	char	*buf;
	int		r_size;

	buf = (char *)malloc(sizeof(char) * (1024 + 1));
	if (!buf)
		return (NULL);
	r_size = 1;
	while (r_size > 0 && nl_index(ptr, '\n') == -1)
	{
		r_size = read(fd, buf, 1024);
		if (r_size == 0)
			break ;
		if (r_size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[r_size] = '\0';
		ptr = ft_strjoin_sec(ptr, buf);
	}
	free(buf);
	return (ptr);
}

static char	*do_split(char *ptr)
{
	char	*line;
	int		idx;
	int		i;

	idx = 0;
	if (*ptr == '\0')
		return (NULL);
	while (ptr[idx] && ptr[idx] != '\n')
		idx++;
	if (ptr[idx] == '\n')
		idx++;
	line = (char *)malloc((idx + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < idx)
	{
		line[i] = ptr[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*do_move(char *ptr)
{
	char	*str;
	int		idx;
	int		i;

	idx = 0;
	while (ptr[idx] && ptr[idx] != '\n')
		idx++;
	if (ptr[idx] == '\n')
		idx++;
	if (ptr[idx] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(ptr) - idx + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (ptr[idx])
		str[i++] = ptr[idx++];
	str[i] = '\0';
	free(ptr);
	return (str);
}

char	*get_next_line(int fd, char **ret)
{
	static char	*ptr[10240];
	char		*line;

	if (fd < 0)
		return (NULL);
	ptr[fd] = read_line(ptr[fd], fd);
	if (!ptr[fd])
		return (NULL);
	line = do_split(ptr[fd]);
	ptr[fd] = do_move(ptr[fd]);
	*ret = line;
	return (line);
}
