/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:46:09 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 19:51:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_color(t_map_info *info)
{
	if (info == NULL || info->color == NULL)
		return ;
	free(info->color);
	info->color = NULL;
}
