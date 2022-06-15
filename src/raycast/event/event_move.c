/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:15:50 by yejin             #+#    #+#             */
/*   Updated: 2022/06/16 00:53:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	check_pos_range(t_map_info *map_info, double diff_x, double diff_y)
{
	int		map_x;
	int		map_y;

	map_x = (int)map_info->state.pos_x;
	map_y = (int)map_info->state.pos_y;
	if (diff_x == 0 && diff_y == 0)
	{
		if (map_info->map[map_y - 1][map_x - 1] != '0' || \
			map_info->map[map_y - 1][map_x] != '0' || \
			map_info->map[map_y][map_x - 1] != '0')
			return (0);
	}
	else if (diff_x == 0)
	{
		if (map_info->map[map_y][map_x - 1] != '0')
			return (0);
	}
	else if (diff_y == 0)
	{
		if (map_info->map[map_y - 1][map_x] != '0')
			return (0);
	}
	if (map_info->map[map_y][map_x] != '0')
		return (0);
	return (1);
}

void	move_to_north(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	dx = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

void	move_to_south(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	dx = -state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = -state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

void	move_to_west(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	dx = state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = -state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}

void	move_to_east(t_map_info *map_info)
{
	t_state	state;
	double	dx;
	double	dy;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	dx = -state.dir_y / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	dy = state.dir_x / sqrtf(powf(state.dir_x, 2) + powf(state.dir_y, 2));
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x -= dx * SPEED;
		map_info->state.pos_y -= dy * SPEED;
	}
}
