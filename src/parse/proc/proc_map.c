/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:52:29 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 16:27:08 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	judge(t_map_info *info, char *buf)
{
	char	*tmp;

	tmp = ft_strtrim(buf, info->wspace);
	if (ft_strlen(tmp) == 0)
		;
	else
		proc_meaningful(info, buf);
	free(tmp);
}

static void	read_file(t_map_info *info, int fd)
{
	char	*buf;

	while (get_next_line(fd, &buf) > 0)
	{
		judge(info, buf);
		free(buf);
	}
	close(fd);
}

/*
**	Entrance after pass first exception check
*/

void	proc_map(t_map_info *info, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0644);
	read_file(info, fd);
	printf("\n");
	check_texture_and_color(info);
}
