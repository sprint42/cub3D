/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:27:54 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/14 19:51:29 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_valid(t_map_info *info)
{
	if (info == NULL)
		return ;
	if (info->valid)
		free(info->valid);
	info->valid = NULL;
}
