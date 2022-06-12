/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:15:50 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 06:13:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	move_to_north(t_map_info *map_info)
{
	t_state	state;
	double dx;
	double dy;

	state = map_info->state;
	dx = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (map_info->map[(int)map_info->state.pos_y][(int)map_info->state.pos_x] != '0' || \
		map_info->map[(int)(map_info->state.pos_y - 0.5)][(int)map_info->state.pos_x] != '0')
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

static void	move_to_south(t_map_info *map_info)
{
	t_state	state;
	double dx;
	double dy;

	state = map_info->state;
	dx = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x -= dx * SPEED;
	map_info->state.pos_y -= dy * SPEED;
	if (map_info->map[(int)map_info->state.pos_y][(int)map_info->state.pos_x] != '0')
	{
		map_info->state.pos_x += dx * SPEED;
		map_info->state.pos_y += dy * SPEED;
	}
}

static void	move_to_west(t_map_info *map_info)
{
	t_state	state;
	double dx;
	double dy;

	state = map_info->state;
	dx = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = -state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (map_info->map[(int)map_info->state.pos_y][(int)map_info->state.pos_x] != '0' || \
		map_info->map[(int)map_info->state.pos_y][(int)(map_info->state.pos_x - 0.5)] != '0' )
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

static void	move_to_east(t_map_info *map_info)
{
	t_state	state;
	double dx;
	double dy;

	state = map_info->state;
	dx = -state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (map_info->map[(int)map_info->state.pos_y][(int)map_info->state.pos_x] != '0')
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

void	event_move(int key, t_map_info *map_info)
{
	if (key == KEY_W)
		move_to_north(map_info);
	else if (key == KEY_S)
		move_to_south(map_info);
	else if(key == KEY_A)
		move_to_west(map_info);
	else
		move_to_east(map_info);
}