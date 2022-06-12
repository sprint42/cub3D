/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:16 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 04:24:29 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	play(t_map_info *map_info)
{
	draw_sight(map_info);
	mlx_hook(map_info->win_ptr, EVENT_KEY_PRESS, 0, press_key, map_info);
	mlx_loop(map_info->mlx_ptr);
}