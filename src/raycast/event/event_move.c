/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:15:50 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 22:36:52 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	check_pos_range(t_map_info *map_info, double dx, double dy)
{
	double	diff_x;
	double	diff_y;
	int		map_x;
	int		map_y;

	map_x = (int)map_info->state.pos_x;
	map_y = (int)map_info->state.pos_y;
	diff_x = map_info->state.pos_x - map_x;
	diff_y = map_info->state.pos_y - map_y;
	if (diff_x == 0)
	{
		if (dx 
		if (diff_x == 0 && dx <= 0)
		map_x--;
		if (diff_y == 0 && dy <= 0)
		map_y--;	
	}
	if (map_info->map[map_y][map_x] != '0')
		return (0);
	return (1);
	// if (map_info->state.pos_x < 0)
	// 	map_info->state.pos_x = 0;
	// if (map_info->state.pos_y < 0)
	// 	map_info->state.pos_y = 0;
	// if (map_info->state.pos_x >= map_info->width)
	// 	map_info->state.pos_x = map_info->width - 1;
	// if (map_info->state.pos_y >= map_info->height)
	// 	map_info->state.pos_y = map_info->height - 1;
	
}

void	move_to_north(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	origin_x;
	double	origin_y;

	state = map_info->state;
	dx = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (!check_pos_range(map_info, dx, dy))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}

void	move_to_south(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	origin_x;
	double	origin_y;

	state = map_info->state;
	dx = -state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = -state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (!check_pos_range(map_info, dx, dy))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}

void	move_to_west(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	origin_x;
	double	origin_y;

	state = map_info->state;
	dx = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = -state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (!check_pos_range(map_info, dx, dy))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}

void	move_to_east(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	origin_x;
	double	origin_y;

	state = map_info->state;
	dx = -state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (!check_pos_range(map_info, dx, dy))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
	// printf("%d, %d\n", (int)state.pos_y, (int)state.pos_x);
}
