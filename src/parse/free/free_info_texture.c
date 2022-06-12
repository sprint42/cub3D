/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:36:44 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:19:42 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_texture(t_texture_path *path)
{
	free(path->path_e);
	free(path->path_w);
	free(path->path_s);
	free(path->path_n);
	path->path_e = NULL;
	path->path_w = NULL;
	path->path_s = NULL;
	path->path_n = NULL;
	free(path);
	path = NULL;
}
