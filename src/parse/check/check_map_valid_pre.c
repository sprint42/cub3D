/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_pre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:55 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 18:05:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_valid_character(t_map_info **info, char c)
{
	char	*set;
	int		flag;

	set = (*info)->valid;
	flag = 0;
	while (*set)
	{
		if (*set == c)
			flag = 1;
		set++;
	}
	return (flag);
}

static int	is_valid_string(t_map_info **info, char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (!is_valid_character(info, *tmp))
			return (0);
		tmp++;
	}
	return (1);
}

static void	check_valid_character(t_map_info **info)
{
	char	**ptr;

	ptr = (*info)->map;
	while (*ptr)
	{
		if (!is_valid_string(info, *ptr))
		{
			error_print(ERROR_INVALID_MAP_CHAR);
			exit(EXIT_FAILURE);
		}
		ptr++;
	}
}

static void	check_map_exist(t_map_info **info)
{
	if (!((*info)->map))
	{
		error_print(ERROR_MAP_NOT_EXIST);
		exit(EXIT_FAILURE);
	}
}

void	check_map_valid_pre(t_map_info **info)
{
	check_map_exist(info);
	check_valid_character(info);
	check_player_spawn_cnt(info);
}
