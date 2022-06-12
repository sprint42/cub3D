/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:45 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:21:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_texture_null(t_map_info **info, int type)
{
	if (type == EA && (*info)->path->path_e)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == WE && (*info)->path->path_w)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == SO && (*info)->path->path_s)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == NO && (*info)->path->path_n)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
}

static void	dup_texture_path(t_map_info **info, char **arr)
{
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
	{
		check_texture_null(info, NO);
		(*info)->path->path_n = ft_strdup(arr[1]);
	}
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
	{
		check_texture_null(info, SO);
		(*info)->path->path_s = ft_strdup(arr[1]);
	}
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
	{
		check_texture_null(info, EA);
		(*info)->path->path_e = ft_strdup(arr[1]);
	}
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
	{
		check_texture_null(info, WE);
		(*info)->path->path_w = ft_strdup(arr[1]);
	}
}

void	bind_texture(t_map_info **info, char *buf)
{
	char	**res;

	res = ft_split(buf, ' ');
	dup_texture_path(info, res);
	free_db_arr(res);
}
