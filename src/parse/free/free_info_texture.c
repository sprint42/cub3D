/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:36:44 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 15:40:55 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_texture(t_texture_path *texture)
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
