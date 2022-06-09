/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:12:41 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 17:04:43 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	destroy_texture(t_map_info **info)
{
	t_map_ptr	*comp;

	comp = (*info)->ptr;
	if (comp->ptr_e)
		mlx_destroy_image((*info)->mlx_ptr, comp->ptr_e);
	if (comp->ptr_w)
		mlx_destroy_image((*info)->mlx_ptr, comp->ptr_w);
	if (comp->ptr_s)
		mlx_destroy_image((*info)->mlx_ptr, comp->ptr_s);
	if (comp->ptr_n)
		mlx_destroy_image((*info)->mlx_ptr, comp->ptr_n);
}
