/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:08:16 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:18:10 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static void	init_components(t_map_info **info)
{
	(*info)->texture->comp_e = NULL;
	(*info)->texture->comp_w = NULL;
	(*info)->texture->comp_s = NULL;
	(*info)->texture->comp_n = NULL;
}

static void	bind_cardinal_points(t_map_info **info)
{
	init_cardinal_east(info);
	init_cardinal_west(info);
	init_cardinal_south(info);
	init_cardinal_north(info);
}

void	malloc_comp(t_map_info **info)
{
	(*info)->texture = (t_texture *)malloc(sizeof(t_texture));
	if (!(*info)->texture)
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	init_components(info);
	bind_cardinal_points(info);
}
