/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:36:44 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 20:41:49 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_texture(t_texture *texture)
{
	free(texture->texture_e);
	free(texture->texture_w);
	free(texture->texture_s);
	free(texture->texture_n);
	texture->texture_e = NULL;
	texture->texture_w = NULL;
	texture->texture_s = NULL;
	texture->texture_n = NULL;
	free(texture);
	texture = NULL;
}
