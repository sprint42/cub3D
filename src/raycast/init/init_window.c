/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:46:23 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 02:43:03 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_window_image(t_map_info *map_info)
{
	map_info->state.img_buf.ptr = mlx_new_image(map_info->mlx_ptr, winW, winH);
	if (map_info->state.img_buf.ptr == NULL)
	{
		printf("Error\nmessage: image buffer initialize failed\n");
		exit(EXIT_FAILURE);
	}
	map_info->state.img_buf.addr = mlx_get_data_addr(map_info->state.img_buf.ptr, &(map_info->state.img_buf.bpp), \
									&(map_info->state.img_buf.size_line), &(map_info->state.img_buf.endian));
}

void	init_window(t_map_info *map_info)
{
	map_info->win_ptr = mlx_new_window(map_info->mlx_ptr, winW, winH, "cub3D");
	if (map_info->win_ptr == NULL)
	{
		printf("Error\nmessage: window initialize failed\n");
		exit(EXIT_FAILURE);
	}
	init_window_image(map_info);
}