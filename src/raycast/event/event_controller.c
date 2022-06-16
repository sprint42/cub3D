/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:44:20 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/16 02:00:19 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	event_move(int key, t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	
	state = map_info->state;
	dx = state.dir_x / sqrtf(powf(map_info->state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_y / sqrtf(powf(map_info->state.dir_x, 2) + powf(state.dir_y, 2));
	if (key == KEY_W)
		move_to_north(map_info, dx, dy);
	else if (key == KEY_S)
		move_to_south(map_info, -dx, -dy);
	else if (key == KEY_A)
		move_to_west(map_info, dy, -dx);
	else
		move_to_east(map_info, -dy, dx);
}

void	event_rotate(int key, t_map_info *map_info)
{
	if (key == KEY_LA)
		rotate_left(map_info);
	else
		rotate_right(map_info);
}
