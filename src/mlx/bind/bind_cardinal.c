/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_cardinal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:23:49 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 19:49:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	bind_cardinal_east(t_map_info **info)
{
	t_texture_info	*pck;

	pck = (*info)->comp->info_e;
	pck->ptr = (*info)->ptr->ptr_e;
	pck->addr = mlx_get_data_addr(pck->ptr, &(pck->bpp), &(pck->size_line), &(pck->endian));
	if (!(pck->addr))
		err_exit(ERROR_MAL);
}

void	bind_cardinal_west(t_map_info **info)
{
	t_texture_info	*pck;

	pck = (*info)->comp->info_w;
	pck->ptr = (*info)->ptr->ptr_w;
	pck->addr = mlx_get_data_addr(pck->ptr, &(pck->bpp), &(pck->size_line), &(pck->endian));
	if (!(pck->addr))
		err_exit(ERROR_MAL);
}

void	bind_cardinal_south(t_map_info **info)
{
	t_texture_info	*pck;

	pck = (*info)->comp->info_s;
	pck->ptr = (*info)->ptr->ptr_s;
	pck->addr = mlx_get_data_addr(pck->ptr, &(pck->bpp), &(pck->size_line), &(pck->endian));
	if (!(pck->addr))
		err_exit(ERROR_MAL);
}

void	bind_cardinal_north(t_map_info **info)
{
	t_texture_info	*pck;

	pck = (*info)->comp->info_n;
	pck->ptr = (*info)->ptr->ptr_n;
	pck->addr = mlx_get_data_addr(pck->ptr, &(pck->bpp), &(pck->size_line), &(pck->endian));
	if (!(pck->addr))
		err_exit(ERROR_MAL);
}
