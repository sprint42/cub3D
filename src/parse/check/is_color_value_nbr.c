/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_value_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:26:08 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 15:00:00 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_in_range(char *value)
{
	int	tmp;

	tmp = ft_atoi(value);
	if (tmp < 0 || tmp > 255)
		return (0);
	return (1);
}

static int	is_value_nbr(char *value)
{
	char	*tmp;

	tmp = value;
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (0);
		tmp++;
	}
	return (1);
}

int	is_color_value_nbr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		if (!is_value_nbr(*tmp) || !is_in_range(*tmp))
			return (0);
		tmp++;
	}
	return (1);
}
