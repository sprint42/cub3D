/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_color_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:18:06 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 15:32:23 by mcha             ###   ########.fr       */
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

void	bind_color_value(t_map_info **info, char *value, int type)
{
	if (type == F)
		bind_f_value(info, value);
	else if (type == C)
		bind_c_value(info, value);
}
