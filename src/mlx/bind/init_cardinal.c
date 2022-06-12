/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cardinal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:24:32 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 15:46:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	init_cardinal_east(t_map_info **info)
{
	(*info)->comp->info_e = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->comp->info_e)
		err_exit(ERROR_MAL);
	(*info)->comp->info_e->ptr = NULL;
	(*info)->comp->info_e->addr = NULL;
	(*info)->comp->info_e->bpp = 0;
	(*info)->comp->info_e->size_line= 0;
	(*info)->comp->info_e->endian = 0;
}

void	init_cardinal_west(t_map_info **info)
{
	(*info)->comp->info_w = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->comp->info_w)
		err_exit(ERROR_MAL);
	(*info)->comp->info_w->ptr = NULL;
	(*info)->comp->info_w->addr = NULL;
	(*info)->comp->info_w->bpp = 0;
	(*info)->comp->info_w->size_line= 0;
	(*info)->comp->info_w->endian = 0;
}

void	init_cardinal_south(t_map_info **info)
{
	(*info)->comp->info_s = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->comp->info_s)
		err_exit(ERROR_MAL);
	(*info)->comp->info_s->ptr = NULL;
	(*info)->comp->info_s->addr = NULL;
	(*info)->comp->info_s->bpp = 0;
	(*info)->comp->info_s->size_line= 0;
	(*info)->comp->info_s->endian = 0;
}

void	init_cardinal_north(t_map_info **info)
{
	(*info)->comp->info_n = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->comp->info_n)
		err_exit(ERROR_MAL);
	(*info)->comp->info_n->ptr = NULL;
	(*info)->comp->info_n->addr = NULL;
	(*info)->comp->info_n->bpp = 0;
	(*info)->comp->info_n->size_line= 0;
	(*info)->comp->info_n->endian = 0;
}
