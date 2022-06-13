/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_color_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:18:06 by mcha              #+#    #+#             */
/*   Updated: 2022/06/13 12:06:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	bind_f_value(t_map_info **info, char *value)
{
	char	**arr;

	arr = ft_split(value, ',');
	(*info)->color->f_r = ft_atoi(arr[0]);
	(*info)->color->f_g = ft_atoi(arr[1]);
	(*info)->color->f_b = ft_atoi(arr[2]);
	(*info)->color->f_check = 1;
	free_db_arr(arr);
}

static void	bind_c_value(t_map_info **info, char *value)
{
	char	**arr;

	arr = ft_split(value, ',');
	(*info)->color->c_r = ft_atoi(arr[0]);
	(*info)->color->c_g = ft_atoi(arr[1]);
	(*info)->color->c_b = ft_atoi(arr[2]);
	(*info)->color->c_check = 1;
	free_db_arr(arr);
}

void	translate_rgb(t_map_info **info)
{
	(*info)->color->f_rgb = (*info)->color->f_r;
	(*info)->color->f_rgb = ((*info)->color->f_rgb << 8) + (*info)->color->f_g;
	(*info)->color->f_rgb = ((*info)->color->f_rgb << 8) + (*info)->color->f_b;
	(*info)->color->c_rgb = (*info)->color->c_r;
	(*info)->color->c_rgb = ((*info)->color->c_rgb << 8) + (*info)->color->c_g;
	(*info)->color->c_rgb = ((*info)->color->c_rgb << 8) + (*info)->color->c_b;
}

void	bind_color_value(t_map_info **info, char *value, int type)
{
	if (type == F)
		bind_f_value(info, value);
	else if (type == C)
		bind_c_value(info, value);
	if ((*info)->color->f_check && (*info)->color->c_check)
		translate_rgb(info);
}
