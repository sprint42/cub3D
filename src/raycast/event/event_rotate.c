/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:25:49 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 04:47:29 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	rotate_left(t_map_info *map_info)
{
	double	curr_dir_x;
	double	curr_dir_y;
	double	curr_plane_x;
	double	curr_plane_y;
	
	curr_dir_x = map_info->state.dir_x;
	curr_dir_y = map_info->state.dir_y;
	map_info->state.dir_x = curr_dir_x * cos(THETA) + curr_dir_y * sin(THETA);
	map_info->state.dir_y = curr_dir_y * cos(THETA) - curr_dir_x * sin(THETA);
	curr_plane_x = map_info->state.plane_x;
	curr_plane_y = map_info->state.plane_y;
	map_info->state.plane_x = curr_plane_x * cos(THETA) + curr_plane_y * sin(THETA);
	map_info->state.plane_y = curr_plane_y * cos(THETA) - curr_plane_x * sin(THETA);
}

static void	rotate_right(t_map_info *map_info)
{
	double	curr_dir_x;
	double	curr_dir_y;
	double	curr_plane_x;
	double	curr_plane_y;
	
	curr_dir_x = map_info->state.dir_x;
	curr_dir_y = map_info->state.dir_y;
	map_info->state.dir_x = curr_dir_x * cos(THETA) - curr_dir_y * sin(THETA);
	map_info->state.dir_y = curr_dir_y * cos(THETA) + curr_dir_x * sin(THETA);
	curr_plane_x = map_info->state.plane_x;
	curr_plane_y = map_info->state.plane_y;
	map_info->state.plane_x = curr_plane_x * cos(THETA) - curr_plane_y * sin(THETA);
	map_info->state.plane_y = curr_plane_y * cos(THETA) + curr_plane_x * sin(THETA);
}

void	event_rotate(int key, t_map_info *map_info)
{
	if (key == KEY_LA)
		rotate_left(map_info);
	else
		rotate_right(map_info);
}