/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:07:46 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 12:27:27 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

int	press_key(int key, t_map_info *map_info)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		event_move(key, map_info);
	else if (key == KEY_LA || key == KEY_RA)
		event_rotate(key, map_info);
	else if (key == KEY_ESC)
		event_red_cross(map_info);
	mlx_clear_window(map_info->mlx_ptr, map_info->win_ptr);
	draw_sight(map_info);
	mlx_put_image_to_window(map_info->mlx_ptr, map_info->win_ptr, map_info->state.img_buf.ptr, 0, 0);
	return (0);
}
