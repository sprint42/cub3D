/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:12:04 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 13:29:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

void	draw_pixel(t_map_info *map_info, int win_x, int win_y, int color)
{
	char	*pixel_ptr;

	// printf("		%d, %d\n", win_x, win_y);
	pixel_ptr = map_info->state.img_buf.addr;
	// printf("1\n");
	pixel_ptr += win_y * map_info->state.img_buf.size_line;
	// printf("2\n");
	pixel_ptr += win_x * (map_info->state.img_buf.bpp / 8);
	// printf("3\n");
	*(unsigned int *)pixel_ptr = color;
	// printf("4\n");
}