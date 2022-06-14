/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:55:50 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 20:12:48 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "raycast.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LA 123
# define KEY_RA 124
# define KEY_ESC 53

# define EVENT_KEY_PRESS 2
# define EVENT_RED_CROSS 17

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

#endif