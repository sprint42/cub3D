/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:00:35 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 20:15:52 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_STRUCT_H
# define RAYCAST_STRUCT_H

# include "parse_struct.h"

typedef struct s_ray
{
	double	camera_pos;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	nextdist_x;
	double	nextdist_y;
	double	diststep_x;
	double	diststep_y;
	int		hit_side;
	double	parallel_dist;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_draw
{
	int		drawline_height;
	double	step;
	int		tex_x;
	double	tex_y_pos;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	t_comp	*curr_img;
}	t_draw;

#endif