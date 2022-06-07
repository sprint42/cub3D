/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_spawn_cnt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:21:22 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 22:48:29 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_player_spawn(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
			cnt++;
		str++;
	}
	return (cnt);
}

void	check_player_spawn_cnt(t_map_info *info)
{
	char	**ptr;
	int		cnt;

	cnt = 0;
	ptr = info->map;
	while (*ptr)
	{
		cnt += is_player_spawn(*ptr);
		ptr++;
	}	
	if (cnt > 1 || cnt < 1)
	{
		error_print(ERROR_PLAYER_SPAWN_CNT);
		exit(EXIT_FAILURE);
	}
}
