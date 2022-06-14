/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:09:57 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 20:15:50 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "math.h"
# include "minilib.h"
# include "raycast_struct.h"
# include "event.h"

# define WIN_W 1024
# define WIN_H 512
# define TEX_W 64
# define TEX_H 64

# define SIDE_X 0
# define SIDE_Y 1
# define SPEED 0.4
# define THETA 0.03

/* INIT */

void	init_window(t_map_info *map_info);
void	init_state(t_map_info *map_info);
void	init_ray(t_map_info *map_info, t_ray *ray);
void	init_draw_info(t_map_info *map_info, t_ray *ray, t_draw *draw_info);

/* DRAW */
void	draw_sight(t_map_info *map_info);
void	draw_vertical_line(t_map_info *map_info, int win_x, t_draw draw_info);
void	draw_pixel(t_map_info *map_info, int win_x, int win_y, int color);

#endif