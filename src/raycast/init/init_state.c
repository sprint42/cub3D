/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:10:13 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 02:49:59 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_position(t_map_info *map_info, int (*i), int *j)
{
	(*i) = 0;
	while ((*i) < map_info->height)
	{
		(*j) = 0;
		while ((*j) < map_info->width)
		{
			if (map_info->map[(*i)][(*j)] == 'N' || map_info->map[(*i)][(*j)] == 'S' || map_info->map[(*i)][(*j)] == 'W' || map_info->map[(*i)][(*j)] == 'E')
			{
				map_info->state.pos_x = texW * (*j);
				map_info->state.pos_y = texH * (*i);
				return ;
			}
			(*j)++;
		}
		(*i)++;
	}
}

static void	init_dir_vector(t_map_info *map_info, int i, int j)
{
	if (map_info->map[i][j] == 'N')
	{
		map_info->state.dir_x = 0;
		map_info->state.dir_y = -1;
	}
	else if (map_info->map[i][j] == 'S')
	{
		map_info->state.dir_x = 0;
		map_info->state.dir_y = 1;
	}
	else if (map_info->map[i][j] == 'W')
	{
		map_info->state.dir_x = -1;
		map_info->state.dir_y = 0;
	}
	else if (map_info->map[i][j] == 'E')
	{
		map_info->state.dir_x = 1;
		map_info->state.dir_y = 0;
	}
}

static void	init_plane_vector(t_map_info *map_info, int i, int j)
{
	if (map_info->map[i][j] == 'N')
	{
		map_info->state.plane_x = 0.66;
		map_info->state.plane_y = 0;
	}
	else if (map_info->map[i][j] == 'S')
	{
		map_info->state.plane_x = -0.66;
		map_info->state.plane_y = 0;
	}
	else if (map_info->map[i][j] == 'W')
	{
		map_info->state.plane_x = 0;
		map_info->state.plane_y = -0.66;
	}
	else if (map_info->map[i][j] == 'E')
	{
		map_info->state.plane_x = 0;
		map_info->state.plane_y = 0.66;
	}
}

void	init_state(t_map_info *map_info)
{
	int	i;
	int	j;

	init_position(map_info, &i, &j);
	init_dir_vector(map_info, i, j);
	init_plane_vector(map_info, i, j);
}
