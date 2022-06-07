/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_meaningful.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:09:39 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 19:17:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	proc_meaningful(t_map_info *info, char *buf)
{
	if (is_texture(info, buf))
		bind_texture(info, buf);
	else if (is_color(buf))
		bind_color(info, buf);
	else if (info->flag & COMP_BIND_DONE)
	{
		if (!(info->flag & START_MAP_PARSE))
			info->flag |= START_MAP_PARSE;
		else if (info->flag & END_MAP_PARSE)
		{
			error_print(ERROR_COMP_AFTER_END);
			exit(EXIT_FAILURE);
		}
		bind_map(info, buf);
	}
	else
	{
		error_print(ERROR_NOT_APPROP);
		exit(EXIT_FAILURE);
	}
}
