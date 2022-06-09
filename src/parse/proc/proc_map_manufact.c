/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map_manufact.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:01:11 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 18:07:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_row_col(t_map_info **info)
{
	char	**ptr;
	int		ret;

	ptr = (*info)->map;
	ret = 0;
	while (*ptr)
	{
		if ((*info)->c < (int)ft_strlen(*ptr))
			(*info)->c = ft_strlen(*ptr);
		ret++;
		ptr++;
	}
	return (ret);
}

static char	**init_man_arr(t_map_info **info)
{
	char	**arr;
	int		idx;

	idx = 0;
	arr = (char **)malloc(sizeof(char *) * ((*info)->r + 1));
	while (idx < (*info)->r)
	{
		arr[idx] = ft_calloc((*info)->c + 1, sizeof(char));
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}

static void	copy_map(t_map_info **info, char **arr)
{
	int	r;
	int	c;

	r = 0;
	while (r < (*info)->r)
	{
		c = 0;
		while (c < (*info)->c && (*info)->map[r][c])
		{
			arr[r][c] = (*info)->map[r][c];
			c++;
		}
		while (c < (*info)->c)
		{
			arr[r][c] = ' ';
			c++;
		}
		arr[r][c] = 0;
		r++;
	}
	arr[r] = 0;
}

void	proc_map_manufact(t_map_info **info)
{
	char	**tmp;

	(*info)->r = get_row_col(info);
	tmp = init_man_arr(info);
	copy_map(info, tmp);
	free_db_arr((*info)->map);
	(*info)->map = tmp;
}
