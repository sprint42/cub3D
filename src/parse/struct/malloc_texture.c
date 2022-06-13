/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:52:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/13 12:05:00 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	malloc_texture(t_map_info **info)
{
	(*info)->path = (t_texture_path *)malloc(sizeof(t_texture_path));
	if (!((*info)->path))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->path->path_e = NULL;
	(*info)->path->path_w = NULL;
	(*info)->path->path_s = NULL;
	(*info)->path->path_n = NULL;
}
