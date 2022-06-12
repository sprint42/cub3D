/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:19 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 02:00:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	find_hit_point(t_map_info *map_info, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->nextdist_x < ray->nextdist_y)
		{
			ray->nextdist_x += ray->diststep_x;
			ray->map_x += ray->step_x;
			ray->hit_side = SIDE_X;
		}
		else
		{
			ray->nextdist_y += ray->diststep_x;
			ray->map_x += ray->step_x;
			ray->hit_side = SIDE_Y;
		}
		if (map_info->map[ray->map_y][ray->map_x] == 1)
			hit = 1;
	}
}


void	draw_sight(t_map_info *map_info)
{
	int		i;
	t_ray	ray;
	t_draw	draw_info;

	i = 0;
	while (i < winW)
	{
		ray.camera_pos = -2 * i / (double)winW + 1;
		init_ray(map_info, &ray);
		find_hit_point(map_info, &ray);
		init_draw_info(map_info, &ray, &draw_info);
		// draw
		i++;
	}
}