/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:01:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 18:02:30 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_color_null(t_map_info **info, int type)
{
	if (type == F && (*info)->color->f_check)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
	else if (type == C && (*info)->color->c_check)
	{
		error_print(ERROR_ALREADY_BIND);
		exit(EXIT_FAILURE);
	}
}

static void	dup_color_value(t_map_info **info, char **arr)
{
	if (!ft_strncmp(arr[0], "F", ft_strlen(arr[0])))
	{
		check_color_null(info, F);
		bind_color_value(info, arr[1], F);
	}	
	else if (!ft_strncmp(arr[0], "C", ft_strlen(arr[0])))
	{
		check_color_null(info, C);
		bind_color_value(info, arr[1], C);
	}
}

void	bind_color(t_map_info **info, char *buf)
{
	char	**res;

	res = ft_split(buf, ' ');
	dup_color_value(info, res);
	free_db_arr(res);
}
