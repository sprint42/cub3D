/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:25:49 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 13:45:07 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	rotate_left(t_map_info *map_info)
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

void	rotate_right(t_map_info *map_info)
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
