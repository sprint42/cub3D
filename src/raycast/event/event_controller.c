/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:44:20 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 13:44:58 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	event_move(int key, t_map_info *map_info)
{
	if (key == KEY_W)
		move_to_north(map_info);
	else if (key == KEY_S)
		move_to_south(map_info);
	else if(key == KEY_A)
		move_to_west(map_info);
	else
		move_to_east(map_info);
}

void	event_rotate(int key, t_map_info *map_info)
{
	if (key == KEY_LA)
		rotate_left(map_info);
	else
		rotate_right(map_info);
}
