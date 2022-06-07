/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:14:35 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 17:34:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*find_end(char *buf)
{
	char	*ptr;

	ptr = buf;
	while (*ptr && *ptr != '\n')
		ptr++;
	return (ptr);
}

static void	bind_map_first(t_map_info *info, char *buf)
{
	char	*target;

	target = ft_substr(buf, 0, find_end(buf) - buf);
	info->map = (char **)malloc(sizeof(char *) * 2);
	info->map[1] = 0;
	info->map[0] = ft_strdup(target);
	free(target);
}

static void	move_map_components(t_map_info *info, char **arr, size_t sz)
{
	char	**tmp;
	size_t	idx;

	idx = 0;
	tmp = arr;
	while (idx < sz && info->map[idx])
	{
		tmp[idx] = ft_strdup(info->map[idx]);
		idx++;
	}
	free_db_arr(info->map);
}

static void	bind_map_continue(t_map_info *info, char *buf)
{
	char	*target;
	char	**tmp;
	size_t	sz;

	target = ft_substr(buf, 0, find_end(buf) - buf);
	sz = ft_db_arr_sz(info->map) + 1;
	tmp = (char **)malloc(sizeof(char *) * (sz + 1));
	tmp[sz] = 0;
	move_map_components(info, tmp, sz);
	tmp[sz - 1] = ft_strdup(target);
	info->map = tmp;
	free(target);
}

void	bind_map(t_map_info *info, char *buf)
{
	if (!(info->flag & START_MAP_PARSE))
		info->flag |= START_MAP_PARSE;
	if (info->map == NULL)
		bind_map_first(info, buf);
	else
		bind_map_continue(info, buf);
}
