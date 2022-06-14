/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:45:34 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 20:31:36 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_texture_index(t_map_info *map_info, \
								t_ray *ray, t_draw *draw_info)
{
	t_state	state;

	state = map_info->state;
	if (ray->hit_side == SIDE_X)
		draw_info->wall_x = state.pos_y + ray->parallel_dist * ray->raydir_y;
	else if (ray->hit_side == SIDE_Y)
		draw_info->wall_x = state.pos_x + ray->parallel_dist * ray->raydir_x;
	draw_info->wall_x -= (int)(draw_info->wall_x);
	draw_info->tex_x = draw_info->wall_x * TEX_W;
}

static void	init_draw_texture(t_map_info *map_info, \
								t_ray *ray, t_draw *draw_info)
{
	t_state	state;

	state = map_info->state;
	if (ray->hit_side == SIDE_X && ray->raydir_x >= 0)
		draw_info->curr_img = map_info->texture->comp_w;
	else if (ray->hit_side == SIDE_X)
		draw_info->curr_img = map_info->texture->comp_e;
	else if (ray->hit_side == SIDE_Y && ray->raydir_y >= 0)
		draw_info->curr_img = map_info->texture->comp_n;
	else if (ray->hit_side == SIDE_Y)
		draw_info->curr_img = map_info->texture->comp_s;
}

void	init_draw_info(t_map_info *map_info, t_ray *ray, t_draw *draw_info)
{
	t_state	state;

	state = map_info->state;
	if (ray->hit_side == SIDE_X)
		ray->parallel_dist = (ray->map_x - state.pos_x + (1 - ray->step_x) / 2) \
																/ ray->raydir_x;
	else
		ray->parallel_dist = (ray->map_y - state.pos_y + (1 - ray->step_y) / 2) \
																/ ray->raydir_y;
	ray->parallel_dist += 1e-6;
	draw_info->drawline_height = (int)(WIN_H / ray->parallel_dist);
	draw_info->step = (double)TEX_H / draw_info->drawline_height;
	draw_info->tex_y_pos = 0;
	draw_info->draw_start = -(draw_info->drawline_height / 2) + WIN_H / 2;
	if (draw_info->draw_start < 0)
	{
		draw_info->tex_y_pos = -draw_info->draw_start * draw_info->step;
		draw_info->draw_start = 0;
	}
	draw_info->draw_end = draw_info->drawline_height / 2 + WIN_H / 2;
	if (draw_info->draw_end >= WIN_H)
		draw_info->draw_end = WIN_H - 1;
	init_draw_texture(map_info, ray, draw_info);
	init_texture_index(map_info, ray, draw_info);
}
