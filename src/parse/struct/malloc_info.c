/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:10:59 by mcha              #+#    #+#             */
/*   Updated: 2022/06/13 02:37:09 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*return_wspace(void)
{
	char	*wspace;

	wspace = (char *)malloc(sizeof(char) * 7);
	if (!wspace)
		return (NULL);
	wspace[0] = ' ';
	wspace[1] = '\t';
	wspace[2] = '\n';
	wspace[3] = '\v';
	wspace[4] = '\f';
	wspace[5] = '\r';
	wspace[6] = 0;
	return (wspace);
}

static void	get_wspace(t_map_info **info)
{
	(*info)->wspace = return_wspace();
	if (!((*info)->wspace))
	{
		error_print(ERROR_MAL);
		free(info);
		exit(EXIT_FAILURE);
	}
}

static void	get_valid(t_map_info **info)
{
	(*info)->valid = (char *)malloc(sizeof(char) * 9);
	if (!((*info)->valid))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->valid[0] = ' ';
	(*info)->valid[1] = '1';
	(*info)->valid[2] = '2';
	(*info)->valid[3] = 'N';
	(*info)->valid[4] = 'S';
	(*info)->valid[5] = 'W';
	(*info)->valid[6] = 'E';
	(*info)->valid[7] = '0';
	(*info)->valid[8] = 0;
}

static void	bind_info_value(t_map_info **info)
{
	(*info)->width = 0;
	(*info)->height = 0;
	(*info)->flag = 0;
	(*info)->wspace = NULL;
	(*info)->valid = NULL;
	(*info)->path = NULL;
	(*info)->color = NULL;
	(*info)->ptr = NULL;
	(*info)->texture = NULL;
	(*info)->map = NULL;
	(*info)->mlx_ptr = NULL;
	(*info)->win_ptr = NULL;
}

void	malloc_info(t_map_info **info)
{
	*info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!(*info))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	bind_info_value(info);
	get_wspace(info);
	get_valid(info);
	malloc_texture(info);
	malloc_color(info);
	malloc_ptr(info);
	malloc_comp(info);
}
