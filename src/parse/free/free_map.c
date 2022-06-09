/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:50 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 18:06:42 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	free_map_element(t_map_info **info)
{
	if (info && (*info)->wspace)
		free_info_wspace((*info)->wspace);
	if (info && (*info)->texture)
		free_info_texture((*info)->texture);
}

void	free_map(t_map_info **info)
{
	if (*info)
	{
		free_map_element(info);
		free(*info);
		*info = NULL;
	}
}
