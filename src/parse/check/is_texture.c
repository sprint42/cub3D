/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:15:31 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 16:24:33 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	texture_type_condition(char *buf)
{
	return (!ft_strncmp(buf, "NO", ft_strlen(buf)) || \
			!ft_strncmp(buf, "SO", ft_strlen(buf)) || \
			!ft_strncmp(buf, "WE", ft_strlen(buf)) || \
			!ft_strncmp(buf, "EA", ft_strlen(buf)));
}

static int	is_texture_type(char *buf)
{
	if (texture_type_condition(buf))
		return (1);
	return (0);
}

static int	is_texture_syntax(t_map_info *info, char *buf)
{
	char	*tmp;
	char	**res;

	tmp = ft_strtrim(buf, info->wspace);
	res = ft_split(tmp, ' ');
	if (ft_db_arr_sz(res) == 2 && is_texture_type(res[0]))
	{
		free_db_arr(res);
		return (1);
	}
	free_db_arr(res);
	return (0);
}

int	is_texture(t_map_info *info, char *buf)
{
	if (is_texture_syntax(info, buf))
		return (1);
	return (0);
}
