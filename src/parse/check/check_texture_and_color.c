/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:27 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 17:46:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_component_not_bind(t_map_info *info)
{
	return (!(info->texture->texture_e) || \
			!(info->texture->texture_n) || \
			!(info->texture->texture_w) || \
			!(info->texture->texture_s) || \
			!(info->color->c_check) || \
			!(info->color->f_check));
}

int	check_component_all_bind(t_map_info *info)
{
	return (info->texture->texture_e && \
			info->texture->texture_n && \
			info->texture->texture_w && \
			info->texture->texture_s && \
			info->color->c_check && \
			info->color->f_check);
}

void	check_texture_and_color(t_map_info *info)
{
	if (check_component_not_bind(info))
	{
		error_print(ERROR_COMP_NOT_FOUND);
		exit(EXIT_FAILURE);
	}
	else if (check_component_all_bind(info))
	{
		printf("\n==================================================\n");
		printf("==						==\n");
		printf("==	All components is successfully binded	==\n");
		printf("==						==\n");
		printf("==================================================\n");
	}
}
