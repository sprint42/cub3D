/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:27 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 23:09:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_texture_and_color(t_map_info *info)
{
	if (!(info->texture->texture_e) || \
		!(info->texture->texture_n) || \
		!(info->texture->texture_w) || \
		!(info->texture->texture_s))
	{
		error_print(ERROR_COMP_NOT_FOUND);
		exit(EXIT_FAILURE);
	}
}
