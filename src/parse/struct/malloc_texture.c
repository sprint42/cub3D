/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:52:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 19:43:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	malloc_texture(t_map_info **info)
{
	(*info)->texture = (t_texture *)malloc(sizeof(t_texture));
	if (!((*info)->texture))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->texture->texture_e = NULL;
	(*info)->texture->texture_w = NULL;
	(*info)->texture->texture_s = NULL;
	(*info)->texture->texture_n = NULL;
}
