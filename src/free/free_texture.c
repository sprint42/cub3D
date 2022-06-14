/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:54:49 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 13:10:43 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_comp(t_map_info *info, t_comp *comp)
{
	if (comp == NULL)
		return ;
	if (comp->ptr)
		mlx_destroy_image(info->mlx_ptr, comp->ptr);
	free(comp->ptr);
	comp->ptr = NULL;
	if (comp->addr)
		free(comp->addr);
	comp->addr = NULL;
}

void	free_texture(t_map_info *info)
{
	if (info == NULL || info->texture == NULL)
		return ;
	free_comp(info, info->texture->comp_e);
	info->texture->comp_e = NULL;
	free_comp(info, info->texture->comp_n);
	info->texture->comp_n = NULL;
	free_comp(info, info->texture->comp_s);
	info->texture->comp_s = NULL;
	free_comp(info, info->texture->comp_w);
	info->texture->comp_w = NULL;
	free(info->texture);
	info->texture = NULL;
}