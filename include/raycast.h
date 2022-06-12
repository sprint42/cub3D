/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:09:57 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 00:46:14 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilib.h"

# define winW 4096
# define winH 2048
# define texW 64
# define texH 64

typedef struct	s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	nextdist_x;
	double	nextdist_y;
	double	diststep_x;
	double	diststep_y;
	double	parallel_dist;
	int		x_step_dir;
	int		y_step_dir;
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

/* INIT */

// init_window.c
void	init_window(t_map_info *map_info);

// init_state.c
void	init_state(t_map_info *map_info);

// play.c
void	play(t_map_info *map_info);

// draw_sight.c

#endif