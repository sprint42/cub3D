/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:42:22 by mcha              #+#    #+#             */
/*   Updated: 2022/06/13 12:01:42 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	malloc_color(t_map_info **info)
{
	(*info)->color = (t_color *)malloc(sizeof(t_color));
	if (!((*info)->color))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->color->f_r = 0;
	(*info)->color->f_g = 0;
	(*info)->color->f_b = 0;
	(*info)->color->c_r = 0;
	(*info)->color->c_g = 0;
	(*info)->color->c_b = 0;
	(*info)->color->c_check = 0;
	(*info)->color->f_check = 0;
	(*info)->color->f_rgb = 0;
	(*info)->color->c_rgb = 0;
}
