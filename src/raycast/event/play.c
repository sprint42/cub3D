/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:16 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 19:40:36 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	play(t_map_info *map_info)
{
	draw_sight(map_info);
	mlx_hook(map_info->win_ptr, EVENT_KEY_PRESS, 0, press_key, map_info);
	mlx_hook(map_info->win_ptr, EVENT_RED_CROSS, 0, event_red_cross, map_info);
	mlx_loop(map_info->mlx_ptr);
}