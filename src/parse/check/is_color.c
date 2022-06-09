/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:18:16 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 14:48:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	color_value_condition(char *buf)
{
	char	**res;

	res = ft_split(buf, ',');
	if (ft_db_arr_sz(res) == 3 && is_color_value_nbr(res))
	{
		free_db_arr(res);
		return (1);
	}
	free_db_arr(res);
	return (0);
}

static int	color_type_condition(char *buf)
{
	return (!ft_strncmp(buf, "F", ft_strlen(buf)) || \
			!ft_strncmp(buf, "C", ft_strlen(buf)));
}

static int	is_color_type(char **arr)
{
	if (color_type_condition(arr[0]) && color_value_condition(arr[1]))
		return (1);
	return (0);
}

static int	is_color_syntax(char *buf)
{
	char	**res;

	res = ft_split(buf, ' ');
	if (ft_db_arr_sz(res) == 2 && is_color_type(res))
	{
		free_db_arr(res);
		return (1);
	}
	free_db_arr(res);
	return (0);
}

int	is_color(char *buf)
{
	if (is_color_syntax(buf))
		return (1);
	return (0);
}
