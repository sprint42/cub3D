/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:12:04 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 03:58:55 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

void	draw_pixel(t_map_info *map_info, int win_x, int win_y, int color)
{
	char	*pixel_ptr;

	pixel_ptr = map_info->state.img_buf.addr;
	pixel_ptr += win_y * map_info->state.img_buf.size_line;
	pixel_ptr += win_x * (map_info->state.img_buf.bpp / 8);
	*(unsigned int *)pixel_ptr = color;
}