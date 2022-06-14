/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:09:57 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 19:41:27 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "math.h"
# include "minilib.h"

# define winW 1024
# define winH 512
# define texW 64
# define texH 64
# define SIDE_X 0
# define SIDE_Y 1

# define EVENT_KEY_PRESS 2
# define EVENT_RED_CROSS 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LA 123
# define KEY_RA 124
# define KEY_ESC 53

# define SPEED 0.4
# define THETA 2 * M_PI / 180

typedef struct	s_ray
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

/* INIT */

void	init_window(t_map_info *map_info);
void	init_state(t_map_info *map_info);
void	init_ray(t_map_info *map_info, t_ray *ray);
void	init_draw_info(t_map_info *map_info, t_ray *ray, t_draw *draw_info);

/* EVENT */
void	play(t_map_info *map_info);
int		press_key(int key, t_map_info *map_info);
void	event_move(int key, t_map_info *map_info);
void	move_to_north(t_map_info *map_info);
void	move_to_south(t_map_info *map_info);
void	move_to_west(t_map_info *map_info);
void	move_to_east(t_map_info *map_info);
void	event_rotate(int key, t_map_info *map_info);
void	rotate_left(t_map_info *map_info);
void	rotate_right(t_map_info *map_info);
int		event_red_cross(t_map_info *map_info);

/* DRAW */
void	draw_sight(t_map_info *map_info);
void	draw_vertical_line(t_map_info *map_info, int win_x, t_draw draw_info);
void	draw_pixel(t_map_info *map_info, int win_x, int win_y, int color);

#endif