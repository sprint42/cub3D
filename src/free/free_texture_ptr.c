/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:33:10 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 13:11:26 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_texture_ptr(t_map_info *info)
{
	if (info == NULL || info->ptr == NULL)
		return ;
	if (info->ptr->ptr_e)
		mlx_destroy_image(info->mlx_ptr, info->ptr->ptr_e);
	info->ptr->ptr_e = NULL;
	if (info->ptr->ptr_n)
		mlx_destroy_image(info->mlx_ptr, info->ptr->ptr_n);
	info->ptr->ptr_n = NULL;
	if (info->ptr->ptr_s)
		mlx_destroy_image(info->mlx_ptr, info->ptr->ptr_s);
	info->ptr->ptr_s = NULL;
	if (info->ptr->ptr_w)
		mlx_destroy_image(info->mlx_ptr, info->ptr->ptr_w);
	info->ptr->ptr_w = NULL;
	free(info->ptr);
	info->ptr = NULL;
}