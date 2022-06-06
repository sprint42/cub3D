/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:45 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 17:15:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_texture_null(t_map_info *info, int type)
{

}

static void	dup_texture_path(t_map_info *info, char **arr)
{
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
	{
		if (info->texture->texture_n)
		{
			
		}
		info->texture->texture_n = ft_strdup(arr[1]);
	}
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
		info->texture->texture_s = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
		info->texture->texture_e = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
		info->texture->texture_w = ft_strdup(arr[1]);
}

void	bind_texture(t_map_info *info, char *buf)
{
	char	*tmp;
	char	**res;

	tmp = ft_strtrim(buf, info->wspace);
	res = ft_split(tmp, ' ');
	dup_texture_path(info, res);
}
