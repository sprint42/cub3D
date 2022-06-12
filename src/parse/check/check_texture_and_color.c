/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:27 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:16:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_component_not_bind(t_map_info **info)
{
	return (!((*info)->texture->comp_e) || \
			!((*info)->texture->comp_n) || \
			!((*info)->texture->comp_w) || \
			!((*info)->texture->comp_s) || \
			!((*info)->color->c_check) || \
			!((*info)->color->f_check));
}

int	check_component_all_bind(t_map_info **info)
{
	return ((*info)->texture->comp_e && \
			(*info)->texture->comp_n && \
			(*info)->texture->comp_w && \
			(*info)->texture->comp_s && \
			(*info)->color->c_check && \
			(*info)->color->f_check);
}

void	check_texture_and_color(t_map_info **info)
{
	if (check_component_not_bind(info))
	{
		error_print(ERROR_COMP_NOT_FOUND);
		exit(EXIT_FAILURE);
	}
}
