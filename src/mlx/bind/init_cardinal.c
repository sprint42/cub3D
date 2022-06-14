/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cardinal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:24:32 by mcha              #+#    #+#             */
/*   Updated: 2022/06/14 19:50:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	init_cardinal_east(t_map_info **info)
{
	(*info)->texture->comp_e = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->texture->comp_e)
		err_exit(ERROR_MAL);
	(*info)->texture->comp_e->ptr = NULL;
	(*info)->texture->comp_e->addr = NULL;
	(*info)->texture->comp_e->bpp = 0;
	(*info)->texture->comp_e->size_line = 0;
	(*info)->texture->comp_e->endian = 0;
}

void	init_cardinal_west(t_map_info **info)
{
	(*info)->texture->comp_w = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->texture->comp_w)
		err_exit(ERROR_MAL);
	(*info)->texture->comp_w->ptr = NULL;
	(*info)->texture->comp_w->addr = NULL;
	(*info)->texture->comp_w->bpp = 0;
	(*info)->texture->comp_w->size_line = 0;
	(*info)->texture->comp_w->endian = 0;
}

void	init_cardinal_south(t_map_info **info)
{
	(*info)->texture->comp_s = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->texture->comp_s)
		err_exit(ERROR_MAL);
	(*info)->texture->comp_s->ptr = NULL;
	(*info)->texture->comp_s->addr = NULL;
	(*info)->texture->comp_s->bpp = 0;
	(*info)->texture->comp_s->size_line = 0;
	(*info)->texture->comp_s->endian = 0;
}

void	init_cardinal_north(t_map_info **info)
{
	(*info)->texture->comp_n = (t_comp *)malloc(sizeof(t_comp));
	if (!(*info)->texture->comp_n)
		err_exit(ERROR_MAL);
	(*info)->texture->comp_n->ptr = NULL;
	(*info)->texture->comp_n->addr = NULL;
	(*info)->texture->comp_n->bpp = 0;
	(*info)->texture->comp_n->size_line = 0;
	(*info)->texture->comp_n->endian = 0;
}
