/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:45 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 15:32:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_texture_null(t_map_info *info, int type)
{
	if (type == EA && info->texture->texture_e)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == WE && info->texture->texture_w)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == SO && info->texture->texture_s)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == NO && info->texture->texture_n)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
}

static void	dup_texture_path(t_map_info *info, char **arr)
{
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
	{
		check_texture_null(info, NO);
		info->texture->texture_n = ft_strdup(arr[1]);
		printf("Bind texture successed. type: %s	path: %s\n", "NO", info->texture->texture_n);
	}
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
	{
		check_texture_null(info, SO);
		info->texture->texture_s = ft_strdup(arr[1]);
		printf("Bind texture successed. type: %s	path: %s\n", "SO", info->texture->texture_s);
	}
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
	{
		check_texture_null(info, EA);
		info->texture->texture_e = ft_strdup(arr[1]);
		printf("Bind texture successed. type: %s	path: %s\n", "EA", info->texture->texture_e);
	}
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
	{
		check_texture_null(info, WE);
		info->texture->texture_w = ft_strdup(arr[1]);
		printf("Bind texture successed. type: %s	path: %s\n", "WE", info->texture->texture_w);
	}
}

void	bind_texture(t_map_info *info, char *buf)
{
	char	**res;

	res = ft_split(buf, ' ');
	dup_texture_path(info, res);
	free_db_arr(res);
}
