/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_texture_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:36:44 by mcha              #+#    #+#             */
/*   Updated: 2022/06/14 13:11:56 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_texture_path(t_map_info *info)
{
	if (info == NULL || info->path == NULL)
		return ;
	if (info->path->path_e)
		free(info->path->path_e);
	info->path->path_e = NULL;
	if (info->path->path_w)
		free(info->path->path_w);
	info->path->path_w = NULL;
	if (info->path->path_s)
		free(info->path->path_s);
	info->path->path_s = NULL;
	if (info->path->path_n)
		free(info->path->path_n);
	info->path->path_n = NULL;
	free(info->path);
	info->path = NULL;
}
