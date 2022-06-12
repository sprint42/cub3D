/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:10:13 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 00:10:14 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_window(t_map_info *map_info)
{
	map_info->win_ptr = mlx_new_window(map_info->mlx_ptr, winW, winH, "cub3D");
	if (map_info->win_ptr == 0)
	{
		printf("Error\nmessage: window initialize failed\n");
		exit(EXIT_FAILURE);
	}
	map_info->state.img_buf.ptr = mlx_new_image(map_info->mlx_ptr, winW, winH);
	if (map_info->state.img_buf.ptr)
	{
		printf("Error\nmessage: image buffer initialize failed\n");
		exit(EXIT_FAILURE);
	}
	map_info->state.img_buf.addr = mlx_get_data_addr(map_info->state.img_buf.ptr, &(map_info->state.img_buf.bpp), \
									&(map_info->state.img_buf.size_line), &(map_info->state.img_buf.endian));
}

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
				break ;
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

	init_window(map_info);
	init_position(map_info, &i, &j);
	init_dir_vector(map_info, i, j);
	init_plane_vector(map_info, i, j);
}
