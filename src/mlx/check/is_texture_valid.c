/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:45:29 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:21:56 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static void	is_xpm_file(char *filename)
{
	char	*tmp;

	tmp = filename;
	if (tmp && ft_strlen(tmp) < 4)
	{
		error_print(ERROR_XPM);
		exit(EXIT_FAILURE);
	}
	while (*tmp)
		tmp++;
	tmp -= 4;
	if (tmp && ft_strncmp(tmp, ".xpm", 4))
	{
		error_print(ERROR_XPM);
		exit(EXIT_FAILURE);
	}
}

static void	is_file_exist(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
	{
		close(fd);
		error_print(ERROR_FILE_NOT_EXIST);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	check_cardinal_points(t_map_info **info)
{
	is_xpm_file((*info)->path->path_e);
	is_xpm_file((*info)->path->path_w);
	is_xpm_file((*info)->path->path_s);
	is_xpm_file((*info)->path->path_n);
}

static void	check_is_file_exist(t_map_info **info)
{
	is_file_exist((*info)->path->path_e);
	is_file_exist((*info)->path->path_w);
	is_file_exist((*info)->path->path_s);
	is_file_exist((*info)->path->path_n);
}

void	is_texture_valid(t_map_info **info)
{
	check_cardinal_points(info);
	check_is_file_exist(info);
}
