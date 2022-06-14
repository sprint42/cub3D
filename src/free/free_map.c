/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:50 by mcha              #+#    #+#             */
/*   Updated: 2022/06/14 13:15:22 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	free_map_element(t_map_info *info)
{
	free_info_wspace(info);
	free_info_valid(info);
	free_info_texture_path(info);
	free_info_color(info);
	free_texture_ptr(info);
	free_texture(info);
	if (info->map)
		free_db_arr(info->map);
	info->map = NULL;
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	free(info->win_ptr);
	free(info->mlx_ptr);
	if (info->state.img_buf)
		free_comp(info, info->state.img_buf);
	info->state.img_buf = NULL;
}

void	free_map(t_map_info **info)
{
	if (*info)
	{
		free_map_element(*info);
		free(*info);
		*info = NULL;
	}
}
