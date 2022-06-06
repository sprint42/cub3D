/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_meaningful.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:09:39 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 16:21:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	proc_meaningful(t_map_info *info, char *buf)
{
	if (is_texture(info, buf))
		bind_texture(info, buf);
}
