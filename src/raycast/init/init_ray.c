/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:46:30 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 20:31:51 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_step(t_map_info *map_info, t_ray *ray)
{
	t_state	state;

	state = map_info->state;
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->nextdist_x = (state.pos_x - ray->map_x) * ray->diststep_x;
	}
	else
	{
		ray->step_x = 1;
		ray->nextdist_x = (ray->map_x + 1 - state.pos_x) * ray->diststep_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->nextdist_y = (state.pos_y - ray->map_y) * ray->diststep_y;
	}
	else
	{
		ray->step_y = 1;
		ray->nextdist_y = (ray->map_y + 1 - state.pos_y) * ray->diststep_y;
	}
}

void	init_ray(t_map_info *map_info, t_ray *ray)
{
	t_state	state;

	state = map_info->state;
	ray->raydir_x = state.dir_x + state.plane_x * ray->camera_pos;
	ray->raydir_y = state.dir_y + state.plane_y * ray->camera_pos;
	ray->map_x = (int)state.pos_x;
	ray->map_y = (int)state.pos_y;
	ray->diststep_x = fabs(1 / ray->raydir_x);
	ray->diststep_y = fabs(1 / ray->raydir_y);
	init_step(map_info, ray);
}
