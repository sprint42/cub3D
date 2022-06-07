/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_after.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:34:55 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 22:41:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	judge_valid_space(t_map_info *info, int r, int c)
{
	if (r > 0 && (info->map[r - 1][c] != ' ' && info->map[r - 1][c] != '1'))
	{
		error_print(ERROR_INVALID_MAP_CHAR);
		exit(EXIT_FAILURE);
	}
	if (r < info->r - 1 && (info->map[r + 1][c] != ' ' && \
	info->map[r + 1][c] != '1'))
	{
		error_print(ERROR_INVALID_MAP_CHAR);
		exit(EXIT_FAILURE);
	}
	if (c > 0 && (info->map[r][c - 1] != ' ' && info->map[r][c - 1] != '1'))
	{
		error_print(ERROR_INVALID_MAP_CHAR);
		exit(EXIT_FAILURE);
	}
	if (c < info->c - 1 && (info->map[r][c + 1] != ' ' && \
	info->map[r][c + 1] != '1'))
	{
		error_print(ERROR_INVALID_MAP_CHAR);
		exit(EXIT_FAILURE);
	}
}

void	check_map_inner(t_map_info *info)
{
	char	**arr;
	int		r;
	int		c;

	r = 0;
	arr = info->map;
	while (r < info->r)
	{
		c = 0;
		while (c < info->c)
		{
			if (arr[r][c] == ' ')
				judge_valid_space(info, r, c);
			c++;
		}
		r++;
	}
}

static void	check_outer(t_map_info *info, int type, int r)
{
	int	c;

	c = 0;
	if (type == UD)
	{
		while (c < info->c)
		{
			if (info->map[r][c] != ' ' && info->map[r][c] != '1')
			{
				error_print(ERROR_INVALID_MAP_CHAR);
				exit(EXIT_FAILURE);
			}
			c++;
		}
	}
	else if (type == LR)
	{
		if ((info->map[r][0] != ' ' && info->map[r][0] != '1') || \
			(info->map[r][info->c - 1] != ' ' && \
			info->map[r][info->c - 1] != '1'))
		{
			error_print(ERROR_INVALID_MAP_CHAR);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_map_outer(t_map_info *info)
{
	int	r;

	r = 0;
	while (r < info->r)
	{
		if (r == 0 || r == info->r - 1)
			check_outer(info, UD, r);
		else
			check_outer(info, LR, r);
		r++;
	}
}

void	check_map_valid_after(t_map_info *info)
{
	check_map_outer(info);
	check_map_inner(info);
}
