/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:09:51 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 16:16:20 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_vertical_line(t_map_info *map_info, int win_x, t_draw draw_info)
{
	char	*ptr;
	int		win_y;
	int		tex_y;
	int		color;

	win_y = 0;
	while (win_y < draw_info.draw_start)
	{
		draw_pixel(map_info, win_x, win_y, 0);
		win_y++;
	}
	printf("draw_end : %d\n", draw_info.draw_end);
	while (win_y < draw_info.draw_end)
	{
		tex_y = (int)(draw_info.tex_y_pos);
		ptr = draw_info.curr_img->addr;
		ptr += tex_y * draw_info.curr_img->size_line + draw_info.tex_x * (draw_info.curr_img->bpp / 8);
		color = *(unsigned int *)ptr;
		draw_pixel(map_info, win_x, win_y, color);
		win_y++;
		draw_info.tex_y_pos += draw_info.step;
	}
	printf("tile\n");
	while (win_y < winH)
	{
		draw_pixel(map_info, win_x, win_y, 0);
		win_y++;
	}
}