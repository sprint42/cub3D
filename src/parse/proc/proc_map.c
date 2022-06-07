/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:52:29 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 17:53:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	is_empty_before_map(t_map_info *info)
{
	if ((info->flag & COMP_BIND_DONE) && \
		(info->flag & START_MAP_PARSE) && \
		!(info->flag & END_MAP_PARSE))
		info->flag |= END_MAP_PARSE;
	else if ((info->flag & COMP_BIND_DONE) && !(info->flag & START_MAP_PARSE))
		info->flag |= CHECK_BEFORE_MAP;
}

static void	judge(t_map_info *info, char *buf)
{
	char	*tmp;

	tmp = ft_strtrim(buf, info->wspace);
	if (ft_strlen(tmp) != 0)
	{
		if (info->flag & COMP_BIND_DONE)
		{
			if (!(info->flag & CHECK_BEFORE_MAP))
			{
				error_print(ERROR_EMPTY_N_OCCURED);
				exit(EXIT_FAILURE);
			}
			proc_meaningful(info, buf);
		}
		else
			proc_meaningful(info, tmp);
	}
	else
		is_empty_before_map(info);
	free(tmp);
}

/*
**	Garbage function
*/
static void	print_map(t_map_info *info)
{
	char	**ptr;

	ptr = info->map;
	printf("\n	<< Map start >>\n");
	while (*ptr)
	{
		printf("%s\n", *ptr);
		ptr++;
	}
	printf("	<< Map end >>\n");
}

static void	read_file(t_map_info *info, int fd)
{
	char	*buf;

	while (get_next_line(fd, &buf) > 0)
	{
		judge(info, buf);
		if (check_component_all_bind(info))
			info->flag |= COMP_BIND_DONE;
		free(buf);
	}
	print_map(info);
	close(fd);
	check_map_valid(info);
}

/*
**	Entrance after pass first exception check
*/

void	proc_map(t_map_info *info, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0644);
	read_file(info, fd);
	check_texture_and_color(info);
}
