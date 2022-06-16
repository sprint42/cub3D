/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:015:50 by yejin             #+#    #+#             */
/*   Updated: 2022/06/16 10:17:05 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	check_pos_range(t_map_info *map_info, double diff_x, double diff_y)
{
	int		map_x;
	int		map_y;

	map_x = (int)map_info->state.pos_x;
	map_y = (int)map_info->state.pos_y;
	printf("%f, %f\n", diff_x, diff_y);
	if (diff_x < 0.015 && diff_y < 0.015)
	{
		if (map_info->map[map_y - 1][map_x - 1] != '0' || \
			map_info->map[map_y - 1][map_x] != '0' || \
			map_info->map[map_y][map_x - 1] != '0')
			return (0);
	}
	else if (diff_x < 0.015)
	{
		if (map_info->map[map_y][map_x - 1] != '0')
			return (0);
	}
	else if (diff_y < 0.015)
	{
		if (map_info->map[map_y - 1][map_x] != '0')
			return (0);
	}
	if (map_info->map[map_y][map_x] != '0')
		return (0);
	return (1);
}

void	move_to_north(t_map_info *map_info, double dx, double dy)
{
	t_state	state;
	double	origin_x;
	double	origin_y;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (1 - (map_info->state.pos_x - (int)map_info->state.pos_x) < 0.015)
		map_info->state.pos_x += 0.015;
	if (1 - (map_info->state.pos_y - (int)map_info->state.pos_y) < 0.015)
		map_info->state.pos_y += 0.015;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
		
	}
}

void	move_to_south(t_map_info *map_info, double dx, double dy)
{
	t_state	state;
	double	origin_x;
	double	origin_y;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (1 - (map_info->state.pos_x - (int)map_info->state.pos_x) < 0.015)
		map_info->state.pos_x += 0.015;
	if (1 - (map_info->state.pos_y - (int)map_info->state.pos_y) < 0.015)
		map_info->state.pos_y += 0.015;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}

void	move_to_west(t_map_info *map_info, double dx, double dy)
{
	t_state	state;
	double	origin_x;
	double	origin_y;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (1 - (map_info->state.pos_x - (int)map_info->state.pos_x) < 0.015)
		map_info->state.pos_x += 0.015;
	if (1 - (map_info->state.pos_y - (int)map_info->state.pos_y) < 0.015)
		map_info->state.pos_y += 0.015;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}

void	move_to_east(t_map_info *map_info, double dx, double dy)
{
	t_state	state;
	double	origin_x;
	double	origin_y;
	double	diff_x;
	double	diff_y;

	state = map_info->state;
	origin_x = map_info->state.pos_x;
	origin_y = map_info->state.pos_y;
	map_info->state.pos_x += dx * SPEED;
	map_info->state.pos_y += dy * SPEED;
	if (1 - (map_info->state.pos_x - (int)map_info->state.pos_x) < 0.015)
		map_info->state.pos_x += 0.015;
	if (1 - (map_info->state.pos_y - (int)map_info->state.pos_y) < 0.015)
		map_info->state.pos_y += 0.015;
	diff_x = map_info->state.pos_x - (int)map_info->state.pos_x;
	diff_y = map_info->state.pos_y - (int)map_info->state.pos_y;
	if (!check_pos_range(map_info, diff_x, diff_y))
	{
		map_info->state.pos_x = origin_x;
		map_info->state.pos_y = origin_y;
	}
}
