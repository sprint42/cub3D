/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:54:49 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 19:38:39 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_texture(t_map_info *info)
{
	if (info == NULL || info->texture == NULL)
		return ;
	free(info->texture->comp_e);
	info->texture->comp_e = NULL;
	free(info->texture->comp_n);
	info->texture->comp_n = NULL;
	free(info->texture->comp_s);
	info->texture->comp_s = NULL;
	free(info->texture->comp_w);
	info->texture->comp_w = NULL;
	free(info->texture);
	info->texture = NULL;
}