/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:04 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:25:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static void	is_texture_bind_successfully(t_map_info **info)
{
	t_map_ptr	*ptr;

	ptr = (*info)->ptr;
	if (!(ptr->ptr_e) || !(ptr->ptr_w) || !(ptr->ptr_s) || !(ptr->ptr_n))
	{
		destroy_texture(info);
		error_print(ERROR_BIND_FAIL);
		exit(EXIT_FAILURE);
	}
}

static void	link_texture_to_struct(t_map_info **info)
{
	bind_cardinal_east(info);
	bind_cardinal_west(info);
	bind_cardinal_south(info);
	bind_cardinal_north(info);
}

void	init_texture(t_map_info **info)
{
	int				x;
	int				y;
	t_map_ptr		*comp;
	t_texture_path	*path;

	comp = (*info)->ptr;
	path = (*info)->path;
	comp->ptr_e = \
		mlx_xpm_file_to_image((*info)->mlx_ptr, path->path_e, &x, &y);
	comp->ptr_w = \
		mlx_xpm_file_to_image((*info)->mlx_ptr, path->path_w, &x, &y);
	comp->ptr_s = \
		mlx_xpm_file_to_image((*info)->mlx_ptr, path->path_s, &x, &y);
	comp->ptr_n = \
		mlx_xpm_file_to_image((*info)->mlx_ptr, path->path_n, &x, &y);
	is_texture_bind_successfully(info);
	link_texture_to_struct(info);
}
