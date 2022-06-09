/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:08:16 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 18:44:33 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static void	init_components(t_map_info **info)
{
	(*info)->comp->info_e = NULL;
	(*info)->comp->info_w = NULL;
	(*info)->comp->info_s = NULL;
	(*info)->comp->info_n = NULL;
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
	(*info)->comp = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->comp)
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	init_components(info);
	bind_cardinal_points(info);
}
